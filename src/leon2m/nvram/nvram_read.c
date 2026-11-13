/* nvram_read  (FUN_a0140360)
 *
 * Read a block from a storage device: EEPROM over I2C, or the flash window.
 * Name basis: proven - i2c_gpio_read_block for EEPROM devices, a copy for flash-backed ones
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0140360 @ 0xa0140360, flags -mcpu=v8 -O3 -g (also with -msoft-float).
 * Source form (gcc 3.4.4, plain C, no aids). All three points below are needed for the firmware's code:
 *  1. 'goto out;' at the end of the flash arm. The goto predictor makes the flash arm less probable, which raises
 *     the weight of the entry block; the global register allocator then gives the product dev * 0x26 a register
 *     ahead of the zero-extended area byte, and the registers come out as in the firmware.
 *  2. Term order 'start + (block << 11) + device offset' in the kind != 0 arm: the RTL order decides the register
 *     renaming chain, which gives the same 'add' in both kind arms so that it fills the branch delay slot.
 *  3. Copy loop: 'k = i; ... buf[i] = p[k];' with an unsigned int k. A u16 index would be zero-extended and
 *     put first in the address; a plain register index keeps 'ldub [p + i]' as in the firmware, while the store
 *     keeps '[i + buf]'. 'p = flash_window + off; p += addr;' inside the loop gives the firmware's hoist order.
 */
struct nvram_device_record { unsigned char bus_or_area; unsigned char block; unsigned short size; unsigned char row_blocks; char name[33]; };
struct nvram_area_record { unsigned short size; unsigned char kind, group; char name[32]; };
struct nvram_area_layout { unsigned short start; unsigned short half_2; int word_4; unsigned char current_row, row_count; unsigned char pad[2]; };
struct nvram_device_layout { unsigned short offset; unsigned char byte_2, byte_3; };
/* Software I2C bus descriptor (10 bytes), as in i2c_gpio_write_block. */
struct i2c_bus { unsigned char scl_port, scl_mask, sda_port, sda_mask; unsigned short delay; unsigned char device, address_bytes; unsigned short mode; };
extern const struct nvram_device_record nvram_device_table[];   /* ROM storage-device records, 38 bytes each */
extern const struct nvram_area_record nvram_flash_area_table[];   /* ROM area records, 36 bytes each */
extern const struct i2c_bus nvram_bus_table[];   /* ROM I2C bus descriptors, 10 bytes each */
extern struct nvram_area_layout nvram_area_layouts[];         /* RAM area table (startup_init_eeprom_layout) */
extern struct nvram_device_layout nvram_device_layouts[];          /* RAM per-device offsets (startup_init_eeprom_layout) */
extern const unsigned char flash_window[]; /* CPU address 0: flash window */
extern void i2c_gpio_read_block(struct i2c_bus *, unsigned short, unsigned short, unsigned char *);

/* Memory-mapped read: copy len bytes from the flash window at off + addr (inlined into nvram_read). */
static void flash_copy(unsigned int off, unsigned short addr, unsigned short len, unsigned char *buf)
{
    unsigned short i;
    const unsigned char *p;
    unsigned int k;
    for (i = 0; i < len; i++) {
        k = i;
        p = flash_window + off;
        p += addr;
        buf[i] = p[k];
    }
}

/*
 * Read len bytes at offset addr of storage device dev into buf. No result.
 *
 *   dev   index into the ROM device table (FW.021 has one device, 0)
 *   addr  offset inside the device
 *
 * The device record's first byte decides the path. Bit 7 clear: an I2C EEPROM; the byte is the bus number, the
 * bus descriptor is copied to the stack and the bit-banged I2C block read does the work. Bit 7 set: the device
 * lies in flash and is read through the flash window (CPU address 0) with no bus traffic; the byte is then used
 * as the area number. The offset of the data in the window is
 *   - for an area of kind 0: the area's start, plus current_row * (row_blocks << 8) unless no row is current
 *     (current_row 0xFF);
 *   - for any other kind: the area's start + (block << 11) + the device's offset in its slot.
 * Called by the start-up settings check, FGA_Init and the other EEPROM readers. FW.021's device 0 takes the I2C path.
 */
void nvram_read(unsigned char dev, unsigned short addr, unsigned short len, unsigned char *buf)
{
    struct i2c_bus bus;
    unsigned char bus_or_area;
    unsigned short base;

    if ((signed char)nvram_device_table[dev].bus_or_area < 0) {
        bus_or_area = nvram_device_table[dev].bus_or_area;
        if (nvram_flash_area_table[bus_or_area].kind == 0) {
            base = nvram_area_layouts[bus_or_area].current_row == 0xff ? nvram_area_layouts[bus_or_area].start
                 : nvram_area_layouts[bus_or_area].current_row * (nvram_device_table[dev].row_blocks << 8) + nvram_area_layouts[bus_or_area].start;
        } else
            base = nvram_area_layouts[bus_or_area].start + (nvram_device_table[dev].block << 11) + nvram_device_layouts[dev].offset;
        flash_copy(base, addr, len, buf);
        goto out;
    }
    bus_or_area = nvram_device_table[dev].bus_or_area;
    bus = nvram_bus_table[bus_or_area];
    i2c_gpio_read_block(&bus, addr, len, buf);
out:
    ;
}
