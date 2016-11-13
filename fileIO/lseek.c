/*
 * =====================================================================================
 *
 *       Filename:  lseek.c
 *
 *    Description:  test lseek system call
 *
 *        Version:  1.0
 *        Created:  11/13/16 23:22:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lavawong, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc < 1) {
        printf("Error need file path\n");
        return 1;
    }

    char  *path;
    int   fd;
    off_t currpos, offset;


    printf("argv[0]:%s  argv[1]:%s\n", argv[0], argv[1]);
    path = argv[1];
    offset = 0;
    if (path == NULL) {
        printf("Path is null\n");
        currpos = lseek(STDIN_FILENO, offset, SEEK_CUR);
        path = "STDIN_FILENO";
    } else {
        printf("Path is %s\n", path);
        fd = open(path, O_RDONLY);
        if (fd == -1) {
            printf("Error open file %s\n", path);
            return 1;
        }
        currpos = lseek(STDIN_FILENO, offset, SEEK_CUR);
    }

    if (currpos == -1) {
        printf("Error lseek file %s in offset %ld\n", path, (long)offset);
        return 1;
    } else {
        printf("lseek file %s in offset %ld success!\n", path, (long)offset);
    }
    if (fd > 2) {
        close(fd);
    }

    return 0;
}
