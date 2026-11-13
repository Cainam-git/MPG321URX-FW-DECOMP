/* pq_gamma_set_lut_options  (FUN_a010adc0)
 *
 * Set the two option bits of the gamma look-up tables.
 * Name basis: descriptive - bit 7 of 0xCF00EAC0 and bit 6 of 0xCF00EAC8, each the inverse of its argument
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010adc0 @ 0xa010adc0, flags -mcpu=v8 -O3 -g.
 * Source form: both parameters are int.
 */

#define REG_CF00EAC0 (*(volatile unsigned int *)0xcf00eac0)
#define REG_CF00EAC0_BIT7 0x80          /* read by pq_gamma_write_primary_lut */
#define reg_pq_gamma_lut_control (*(volatile unsigned int *)0xcf00eac8)
#define GAMMA_LUT_OPTION_BIT6 0x40      /* bit 6 of the gamma LUT control register */

/*
 * Set or clear the two option bits, each the inverse of its argument:
 *   first_off   0 sets bit 7 of 0xCF00EAC0, anything else clears it. While that bit is set,
 *               pq_gamma_write_primary_lut repeats the last entry of a block that ends at entry 0x100 as
 *               entry 0x100.
 *   second_off  0 sets bit 6 of the gamma LUT control register 0xCF00EAC8, anything else clears it.
 *
 * Callers: pq_load_gamma, with (0, 1) before it loads gamma data from storage into the primary LUT, and
 * pq_api_set_gamma_lut_options (no caller).
 */
void pq_gamma_set_lut_options(int first_off, int second_off)
{
    if (first_off == 0) {
        REG_CF00EAC0 = REG_CF00EAC0 | REG_CF00EAC0_BIT7;
    } else {
        REG_CF00EAC0 = REG_CF00EAC0 & ~REG_CF00EAC0_BIT7;
    }
    if (second_off == 0) {
        reg_pq_gamma_lut_control = reg_pq_gamma_lut_control | GAMMA_LUT_OPTION_BIT6;
    } else {
        reg_pq_gamma_lut_control = reg_pq_gamma_lut_control & ~GAMMA_LUT_OPTION_BIT6;
    }
    return;
}
