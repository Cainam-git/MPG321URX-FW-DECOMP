/* sys_frc_get_channel_enables  (FUN_a0112fb8)
 *
 * Return the channel enable bits of the frame-rate converter.
 * Returns: bits
 * Name basis: descriptive - low byte of 0xCF011A00; unused
 *
 * Matching notes
 * --------------
 * FUN_a0112fb8 (leon2m 0xa0112fb8-0xa0112fcc, 20 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: a volatile word read returned as unsigned char (the and 0xff sits in the retl delay slot).
 */
#define FRC_CHANNEL_ENABLE_REG (*(volatile unsigned int *)0xcf011a00)

/*
 * Return the low byte of the channel enable register 0xCF011A00. sys_frc_disable_channels reads the same
 * register to find the channels that are on. Nothing calls this routine.
 */
unsigned char sys_frc_get_channel_enables(void)
{
    return FRC_CHANNEL_ENABLE_REG;
}
