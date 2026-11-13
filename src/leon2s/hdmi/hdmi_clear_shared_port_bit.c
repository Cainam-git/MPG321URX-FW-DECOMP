/* hdmi_clear_shared_port_bit  (FUN_a00914fc)
 *
 * Clear the bit of an HDMI port in the shared status register 0xCF03C890.
 *   port: HDMI 2.0 receiver 0/1
 * Name basis: descriptive - shared register area 0xCF03C8xx; caller hdmi_tmds_run_link_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00914fc @ 0xa00914fc (-mcpu=v8 -Os -g)
 */
#define reg_ipc_shared_hdmi_status (*(volatile unsigned int *)0xcf03c890)

/* Clear bit 'port' of the shared status register 0xCF03C890 (bit 0 = receiver 0, bit 1 = receiver 1). */
void hdmi_clear_shared_port_bit(unsigned char port)
{
    reg_ipc_shared_hdmi_status = reg_ipc_shared_hdmi_status & ~(1 << port);
    return;
}
