/* __fp_lock_all  (FUN_a015b780)
 *
 * Take the stream-list lock and lock every open stream.
 * Name basis: proven - __sfp_lock_acquire, then _fwalk with __fp_lock (newlib findfp.c)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015b780 @ 0xa015b780-0xa015b7a0 (8 words), flags -mcpu=v8 -O2 -g.
 * The callback address is 0x000fb738 (fw sethi 0xfb400 | 0x338), not __fp_lock; the source names it
 * FUN_000fb738 so that the link resolves to the real address. The _fwalk call is a tail call.
 */
extern unsigned int _impure_ptr;
extern void __sfp_lock_acquire(void);
extern int _fwalk(void *reent, int (*fn)(void *));
extern int __fp_lock(void *fp);

/*
 * Lock the stream list (__sfp_lock_acquire), then call _fwalk on the state record _impure_ptr with the routine
 * at 0xFB738 as the callback, which _fwalk applies to every open stream of the record.
 */
void __fp_lock_all(void)
{
  __sfp_lock_acquire();
  _fwalk((void *)_impure_ptr, __fp_lock);
}
