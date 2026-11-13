/* __sfp_lock_release  (FUN_a015b60c)
 *
 * Release the lock that protects the list of streams.
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015b60c @ 0xa015b60c, flags -mcpu=v8 -O2 -g.
 * Source form: the decompiler's form is kept.
 */
extern int __st_pthread_mutex_unlock();

#define SFP_LOCK 0xa802aa20             /* the lock object of the stream list */

/*
 * Unlock the stream list: __st_pthread_mutex_unlock on the lock object at 0xA802AA20.
 */
void __sfp_lock_release(void)

{
  __st_pthread_mutex_unlock(SFP_LOCK);
  return;
}