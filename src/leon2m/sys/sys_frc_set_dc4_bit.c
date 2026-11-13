/* sys_frc_set_dc4_bit  (FUN_a0109b14)
 *
 * Set or clear one bit of converter register 0xCF011DC4.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0109b14 @ 0xa0109b14, flags -mcpu=v8 -O3 -g.
 * Source form: one read-modify-write through a volatile register, in either case.
 */
#define REG_CF011DC4 (*(volatile unsigned int *)0xcf011dc4)

/*
 * Set (on != 0) or clear bit `bit` of the register 0xCF011DC4. Called by sys_mode_apply_converter_setup
 * (sys_mode_apply_converter_setup), together with sys_frc_set_dc0_bit.
 */
void sys_frc_set_dc4_bit(unsigned char bit, unsigned char on)
{
    if (on)
        REG_CF011DC4 |= 1 << bit;
    else
        REG_CF011DC4 &= ~(1 << bit);
}
