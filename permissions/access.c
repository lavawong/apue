/*
 * =====================================================================================
 *
 *       Filename:  access.c
 *
 *    Description:  detect access permissions
 *
 *        Version:  1.0
 *        Created:  11/19/16 00:49:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lavawong  
 *   Organization:  
 *
 * =====================================================================================
 */

#include "apue.h"
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage: access.out <pathname>\n");
        return 1;
    }
    if (access(argv[1], R_OK) < 0) {
        printf("access error for %s: %s\n", argv[1], strerror(errno));
    } else {
        printf("read access OK\n");
    }
    if (open(argv[1], O_RDONLY) < 0) {
        printf("open error for %s: %s\n", argv[1], strerror(errno));
    } else {
        printf("open for reading OK\n");
    }
    
    return 0;
}


