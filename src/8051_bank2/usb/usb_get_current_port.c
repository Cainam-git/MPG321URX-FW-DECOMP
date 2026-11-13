/* usb_get_current_port  (FUN_CODE_4ffa)
 *
 * Return the number of the current USB port.
 * Returns: port
 * Name basis: descriptive - byte at XDATA 0x075B, the index used for the per-port tables
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED). The address is read through a pointer cast, not through a named extern.
 */
/* usb_get_current_port: return usb_port_index (XDATA 0x075B), the USB port whose records usb_select_controller
 * loaded last (0 or 1). Callers: fwupd_find_update_file, fwupd_verify_file_sum and others. */
unsigned char usb_get_current_port(void) {
    return *(unsigned char xdata *)0x75b;
}
