/* __malloc_unlock  (FUN_a015cc6c)
 *
 * Release the heap lock.
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015cc6c @ 0xa015cc6c, flags -mcpu=v8 -O2 -g.
 * Source form: the decompiler's form is kept.
 */
extern int __st_pthread_mutex_unlock();

#define MALLOC_LOCK 0xa802aec0          /* the lock object of the heap */

/*
 * Unlock the heap: __st_pthread_mutex_unlock on the lock object at 0xA802AEC0.
 */
void __malloc_unlock(void)

{
  __st_pthread_mutex_unlock(MALLOC_LOCK);
  return;
}
