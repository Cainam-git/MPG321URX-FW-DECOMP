/* pq_fga_get_table_mask  (FUN_a012e838)
 *
 * Return the mask of gamma tables that exist (0x508).
 * Returns: 0x508
 * Name basis: derived - constant; read by the DDC/CI request handler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012e838 @ 0xa012e838-0xa012e840 (8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: a constant return; the value is set in the retl delay slot.
 */

#define FGA_BLOCK_KEYS 0x508    /* bits of the first FGA key table: keys 0x16, 0x20, 0x24 = stored blocks 0..2 */

/*
 * Return FGA_BLOCK_KEYS. ddc_handle_request sends it as reply byte 6 of the FGA query 0x25 (GetVCP 0xF1),
 * next to pq_fga_get_color_mask.
 */
int pq_fga_get_table_mask(void)
{
    return FGA_BLOCK_KEYS;
}
