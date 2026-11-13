/* nvram_erase_area  (FUN_a0140500)
 *
 * Erase the flash sector of a flash-backed storage area.
 * Note: Erases flash.
 * Name basis: derived - unlock, sector erase at the area base, lock
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0140500 @ 0xa0140500, flags -mcpu=v8 -O3 -g.
 * Source form: area_base is an inlined static helper that masks each return value with ~0xfff (the firmware
 * masks in both arms and narrows to 16 bits at the join).
 */
struct nvram_device_record { unsigned char bus_or_area; unsigned char block; unsigned short size; unsigned char row_blocks; char name[33]; };
struct nvram_area_record { unsigned short size; unsigned char kind, group; char name[32]; };
struct nvram_area_layout { unsigned short start; unsigned short half_2; int word_4; unsigned char current_row, row_count; unsigned char pad[2]; };
extern const struct nvram_device_record nvram_device_table[];   /* ROM storage-device records, 38 bytes each */
extern const struct nvram_area_record nvram_flash_area_table[]; /* ROM area records, 36 bytes each */
extern struct nvram_area_layout nvram_area_layouts[];           /* RAM area table, 12 bytes each */
extern void flash_write_protect_off(void);
extern void flash_write_protect_on(void);
extern void ipc_8051_flash_erase_sector(unsigned short);

/*
 * Start address of the 4 KB flash sector that holds the area's current row. The argument is used as the index
 * of the device record, and the area number is taken from that record's bus_or_area byte (the caller passes the
 * area number itself, which is the device number only for device 0). An area whose group byte is 0 is addressed
 * by its start plus current_row * (row_blocks << 8); any other area by its start plus (block << 11).
 */
static unsigned int area_base(unsigned char dev)
{
    unsigned char area = nvram_device_table[dev].bus_or_area;

    if (nvram_flash_area_table[area].group == 0)
        return (nvram_area_layouts[area].current_row * (nvram_device_table[dev].row_blocks << 8) + nvram_area_layouts[area].start) & ~0xfff;
    return ((nvram_device_table[dev].block << 11) + nvram_area_layouts[area].start) & ~0xfff;
}

/*
 * Erase the flash sector that holds storage device dev's area. Does nothing for a device without bit 7 set in
 * its bus_or_area byte (an I2C EEPROM); for a flash device the byte is the area number. The write protection is
 * lifted for the erase and set again afterwards. Called by pq_fga_handle_command and SYSAPI_EraseUSRFlashType2.
 */
void nvram_erase_area(unsigned char dev)
{
    unsigned char area = nvram_device_table[dev].bus_or_area;

    if ((signed char)nvram_device_table[dev].bus_or_area < 0) {
        flash_write_protect_off();
        ipc_8051_flash_erase_sector(area_base(area));
        flash_write_protect_on();
    }
}
