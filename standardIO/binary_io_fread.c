/*
 * =====================================================================================
 *
 *       Filename:  binary_io_fwrite.c
 *
 *    Description:  binary I/O
 *                  $ ./binary_io_fwrite.out | ./binary_io_fread.out
 *        Version:  1.0
 *        Created:  11/22/16 01:11:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lavawong 
 *   Organization:  
 *  
 *
 * =====================================================================================
 */
#include "apue.h"
#include <sys/errno.h>

#define NAMESIZE 64

struct Persion {
    int     age;
    long    money;
    char    name[NAMESIZE];
};

int main(void)
{
    struct Persion persion;
    
    printf("==============begin read==============\n");
    while (fread(&persion, sizeof(persion), 1, stdin) == 1) {
        printf("fwread persion\n");
        printf("name  : %s\n", persion.name);
        printf("age   : %d\n", persion.age);
        printf("money : %ld\n", persion.money);
    }
    printf("=============== end read===============\n");
    if (errno > 0) {
        printf("read stream error: %s\n", strerror(errno));
    }

    if (ferror(stdin)) {
        printf("input error!\n");
        return 1;
    }
    return 0;
}


