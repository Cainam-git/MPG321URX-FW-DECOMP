/* usb_port_write_bytes  (FUN_CODE_e306)
 *
 * Write a byte count, rounded up to whole 32-byte blocks, through the block port.
 * Name basis: descriptive - n = ceil(len / 32)
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e306 @ 0xe306, OPTIMIZE(8,SPEED) LARGE.
 * usb_port_write_blocks_buf is declared small (as in its own file); buf arrives in R1..R3 and is passed on
 * unchanged, the call is a tail jump.
 */
extern unsigned long xdata usb_mem_base;
extern void usb_port_write_blocks_buf(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char f) small;

#define BLOCK_SHIFT     5       /* 32 bytes per block */
#define BLOCK_REST      0x1f
#define IN_ORDER        1       /* bytes go out as they lie in buf (usb_port_write_blocks_buf) */

/* Write `length` bytes of buf, as whole 32-byte blocks (the last one filled up from whatever follows in buf), to
 * the port memory at block usb_mem_base (the common base of the USB port memory).
 * Only caller: usb_device_answer_setup, which puts each reply it takes from CODE memory there (lengths 2 to 0x50,
 * so at most three blocks) before usb_device_dma_transfer. */
void usb_port_write_bytes(unsigned char *buf, unsigned char length)
{
    unsigned char blocks;
    blocks = length >> BLOCK_SHIFT;
    if (length & BLOCK_REST) blocks++;
    usb_port_write_blocks_buf(buf, usb_mem_base, blocks, IN_ORDER);
}
