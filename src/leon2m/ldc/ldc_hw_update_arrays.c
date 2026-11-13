/* ldc_hw_update_arrays  (FUN_a00fa6b4)
 *
 * Store the level field of 0xD0040014; when its top bits changed, refill the arrays and write one out.
 * Note: The refill happens only when bits 30..31 of the register differ from the last call and ldc_mode is 1,
 *   2 or 3.
 * Name basis: descriptive - register 0xD0040014 bits 16..25 and 30..31; array registers 0xD00400A0 /
 *   0xD00400A4; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fa6b4 @ 0xa00fa6b4, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the bit updates go through the inlined field-set helper fset; the
 * second loop reads ldc_array_first through a pointer local assigned right before it (it then shares the first
 * loop's base register); statement order: ldc_level_field_applied before ldc_cleared_on_array_refill, array stores
 * ldc_array_third, ldc_array_first, ldc_array_second, and the ldc_last_array_word store before the last register
 * write.
 */

#define R(a) (*(volatile unsigned int *)(a))

/* Registers of the grid block (0xD0040000 on) used here. */
#define LDC_REG_LEVEL       0xd0040014  /* bits 16..25 level field, bits 30..31 its top bits */
#define LDC_REG_ARRAY_INDEX 0xd00400a0  /* bits 0..8 entry, bit 9 set while writing, bit 24 */
#define LDC_REG_ARRAY_DATA  0xd00400a4  /* value of the entry given in LDC_REG_ARRAY_INDEX */

/* The three arrays hold one entry per cell: 12 rows of 24 cells. */
#define LDC_ARRAY_SIZE  0x120
#define CELL_ROWS       12
#define CELL_COLUMNS    24

/* Return x with bits lo..hi replaced by v. */
static unsigned int fset(unsigned int x, unsigned int hi, unsigned int lo, unsigned int v)
{
    unsigned int m = (1 << hi) | ((1 << hi) - (1 << lo));

    return (x & ~m) | ((v << lo) & m);
}

extern unsigned short ldc_level_field;
extern unsigned short ldc_level_field_applied;
extern unsigned char ldc_level_top_bits;
extern unsigned char ldc_level_changed_flag;
extern unsigned char ldc_mode;
extern unsigned short ldc_cleared_on_array_refill;
extern unsigned short ldc_array_second[LDC_ARRAY_SIZE];
extern unsigned short ldc_array_third[LDC_ARRAY_SIZE];
extern unsigned short ldc_array_first[LDC_ARRAY_SIZE];
extern unsigned int ldc_last_array_word;

/*
 * Take the level field from the grid block and, in modes 1..3, rewrite the cell arrays when it has changed.
 *
 *  1. Read LDC_REG_LEVEL: bits 16..25 are stored in ldc_level_field; its top bits 30..31 are compared with the
 *     ones seen last time (ldc_level_top_bits). When they differ the new value is kept and
 *     ldc_level_changed_flag is set, otherwise the flag is cleared.
 *  2. Only when the flag is set and ldc_mode is 1, 2 or 3: ldc_level_field is copied to ldc_level_field_applied,
 *     ldc_cleared_on_array_refill is cleared, all three cell arrays are filled with the level field and ldc_array_first is written
 *     into the grid block entry by entry through LDC_REG_ARRAY_DATA / LDC_REG_ARRAY_INDEX (entry value into the
 *     data register, then the index with bit 9 set and bit 24 clear), closed by data 0 and the last index word
 *     with bit 9 cleared (also kept in ldc_last_array_word).
 *
 * No parameters, no result. The routine stands before ldc_hw_run_mode3_pass, which expands it inline.
 */
void ldc_hw_update_arrays(void)
{
    unsigned int level_reg = R(LDC_REG_LEVEL);
    unsigned char top_bits;
    unsigned char seen_top_bits;
    unsigned int i;
    unsigned char row, col;
    unsigned short index;
    unsigned int word;
    unsigned short *array;

    ldc_level_field = (level_reg << 6) >> 22;
    top_bits = level_reg >> 30;
    seen_top_bits = ldc_level_top_bits;
    if (top_bits != seen_top_bits) {
        ldc_level_top_bits = top_bits;
        ldc_level_changed_flag = 1;
    } else {
        ldc_level_changed_flag = 0;
    }
    if ((unsigned char)(ldc_mode - 1) <= 2 && ldc_level_changed_flag != 0) {
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
