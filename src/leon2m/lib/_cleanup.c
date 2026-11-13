/* _cleanup  (FUN_a015b5dc)
 *
 * Flush and close all open streams of the global reentrancy structure.
 * Name basis: proven - calls _cleanup_r(_global_impure_ptr) (newlib findfp.c)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015b5dc @ 0xa015b5dc-0xa015b5f4 (6 words), flags -mcpu=v8 -O2 -g.
 * Tail call of _cleanup_r: the caller's return address is handed on, so the callee returns straight to this
 * routine's caller. The last word is the nop the compiler places behind such a call sequence.
 */
typedef unsigned int undefined4;
extern unsigned int _global_impure_ptr;
extern void _cleanup_r(undefined4);

/*
 * Call _cleanup_r with the global state record _global_impure_ptr.
 * Nothing in the firmware calls this routine and no stored address points at it.
 */
void _cleanup(void)
{
    _cleanup_r(_global_impure_ptr);
}
