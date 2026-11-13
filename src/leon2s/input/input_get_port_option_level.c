/* input_get_port_option_level  (FUN_a00703d4)
 *
 * Return the second-level option bit n when option bit n is set.
 *   port
 * Returns: non-zero when set
 * Name basis: descriptive - bit n + 8 of the mask, only when bit n is set
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00703d4 @ 0xa00703d4, flags -mcpu=v8 -Os -g. A leaf routine.
 */

extern unsigned int input_port_option_mask;

/*
 * Return bit 8 + 'port' of the port option mask when bit 'port' is set, otherwise 0 (non-zero result when
 * both are set). Called by input_update_port_records.
 */
unsigned char input_get_port_option_level(unsigned int port)
{
    unsigned int mask = input_port_option_mask;
    unsigned int bit = 1 << port;

    if (mask & bit)
        return (mask >> 8) & bit;
    return 0;
}
