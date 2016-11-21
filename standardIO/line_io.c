/*
 * =====================================================================================
 *
 *       Filename:  line_io.c
 *
 *    Description:  line at a time I/O
 *
 *        Version:  1.0
 *        Created:  11/22/16 01:11:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lavawong 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "apue.h"
int main(void)
{
    char    buf[MAXLINE];

    while ((fgets(buf, MAXLINE, stdin)) != NULL) {
        /* printf("fputs line!\n"); */
        if (fputs(buf, stdout) == EOF) {
            printf("output error");
            return 1;
        }
    }

    if (ferror(stdin)) {
        printf("input error");
        return 1;
    }
    return 0;
}


