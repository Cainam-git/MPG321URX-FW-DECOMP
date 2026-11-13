/* pq_color_matrix_store_offsets  (FUN_a013b4d0)
 *
 * Store the three offset values without applying them.
 * Name basis: derived - bytes 0..2 of the offset record at 0xA802A468; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013b4d0 @ 0xa013b4d0-0xa013b4e8 (24 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: one array symbol; the compiler orders the stores 0, 2, 1.
 */
extern unsigned char pq_color_offsets[];            /* offsets of matrix rows 0..2 */

/*
 * Store the offsets of matrix rows 0, 1 and 2; nothing is written to the hardware (pq_color_matrix_set_offsets
 * also writes them). Nothing in the firmware refers to this routine (no call and no stored address).
 */
void pq_color_matrix_store_offsets(unsigned char red, unsigned char green, unsigned char blue)
{
    pq_color_offsets[0] = red;
    pq_color_offsets[1] = green;
    pq_color_offsets[2] = blue;
}
