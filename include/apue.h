/**
 * apue head
 */

#ifndef _APUE_H
#define _APUE_H

#define _POSIX_C_SOURCE 200809L

#if defined(SOLARIS)        /* Solaris 10 */
#define _XOPEN_SOURCE 600
#else
#define _XOPEN_SOURCE 700
#endif

#include <sys/types.h>      /* some systems still require this */
#include <sys/stat.h>
#include <sys/termios.h>    /* for winsize */
#if defined(MACOS) || !defined(TIOCGWINSZ)
#include <sys/ioctl.h>
#endif

#include <stdio.h>      /* for convenience */
#include <stdlib.h>     /* for convenience */
#include <stddef.h>     /* for offsetof */
#include <string.h>     /* for convenience */
#include <unistd.h>     /* for convenience */
#include <signal.h>     /* for SIG_ERR */

#define MAXLINE 4096            /* max line length */
typedef long long LLONG;
typedef unsigned long long ULLONG;
typedef long LONG;
typedef int16_t BOOL;
#define TRUE  1
#define FALSE 0

/* register lock operation */
#define read_lock(fd,offset,whence,len) \
    lock_reg(fd, F_SETLK,F_RDLCK,(offset),(whence),(len))
#define readw_lock(fd,offset,whence,len) \
    lock_reg(fd, F_SETLKW,F_RDLCK,(offset),(whence),(len))
#define write_lock(fd,offset,whence,len) \
    lock_reg(fd, F_SETLK,F_WRLCK,(offset),(whence),(len))
#define writew_lock(fd,offset,whence,len) \
    lock_reg(fd, F_SETLKW,F_WRLCK,(offset),(whence),(len))
#define un_lock(fd,offset,whence,len) \
    lock_reg(fd, F_SETLKW,F_UNLCK,(offset),(whence),(len))
#define is_read_lockable(fd,offset,whence,len) \
    lock_reg(fd, F_RDLCK,(offset),(whence),(len))
#define is_write_lockable(fd,offset,whence,len) \
    lock_reg(fd, F_WRLCK,(offset),(whence),(len))


void err_dump(const char *, ...); /* {App misc_source} */
void err_msg(const char *, ...);
void err_quit(const char *, ...);
void err_exit(int, const char *, ...);
void err_ret(const char *, ...);
void err_sys(const char *, ...);

void log_msg(const char *, ...); /* {App misc_source} */
void log_open(const char *, int, int);
void log_quit(const char *, ...);
void log_ret(const char *, ...);
void log_sys(const char *, ...);

void TELL_WAIT(void); /* parent/child from {Sec race_conditions} */
void TELL_PARENT(pid_t);
void TELL_CHILD(pid_t);
void WAIT_PARENT(void);
void WAIT_CHILD(void);

void pr_exit(int);
/**
 * Lock file descriptor with non block.
 * @param fd file descriptor
 * @return 0 success, -1 failure
 */
int lockfile(int fd);
/**
 * Lock file register
 * @param fd file descriptor
 * @param cmd FCNTL(2) lock cmd, EXAMPLE: F_SETLKW or F_SETLK
 * @param type F_RDLCK, F_WRLCK, F_UNLCK
 * @param offset byte offset, relative to whence
 * @param whence SEEK_SET, SEEK_CUR, SEEK_END
 * @param len lock offset to offset+len #bytes (0 means to EOF
 * @return 0 success, -1 error
 */
int lock_reg(int fd, int cmd, int type, off_t offset, int whence, off_t len);
/**
 *
 * @param fd file descriptor
 * @param type F_RDLCK, F_WRLCK
 * @param offset byte offset, relative to whence
 * @param whence SEEK_SET, SEEK_CUR, SEEK_END
 * @param len lock offset to offset+len #bytes (0 means to EOF
 * @return true, return pid of lock owner
 */
pid_t lock_test(int fd, int type, off_t offset, int whence, off_t len);

int set_cloexec(int fd);
/**
 * 设置文描述父标志
 * @param fd 文件 FD
 * @param flags 标识
 * @return
 */
void set_fl(int fd, int flags);
/**
 * 清除文件描述符标志
 * @param fd 文件 FD
 * @param flags 标识
 */
void clr_fl(int fd, int flags);

#endif /* _APUE_H */
