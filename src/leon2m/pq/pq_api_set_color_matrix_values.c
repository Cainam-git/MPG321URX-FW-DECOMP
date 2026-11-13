/* pq_api_set_color_matrix_values  (FUN_a01476c0)
 *
 * Program the colour matrix with a set of 12 values and the two stored option bits.
 *   values: address of the 12 halfword matrix values
 * Name basis: descriptive - tail call to pq_color_matrix_set_values with a pointer to 12 halfwords; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01476c0 @ 0xa01476c0-0xa01476d0 (4 words), flags -mcpu=v8 -O2 -g (section default).
 * The call is a tail call; the last word is the nop the compiler places behind it.
 */

/* The values of the colour matrix as pq_color_matrix_write takes them. */
union color_matrix_values {
    unsigned short h[12];               /* three rows of four halfwords: R, G, B coefficient and the offset */
    unsigned int w[6];
};
extern void pq_color_matrix_set_values(const union color_matrix_values *values);

/*
 * Write all three rows of the colour matrix (pq_color_matrix_set_values: pq_color_matrix_write with the two
 * stored flag bits of pq_color_matrix_flags and every row selected).
 *
 *   values  the matrix values; 0 writes the built-in default (0x100 on each row's own diagonal position, offset
 *           0x80)
 *
 * Nothing in the firmware calls this routine.
 */
void pq_api_set_color_matrix_values(const union color_matrix_values *values)
{
    pq_color_matrix_set_values(values);
}
