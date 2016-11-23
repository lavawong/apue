/*
 * =====================================================================================
 *
 *       Filename:  tmp_dir.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  11/24/16 02:12:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author: lavawong 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "apue.h"
#include <errno.h>

void make_temp(char *);

int
main()
{
    char        good_temp[] = "/tmp/dirXXXXXX";
    char        *bad_temp   = "/tmp/dirXXXXXX";
    printf("trying to create first temp file...\n");
    make_temp(good_temp);
    printf("trying to create second temp file...\n");
    make_temp(bad_temp);
    return 0;
}

void
make_temp(char *tmp)
{
    int         fd;
    struct stat sbuf;
    
    if ((fd = mkstemp(tmp)) < 0) {
        printf("can't create temp file\n");
    } else {
        printf("temp name = %s\n", tmp);
        close(fd);
        if (stat(tmp, &sbuf) < 0) {
            if (errno == ENOENT) 
                printf("file doesn't exist\n");
            else
                printf("stat failed\n");
        } else {
            printf("file exists\n");
            unlink(tmp);
        }
    }
}




