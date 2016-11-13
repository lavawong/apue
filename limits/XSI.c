/*
 * =====================================================================================
 *
 *       Filename:  IOS.c
 *
 *    Description:  print IOS limits
 *
 *        Version:  1.0
 *        Created:  11/11/16 23:13:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lavawong, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "apue.h"
#include <limits.h>

int main(void)
{
    printf("============== sysconf ==============\n");
    printf("NL_LANGMAX      : %ld\n", sysconf(NL_LANGMAX));
    printf("NZERO           : %ld\n", sysconf(NZERO));
    printf("_XOPEN_IOV_MAX  : %ld\n", sysconf(_XOPEN_IOV_MAX));
    printf("_XOPEN_NAME_MAX : %ld\n", sysconf(_XOPEN_NAME_MAX));
    printf("_XOPEN_PATH_MAX : %ld\n", sysconf(_XOPEN_PATH_MAX));
    return 0;
}


