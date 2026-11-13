/* input_csc_is_format_group_0  (FUN_a010128c)
 *
 * Return whether a colour format code is 0 or 1.
 * Returns: 0 or 1
 * Name basis: descriptive - first group; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010128c @ 0xa010128c, flags -mcpu=v8 -O2 -g (section default).
 * Source form: a switch with cases 0 and 1 (the compiler emits one unsigned range compare, cmp 1 / bleu, with the
 * 1 in the delay slot).
 */

/*
 * Return 1 when the colour format code is 0 or 1, otherwise 0. See input_csc_is_format_group_3 for the other
 * groups.
 *
 * No routine in the image calls it.
 */
unsigned char input_csc_is_format_group_0(unsigned char code)
{
    switch (code) {
    case 0:
    case 1:
        return 1;
    default:
        return 0;
    }
}
