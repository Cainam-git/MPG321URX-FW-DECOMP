/* ldc_hw_copy_table_rows  (FUN_a00f9d78)
 *
 * Copy 20 table entries into rows 12..15 of the working table for the current mode.
 * Name basis: descriptive - mode 3 or 4 from bits 12..15 of 0xD0040098; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f9d78 @ 0xa00f9d78, flags -mcpu=v8 -O3 -g.
 * Source form: the 20 copies of each table are written out one by one, in the order of the work table.
 */


/* The grid tables have 16 rows of 17 halfwords. */
extern unsigned short ldc_work_table[][8];      /* rows of 8 halfwords; rows 12..15 are written here */
extern unsigned short ldc_grid_table_4[16][17];
extern unsigned short ldc_grid_table_3[16][17];
/* Register 0xD0040098 of the grid block; bits 12..15 select the grid table. */
#define LDC_REG_98 (*(volatile unsigned int *)0xd0040098)

/*
 * Copy 20 points of the grid table that bits 12..15 of LDC_REG_98 select into rows 12..15 of ldc_work_table.
 *
 * Only selector values 3 and 4 have a table (ldc_grid_table_3 / ldc_grid_table_4); for any other value nothing is
 * copied. Returns 1 in every case. No caller of this routine is known.
 *
 * Work table row 12 + n, entries 0..4 = table row 5 * n, columns 2, 5, 8, 11 and 14 (n = 0..3). These are the
 * table positions that ldc_hw_fill_grid_table sets from rows 1..4 of the work table.
 */
int ldc_hw_copy_table_rows(void)
{
    unsigned int table_select = (unsigned short)LDC_REG_98 >> 12;

    /* The entries are taken from the grid table of the selector value; any other value copies nothing. */
    if (table_select == 3) {
        ldc_work_table[12][0] = ldc_grid_table_3[0][2];
        ldc_work_table[12][1] = ldc_grid_table_3[0][5];
        ldc_work_table[12][2] = ldc_grid_table_3[0][8];
        ldc_work_table[12][3] = ldc_grid_table_3[0][11];
        ldc_work_table[12][4] = ldc_grid_table_3[0][14];
        ldc_work_table[13][0] = ldc_grid_table_3[5][2];
        ldc_work_table[13][1] = ldc_grid_table_3[5][5];
        ldc_work_table[13][2] = ldc_grid_table_3[5][8];
        ldc_work_table[13][3] = ldc_grid_table_3[5][11];
        ldc_work_table[13][4] = ldc_grid_table_3[5][14];
        ldc_work_table[14][0] = ldc_grid_table_3[10][2];
        ldc_work_table[14][1] = ldc_grid_table_3[10][5];
        ldc_work_table[14][2] = ldc_grid_table_3[10][8];
        ldc_work_table[14][3] = ldc_grid_table_3[10][11];
        ldc_work_table[14][4] = ldc_grid_table_3[10][14];
        ldc_work_table[15][0] = ldc_grid_table_3[15][2];
        ldc_work_table[15][1] = ldc_grid_table_3[15][5];
        ldc_work_table[15][2] = ldc_grid_table_3[15][8];
        ldc_work_table[15][3] = ldc_grid_table_3[15][11];
        ldc_work_table[15][4] = ldc_grid_table_3[15][14];
    } else if (table_select == 4) {
        ldc_work_table[12][0] = ldc_grid_table_4[0][2];
        ldc_work_table[12][1] = ldc_grid_table_4[0][5];
        ldc_work_table[12][2] = ldc_grid_table_4[0][8];
        ldc_work_table[12][3] = ldc_grid_table_4[0][11];
        ldc_work_table[12][4] = ldc_grid_table_4[0][14];
        ldc_work_table[13][0] = ldc_grid_table_4[5][2];
        ldc_work_table[13][1] = ldc_grid_table_4[5][5];
        ldc_work_table[13][2] = ldc_grid_table_4[5][8];
        ldc_work_table[13][3] = ldc_grid_table_4[5][11];
        ldc_work_table[13][4] = ldc_grid_table_4[5][14];
        ldc_work_table[14][0] = ldc_grid_table_4[10][2];
        ldc_work_table[14][1] = ldc_grid_table_4[10][5];
        ldc_work_table[14][2] = ldc_grid_table_4[10][8];
        ldc_work_table[14][3] = ldc_grid_table_4[10][11];
        ldc_work_table[14][4] = ldc_grid_table_4[10][14];
        ldc_work_table[15][0] = ldc_grid_table_4[15][2];
        ldc_work_table[15][1] = ldc_grid_table_4[15][5];
        ldc_work_table[15][2] = ldc_grid_table_4[15][8];
        ldc_work_table[15][3] = ldc_grid_table_4[15][11];
        ldc_work_table[15][4] = ldc_grid_table_4[15][14];
    }
    return 1;
}
