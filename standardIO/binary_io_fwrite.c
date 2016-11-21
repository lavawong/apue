/*
 * =====================================================================================
 *
 *       Filename:  binary_io_fread.c
 *
 *    Description:  binary I/O
 *                  $ ./binary_io_fwrite.out | ./binary_io_fread.out
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

#define NAMESIZE 64

struct Persion {
    int     age;
    long    money;
    char    name[NAMESIZE];
};

int main(void)
{
    struct Persion persions[] = {
        { .age = 23, .money = 2344000, .name = "Lava"},
        { .age = 22, .money = 6344000, .name = "Wong"},
        { .age = 25, .money = 1344000, .name = "Dave"},
        { .age = 27, .money = 8344000, .name = "Shivaf"},
    };
    struct Persion persion;
    int          i = 0;
    int        len = sizeof(persions)/sizeof(persion);
    int       nobj = 2;
    while ( i < len ) {
        persion = persions[i];
        if (fwrite(&persions[i], sizeof(persion), nobj, stdout) != nobj) {
            printf("fwrite error");
            return 1;
        }
        i = i + nobj;
    }

    if (ferror(stdout)) {
        printf("output error");
        return 1;
    }
    return 0;
}


