/* __sfp_lock_acquire  (FUN_a015b5f4)
 *
 * Take the lock that protects the list of streams.
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015b5f4 @ 0xa015b5f4, flags -mcpu=v8 -O2 -g.
 * Source form: the decompiler's form is kept.
 */
extern int __st_pthread_mutex_lock();

#define SFP_LOCK 0xa802aa20             /* the lock object of the stream list */

/*
 * Lock the stream list: __st_pthread_mutex_lock on the lock object at 0xA802AA20.
 */
void __sfp_lock_acquire(void)

{
  __st_pthread_mutex_lock(SFP_LOCK);
  return;
}