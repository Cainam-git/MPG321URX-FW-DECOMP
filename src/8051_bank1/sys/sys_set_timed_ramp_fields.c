/* sys_set_timed_ramp_fields  (FUN_CODE_d70f)
 *
 * Store two ramp field values and select ramp mode for the timed effect.
 *   slot: field 0/1
 *   record_index: 3-bit target
 *   rate: 5-bit rate
 * Name basis: descriptive - command 0x30; record 0xA735 stepped by sys_run_timed_ramp (mode 2 ramps bytes
 *   up/down)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d70f @ 0xd70f
 * Byte-exact with OPTIMIZE(8,SPEED) ONLY (level 7 gives 41 B).
 */
#define TIMED_MODE_RAMP 2  /* value of sys_timed_mode: ramp */
#define TIMED_SLOT_LAST 1  /* highest slot of sys_timed_target */

extern unsigned char xdata sys_timed_target[];
extern unsigned char xdata sys_timed_mode;

/*
 * Store the two fields of a timed ramp entry and set the timed mode to ramp. 'slot' (0 or 1, larger values are
 * cut to 1) picks the byte of sys_timed_target; the byte gets 'record_index' (3 bits) in bits 5..7 and 'rate'
 * (5 bits) in bits 0..4. The caller of this routine is at 0x25a6. The 0xA73A pair is also written by
 * sys_set_timed_toggle_target, which sets the mode to 1.
 */
void sys_set_timed_ramp_fields(unsigned char slot, unsigned char record_index, unsigned char rate)
{
    if (slot > TIMED_SLOT_LAST) slot = TIMED_SLOT_LAST;
    sys_timed_target[slot] = ((record_index & 7) << 5) | (rate & 0x1f);
    sys_timed_mode = TIMED_MODE_RAMP;
}
