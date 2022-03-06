/**
 * Created by Lava Wong on 2022/2/28.
 */
#include "apue.h"
#include <errno.h>
#include <pthread.h>
#include <syslog.h>


static BOOL g_active = FALSE;

int already_running(void);

void daemonize(const char *cmd);

void reread(void);

int set_close_exec(int fd);

void sigterm(int signo) {
    g_active = FALSE;
    syslog(LOG_NOTICE, "got SIGTERM; exiting...");
    exit(0);
}

void sighup(int signo) {
    syslog(LOG_NOTICE, "Re-reading configuration file...");
    reread();
}

void *thr_fn(void *arg) {
    int err, signo;
    sigset_t sigset;
    sigemptyset(&sigset);
    sigaddset(&sigset, signo);
    for (;;) {
        err = sigwait(&sigset, &signo);
        if (err != 0) {
            syslog(LOG_ERR, "sigwait failed: %s", strerror(err));
            exit(1);
        }
        switch (signo) {
            case SIGHUP:
                sighup(signo);
                break;
            case SIGTERM:
                sigterm(signo);
            default:
                syslog(LOG_NOTICE, "unexpected signal %d\n", signo);
        }
    }
}

void* daemon_main(void* /* ptr */) {
    unsigned int counter = 0;

    while (g_active == TRUE) {
        /* !!! THE PROBLEM IS HERE !!!
         *
         * All function calls in this loop do not work,
         * but it still can quit from it, when g_active == false.
         * If I remove the loop from here, the thread will be terminated normally */

        syslog(LOG_NOTICE, "sleep Counter = %d", counter);
        sleep(2);
        syslog(LOG_NOTICE, "Counter = %d", counter++);
    }
    return NULL;
}

int main(int argc, const char *argv[]) {
    int              err;
    pthread_t        tid;
    char             *cmd;
    struct sigaction sa;

    if ((cmd = strrchr(argv[0], '/')) == NULL)
        cmd = argv[0];
    else
        cmd++;
    /*
     * Become a daemon.
     */
    daemonize(cmd);

    /*
     * Make sure only one copy of the daemon is running.
     */
    if (already_running()) {
        syslog(LOG_ERR, "daemon already running");
        exit(1);
    }

    syslog(LOG_NOTICE, "daemon-specific initialization");
    /*
     * Handle signals of interest
     */
    sa.sa_handler = sigterm;
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGHUP);
    sa.sa_flags = 0;
    if (sigaction(SIGTERM, &sa, NULL) < 0) {
        syslog(LOG_ERR, "can't catch SIGTERM: %s", strerror(errno));
        exit(1);
    }
    sa.sa_handler = sighup;
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGTERM);
    sa.sa_flags = 0;
    if (sigaction(SIGHUP, &sa, NULL) < 0) {
        syslog(LOG_ERR, "can't catch SIGHUP: %s", strerror(errno));
        exit(1);
    }
    /*
     * Create a thread to handle SIGHUP and SIGTERM
     */
//    err = pthread_create(&tid, NULL, thr_fn, NULL);
//    if (err != 0) {
//        syslog(LOG_ERR, "can't create thread");
//        exit(1);
//    }
    // daemon-specific initialization goes here
    pthread_t second_thread;
    g_active = TRUE;
    /*
     * Proceed with the rest of daemon.
     */
    int ires = pthread_create(&second_thread, NULL, daemon_main, NULL);
    if (ires != 0) {
        syslog(LOG_ERR, "Could not create a second thread. Error <%d>", ires);
        closelog();
        exit(EXIT_FAILURE);
    }

    syslog(LOG_NOTICE, "Initialization completed");
    pthread_join(second_thread, NULL);

    // close system log for the child process
    syslog(LOG_NOTICE, "Successfully stopped");
    closelog();

    exit(0);
}