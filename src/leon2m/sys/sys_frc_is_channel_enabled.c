/* sys_frc_is_channel_enabled  (FUN_a0109598)
 *
 * Return whether a converter channel is enabled.
 * Returns: 0 or 1
 * Name basis: derived - bit n of 0xCF011A00; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0109598 @ 0xa0109598, flags -mcpu=v8 -O3 -g.
 * Source form: the masked value is kept in its own unsigned int local (and/cmp/addx).
 */
#define REG_CF011A00 (*(volatile unsigned int *)0xcf011a00)

/*
 * Return 1 when bit `bit` of the register 0xCF011A00 is set, else 0. Nothing in the image calls it.
 */
unsigned int sys_frc_is_channel_enabled(unsigned int bit)
{
    unsigned int masked = REG_CF011A00 & (1 << bit);
    return masked != 0;
}
