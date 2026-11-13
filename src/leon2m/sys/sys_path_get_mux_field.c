/* sys_path_get_mux_field  (FUN_a0120638)
 *
 * Return the 2-bit selector of register 0xCF0116D8 as 2, 3 or 1.
 * Returns: 1..3
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0120638 @ 0xa0120638-0xa0120678 (64 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: a switch with 'default' first, then case 2 and case 3, into an unsigned char result (GCC turns the
 * field == 3 / default pair into the (-(v == 3) & 2) + 1 store-flag sequence).
 */
#define REG_cf0116d8 (*(volatile unsigned int *)0xcf0116d8)

/*
 * Return bits 0..1 of register 0xCF0116D8 as 2 or 3, or as 1 for every other value (0 and 1 both give 1).
 * input_adc_step_width_to_target compares the result with a block number. Written by sys_path_set_mux_field.
 */
unsigned char sys_path_get_mux_field(void)
{
    unsigned int field = REG_cf0116d8 & 3;
    unsigned char result;

    switch (field) {
    default:
        result = 1;
        break;
    case 2:
        result = 2;
        break;
    case 3:
        result = 3;
        break;
    }
    return result & 3;
}
