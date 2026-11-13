/* DRV_HDMI_IF_Enable_RxPort  (DRV_HDMI_IF_Enable_RxPort)
 *
 * Enable or disable an HDMI receiver port interface.
 *   port: receiver
 *   enable: 1 = enable
 * Returns: 0, or 0x16 for an invalid port
 * Name basis: proven - original name printed ('[VERBOSE]: %s: Port%c'); port 2 returns 0x16
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_IF_Enable_RxPort @ 0xa00a16cc, flags -mcpu=v8 -Os -g.
 * Source form: the function name is a separate static const char[] (the firmware keeps it as its own
 * .rodata object).
 */
extern int dbg_printf(const char *, ...);          /* trace printf */
extern void hdmi_rx21_write_port_enable(unsigned int, unsigned int); /* register write */
static const char fn_[] = "DRV_HDMI_IF_Enable_RxPort";

/* Passes the enable request to hdmi_rx21_write_port_enable. Port 2 is refused: it prints
 * "[VERBOSE]: DRV_HDMI_IF_Enable_RxPort: PortC" and returns 0x16.
 *   port:   receiver (low 8 bits used)
 *   enable: 1 = enable (low 8 bits used)
 * Returns 0, or 0x16 for port 2. */
unsigned int DRV_HDMI_IF_Enable_RxPort(unsigned int port, unsigned int enable)
{
    if (port == 2) {
        dbg_printf("[VERBOSE]: %s: Port%c \n", fn_, 0x43);
        return 0x16;
    } else {
        hdmi_rx21_write_port_enable(port & 0xff, enable & 0xff);
        return 0;
    }
}
