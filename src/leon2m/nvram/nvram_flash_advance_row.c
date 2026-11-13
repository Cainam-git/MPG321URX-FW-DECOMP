/* nvram_flash_advance_row  (FUN_a01405d0)
 *
 * Move a flash-backed storage area on to its next row and write it there.
 * Note: Writes flash.
 * Name basis: derived - advances the row index and issues the erase / write sequence for the old and new row
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01405d0 @ 0xa01405d0, flags -mcpu=v8 -O3 -g.
 * Source form: plan is written through a pointer plan_ptr = &plan and read directly (the firmware rebuilds the
 * frame address at the shared retire_old = 1 store; plan.old_row is stored but never read); the old_row != 0xff
 * arm comes first and the 0xff arm assigns old_row = 0xff again (the firmware sets the register to -1 there); the
 * test for retire_old is grouped as 'erase && (new < old && old < new + per)' (the ungrouped '&&' is folded into
 * flag arithmetic). row_addr and area_base are inlined static helpers with one exit and an unsigned short result
 * variable, so the masks are 16-bit immediates and the conversion follows the join; row_addr selects the index with
 * '?:' into a new variable; the sums are written start + (block << 11).
 */
struct nvram_device_record { unsigned char bus_or_area; unsigned char block; unsigned short size; unsigned char row_blocks; char name[33]; };
struct nvram_area_record { unsigned short size; unsigned char kind, group; char name[32]; };
struct nvram_area_layout { unsigned short start; unsigned short half_2; int word_4; unsigned char current_row, row_count; unsigned char pad[2]; };
/* What to do for this advance (see nvram_flash_advance_row). */
struct row_plan { unsigned char mark_new, retire_old, erase_sector, old_row; };
extern const struct nvram_device_record nvram_device_table[];
extern const struct nvram_area_record nvram_flash_area_table[];
extern struct nvram_area_layout nvram_area_layouts[];
extern unsigned short nvram_pending_flash_row;
extern unsigned char nvram_new_row_marker[], nvram_old_row_marker[];
extern void flash_write_protect_off(void);
extern void flash_write_protect_on(void);
extern void ipc_8051_flash_erase_sector(unsigned short);
extern void ipc_8051_flash_program_row(unsigned short, unsigned char);
extern void MailBox_LoadFE2P(unsigned short, unsigned char);
extern void ipc_8051_send_storage_block(unsigned short, unsigned short, unsigned char *);

/* Start address of the flash sector (4 KB: mask 0xf000) that holds the area's current row. */
static unsigned short area_base(unsigned char dev)
{
    unsigned char area = nvram_device_table[dev].bus_or_area;
    unsigned short address;

    if (nvram_flash_area_table[area].group == 0)
        address = (nvram_area_layouts[area].current_row * (nvram_device_table[dev].row_blocks << 8) + nvram_area_layouts[area].start) & 0xf000;
    else
        address = (nvram_area_layouts[area].start + (nvram_device_table[dev].block << 11)) & 0xf000;
    return address;
}

/*
 * Flash address of a row of the device's area. row = 0xff stands for the area's current row. Result 0xffff when
 * the area has no current row. For an area of kind 0 the address is start + row * (row_blocks << 8); for any
 * other kind it is (start + (block << 11)) & 0xf800 whatever the row.
 */
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
 * Write out the 8051's flash data buffer for a flash-backed device, moving an area of kind 0 on to its next row.
 * Writes flash. Does nothing for an I2C device (bit 7 of the device record's first byte clear; FW.021's
 * device 0 is one).
 *
 *   dev  index into the ROM device table
 *
 * Area of kind 1: the buffer is programmed to the pending row (nvram_pending_flash_row), 8 units long.
 *
 * Other kinds: the area is a ring of row_count rows, each row_blocks * 256 bytes long, and the last byte of a
 * row is its marker (startup_init_eeprom_layout takes the first row whose last byte is 0x55 as the current
 * row). The next row is (current + 3) % row_count; with no current row (0xff) it is row 0. The plan:
 *   - erase_sector: the new row is the first row of a 4 KB sector (new % (16 / row_blocks) == 0), so that
 *     sector is erased first (never with no current row);
 *   - mark_new: always; the buffer's last byte is set to the byte at nvram_new_row_marker and the buffer is programmed
 *     to the new row;
 *   - retire_old: unless a sector was erased that holds the old row, and not with no current row; the buffer's
 *     last byte is set to the byte at nvram_old_row_marker and programmed to the old row, then the new row is loaded
 *     back into the buffer.
 * Flash write protection is off for the whole sequence. Called by nvram_write (when its flag is set), by the
 * flush routines and by nvram_flash_prepare_write.
 */
void nvram_flash_advance_row(unsigned char dev)
{
    unsigned char area = nvram_device_table[dev].bus_or_area;
    unsigned char old_row;
    unsigned char new_row, row_blocks;
    int rows_per_sector;
    unsigned short old_address, new_address;
    struct row_plan plan;
    struct row_plan *plan_ptr = &plan;

    if ((signed char)nvram_device_table[dev].bus_or_area >= 0)
        return;
    if (nvram_flash_area_table[area].kind == 1) {
        flash_write_protect_off();
        ipc_8051_flash_program_row(nvram_pending_flash_row, 8);
        flash_write_protect_on();
        return;
    }
    old_row = nvram_area_layouts[area].current_row;
    if (old_row != 0xff) {
        new_row = (old_row + 3) % nvram_area_layouts[area].row_count;
        rows_per_sector = 16 / nvram_device_table[dev].row_blocks;
        nvram_area_layouts[area].current_row = new_row;
        plan_ptr->mark_new = 1;
        plan_ptr->old_row = old_row;
        plan_ptr->erase_sector = new_row % rows_per_sector == 0;
        /* No retire when the erase takes the old row's sector with it. */
        if (plan_ptr->erase_sector && (new_row < old_row && old_row < new_row + rows_per_sector))
            plan_ptr->retire_old = 0;
        else
            plan_ptr->retire_old = 1;
    } else {
        nvram_area_layouts[area].current_row = 0;
        old_row = 0xff;
        plan_ptr->mark_new = 1;
        plan_ptr->old_row = old_row;
        plan_ptr->erase_sector = 0;
        plan_ptr->retire_old = 0;
    }
    old_address = row_addr(dev, old_row);
    new_address = row_addr(dev, 0xff);
    row_blocks = nvram_device_table[dev].row_blocks;
    flash_write_protect_off();
    if (plan.erase_sector)
        ipc_8051_flash_erase_sector(area_base(dev));
    if (plan.mark_new)
        ipc_8051_send_storage_block(row_blocks * 256 - 1, 1, nvram_new_row_marker);
    ipc_8051_flash_program_row(new_address, row_blocks);
    if (plan.retire_old) {
        ipc_8051_send_storage_block(row_blocks * 256 - 1, 1, nvram_old_row_marker);
        ipc_8051_flash_program_row(old_address, row_blocks);
        MailBox_LoadFE2P(new_address, row_blocks);
    }
    flash_write_protect_on();
}
