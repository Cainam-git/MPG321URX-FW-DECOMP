/* panel_api_store_blurfree_mode  (FUN_a014bce4)
 *
 * Store the blur-reduction mode without applying it.
 * Name basis: derived - writes the word at 0xA802E408 that panel_api_set_blurfree_mode also stores
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014bce4 @ 0xa014bce4, flags -mcpu=v8 -O2.
 */

extern unsigned int sys_config_blurfree_mode;

/* Store the blur-reduction mode without applying it (panel_api_set_blurfree_mode stores and applies). */
void panel_api_store_blurfree_mode(unsigned int mode)
{
    sys_config_blurfree_mode = mode;
}
