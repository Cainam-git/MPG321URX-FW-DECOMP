/* nvram_load_saved_mode_row  (FUN_a01541ec)
 *
 * Find the saved EEPROM row for the current timing and restore it into the mode record.
 * Returns: found flag
 * Name basis: derived - 20-row table keyed by the timing key; copies the row into the mode record
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01541ec, flags -mcpu=v8 -O3 -g.
 * Source form: the row address is computed in 16-bit arithmetic, '(unsigned short)(row_index << 4) +
 * (unsigned short)0x300' (the halfword add keeps the firmware's sll/srl 16). The tail is written
 * 'if (found == 1) { copy; return 1; } return 0;', which gives the firmware's layout (the found block has its own
 * copy of the found test and the loop-exit test jumps into it). The copy statements run in row order
 * (row halfwords 0..5, then the two bytes); a different order changes the load/store order of the firmware.
 * No volatile.
 */
/* The mode record passed in (the channel record from offset 6 on); only the fields held in a row are named. */
struct mode_record {
    unsigned char before_half_0x08[8];
    unsigned short half_0x08;
    unsigned char before_half_0x18[0x18 - 0x0a];
    unsigned short half_0x18, half_0x1a;
    unsigned char before_byte_0x20[0x20 - 0x1c];
    unsigned char byte_0x20, pad_0x21;
    unsigned short half_0x22, half_0x24, half_0x26;
    unsigned char before_byte_0x34[0x34 - 0x28];
    unsigned char byte_0x34, pad_0x35;
    unsigned short timing_key;              /* +0x36: identifies the timing; the key of the table rows */
};
/* One row of the saved-mode table (16 bytes); the key is the last halfword. */
struct saved_mode_row {
    unsigned short half_0x0, half_0x2, half_0x4, half_0x6, half_0x8, half_0xa;
    unsigned char byte_0xc, byte_0xd;
    unsigned short timing_key;
};
extern void nvram_read(int dev, unsigned short addr, int len, void *buf);

/*
 * Look the timing of a mode record up in the saved-mode table (20 rows of 16 bytes at EEPROM offset 0x300,
 * device 0) and, when a row has the same timing key, copy the row's values into the record.
 *
 *   mode  the mode record of a channel (channel record + 6); its timing_key is the search key
 *
 * Rows are read in turn from row 0 and the search stops at the first row with the same key. Returns 1 when a
 * row was found and copied into the record (half_0x08, half_0x18, half_0x1a, half_0x22, half_0x24, half_0x26,
 * byte_0x20, byte_0x34), 0 when none was found; then the record is not changed.
 *
 * Called by input_match_port_mode when a new input timing is applied; when it returns 0 the timing is
 * stored with nvram_store_mode_row. The row layout is the one nvram_store_mode_row writes.
 */
unsigned char nvram_load_saved_mode_row(struct mode_record *mode)
{
    struct saved_mode_row row = { 0 };
    unsigned char row_index, found = 0;

    for (row_index = 0; row_index < 20; row_index++) {
        nvram_read(0, (unsigned short)(row_index << 4) + (unsigned short)0x300, 0x10, &row);
        if (mode->timing_key == row.timing_key) {
            found = 1;
            break;
        }
    }
    if (found == 1) {
        mode->half_0x08 = row.half_0x0;
        mode->half_0x18 = row.half_0x2;
        mode->half_0x1a = row.half_0x4;
        mode->half_0x22 = row.half_0x6;
        mode->half_0x24 = row.half_0x8;
        mode->half_0x26 = row.half_0xa;
        mode->byte_0x20 = row.byte_0xc;
        mode->byte_0x34 = row.byte_0xd;
        return 1;
    }
    return 0;
}
