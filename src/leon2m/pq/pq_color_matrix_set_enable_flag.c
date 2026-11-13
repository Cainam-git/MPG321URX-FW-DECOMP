/* pq_color_matrix_set_enable_flag  (FUN_a013b6e4)
 *
 * Store the on/off flag of the colour matrix.
 * Name basis: descriptive - bit 0 of the byte at 0xA802CBBC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013b6e4 @ 0xa013b6e4-0xa013b710 (11 words), flags -mcpu=v8 -O2 -g (section default).
 * Source form: no volatile (a RAM byte: one load and one store), and an unsigned int temp for the masked byte (an
 * unsigned char '&= 0xfe' gives 'and -2' and two stores).
 */
extern unsigned char pq_color_matrix_flags;

#define COLOR_MATRIX_FLAG_ON 0x01       /* bit 0 of pq_color_matrix_flags: the enable bit for pq_color_matrix_write */

/*
 * Store the on flag (bit 0) of pq_color_matrix_flags. The hardware is not touched here; the flag is written to
 * the matrix the next time pq_color_matrix_write is called with the stored flags.
 *
 *   on  0 or 1; any other value leaves the flag unchanged
 *
 * Called by pq_api_enable_color_matrix and sys_init_picture_blocks.
 */
void pq_color_matrix_set_enable_flag(unsigned int on)
{
  unsigned int flags;

  if (on < 2) {
    flags = pq_color_matrix_flags & 0xfe;
    if (on & 1)
      flags |= COLOR_MATRIX_FLAG_ON;
    pq_color_matrix_flags = flags;
  }
}
