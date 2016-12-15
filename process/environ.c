/*
 * =====================================================================================
 *
 *       Filename:  environ.c
 *
 *    Description:  print environments
 *
 *        Version:  1.0
 *        Created:  11/27/16 20:58:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lavawong 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "apue.h"

int
main(int argc, char *argv[])
{
    int            i = 0;
    extern char    **environ;
    
    while (NULL != environ[i]) {
        printf("Index %d: %s\n", i, environ[i]);
        i++;
    }
    exit(0); /* return 0; */
}

