/* sys_frc_set_dc0_bit  (FUN_a0109ad0)
 *
 * Set or clear one bit of converter register 0xCF011DC0.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0109ad0 @ 0xa0109ad0, flags -mcpu=v8 -O3 -g.
 * Source form: one read-modify-write through a volatile register, in either case.
 */
#define REG_CF011DC0 (*(volatile unsigned int *)0xcf011dc0)

/*
 * Set (on != 0) or clear bit `bit` of the register 0xCF011DC0.
 *
 * Called by sys_mode_apply_converter_setup (sys_mode_apply_converter_setup), which sets or clears the same bit number in
 * this register and in 0xCF011DC4 (sys_frc_set_dc4_bit) for bits 0 to 3.
 */
void sys_frc_set_dc0_bit(unsigned char bit, unsigned char on)
{
    if (on)
        REG_CF011DC0 |= 1 << bit;
    else
        REG_CF011DC0 &= ~(1 << bit);
}
