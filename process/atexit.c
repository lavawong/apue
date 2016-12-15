/*
 * =====================================================================================
 *
 *       Filename:  atexit.c
 *
 *    Description:  test atexit
 *
 *        Version:  1.0
 *        Created:  11/27/16 20:58:01
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

void 
will_exit(void)
{
    printf("This is will_exit function\n");
}

int
main(void)
{
    printf("Test atexit\n");
    atexit(&will_exit);
    exit(0); /* return 0; */
    
}

