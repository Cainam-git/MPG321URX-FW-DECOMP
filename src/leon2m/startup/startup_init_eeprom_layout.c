/* startup_init_eeprom_layout  (FUN_a01400e0)
 *
 * Build the layout of the storage areas from the ROM tables.
 * Name basis: derived - called from start-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01400e0 @ 0xa01400e0, flags -mcpu=v8 -O3 -g.
 * Source form: device_offset_sum is declared first with 8 u16 slots (frame size 128; the slot index
 * 2 * area + block can reach 5, only slots 0 and 1 are cleared, as in the firmware); the running sums are '+=' (operand
 * order); the first loop stores next_row_word and current_row before the read; the row scan sits inside
 * 'if (kind == 0)' (a 'continue' duplicates the store of current_row); the one-record loops are written
 * 'for (i < 1)' (the firmware's 'cmp i,0; be'); counters are unsigned char.
 */
/* ROM record of one storage area (36 bytes; FW.021 has three, named "OPR_EEPROM_1/2/3"). */
struct nvram_area_record { unsigned short size; unsigned char kind, group; char name[32]; };
/* ROM record of one storage device (38 bytes; FW.021 has one, "DG_EEPROM1"). */
struct nvram_device_record { unsigned char area; unsigned char block; unsigned short size; unsigned char row_blocks; char name[33]; };
/* RAM layout of one area (12 bytes): start offset, current row (0xFF = none), row count. */
struct nvram_area_layout { unsigned short start; unsigned short half_2; int word_4; unsigned char current_row, row_count; unsigned char pad[2]; };
/* RAM layout of one device (4 bytes): start offset inside its slot. */
struct nvram_device_layout { unsigned short offset; unsigned char byte_2, byte_3; };
extern const struct nvram_area_record nvram_flash_area_table[];
extern const struct nvram_device_record nvram_device_table[];
extern struct nvram_area_layout nvram_area_layouts[];
extern struct nvram_device_layout nvram_device_layouts[];

/*
 * Build the RAM layout tables of the storage areas and devices from the two ROM tables. No hardware access, no
 * waits: every loop has a fixed bound. Called once at start-up, before the default records are loaded.
 *
 * 1. For each of the 3 area records: its layout gets start = the running total of its group (areas of one group
 *    follow each other, the group's total grows by the area's size), word_4 = -1 and current_row = 0xFF.
 * 2. For the one device record: the slot 2 * area + block keeps a running total; the device layout gets
 *    offset = that total before adding the device's size, and byte_2 = 8 >> row_blocks.
 * 3. For the one device record whose area has kind 0 only: the area holds n = (size >> 8) >> (row_blocks - 1)
 *    rows; row_count = n and current_row = the number of the first row whose last byte (read in place at
 *    start + (row + 1) * (row_blocks << 8) - 1) is 0x55, or 0xFF when none. FW.021's area 0 has kind 2, so this
 *    scan does not run there and current_row stays 0xFF.
 *
 * nvram_read, nvram_flash_advance_row and the other storage routines use these tables to find where an area lies.
 */
void startup_init_eeprom_layout(void)
{
    unsigned short device_offset_sum[8];
    unsigned short group_offset_sum[4];
    unsigned char i, row, slot, shift, row_count, found_row;
    unsigned short old_sum;
    struct nvram_area_layout *layout;

    for (i = 0; i < 4; i++)
        group_offset_sum[i] = 0;
    for (i = 0; i < 3; i++) {
        nvram_area_layouts[i].word_4 = -1;
        nvram_area_layouts[i].current_row = 0xff;
        nvram_area_layouts[i].start = group_offset_sum[nvram_flash_area_table[i].group];
        group_offset_sum[nvram_flash_area_table[i].group] += nvram_flash_area_table[i].size;
    }
    for (i = 0; i < 2; i++)
        device_offset_sum[i] = 0;
    for (i = 0; i < 1; i++) {
        slot = nvram_device_table[i].area * 2 + nvram_device_table[i].block;
        old_sum = device_offset_sum[slot];
        device_offset_sum[slot] += nvram_device_table[i].size;
        nvram_device_layouts[i].byte_2 = 8 >> nvram_device_table[i].row_blocks;
        nvram_device_layouts[i].offset = old_sum;
    }
    for (i = 0; i < 1; i++) {
        slot = nvram_device_table[i].area;
        if (nvram_flash_area_table[slot].kind == 0) {
            shift = nvram_device_table[i].row_blocks;
            layout = &nvram_area_layouts[slot];
            row_count = (nvram_flash_area_table[slot].size >> 8) >> (shift - 1);
            layout->row_count = row_count;
            found_row = 0xff;
            for (row = 0; row < row_count; row++)
                if (*(unsigned char *)(nvram_area_layouts[slot].start + (row + 1) * (shift << 8) - 1) == 0x55) {
                    found_row = row;
                    break;
                }
            layout->current_row = found_row;
        }
    }
}
