/* pq_color_matrix_set_values  (FUN_a013b658)
 *
 * Program the colour matrix with a set of 12 values and the two stored option bits.
 *   values: address of three rows of {R, G, B, offset} halfwords; null writes the built-in default
 * Name basis: descriptive - pq_color_matrix_write(flag bit 0, flag bit 1, values, 0xFF) with the bits of the
 *   byte at 0xA802CBBC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013b658 @ 0xa013b658-0xa013b684 (11 words), flags -mcpu=v8 -O2 -g.
 * Source form: one call with the stored flag bits; the compiler makes it a tail call that hands on the
 * caller's return address. The last word is the nop the compiler places behind such a call sequence.
 */

/* The values of the colour matrix as pq_color_matrix_write takes them. */
union color_matrix_values {
    unsigned short h[12];               /* three rows of four halfwords: R, G, B coefficient and the offset */
    unsigned int w[6];
};
extern unsigned char pq_color_matrix_flags;
extern void pq_color_matrix_write(unsigned char en, int mode, const union color_matrix_values *m, unsigned int mask);

#define COLOR_MATRIX_FLAG_ON  0x01      /* bit 0 of pq_color_matrix_flags: enable argument; bit 1: mode argument */
#define ALL_ROW_PARTS         0xff      /* which_rows: every coefficient row and every offset */

/*
 * Write a whole table of colour matrix values with the two stored flag bits (bit 0 enable, bit 1 mode, as
 * pq_color_matrix_set_enable_flag and pq_color_matrix_set_option store them).
 *
 *   values  three rows of {R, G, B, offset}; null writes the built-in default of pq_color_matrix_write
 *
 * The only caller is pq_api_set_color_matrix_values, which nothing in the firmware calls.
 */
void pq_color_matrix_set_values(const union color_matrix_values *values)
{
    pq_color_matrix_write(pq_color_matrix_flags & COLOR_MATRIX_FLAG_ON, (pq_color_matrix_flags >> 1) & 1, values,
                          ALL_ROW_PARTS);
}
