/* pq_color_matrix_set_scale  (FUN_a013adf4)
 *
 * Store the scale that the colour matrix is built with.
 * Name basis: descriptive - byte at 0xA802A460, passed to every rebuild; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013adf4 @ 0xa013adf4-0xa013ae00 (12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: a direct store to the extern byte (the store sits in the retl delay slot).
 */
extern unsigned char pq_color_matrix_scale;

/*
 * Store the overall scale of the colour matrix (x / 128, 0x80 = 1.0, as pq_color_matrix_rebuild uses it).
 * Nothing in the firmware calls this routine; pq_color_matrix_rebuild has its own copy of it.
 */
void pq_color_matrix_set_scale(unsigned char scale)
{
    pq_color_matrix_scale = scale;
}
