/* __malloc_lock  (FUN_a015cc54)
 *
 * Take the heap lock.
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015cc54 @ 0xa015cc54, flags -mcpu=v8 -O2 -g.
 * Source form: the decompiler's form is kept.
 */
extern int __st_pthread_mutex_lock();

#define MALLOC_LOCK 0xa802aec0          /* the lock object of the heap */

/*
 * Lock the heap: __st_pthread_mutex_lock on the lock object at 0xA802AEC0.
 */
void __malloc_lock(void)

{
  __st_pthread_mutex_lock(MALLOC_LOCK);
  return;
}
