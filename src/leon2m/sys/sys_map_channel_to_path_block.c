/* sys_map_channel_to_path_block  (FUN_a01423b0)
 *
 * Return 0 for channel 0, 1 for channel 1 and 3 otherwise.
 * Returns: 0, 1 or 3
 * Name basis: descriptive - the same map that the channel mode routine uses; unused
 *
 * Matching notes
 * --------------
 * FUN_a01423b0 (leon2m 0xa01423b0-0xa01423dc, 44 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Nothing in the image refers to this routine. Source form: result 3 as default, a switch for cases
 * 0 and 1, return result & 3.
 */

/* Map channel 0 to 0, channel 1 to 1 and every other value to 3. Nothing calls this routine. */
unsigned char sys_map_channel_to_path_block(unsigned char channel)
{
    unsigned char result = 3;
    switch (channel) { case 0: result = 0; break; case 1: result = 1; break; }
    return result & 3;
}
