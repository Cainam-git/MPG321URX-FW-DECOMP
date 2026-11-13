/* pq_color_matrix_set_blue_offset  (FUN_a013b544)
 *
 * Store the third offset value and program the offsets.
 * Name basis: derived - byte 2 of the offset record; channel index 2, the index that the menu's blue gain item
 *   uses
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013b544 @ 0xa013b544-0xa013b5a0 (23 words), flags -mcpu=v8 -O3 -g.
 * Source form: the body of pq_color_matrix_set_offsets is a static function here (set_offsets), inlined with the
 * arguments (stored red, stored green, blue).
 */

/* The offsets of matrix rows 0, 1 and 2. */
struct color_offsets { unsigned char red, green, blue; };
extern struct color_offsets pq_color_offsets;
extern unsigned char pq_color_matrix_flags;
extern void pq_color_matrix_write(unsigned char, unsigned char, unsigned short *, int);

#define COLOR_MATRIX_FLAG_ON  0x01      /* bit 0 of pq_color_matrix_flags: enable argument; bit 1: mode argument */
#define MATRIX_VALUES         12        /* three rows of {R, G, B coefficient, offset} */
#define OFFSET_SLOT(row)      ((row) * 4 + 3)
#define ALL_ROW_OFFSETS       0x70      /* which_rows of pq_color_matrix_write: the offsets of rows 0..2 only */

/* Copy of pq_color_matrix_set_offsets: store the three offsets and write them. */
static void set_offsets(unsigned char red, unsigned char green, unsigned char blue)
{
    unsigned short values[MATRIX_VALUES];

    pq_color_offsets.red = red;
    pq_color_offsets.green = green;
    pq_color_offsets.blue = blue;
    values[OFFSET_SLOT(0)] = red;
    values[OFFSET_SLOT(1)] = green;
    values[OFFSET_SLOT(2)] = blue;
    pq_color_matrix_write(pq_color_matrix_flags & COLOR_MATRIX_FLAG_ON, (pq_color_matrix_flags >> 1) & 1, values,
                          ALL_ROW_OFFSETS);
}

/*
 * Replace the offset of matrix row 2, keep the other two, and write all three offsets.
 * Callers: pq_api_set_rgb_offset and sys_api_config (setting 0..100 turned into setting * 2 + 0x1C).
 */
void pq_color_matrix_set_blue_offset(unsigned char blue)
{
    set_offsets(pq_color_offsets.red, pq_color_offsets.green, blue);
}
