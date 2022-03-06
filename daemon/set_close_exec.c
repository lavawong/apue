#include "apue.h"
#include <fcntl.h>

int set_close_exec(int fd) {
  int val;
  if ((val = fcntl(fd, F_GETFD, 0)) < 0) {
    return -1;
  }

  val |= FD_CLOEXEC; /* enalbe close-on-exec */

  return fcntl(fd, F_SETFD, val);
}