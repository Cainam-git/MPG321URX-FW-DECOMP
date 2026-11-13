/* sys_set_timed_toggle_target  (FUN_CODE_de03)
 *
 * Store a target word and select toggle mode for the timed effect.
 *   target
 * Name basis: descriptive - command 0x18; record 0xA735 stepped by sys_run_timed_ramp (mode 1 toggles bits at
 *   an address)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_de03 @ 0xde03
 * Byte-exact with OPTIMIZE(8,SPEED) (also level 7).
 */
#define TIMED_MODE_TOGGLE 1   /* sys_timed_mode value */

extern unsigned int xdata sys_timed_target;
extern unsigned char xdata sys_timed_mode;

/* Store the toggle target address and select mode 1 (toggle) of the timed
 * effect. Run for mailbox command 0x18; only caller: the call at 0x2579.
 *   target: toggle target address */
void sys_set_timed_toggle_target(unsigned int target)
{
    sys_timed_target = target;
    sys_timed_mode = TIMED_MODE_TOGGLE;
}
