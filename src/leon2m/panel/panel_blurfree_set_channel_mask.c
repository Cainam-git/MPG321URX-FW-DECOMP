/* panel_blurfree_set_channel_mask  (FUN_a014f980)
 *
 * Store the mask of PWM channels used for blur reduction.
 * Name basis: derived - byte 0xA802CC86 is the per-channel mask the blur-reduction loops test
 *
 * Matching notes
 * --------------
 * Compiled with -mcpu=v8 -O2 -g. A direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char panel_blurfree_channel_mask;

/* Store the mask of PWM channels (0x10 + bit, bits 0..7) that panel_blurfree_enable_channels and
 * panel_blurfree_set_channel_output_mode act on. panel_blurfree_periodic_task does nothing while it is 0.
 * Called by panel_blurfree_set_parameter, id 1. */
void panel_blurfree_set_channel_mask(unsigned char channel_mask)
{
    panel_blurfree_channel_mask = channel_mask;
}
