#include "apue.h"
#include <sys/wait.h>

int
main(void)
{
    int     status;
    if ((status = system("/bin/date")) < 0) {
        err_sys("system() error");
    }
    
    pr_exit(status);
    exit(0);
}
