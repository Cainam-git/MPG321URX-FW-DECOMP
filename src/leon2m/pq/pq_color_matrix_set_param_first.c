/* pq_color_matrix_set_param_first  (FUN_a013b6c4)
 *
 * Store the first (signed) matrix parameter and rebuild the colour matrix.
 * Name basis: descriptive - signed byte at 0xA802A461; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013b6c4 @ 0xa013b6c4-0xa013b6e4 (8 words), flags -mcpu=v8 -O2 -g (section default).
 * The call is a tail call; the last word is the nop the compiler places behind it.
 */
extern unsigned char pq_color_matrix_scale;
extern signed char pq_color_matrix_param_first;
extern void pq_color_matrix_rebuild(unsigned char);

/*
 * Store the first colour matrix parameter and rebuild the matrix with the stored scale. In the rebuild this
 * parameter scales row 0 of the matrix and, by its magnitude, rows 1 and 2.
 * Nothing in the firmware calls this routine. pq_color_matrix_set_param_second and _third are its twins.
 */
void pq_color_matrix_set_param_first(signed char value)
{
    pq_color_matrix_param_first = value;
    pq_color_matrix_rebuild(pq_color_matrix_scale);
}
