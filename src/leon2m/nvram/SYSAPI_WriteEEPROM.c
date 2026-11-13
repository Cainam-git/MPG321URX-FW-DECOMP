/* SYSAPI_WriteEEPROM  (FUN_a014aed0)
 *
 * Write a block to the settings EEPROM after checking that it fits.
 * Returns: 1 on success, 0 on error
 * Note: Writes the EEPROM.
 * Name basis: proven - prints 'SYSAPI_WriteEEPROM : DG Unknow or exceed size limit!!!!!' (original name)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014aed0, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: the area lookup is a static helper (inlined at -O3) that fills a local
 * struct kept on the stack, with a nested switch on (area_code & 0xf0) and then on area_code; the struct is
 * { unsigned char device; unsigned short size; }.
 */
struct eeprom_area { unsigned char device; unsigned short size; };
extern unsigned char dbg_is_print_enabled(unsigned int level);
extern int nvram_write();
extern int dbg_printf();

#define EEPROM_AREA       0x30          /* the only area code the lookup knows (also the code group 0x30) */
#define EEPROM_AREA_SIZE  0x8000        /* size of that area, in bytes; it is storage device 0 */
#define DEVICE_NONE       0xff          /* "no such area" in the device field */
#define DBG_CLASS_ERROR   0x40          /* debug message class tested before the error text is printed */

/* Find the storage device and size of an EEPROM area; only EEPROM_AREA is known. */
static void get_area(unsigned char area_code, struct eeprom_area *area)
{
    area->device = DEVICE_NONE;
    area->size = 0;
    switch (area_code & 0xf0) {
    case 0x30:
        switch (area_code) {
        case EEPROM_AREA:
            area->device = 0;
            area->size = EEPROM_AREA_SIZE;
            break;
        }
        break;
    }
}

/*
 * Write len bytes from buf at offset "offset" of the EEPROM area "area_code" (EEPROM_AREA is the only one
 * accepted). Returns 1 when the data was handed to nvram_write and 0 when the area is unknown or the request
 * does not fit in the area (an error text is printed then when the error debug class is on).
 *
 * Note: Writes the EEPROM. Unlike the type 1 and type 2 savers, it passes 1 as the last argument of nvram_write.
 */
_Bool SYSAPI_WriteEEPROM(unsigned char area_code, unsigned char *buf, unsigned short offset, unsigned short len)
{
    struct eeprom_area area;
    _Bool ok = 0;

    get_area(area_code, &area);
    if (area.device == DEVICE_NONE || offset + len > area.size) {
        if (dbg_is_print_enabled(DBG_CLASS_ERROR))
            dbg_printf("\033[1;31mSYSAPI_WriteEEPROM : DG Unknow or exceed size limit!!!!!\r\n\033[m");
    } else {
        nvram_write(area.device, offset, len, buf, 1);
        ok = 1;
    }
    return ok;
}
