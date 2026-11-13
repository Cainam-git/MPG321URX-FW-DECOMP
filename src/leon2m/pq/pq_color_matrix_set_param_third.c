/* pq_color_matrix_set_param_third  (FUN_a013b6a4)
 *
 * Store the third matrix parameter and rebuild the colour matrix.
 * Name basis: descriptive - byte at 0xA802CBBD; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013b6a4 @ 0xa013b6a4-0xa013b6c4 (8 words), flags -mcpu=v8 -O2 -g.
 * Source form: the rebuild is a tail call that hands on the caller's return address; the last word is the nop
 * the compiler places behind such a call sequence.
 */
extern unsigned char pq_color_matrix_scale;
extern unsigned char pq_color_matrix_param_third;
extern void pq_color_matrix_rebuild(unsigned char);

/*
 * Store the third colour matrix parameter and rebuild the matrix with the stored scale. In the rebuild it is
 * the angle (256 steps per turn) by which rows 1 and 2 are turned.
 *
 * Nothing in the firmware calls this routine and no stored address points at it.
 */
void pq_color_matrix_set_param_third(unsigned char angle)
{
    pq_color_matrix_param_third = angle;
    pq_color_matrix_rebuild(pq_color_matrix_scale);
}
