/* pq_set_color_matrix_preset  (FUN_a0150b8c)
 *
 * Select one of five 3x4 coefficient tables and program it.
 * Name basis: derived - five tables of 12 halfwords (3x4 matrix shape) passed to pq_color_matrix_write
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0150b8c @ 0xa0150b8c-0xa0150da4 (134 words), flags -mcpu=v8 -O3 -g.
 * Source form: each table is a const local union of 12 halfwords and 6 words, initialised through the halfword
 * array (GCC clears such a union first, three std of zero, and then stores the non-zero halfwords, table by
 * table); a local array of pointers to the five tables.
 */
extern void pq_color_matrix_write(unsigned char, unsigned char, const unsigned short *, int);

/* The values of the colour matrix as pq_color_matrix_write takes them. */
union color_matrix_values {
    unsigned short h[12];               /* three rows of four halfwords: three coefficients and the offset */
    unsigned int w[6];
};

#define COLOR_MATRIX_PRESETS  5
#define COLOR_MATRIX_ENABLE   1         /* sets the matrix on bit */
#define COLOR_MATRIX_MODE_KEEP 2        /* neither 0 nor 1: pq_color_matrix_write leaves the mode bit alone */
#define COLOR_MATRIX_ALL_ROWS 0xff

/*
 * Switch the colour matrix on and write one of five preset matrices to all its rows.
 *
 *   preset  0..4: that table; any other value: pq_color_matrix_write's built-in default (the same values as
 *           table 0: 0x100 on each row's own diagonal position, offset 0x80)
 *
 * pq_color_matrix_flags is not changed. The only caller, pq_api_set_window_item, does this for its item 15
 * (PQ_ITEM_COLOR_MATRIX_PRESET) with a preset 0..6 after selecting the window.
 */
void pq_set_color_matrix_preset(unsigned int preset)
{
    const union color_matrix_values m0 = { {0x100, 0, 0, 0x80, 0, 0x100, 0, 0x80, 0, 0, 0x100, 0x80} };
    const union color_matrix_values m1 = { {0x131, 0x447, 0x16, 0x80, 0x40b, 0x117, 0x40c, 0x80, 0x413, 0xe, 0x105, 0x80} };
    const union color_matrix_values m2 = { {0x162, 0x48e, 0x2c, 0x80, 0x416, 0x12e, 0x418, 0x80, 0x427, 0x1c, 0x10b, 0x80} };
    const union color_matrix_values m3 = { {0x176, 0x4ab, 0x35, 0x80, 0x41d, 0x13c, 0x41f, 0x80, 0x436, 0x15, 0x121, 0x80} };
    const union color_matrix_values m4 = { {0x18b, 0x4c9, 0x3e, 0x80, 0x424, 0x149, 0x426, 0x80, 0x445, 0xe, 0x137, 0x80} };
    const unsigned short *tables[COLOR_MATRIX_PRESETS] = {m0.h, m1.h, m2.h, m3.h, m4.h};

    if (preset <= 4)
        pq_color_matrix_write(COLOR_MATRIX_ENABLE, COLOR_MATRIX_MODE_KEEP, tables[preset], COLOR_MATRIX_ALL_ROWS);
    else
        pq_color_matrix_write(COLOR_MATRIX_ENABLE, COLOR_MATRIX_MODE_KEEP, 0, COLOR_MATRIX_ALL_ROWS);
}
