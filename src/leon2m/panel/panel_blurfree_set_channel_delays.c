/* panel_blurfree_set_channel_delays  (FUN_a014f8a0)
 *
 * Store a delay value for every PWM channel selected by a mask.
 * Name basis: derived - bytes 0xA802A4A8..AF, one per channel; setting ids 4..11
 *
 * Matching notes
 * --------------
 * Compiled with -mcpu=v8 -O3 -g. Eight separate byte globals, one `if` per mask bit; no array.
 */
extern unsigned char panel_blurfree_channel_delays, panel_blurfree_channel_delay_1, panel_blurfree_channel_delay_2, panel_blurfree_channel_delay_3;
extern unsigned char panel_blurfree_channel_delay_4, panel_blurfree_channel_delay_5, panel_blurfree_channel_delay_6, panel_blurfree_channel_delay_7;

/* Store a delay value for each channel whose bit is set in channel_mask (bit i = channel i, 0..7).
 * The bytes are read by panel_blurfree_apply_channel_delays, which passes every value other than 0xff to
 * panel_pwm_set_channel_delay for PWM channel 0x10 + i.
 * Called by panel_blurfree_set_parameter, ids 4..11, one channel per id. */
void panel_blurfree_set_channel_delays(unsigned char channel_mask, unsigned char delay)
{
    if (channel_mask & 1)
        panel_blurfree_channel_delays = delay;
    if (channel_mask & 2)
        panel_blurfree_channel_delay_1 = delay;
    if (channel_mask & 4)
        panel_blurfree_channel_delay_2 = delay;
    if (channel_mask & 8)
        panel_blurfree_channel_delay_3 = delay;
    if (channel_mask & 0x10)
        panel_blurfree_channel_delay_4 = delay;
    if (channel_mask & 0x20)
        panel_blurfree_channel_delay_5 = delay;
    if (channel_mask & 0x40)
        panel_blurfree_channel_delay_6 = delay;
    if (channel_mask & 0x80)
        panel_blurfree_channel_delay_7 = delay;
}
