/* __st_pthread_mutex_lock  (FUN_a015ea08)
 *
 * Call the optional mutex-lock hook; return 0 when none is installed.
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015ea08 @ 0xa015ea08 (-mcpu=v8 -O2 -g)
 * Source form: the hook result is returned from inside the if; the other path returns 0.
 */
extern int (*libc_mutex_lock_hook)(int);

/*
 * Call the hook at 0xA802CFE4 with the argument and return its result; return 0 when no hook is stored there.
 */
int __st_pthread_mutex_lock(int mutex)
{
    if (libc_mutex_lock_hook != 0) {
        return libc_mutex_lock_hook(mutex);
    }
    return 0;
}
