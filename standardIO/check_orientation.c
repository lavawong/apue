/*
 * =====================================================================================
 *
 *       Filename:  check_orientation.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/22/16 21:42:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lavawong, 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "apue.h"
#include <wchar.h>

typedef enum { FALSE, TRUE } BOOL;

void check_orientation(FILE *stream)
{
    int rc;
    rc = fwide(stream, 0);
    if (rc < 0) {
        printf("Stream has byte orientation.\n");
    } else if (rc > 0) {
        printf("Stream has wide orientation.\n");
    } else {
        printf("Stream has no orientation.\n");
    }
    return;
}

int main(int argc, char *argv[])
{
    FILE *stream;
    BOOL is_open_file = FALSE;
    /* 
       Demonstrate that fwide can be used to set the orientation,
       but cannot change it once it has been set.
       */
    if (argc < 2) {
        stream = stdin;
        printf("Current stream is stdin\n");
    } else {
        stream = fopen(argv[1], "r");
        is_open_file = TRUE;
        if (NULL == stream) {
            printf("Unable to open: %s\n", argv[1]);
            return 1;
        }
        printf("Current stream is file: %s\n", argv[1]);
    }
    check_orientation(stream);
    fwide(stream, -1);
    printf("After fwide(stream, -1);\n");
    check_orientation(stream);
    fwide(stream, 1);
    printf("After fwide(stream, 1);\n");
    check_orientation(stream);
    fwide(stream, 0);
    printf("After fwide(stream, 0);\n");
    check_orientation(stream);
    if (is_open_file == TRUE) {
        fclose(stream);
        printf("Close the stream\n");
        stream = fopen(argv[1], "r");
        check_orientation(stream);
        fwprintf(stream, L"pi = %.5f", 4 * atan(1.0));
        printf("After fwprintf(): ");
        check_orientation(stream);
        fclose(stream);
    }

    return 0;
}


