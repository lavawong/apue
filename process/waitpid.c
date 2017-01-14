#include "apue.h"
#include <sys/wait.h> 

    int
main(int argc, char* argv[])
{
    pid_t   pid;

    printf("main prarent pid = %ld\n", (long)getppid());
    printf("main pid = %ld\n", (long)getpid());

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0) {
        if ((pid = fork()) < 0)
            err_sys("fork error");
        else if (pid == 0) {
            printf("third prarent pid = %ld\n", (long)getppid());
            exit(1);
        }
        sleep(2);
        printf("second child, prarent pid = %ld\n", (long)getppid());
        exit(0);
    }
    if (waitpid(pid, NULL, 0) != pid)
        err_sys("waitpid error");

    return 0;
}
