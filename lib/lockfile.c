/**
 * Created by Lava Wong on 2022/2/28.
 */
#include <stdio.h>
/**
 * 尝试获取文件描述符的锁
 * @param fd file descriptor
 * @return 0 成功；-1 失败；
 */
int lockfile(int fd) {
    FILE *fp = fdopen(fd, "w");
    if (ftrylockfile(fp) == 0){
        return 0;
    } else {
        return -1;
    }
}
