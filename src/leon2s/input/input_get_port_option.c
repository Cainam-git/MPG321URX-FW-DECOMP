/* input_get_port_option  (FUN_a00703b8)
 *
 * Return option bit n of the per-port option mask.
 *   port
 * Returns: non-zero when set
 * Name basis: descriptive - bit n of the mask built by input_set_port_option_mask
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00703b8 @ 0xa00703b8, flags -mcpu=v8 -Os -g. A leaf routine without a register window.
 */

extern unsigned int input_port_option_mask;

/* Return bit 'port' of the port option mask (non-zero when set). Called by hdcp_tx_task. */
unsigned char input_get_port_option(unsigned int port)
{
    return input_port_option_mask & (1 << port);
}
