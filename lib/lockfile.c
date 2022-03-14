/**
 * Created by Lava Wong on 2022/2/28.
 */
#include <fcntl.h>

int lockfile(int fd) {
//    struct flock lock;
//    lock.l_type = F_WRLCK;
//    lock.l_whence = SEEK_SET;

    if (flock(fd, LOCK_EX | LOCK_NB) == 0){
        return 0;
    } else {
        return -1;
    }
}
