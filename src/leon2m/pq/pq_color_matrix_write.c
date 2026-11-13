/* pq_color_matrix_write  (FUN_a00f6fe4)
 *
 * Write the rows of the colour matrix to the hardware.
 * Name basis: proven - three rows of three coefficients plus three offsets to 0xCF00E98C..0xCF00E9A4, selected
 *   by mask bits; waits for a frame
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6fe4 @ 0xa00f6fe4, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the parameter table and the default are the union of 12 halfwords and 6 words (the same
 *    union as the getter pq_color_matrix_read);
 *  - the default is a const local with a complete initialiser (GCC clears it with three stores
 *    of zero, then stores the non-zero halfwords);
 *  - the low byte of a coefficient is read as h & 0xff (ldub).
 */

/* REG(addr) reads or writes a memory-mapped register. */
#define REG(a) (*(volatile unsigned int *)(a))

#define COLOR_MATRIX_CTRL        0xcf00e984  /* on / mode bits, row select bits 0..2, bit 3 */
#define COLOR_MATRIX_COEFF_ADDR  0xcf00e98c  /* six registers 4 apart: low, high byte of each coefficient of the row */
#define COLOR_MATRIX_OFFSET_ADDR 0xcf00e9a4  /* the offset of the selected row */

#define COLOR_MATRIX_ON    0x40              /* bit 6: matrix on when set */
#define COLOR_MATRIX_MODE  0x80              /* bit 7: mode switch */
#define COLOR_MATRIX_CTRL_BIT3 0x8           /* bit 3: cleared by every row selection, set at the end */

/* Row selector in the control register: bits 1..2 are the row number. A coefficient row keeps bit 0 as it is;
   an offset row sets it (1, 3, 5). Both selections keep bits 4..7, clear bit 3 and clear everything above
   bit 7. */
#define ROW_SELECT_COEFF_0   0
#define ROW_SELECT_COEFF_1   2
#define ROW_SELECT_COEFF_2   4
#define ROW_SELECT_OFFSET_0  1
#define ROW_SELECT_OFFSET_1  3
#define ROW_SELECT_OFFSET_2  5
#define ROW_SELECT_KEEP_COEFF  0xf1          /* coefficient selection keeps bit 0 and bits 4..7 */
#define ROW_SELECT_KEEP_OFFSET 0xf0          /* offset selection keeps bits 4..7 */

/* Bits of the mask argument: bits 0..2 = coefficients of rows 0..2, bits 4..6 = offsets of rows 0..2. */
#define ROW_0     1
#define ROW_1     2
#define ROW_2     4
#define ROW_OFFSET_0 0x10
#define ROW_OFFSET_1 0x20
#define ROW_OFFSET_2 0x40

/* The table of the three rows: each row is three coefficients (R, G, B) and one offset. */
union color_matrix_values {
    unsigned short h[12];   /* three rows of four halfwords */
    unsigned int w[6];      /* the same words, as the getter returns them */
};

extern void panel_wait_sync_pulse(void);

/*
 * Write the rows of the colour matrix to the hardware.
 *
 *   enable      0/1: the matrix on bit is cleared or set
 *   mode        0/1: the mode bit is cleared or set
 *   values      three rows of {R, G, B, offset}; when 0, a built-in default is written in
 *               which each row has 0x100 on its own diagonal position and 0x80 as its offset
 *   which_rows  which rows to write: bits 0..2 the coefficient rows, bits 0x10..0x40 the offsets
 *
 * For each selected part the row selector in the control register is pointed at that row and the
 * values are written: a coefficient row as the low and high bytes of its three halfwords, an offset
 * as one register write of its halfword. Then panel_wait_sync_pulse waits for one sync pulse and
 * bit 3 of the control register is set.
 *
 * Callers: pq_ace_init, pq_fga_load_color_matrix_row, pq_color_matrix_rebuild,
 * pq_color_matrix_set_offsets, pq_color_matrix_set_red / green / blue_offset, pq_color_matrix_set_values,
 * pq_set_color_matrix_preset.
 */
void pq_color_matrix_write(unsigned char enable, int mode, const union color_matrix_values *values, unsigned int which_rows)
{
    const union color_matrix_values def = { {0x100, 0, 0, 0x80, 0, 0x100, 0, 0x80, 0, 0, 0x100, 0x80} };

    if (values == 0)
        values = &def;
    if (enable)
        REG(COLOR_MATRIX_CTRL) |= COLOR_MATRIX_ON;
    else
        REG(COLOR_MATRIX_CTRL) &= ~COLOR_MATRIX_ON;
    if (mode == 1)
        REG(COLOR_MATRIX_CTRL) |= COLOR_MATRIX_MODE;
    else if (mode == 0)
        REG(COLOR_MATRIX_CTRL) &= ~COLOR_MATRIX_MODE;
    if (which_rows & ROW_0) {
        /* Coefficient row 0: bits 1..3 cleared, bit 0 kept; then the three coefficients, low byte first. */
        REG(COLOR_MATRIX_CTRL) &= ROW_SELECT_KEEP_COEFF;
        REG(COLOR_MATRIX_COEFF_ADDR) = values->h[0] & 0xff;
        REG(COLOR_MATRIX_COEFF_ADDR + 0x4) = values->h[0] >> 8;
        REG(COLOR_MATRIX_COEFF_ADDR + 0x8) = values->h[1] & 0xff;
        REG(COLOR_MATRIX_COEFF_ADDR + 0xc) = values->h[1] >> 8;
        REG(COLOR_MATRIX_COEFF_ADDR + 0x10) = values->h[2] & 0xff;
        REG(COLOR_MATRIX_COEFF_ADDR + 0x14) = values->h[2] >> 8;
    }
    if (which_rows & ROW_1) {
        REG(COLOR_MATRIX_CTRL) = (REG(COLOR_MATRIX_CTRL) & ROW_SELECT_KEEP_COEFF) | ROW_SELECT_COEFF_1;
        REG(COLOR_MATRIX_COEFF_ADDR) = values->h[4] & 0xff;
        REG(COLOR_MATRIX_COEFF_ADDR + 0x4) = values->h[4] >> 8;
        REG(COLOR_MATRIX_COEFF_ADDR + 0x8) = values->h[5] & 0xff;
        REG(COLOR_MATRIX_COEFF_ADDR + 0xc) = values->h[5] >> 8;
        REG(COLOR_MATRIX_COEFF_ADDR + 0x10) = values->h[6] & 0xff;
        REG(COLOR_MATRIX_COEFF_ADDR + 0x14) = values->h[6] >> 8;
    }
    if (which_rows & ROW_2) {
        REG(COLOR_MATRIX_CTRL) = (REG(COLOR_MATRIX_CTRL) & ROW_SELECT_KEEP_COEFF) | ROW_SELECT_COEFF_2;
        REG(COLOR_MATRIX_COEFF_ADDR) = values->h[8] & 0xff;
        REG(COLOR_MATRIX_COEFF_ADDR + 0x4) = values->h[8] >> 8;
        REG(COLOR_MATRIX_COEFF_ADDR + 0x8) = values->h[9] & 0xff;
        REG(COLOR_MATRIX_COEFF_ADDR + 0xc) = values->h[9] >> 8;
        REG(COLOR_MATRIX_COEFF_ADDR + 0x10) = values->h[10] & 0xff;
        REG(COLOR_MATRIX_COEFF_ADDR + 0x14) = values->h[10] >> 8;
    }
    if (which_rows & ROW_OFFSET_0) {
        /* Offset of row 0: selector 1, then the offset halfword. */
        REG(COLOR_MATRIX_CTRL) = (REG(COLOR_MATRIX_CTRL) & ROW_SELECT_KEEP_OFFSET) | ROW_SELECT_OFFSET_0;
        REG(COLOR_MATRIX_OFFSET_ADDR) = values->h[3];
    }
    if (which_rows & ROW_OFFSET_1) {
        REG(COLOR_MATRIX_CTRL) = (REG(COLOR_MATRIX_CTRL) & ROW_SELECT_KEEP_OFFSET) | ROW_SELECT_OFFSET_1;
        REG(COLOR_MATRIX_OFFSET_ADDR) = values->h[7];
    }
    if (which_rows & ROW_OFFSET_2) {
        REG(COLOR_MATRIX_CTRL) = (REG(COLOR_MATRIX_CTRL) & ROW_SELECT_KEEP_OFFSET) | ROW_SELECT_OFFSET_2;
        REG(COLOR_MATRIX_OFFSET_ADDR) = values->h[11];
    }
    panel_wait_sync_pulse();
    REG(COLOR_MATRIX_CTRL) |= COLOR_MATRIX_CTRL_BIT3;
}
