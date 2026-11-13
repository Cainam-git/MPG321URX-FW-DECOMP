/* sys_frc_set_channel_enable_bit  (FUN_a0113020)
 *
 * Set or clear one channel enable bit of the frame-rate converter.
 * Name basis: descriptive - bit n of 0xCF011A00; unused
 *
 * Matching notes
 * --------------
 * FUN_a0113020 (leon2m 0xa0113020-0xa0113064, 68 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: two read-modify-writes of the volatile register macro, the set arm first.
 */
#define FRC_CHANNEL_ENABLE_REG (*(volatile unsigned int *)0xcf011a00)

/* Set (on non-zero) or clear (on 0) bit number `bit` of the channel enable register 0xCF011A00. Nothing calls this routine. */
void sys_frc_set_channel_enable_bit(unsigned int bit, unsigned char on)
{
    if (on)
        FRC_CHANNEL_ENABLE_REG |= 1 << bit;
    else
        FRC_CHANNEL_ENABLE_REG &= ~(1 << bit);
}
