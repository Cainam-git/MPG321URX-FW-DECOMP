/* __st_pthread_mutexattr_destroy  (FUN_a015eac8)
 *
 * Call the optional mutex-attribute-destroy hook; return 0 when none is installed.
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015eac8 @ 0xa015eac8 (-mcpu=v8 -O2 -g)
 * Same code as __st_pthread_mutex_destroy with other constants.
 */
typedef int (*code)(int);
extern code libc_mutexattr_destroy_hook;

/*
 * Call the hook at 0xA802CFD8 with the attribute argument and return its result; return 0 when no hook is stored there.
 */
int __st_pthread_mutexattr_destroy(int attr)
{
    int result;
    result = 0;
    if (libc_mutexattr_destroy_hook != 0) {
        result = libc_mutexattr_destroy_hook(attr);
    }
    return result;
}
