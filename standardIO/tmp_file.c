/*
 * =====================================================================================
 *
 *       Filename:  tmp.c
 *
 *    Description:  tmpnam and tmpfile function
 *
 *        Version:  1.0
 *        Created:  11/24/16 02:00:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "apue.h"

int
main(void)
{
    char    name[L_tmpnam], line[MAXLINE];
    FILE    *fp;

    printf("%s\n", tmpnam(NULL));

    tmpnam(name);
    printf("%s\n", name);

    if ( (fp = tmpfile()) == NULL) {
        printf("tmpfile error");
        return 1;
    }

    fputs("one line of output\n", fp);

    rewind(fp);
    if (fgets(line, sizeof(line), fp) == NULL) {
        printf("fgets error");
        return 1;
    }
    fputs(line, stdout);
    
    return 0;
}
