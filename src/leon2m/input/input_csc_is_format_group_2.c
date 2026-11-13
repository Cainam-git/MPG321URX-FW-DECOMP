/* input_csc_is_format_group_2  (FUN_a01010f4)
 *
 * Return whether a colour format code belongs to the third group.
 * Returns: 0 or 1
 * Name basis: descriptive - codes 4, 5, 10, 11, 0x10, 0x11, ...; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01010f4 @ 0xa01010f4, flags -mcpu=v8 -O3 -g.
 * Source form: one || chain; 10 and 11 are tested as (unsigned char)(code - 10) < 2 (same form as
 * input_csc_is_format_group_3).
 */

/*
 * Return 1 when the colour format code is one of 4, 5, 10, 11, 0x10, 0x11, 0x16, 0x17, 0x1e, 0x1f, 0x24, 0x25;
 * otherwise 0. See input_csc_is_format_group_3 for the other groups.
 *
 * No routine in the image calls it.
 */
int input_csc_is_format_group_2(unsigned char code)
{
    if ((unsigned char)(code - 10) < 2 || code == 4 || code == 5 || code == 0x10 || code == 0x11 || code == 0x16 || code == 0x17 ||
        code == 0x1e || code == 0x1f || code == 0x24 || code == 0x25)
        return 1;
    return 0;
}
