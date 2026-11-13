/* input_user_is_active_port_in_range  (FUN_a00d8034)
 *
 * Return whether the active port code lies between 0x0B and 0x0F.
 * Returns: 0 or 1
 * Name basis: descriptive - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d8034 @ 0xa00d8034, flags -mcpu=v8 -O3 -g.
 */

extern unsigned char input_api_get_channel_port_code(unsigned char);

/*
 * Return 1 when the port code of channel 0 is between 0x0B and 0x0F, else 0. No code calls this routine.
 */
unsigned char input_user_is_active_port_in_range(void)
{
    unsigned char in_range;

    in_range = 0;
    if ((unsigned char)(input_api_get_channel_port_code(0) - 0xb) < 5)
        in_range = 1;
    return in_range;
}
