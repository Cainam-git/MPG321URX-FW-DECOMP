/* _close_r  (FUN_a015e224)
 *
 * Close a file descriptor (reentrant wrapper).
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015e224 @ 0xa015e224, flags -mcpu=v8 -O2 -g.
 */
extern unsigned int libc_errno; /* 0xa802e40c */
extern int sys_return_zero_copy5(int param); /* 0xa015e7d8 */

/*
 * Reentrant form of close: clear libc_errno (0xA802E40C), call sys_return_zero_copy5(fd), which always returns 0,
 * and return its result. When the result is -1 and libc_errno has become non-zero, the value is also
 * stored at *errno_ptr.
 */
int _close_r(unsigned int *errno_ptr, int fd)
{
    int result;

    libc_errno = 0;
    result = sys_return_zero_copy5(fd);
    if ((result == 0xffffffff) && (libc_errno != 0)) {
        *errno_ptr = libc_errno;
    }
    return result;
}
