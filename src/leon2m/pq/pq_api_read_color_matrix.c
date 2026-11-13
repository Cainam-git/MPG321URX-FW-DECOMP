/* pq_api_read_color_matrix  (FUN_a01476d0)
 *
 * Read the three rows of the colour matrix back from the hardware.
 * Name basis: derived - tail call to the read of 0xCF00E98C..0xCF00E9A4; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01476d0 @ 0xa01476d0-0xa01476e4 (5 words), flags -mcpu=v8 -O2 -g (section default).
 * The call is a tail call; the last word is the nop the compiler places behind it.
 */

/* The values of the colour matrix as pq_color_matrix_read returns them. */
union color_matrix_values {
    unsigned short h[12];               /* three rows of four halfwords: three coefficients and the offset */
    unsigned int w[6];
};
extern void pq_color_matrix_read(unsigned char, union color_matrix_values *);

/*
 * Read the three rows of the colour matrix into 'values' (pq_color_matrix_read).
 *
 *   enable  non-zero sets, 0 clears bit 6 of the colour matrix control register 0xCF00E984 (the bit that
 *           pq_color_matrix_write sets for its enable argument) before the rows are read; the register is
 *           restored afterwards
 *   values  receives the twelve halfwords
 *
 * Nothing in the firmware calls this routine.
 */
void pq_api_read_color_matrix(unsigned char enable, union color_matrix_values *values)
{
    pq_color_matrix_read(enable, values);
}
