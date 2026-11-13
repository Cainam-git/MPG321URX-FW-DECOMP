/* nvram_flush_pending_now  (FUN_a0140a0c)
 *
 * Write the pending flash-backed data at once.
 * Note: Writes flash.
 * Name basis: derived - when the pending flag is set; called before power-off and power saving
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0140a0c @ 0xa0140a0c, flags -mcpu=v8 -O3 -g.
 * Source form: the search is an inlined static helper with an early return of the index and 0xff after the loop;
 * the area number is held in a local.
 */
struct nvram_device_record { unsigned char bus_or_area; unsigned char block; unsigned short size; unsigned char row_blocks; char name[33]; };
struct nvram_area_record { unsigned short size; unsigned char kind, group; char name[32]; };
struct nvram_area_layout { unsigned short start; unsigned short half_2; int word_4; unsigned char current_row, row_count; unsigned char pad[2]; };
extern const struct nvram_device_record nvram_device_table[];   /* ROM storage-device records, 38 bytes each */
extern const struct nvram_area_record nvram_flash_area_table[]; /* ROM area records, 36 bytes each */
extern struct nvram_area_layout nvram_area_layouts[];           /* RAM area table, 12 bytes each */
extern unsigned char nvram_pending_write_flag;
extern unsigned short nvram_pending_flash_row;
extern void nvram_flash_advance_row(unsigned char);

#define NVRAM_DEVICE_COUNT 1        /* storage devices searched: only device 0 */
#define NVRAM_NO_DEVICE    0xff     /* "no device" argument of nvram_flash_advance_row */

/*
 * Find the storage device whose area contains the pending flash address: start <= address < start + size.
 * Returns the device number, or NVRAM_NO_DEVICE when none matches.
 */
static unsigned char find(void)
{
    unsigned char i, area;

    for (i = 0; i < NVRAM_DEVICE_COUNT; i++) {
        area = nvram_device_table[i].bus_or_area;
        if (nvram_area_layouts[area].start <= nvram_pending_flash_row && nvram_pending_flash_row < nvram_area_layouts[area].start + nvram_flash_area_table[area].size)
            return i;
    }
    return NVRAM_NO_DEVICE;
}

/*
 * If flash-backed data waits to be written (nvram_pending_write_flag), hand it to nvram_flash_advance_row now
 * and clear the flag. Called by SYSAPI_PowerSaving (SYSAPI_PowerSaving), so the data is out before power saving.
 */
void nvram_flush_pending_now(void)
{
    if (nvram_pending_write_flag != 0) {
        nvram_flash_advance_row(find());
        nvram_pending_write_flag = 0;
    }
}
