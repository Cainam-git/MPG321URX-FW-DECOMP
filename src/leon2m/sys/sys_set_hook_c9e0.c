/* sys_set_hook_c9e0  (FUN_a0121eac)
 *
 * Store the hook pointer at 0xA802C9E0.
 * Name basis: descriptive - called by the unit event routine when set; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0121eac @ 0xa0121eac-0xa0121eb8, flags -mcpu=v8 -O2 -g. Source form: a direct store to the
 * extern symbol (the store sits in the retl delay slot).
 */
extern unsigned int sys_unit0_hook;

/* Set the routine that sys_latch_unit_event_ch0 calls (when not 0) after it has handled unit 0's event. */
void sys_set_hook_c9e0(unsigned int hook)
{
    sys_unit0_hook = hook;
}
