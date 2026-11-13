/* panel_level_gen_get_reg_e4  (FUN_a0101a14)
 *
 * Return the low byte of register 0xCF0160E4.
 * Returns: byte
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * FUN_a0101a14 (leon2m 0xa0101a14-0xa0101a28, 20 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: a volatile word read returned as unsigned char (the and 0xff sits in the retl delay slot).
 */
/* Register 0xCF0160E4 of the level generator block; read only here. */
#define LEVEL_GEN_REG_E4 (*(volatile unsigned int *)0xcf0160e4)

/*
 * Return the low byte of register 0xCF0160E4.
 *
 * Nothing in the firmware calls this routine or holds its address.
 */
unsigned char panel_level_gen_get_reg_e4(void)
{
    return LEVEL_GEN_REG_E4;
}
