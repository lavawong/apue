/*
 * =====================================================================================
 *
 *       Filename:  hole.c
 *
 *    Description:  test file hole
 *
 *        Version:  1.0
 *        Created:  11/14/16 00:20:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "apue.h"
#include <fcntl.h>

char    buf1[] = "abcdefghij";
char    buf2[] = "ABCDEFGHIJ";

int main(int argc, char *argv[])
{
    int   fd;
    
    if ((fd = creat("file.hole", S_IRWXU)) < 0) {
        printf("creat error");
        return 1;
    }

    if (write(fd, buf1, 10) != 10) {
        printf("buf1 write error");
        return 1;
    }

    if (lseek(fd, 16384, SEEK_SET) == -1) {
        printf("lseek error");
        return 1;
    }

    if (write(fd, buf2, 10) != 10) {
        printf("buf2 write error");
        return 1;
    }

    return 0;
}
