/* panel_blurfree_apply_channel_delays  (FUN_a014faa8)
 *
 * Write the stored delay of each PWM channel to the hardware, then the reference delay.
 * Name basis: derived - delay register write per table byte that is not 0xff, then channel 0x18
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014faa8, flags -mcpu=v8 -O3 -g.
 * Eight separate ifs, not a loop; the last call is a tail call.
 */

extern unsigned char panel_blurfree_channel_delays[8];
extern unsigned char panel_blurfree_reference_delay;
extern void panel_pwm_set_channel_delay(unsigned char channel, unsigned char delay);

/*
 * Write the stored delay of each of the PWM channels 0x10..0x17 to the hardware (a stored 0xff means "none"),
 * then the reference delay to channel 0x18. Called from panel_blurfree_set_mode.
 */
void panel_blurfree_apply_channel_delays(void)
{
    if (panel_blurfree_channel_delays[0] != 0xff)
        panel_pwm_set_channel_delay(0x10, panel_blurfree_channel_delays[0]);
    if (panel_blurfree_channel_delays[1] != 0xff)
        panel_pwm_set_channel_delay(0x11, panel_blurfree_channel_delays[1]);
    if (panel_blurfree_channel_delays[2] != 0xff)
        panel_pwm_set_channel_delay(0x12, panel_blurfree_channel_delays[2]);
    if (panel_blurfree_channel_delays[3] != 0xff)
        panel_pwm_set_channel_delay(0x13, panel_blurfree_channel_delays[3]);
    if (panel_blurfree_channel_delays[4] != 0xff)
        panel_pwm_set_channel_delay(0x14, panel_blurfree_channel_delays[4]);
    if (panel_blurfree_channel_delays[5] != 0xff)
        panel_pwm_set_channel_delay(0x15, panel_blurfree_channel_delays[5]);
    if (panel_blurfree_channel_delays[6] != 0xff)
        panel_pwm_set_channel_delay(0x16, panel_blurfree_channel_delays[6]);
    if (panel_blurfree_channel_delays[7] != 0xff)
        panel_pwm_set_channel_delay(0x17, panel_blurfree_channel_delays[7]);
    panel_pwm_set_channel_delay(0x18, panel_blurfree_reference_delay);
}
