/* pq_color_matrix_set_offsets  (FUN_a013b4e8)
 *
 * Store the three offset values and program them.
 * Name basis: derived - offset record at 0xA802A468, then the matrix register routine with the offset column;
 *   unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013b4e8 @ 0xa013b4e8-0xa013b544 (23 words), flags -mcpu=v8 -O3 -g.
 * Source form: the offsets are one struct of three bytes, stored in ascending offset order red, green, blue
 * (the order red, blue, green gives other code); all three parameters are unsigned char.
 */

/* The offsets of matrix rows 0, 1 and 2. */
struct color_offsets { unsigned char red, green, blue; };
extern struct color_offsets pq_color_offsets;
extern unsigned char pq_color_matrix_flags;
extern void pq_color_matrix_write(unsigned char, unsigned char, unsigned short *, int);

#define COLOR_MATRIX_FLAG_ON  0x01      /* bit 0 of pq_color_matrix_flags: enable argument */
                                        /* bit 1 (COLOR_MATRIX_FLAG_OPTION) is the mode argument */
#define MATRIX_VALUES         12        /* three rows of {R, G, B coefficient, offset} */
#define OFFSET_SLOT(row)      ((row) * 4 + 3)
#define ALL_ROW_OFFSETS       0x70      /* which_rows of pq_color_matrix_write: the offsets of rows 0..2 only */

/*
 * Store the offsets of matrix rows 0, 1 and 2 and write them to the colour matrix with the stored flag bits.
 * Only the three offset slots of the value table are filled; the mask writes nothing else.
 *
 * Nothing in the firmware calls this routine; the three single-offset setters (pq_color_matrix_set_red /
 * green / blue_offset) each have their own copy of it.
 */
void pq_color_matrix_set_offsets(unsigned char red, unsigned char green, unsigned char blue)
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
