/* sys_frc_set_input_enable_bit  (FUN_a0109514)
 *
 * Set or clear one bit of the converter's first enable register.
 * Name basis: descriptive - bit n of 0xCF011800; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0109514 @ 0xa0109514, flags -mcpu=v8 -O3 -g.
 * Source form: one read-modify-write through a volatile register; bit is an unsigned int.
 */
#define REG_CF011800 (*(volatile unsigned int *)0xcf011800)

/*
 * Set (on != 0) or clear bit `bit` of the register 0xCF011800. Nothing in the image calls it; the same code
 * exists once more as sys_frc_set_input_enable_bit_copy.
 */
void sys_frc_set_input_enable_bit(unsigned int bit, unsigned char on)
{
    if (on)
        REG_CF011800 |= 1 << bit;
    else
        REG_CF011800 &= ~(1 << bit);
}
