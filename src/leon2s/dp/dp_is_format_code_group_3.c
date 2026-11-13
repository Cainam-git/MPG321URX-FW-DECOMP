/* dp_is_format_code_group_3  (FUN_a00ad828)
 *
 * Return whether a format code is one of twelve listed values.
 * Returns: 0 or 1
 * Name basis: descriptive - codes 6, 7, 0x0C, 0x0D, 0x12, 0x13, ...
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ad828 @ 0xa00ad828, flags -mcpu=v8 -Os -g.
 * Source form: 0x0C and 0x0D are tested as one range, (code - 0xC) below 2.
 */
/*
 * Return 1 when the code is one of 0x06, 0x07, 0x0C, 0x0D, 0x12, 0x13, 0x18, 0x19, 0x20, 0x21, 0x26, 0x27, else 0.
 * dp_run_link_state and dp_apply_format_code call it with the colour_space field of the port record.
 *   code: format code
 */
int dp_is_format_code_group_3(unsigned char code)
{
    unsigned int in_group;

    if (((((unsigned char)(code - 0xcU) < 2U) || (code == 0x06)) ||
         (code == 0x07) || (code == 0x12)) ||
        ((code == 0x13) || (code == 0x18) || (code == 0x19) ||
         (code == 0x20) || (code == 0x21) || (code == 0x26) ||
         (code == 0x27))) {
        in_group = 1;
    } else {
        in_group = 0;
    }
    return in_group;
}
