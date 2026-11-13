/* __st_pthread_mutexattr_settype  (FUN_a015eaf8)
 *
 * Call the optional mutex-attribute-settype hook; return 0 when none is installed.
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015eaf8 @ 0xa015eaf8 (-mcpu=v8 -O2 -g)
 * Same shape as __st_pthread_mutex_init (hook at 0xA802CFF0) and the one-argument hook callers __st_pthread_mutex_destroy..__st_pthread_mutexattr_destroy
 * between them.
 */
extern int (*libc_mutexattr_settype_hook)(int, int);

/*
 * Call the hook at 0xA802CFD4 with both arguments and return its result; return 0 when no hook is stored there.
 */
int __st_pthread_mutexattr_settype(int attr, int type)
{
    int result = 0;
    if (libc_mutexattr_settype_hook != 0) {
        result = libc_mutexattr_settype_hook(attr, type);
    }
    return result;
}
