#include "apue.h"
#include <sys/wait.h>

char *env_int[] = { "USER=unknown", "PATH=/tmp", NULL};

int
main(void)
{
    pid_t   pid;

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        if (execle("./echoall.out", "echoall", "myarg1",
                "MY ARG2", (char *)0, env_int) < 0)
            err_sys("execle error");
    }

    if (waitpid(pid, NULL, 0) < 0)
        err_sys("waitpid error");
    
    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        if (execlp("echoall.out", "echoall", "only 1 arg", (char *)0) < 0)
            err_sys("execlp error");
    }

    exit(0);
}

