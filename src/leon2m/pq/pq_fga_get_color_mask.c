/* pq_fga_get_color_mask  (FUN_a012e840)
 *
 * Return the mask of colour entries that exist (0x92).
 * Returns: 0x92
 * Name basis: derived - constant; read by the DDC/CI request handler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012e840 @ 0xa012e840-0xa012e848 (8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: a constant return; the value is set in the retl delay slot.
 */

#define FGA_COLOR_KEYS 0x92     /* bits of the second FGA key table: keys 50, 65, 93 = Warm 50 / Normal 65 / Cool 93 */

/*
 * Return FGA_COLOR_KEYS. ddc_handle_request sends it as reply byte 7 of the FGA query 0x25 (GetVCP 0xF1),
 * next to pq_fga_get_table_mask.
 */
int pq_fga_get_color_mask(void)
{
    return FGA_COLOR_KEYS;
}
