/**
 * Created by Lava Wong on 2022/2/27.
 */
#include "apue.h"
#include <errno.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <syslog.h>

void daemonize(const char *cmd) {
    int              i, fd0, fd1, fd2;
    pid_t            pid;
    struct rlimit    rl;
    struct sigaction sa;

    /*
     * Clear file creation mask.
     */
    umask(0);

    syslog(LOG_INFO, "log cmd:%s", cmd);
//  int err = setuid(0);
//  if (err != 0) {
//    syslog(LOG_INFO, "cmd:%s setuid error! %s", cmd, strerror(errno));
//  }

    syslog(LOG_INFO, "%s fork before:%d", cmd, getpid());
    /*
     * Become a session leader to lose controlling TTY.
     */
    if ((pid = fork()) < 0)
        err_quit("%s: can't fork", cmd);
    else if (pid != 0) /* parent */
        exit(0);

    /*
     * Ensure future opens won't allocate controlling TTYs.
     */
    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGHUP, &sa, NULL) < 0)
        err_quit("%s: can't ignore SIGHUP", cmd);
    if ((pid = fork()) < 0)
        err_quit("%s: can't fork", cmd);
    else if (pid != 0) /* parent */
        exit(0);
    setsid();
    /*
     * Change the current working directory to the root so
     * we won't prevent file systems from being unmounted.
     */
    if (chdir("/") < 0)
        err_quit("%s: can't chage directory to /", cmd);
    syslog(LOG_INFO, "%s fork after:%d", cmd, getpid());

    /*
     * Get maximum number of file descriptions.
     */
    if (getrlimit(RLIMIT_NOFILE, &rl) < 0) {
        err_quit("%s: can't get file limit", cmd);
    } else {
        /*
         * Close all open file descriptors.
         */
        if (rl.rlim_max > 0) {
            if (rl.rlim_max == RLIM_INFINITY)
                rl.rlim_max = 1024;
            for (i = 0; i < rl.rlim_max; ++i) {
                close(i);
            }
        }
    }
    syslog(LOG_INFO, "%s rlim_max:%llu", cmd, rl.rlim_max);
    syslog(LOG_INFO, "%s RLIM_INFINITY:%llu", cmd, RLIM_INFINITY);



    syslog(LOG_INFO, "%s fork after:%d", cmd, getpid());

    /*
     * Attach file descriptors -, 1, and 2 to /dev/null.
     */
    fd0 = open("/dev/null", O_RDWR);
    fd1 = dup(0);
    fd2 = dup(0);

    /*
     * Initialize the log file.
     */
    openlog(cmd, LOG_NDELAY | LOG_PID | LOG_CONS | LOG_USER, LOG_SYSLOG);
    setlogmask(LOG_UPTO(LOG_INFO)); // macOS not working!
    if (fd0 != 0 || fd1 != 1 || fd2 != 2) {
        syslog(LOG_NOTICE, "file descriptors %d %d %d", fd0, fd1, fd2);
        exit(1);
    } else {
        syslog(LOG_NOTICE, "daemonize ok %d", getpid());
    }
}
