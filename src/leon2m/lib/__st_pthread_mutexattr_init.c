/* __st_pthread_mutexattr_init  (FUN_a015ea98)
 *
 * Call the optional mutex-attribute-init hook; return 0 when none is installed.
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015ea98 @ 0xa015ea98 (-mcpu=v8 -O2 -g)
 * Same code as __st_pthread_mutex_destroy with other constants.
 */
typedef int (*code)(int);
extern code libc_mutexattr_init_hook;

/*
 * Call the hook at 0xA802CFDC with the attribute argument and return its result; return 0 when no hook is stored there.
 */
int __st_pthread_mutexattr_init(int attr)
{
    int result;
    result = 0;
    if (libc_mutexattr_init_hook != 0) {
        result = libc_mutexattr_init_hook(attr);
    }
    return result;
}
