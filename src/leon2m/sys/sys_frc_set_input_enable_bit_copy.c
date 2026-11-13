/* sys_frc_set_input_enable_bit_copy  (FUN_a0112fe0)
 *
 * Set or clear one bit of the converter's first enable register.
 * Note: Identical copy of sys_frc_set_input_enable_bit.
 * Name basis: descriptive - bit n of 0xCF011800; unused
 *
 * Matching notes
 * --------------
 * FUN_a0112fe0 (leon2m 0xa0112fe0-0xa0113020, 64 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: two read-modify-writes of the volatile register macro, the set arm first.
 */
#define FRC_CONTROL_REG (*(volatile unsigned int *)0xcf011800)

/*
 * Set (on non-zero) or clear (on 0) bit number `bit` of the converter control register 0xCF011800.
 * A byte-for-byte copy of sys_frc_set_input_enable_bit. Nothing calls this copy.
 */
void sys_frc_set_input_enable_bit_copy(unsigned int bit, unsigned char on)
{
    if (on)
        FRC_CONTROL_REG |= 1 << bit;
    else
        FRC_CONTROL_REG &= ~(1 << bit);
}
