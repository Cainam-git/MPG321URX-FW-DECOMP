/* hdmi_is_second_port  (FUN_a008f4d0)
 *
 * Return 1 for HDMI 2.0 receiver 1, 0 otherwise.
 *   port: HDMI 2.0 receiver 0/1
 * Returns: 0 or 1
 * Name basis: descriptive - port == 1; result used as a table index
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008f4d0 @ 0xa008f4d0-0xa008f4ec, flags -mcpu=v8 -Os -g (leaf).
 * Source form: the 0/1 byte flag 'unsigned char r = 0; if (...) r = 1; return r & 1;' (the firmware has the
 * 'and 1' at the join).
 */
/*
 * Return 1 when the HDMI 2.0 receiver port is 1, else 0. hdmi_poll_rx_status and hdmi_tmds_run_link_state keep
 * the result as the PHY index they pass to hdmi_get_port_mode_byte. Also called by DRV_HDMI21_RX_Init.
 *   port: HDMI 2.0 receiver 0/1.
 */
unsigned char hdmi_is_second_port(unsigned char port)
{
    unsigned char r = 0;
    if (port == 1)
        r = 1;
    return r & 1;
}
