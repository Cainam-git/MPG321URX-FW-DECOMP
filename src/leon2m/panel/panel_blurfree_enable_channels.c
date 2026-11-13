/* panel_blurfree_enable_channels  (FUN_a014fd34)
 *
 * Switch every PWM channel selected by the channel mask on or off.
 * Name basis: derived - enable bit per channel in 0xCF016470 for each mask bit
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014fd34, flags -mcpu=v8 -O2.
 * Eight separate tests; the mask byte is read again for each.
 */

extern unsigned char panel_blurfree_channel_mask;
extern void panel_pwm_enable_channel(int channel, int enable);

/*
 * Switch each PWM channel (0x10 + bit number) whose bit is set in the channel mask (bits 0..7) on or off,
 * as the argument says.
 */
void panel_blurfree_enable_channels(unsigned int enable)
{
    if (panel_blurfree_channel_mask & 1)
        panel_pwm_enable_channel(0x10, enable & 0xff);
    if (panel_blurfree_channel_mask & 2)
        panel_pwm_enable_channel(0x11, enable & 0xff);
    if (panel_blurfree_channel_mask & 4)
        panel_pwm_enable_channel(0x12, enable & 0xff);
    if (panel_blurfree_channel_mask & 8)
        panel_pwm_enable_channel(0x13, enable & 0xff);
    if (panel_blurfree_channel_mask & 0x10)
        panel_pwm_enable_channel(0x14, enable & 0xff);
    if (panel_blurfree_channel_mask & 0x20)
        panel_pwm_enable_channel(0x15, enable & 0xff);
    if (panel_blurfree_channel_mask & 0x40)
        panel_pwm_enable_channel(0x16, enable & 0xff);
    if (panel_blurfree_channel_mask & 0x80)
        panel_pwm_enable_channel(0x17, enable & 0xff);
}
