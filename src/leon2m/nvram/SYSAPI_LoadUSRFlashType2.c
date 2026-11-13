/* SYSAPI_LoadUSRFlashType2  (FUN_a014ac28)
 *
 * Read a block of type 2 user data from storage after checking that it fits.
 * Returns: 1 on success, 0 on error; as built always 0 (see the note)
 * Note: The area look-up accepts only code 0x30 inside code group 0x10, which no code is, so every call ends
 *   as 'unknown area'. Nothing calls it.
 * Name basis: proven - prints 'SYSAPI_LoadUSRFlashType2 : ...' (original name); no reference in the image
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014ac28, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: the area lookup is written in the routine itself as a local struct
 * { unsigned char device; unsigned short limit; } that stays in memory; the device field is preset to 0xff and
 * set again in every arm of the nested ifs; the result is an unsigned char returned as (ok & 1); the print
 * test is (dbg_is_print_enabled(...) & 0xff). SYSAPI_ReadEEPROM is the same code with other constants.
 */
extern int dbg_printf(const char *fmt, ...);
extern unsigned int dbg_is_print_enabled(unsigned int);
extern void nvram_read(unsigned char dev, unsigned short addr, unsigned short len, unsigned char *buf);

struct usr_flash_area {
    unsigned char device;       /* storage device number, 0xff when the area is unknown */
    unsigned short limit;       /* size of the area in bytes */
};

#define USR_FLASH_AREA_CODE  0x30       /* the only area code the lookup knows */
#define USR_FLASH_AREA_SIZE  0x8000     /* size of that area, in bytes; it is storage device 0 */
#define DEVICE_NONE          0xff       /* "no such area" in the device field */
#define DBG_CLASS_ERROR      0x40       /* debug message class tested before the error text is printed */

/*
 * Read len bytes at offset "offset" of the type 2 user data area "area_code" into buf.
 * Returns 1 when the data was read and 0 when the area is unknown or the request does not fit in the area
 * (an error text is printed then when the error debug class is on).
 * The lookup accepts only code 0x30 inside code group 0x10, which no code satisfies, so every call ends in the
 * unknown-area case. Nothing calls it.
 */
unsigned char SYSAPI_LoadUSRFlashType2(unsigned char area_code, unsigned char *buf, unsigned short offset, unsigned short len)
{
    struct usr_flash_area area;
    unsigned char ok = 0;

    area.device = DEVICE_NONE;

    if ((area_code & 0xf0) == 0x10) {
        if (area_code == USR_FLASH_AREA_CODE) {
            area.device = 0;
            area.limit = USR_FLASH_AREA_SIZE;
        } else {
            area.device = DEVICE_NONE;
            area.limit = 0;
        }
    } else {
        area.device = DEVICE_NONE;
        area.limit = 0;
    }
    if (area.device != DEVICE_NONE && offset + len <= area.limit) {
        nvram_read(area.device, offset, len, buf);
        ok = 1;
    } else if (dbg_is_print_enabled(DBG_CLASS_ERROR) & 0xff)
        dbg_printf("\033[1;31mSYSAPI_LoadUSRFlashType2 : DG Unknow or exceed size limit!!!!!\r\n\033[m");
    return ok & 1;
}
