/* sys_frc_disable_channels  (FUN_a0113064)
 *
 * Switch one converter channel off, or every enabled channel when given 0xFF.
 * Name basis: descriptive - bits 0..4 of 0xCF011800 / 0xCF011A00; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0113064 @ 0xa0113064, flags -mcpu=v8 -O3 -g.
 * Source form: the do/while loop keeps a separate counter and a masked copy of it (loop_count, bit); the
 * declarations come in the order below.
 */
extern int pq_block8_stop(void);
extern int reg_set_channel_ctrl_bit(unsigned int, unsigned int);

#define REG_cf011800 (*(volatile unsigned int *)0xcf011800)
#define REG_cf011a00 (*(volatile unsigned int *)0xcf011a00)

#define ALL_CHANNELS 0xff       /* `channel` value that stands for every channel that is on */
#define FRC_CHANNEL_COUNT 5     /* channels 0..4 */

/*
 * Switch converter channels off: one channel, or every channel that is on.
 *
 * channel   0..4 for one channel, ALL_CHANNELS for all channels whose bit is set in the channel enable
 *           register 0xCF011A00 (read before anything is changed)
 *
 * First stops picture block 8 (pq_block8_stop). For each channel to switch off it calls
 * reg_set_channel_ctrl_bit(channel, 1) and clears the channel's bit in both 0xCF011800 and 0xCF011A00.
 * With a single channel the bit in 0xCF011A00 is cleared whether or not it was set.
 */
void sys_frc_disable_channels(unsigned char channel)
{
    unsigned char enabled;
    unsigned int loop_count;
    unsigned int bit;
    unsigned int keep_mask;
    unsigned int keep_mask_single;

    enabled = REG_cf011a00;
    pq_block8_stop();

    if (channel == ALL_CHANNELS) {
        loop_count = 0;
        bit = 0;
        do {
            loop_count = loop_count + 1;
            if (((enabled & 0xff) >> bit & 1U) != 0) {
                reg_set_channel_ctrl_bit(bit, 1);
                keep_mask = ~(1 << bit);
                REG_cf011800 = REG_cf011800 & keep_mask;
                REG_cf011a00 = REG_cf011a00 & keep_mask;
            }
            bit = loop_count & 0xff;
        } while (bit < FRC_CHANNEL_COUNT);
    } else {
        reg_set_channel_ctrl_bit(channel, 1);
        keep_mask_single = ~(1 << channel);
        REG_cf011800 = REG_cf011800 & keep_mask_single;
        REG_cf011a00 = REG_cf011a00 & keep_mask_single;
    }
}
