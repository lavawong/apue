#include "apue.h"
int
main(void)
{
    pid_t   pid;
    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid != 0) {
        sleep(2);
        exit(2);
    }
    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid != 0) {
        sleep(4);
        abort();
    }
    /* parent */
    /* terminate with exit status 2 */
    /* first child */
    /* terminate with core dump */
    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid != 0) {
        /* second child */
        execl("/bin/dd", "dd", "if=/etc/passwd", "of=/dev/null", NULL);
        exit(7);
        /* shouldn’t get here */
    }
    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid != 0) {/* fourth child */
        sleep(8);
        /* normal exit */
        exit(0);
    }
    /* fourth child */
    sleep(6);
    /* terminate w/signal, no core dump */
    kill(getpid(), SIGKILL);
    /* shouldn’t get here */
    exit(6);

}
