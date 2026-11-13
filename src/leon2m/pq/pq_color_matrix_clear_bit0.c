/* pq_color_matrix_clear_bit0  (FUN_a00f6c6c)
 *
 * Clear bit 0 of the colour matrix control register 0xCF00E984.
 * Note: In pq_color_matrix_write bit 6 of this register is the on bit and bit 0 picks an offset row; called by
 *   pq_fga_handle_command with the stage switch-offs.
 * Name basis: descriptive - one AND of register 0xCF00E984 with ~1; what bit 0 alone controls is not shown
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6c6c @ 0xa00f6c6c-0xa00f6c88 (28 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: single read-modify-write of a memory-mapped register.
 */
#define COLOR_MATRIX_REG (*(volatile unsigned int *)0xcf00e984)   /* COLOR_MATRIX_CTRL */
#define COLOR_MATRIX_CTRL_BIT0 1u

/*
 * Clear bit 0 of the colour matrix control register 0xCF00E984.
 * In pq_color_matrix_write bit 6 of this register is the on bit and bit 0 is part of the row selector, so
 * the code does not show what bit 0 alone controls.
 * Caller: pq_fga_handle_command (one calibration command received over DDC/CI).
 */
void pq_color_matrix_clear_bit0(void)
{
    COLOR_MATRIX_REG &= ~COLOR_MATRIX_CTRL_BIT0;
}
