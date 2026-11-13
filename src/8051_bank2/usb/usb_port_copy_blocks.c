/* usb_port_copy_blocks  (FUN_CODE_e04a)
 *
 * Read blocks from one address and write them to another through the block port.
 * Name basis: descriptive - data buffer at DATA 0x22; read, then write of n blocks
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE. LARGE parameters dest (R4..R7, stored to its home 0x0986 with ?C?LSTXDATA),
 * src (0x098A) and count (0x098E). usb_port_read_blocks_buf and usb_port_write_blocks_buf are declared small as in
 * fwupd/fwupd_refresh_flash_records.c (n and in_order at DATA 0x0F / 0x10); the write is a tail call.
 */
extern unsigned char data usb_block_buffer[];   /* the block buffer */
extern void usb_port_read_blocks_buf(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char in_order) small;
extern void usb_port_write_blocks_buf(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char in_order) small;

/* usb_port_copy_blocks: copy count 32-byte blocks of port memory from block src to block dest, through the block
 * buffer at DATA 0x22. Both transfers pass in_order 0, so the two reversals of each 4-byte group cancel out.
 * Caller: usb_host_run_transfer, which copies one transfer record into the queue head's current record. */
void usb_port_copy_blocks(unsigned long dest, unsigned long src, unsigned char count)
{
    usb_port_read_blocks_buf(usb_block_buffer, src, count, 0);
    usb_port_write_blocks_buf(usb_block_buffer, dest, count, 0);
}
