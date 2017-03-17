#include "apue.h"
#include <sys/types.h>
#include <sys/wait.h>

int
main(void)
{
    int     n;
    int     fd[2];
    pid_t   pid;
    char    line[MAXLINE];
    
    if (pipe(fd) < 0)
        err_sys("pipe error");

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid > 0) {
        close(fd[0]);
        write(fd[1], "hello world\n", 12);
        printf("pid: %d, ppid: %d\n", getpid(), getppid());
        printf("end parent!\n");
    } else {
        sleep(2);
        close(fd[1]);
        n = read(fd[0], line, MAXLINE);
        write(STDOUT_FILENO, line, n);
        printf("pid: %d, ppid: %d\n", getpid(), getppid());
    }
    waitpid(pid, NULL,WCONTINUED);
    exit(0);
}
