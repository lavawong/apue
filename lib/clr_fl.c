/**
 * Created by Lava Wong on 2022/3/13.
 */
#include "apue.h"
#include <fcntl.h>

void clr_fl(int fd, int flags) {
    int val;
    if ((val = fcntl(fd, F_GETFL, 0)) < 0) {
        err_sys("fcntl F_GETFL error");
    }

    val &= ~flags; /* turn flags off */

    if (fcntl(fd, F_SETFL, val) < 0) {
        err_sys("fcntl F_SETFL error");
    }
}