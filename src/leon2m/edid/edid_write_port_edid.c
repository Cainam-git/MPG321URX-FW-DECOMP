/* edid_write_port_edid  (FUN_a012c80c)
 *
 * Write an EDID, or the built-in default for the port's variant, to an input port.
 * Note: Changes what the connected device sees.
 * Name basis: derived - default tables per variant; prints and stops when the data is larger than the port's
 *   memory
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012c80c @ 0xa012c80c-0xa012ccf0 (313 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - the variant byte device_settings[DEVICE_SETTINGS_EDID_VARIANT + port] is written out at each use, as in
 *    startup_load_port_edids (one load at 0xa012c820 for the test and the table reads, a second load at
 *    0xa012c8c4 for the print after the edid_get_port_memory_size calls);
 *  - the test is 'variant == EDID_VARIANT_NONE || partial' (xor/subx at 0xa012c824..2c, addx at 0xa012c838,
 *    orcc at 0xa012c844);
 *  - the hang loop is a for (;;) whose body is two asm nops (the firmware's loop body is two nop instructions);
 *  - the parameter len itself takes the table length and is reduced in place on the partial path ('len = len -
 *    done' / 'len = 0'): its entry copy 'mov %i3, %l3' at 0xa012c84c comes before the 'clrh' of the bus record at
 *    0xa012c850, the table length is loaded into %l3 at 0xa012c880, and the join at 0xa012c910 has only the 'srl'
 *    of the zero-extension with the 'sll' on each incoming path;
 *  - src is a local set in both arms ('src = data;' / 'src = edid_default_ptrs[...];'); with it the variant byte
 *    is in %o1 (0xa012c820, else-arm 'sll' at 0xa012c86c and 'add' at 0xa012c874);
 *  - the two mode bits of the bus record are two one-bit fields, bit 14 written before bit 15 ('andn' with
 *    0x40000000 at 0xa012ca58, 'or' with 0x80000000 at 0xa012ca60); delay = 4 after alen = 1 (sth at 0xa012ca78,
 *    before the edid_get_port_memory_size call);
 *  - the piece loop starts with 'remaining = len; done = 0;' (clr %l3 at 0xa012cad8);
 *  - the size code update is written as in startup_load_port_edids: the test against the old code first, then
 *    '&=' and '|=' on edid_port_size_codes (ld at 0xa012cc64, st at 0xa012cc98).
 */

/* Device settings bytes +0x1B + port: the EDID variant of each port, the index into edid_default_ptrs and
   edid_variant_lengths. */
#define DEVICE_SETTINGS_EDID_VARIANT 0x1b
#define EDID_VARIANT_NONE   0xff        /* no variant: the data given is written (edid_api_write_port_edid
                                           stores this when its clear argument is set) */

/* The 8051 keeps its EDID RAM in rows of 16 bytes (docs/MAILBOX.md, command 0x0D: offset / 16). */
#define EDID_RAM_ROW        0x10

/* The software I2C bus of a port without internal EDID. */
#define EDID_DEVICE         0xa0        /* bus address of the EDID memory */
#define BLOCK_SELECT_DEVICE 0x60        /* takes the number of the 256-byte block (address >> 8) */
#define BUS_BLOCK           0x100       /* one address byte reaches 256 bytes */
#define BUS_DELAY           4           /* delay field of the bus record */
#define ONE_ADDRESS_BYTE    1
#define BUS_WRITE_PIECE     8           /* bytes per bus write */
#define WRITE_WAIT_TICKS    0x13        /* longest wait for the memory to answer again after a piece */

/* Bus record of the software I2C routines (same layout as in i2c_gpio_write_block). The two mode bits are bits
   15 and 14 of the halfword at +8; i2c_gpio_write_block and _probe_device use the bus only in mode 2 (bit 15 set,
   bit 14 clear). */
struct I2cBus { unsigned char scl_port, scl_mask, sda_port, sda_mask; unsigned short delay; unsigned char dev, alen;
                unsigned short mode_bit1 : 1, mode_bit0 : 1, rest : 14; };
extern unsigned int edid_port_size_codes;
extern unsigned char device_settings[];
extern const unsigned short edid_variant_lengths[];
extern unsigned int edid_default_ptrs[];
extern int dbg_printf(const char *, ...);
extern unsigned char edid_get_port_flag(unsigned char);
extern unsigned short edid_get_port_memory_base(unsigned char);
extern unsigned short edid_get_port_memory_size(unsigned char);
extern unsigned char input_slot_get_table_byte8(unsigned char);
extern unsigned char input_slot_get_table_byte9(unsigned char);
extern unsigned char input_slot_get_table_byte10(unsigned char);
extern unsigned char edid_get_bus_table_byte0(unsigned char);
extern unsigned char edid_get_bus_table_byte1(unsigned char);
extern unsigned char edid_get_bus_table_byte2(unsigned char);
extern unsigned char edid_get_bus_table_byte3(unsigned char);
extern unsigned char ddc_get_port_slave_address(unsigned char);
extern void ipc_8051_disable_ddc_slave(unsigned char);
extern void ipc_8051_enable_ddc_slave(unsigned char, unsigned char);
extern void ipc_8051_enable_internal_edid(unsigned char, unsigned short, unsigned char);
extern void ipc_8051_read_port_memory(unsigned short, unsigned char, unsigned char *);
extern void ipc_8051_wait_tx_queue(unsigned char, unsigned short);
extern void ipc_8051_write_port_memory(unsigned short, unsigned short, unsigned char *);
extern unsigned short i2c_gpio_write_block(struct I2cBus, unsigned short, unsigned short, unsigned char *, unsigned char,
                                      unsigned char);
extern void gpio_write_pin(unsigned char, unsigned char, unsigned char);
extern void timer_sleep_ticks(unsigned short);
extern unsigned char i2c_gpio_probe_device(unsigned char);
extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short);

/*
 * Write an EDID into a port's EDID memory.
 *
 *   port     index into the port table (the callers get it with input_port_table_get_bus_id)
 *   addr     first byte of the memory to write
 *   data     the bytes to write, when they are used (see below)
 *   len      number of bytes in data
 *   partial  1: write len bytes of data at addr; 0: write a whole EDID
 *
 * Called by edid_api_write_port_edid (partial 0, after it has stored the port's variant byte) and
 * edid_api_write_port_edid_bytes (partial 1).
 *
 * Phases:
 *  1. Choose the bytes. With partial set, or when the port's variant byte (device settings +0x1B + port) is
 *     0xFF, the data given is written. Otherwise the built-in EDID of that variant (edid_default_ptrs) with its
 *     length (edid_variant_lengths) replaces data and len.
 *  2. Length check. When the bytes do not fit the port's EDID memory (edid_get_port_memory_size), print
 *     "DDC_<port> : MaxLen <size> / EDID_<variant> : Len <len>" and stop here for ever.
 *  3a. Ports whose flag is set (edid_get_port_flag) keep their EDID in the 8051's EDID RAM, at the port's base.
 *     Partial: a start that is not on a 16-byte row is merged into that row (row read back, bytes copied in, row
 *     written); the rest is written from the next row on. Whole EDID: the port's size code (its nibble of
 *     edid_port_size_codes, the length in 128-byte units) is set to the new length and the bytes are written;
 *     when the length differs from what the old code gave, the internal EDID of the port is switched on again
 *     with the new length (ipc_8051_enable_internal_edid). Before each write the routine waits until the queue
 *     to the 8051 has room for the bytes (ipc_8051_wait_tx_queue in mode 1, which has no time limit).
 *  3b. Every other port has an EDID memory on a software I2C bus. The 8051's DDC/CI slave of the port is off
 *     meanwhile, and the pin given by bytes +8 / +9 of the port's port table entry is driven to the inverse of
 *     its level byte +0xA. The bytes go out in pieces of 8, each preceded by the block number sent to device
 *     0x60 when the memory is larger than 256 bytes; after each piece the routine waits until the memory answers
 *     its address again, checking every 2 ticks for at most 0x13 ticks. At the end the pin goes back to its
 *     level and the DDC/CI slave is switched on again with the port's option byte as its slave address.
 */
void edid_write_port_edid(unsigned char port, unsigned short addr, unsigned char *data, unsigned short len,
                  unsigned char partial)
{
    unsigned char row[16];
    unsigned char *src;
    unsigned char i, paged, row_offset, size_changed;
    struct I2cBus bus = { 0 };
    unsigned short base, remaining, done, row_addr, start_ticks;

    paged = 0;
    size_changed = 0;
    done = 0;

    /* 1. The data given, or the built-in EDID of the port's variant. */
    if (device_settings[DEVICE_SETTINGS_EDID_VARIANT + port] == EDID_VARIANT_NONE || partial)
        src = data;
    else {
        src = (unsigned char *)edid_default_ptrs[device_settings[DEVICE_SETTINGS_EDID_VARIANT + port]];
        len = edid_variant_lengths[device_settings[DEVICE_SETTINGS_EDID_VARIANT + port]];
    }

    /* 2. Too long for the port's memory: report and stop. */
    if (len > edid_get_port_memory_size(port)) {
        dbg_printf("\033[1;31mDDC_%d : MaxLen %d / EDID_%d : Len %d\r\n\033[m", port, edid_get_port_memory_size(port), device_settings[DEVICE_SETTINGS_EDID_VARIANT + port], len);
        for (;;) {
            __asm__ volatile ("nop");
            __asm__ volatile ("nop");
        }
    }

    /* 3a. EDID in the 8051's EDID RAM. */
    if (edid_get_port_flag(port)) {
        base = edid_get_port_memory_base(port);
        if (partial) {
            if (addr & 0xf) {
                /* Not on a row: read the row back, put the first bytes into it and write it whole. */
                row_addr = addr & ~0xf;
                ipc_8051_read_port_memory(row_addr + base, EDID_RAM_ROW, row);
                row_offset = addr & 0xf;
                done = (len <= EDID_RAM_ROW - row_offset) ? len : EDID_RAM_ROW - row_offset;
                for (i = 0; i < done; i++)
                    row[row_offset + i] = src[i];
                ipc_8051_wait_tx_queue(1, EDID_RAM_ROW);
                ipc_8051_write_port_memory(base + row_addr, EDID_RAM_ROW, row);
                if (done < len) {
                    len = len - done;
                    addr = row_addr + EDID_RAM_ROW;
                } else
                    len = 0;
            }
            /* The rest, from the next row on. */
            if (len != 0) {
                ipc_8051_wait_tx_queue(1, len);
                ipc_8051_write_port_memory(base + addr, len, src + done);
            }
        } else {
            /* Whole EDID: keep the port's size code (length / 128) up to date. */
            if (len != ((edid_port_size_codes >> (port * 4)) & 0xf) << 7)
                size_changed = 1;
            edid_port_size_codes &= ~(0xf << (port * 4));
            edid_port_size_codes |= (len >> 7) << (port * 4);
            ipc_8051_wait_tx_queue(1, len);
            ipc_8051_write_port_memory(base + addr, len, src);
            /* A new length: switch the port's internal EDID on again with it (base in 128-byte units). */
            if (size_changed)
                ipc_8051_enable_internal_edid(1 << port, len, base >> 7);
        }
        return;
    }

    /* 3b. EDID memory on the port's software I2C bus. Keep the 8051's DDC/CI slave of the port off meanwhile. */
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
    if (edid_get_port_memory_size(port) > BUS_BLOCK)
        paged = 1;
    /* The port table pin: port +8, mask +9, driven to the inverse of level +0xA during the write. */
    gpio_write_pin(input_slot_get_table_byte8(port), input_slot_get_table_byte9(port), ~input_slot_get_table_byte10(port));
    remaining = len;
    done = 0;
    while (remaining != 0) {
        if (paged) {
            bus.dev = BLOCK_SELECT_DEVICE;
            i2c_gpio_write_block(bus, addr >> 8, 0, 0, 1, 0);
            bus.dev = EDID_DEVICE;
        }
        if (remaining > BUS_WRITE_PIECE) {
            i2c_gpio_write_block(bus, addr & 0xff, BUS_WRITE_PIECE, src + done, 1, 1);
            remaining -= BUS_WRITE_PIECE;
            addr += BUS_WRITE_PIECE;
            done += BUS_WRITE_PIECE;
        } else {
            i2c_gpio_write_block(bus, addr & 0xff, remaining, src + done, 1, 1);
            remaining = 0;
        }
        /* Wait until the memory answers its address again, or the time is up. */
        start_ticks = timer_get_ticks16();
        do {
            timer_sleep_ticks(2);
            if (i2c_gpio_probe_device(bus.dev))
                break;
        } while (timer_ticks_since(start_ticks) <= WRITE_WAIT_TICKS);
    }
    gpio_write_pin(input_slot_get_table_byte8(port), input_slot_get_table_byte9(port), input_slot_get_table_byte10(port));
    ipc_8051_enable_ddc_slave(1 << port, ddc_get_port_slave_address(port));
}
