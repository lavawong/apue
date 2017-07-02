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
#include <stdlib.h>
#include <unistd.h>

#ifndef __USE_POSIX
#define __USE_POSIX
#endif

#include <limits.h>


int
main(void)
{
    char    *hostname = NULL;
    long    host_name_max;
#ifdef _SC_HOST_NAME_MAX
    host_name_max = sysconf(_SC_HOST_NAME_MAX);
#elif _POSIX_HOST_NAME_MAX
    host_name_max = _POSIX_HOST_NAME_MAX;
#endif
    if (host_name_max <=0 )
        host_name_max = 64; /* guess linux 3.2.0 is defined 64*/
    
    if (gethostname(hostname, host_name_max) != -1) {
        printf("hostname: %s\n", hostname);
    } else {
        printf("Get hostname failure!\n");
    }
    return 0;
}

