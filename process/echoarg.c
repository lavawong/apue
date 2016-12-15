/*
 * =====================================================================================
 *
 *       Filename:  args.c
 *
 *    Description:  print args
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

int
main(int argc, char *argv[])
{
    int     i;
    
    for (i = 0; i < argc; i++)
        printf("argv[%d]: %s\n", i, argv[i]);
    exit(0); /* return 0; */
}

