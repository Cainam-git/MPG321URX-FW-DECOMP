/* nvram_is_device_usable  (FUN_a0140304)
 *
 * Return whether a storage device can be used.
 * Returns: 1 when usable
 * Name basis: derived - leaf test used before a read
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0140304 @ 0xa0140304, flags -mcpu=v8 -O3 -g.
 * Source form: the record byte is read twice (ldub for the index, ldsb for the sign test) and the result is
 * 'and 1'.
 */
struct nvram_device_record { unsigned char bus_or_area; unsigned char block; unsigned short size; unsigned char row_blocks; char name[33]; };
struct nvram_area_layout { unsigned short start; unsigned short half_2; int word_4; unsigned char current_row, row_count; unsigned char pad[2]; };
extern const struct nvram_device_record nvram_device_table[];   /* ROM storage-device records, 38 bytes each */
extern struct nvram_area_layout nvram_area_layouts[];         /* RAM area table, 12 bytes each */

#define NVRAM_ROW_NONE 0xff     /* current_row value of an area with no current row */

/*
 * Tell whether storage device dev can be read. A device whose record has bit 7 of bus_or_area clear (an I2C
 * EEPROM) is always usable. A device in flash (bit 7 set; the byte is then its area number) is usable once its
 * area has a current row. The roles of the byte are those described in nvram_read.
 *
 * Called by the start-up settings check (nvram_validate_settings_at_startup, with device 0) and by SYSAPI_LoadUSRFlashType1 before it reads.
 * Reads RAM and ROM only; it cannot fail or wait.
 */
unsigned char nvram_is_device_usable(unsigned char dev)
{
    unsigned char usable = 1;
    if ((signed char)nvram_device_table[dev].bus_or_area < 0)
        usable = nvram_area_layouts[nvram_device_table[dev].bus_or_area].current_row != NVRAM_ROW_NONE;
    return usable & 1;
}
