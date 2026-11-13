/* sys_frc_set_dc8_bit  (FUN_a010ace4)
 *
 * Set or clear one bit of converter register 0xCF011DC8.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * FUN_a010ace4 (leon2m 0xa010ace4-0xa010ad28, 68 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: two read-modify-writes of the volatile register macro, the set arm first.
 */
#define FRC_REG_DC8 (*(volatile unsigned int *)0xcf011dc8)

/* Set (on non-zero) or clear (on 0) bit number `bit` of register 0xCF011DC8. */
void sys_frc_set_dc8_bit(unsigned int bit, unsigned char on)
{
    if (on)
        FRC_REG_DC8 |= 1 << bit;
    else
        FRC_REG_DC8 &= ~(1 << bit);
}
