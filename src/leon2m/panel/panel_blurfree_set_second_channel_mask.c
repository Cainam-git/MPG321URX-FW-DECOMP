/* panel_blurfree_set_second_channel_mask  (FUN_a014f974)
 *
 * Store the second mask of PWM channels.
 * Name basis: derived - byte 0xA802CC87; setting id 0
 *
 * Matching notes
 * --------------
 * Compiled with -mcpu=v8 -O2 -g. A direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char panel_blurfree_second_channel_mask;

/* Store the channel mask that SetPSMMixMode uses to choose which PWM channels (0x10 + bit, bits 0..6) get
 * the stored on-time as their duty. panel_blurfree_set_pin_functions tests it together with the
 * channel mask.
 * Called by panel_blurfree_set_parameter, id 0. */
void panel_blurfree_set_second_channel_mask(unsigned char channel_mask)
{
    panel_blurfree_second_channel_mask = channel_mask;
}
