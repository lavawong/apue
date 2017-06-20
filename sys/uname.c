/*
 * =====================================================================================
 *
 *       Filename:  uname.c
 *
 *    Description:  get uname
 *
 *        Version:  1.0
 *        Created:  11/26/16 23:03:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lavawong
 *   Organization:  
 *
 * =====================================================================================
 */

#include "apue.h"
#include <sys/utsname.h>

int
main(void)
{
    struct utsname *name = NULL;
    
    if (uname(name) != -1) {
        printf("sysname \t nodename \t release \t version \t machine\n");
        printf("%s \t %s \t %s \t %s \t %s\n", name->sysname, name->nodename, name->release, name->version, name->machine);
    } else {
        printf("Read uname failure!\n");
    }

    return 0;
}

