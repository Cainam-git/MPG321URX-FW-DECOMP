/* timer_isr_hook3  (FUN_a002d148)
 *
 * Call timer hook 3 (word 0xA802B0DC) with 3 when set.
 * Note: Nothing in the image refers to it (no call, no stored address); of the hook callers only
 *   timer_isr_hook4 is registered, by timer_init.
 * Name basis: descriptive - same hook words as timer_isr_hook1 (hook 3 at 0xA802B0DC)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002d148 @ 0xa002d148, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the routine returns its first parameter (%i0 is not touched, so the restore hands it back in
 * %o0); the hook is declared as a function without a prototype.
 */
typedef int hook_function();
extern hook_function *timer_hook3;     /* hook 3 of timer_tick_record (+0x18) */

#define HOOK_NUMBER 3                   /* each hook is called with its own number */

/*
 * Call hook 3 of the timer record with 3 when it is set. Nothing in the image refers to this routine (no
 * call, branch, sethi/or constant or address word); timer_isr_hook4 is the one timer_init registers.
 * 'value' comes back unchanged; 'unused' is not used.
 */
int timer_isr_hook3(unsigned int value, unsigned int unused)
{
  if (timer_hook3 != 0) {
    (*timer_hook3)(HOOK_NUMBER);
  }
  return value;
}