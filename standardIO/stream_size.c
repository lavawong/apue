/*
 * =====================================================================================
 *
 *       Filename:  fileno.c
 *
 *    Description:  test fileno
 *
 *        Version:  1.0
 *        Created:  11/23/16 23:44:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lavawong 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "apue.h"
#include <sys/errno.h>

void    pr_stdio(const char *, FILE *);
int     is_unbuffered(FILE *);
int     is_linebuffered(FILE *);
int     buffer_size(FILE *);

int
main(void)
{
    FILE    *fp;
    
    fputs("Enter any character:\n", stdout);
    if (getchar() == EOF) {
        printf("getchar error: %s\n", strerror(errno));
    }
    fputs("one line to standard error\n", stderr);
    
    pr_stdio("stdin", stdin);
    pr_stdio("stdout", stdout);
    pr_stdio("stderr", stderr);
    
    if ((fp = fopen("/etc/passwd", "r")) == NULL) {
        printf("fopen error: %s\n", strerror(errno));
        return 1;
    }

    if (getc(fp) == EOF) {
        printf("getc error: %s\n", strerror(errno));
    }
    pr_stdio("/etc/passwd", fp);
    return 0;
}


void
pr_stdio(const char *name, FILE *fp)
{
    printf("stream = %s, ", name);
    if (is_unbuffered(fp))
        printf("unbuffered");
    else if (is_linebuffered(fp))
        printf("line buffered");
    else
        printf("fully buffered");
    printf(", buffer size = %d\n", buffer_size(fp));
}

#if defined(_IO_UNBUFFERED)
/* example: linux /usr/include/libio.h */
int
is_unbuffered(FILE *fp)
{
    return (fp->_flags & _IO_UNBUFFERED);
}

int
is_linebuffered(FILE *fp)
{
    return (fp->_flags & _IO_LINE_BUF);
}

int
buffer_size(FILE *fp)
{
    return (fp->_IO_buf_end - fp->_IO_buf_base);
}

#elif defined(__SNBF)
/* example: android bionic stdio.h */
int
is_unbuffered(FILE *fp)
{
    return (fp->_flags & __SNBF);
}

int
is_linebuffered(FILE *fp)
{
    return (fp->_flags & __SLBF);
}

int
buffer_size(FILE *fp)
{
    return (fp->_bf._size);
}

#elif defined(_IONBF)

/*
    The GNU C Library [12.20.3]
    https://www.gnu.org/software/libc/manual/html_node/index.html#SEC_Contents
*/
#ifdef  _LP64
#define _flag __pad[4]
#define _ptr  __pad[1]
#define _base  __pad[2]
#endif

int
is_unbuffered(FILE *fp)
{
    return (fp->_flags & _IONBF);
}

int
is_linebuffered(FILE *fp)
{
    return (fp->_flags & _IOLBF);
}

int
buffer_size(FILE *fp)
{
#ifdef _LP64
    return (fp->_base - fp->_ptr);
#else
    return (BUFSIZ); /* just a guess */
#endif
}

#else

#error unknown stdio implementation!

#endif

