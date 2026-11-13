/* __fp_unlock_all  (FUN_a015b7a0)
 *
 * Unlock every open stream and release the stream-list lock.
 * Name basis: proven - _fwalk with __fp_unlock, then __sfp_lock_release (newlib findfp.c)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015b7a0 @ 0xa015b7a0, flags -mcpu=v8 -O2 -g.
 * Source form: the decompiler's form is kept: __sfp_lock_release is declared without a parameter list and given
 * the six parameters of this routine.
 */
typedef unsigned int undefined4;
extern unsigned char libc_fp_unlock_entry[];
extern unsigned int _impure_ptr;
extern int __sfp_lock_release();
extern int _fwalk();

/*
 * Call _fwalk on the state record _impure_ptr with the routine at libc_fp_unlock_entry (0xFB75C) as the
 * callback, which _fwalk applies to every open stream, then release the stream list lock
 * (__sfp_lock_release). The six parameters are not used; they are only passed on to __sfp_lock_release.
 */
void __fp_unlock_all(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  _fwalk(_impure_ptr,libc_fp_unlock_entry);
  __sfp_lock_release(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}
