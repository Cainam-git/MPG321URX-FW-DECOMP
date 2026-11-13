/* SYSAPI_LoadUSRFlashType1  (FUN_a014aaa0)
 *
 * Read a block of type 1 user data from storage after checking that it fits.
 * Returns: 1 on success, 0 on error; as built always 0 (see the note)
 * Note: The area look-up accepts only code 0x30 inside code group 0x00, which no code is, so every call ends
 *   as 'unknown area'. A read would start at offset 0 whatever offset is given. Nothing calls it.
 * Name basis: proven - prints 'SYSAPI_LoadUSRFlashType1 : ...' (original name); no reference in the image
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014aaa0, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: the area lookup is a static helper (inlined at -O3) that fills a local
 * struct kept on the stack, with a nested switch on (area_code & 0xf0) and then on area_code; the struct is
 * { unsigned char device; unsigned short size; }. SYSAPI_SaveUSRFlashType1 uses the same helper.
 */
struct usr_flash_area { unsigned char device; unsigned short size; };
extern unsigned char dbg_is_print_enabled(unsigned int level);
extern unsigned char nvram_is_device_usable(unsigned char dev);
extern void nvram_read(unsigned char dev, unsigned short addr, unsigned short len, unsigned char *buf);
extern int dbg_printf();

#define USR_FLASH_AREA_CODE  0x30       /* the only area code the lookup knows */
#define USR_FLASH_AREA_SIZE  0x8000     /* size of that area, in bytes; it is storage device 0 */
#define DEVICE_NONE          0xff       /* "no such area" in the device field */
#define DBG_CLASS_ERROR      0x40       /* debug message class tested before the error text is printed */

/*
 * Find the storage device and size of a user data area. Only the case "group 0x00 and code 0x30" sets them;
 * a code cannot be both 0x30 and in group 0x00, so for every code the device stays DEVICE_NONE and the size 0.
 */
static void get_area(unsigned char area_code, struct usr_flash_area *area)
{
    area->device = DEVICE_NONE;
    area->size = 0;
    switch (area_code & 0xf0) {
    case 0x00:
        switch (area_code) {
        case USR_FLASH_AREA_CODE:
            area->device = 0;
            area->size = USR_FLASH_AREA_SIZE;
            break;
        }
        break;
    }
}

/*
 * Read len bytes at offset "offset" of the type 1 user data area "area_code" into buf.
 * Returns 1 when the data was read and 0 when the area is unknown, the request does not fit in the area, or
 * the storage device is not usable. An unknown area or a request that does not fit prints an error text when
 * the error debug class is on. Because of get_area, every call ends in the unknown-area case.
 * Nothing calls it.
 *
 * Note: the offset is only used in the size check; the read always starts at offset 0.
 */
_Bool SYSAPI_LoadUSRFlashType1(unsigned char area_code, unsigned char *buf, unsigned short offset, unsigned short len)
{
    struct usr_flash_area area;
    _Bool ok = 0;

    get_area(area_code, &area);
    if (area.device == DEVICE_NONE || offset + len > area.size) {
        if (dbg_is_print_enabled(DBG_CLASS_ERROR))
            dbg_printf("\033[1;31mSYSAPI_LoadUSRFlashType1 : DG Unknow or exceed size limit!!!!!\r\n\033[m");
    } else {
        if (nvram_is_device_usable(area.device) == 1) {
            ok = 1;
            nvram_read(area.device, 0, len, buf);
        }
    }
    return ok;
}
