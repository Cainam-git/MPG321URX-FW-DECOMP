/* ldc_api_set_dimming_mode  (FUN_a014bd0c)
 *
 * Send the mode 0..3 to the dimming processor, with a follow-up command for modes 1 and 2.
 * Name basis: descriptive - commands through mailbox portal 2, slot 0x20
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014bd0c, flags -mcpu=v8 -O2 -g.
 * Source form the exact build depends on: an if/else chain that tests the mode 0, 1, 2, 3 in that order (the
 * firmware tests them in that order).
 */
extern void ldc_send_ldc_mode(unsigned int mode);
extern void ldc_send_cmd_0x42(unsigned char on);

/*
 * Send the dimming mode to the dimming processor.
 *
 *   mode  0..3; anything else does nothing. The value sent with command 0x20 is 0 for mode 0, 1 for mode 1,
 *         3 for mode 2 and 2 for mode 3. Modes 1 and 2 also send command 0x42 with the value 1.
 *
 * Called by APPSetPowerOff, sys_user_apply_dimming_mode and ldc_user_set_dimming_mode.
 */
void ldc_api_set_dimming_mode(unsigned char mode)
{
    if (mode == 0) {
        ldc_send_ldc_mode(0);
    } else if (mode == 1) {
        ldc_send_ldc_mode(1);
        ldc_send_cmd_0x42(1);
    } else if (mode == 2) {
        ldc_send_ldc_mode(3);
        ldc_send_cmd_0x42(1);
    } else if (mode == 3) {
        ldc_send_ldc_mode(2);
    }
}
