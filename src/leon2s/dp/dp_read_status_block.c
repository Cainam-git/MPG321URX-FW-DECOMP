/* dp_read_status_block  (FUN_a00ae5e4)
 *
 * Read a port's queued status bytes and run a register 0x24 bit sequence for three known patterns.
 * Note: Sequence: bit 1 of register 0x24 off, bit 2 on, register 0x25 = 0, bit 3 on; patterns 0x10/0x30,
 *   0x10/0x50 and 0x50/0x50 in bytes 0 and 2.
 * Name basis: descriptive - register 0xF9, then bits of register 0x24
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ae5e4 @ 0xa00ae5e4-0xa00ae850 (620 bytes), flags -mcpu=v8 -Os -g.
 * Source forms: every call passes the raw parameter to a callee whose first parameter is unsigned char, so
 * the 'and 0xff' is redone after each join, as in the firmware; the function returns its parameter, which
 * keeps the final call a normal call (no sibling call).
 */
#define STATUS_BLOCK_MAX 0x14                   /* bytes kept in dp_status_block_bytes */

extern unsigned char dp_status_block_bytes[];
extern unsigned int dp_reg_read8(unsigned char, unsigned short);
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned int, unsigned int);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned int);
extern void timer_delay_units(unsigned int);

/*
 * Read the status bytes a DP receiver has queued and, for three known patterns, run a sequence on register
 * 0x24.
 *
 * Does nothing unless bit 3 of register 0xF7 is set. Otherwise register 0xF9 is read for as long as bit 0 of
 * register 0xF8 is set; the first 20 bytes go to dp_status_block_bytes (not cleared first, so bytes after the
 * last one received keep their old value), later ones are read and dropped. The bits 3..7 of register 0xF8,
 * read before the loop, are called version below. Then, by bytes 0, 2 and 3 of the buffer:
 *   0x10, 0x30: the sequence (bit 1 of 0x24 cleared, bit 2 set, 0x25 = 0) twice, bit 3 set, a wait of
 *               800 delay units, bit 0 cleared;
 *   0x10, 0x50: the sequence once, bit 3 set;
 *   0x50, 0x50 with byte 3 = 0 and version 4: bit 0 set, the sequence once.
 * At the end bit 3 of register 0xF7 is set again. Called by dp_isr_port0 and dp_isr_port1.
 *   port: DP receiver (0 or 1)
 *   returns: port
 */
unsigned int dp_read_status_block(unsigned int port)
{
    unsigned char version;
    unsigned char count;

    if (dp_reg_read8(port, 0xf7) & 8) {
        version = (unsigned char)dp_reg_read8(port, 0xf8) >> 3;
        count = 0;
        while (dp_reg_read8(port, 0xf8) & 1) {
            if (count < STATUS_BLOCK_MAX) {
                dp_status_block_bytes[count] = dp_reg_read8(port, 0xf9);
                count++;
            } else {
                dp_reg_read8(port, 0xf9);
            }
        }
        if (dp_status_block_bytes[0] == 0x10 && dp_status_block_bytes[2] == 0x30) {
            dp_reg_update_bits(port, 0x24, 2, 0);
            dp_reg_update_bits(port, 0x24, 4, 1);
            dp_reg_write8(port, 0x25, 0);
            dp_reg_update_bits(port, 0x24, 2, 0);
            dp_reg_update_bits(port, 0x24, 4, 1);
            dp_reg_write8(port, 0x25, 0);
            dp_reg_update_bits(port, 0x24, 8, 1);
            timer_delay_units(800);
            dp_reg_update_bits(port, 0x24, 1, 0);
        }
        if (dp_status_block_bytes[0] == 0x10 && dp_status_block_bytes[2] == 0x50) {
            dp_reg_update_bits(port, 0x24, 2, 0);
            dp_reg_update_bits(port, 0x24, 4, 1);
            dp_reg_write8(port, 0x25, 0);
            dp_reg_update_bits(port, 0x24, 8, 1);
        }
        if (dp_status_block_bytes[0] == 0x50 && dp_status_block_bytes[2] == 0x50 && dp_status_block_bytes[3] == 0 && version == 4) {
            dp_reg_update_bits(port, 0x24, 1, 1);
            dp_reg_update_bits(port, 0x24, 2, 0);
            dp_reg_update_bits(port, 0x24, 4, 1);
            dp_reg_write8(port, 0x25, 0);
        }
        dp_reg_update_bits(port, 0xf7, 8, 1);
    }
    return port;
}
