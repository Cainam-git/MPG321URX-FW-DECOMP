/* __st_pthread_mutex_destroy  (FUN_a015e9d8)
 *
 * Call the optional mutex-destroy hook; return 0 when none is installed.
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015e9d8 @ 0xa015e9d8 (-mcpu=v8 -O2 -g)
 */
typedef int (*code)(int);
extern code libc_mutex_destroy_hook;

/*
 * Call the hook at 0xA802CFEC with the argument and return its result; return 0 when no hook is stored there.
 */
int __st_pthread_mutex_destroy(int mutex)
{
    int result;
    result = 0;
    if (libc_mutex_destroy_hook != 0) {
        result = libc_mutex_destroy_hook(mutex);
    }
    return result;
}
