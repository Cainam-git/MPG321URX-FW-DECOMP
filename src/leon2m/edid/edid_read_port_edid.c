/* edid_read_port_edid  (FUN_a012c320)
 *
 * Read the EDID memory of an input port, in full or a given range.
 * Name basis: derived - through the 8051 for ports with internal EDID, else over the port's own bus; the
 *   memory 'Enable Internal EDID' switches
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012c320 @ 0xa012c320-0xa012c80c (315 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - 'start = addr;' precedes 'done = 0;' (0xa012c34c, 0xa012c350);
 *  - row_offset is an unsigned char local set after the row read ('and %l1, 0xf' at 0xa012c77c); the test at
 *    0xa012c370 is a separate 'btst 0xf';
 *  - the two mode bits of the bus record are two one-bit fields, bit 14 written before bit 15 ('andn' with
 *    0x40000000 at 0xa012c458, 'or' with 0x80000000 at 0xa012c464);
 *  - inferred: the two bus loops advance a variable of their own (address), set from addr before each loop; the
 *    firmware keeps the incoming %i1 for them and for the first part with the single copy at 0xa012c34c, and a
 *    version that advances the parameter itself compiles with one more register copy there.
 */

/* The 8051 reads its EDID RAM back in rows of 16 bytes (docs/MAILBOX.md, command 0x0D: offset / 16). */
#define EDID_RAM_ROW        0x10
#define EDID_RAM_PIECE      0x80        /* the most this routine asks of the 8051 in one read */

/* The software I2C bus of a port without internal EDID. */
#define EDID_DEVICE         0xa0        /* bus address of the EDID memory */
#define BLOCK_SELECT_DEVICE 0x60        /* takes the number of the 256-byte block (address >> 8) */
#define BUS_BLOCK           0x100       /* one address byte reaches 256 bytes */
#define BUS_DELAY           4           /* delay field of the bus record */
#define ONE_ADDRESS_BYTE    1

/* Bus record of the software I2C routines (same layout as in i2c_gpio_write_block). The two mode bits are bits
   15 and 14 of the halfword at +8; i2c_gpio_read_block, _write_block and _probe_device use the bus only in mode 2
   (bit 15 set, bit 14 clear). */
struct I2cBus { unsigned char scl_port, scl_mask, sda_port, sda_mask; unsigned short delay; unsigned char dev, alen;
                unsigned short mode_bit1 : 1, mode_bit0 : 1, rest : 14; };
extern unsigned char edid_get_port_flag(unsigned char);
extern unsigned short edid_get_port_memory_base(unsigned char);
extern unsigned short edid_get_port_memory_size(unsigned char);
extern unsigned char edid_get_bus_table_byte0(unsigned char);
extern unsigned char edid_get_bus_table_byte1(unsigned char);
extern unsigned char edid_get_bus_table_byte2(unsigned char);
extern unsigned char edid_get_bus_table_byte3(unsigned char);
extern unsigned char ddc_get_port_slave_address(unsigned char);
extern void ipc_8051_disable_ddc_slave(unsigned char);
extern void ipc_8051_enable_ddc_slave(unsigned char, unsigned char);
extern void ipc_8051_read_port_memory(unsigned short, unsigned char, unsigned char *);
extern unsigned short i2c_gpio_read_block(struct I2cBus, unsigned short, unsigned short, unsigned char *);
extern unsigned short i2c_gpio_write_block(struct I2cBus, unsigned short, unsigned short, unsigned char *, unsigned char,
                                      unsigned char);

/*
 * Read a port's EDID into buf, either the whole EDID memory or len bytes from addr.
 *
 *   port     index into the port table (the callers get it with input_port_table_get_bus_id)
 *   addr     first byte to read when partial is set; on the bus path also the start of a full read
 *   buf      receives the bytes
 *   len      partial set: the number of bytes to read; partial clear: receives the size of the port's EDID
 *            memory (edid_get_port_memory_size), which is the number of bytes read
 *   partial  1: read len bytes from addr; 0: read the whole EDID memory
 *
 * Called by edid_api_read_port_edid (whole memory, addr 0) and edid_api_read_port_edid_range (partial).
 *
 * Two kinds of port:
 *  1. Ports whose flag is set (edid_get_port_flag) keep their EDID in the 8051's EDID RAM, at the port's base
 *     (edid_get_port_memory_base). The bytes are asked of the 8051 in pieces of at most 0x80
 *     (ipc_8051_read_port_memory). A partial read that does not start on a 16-byte row first reads that whole
 *     row and copies the wanted bytes out of it; the pieces then go on from the next row. A full read starts at
 *     the base and does not use addr.
 *  2. Every other port has an EDID memory on a software I2C bus. While the bus is in use, the 8051's DDC/CI
 *     slave of the port is switched off; at the end it is switched on again with the port's option byte as its
 *     slave address. When the memory is larger than 256 bytes, every read is preceded by the block number
 *     (address >> 8) sent to device 0x60, and no read crosses a 256-byte boundary.
 */
void edid_read_port_edid(unsigned char port, unsigned short addr, unsigned char *buf, unsigned short *len,
                  unsigned char partial)
{
    unsigned char row[16] = { 0 };
    struct I2cBus bus = { 0 };
    unsigned short base, remaining, piece, offset, done, start, memory_size, address;
    unsigned char i, paged, row_offset;

    start = addr;
    done = 0;
    paged = 0;

    /* 1. EDID in the 8051's EDID RAM. */
    if (edid_get_port_flag(port)) {
        base = edid_get_port_memory_base(port);
        if (partial) {
            remaining = *len;
            if (addr & 0xf) {
                /* Not on a row: read the whole row and take the bytes from addr to its end (or fewer). */
                addr &= ~0xf;
                ipc_8051_read_port_memory(addr + base, EDID_RAM_ROW, row);
                row_offset = start & 0xf;
                done = (*len <= EDID_RAM_ROW - row_offset) ? *len : EDID_RAM_ROW - row_offset;
                for (i = 0; i < done; i++)
                    buf[i] = row[row_offset + i];
                if (done < *len) {
                    start = addr + EDID_RAM_ROW;
                    remaining = remaining - done;
                } else
                    remaining = 0;
            }
            /* The rest from start on, behind the bytes already copied. */
            offset = 0;
            while (remaining != 0) {
                if (remaining > EDID_RAM_PIECE) {
                    ipc_8051_read_port_memory(base + start, EDID_RAM_PIECE, buf + (offset + done));
                    base += EDID_RAM_PIECE;
                    offset += EDID_RAM_PIECE;
                    remaining -= EDID_RAM_PIECE;
                } else {
                    ipc_8051_read_port_memory(base + start, remaining, buf + (offset + done));
                    remaining = 0;
                }
            }
        } else {
            /* The whole memory, from its base. */
            remaining = edid_get_port_memory_size(port);
            *len = remaining;
            offset = 0;
            while (remaining != 0) {
                if (remaining > EDID_RAM_PIECE) {
                    ipc_8051_read_port_memory(base, EDID_RAM_PIECE, buf + offset);
                    base += EDID_RAM_PIECE;
                    offset += EDID_RAM_PIECE;
                    remaining -= EDID_RAM_PIECE;
                } else {
                    ipc_8051_read_port_memory(base, remaining, buf + offset);
                    remaining = 0;
                }
            }
        }
        return;
    }

    /* 2. EDID memory on the port's software I2C bus. Keep the 8051's DDC/CI slave of the port off meanwhile. */
    ipc_8051_disable_ddc_slave(1 << port);
    bus.scl_port = edid_get_bus_table_byte0(port);
    bus.scl_mask = edid_get_bus_table_byte1(port);
    bus.sda_port = edid_get_bus_table_byte2(port);
    bus.sda_mask = edid_get_bus_table_byte3(port);
    bus.dev = EDID_DEVICE;
    bus.mode_bit0 = 0;
    bus.mode_bit1 = 1;
    bus.alen = ONE_ADDRESS_BYTE;
    bus.delay = BUS_DELAY;
    memory_size = edid_get_port_memory_size(port);
    if (memory_size > BUS_BLOCK)
        paged = 1;
    if (partial) {
        /* len bytes from addr, in pieces that end at a 256-byte boundary. */
        remaining = *len;
        address = addr;
        while (remaining != 0) {
            if (paged) {
                bus.dev = BLOCK_SELECT_DEVICE;
                i2c_gpio_write_block(bus, address >> 8, 0, 0, 1, 0);
                bus.dev = EDID_DEVICE;
            }
            piece = ((address & 0xff) + remaining > BUS_BLOCK) ? BUS_BLOCK - (address & 0xff) : remaining;
            i2c_gpio_read_block(bus, address & 0xff, piece, buf + done);
            address += piece;
            done += piece;
            remaining -= piece;
        }
    } else {
        /* The whole memory. */
        piece = edid_get_port_memory_size(port);
        *len = piece;
        if (paged) {
            /* One 256-byte block at a time. The bytes land at buf + address, so the read is meant to start
               at addr 0 (what edid_api_read_port_edid passes). */
            remaining = piece;
            address = addr;
            while (remaining != 0) {
                bus.dev = BLOCK_SELECT_DEVICE;
                i2c_gpio_write_block(bus, address >> 8, 0, 0, 1, 0);
                bus.dev = EDID_DEVICE;
                if (remaining > BUS_BLOCK) {
                    i2c_gpio_read_block(bus, address & 0xff, BUS_BLOCK, buf + address);
                    address += BUS_BLOCK;
                    remaining -= BUS_BLOCK;
                } else {
                    i2c_gpio_read_block(bus, address & 0xff, remaining, buf + address);
                    address += remaining;
                    remaining = 0;
                }
            }
        } else
            i2c_gpio_read_block(bus, addr, piece, buf);
    }
    ipc_8051_enable_ddc_slave(1 << port, ddc_get_port_slave_address(port));
}
