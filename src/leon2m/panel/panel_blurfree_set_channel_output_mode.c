/* panel_blurfree_set_channel_output_mode  (FUN_a014fbf0)
 *
 * Set the output mode of every PWM channel selected by the channel mask.
 * Name basis: descriptive - 2-bit mode field per channel 0x10 + i for each mask bit
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014fbf0, flags -mcpu=v8 -O2.
 * Eight separate tests; the mask byte is read again for each.
 */

extern unsigned char panel_blurfree_channel_mask;
extern void panel_pwm_set_channel_output_mode(int channel, int mode);

/*
 * Set the output mode of each PWM channel (0x10 + bit number) whose bit is set in the channel mask (bits 0..7).
 * Same code as panel_blurfree_enable_channels with another callee.
 */
void panel_blurfree_set_channel_output_mode(unsigned int mode)
{
    if (panel_blurfree_channel_mask & 1)
        panel_pwm_set_channel_output_mode(0x10, mode & 0xff);
    if (panel_blurfree_channel_mask & 2)
        panel_pwm_set_channel_output_mode(0x11, mode & 0xff);
    if (panel_blurfree_channel_mask & 4)
        panel_pwm_set_channel_output_mode(0x12, mode & 0xff);
    if (panel_blurfree_channel_mask & 8)
        panel_pwm_set_channel_output_mode(0x13, mode & 0xff);
    if (panel_blurfree_channel_mask & 0x10)
        panel_pwm_set_channel_output_mode(0x14, mode & 0xff);
    if (panel_blurfree_channel_mask & 0x20)
        panel_pwm_set_channel_output_mode(0x15, mode & 0xff);
    if (panel_blurfree_channel_mask & 0x40)
        panel_pwm_set_channel_output_mode(0x16, mode & 0xff);
    if (panel_blurfree_channel_mask & 0x80)
        panel_pwm_set_channel_output_mode(0x17, mode & 0xff);
}
