/* usb_port_read_blocks_buf  (FUN_CODE_abce)
 *
 * Read n 32-byte blocks from a bus address into a buffer.
 *   buf: destination
 *   addr: bus address
 *   n: blocks
 *   f: 1 keeps the byte order of each group of four, any other value reverses each group
 * Name basis: derived - address to bus block address registers, data from the block read data register; byte
 *   order per group of four set by in_order
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_abce @ 0xabce (392 B), SMALL-model function (parameter block ?_FUN_CODE_abce?BYTE at DATA 0x08:
 * buf 0x08..0x0A generic pointer, addr 0x0B..0x0E, n 0x0F, in_order 0x10; locals index 0x11, block 0x12).
 * Byte-exact with OPTIMIZE(7,SPEED), (8,SPEED) and (8,SPEED) LARGE. No aids.
 * reg_bus_block_rdata is declared volatile: the code reads the same address once for every byte it stores (a data
 * port), so the reads must not be merged. 'addr += block' inside the loop and the byte-wide index compared with
 * the int 'block * 32 + 32' are the firmware's forms.
 */

#define BLOCK_BYTES          32
#define BUS_START            0x80        /* written to the control and read-start registers */
#define BUS_READ_DONE        0x80        /* read status when the block is ready */
#define READ_WAIT_ROUNDS     0xfa        /* status reads before the block is taken anyway */
#define IN_PORT_ORDER        1           /* in_order value: bytes stored in the order they come */
#define BLOCK_PAUSE_UNITS    2           /* timer_delay_units pause after each block when n > 1 */

extern unsigned char xdata reg_bus_block_ctrl;
extern unsigned char xdata reg_bus_block_read_start;
extern unsigned char xdata reg_bus_block_read_status;
extern volatile unsigned char xdata reg_bus_block_rdata;
extern unsigned char xdata reg_bus_block_addr0;
extern unsigned char xdata reg_bus_block_addr1;
extern unsigned char xdata reg_bus_block_addr2;
extern unsigned char xdata reg_bus_block_addr3;
void timer_delay_units(unsigned char n);

/* usb_port_read_blocks_buf: read n blocks of 32 bytes through the bus block registers into buf.
 *
 * buf:      destination, n * 32 bytes.
 * addr:     bus address of the first block; one address step is one 32-byte block.
 * n:        number of blocks. Every caller passes 1, except usb_port_read_blocks with 2.
 * in_order: 1 stores the bytes in the order they come from the data register; any other value (all callers pass
 *           0) stores each group of four the other way round (fourth byte first). usb_port_write_blocks_buf has the
 *           same parameter.
 *
 * Per block: the four address bytes go out (bits 0..7 first), the control and read-start registers get 0x80, and
 * the status register is polled up to 250 times for 0x80; the 32 bytes are read whether or not it came. With n > 1
 * each block is followed by a short pause.
 * Two forms limit n: addr grows by the block number each round (blocks at addr, addr + 1, addr + 3, ...), so the
 * blocks follow each other only for n <= 2; and the buffer index is one byte, so n must stay below 8.
 * Callers: fwupd_build_record_table, fwupd_record_verify, fwupd_check_image_signature, usb_port_copy_blocks;
 * fwupd_record_copy_field and usb_port_read_blocks forward to it.
 */
void usb_port_read_blocks_buf(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char in_order) small
{
    unsigned char index;
    unsigned char block;
    for (block = 0; block < n; block++) {
        addr += block;
        reg_bus_block_addr0 = addr;
        reg_bus_block_addr1 = addr >> 8;
        reg_bus_block_addr2 = addr >> 16;
        reg_bus_block_addr3 = addr >> 24;
        reg_bus_block_ctrl = BUS_START;
        reg_bus_block_read_start = BUS_START;
        index = READ_WAIT_ROUNDS;
        do {
            if (reg_bus_block_read_status == BUS_READ_DONE) break;
        } while (--index);
        if (in_order == IN_PORT_ORDER) {
            for (index = block << 5; index < block * 32 + 32; index += 4) {
                buf[index] = reg_bus_block_rdata;
                buf[index + 1] = reg_bus_block_rdata;
                buf[index + 2] = reg_bus_block_rdata;
                buf[index + 3] = reg_bus_block_rdata;
            }
        } else {
            for (index = block << 5; index < block * 32 + 32; index += 4) {
                buf[index + 3] = reg_bus_block_rdata;
                buf[index + 2] = reg_bus_block_rdata;
                buf[index + 1] = reg_bus_block_rdata;
                buf[index] = reg_bus_block_rdata;
            }
        }
        if (n > 1) timer_delay_units(BLOCK_PAUSE_UNITS);
    }
}
