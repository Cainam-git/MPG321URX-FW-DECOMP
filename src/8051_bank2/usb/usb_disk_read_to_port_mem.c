/* usb_disk_read_to_port_mem  (FUN_CODE_e141)
 *
 * Read bytes from the USB disk, from a sector on, into the selected port's memory (usb_port_mem_base).
 *   sector: first disk sector
 *   byte_count: number of bytes to read
 * Name basis: derived - usb_disk_read_blocks with the value of usb_port_mem_base (XDATA 0x07D5) as
 *   destination; only caller fwupd_verify_file_sum
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e141 @ 0xe141, OPTIMIZE(8,SPEED) LARGE.
 * All three values are unsigned long. sector comes in R4..R7, byte_count in this routine's LARGE parameter block;
 * Keil keeps sector on the stack (PUSH R4..R7) while it copies byte_count and usb_port_mem_base into the parameter
 * block of usb_disk_read_blocks, then POPs and ends with LJMP.
 */
extern unsigned long xdata usb_port_mem_base;
void usb_disk_read_blocks(unsigned long a, unsigned long b, unsigned long c);

/* Read byte_count bytes of the USB disk, from disk sector `sector` on, into the memory of the selected port
 * (usb_port_mem_base, a place counted in 32-byte blocks: common base + port * 0x380).
 * Only caller: fwupd_verify_file_sum, which reads one 512-byte sector of CONFIG.bin this way. */
void usb_disk_read_to_port_mem(unsigned long sector, unsigned long byte_count)
{
    usb_disk_read_blocks(sector, byte_count, usb_port_mem_base);
}
