/* nvram_store_mode_row  (FUN_a01542c4)
 *
 * Store the mode record in the 20-row EEPROM table at 0x300, reusing or adding a row for the timing.
 * Note: Writes the EEPROM.
 * Name basis: derived - EEPROM table at offset 0x300 keyed by the timing key; a new timing takes the next ring
 *   row
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01542c4 @ 0xa01542c4-0xa015440c (82 words), -mcpu=v8 -O3 -g.
 * Levers: the row address in u16 ARITHMETIC '(unsigned short)(i << 4) + (unsigned short)0x300' (HImode add
 *   keeps the fw sll/srl 16 and the PRE copy); 'row.timing_key == mode->timing_key' (load order); the loop counter
 *   i reused for the ring index. The ring-block row ADDRESS is computed BEFORE the ring update ('i = ring_index;
 *   row_address = ...; ring_index = (i + 1) % 20;'): the fw adds 1 to the raw ldub and masks only for the address
 *   (without this form 14 words differ).
 * Aids: none. No volatile.
 */
/* The mode record passed in (the channel record from offset 6 on); only the fields copied into a row are named. */
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
/* The device settings record (0x50 bytes), of which only the ring index is used here. */
struct settings_ring {
    unsigned char before_ring_index[0x1a];
    unsigned char ring_index;               /* +0x1A: the table row the next new timing takes */
    unsigned char after_ring_index[0x50 - 0x1b];
};
extern struct settings_ring device_settings;
extern void nvram_read(int dev, unsigned short addr, int len, void *buf);
extern void nvram_write(int dev, unsigned short addr, int len, void *buf, int x);

/*
 * Save the mode record into the saved-mode table (20 rows of 16 bytes at EEPROM 0x300, device 0).
 *
 *   mode  the mode record of a channel (channel record + 6)
 *
 * The rows 0..19 are read in turn until one has the same timing key as the record. The row is then filled from
 * the record. A timing already in the table keeps its row and the row is rewritten in place. A new timing takes
 * the row named by the ring index in the device settings; the ring index moves on to the next row (after row 19
 * comes row 0, so the oldest row is overwritten) and the settings record is written back to the EEPROM at 0x470.
 * Last, the row is written to 0x300 + 16 * row.
 *
 * Called when nvram_load_saved_mode_row found no row for a new timing (input_match_port_mode, input_select_mode_row_by_id) and
 * by nvram_api_store_by_selector for the channels.
 */
void nvram_store_mode_row(struct mode_record *mode)
{
    struct saved_mode_row row = { 0 };
    unsigned char i, found = 0;
    unsigned short row_address;

    for (i = 0; i < 20; i++) {
        row_address = (unsigned short)(i << 4) + (unsigned short)0x300;
        nvram_read(0, row_address, 0x10, &row);
        if (row.timing_key == mode->timing_key) {
            found = 1;
            break;
        }
    }
    row.half_0x0 = mode->half_0x08;
    row.half_0x2 = mode->half_0x18;
    row.half_0x4 = mode->half_0x1a;
    row.half_0x6 = mode->half_0x22;
    row.half_0x8 = mode->half_0x24;
    row.half_0xa = mode->half_0x26;
    row.byte_0xc = mode->byte_0x20;
    row.byte_0xd = mode->byte_0x34;
    row.timing_key = mode->timing_key;
    if (!found) {
        i = device_settings.ring_index;
        row_address = (unsigned short)(i << 4) + (unsigned short)0x300;
        device_settings.ring_index = (i + 1) % 20;
        nvram_write(0, 0x470, 0x50, &device_settings, 0);
    }
    nvram_write(0, row_address, 0x10, &row, 0);
}
