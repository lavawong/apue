/*
 * =====================================================================================
 *
 *       Filename:  getpriority.c
 *
 *    Description:  print environments
 *
 *        Version:  1.0
 *        Created:  01/13/17 20:58:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lavawong 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <sys/resource.h>

int
main(void)
{
    int     pid_pri;

    printf("%d\n", getpriority(PRIO_PROCESS, 0));

    exit(0);
}