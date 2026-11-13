/* __st_pthread_mutex_unlock  (FUN_a015ea68)
 *
 * Call the optional mutex-unlock hook; return 0 when none is installed.
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015ea68 @ 0xa015ea68 (-mcpu=v8 -O2 -g)
 * Same form as __st_pthread_mutex_destroy / __st_pthread_mutex_lock.
 */
extern int (*libc_mutex_unlock_hook)(int);
extern int __st_pthread_mutex_unlock(int param_1);

/*
 * Call the hook at 0xA802CFE0 with the argument and return its result; return 0 when no hook is stored there.
 */
int __st_pthread_mutex_unlock(int mutex)
{
    int result = 0;
    if (libc_mutex_unlock_hook != 0) {
        result = libc_mutex_unlock_hook(mutex);
    }
    return result;
}
