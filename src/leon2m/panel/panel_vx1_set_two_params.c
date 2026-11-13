/* panel_vx1_set_two_params  (FUN_a0122cd8)
 *
 * Store two V-by-One parameters after range checks.
 * Name basis: descriptive - 1..16 and below 32; unused
 *
 * Matching notes
 * --------------
 * FUN_a0122cd8 (leon2m 0xa0122cd8-0xa0122d0c, 52 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: the first test is (unsigned char)(first_param - 1) < 16.
 */
extern unsigned char panel_vx1_first_param;
extern unsigned char panel_vx1_second_param;

/*
 * Store first_param in panel_vx1_first_param when it is 1..16, and second_param in panel_vx1_second_param
 * when it is below 32. A value outside its range is ignored; the two are checked separately.
 * No routine in the image calls it.
 */
void panel_vx1_set_two_params(unsigned char first_param, unsigned char second_param)
{
    if ((unsigned char)(first_param - 1) < 16)
        panel_vx1_first_param = first_param;
    if (second_param < 32)
        panel_vx1_second_param = second_param;
}
