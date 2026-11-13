/* input_csc_is_format_group_3  (FUN_a0101028)
 *
 * Return whether a colour format code belongs to the fourth group.
 * Returns: 0 or 1
 * Name basis: descriptive - codes 6, 7, 12, 13, 0x12, 0x13, ...; used by the bring-up state machine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101028 @ 0xa0101028, flags -mcpu=v8 -O3 -g.
 * Source form: one || chain; 12 and 13 are tested as (unsigned char)(code - 12) < 2. input_csc_is_format_group_1
 * and _2 use the same form; _0 is a switch.
 */

/*
 * Return 1 when the colour format code is one of 6, 7, 12, 13, 0x12, 0x13, 0x18, 0x19, 0x20, 0x21, 0x26, 0x27;
 * otherwise 0. The four group routines (_0 to _3) together cover the codes 0 to 0x27, each code in exactly one
 * group; group 0 holds 0 and 1, the other groups hold pairs of consecutive codes.
 *
 * Called from input_channel_bring_up_task.
 */
int input_csc_is_format_group_3(unsigned char code)
{
    if ((unsigned char)(code - 12) < 2 || code == 6 || code == 7 || code == 0x12 || code == 0x13 || code == 0x18 || code == 0x19 ||
        code == 0x20 || code == 0x21 || code == 0x26 || code == 0x27)
        return 1;
    return 0;
}
