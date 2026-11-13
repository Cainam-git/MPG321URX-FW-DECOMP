/* panel_layer_set_update_strobe_enabled  (FUN_a010b444)
 *
 * Store the byte that switches the layer update request and its wait on or off.
 * Note: Nothing calls it; the byte is tested for 1 by panel_layer_strobe_update and the window set-up
 *   routines.
 * Name basis: derived - stores one byte at 0xA8027A88; the layer routines request the update and wait for it
 *   only while that byte is 1
 *
 * Matching notes
 * --------------
 * FUN_a010b444, flags -mcpu=v8 -O2 -g. Leaf. Nothing in the image calls or points to it.
 * Source form: a direct store to the extern symbol (the store sits in the return delay slot).
 */
extern unsigned char panel_layer_update_strobe_enabled;

/* Store value in the byte panel_layer_update_strobe_enabled. panel_channel_layer_setup_window tests that byte for 1. */
void panel_layer_set_update_strobe_enabled(unsigned char value)
{
    panel_layer_update_strobe_enabled = value;
}
