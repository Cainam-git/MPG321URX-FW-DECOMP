/* hdmi_rx21_set_port_enable  (FUN_a00a1c74)
 *
 * Enable and start, or stop and disable, an HDMI 2.1 receiver port.
 *   port: receiver
 *   enable: 1 = enable
 * Name basis: derived - on: DRV_HDMI_IF_Enable_RxPort + hdmi_rx21_start_port; off: hdmi_rx21_stop_port
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a1c74, flags -mcpu=v8 -Os -g (section default). Both arguments are masked to 8 bits for the
 * calls to hdmi_rx21_clear_reg8_bit2 and the empty handlers; DRV_HDMI_IF_Enable_RxPort, hdmi_rx21_start_port and
 * hdmi_rx21_stop_port get the first argument unmasked. DRV_HDMI_IF_Enable_RxPort takes two word arguments: the
 * `if` path sets %o1, the `else` path clears %i1 before the tail-call restore.
 */
extern void hdmi_rx21_clear_reg8_bit2(unsigned int, unsigned int);
extern void DRV_HDMI_IF_Enable_RxPort(unsigned int, unsigned int);
extern void hdmi_rx21_start_port(unsigned int);
extern void irq_empty_vector_handler_copy6(unsigned int);
extern void irq_empty_vector_handler_copy5(unsigned int);
extern void hdmi_rx21_stop_port(unsigned int);

/*
 * Switch HDMI 2.1 receiver `port` on or off.
 *   enable != 0: hdmi_rx21_clear_reg8_bit2, DRV_HDMI_IF_Enable_RxPort(port, enable), hdmi_rx21_start_port,
 *                irq_empty_vector_handler_copy6.
 *   enable == 0: hdmi_rx21_clear_reg8_bit2 with 0, irq_empty_vector_handler_copy5, hdmi_rx21_stop_port,
 *                DRV_HDMI_IF_Enable_RxPort(port, 0).
 * Called by DRV_HDMI21_RX_Init.
 *   port    HDMI 2.1 receiver 0/1
 *   enable  non-zero = enable
 */
void hdmi_rx21_set_port_enable(unsigned int port, unsigned int enable)
{
    unsigned int enable_byte = enable & 0xff;
    unsigned int port_byte = port & 0xff;

    if (enable_byte != 0) {
        hdmi_rx21_clear_reg8_bit2(port_byte, enable_byte);
        DRV_HDMI_IF_Enable_RxPort(port, enable_byte);
        hdmi_rx21_start_port(port);
        irq_empty_vector_handler_copy6(port_byte);
        return;
    } else {
        hdmi_rx21_clear_reg8_bit2(port_byte, 0);
        irq_empty_vector_handler_copy5(port_byte);
        hdmi_rx21_stop_port(port);
        DRV_HDMI_IF_Enable_RxPort(port, 0);
        return;
    }
}
