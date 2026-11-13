/* dp_get_port_setting_112  (FUN_a00ab674)
 *
 * Return setting byte +0x112 of a DP port record.
 *   port
 * Returns: byte
 * Name basis: descriptive - byte set by dp_set_port0_setting_112; caller dp_tx_run_hpd_actions
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ab674 @ 0xa00ab674, flags -mcpu=v8 -Os -g (set in symbols/leon2s.json). Leaf.
 */
extern unsigned char dp_input_records[];            /* 300-byte record per port */

/*
 * Return byte 0x112 of the 300-byte record of a DP port.
 * dp_init_port_settings sets the byte to 0; dp_tx_run_hpd_actions calls this routine with port 0.
 *   port: DP port, index of the record
 */
unsigned char dp_get_port_setting_112(unsigned int port)
{
    return dp_input_records[(port & 0xff) * 300 + 0x112];
}
