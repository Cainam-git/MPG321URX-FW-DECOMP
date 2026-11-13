/* __st_pthread_mutex_init  (FUN_a015e9a4)
 *
 * Call the optional mutex-init hook; return 0 when none is installed.
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015e9a4 @ 0xa015e9a4 (-mcpu=v8 -O2 -g)
 * Same shape as the one-argument hook callers __st_pthread_mutex_destroy..__st_pthread_mutexattr_destroy that follow it and as the two-argument
 * __st_pthread_mutexattr_settype (hook at 0xA802CFD4).
 */
extern int (*libc_mutex_init_hook)(unsigned int, unsigned int);

/*
 * Call the hook at 0xA802CFF0 with both arguments and return its result; return 0 when no hook is stored there.
 */
int __st_pthread_mutex_init(unsigned int mutex, unsigned int attr)
{
    if (libc_mutex_init_hook != 0)
        return libc_mutex_init_hook(mutex, attr);
    return 0;
}
