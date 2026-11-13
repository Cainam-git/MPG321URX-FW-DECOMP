/* nvram_write  (FUN_a0140e74)
 *
 * Write a block to a storage device, page by page, waiting until the chip is ready.
 * Note: Writes the EEPROM or flash.
 * Name basis: proven - i2c_gpio_write_block per page for EEPROM devices; flash route for the others
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0140e74 @ 0xa0140e74, flags -mcpu=v8 -O3 -g.
 * Source form: (1) the bit-7 (flash) path is written first ('if (bus_or_area < 0) { flash } else { I2C }'): with
 * -frename-registers (on at -O3) the register renaming walks the basic blocks in source order and picks the least
 * recently used register, so the block order decides the registers of the I2C path; (2) 'offset = 0; if (...)
 * offset = ...;' in a static u16 helper; (3) the descriptor copy is a struct copy in each chunk arm.
 */
struct nvram_device_record { unsigned char bus_or_area; unsigned char block; unsigned short size; unsigned char row_blocks; char name[33]; };
struct nvram_area_record { unsigned short size; unsigned char kind, group; char name[32]; };
struct nvram_device_layout { unsigned short offset; unsigned char byte_2, byte_3; };
/* Software I2C bus descriptor (10 bytes), as in i2c_gpio_write_block. */
struct i2c_bus { unsigned char scl_port, scl_mask, sda_port, sda_mask; unsigned short delay; unsigned char device, address_bytes; unsigned short mode; };
/* Port, mask and level of a bus's write pin. */
struct write_pin { unsigned char port, mask, level; };
extern const struct nvram_device_record nvram_device_table[];
extern const struct nvram_area_record nvram_flash_area_table[];
extern const struct i2c_bus nvram_bus_table[];
extern const struct write_pin nvram_write_pins[];
extern struct nvram_device_layout nvram_device_layouts[];
extern unsigned char nvram_pending_write_flag;
extern unsigned short nvram_last_write_ticks;
extern void gpio_write_pin(unsigned char, unsigned char, unsigned char);
extern unsigned short i2c_gpio_write_block(struct i2c_bus *, unsigned short, unsigned short, unsigned char *, unsigned char, unsigned char);
extern void timer_sleep_ticks(unsigned short);
extern unsigned char i2c_gpio_probe_device(unsigned char);
extern unsigned short timer_get_ticks16(void);
extern void func_0x4008c86c(unsigned char, unsigned char, unsigned char);
extern void nvram_flash_prepare_write(unsigned char);
extern void ipc_8051_send_storage_block(unsigned short, unsigned short, unsigned char *);
extern void nvram_flash_advance_row(unsigned char);

#define I2C_WRITE_PAGE_BYTES 16     /* longest single page write */
#define I2C_WRITE_SETTLE_TICKS 7    /* sleep after each page write, before the acknowledge poll */

/* Offset of the device's data inside its area's buffer: the device's offset in its slot for an area of kind 1, else 0. */
static unsigned short area_offset(unsigned char dev, unsigned char area)
{
    unsigned short offset = 0;
    if (nvram_flash_area_table[area].kind == 1)
        offset = nvram_device_layouts[dev].offset;
    return offset;
}

/*
 * Write len bytes from buf to storage device dev at offset addr.
 * Writes the EEPROM or flash.
 *
 *   dev   index into the ROM device table (FW.021 has one device, 0)
 *   addr  offset inside the device
 *   len   number of bytes
 *   buf   the data
 *   flag  flash-backed device only: non-zero writes the buffer out to flash now
 *
 * The first byte of the device record decides the path.
 *
 * Bit 7 set (flash-backed): nvram_flash_prepare_write makes the 8051's flash data buffer ready, the data is sent
 * into it at addr (plus area_offset), nvram_pending_write_flag is set and the time stamp
 * nvram_last_write_ticks is taken (the flush task writes pending data to flash 1000 ticks later). With flag set
 * nvram_flash_advance_row writes it to flash at once and the pending flag is cleared again.
 *
 * Bit 7 clear (I2C EEPROM, bus number = that byte; FW.021's device 0): the bus's write pin
 * (nvram_write_pins) is driven to the opposite of its stored level, the data goes out in pages of at most
 * 16 bytes, and after each page the routine sleeps 7 ticks and then polls the device until it acknowledges its
 * address. The pin returns to its stored level after the last page. The poll has no counter and no timeout, so a
 * device that never answers holds the routine for ever. The result of each page write (the count of
 * acknowledged bytes) is not looked at: a failed write is not reported.
 * Called by the code that saves settings, FGA data and the saved-mode table.
 */
void nvram_write(unsigned char dev, unsigned short addr, unsigned short len, unsigned char *buf, unsigned char flag)
{
    unsigned char bus_or_area;
    unsigned short remaining, offset;

    if ((signed char)nvram_device_table[dev].bus_or_area < 0) {
        bus_or_area = nvram_device_table[dev].bus_or_area;
        nvram_flash_prepare_write(dev);
        offset = area_offset(dev, bus_or_area);
        ipc_8051_send_storage_block(addr + offset, len, buf);
        nvram_pending_write_flag = 1;
        nvram_last_write_ticks = timer_get_ticks16();
        if (flag) {
            nvram_flash_advance_row(dev);
            nvram_pending_write_flag = 0;
        }
    } else {
        bus_or_area = nvram_device_table[dev].bus_or_area;
        func_0x4008c86c(nvram_write_pins[bus_or_area].port, nvram_write_pins[bus_or_area].mask, ~nvram_write_pins[bus_or_area].level);
        remaining = len;
        while (remaining != 0) {
            if (remaining > I2C_WRITE_PAGE_BYTES) {
                struct i2c_bus bus = nvram_bus_table[bus_or_area];
                i2c_gpio_write_block(&bus, addr, I2C_WRITE_PAGE_BYTES, buf + (len - remaining), 1, 1);
                addr += I2C_WRITE_PAGE_BYTES;
                remaining -= I2C_WRITE_PAGE_BYTES;
            } else {
                struct i2c_bus bus = nvram_bus_table[bus_or_area];
                i2c_gpio_write_block(&bus, addr, remaining, buf + (len - remaining), 1, 1);
                remaining = 0;
            }
            timer_sleep_ticks(I2C_WRITE_SETTLE_TICKS);
            while (!i2c_gpio_probe_device(nvram_bus_table[bus_or_area].device))
                ;
        }
        func_0x4008c86c(nvram_write_pins[bus_or_area].port, nvram_write_pins[bus_or_area].mask, nvram_write_pins[bus_or_area].level);
    }
}
