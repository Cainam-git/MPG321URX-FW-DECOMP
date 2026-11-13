/* pq_color_matrix_read  (FUN_a00f72cc)
 *
 * Read the rows of the colour matrix back from the hardware.
 * Name basis: proven - three groups of four values from 0xCF00E98C..0xCF00E9A4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f72cc @ 0xa00f72cc-0xa00f7434, flags -mcpu=v8 -O3 -g.
 * Source form: out points to a union of 12 halfwords and 6 words, so the halfword stores share an alias set with the
 * word register reads and stay between them in the firmware's order (with a plain unsigned short pointer GCC moves
 * all reads of a group before its stores). The saved value is an unsigned char local.
 */
#define R(a) (*(volatile unsigned int *)(a))

union color_matrix_data {
    unsigned short halfwords[12];
    unsigned int words[6];
};
extern void panel_wait_sync_pulse(void);

/* Colour matrix registers (names as in pq_color_matrix_write). */
#define COLOR_MATRIX_CTRL 0xcf00e984    /* bit 6 matrix on, bits 1..2 row number, bit 0 offset row */
/* DATA0..DATA5: low and high byte of the three coefficients of the selected row; DATA6: the register
   pq_color_matrix_write writes a row's offset to (with bit 0 set). */
#define COLOR_MATRIX_DATA0 0xcf00e98c
#define COLOR_MATRIX_DATA1 0xcf00e990
#define COLOR_MATRIX_DATA2 0xcf00e994
#define COLOR_MATRIX_DATA3 0xcf00e998
#define COLOR_MATRIX_DATA4 0xcf00e99c
#define COLOR_MATRIX_DATA5 0xcf00e9a0
#define COLOR_MATRIX_DATA6 0xcf00e9a4
#define COLOR_MATRIX_ON 0x40            /* bit 6: matrix on when set */
#define ROW_SELECT_KEEP_COEFF 0xf1      /* a row selection keeps bit 0 and bits 4..7, clears bits 1..3 and above 7 */
#define ROW_SELECT_COEFF_0 0            /* row number n in bits 1..2 */
#define ROW_SELECT_COEFF_1 2
#define ROW_SELECT_COEFF_2 4

/*
 * Read the three rows of the colour matrix back from the hardware.
 *
 *   enable  0 / other: COLOR_MATRIX_ON is cleared / set for the time of the read
 *   out     receives four halfwords per row: three coefficients, each built from the low and high byte
 *           registers DATA0..DATA5, and the word of DATA6 cut to 16 bits
 *
 * The low byte of COLOR_MATRIX_CTRL is saved first; then the routine waits for one sync pulse, sets the on bit
 * as asked and selects rows 0, 1 and 2 in turn with the selection pq_color_matrix_write uses for the
 * coefficients (bit 0 left as it is). At the end the saved low byte is written back, which also undoes the on
 * bit and clears bits 8..31.
 *
 * Only caller: pq_api_read_color_matrix, which nothing calls.
 */
void pq_color_matrix_read(unsigned char enable, union color_matrix_data *out)
{
    unsigned char save;

    save = R(COLOR_MATRIX_CTRL);
    panel_wait_sync_pulse();
    if (enable != 0)
        R(COLOR_MATRIX_CTRL) |= COLOR_MATRIX_ON;
    else
        R(COLOR_MATRIX_CTRL) &= ~COLOR_MATRIX_ON;
    R(COLOR_MATRIX_CTRL) = (R(COLOR_MATRIX_CTRL) & ROW_SELECT_KEEP_COEFF) | ROW_SELECT_COEFF_0;
    out->halfwords[0] = R(COLOR_MATRIX_DATA0) | (R(COLOR_MATRIX_DATA1) << 8);
    out->halfwords[1] = R(COLOR_MATRIX_DATA2) | (R(COLOR_MATRIX_DATA3) << 8);
    out->halfwords[2] = R(COLOR_MATRIX_DATA4) | (R(COLOR_MATRIX_DATA5) << 8);
    out->halfwords[3] = R(COLOR_MATRIX_DATA6);
    R(COLOR_MATRIX_CTRL) = (R(COLOR_MATRIX_CTRL) & ROW_SELECT_KEEP_COEFF) | ROW_SELECT_COEFF_1;
    out->halfwords[4] = R(COLOR_MATRIX_DATA0) | (R(COLOR_MATRIX_DATA1) << 8);
    out->halfwords[5] = R(COLOR_MATRIX_DATA2) | (R(COLOR_MATRIX_DATA3) << 8);
    out->halfwords[6] = R(COLOR_MATRIX_DATA4) | (R(COLOR_MATRIX_DATA5) << 8);
    out->halfwords[7] = R(COLOR_MATRIX_DATA6);
    R(COLOR_MATRIX_CTRL) = (R(COLOR_MATRIX_CTRL) & ROW_SELECT_KEEP_COEFF) | ROW_SELECT_COEFF_2;
    out->halfwords[8] = R(COLOR_MATRIX_DATA0) | (R(COLOR_MATRIX_DATA1) << 8);
    out->halfwords[9] = R(COLOR_MATRIX_DATA2) | (R(COLOR_MATRIX_DATA3) << 8);
    out->halfwords[10] = R(COLOR_MATRIX_DATA4) | (R(COLOR_MATRIX_DATA5) << 8);
    out->halfwords[11] = R(COLOR_MATRIX_DATA6);
    R(COLOR_MATRIX_CTRL) = save;
}
