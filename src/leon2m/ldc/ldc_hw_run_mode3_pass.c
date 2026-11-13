/* ldc_hw_run_mode3_pass  (FUN_a00fa814)
 *
 * Run one pass of mode 3: write the arrays and tables, read the cells, compute 3 x 3 sums.
 * Name basis: derived - registers 0xD00400A0..0xD00400B4; its entry is registered as the handler of interrupt
 *   source 0xC by ldc_hw_enable_with_irq, ldc_hw_start and ldc_hw_setup_for_panel_size
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fa814 @ 0xa00fa814-0xa00fb434 (776 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * ldc_hw_latch_level_field, ldc_hw_update_arrays_if_changed and ldc_hw_update_arrays stand before it in this
 * file so that ldc_hw_update_arrays is expanded inline at the start, as in the firmware.
 * Source form: register fields through the inlined helper fset (as in ldc_hw_access_register).
 *  - ldc_grid_table_select is read into the local table_select before the two table loops, and the two masked
 *    fields of LDC_REG_C4 (shift_low, shift_high) are taken before the cell loops: with the byte or the masking
 *    inside the loops the loop optimizer places the hoisted values in another order (0xa00fac08, 0xa00fadd4).
 *  - The first array write stores to LDC_REG_ARRAY_INDEX with a chained assignment ('R(...) = word = fset(...)';
 *    word is read again after the loop); the last array write has its own counters (row, col).
 *  - The last array write and its pointer assignment stand in a block that is left by break: at 0xa00fb268 the
 *    address of ldc_array_third comes before the two constants of the loop, an order the scheduler gives only with
 *    a loop boundary in front of the pointer assignment (do { } while (0) emits none); the firmware has no jump
 *    there. The same construct is in nvram_load_user_settings.
 *  - word doubles as the counter of the array refill loop in the set-up phase.
 */
#define R(a) (*(volatile unsigned int *)(a))

/* Registers of the grid block (0xD0040000 on) used here. */
#define LDC_REG_CTRL        0xd0040000  /* bit 31 enable, bit 30 cleared in the mode 3 set-up */
#define LDC_REG_LEVEL       0xd0040014  /* bits 16..25 level field, bits 30..31 its top bits */
#define LDC_REG_WEIGHTS_A   0xd0040090  /* byte 0 blend weight of ldc_cell_values; bytes 1..3 filter weights */
#define LDC_REG_WEIGHTS_B   0xd0040094  /* byte 0 blend weight of ldc_cell_smoothed_values */
#define LDC_REG_98          0xd0040098  /* bits 12..15 grid table selector */
#define LDC_REG_ARRAY_INDEX 0xd00400a0  /* bits 0..8 entry, bit 9 set while writing, bit 24 */
#define LDC_REG_ARRAY_DATA  0xd00400a4  /* value of the entry given in LDC_REG_ARRAY_INDEX */
#define LDC_REG_TABLE_INDEX 0xd00400b0  /* bits 0..8 entry, bit 9 set while writing, bit 24 */
#define LDC_REG_TABLE_DATA  0xd00400b4  /* value of the entry given in LDC_REG_TABLE_INDEX */
#define LDC_REG_BC          0xd00400bc
#define LDC_REG_READ_CTRL   0xd00400c0  /* bit 0 set while the cells are read */
#define LDC_REG_C4          0xd00400c4  /* bits 4..7 / 8..11: shift counts of the two cell fields */
#define LDC_REG_CELL_SEL_A  0xd00400c8  /* bits 16.. position to read */
#define LDC_REG_CELL_DATA_A 0xd00400cc  /* bits 0..9 low field, bits 10..23 high field */
#define LDC_REG_CELL_SEL_B  0xd00402c8  /* the same pair for the right half of each row */
#define LDC_REG_CELL_DATA_B 0xd00402cc
#define LDC_REG_MODE        0xd00400d8  /* bits 0..3 mode (written by ldc_hw_set_mode, ldc_hw_set_timing) */
#define LDC_REG_F0          0xd00400f0
#define LDC_REG_F4          0xd00400f4  /* low halfword: level / 4 and last largest cell value / 4 */
#define LDC_REG_RESULT      0xd00400fc  /* the two sums, change flag and pass count of a mode 3 pass */
/* LDC_REG_ARRAY_INDEX / LDC_REG_TABLE_INDEX: an entry is written by putting its value in the data register
 * and then its index, with bit 9 set and bit 24 clear, in the index register; after the last entry the data
 * register gets 0 and the index register the last word with bit 9 cleared. */

/* The three arrays hold one entry per cell: 12 rows of 24 cells. */
#define LDC_ARRAY_SIZE  0x120
#define CELL_ROWS       12
#define CELL_COLUMNS    24
#define CELL_MAX        0x3ff           /* largest cell value: 10 bits */

/* The two running-value arrays have a border of one entry around the 12 x 24 cells: 14 rows of 26. */
#define BORDERED_COLUMNS 26

/* Return x with bits lo..hi replaced by v. */
static unsigned int fset(unsigned int x, unsigned int hi, unsigned int lo, unsigned int v)
{
    unsigned int m = (1 << hi) | ((1 << hi) - (1 << lo));

    return (x & ~m) | ((v << lo) & m);
}

extern unsigned int ldc_mode3_pass_count;
extern unsigned short ldc_level_field;
extern unsigned short ldc_level_field_applied;
extern unsigned char ldc_mode3_busy_flag;
extern unsigned char ldc_level_top_bits;
extern unsigned char ldc_level_changed_flag;
extern unsigned char ldc_mode;
extern unsigned char ldc_mode3_setup_state;
extern unsigned short ldc_cleared_on_array_refill;
extern unsigned short ldc_array_second[LDC_ARRAY_SIZE];
extern unsigned short ldc_array_third[LDC_ARRAY_SIZE];
extern unsigned short ldc_array_first[LDC_ARRAY_SIZE];
extern unsigned short ldc_mode3_array[LDC_ARRAY_SIZE];
extern unsigned int ldc_last_array_word;
extern unsigned char ldc_grid_table_select;
extern unsigned short ldc_mode3_max_value;
extern unsigned short ldc_mode3_sum_first;
extern unsigned short ldc_mode3_sum_second;
extern unsigned short ldc_grid_table_5[16][17];
extern unsigned short ldc_grid_table_4[16][17];
extern unsigned short ldc_grid_table_3[16][17];
extern unsigned short ldc_grid_table_2[16][17];
extern unsigned short ldc_grid_table_1[16][17];
extern unsigned short ldc_grid_table_0[16][17];
extern unsigned short ldc_cell_reads_first[CELL_ROWS * CELL_COLUMNS];
extern unsigned short ldc_cell_reads_second[CELL_ROWS * CELL_COLUMNS];
extern unsigned short ldc_cell_values[14 * BORDERED_COLUMNS];
extern unsigned short ldc_cell_smoothed_values[14 * BORDERED_COLUMNS];
extern unsigned short ldc_cell_top_value;

/*
 * Copy the 10-bit level field (bits 16..25 of LDC_REG_LEVEL) to ldc_level_field and set
 * ldc_level_changed_flag when the register's top two bits differ from the ones seen last time, else clear it.
 */
void ldc_hw_latch_level_field(void)
{
    unsigned int level_reg = R(LDC_REG_LEVEL);
    unsigned char top_bits;

    ldc_level_field = (level_reg << 6) >> 22;
    top_bits = level_reg >> 30;
    if (top_bits != ldc_level_top_bits) {
        ldc_level_top_bits = top_bits;
        ldc_level_changed_flag = 1;
    } else
        ldc_level_changed_flag = 0;
}

/*
 * When ldc_level_changed_flag is set: fill all three cell arrays with the level field and write
 * ldc_array_first into the grid block, entry by entry through LDC_REG_ARRAY_DATA / LDC_REG_ARRAY_INDEX.
 */
void ldc_hw_update_arrays_if_changed(void)
{
    unsigned int i;
    unsigned char row, col;
    unsigned short index;
    unsigned int word;
    unsigned short *array;

    if (ldc_level_changed_flag != 0) {
        ldc_level_field_applied = ldc_level_field;
        ldc_cleared_on_array_refill = 0;
        for (i = 0; i < LDC_ARRAY_SIZE; i++) {
            ldc_array_third[i] = ldc_level_field;
            ldc_array_first[i] = ldc_level_field;
            ldc_array_second[i] = ldc_level_field;
        }
        array = ldc_array_first;
        for (row = 0; row < CELL_ROWS; row++) {
            for (col = 0; col < CELL_COLUMNS; col++) {
                index = row * CELL_COLUMNS + col;
                R(LDC_REG_ARRAY_DATA) = array[index];
                word = fset(index, 9, 9, 1);
                word = fset(word, 24, 24, 0);
                R(LDC_REG_ARRAY_INDEX) = word;
            }
        }
        /* Close the write: data 0, bit 9 cleared. */
        R(LDC_REG_ARRAY_DATA) = 0;
        word = fset(word, 9, 9, 0);
        ldc_last_array_word = word;
        R(LDC_REG_ARRAY_INDEX) = word;
    }
}

/* Latch the level field; in modes 1..3 refill and write the arrays when its top bits changed. */
void ldc_hw_update_arrays(void)
{
    ldc_hw_latch_level_field();
    if ((unsigned char)(ldc_mode - 1) <= 2)
        ldc_hw_update_arrays_if_changed();
}

/*
 * One pass of the grid block's interrupt.
 *
 * Its entry address (ldc_hw_mode3_pass_entry) is registered as the handler of interrupt source 0xC, bit 0x100,
 * by ldc_hw_enable_with_irq and by ldc_hw_setup_for_panel_size. No routine calls it directly.
 *
 * Phases:
 *   1. Mark the pass busy, count it, latch the level field (ldc_hw_update_arrays, expanded here).
 *   2. Read the block's mode (bits 0..3 of LDC_REG_MODE). A new mode is stored in ldc_mode and restarts the
 *      mode 3 set-up. Modes 1 and 2 end the pass here; mode 4 keeps ldc_mode3_setup_state; every mode other
 *      than 1..4 clears it. Only mode 3 goes on:
 *   3. Set-up, once after each mode change: fixed register fields, the three arrays filled with the level
 *      field, ldc_array_first written into the block.
 *   4. Grid table: when bits 12..15 of LDC_REG_98 changed, the selected 16 x 17 table is written into the block
 *      through LDC_REG_TABLE_DATA / LDC_REG_TABLE_INDEX, column by column.
 *   5. Only when the level field's top bits did not change in phase 1:
 *      a. read the 12 x 24 cells from the two read register pairs, each giving a low and a high field;
 *      b. blend them into the two running-value arrays;
 *      c. a 3 x 3 weighted sum over ldc_cell_values, divided by the weights that fall inside the grid,
 *         gives the new ldc_array_third and ldc_mode3_array;
 *      d. write ldc_array_third into the block and the pass results to LDC_REG_RESULT.
 *   6. Mark the set-up done (ldc_mode3_setup_state = 1) and clear the busy flag.
 */
void ldc_hw_run_mode3_pass(void)
{
    unsigned char mode, cell_col, table_col, table_row, cell_row, table_select;
    unsigned int selector;
    unsigned short *array;
    unsigned short index;
    unsigned int word;

    /* 1. Busy, count, latch the level field. */
    ldc_mode3_busy_flag = 1;
    ldc_mode3_pass_count++;
    ldc_hw_update_arrays();

    /* 2. Mode of the block. */
    mode = R(LDC_REG_MODE) & 0xf;
    if (ldc_mode != mode) {
        ldc_mode = mode;
        ldc_mode3_setup_state = 0;
    }
    mode = ldc_mode;
    if ((unsigned char)(mode - 1) > 1) {        /* modes 1 and 2: nothing to do */
        if (mode == 3) {
            /* 3. Set-up after a mode change. */
            if (ldc_mode3_setup_state == 0) {
                R(LDC_REG_CTRL) &= ~0x40000000;
                R(LDC_REG_WEIGHTS_A) = (R(LDC_REG_WEIGHTS_A) & ~0xff) | 0x80;  /* blend weight 0x80 */
                R(LDC_REG_WEIGHTS_B) = (R(LDC_REG_WEIGHTS_B) & ~0xff) | 0xe0;  /* blend weight 0xE0 */
                R(LDC_REG_98) = (R(LDC_REG_98) & ~0xf000) | 0x3000;            /* grid table 3 */
                R(LDC_REG_C4) &= ~0xf0;                                         /* low field shift 0 */
                R(LDC_REG_BC) &= 0x7fffccff;
                R(LDC_REG_MODE) |= 0x1000000;
                R(LDC_REG_F0) = (R(LDC_REG_F0) & ~0xffff) | 0xf0f0;
                ldc_level_field_applied = ldc_level_field;
                ldc_cleared_on_array_refill = 0;
                for (word = 0; word < LDC_ARRAY_SIZE; word++) {
                    ldc_array_third[word] = ldc_level_field;
                    ldc_array_second[word] = ldc_level_field;
                    ldc_array_first[word] = ldc_level_field;
                }
                array = ldc_array_first;
                for (cell_row = 0; cell_row < CELL_ROWS; cell_row++) {
                    for (cell_col = 0; cell_col < CELL_COLUMNS; cell_col++) {
                        index = cell_row * CELL_COLUMNS + cell_col;
                        R(LDC_REG_ARRAY_DATA) = array[index];
                        word = fset(index, 9, 9, 1);
                        R(LDC_REG_ARRAY_INDEX) = word = fset(word, 24, 24, 0);
                    }
                }
                R(LDC_REG_ARRAY_DATA) = 0;
                word = fset(word, 9, 9, 0);
                ldc_last_array_word = word;
                R(LDC_REG_ARRAY_INDEX) = word;
            }

            /* 4. Load the selected grid table when the selector changed. Entry index = table row + column * 16;
             * selector values above 5 load table 0. */
            selector = (R(LDC_REG_98) >> 12) & 0xf;
            if (ldc_grid_table_select != selector) {
                ldc_grid_table_select = selector;
                word = R(LDC_REG_TABLE_INDEX);
                word = fset(word, 9, 9, 1);
                word = fset(word, 24, 24, 0);
                table_select = ldc_grid_table_select;
                for (table_col = 0; table_col <= 16; table_col++) {
                    for (table_row = 0; table_row <= 15; table_row++) {
                        index = table_row + table_col * 16;
                        if (table_select == 0)
                            R(LDC_REG_TABLE_DATA) = ldc_grid_table_0[table_row][table_col];
                        else if (table_select == 1)
                            R(LDC_REG_TABLE_DATA) = ldc_grid_table_1[table_row][table_col];
                        else if (table_select == 2)
                            R(LDC_REG_TABLE_DATA) = ldc_grid_table_2[table_row][table_col];
                        else if (table_select == 3)
                            R(LDC_REG_TABLE_DATA) = ldc_grid_table_3[table_row][table_col];
                        else if (table_select == 4)
                            R(LDC_REG_TABLE_DATA) = ldc_grid_table_4[table_row][table_col];
                        else if (table_select == 5)
                            R(LDC_REG_TABLE_DATA) = ldc_grid_table_5[table_row][table_col];
                        else
                            R(LDC_REG_TABLE_DATA) = ldc_grid_table_0[table_row][table_col];
                        word = fset(word, 8, 0, index);
                        R(LDC_REG_TABLE_INDEX) = word;
                    }
                }
                R(LDC_REG_TABLE_DATA) = 0;
                word = fset(word, 9, 9, 0);
                word = fset(word, 24, 24, 0);
                R(LDC_REG_TABLE_INDEX) = word;
            }

            /* 5. Read, blend and filter the cells, unless the level field's top bits just changed. */
            if (ldc_level_changed_flag == 0) {
                unsigned int pass_count_start;
                unsigned char blend_weight_a;
                unsigned char centre_weight, side_weight, corner_weight, blend_weight_b, ring_pos;
                unsigned short top_value;
                unsigned char i, j;
                unsigned short level;
                unsigned int weights_a, weights_b, reg_c4;
                unsigned int max_low, sum_low, sum_high;
                unsigned int read_index, cell, position, data_a, data_b;
                unsigned int low_a, high_a, low_b, high_b, divisor, sum;
                unsigned int column_sums[4];
                unsigned char new_weight_a, new_weight_b;
                unsigned int divisors[3];
                unsigned char row, col;
                unsigned int shift_low, shift_high;

                pass_count_start = ldc_mode3_pass_count;
                level = ldc_level_field;
                ldc_level_field_applied = level;
                max_low = 0;
                sum_low = 0;
                sum_high = 0;
                ring_pos = 0;
                top_value = 0;
                R(LDC_REG_F4) = (R(LDC_REG_F4) & 0xffff0000) | (level >> 2) | ((ldc_mode3_max_value >> 2) << 8);
                /* The weights of the blend and of the 3 x 3 sum. */
                weights_a = R(LDC_REG_WEIGHTS_A);
                centre_weight = (weights_a & 0xff00) >> 8;      /* byte 1 */
                side_weight = weights_a >> 16;                  /* byte 2: left, right, above, below */
                blend_weight_a = weights_a;                     /* byte 0 */
                corner_weight = weights_a >> 24;                /* byte 3: the four diagonal neighbours */
                weights_b = R(LDC_REG_WEIGHTS_B);
                blend_weight_b = weights_b;
                reg_c4 = R(LDC_REG_C4);
                shift_low = reg_c4 & 0xf0;
                shift_high = reg_c4 & 0xf00;

                /* 5a. Read the cells: each read register pair gives 12 x 12 positions, register A the left 12
                 * and register B the right 12 cells of each row. Each field is shifted left by its count from
                 * LDC_REG_C4 and limited to CELL_MAX. Low fields go to ldc_cell_reads_second, high fields to
                 * ldc_cell_reads_first; the low fields give the largest value and sum_low. */
                R(LDC_REG_READ_CTRL) |= 1;
                for (i = 0; i < CELL_ROWS; i++) {
                    for (j = 0; j < 12; j++) {
                        position = (j + i * 12) << 16;
                        R(LDC_REG_CELL_SEL_A) = position;
                        data_a = R(LDC_REG_CELL_DATA_A);
                        low_a = (data_a & 0x3ff) << (shift_low >> 4);
                        read_index = j + i * CELL_COLUMNS;
                        if (low_a > CELL_MAX)
                            low_a = CELL_MAX;
                        high_a = ((data_a >> 10) & 0x3fff) << (shift_high >> 8);
                        if (high_a > CELL_MAX)
                            high_a = CELL_MAX;
                        if (max_low < low_a)
                            max_low = low_a;
                        R(LDC_REG_CELL_SEL_B) = position;
                        data_b = R(LDC_REG_CELL_DATA_B);
                        low_b = (data_b & 0x3ff) << (shift_low >> 4);
                        sum_high += high_a;
                        sum_low += low_a;
                        ldc_cell_reads_second[read_index] = low_a;
                        ldc_cell_reads_first[read_index] = high_a;
                        read_index += 12;
                        if (low_b > CELL_MAX)
                            low_b = CELL_MAX;
                        high_b = ((data_b >> 10) & 0x3fff) << (shift_high >> 8);
                        if (high_b > CELL_MAX)
                            high_b = CELL_MAX;
                        if (max_low < low_b)
                            max_low = low_b;
                        sum_high += high_b;
                        ldc_cell_reads_first[read_index] = high_b;
                        ldc_cell_reads_second[read_index] = low_b;
                        sum_low += low_b;
                    }
                }
                new_weight_a = -blend_weight_a;
                new_weight_b = -blend_weight_b;
                ldc_mode3_max_value = max_low;
                sum_low = sum_low / 12 * 24;
                ldc_mode3_sum_first = sum_low;
                sum_high = sum_high / 12 * 24;
                R(LDC_REG_READ_CTRL) &= ~1;
                ldc_mode3_sum_second = sum_high;

                /* 5b. Running values: old * weight + new * (0x100 - weight), rounded, weight from byte 0 of
                 * LDC_REG_WEIGHTS_A (low fields into ldc_cell_values) and LDC_REG_WEIGHTS_B (high fields into
                 * ldc_cell_smoothed_values). Only the inner 12 x 24 entries are written. */
                for (i = 0; i < CELL_ROWS; i++) {
                    for (j = 0; j < CELL_COLUMNS; j++) {
                        read_index = j + i * CELL_COLUMNS;
                        cell = j + i * BORDERED_COLUMNS + BORDERED_COLUMNS + 1;
                        ldc_cell_values[cell] = (blend_weight_a * ldc_cell_values[cell] + new_weight_a * ldc_cell_reads_second[read_index] + 0x80) >> 8;
                        ldc_cell_smoothed_values[cell] = (blend_weight_b * ldc_cell_smoothed_values[cell] + new_weight_b * ldc_cell_reads_first[read_index] + 0x80) >> 8;
                    }
                }

                /* 5c. 3 x 3 weighted sum over ldc_cell_values. The sum takes all eight neighbours, border
                 * entries included; the divisor counts only the neighbours inside the 12 x 24 grid:
                 * corner cell 2 sides + 1 diagonal, edge cell 3 + 2, inner cell 4 + 4; plus the centre weight,
                 * and 1 when all weights are 0. column_sums is a ring of four: the above + below sums of the
                 * left, middle and right column, so each step adds only the new right column. */
                divisors[0] = side_weight * 2 + corner_weight;
                divisors[1] = side_weight * 3 + corner_weight * 2;
                divisors[2] = (side_weight + corner_weight) * 4;
                for (i = 1; i <= CELL_ROWS; i++) {
                    for (j = 1; j <= CELL_COLUMNS; j++) {
                        position = j + i * CELL_COLUMNS - (CELL_COLUMNS + 1);  /* cell index without border */
                        cell = j + i * BORDERED_COLUMNS;
                        if (j == 1) {
                            column_sums[0] = ldc_cell_values[cell - 27] + ldc_cell_values[cell + 25];
                            ring_pos = 0;
                            column_sums[1] = ldc_cell_values[cell - 26] + ldc_cell_values[cell + 26];
                            column_sums[2] = ldc_cell_values[cell - 25] + ldc_cell_values[cell + 27];
                            sum = (ldc_cell_values[cell - 1] + ldc_cell_values[cell + 1] + column_sums[1]) * side_weight
                                + (column_sums[0] + column_sums[2]) * corner_weight;
                        } else {
                            ring_pos++;
                            column_sums[(ring_pos + 2) & 3] = ldc_cell_values[cell - 25] + ldc_cell_values[cell + 27];
                            sum = (ldc_cell_values[cell - 1] + ldc_cell_values[cell + 1] + column_sums[(ring_pos + 1) & 3]) * side_weight
                                + (column_sums[ring_pos & 3] + column_sums[(ring_pos + 2) & 3]) * corner_weight;
                        }
                        sum += ldc_cell_values[cell] * centre_weight;
                        if ((i == 1 || i == 12) && (j == 1 || j == 24))
                            divisor = divisors[0];
                        else if (i != 1 && i != 12 && j != 1 && j != 24)
                            divisor = divisors[2];
                        else
                            divisor = divisors[1];
                        divisor += centre_weight;
                        if (divisor == 0)
                            divisor = 1;
                        sum /= divisor;
                        ldc_array_third[position] = ldc_mode3_array[position] = sum = sum > CELL_MAX ? CELL_MAX : sum;
                        if ((unsigned short)sum > top_value)
                            top_value = sum;
                    }
                }
                ldc_cell_top_value = top_value;

                /* 5d. Write ldc_array_third into the block. */
                while (1) {
                    array = ldc_array_third;
                    for (row = 0; row < CELL_ROWS; row++) {
                        for (col = 0; col < CELL_COLUMNS; col++) {
                            index = row * CELL_COLUMNS + col;
                            R(LDC_REG_ARRAY_DATA) = array[index];
                            word = fset(index, 9, 9, 1);
                            word = fset(word, 24, 24, 0);
                            R(LDC_REG_ARRAY_INDEX) = word;
                        }
                    }
                    break;
                }
                R(LDC_REG_ARRAY_DATA) = 0;
                word = fset(word, 9, 9, 0);
                ldc_last_array_word = word;
                R(LDC_REG_ARRAY_INDEX) = word;
                /* Result word: the first sum, ORed with the second sum shifted left by 12, the change flag
                 * shifted by 24 and, shifted by 28, 15 less the number of passes that started while this phase
                 * ran (8-bit counter difference). */
                pass_count_start = (unsigned char)(ldc_mode3_pass_count - pass_count_start);
                R(LDC_REG_RESULT) = ldc_mode3_sum_first | (ldc_mode3_sum_second << 12) | (ldc_level_changed_flag << 24)
                    | ((0xf - pass_count_start) << 28);
            }
            /* 6. Set-up done. */
            ldc_mode3_setup_state = 1;
        } else if (mode != 4)
            ldc_mode3_setup_state = 0;
    }
    ldc_mode3_busy_flag = 0;
}
