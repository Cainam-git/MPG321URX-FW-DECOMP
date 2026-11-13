/* input_is_port_code_scalable  (FUN_a0121d4c)
 *
 * Return 0 when a port's signal code is one of thirteen listed codes, else 1.
 * Returns: 0 or 1
 * Name basis: descriptive - used to choose the scaling route
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0121d4c @ 0xa0121d4c, flags -mcpu=v8 -O3 -g.
 * Source form: one || chain of equality tests in this order (the compiler evaluates them in pairs with
 * xor/subx and orcc; the last test, 0xe8, stays a plain compare).
 */
extern unsigned char input_block_get_signal_code(unsigned char);

/*
 * Return 0 when the signal code of the port (input_block_get_signal_code) is 0x31, 0x41, 0x51, 0x61, 0x71,
 * 0x81, 0xC1, 0x91, 0xA1, 0xE1, 0xE2, 0xB1 or 0xE8, and 1 for every other code.
 *
 *   port  input block
 *
 * Called from input_adc_auto_adjust, input_adc_auto_color, sys_channel_apply_scaler_route, sys_channel_apply_scaler_route_for, sys_channel_apply_scaler_route_auto and sys_channel_apply_output_timing.
 */
int input_is_port_code_scalable(unsigned char port)
{
    unsigned char code = input_block_get_signal_code(port);

    if (code == 0x31 || code == 0x41 || code == 0x51 || code == 0x61 || code == 0x71 || code == 0x81 || code == 0xc1 ||
        code == 0x91 || code == 0xa1 || code == 0xe1 || code == 0xe2 || code == 0xb1 || code == 0xe8)
        return 0;
    return 1;
}
