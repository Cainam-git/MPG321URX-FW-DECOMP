/* ldc_user_send_cmd_0x61  (FUN_a00db678)
 *
 * Send dimming command 0x61 with selector 7 and a value.
 * Name basis: descriptive - tail call; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00db678 @ 0xa00db678-0xa00db690 (6 words), flags -mcpu=v8 -O2 -g.
 * Source form: a single call as the last statement, which the compiler makes a tail call.
 */

#define LDC_CMD_0x61_SELECTOR  7        /* first byte value sent with the command */

extern void ldc_send_led_driver_register(unsigned char, unsigned char);

/*
 * Send dimming command 0x61 with the selector 7 and the given value.
 * Nothing in the image calls this routine or stores its address.
 */
void ldc_user_send_cmd_0x61(unsigned char value)
{
    ldc_send_led_driver_register(LDC_CMD_0x61_SELECTOR, value);
}
