/**
 * Created by Lava Wong on 2022/3/13.
 */

#include "apue.h"
#include <errno.h>
#include <fcntl.h>

char buf[500000];

/**
 * 观察 temp.file 与 stderr.file 的输出
 * ./non-block-io < /etc/services > temp.file
 * ./non-block-io < /etc/services 2>stderr.file
 *
 * @return
 */
int main(void) {
    LONG ntowrite, nwrite, total_nbyte = 0;
    int  readcount                     = 1;
    char *ptr;

    ntowrite = read(STDIN_FILENO, buf, sizeof(buf));
    fprintf(stderr, "read %zd byte\n", ntowrite);

    set_fl(STDOUT_FILENO, O_NONBLOCK); /* set nonblocking */

    ptr = buf;

    while (ntowrite > 0) {
        errno = 0;
        nwrite = write(STDOUT_FILENO, ptr, ntowrite);
        fprintf(stderr, "ntowrite = %zd, nwrite = %zd, errno = %d\n", ntowrite, nwrite, errno);
        if (nwrite > 0) {
            ptr += nwrite;
            ntowrite -= nwrite;
            total_nbyte += nwrite;
            readcount++;
        }
    }
    fprintf(stderr, "total_nbyte = %zd, readcount = %d\n", total_nbyte, readcount);
    clr_fl(STDOUT_FILENO, O_NONBLOCK); /* clear nonblocking */
}