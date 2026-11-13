/* pq_pivot_set_bit4_pattern  (FUN_a010a3a8)
 *
 * Set or clear bit 4 of the three pivot channel registers in a pattern chosen by the channel.
 *   channel: 1 or 2 pick a pattern, any other value clears all three bits
 *   enable: value of bit 4 of the third register for channels 1 and 2
 * Note: Channel 1: set, cleared, = enable; channel 2: set, set, = enable; any other channel: all three
 *   cleared. Nothing calls it.
 * Name basis: descriptive - bit 4 of 0xCF01E684 / 0xCF01E688 / 0xCF01E68C, all three written on every call; no
 *   caller
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010a3a8 @ 0xa010a3a8-0xa010a494 (59 words), flags -mcpu=v8 -O3 -g.
 * Source form: the same switch form as sys_frc_set_lock_mode, with the default arm first (it gives the
 * firmware's per-case copies of the register addresses).
 */
/* Channel registers of the pivot block (names as in pq_pivot_setup_timing); bit 4 is the bit changed here. */
#define PIVOT_CHANNEL0_CTRL (*(volatile unsigned int *)0xcf01e684)
#define PIVOT_CHANNEL1_CTRL (*(volatile unsigned int *)0xcf01e688)
#define PIVOT_CHANNEL2_CTRL (*(volatile unsigned int *)0xcf01e68c)

#define ROTATION_BIT 0x10   /* bit 4 */
#define CHANNEL_1 1
#define CHANNEL_2 2

/*
 * Set or clear bit 4 of each of the three pivot channel registers, in a pattern chosen by channel:
 *
 *   channel   PIVOT_CHANNEL0_CTRL   PIVOT_CHANNEL1_CTRL   PIVOT_CHANNEL2_CTRL
 *   1         set                   cleared               set when enable != 0, else cleared
 *   2         set                   set                   set when enable != 0, else cleared
 *   other     cleared               cleared               cleared (enable not read)
 *
 * Nothing calls this routine. pq_pivot_setup_timing writes the pattern of channel 2 with enable 0 with its
 * own statements.
 */
void pq_pivot_set_bit4_pattern(unsigned char channel, unsigned char enable)
{
    switch (channel) {
    default:
        /* Not channel 1 or 2: clear the rotation bit in all three registers. */
        PIVOT_CHANNEL0_CTRL &= ~ROTATION_BIT;
        PIVOT_CHANNEL1_CTRL &= ~ROTATION_BIT;
        PIVOT_CHANNEL2_CTRL &= ~ROTATION_BIT;
        break;
    case CHANNEL_1:
        PIVOT_CHANNEL0_CTRL |= ROTATION_BIT;
        PIVOT_CHANNEL1_CTRL &= ~ROTATION_BIT;
        if (enable)
            PIVOT_CHANNEL2_CTRL |= ROTATION_BIT;
        else
            PIVOT_CHANNEL2_CTRL &= ~ROTATION_BIT;
        break;
    case CHANNEL_2:
        PIVOT_CHANNEL0_CTRL |= ROTATION_BIT;
        PIVOT_CHANNEL1_CTRL |= ROTATION_BIT;
        if (enable)
            PIVOT_CHANNEL2_CTRL |= ROTATION_BIT;
        else
            PIVOT_CHANNEL2_CTRL &= ~ROTATION_BIT;
        break;
    }
}
