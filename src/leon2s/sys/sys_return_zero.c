/* sys_return_zero  (FUN_a0089e4c)
 *
 * Return 0.
 * Returns: 0
 * Name basis: descriptive - constant 0; callers in 0xA00DAE90..0xA00DD154
 *
 * Matching notes
 * --------------
 * FUN_a0089e4c (leon2s 0xa0089e4c-0xa0089e54, 8 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Leaf routine without a register window (no save).
 */
/* Return 0. Called by dp_mst_update_payload_table, hdmi_tx_dsc_write_timing and hdmi_tx_dsc_write_rate. */
int sys_return_zero(void)
{
    return 0;
}
