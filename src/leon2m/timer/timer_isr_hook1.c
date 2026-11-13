/* timer_isr_hook1  (FUN_a002d10c)
 *
 * Call timer hook 1 (word 0xA802B0D4) with 1 when set.
 * Note: Nothing in the image refers to it (no call, no stored address); of the hook callers only
 *   timer_isr_hook4 is registered, by timer_init.
 * Name basis: descriptive - hook words follow the tick record 0xA802B0C4 (hook 0 at 0xA802B0D0 called with 0
 *   by timer_tick_isr)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002d10c @ 0xa002d10c, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the routine returns its first parameter (%i0 is not touched, so the restore hands it back in
 * %o0); the hook is declared as a function without a prototype.
 */
typedef int hook_function();
extern hook_function *timer_hook1;     /* hook 1 of timer_tick_record (+0x10) */

#define HOOK_NUMBER 1                   /* each hook is called with its own number */

/*
 * Call hook 1 of the timer record with 1 when it is set. Nothing in the image refers to this routine (no
 * call, branch, sethi/or constant or address word); timer_isr_hook4 is the one timer_init registers.
 * 'value' comes back unchanged; 'unused' is not used.
 */
int timer_isr_hook1(unsigned int value, unsigned int unused)
{
  if (timer_hook1 != 0) {
    (*timer_hook1)(HOOK_NUMBER);
  }
  return value;
}