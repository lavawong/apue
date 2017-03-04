/*
 * =====================================================================================
 *
 *       Filename:  passwd.c
 *
 *    Description:  getpwuid
 *
 *        Version:  1.0
 *        Created:  11/25/16 00:35:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lavawong
 *   Organization:  
 *
 * =====================================================================================
 */

#include "apue.h"
#include <pwd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>


struct passwd *
getpwnam(const char *name)
{
    printf("my getpwnam method\n");
    struct passwd   *ptr;

    setpwent();
    while ((ptr = getpwent()) != NULL)
        if (strcmp(name, ptr->pw_name) == 0)
            break;
    endpwent();
    return (ptr);
}


int
main(int argc, char *argv[])
{
    int             uid;
    char            name[64];
    char            *endptr;
    char            *nptr;
    struct passwd   *pwd;

    if (argc < 2) {
        printf("Usage : passwd.out <UserName|uid>");
        return 1;
    }    

    nptr = argv[1];
    endptr = name;
    uid = strtol(nptr, &endptr, 10);
    printf("endptr: %s \t uid:%d \t nptr:%s\n", endptr, uid, nptr);
    if (0 != strlen(endptr)) {
        printf("getpwnam\n");
        pwd = getpwnam( nptr );
    } else {
        printf("getpwuid\n");
        pwd = getpwuid( (uid_t)uid );
    }
    if (NULL != pwd) {
        
        printf("%12s \t %10s \t %10s \t %10s\n", "User", "uid", "gid", "pwd");
        printf("%12s \t %10d \t %10d \t %10s\n", pwd->pw_name, pwd->pw_uid, pwd->pw_gid, pwd->pw_passwd);
        return 0;
    } else {
        printf("Cannot find user: %s\n", nptr);
        return 1;
    }
}

