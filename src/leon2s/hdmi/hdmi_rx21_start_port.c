/* hdmi_rx21_start_port  (FUN_a00a15c8)
 *
 * Reset an HDMI 2.1 receiver port, mark it active and start the detect timers.
 *   port: receiver
 * Name basis: derived - pulses bit 8, hdmi_rx21_set_port_flag, DRV_HDMI_Start_Timer; only once
 *   DRV_HDMI_IF_Init has run
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a15c8, flags -mcpu=v8 -Os -g (section default). The two loads of the block 0 address are written
 * separately so that the target re-reads it from memory. The parameter is int.
 */
#define HDMI_TIMER_BOTH 0x15            /* start the mode-detect and the rx-detect timer */

extern unsigned char hdmi_rx21_reg_blocks;
extern unsigned char hdmi_rx_if_init_flag;
extern void reg_set_bit(unsigned int, int);
extern void timer_delay_units(unsigned int);
extern void reg_clear_bit(unsigned int, int);
extern void hdmi_rx21_set_port_flag(unsigned int, unsigned char);
extern void DRV_HDMI_Start_Timer(unsigned int);

/*
 * Start HDMI 2.1 receiver `port` once the interface is initialised (hdmi_rx_if_init_flag is non-zero): pulse
 * bit 8 of the word at byte offset 4 of register block 0 (set, one timer_delay_units, clear), set the port flag
 * with hdmi_rx21_set_port_flag(port, 1) and start the detect timers. Returns 0 when started, 1 when the
 * interface is not initialised. Called by hdmi_rx21_set_port_enable.
 *   port  HDMI 2.1 receiver 0/1
 */
int hdmi_rx21_start_port(int port)
{
    if (hdmi_rx_if_init_flag != 0) {
        reg_set_bit(8, *(unsigned int *)(&hdmi_rx21_reg_blocks + port * 0x34) + 4);
        timer_delay_units(1);
        reg_clear_bit(8, *(unsigned int *)(&hdmi_rx21_reg_blocks + port * 0x34) + 4);
        hdmi_rx21_set_port_flag(port & 0xff, 1);
        DRV_HDMI_Start_Timer(HDMI_TIMER_BOTH);
        return 0;
    }
    return 1;
}
