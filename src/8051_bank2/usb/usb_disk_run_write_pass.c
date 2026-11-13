/* usb_disk_run_write_pass  (FUN_CODE_e432)
 *
 * Write memory to the USB disk from the selected file's first sector on (usb_disk_write_frame_dump).
 * Note: Reads the current port number first and does not use it.
 * Name basis: derived - usb_disk_write_frame_dump with the value of fwupd_file_first_sector (XDATA 0x0401);
 *   only caller fwupd_step_port_state
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e432 @ 0xe432, OPTIMIZE(8,SPEED) LARGE.
 * Source form: the port number is stored in a local that is never read (the firmware has the store), then
 * usb_disk_write_frame_dump is reached with a tail jump.
 */
extern unsigned long xdata fwupd_file_first_sector;
unsigned char usb_get_current_port(void);
void usb_disk_write_frame_dump(unsigned long a);

/* Write memory to the USB disk from the first sector of the selected file on (usb_disk_write_frame_dump: memory
 * place from mailbox bytes 0xF19A..0xF19D, chunk count from 0xF19E..0xF19F).
 * Only caller: fwupd_step_port_state, on port command 0x13 in the state where a file has been selected; after the
 * return it sets both port command bytes to 0xEE and stops in an endless loop. */
void usb_disk_run_write_pass(void)
{
    unsigned char port;     /* stored, never read */
    port = usb_get_current_port();
    usb_disk_write_frame_dump(fwupd_file_first_sector);
}
