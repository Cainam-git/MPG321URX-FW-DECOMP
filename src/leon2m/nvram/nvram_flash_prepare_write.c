/* nvram_flash_prepare_write  (FUN_a0140b78)
 *
 * Prepare the row of a flash-backed area for a write at a given offset.
 * Name basis: descriptive - row advance or program call by the area record; remembers the row address
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0140b78 @ 0xa0140b78, flags -mcpu=v8 -O3 -g.
 * Source form: the search is an inlined static helper as in nvram_flush_pending_now; row_addr is the one-exit
 * helper with an unsigned short result variable, called first with the pre-read row byte; the call of
 * nvram_flash_advance_row is written twice, once per arm of 'area != pending_area' /
 * 'kind == 1 && address != pending row', each behind its own test of nvram_pending_write_flag.
 */
struct nvram_device_record { unsigned char bus_or_area; unsigned char block; unsigned short size; unsigned char row_blocks; char name[33]; };
struct nvram_area_record { unsigned short size; unsigned char kind, group; char name[32]; };
struct nvram_area_layout { unsigned short start; unsigned short half_2; int word_4; unsigned char current_row, row_count; unsigned char pad[2]; };
extern const struct nvram_device_record nvram_device_table[];
extern const struct nvram_area_record nvram_flash_area_table[];
extern struct nvram_area_layout nvram_area_layouts[];
extern unsigned char nvram_pending_write_flag;
extern unsigned short nvram_pending_flash_row;
extern void nvram_flash_advance_row(unsigned char);
extern void MailBox_LoadFE2P(unsigned short, unsigned char);

/* The device whose area contains the pending row address; 0xff when none (only device 0 is tested). */
static unsigned char find_pending_device(void)
{
    unsigned char i, area;

    for (i = 0; i < 1; i++) {
        area = nvram_device_table[i].bus_or_area;
        if (nvram_area_layouts[area].start <= nvram_pending_flash_row && nvram_pending_flash_row < nvram_area_layouts[area].start + nvram_flash_area_table[area].size)
            return i;
    }
    return 0xff;
}

/* Flash address of a row of the device's area; same helper as in nvram_flash_advance_row (row 0xff = current row). */
static unsigned short row_addr(unsigned char dev, unsigned char row)
{
    unsigned char area = nvram_device_table[dev].bus_or_area;
    unsigned short address;
    unsigned char index;

    if (nvram_flash_area_table[area].kind == 0) {
        index = row == 0xff ? nvram_area_layouts[area].current_row : row;
        if (index == 0xff)
            address = -1;
        else
            address = index * (nvram_device_table[dev].row_blocks << 8) + nvram_area_layouts[area].start;
    } else
        address = (nvram_area_layouts[area].start + (nvram_device_table[dev].block << 11)) & 0xf800;
    return address;
}

/*
 * Get the 8051's flash data buffer ready for a write into a flash-backed device, and remember which flash row the
 * buffer now stands for (nvram_pending_flash_row; 0xffff means none).
 *
 *   dev  index into the ROM device table
 *
 * 1. Work out the address of the device's current row (row_addr) and which device owns the row that is pending
 *    now (find_pending_device).
 * 2. If another row is pending, it is first written out with nvram_flash_advance_row, but only when
 *    nvram_pending_write_flag says data waits there. This happens when the pending row belongs to a different
 *    area, or to the same area of kind 1 when the pending row is not the one needed now.
 * 3. Load the row into the buffer (MailBox_LoadFE2P). Area of kind 0: if the area has no current row yet,
 *    row 0 becomes the current row and is loaded; otherwise the current row is loaded only when the pending
 *    row belonged to a different area, else nothing is loaded. Other kinds: the 8-unit row at
 *    the area's fixed address is loaded unless it is already the pending row.
 * 4. The row address becomes the pending row.
 * Called by nvram_write before it sends its data to the buffer.
 */
void nvram_flash_prepare_write(unsigned char dev)
{
    unsigned char area = nvram_device_table[dev].bus_or_area;
    unsigned short address = row_addr(dev, nvram_area_layouts[area].current_row);
    unsigned char pending_device = find_pending_device();
    unsigned char pending_area = nvram_device_table[pending_device].bus_or_area;

    if (nvram_pending_flash_row != 0xffff) {
        if (area != pending_area) {
            if (nvram_pending_write_flag)
                nvram_flash_advance_row(pending_device);
        } else if (nvram_flash_area_table[area].kind == 1 && address != nvram_pending_flash_row) {
            if (nvram_pending_write_flag)
                nvram_flash_advance_row(pending_device);
        }
    }
    if (nvram_flash_area_table[area].kind == 0) {
        if (address == 0xffff) {
            nvram_area_layouts[area].current_row = 0;
            address = row_addr(dev, 0xff);
            MailBox_LoadFE2P(address, nvram_device_table[dev].row_blocks);
        } else if (area != pending_area)
            MailBox_LoadFE2P(address, nvram_device_table[dev].row_blocks);
    } else {
        if (nvram_pending_flash_row != address)
            MailBox_LoadFE2P(address, 8);
    }
    nvram_pending_flash_row = address;
}
