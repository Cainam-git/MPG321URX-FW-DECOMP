/* SYSAPI_EraseUSRFlashType2  (FUN_a014ad90)
 *
 * Erase the type 2 user data area.
 * Returns: 1 on success, 0 on error; as built always 0 (see the note)
 * Note: The area look-up accepts only code 0x30 inside code group 0x10, which no code is, so every call ends
 *   as 'unknown area' and nothing is erased. Nothing calls it.
 * Name basis: proven - prints 'SYSAPI_EraseUSRFlashType2 : DG Unknow!!!!!' (original name); no reference in
 *   the image
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014ad90, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: the area lookup is a static helper (inlined at -O3) that fills a local
 * struct kept on the stack, with a nested switch on (area_code & 0xf0) and then on area_code; the struct is
 * { unsigned char device; unsigned short size; }. The size field is filled but not read here. The second
 * parameter is declared and unused.
 */
struct usr_flash_area { unsigned char device; unsigned short size; };
extern unsigned char dbg_is_print_enabled(unsigned int level);
extern void nvram_erase_area(unsigned char dev);
extern int dbg_printf();

#define USR_FLASH_AREA_CODE  0x30       /* the only area code the lookup knows */
#define USR_FLASH_AREA_SIZE  0x8000     /* size of that area, in bytes; it is storage device 0 */
#define DEVICE_NONE          0xff       /* "no such area" in the device field */
#define DBG_CLASS_ERROR      0x40       /* debug message class tested before the error text is printed */

/*
 * Find the storage device of a user data area. Only the case "group 0x10 and code 0x30" sets it; a code cannot
 * be both 0x30 and in group 0x10, so for every code the device stays DEVICE_NONE.
 */
static void get_area(unsigned char area_code, struct usr_flash_area *area)
{
    area->device = DEVICE_NONE;
    area->size = 0;
    switch (area_code & 0xf0) {
    case 0x10:
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
 * Erase the type 2 user data area "area_code". Returns 1 when nvram_erase_area was called and 0 when the area
 * is unknown (an error text is printed then when the error debug class is on). Because of get_area, every call
 * ends in the unknown-area case. Nothing calls it.
 *
 * Note: Erases storage.
 */
_Bool SYSAPI_EraseUSRFlashType2(unsigned char area_code, unsigned char *unused)
{
    struct usr_flash_area area;
    _Bool ok = 0;

    get_area(area_code, &area);
    if (area.device == DEVICE_NONE) {
        if (dbg_is_print_enabled(DBG_CLASS_ERROR))
            dbg_printf("\033[1;31mSYSAPI_EraseUSRFlashType2 : DG Unknow!!!!!\r\n\033[m");
    } else {
        nvram_erase_area(area.device);
        ok = 1;
    }
    return ok;
}
