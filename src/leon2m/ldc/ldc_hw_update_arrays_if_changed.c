/* ldc_hw_update_arrays_if_changed  (FUN_a00fa5b4)
 *
 * Refill three arrays and write them out when the change flag is set.
 * Name basis: descriptive - flag at 0xA802B7FE; registers 0xD00400A0 / 0xD00400A4; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fa5b4 @ 0xa00fa5b4, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the field-set helper fset is inlined; the second loop reads
 * ldc_array_first through a pointer local assigned right before it; statement order as written (level field
 * copy, ldc_cleared_on_array_refill, array stores third / first / second, the last-word store before the last register write).
 * The same block is the second half of ldc_hw_update_arrays.
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
extern unsigned char ldc_level_changed_flag;
extern unsigned short ldc_cleared_on_array_refill;
extern unsigned short ldc_array_second[LDC_ARRAY_SIZE];
extern unsigned short ldc_array_third[LDC_ARRAY_SIZE];
extern unsigned short ldc_array_first[LDC_ARRAY_SIZE];
extern unsigned int ldc_last_array_word;

/*
 * When ldc_level_changed_flag is set: fill all three cell arrays with the level field and write ldc_array_first
 * into the grid block, entry by entry through LDC_REG_ARRAY_DATA / LDC_REG_ARRAY_INDEX. Does nothing when the
 * flag is clear. The flag is set by the level latch (see ldc_hw_update_arrays) when the top bits of
 * LDC_REG_LEVEL changed.
 *
 * Order: copy the level field to ldc_level_field_applied and clear ldc_cleared_on_array_refill; fill the three arrays; write the 12 x 24
 * entries of ldc_array_first (entry value into the data register, then the index with bit 9 set and bit 24 clear
 * into the index register); close the write with data 0 and the last index word with bit 9 cleared, which is
 * also kept in ldc_last_array_word. The routine has no parameters and no result.
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
