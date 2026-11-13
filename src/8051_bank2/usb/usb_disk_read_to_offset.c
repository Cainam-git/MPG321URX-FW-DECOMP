/* usb_disk_read_to_offset  (FUN_CODE_d6d1)
 *
 * Read bytes from the USB disk into the memory that holds the loaded file, at a byte offset.
 *   sector: block address
 *   byte_count: length
 *   dest_offset: offset
 * Note: Sets fwupd_dram_address = usb_mem_base + 0x700 on every call; the destination block is that value +
 *   offset / 32.
 * Name basis: derived - usb_mem_base + 0x700 is stored in fwupd_dram_address, then usb_disk_read_blocks
 *   (READ(10)) with the destination block fwupd_dram_address + dest_offset / 32; caller
 *   fwupd_copy_file_to_dram
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE. LARGE parameters sector (0x0920, passed in R4..R7), byte_count (0x0924)
 * and dest_offset (0x0928). The call is a tail jump (LJMP) into usb_disk_read_blocks; byte_count and the block
 * number go to its parameter block 0x0931 / 0x0935 (?_FUN_CODE_c60e?BYTE). dest_offset / 32 is ?C?ULDIV.
 */
extern unsigned long xdata usb_mem_base;
extern unsigned long xdata fwupd_dram_address;
void usb_disk_read_blocks(unsigned long a, unsigned long b, unsigned long c);

/* usb_disk_read_to_offset: read byte_count bytes from the USB disk, starting at disk sector `sector`, into the
 * memory that holds the loaded file, dest_offset bytes after its start.
 *
 * The memory is counted in 32-byte blocks (usb_disk_read_blocks hands the controller block << 5). The file's first
 * block is set here every time: fwupd_dram_address = usb_mem_base + 0x700, which is two times the PORT_MEM_BYTES
 * (0x380) that usb_select_controller gives each of the ports 0 and 1. fwupd_dram_address is the value
 * fwupd_post_value_0717 posts in the mailbox.
 * Caller: fwupd_copy_file_to_dram, with pieces of at most 0x4000 bytes and the offset of each piece in the file. */
void usb_disk_read_to_offset(unsigned long sector, unsigned long byte_count, unsigned long dest_offset)
{
    fwupd_dram_address = usb_mem_base + 0x700;
    usb_disk_read_blocks(sector, byte_count, fwupd_dram_address + dest_offset / 32);
}
