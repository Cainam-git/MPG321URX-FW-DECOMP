/* pq_color_matrix_set_bit0  (FUN_a00f6c88)
 *
 * Set bit 0 of the colour matrix control register 0xCF00E984.
 * Note: In pq_color_matrix_write bit 6 of this register is the on bit and bit 0 picks an offset row; no
 *   routine calls it.
 * Name basis: descriptive - one OR of register 0xCF00E984 with 1; what bit 0 alone controls is not shown
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6c88 @ 0xa00f6c88-0xa00f6ca4 (28 bytes, leaf), flags -mcpu=v8 -O2 -g (section default).
 */

#define COLOR_MATRIX_REG (*(volatile unsigned int *)0xcf00e984)   /* COLOR_MATRIX_CTRL */
#define COLOR_MATRIX_CTRL_BIT0 1u

/*
 * Set bit 0 of the colour matrix control register 0xCF00E984 (read, modify, write); the counterpart of
 * pq_color_matrix_clear_bit0. In pq_color_matrix_write and pq_color_matrix_read bit 6 of this register is the on
 * bit and bit 0 is part of the row selector, so the code does not show what bit 0 alone controls.
 * Nothing in the firmware refers to this routine: no call, branch, constant or address word.
 */
void pq_color_matrix_set_bit0(void)
{
    COLOR_MATRIX_REG |= COLOR_MATRIX_CTRL_BIT0;
}
