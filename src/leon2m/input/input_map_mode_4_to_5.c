/* input_map_mode_4_to_5  (FUN_a0121ed0)
 *
 * Map the values 1, 2, 3, 4 to 1, 2, 3, 5.
 * Returns: mapped value
 * Name basis: descriptive - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0121ed0 @ 0xa0121ed0, flags -mcpu=v8 -O3 -g.
 * Source form: a switch with the cases in the order 2, 3, 4, 1, default; the result is masked with 7.
 */

/*
 * Return 1, 2, 3 for the values 1, 2, 3; 5 for 4; and 0 for anything else.
 *
 * No routine in the image calls it.
 */
unsigned char input_map_mode_4_to_5(unsigned char mode)
{
    unsigned char result;

    switch (mode) {
    case 2:
        result = 2;
        break;
    case 3:
        result = 3;
        break;
    case 4:
        result = 5;
        break;
    case 1:
        result = 1;
        break;
    default:
        result = 0;
        break;
    }
    return result & 7;
}
