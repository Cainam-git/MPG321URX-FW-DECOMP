/* dp_tx_get_hpd_status  (FUN_a0083e28)
 *
 * Return the hot-plug status byte of the link outputs.
 * Name basis: derived - published to the main processor in mailbox word 3 by ipc_publish_port_status
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0083e28 @ 0xa0083e28 (-mcpu=v8 -Os)
 * Leaf routine without a register window. The flags carry no -g.
 */
extern unsigned char dp_tx_hpd_status;

/* Return dp_tx_hpd_status, the hot-plug status byte of the link outputs (one bit per output, see dp_tx_hpd_is_low). */
unsigned char dp_tx_get_hpd_status(void)
{
    return dp_tx_hpd_status;
}
