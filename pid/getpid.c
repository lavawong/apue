#include "apue.h"

int
main (void) 
{
    printf("Hello from process getpid %ld\n", (long)getpid());
    printf("Hello from process getppid %ld\n", (long)getppid());
    return 0;
}
