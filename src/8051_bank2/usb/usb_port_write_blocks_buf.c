/* usb_port_write_blocks_buf  (FUN_CODE_b1a9)
 *
 * Write n 32-byte blocks of a buffer to a bus address.
 *   buf: source
 *   addr: bus address
 *   n: blocks
 *   f: 1 sends each group of four as it lies in buf, any other value reverses each group
 * Name basis: derived - address to bus block address registers, data to the block write data register; byte
 *   order per group of four set by in_order
 *
 * Matching notes
 * --------------
 * A SMALL-model routine (parameter block ?_FUN_CODE_b1a9?BYTE at DATA 0x08: buf 0x08..0x0A generic pointer,
 * addr 0x0B..0x0E, n 0x0F, in_order 0x10; locals j 0x11, block 0x12). Byte-exact with OPTIMIZE(7,SPEED),
 * (8,SPEED) and (8,SPEED) LARGE.
 * Source form the bytes depend on: the byte index j is compared with 'block * 32 + 32' (a signed int compare).
 */
extern unsigned char xdata reg_bus_block_ctrl;
extern unsigned char xdata reg_bus_block_wdata;
extern unsigned char xdata reg_bus_block_addr0;
extern unsigned char xdata reg_bus_block_addr1;
extern unsigned char xdata reg_bus_block_addr2;
extern unsigned char xdata reg_bus_block_addr3;
void timer_delay_units(unsigned char n);

#define BUS_START    0x80   /* written to reg_bus_block_ctrl before the data, as in usb_port_read_blocks_buf */
#define BLOCK_BYTES  32
#define IN_ORDER     1      /* in_order value: bytes go out as they lie in buf */

/* usb_port_write_blocks_buf: write n 32-byte blocks from buf through the bus block port, starting at block addr.
 * The write side of usb_port_read_blocks_buf; same parameters.
 *
 * in_order: IN_ORDER (1) sends each group of four bytes as it lies in buf; any other value sends each group the
 *           other way round (fourth byte first).
 *
 * Per block: the four address bytes go out (bits 0..7 first), BUS_START goes to the control register, then the 32
 * data bytes. With n > 1 each block is followed by timer_delay_units(1).
 * As in the read routine, addr grows by the block number each round (blocks at addr, addr + 1, addr + 3, ...),
 * and the index into buf is one byte, so n must stay below 8.
 * Callers: fwupd_record_write, usb_port_copy_blocks, usb_port_write_blocks, usb_port_write_bytes (IN_ORDER). */
void usb_port_write_blocks_buf(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char in_order) small
{
    unsigned char j;
    unsigned char block;
    for (block = 0; block < n; block++) {
        addr += block;
        reg_bus_block_addr0 = addr;
        reg_bus_block_addr1 = addr >> 8;
        reg_bus_block_addr2 = addr >> 16;
        reg_bus_block_addr3 = addr >> 24;
        reg_bus_block_ctrl = BUS_START;
        if (in_order == IN_ORDER) {
            for (j = block << 5; j < block * BLOCK_BYTES + BLOCK_BYTES; j += 4) {
                reg_bus_block_wdata = buf[j];
                reg_bus_block_wdata = buf[j + 1];
                reg_bus_block_wdata = buf[j + 2];
                reg_bus_block_wdata = buf[j + 3];
            }
        } else {
            for (j = block << 5; j < block * BLOCK_BYTES + BLOCK_BYTES; j += 4) {
                reg_bus_block_wdata = buf[j + 3];
                reg_bus_block_wdata = buf[j + 2];
                reg_bus_block_wdata = buf[j + 1];
                reg_bus_block_wdata = buf[j];
            }
        }
        if (n > 1) timer_delay_units(1);
    }
}
