/* input_csc_is_format_group_1  (FUN_a01011c0)
 *
 * Return whether a colour format code belongs to the second group.
 * Returns: 0 or 1
 * Name basis: descriptive - codes 2, 3, 8, 9, 0x0E, 0x0F, ...; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01011c0 @ 0xa01011c0, flags -mcpu=v8 -O3 -g.
 * Source form: one || chain; 8 and 9 are tested as (unsigned char)(code - 8) < 2 (same form as
 * input_csc_is_format_group_3).
 */

/*
 * Return 1 when the colour format code is one of 2, 3, 8, 9, 0xe, 0xf, 0x14, 0x15, 0x1c, 0x1d, 0x22, 0x23;
 * otherwise 0. See input_csc_is_format_group_3 for the other groups.
 *
 * No routine in the image calls it.
 */
int input_csc_is_format_group_1(unsigned char code)
{
    if ((unsigned char)(code - 8) < 2 || code == 2 || code == 3 || code == 0xe || code == 0xf || code == 0x14 || code == 0x15 ||
        code == 0x1c || code == 0x1d || code == 0x22 || code == 0x23)
        return 1;
    return 0;
}
