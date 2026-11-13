/* sys_check_channel_index  (FUN_a01436b4)
 *
 * Return a channel number 0..3 unchanged, else 0xFF.
 * Returns: channel or 0xFF
 * Name basis: derived - the range check that precedes the 'SYS remapping channel OOR' message
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01436b4 @ 0xa01436b4-0xa0143700 (19 words).
 * Source form: a switch with one case per channel 0..3 (default -1), not a range test.
 */

/* Return channel unchanged when it is 0..3, else 0xFF. The display-channel routines inline the same check. */
unsigned char sys_check_channel_index(unsigned char channel)
{
    int result;

    switch (channel) {
    case 0: result = 0; break;
    case 1: result = 1; break;
    case 2: result = 2; break;
    case 3: result = 3; break;
    default: result = -1; break;
    }
    return result;
}
