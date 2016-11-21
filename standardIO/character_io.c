/*
 * =====================================================================================
 *
 *       Filename:  character_io.c
 *
 *    Description: character at a time I/O 
 *
 *        Version:  1.0
 *        Created:  11/22/16 01:06:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author: lavawong 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "apue.h"
/*
// What's happened uncomment 30 line? Why?
$ echo "你好" | ./character_io.out
$ echo "hello" | ./character_io.out
*/
int main(void)
{
    int c;

    while ((c = getc(stdin)) != EOF) {
        /* printf("putc a character haha!\n"); */
        if (putc(c, stdout) == EOF) {
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

