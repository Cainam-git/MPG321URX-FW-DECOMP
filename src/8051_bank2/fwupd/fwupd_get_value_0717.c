/* fwupd_get_value_0717  (FUN_CODE_e4e9)
 *
 * Return the 32-bit value stored at XDATA 0x0717.
 * Returns: value
 * Name basis: descriptive - plain getter
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e4e9 @ 0xe4e9, no options recorded: the default OPTIMIZE(7,SPEED).
 */
extern unsigned long xdata fwupd_dram_address;

/* Return fwupd_dram_address, the place of the loaded file in the port memory in 32-byte blocks (usb_mem_base +
 * 0x700, set by usb_disk_read_to_offset and fwupd_read_file_block).
 * Callers add a block number to it to read or write blocks of the file: fwupd_check_image_signature,
 * fwupd_build_record_table, fwupd_refresh_flash_records; fwupd_svc_send_region sends it to the main chip. */
unsigned long fwupd_get_value_0717(void)
{
    return fwupd_dram_address;
}
