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
    printf("CHAR_BIT    : %ld\n", sysconf(CHAR_BIT));
    printf("CHAR_MAX    : %ld\n", sysconf(CHAR_MAX));
    printf("CHAR_MIN    : %ld\n", sysconf(CHAR_MIN));
    printf("SCHAR_MAX   : %ld\n", sysconf(SCHAR_MAX));
    printf("SCHAR_MIN   : %ld\n", sysconf(SCHAR_MIN));
    printf("UCHAR_MAX   : %ld\n", sysconf(UCHAR_MAX));

    printf("\n");
    
    printf("INT_MAX    : %ld\n", sysconf(INT_MAX));
    printf("INT_MIN    : %ld\n", sysconf(INT_MIN));
    printf("UINT_MAX   : %ld\n", sysconf(UINT_MAX));

    printf("\n");
    
    printf("SHRT_MAX    : %ld\n", sysconf(SHRT_MAX));
    printf("SHRT_MIN    : %ld\n", sysconf(SHRT_MIN));
    printf("USHRT_MAX   : %ld\n", sysconf(USHRT_MAX));

    return 0;
}


