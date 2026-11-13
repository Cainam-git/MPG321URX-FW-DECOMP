/* pq_load_fga_color_entries  (FUN_a014e320)
 *
 * Copy three stored FGA colour entries (columns 0x02, 0x10, 0x80) to part record +6, +9 and +0x12.
 * Note: Row = 1 << low nibble of sys_config byte +0x18; each copy needs bit 4 of that byte and a valid stored
 *   entry.
 * Name basis: derived - pq_fga_read_color_entry for the row bit of sys_config byte +0x18 and three column
 *   bits, results stored as three-byte entries of part_record; called from APPActionDispatcher
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014e320, flags -mcpu=v8 -O3 -g.
 * Source form: sys_config and part_record are byte arrays; each block repeats the whole test, and the byte
 * copies are written in this order (it gives the firmware's load / store schedule).
 */
extern unsigned char sys_config[];
extern unsigned char part_record[];
extern unsigned char pq_is_fga_bit4_set(unsigned char gamma_selection);
extern unsigned char pq_fga_read_color_entry(unsigned short row, unsigned char column, unsigned char *rgb);

#define SYS_CONFIG_GAMMA_SELECTION 0x18 /* low nibble: FGA row bit number; bit 4: FGA data in use */
#define FGA_ROW_NUMBER_MASK        0x0f

/* Columns of the stored colour block (as FGA_COLOR_KEYS). */
#define FGA_COLUMN_WARM50          0x02
#define FGA_COLUMN_NORMAL65        0x10
#define FGA_COLUMN_COOL93          0x80

/* Colour triples of the part record that receive them. */
#define PART_WARM50                0x06
#define PART_NORMAL65              0x09
#define PART_COOL93                0x12

/*
 * Copy the three stored FGA colours of the current gamma selection into the part record: column Warm 50 to
 * part_record +6..+8, Normal 65 to +9..+0xB and Cool 93 to +0x12..+0x14 (red, green, blue each).
 *
 * Each copy is made only while bit 4 of sys_config.gamma_selection is set (FGA data in use) and
 * pq_fga_read_color_entry finds the entry; the row is 1 << (low nibble of the gamma selection). A triple that
 * is not read keeps its value. pq_apply_picture_mode reads the same entries and these triples.
 * Called by APPActionDispatcher in its before-display steps of the main channel.
 */
void pq_load_fga_color_entries(void)
{
    unsigned char rgb[3];

    if (pq_is_fga_bit4_set(sys_config[SYS_CONFIG_GAMMA_SELECTION]) && pq_fga_read_color_entry(1 << (sys_config[SYS_CONFIG_GAMMA_SELECTION] & FGA_ROW_NUMBER_MASK), FGA_COLUMN_WARM50, rgb)) {
        part_record[PART_WARM50] = rgb[0];
        part_record[PART_WARM50 + 1] = rgb[1];
        part_record[PART_WARM50 + 2] = rgb[2];
    }
    if (pq_is_fga_bit4_set(sys_config[SYS_CONFIG_GAMMA_SELECTION]) && pq_fga_read_color_entry(1 << (sys_config[SYS_CONFIG_GAMMA_SELECTION] & FGA_ROW_NUMBER_MASK), FGA_COLUMN_NORMAL65, rgb)) {
        part_record[PART_NORMAL65] = rgb[0];
        part_record[PART_NORMAL65 + 1] = rgb[1];
        part_record[PART_NORMAL65 + 2] = rgb[2];
    }
    if (pq_is_fga_bit4_set(sys_config[SYS_CONFIG_GAMMA_SELECTION]) && pq_fga_read_color_entry(1 << (sys_config[SYS_CONFIG_GAMMA_SELECTION] & FGA_ROW_NUMBER_MASK), FGA_COLUMN_COOL93, rgb)) {
        part_record[PART_COOL93] = rgb[0];
        part_record[PART_COOL93 + 1] = rgb[1];
        part_record[PART_COOL93 + 2] = rgb[2];
    }
}
