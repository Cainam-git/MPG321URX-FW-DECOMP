/* usb_clear_port_error_count  (FUN_CODE_e4d9)
 *
 * Set the error counter of the current USB port to 0.
 * Name basis: derived - usb_port_error_counts (XDATA 0x07D3) indexed by usb_port_index (0x075B)
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e4d9 @ 0xe4d9, no options recorded: the default OPTIMIZE(7,SPEED).
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

/* Set the error counter of the current port (usb_port_index) to 0 (usb_get_port_error_count reads it).
 * Callers: fwupd_step_port_state (before each enumeration and before the disk commands), usb_host_enumerate_device
 * and usb_disk_write_frame_dump. */
void usb_clear_port_error_count(void)
{
    usb_port_error_counts[usb_port_index] = 0;
}
