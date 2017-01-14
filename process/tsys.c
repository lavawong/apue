/*
 * ===================================================================
 *
 *       Filename:  atexit.c
 *
 *    Description:  test atexit
 *
 *        Version:  1.0
 *        Created:  11/27/16 20:58:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lavawong 
 *   Organization:  
 *
 * ===================================================================
 */

#include "apue.h"
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    int     status;

    if (argc < 2) 
        err_quit("command-line argument required");
    
    if ((status = system(argv[1])) < 0) 
        err_sys("system() error");

    pr_exit(status);

    exit(0);
}
