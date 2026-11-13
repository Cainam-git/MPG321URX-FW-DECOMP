/* __st_pthread_mutex_trylock  (FUN_a015ea38)
 *
 * Call the optional mutex-trylock hook; return 0 when none is installed.
 * Name basis: derived - same form as its neighbours __st_pthread_mutex_lock / _unlock, hook pointer at
 *   0xA802CFE8; the name itself is not referenced
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015ea38 @ 0xa015ea38 (-mcpu=v8 -O2 -g)
 * Source form: the second parameter is declared although it is not used.
 */
extern int (*libc_mutex_trylock_hook)(int);

/*
 * Call the hook at 0xA802CFE8 with the first argument and return its result; return 0 when no hook is stored
 * there. The second argument is not used.
 */
int __st_pthread_mutex_trylock(int mutex, int unused)
{
    if (libc_mutex_trylock_hook != 0) {
        return libc_mutex_trylock_hook(mutex);
    }
    return 0;
}
