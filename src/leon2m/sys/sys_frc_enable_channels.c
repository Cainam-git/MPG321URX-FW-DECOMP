/* sys_frc_enable_channels  (FUN_a0113138)
 *
 * Switch the frame-rate converter channels of a mask on.
 * Name basis: descriptive - bits 0..4 of 0xCF011800 / 0xCF011A00; bit 5 starts picture block 8; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0113138 @ 0xa0113138-0xa01131d4 (39 words), flags -mcpu=v8 -O3 -g.
 * Source form: the picture block 8 start is the last statement, so it compiles to a tail call.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern void reg_set_channel_ctrl_bit(unsigned int, unsigned int);
extern void pq_block8_start(void);

#define PICTURE_BLOCK8_START_BIT 0x20   /* bit 5 of the mask */

/*
 * Switch converter channels on.
 *
 * mask   bit n (n = 0..4) selects channel n; bit 5 asks for picture block 8 to be started
 *
 * For each selected channel it calls reg_set_channel_ctrl_bit(channel, 0) and sets the channel's bit in both
 * 0xCF011800 and 0xCF011A00. When bit 5 of the mask is set it finally calls pq_block8_start. Its address is
 * taken somewhere (no direct caller).
 */
void sys_frc_enable_channels(unsigned char mask)
{
    unsigned char channel;

    for (channel = 0; channel <= 4; channel++) {
        if ((mask >> channel) & 1) {
            reg_set_channel_ctrl_bit(channel, 0);
            R(0xcf011800) |= 1 << channel;
            R(0xcf011a00) |= 1 << channel;
        }
    }
    if (mask & PICTURE_BLOCK8_START_BIT)
        pq_block8_start();
}
