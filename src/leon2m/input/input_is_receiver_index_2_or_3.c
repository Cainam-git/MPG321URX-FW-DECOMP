/* input_is_receiver_index_2_or_3  (FUN_a0142360)
 *
 * Return whether a value is 2 or 3.
 * Returns: 0 or 1
 * Name basis: descriptive - plain range test
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0142360 @ 0xa0142360-0xa0142380, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: the test is on the unsigned char of (index - 2) (the firmware masks
 * with 0xff after the subtraction); parameter and return are unsigned char, as at the caller GlobalModeHandler.
 */

/*
 * Return 1 when index is 2 or 3, else 0.
 */
unsigned char input_is_receiver_index_2_or_3(unsigned char index)
{
    if ((unsigned char)(index - 2) <= 1)
        return 1;
    return 0;
}
