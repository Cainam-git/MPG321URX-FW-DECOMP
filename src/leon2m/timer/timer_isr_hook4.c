/* timer_isr_hook4  (FUN_a002d174)
 *
 * Call timer hook 4 (word 0xA802B0E0) with 4 when set.
 * Note: No direct caller: installed as an interrupt source handler.
 * Name basis: derived - same hook table as timer_isr_hook1
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002d174 @ 0xa002d174, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the routine returns its first parameter (%i0 is not touched, so the restore hands it back in
 * %o0); the hook is declared as a function without a prototype.
 */
typedef int hook_function();
extern hook_function *timer_hook4;     /* hook 4 of timer_tick_record (+0x1C) */

#define HOOK_NUMBER 4                   /* each hook is called with its own number */

/*
 * Call hook 4 of the timer record with 4 when it is set. timer_init registers this routine as the handler
 * of interrupt level 4, source 4 (bit 0x10), and unmasks that source. 'value' comes back unchanged (the
 * level handler ignores it); 'unused' is not used.
 */
int timer_isr_hook4(unsigned int value, unsigned int unused)
{
  if (timer_hook4 != 0) {
    (*timer_hook4)(HOOK_NUMBER);
  }
  return value;
}