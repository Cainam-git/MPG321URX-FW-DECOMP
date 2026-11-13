/* panel_blurfree_set_channel_duty  (FUN_a014f998)
 *
 * Write a duty value to every PWM channel selected by the second channel mask.
 * Name basis: derived - 10-bit value written per channel 0x10 + n for each bit of 0xA802CC87
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014f998, flags -mcpu=v8 -O3 -g.
 * Seven separate ifs in bit order; the duty is passed on as an unsigned short.
 */

extern unsigned char panel_blurfree_second_channel_mask;
extern void panel_pwm_set_duty(unsigned char channel, unsigned short duty);

/*
 * Write one duty value to each PWM channel (0x10 + bit number) whose bit is set in the second channel mask
 * (bits 0..6). No caller was found.
 */
void panel_blurfree_set_channel_duty(unsigned int duty)
{
    /* The mask byte is read again for every test: a call may change it. */
    if (panel_blurfree_second_channel_mask & 0x1)
        panel_pwm_set_duty(0x10, duty);
    if (panel_blurfree_second_channel_mask & 0x2)
        panel_pwm_set_duty(0x11, duty);
    if (panel_blurfree_second_channel_mask & 0x4)
        panel_pwm_set_duty(0x12, duty);
    if (panel_blurfree_second_channel_mask & 0x8)
        panel_pwm_set_duty(0x13, duty);
    if (panel_blurfree_second_channel_mask & 0x10)
        panel_pwm_set_duty(0x14, duty);
    if (panel_blurfree_second_channel_mask & 0x20)
        panel_pwm_set_duty(0x15, duty);
    if (panel_blurfree_second_channel_mask & 0x40)
        panel_pwm_set_duty(0x16, duty);
}
