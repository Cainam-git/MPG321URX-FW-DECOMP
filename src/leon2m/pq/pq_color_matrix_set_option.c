/* pq_color_matrix_set_option  (FUN_a013b710)
 *
 * Store the second option flag of the colour matrix and switch its hardware bit.
 * Name basis: descriptive - bit 1 of the byte at 0xA802CBBC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013b710 @ 0xa013b710, flags -mcpu=v8 -O3 -g.
 * Source form: each arm ends in its own return after the call.
 */
extern unsigned char pq_color_matrix_flags;
extern void pq_color_matrix_clear_option_bit(void);
extern void pq_color_matrix_set_option_bit(void);

#define COLOR_MATRIX_FLAG_OPTION 0x02   /* bit 1 of pq_color_matrix_flags: the mode bit for pq_color_matrix_write */

/*
 * Store the second option flag (bit 1 of pq_color_matrix_flags) and set or clear bit 7 of the colour matrix
 * option register at once.
 *
 *   on  non-zero: set; 0: clear
 *
 * Called by pq_api_set_color_matrix_option and sys_init_picture_blocks.
 */
void pq_color_matrix_set_option(unsigned char on)
{
  if (on != 0) {
    pq_color_matrix_flags = pq_color_matrix_flags | COLOR_MATRIX_FLAG_OPTION;
    pq_color_matrix_set_option_bit();
    return;
  }
  pq_color_matrix_flags = pq_color_matrix_flags & 0xfd;
  pq_color_matrix_clear_option_bit();
  return;
}
