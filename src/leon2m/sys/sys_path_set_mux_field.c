/* sys_path_set_mux_field  (FUN_a01205c0)
 *
 * Write the 2-bit selector 1..3 in register 0xCF0116D8.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01205c0 @ 0xa01205c0-0xa0120638 (30 words), flags -mcpu=v8 -O3 -g.
 * Source form: an if/else chain with one read-modify-write per value (a switch gives a range test instead of the compare chain).
 */
#define R(a) (*(volatile unsigned int *)(a))
#define MUX_REG 0xcf0116d8      /* bits 0..1 hold the field */

/*
 * Set bits 0..1 of register 0xCF0116D8 to `value` (1, 2 or 3). Bits 2..7 are kept and bits 8..31 are cleared;
 * any other value leaves the register unchanged. sys_path_get_mux_field reads the field back.
 * Called by startup_init_path_blocks (with 2).
 */
void sys_path_set_mux_field(unsigned char value)
{
    if (value == 1)
        R(MUX_REG) = (R(MUX_REG) & 0xfc) | 1;
    else if (value == 2)
        R(MUX_REG) = (R(MUX_REG) & 0xfc) | 2;
    else if (value == 3)
        R(MUX_REG) = (R(MUX_REG) & 0xfc) | 3;
}
