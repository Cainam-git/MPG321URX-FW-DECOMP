/* usb_get_port_error_count  (FUN_CODE_e4c9)
 *
 * Return the error counter of the current USB port.
 * Returns: the count (the callers test it for non-zero)
 * Name basis: derived - usb_port_error_counts (XDATA 0x07D3) indexed by usb_port_index (0x075B); the transfer
 *   and enumeration code adds 1 per failure
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e4c9 @ 0xe4c9, no options recorded: the default OPTIMIZE(7,SPEED).
 */
extern unsigned char xdata fwupd_svc_packet[];
unsigned char i2c_write_packet(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char i2c_read_packet(unsigned char addr, unsigned char *buf);
void fwupd_wait_ready_line(unsigned int t);
void fwupd_svc_read_reply(unsigned char *buf);
void timer_delay_units(unsigned char n);
void timer_delay_base(void);
extern unsigned char xdata usb_port_error_counts[];
extern unsigned char xdata usb_port_index;

/* Return the error counter of the current port (usb_port_index). usb_host_run_transfer and
 * usb_host_enumerate_device add 1 for each failure; the callers only test it for non-zero: fwupd_step_port_state
 * repeats the enumeration while it is set, usb_host_enumerate_device stops, fwupd_write_dualfw_tag writes
 * nothing. */
unsigned char usb_get_port_error_count(void)
{
    return usb_port_error_counts[usb_port_index];
}
