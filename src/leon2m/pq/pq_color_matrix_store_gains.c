/* pq_color_matrix_store_gains  (FUN_a013b48c)
 *
 * Store the three gain values without rebuilding.
 * Name basis: derived - halfwords 0..2 of the gain record at 0xA802A46C; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013b48c @ 0xa013b48c-0xa013b4a4 (24 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: one array symbol; the compiler orders the stores 0, 2, 1.
 */
extern unsigned short pq_color_gains[];             /* gains of matrix rows 0..2 */

/*
 * Store the gains of matrix rows 0, 1 and 2; the matrix is not rebuilt (pq_color_matrix_set_gains also
 * rebuilds it). Nothing in the firmware refers to this routine (no call and no stored address).
 */
void pq_color_matrix_store_gains(unsigned short red, unsigned short green, unsigned short blue)
{
    pq_color_gains[0] = red;
    pq_color_gains[1] = green;
    pq_color_gains[2] = blue;
}
