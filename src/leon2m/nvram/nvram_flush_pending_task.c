/* nvram_flush_pending_task  (FUN_a0140ab4)
 *
 * Write the pending flash-backed data once it has waited for more than 1000 ticks.
 * Note: Writes flash.
 * Name basis: derived - called from the main-loop task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0140ab4 @ 0xa0140ab4, flags -mcpu=v8 -O3 -g.
 * Source form: the device number r is an int set on two labelled paths (the firmware's 'and %o0,0xff' in the call
 * slot is the u8 argument conversion of a non-u8 value; with a u8 i it folds to a nop); a single call; the record
 * types are reduced to the fields read. The routine returns nothing.
 */
struct nvram_device_record_head { unsigned char bus_or_area; unsigned char rest[37]; };   /* 38-byte ROM record, first byte only */
struct nvram_area_record_head { unsigned short size; unsigned char rest[34]; };           /* 36-byte ROM record, first halfword only */
struct nvram_area_layout_head { unsigned short start; unsigned char rest[10]; };          /* 12-byte RAM record, first halfword only */
extern const struct nvram_device_record_head nvram_device_table[];
extern const struct nvram_area_record_head nvram_flash_area_table[];
extern struct nvram_area_layout_head nvram_area_layouts[];
extern unsigned char nvram_pending_write_flag;
extern unsigned short nvram_last_write_ticks;
extern unsigned short nvram_pending_flash_row;
extern unsigned short timer_ticks_since(unsigned short);
extern void nvram_flash_advance_row(unsigned char);

#define NVRAM_FLUSH_DELAY_TICKS 1000    /* pending data waits longer than this before it is written */
#define NVRAM_DEVICE_COUNT      1       /* storage devices searched: only device 0 */
#define NVRAM_NO_DEVICE         0xff    /* "no device" argument of nvram_flash_advance_row */

/*
 * Main-loop task (called by sys_main_loop_periodic_task). When flash-backed data waits to be written
 * (nvram_pending_write_flag) and more than 1000 ticks have passed since the last write (nvram_last_write_ticks),
 * find the storage device whose area contains the pending flash address (start <= address < start + size),
 * hand it to nvram_flash_advance_row (NVRAM_NO_DEVICE when none matches) and clear the flag.
 * nvram_flush_pending_now does the same at once, without the delay.
 */
void nvram_flush_pending_task(void)
{
    unsigned char i;
    int device;

    if (nvram_pending_write_flag == 0)
        return;
    if (timer_ticks_since(nvram_last_write_ticks) <= NVRAM_FLUSH_DELAY_TICKS)
        return;
    for (i = 0; i < NVRAM_DEVICE_COUNT; i++) {
        unsigned char area = nvram_device_table[i].bus_or_area;
        unsigned short start = nvram_area_layouts[area].start;
        if (start <= nvram_pending_flash_row && nvram_pending_flash_row < start + nvram_flash_area_table[area].size)
            goto found;
    }
    device = NVRAM_NO_DEVICE;
    goto out;
found:
    device = i;
out:
    nvram_flash_advance_row(device);
    nvram_pending_write_flag = 0;
}
