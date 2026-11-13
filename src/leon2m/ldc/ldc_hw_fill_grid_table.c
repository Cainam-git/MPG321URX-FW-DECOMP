/* ldc_hw_fill_grid_table  (FUN_a00f9f10)
 *
 * Fill the 16 x 17 table for the current mode from 20 values.
 * Name basis: descriptive - tables at 0xA8026ED6 / 0xA8026CB6; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f9f10 @ 0xa00f9f10-0xa00fa560 (1616 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: the two branches are written out separately; as one static helper taking the table pointer the
 * build differs. The means of phase 5 are computed in unsigned arithmetic ((unsigned int) cast, srl not sra).
 */

/* Size of each grid table: 16 rows of 17 halfwords. */
#define GRID_ROWS    16
#define GRID_COLUMNS 17

/* Fixed value of columns 0 and 16 of every row. */
#define GRID_EDGE_VALUE 0x400

/* Register 0xD0040098 of the grid block; bits 12..15 select the grid table that ldc_hw_run_mode3_pass loads
 * into the block (ldc_grid_table_select). */
#define LDC_REG_98 (*(volatile unsigned int *)0xd0040098)

extern unsigned short ldc_work_table[][8];      /* rows of 8 halfwords; rows 1..4 are read here */
extern unsigned short ldc_grid_table_4[GRID_ROWS][GRID_COLUMNS];
extern unsigned short ldc_grid_table_3[GRID_ROWS][GRID_COLUMNS];

/*
 * Build the whole grid table that bits 12..15 of register 0xD0040098 select, from 20 given points.
 *
 * Only selector values 3 and 4 have a table here (ldc_grid_table_3 / ldc_grid_table_4); for any other value
 * nothing is written. Returns 1 in every case. No caller of this routine is known.
 *
 * Phases, for the selected table t:
 *   1. Points: entries 0..4 of rows 1, 2, 3 and 4 of ldc_work_table go to columns 2, 5, 8, 11 and 14 of table
 *      rows 0, 5, 10 and 15.
 *   2. Right edge: column 16 of every row = GRID_EDGE_VALUE.
 *   3. Down the point columns (2, 5, 8, 11, 14; the loop also visits 16, which is already 0x400 from step 2):
 *      rows r+1..r+4 between point rows r and r+5 are mixed from the two, the weight of row r stepping down in
 *      fifths (0xCC, 0x99, 0x66, 0x33 of 0x100), rounded to nearest.
 *   4. Across every row: the two columns between point columns c and c+3 are mixed the same way with the
 *      weights 0xAA and 0x55 (thirds).
 *   5. Edges: column 15 = rounded mean of columns 14 and 16; column 0 = GRID_EDGE_VALUE; column 1 = rounded
 *      mean of columns 0 and 2.
 * ldc_hw_copy_table_rows reads columns 2, 5, 8, 11, 14 of rows 0, 5, 10, 15 of the same two tables back, but
 * into rows 12..15 of ldc_work_table, not rows 1..4.
 */
int ldc_hw_fill_grid_table(void)
{
    unsigned int table_select = (unsigned short)LDC_REG_98 >> 12;
    unsigned char i, row, col;

    if (table_select == 3) {
        /* 1. The 20 points. */
        ldc_grid_table_3[0][2] = ldc_work_table[1][0];
        ldc_grid_table_3[0][5] = ldc_work_table[1][1];
        ldc_grid_table_3[0][8] = ldc_work_table[1][2];
        ldc_grid_table_3[0][11] = ldc_work_table[1][3];
        ldc_grid_table_3[0][14] = ldc_work_table[1][4];
        ldc_grid_table_3[5][2] = ldc_work_table[2][0];
        ldc_grid_table_3[5][5] = ldc_work_table[2][1];
        ldc_grid_table_3[5][8] = ldc_work_table[2][2];
        ldc_grid_table_3[5][11] = ldc_work_table[2][3];
        ldc_grid_table_3[5][14] = ldc_work_table[2][4];
        ldc_grid_table_3[10][2] = ldc_work_table[3][0];
        ldc_grid_table_3[10][5] = ldc_work_table[3][1];
        ldc_grid_table_3[10][8] = ldc_work_table[3][2];
        ldc_grid_table_3[10][11] = ldc_work_table[3][3];
        ldc_grid_table_3[10][14] = ldc_work_table[3][4];
        ldc_grid_table_3[15][2] = ldc_work_table[4][0];
        ldc_grid_table_3[15][5] = ldc_work_table[4][1];
        ldc_grid_table_3[15][8] = ldc_work_table[4][2];
        ldc_grid_table_3[15][11] = ldc_work_table[4][3];
        ldc_grid_table_3[15][14] = ldc_work_table[4][4];
        /* 2. Right edge. */
        for (i = 0; i < GRID_ROWS; i++)
            ldc_grid_table_3[i][16] = GRID_EDGE_VALUE;
        /* 3. Fill the four rows between two point rows; each pair of weights adds up to 0x100. */
        for (col = 2; col < GRID_COLUMNS; col += 3) {
            for (row = 0; row < 15; row += 5) {
                unsigned int upper = ldc_grid_table_3[row][col];
                unsigned int lower = ldc_grid_table_3[row + 5][col];
                ldc_grid_table_3[row + 1][col] = (upper * 0xcc + lower * 0x34 + 0x80) >> 8;
                ldc_grid_table_3[row + 2][col] = (upper * 0x99 + lower * 0x67 + 0x80) >> 8;
                ldc_grid_table_3[row + 3][col] = (upper * 0x66 + lower * 0x9a + 0x80) >> 8;
                ldc_grid_table_3[row + 4][col] = (upper * 0x33 + lower * 0xcd + 0x80) >> 8;
            }
        }
        /* 4. Fill the two columns between two point columns, in every row. */
        for (row = 0; row < GRID_ROWS; row++) {
            for (col = 2; col < 14; col += 3) {
                unsigned int left = ldc_grid_table_3[row][col];
                unsigned int right = ldc_grid_table_3[row][col + 3];
                ldc_grid_table_3[row][col + 1] = (left * 0xaa + right * 0x56 + 0x80) >> 8;
                ldc_grid_table_3[row][col + 2] = (left * 0x55 + right * 0xab + 0x80) >> 8;
            }
        }
        /* 5. The columns at both edges. */
        for (i = 0; i < GRID_ROWS; i++)
            ldc_grid_table_3[i][15] = (((unsigned int)ldc_grid_table_3[i][14] + ldc_grid_table_3[i][16]) * 0x80 + 0x80) >> 8;
        for (i = 0; i < GRID_ROWS; i++)
            ldc_grid_table_3[i][0] = GRID_EDGE_VALUE;
        for (i = 0; i < GRID_ROWS; i++)
            ldc_grid_table_3[i][1] = (((unsigned int)ldc_grid_table_3[i][0] + ldc_grid_table_3[i][2]) * 0x80 + 0x80) >> 8;
    } else if (table_select == 4) {
        /* The same five phases on ldc_grid_table_4. */
        ldc_grid_table_4[0][2] = ldc_work_table[1][0];
        ldc_grid_table_4[0][5] = ldc_work_table[1][1];
        ldc_grid_table_4[0][8] = ldc_work_table[1][2];
        ldc_grid_table_4[0][11] = ldc_work_table[1][3];
        ldc_grid_table_4[0][14] = ldc_work_table[1][4];
        ldc_grid_table_4[5][2] = ldc_work_table[2][0];
        ldc_grid_table_4[5][5] = ldc_work_table[2][1];
        ldc_grid_table_4[5][8] = ldc_work_table[2][2];
        ldc_grid_table_4[5][11] = ldc_work_table[2][3];
        ldc_grid_table_4[5][14] = ldc_work_table[2][4];
        ldc_grid_table_4[10][2] = ldc_work_table[3][0];
        ldc_grid_table_4[10][5] = ldc_work_table[3][1];
        ldc_grid_table_4[10][8] = ldc_work_table[3][2];
        ldc_grid_table_4[10][11] = ldc_work_table[3][3];
        ldc_grid_table_4[10][14] = ldc_work_table[3][4];
        ldc_grid_table_4[15][2] = ldc_work_table[4][0];
        ldc_grid_table_4[15][5] = ldc_work_table[4][1];
        ldc_grid_table_4[15][8] = ldc_work_table[4][2];
        ldc_grid_table_4[15][11] = ldc_work_table[4][3];
        ldc_grid_table_4[15][14] = ldc_work_table[4][4];
        /* 2. Right edge. */
        for (i = 0; i < GRID_ROWS; i++)
            ldc_grid_table_4[i][16] = GRID_EDGE_VALUE;
        /* 3. Rows between point rows. */
        for (col = 2; col < GRID_COLUMNS; col += 3) {
            for (row = 0; row < 15; row += 5) {
                unsigned int upper = ldc_grid_table_4[row][col];
                unsigned int lower = ldc_grid_table_4[row + 5][col];
                ldc_grid_table_4[row + 1][col] = (upper * 0xcc + lower * 0x34 + 0x80) >> 8;
                ldc_grid_table_4[row + 2][col] = (upper * 0x99 + lower * 0x67 + 0x80) >> 8;
                ldc_grid_table_4[row + 3][col] = (upper * 0x66 + lower * 0x9a + 0x80) >> 8;
                ldc_grid_table_4[row + 4][col] = (upper * 0x33 + lower * 0xcd + 0x80) >> 8;
            }
        }
        /* 4. Columns between point columns. */
        for (row = 0; row < GRID_ROWS; row++) {
            for (col = 2; col < 14; col += 3) {
                unsigned int left = ldc_grid_table_4[row][col];
                unsigned int right = ldc_grid_table_4[row][col + 3];
                ldc_grid_table_4[row][col + 1] = (left * 0xaa + right * 0x56 + 0x80) >> 8;
                ldc_grid_table_4[row][col + 2] = (left * 0x55 + right * 0xab + 0x80) >> 8;
            }
        }
        /* 5. Edge columns. */
        for (i = 0; i < GRID_ROWS; i++)
            ldc_grid_table_4[i][15] = (((unsigned int)ldc_grid_table_4[i][14] + ldc_grid_table_4[i][16]) * 0x80 + 0x80) >> 8;
        for (i = 0; i < GRID_ROWS; i++)
            ldc_grid_table_4[i][0] = GRID_EDGE_VALUE;
        for (i = 0; i < GRID_ROWS; i++)
            ldc_grid_table_4[i][1] = (((unsigned int)ldc_grid_table_4[i][0] + ldc_grid_table_4[i][2]) * 0x80 + 0x80) >> 8;
    }
    return 1;
}
