/* panel_blurfree_set_reversed_mode  (FUN_a014f98c)
 *
 * Store the flag that panel_blurfree_configure sets to 1 in its reversed case.
 * Note: SetPSMMixMode passes the stored flag to panel_blurfree_enable_channels as its on/off argument.
 * Name basis: derived - byte 0xA802CC84; panel_blurfree_configure stores 1 there after the branch that prints
 *   'BlurFree Error! (rev,delay)' on failure, else 0; setting id 15
 *
 * Matching notes
 * --------------
 * Compiled with -mcpu=v8 -O2 -g. A direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char panel_blurfree_reversed_mode;

/* Store the value that SetPSMMixMode passes to panel_blurfree_enable_channels when it switches on
 * (switching off passes 0).
 * Called by panel_blurfree_set_parameter, id 15. */
void panel_blurfree_set_reversed_mode(unsigned char mode)
{
    panel_blurfree_reversed_mode = mode;
}
