/* pq_block_write16  (FUN_a00f2488)
 *
 * Write a 16-bit register pair of one picture block, or of all eight.
 * Name basis: proven - block base addresses from the ROM table at 0x19A2EC; blocks 6 and 7 use 8-bit registers
 *   for two of the pairs
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f2488 @ 0xa00f2488, flags -mcpu=v8 -O3 -g.
 */

/* Register n of a picture block is the word at 0xCF000000 + 4 * (block base + n); only its low 8 bits are used,
   so a 16-bit value takes two registers, low byte first. */
#define BLOCK_REG(index) (*(volatile unsigned int *)(0xcf000000 | ((index) << 2)))

/* The bases in ROM, blocks 0..7: 0x2600, 0x2700, 0x2800, 0x2900, 0x2A00, 0x5D00, 0x2400, 0x2500
   (registers from 0xCF009800, 0xCF009C00, 0xCF00A000, 0xCF00A400, 0xCF00A800, 0xCF017400, 0xCF009000,
   0xCF009400). */
extern unsigned short pq_block_reg_bases[8];

#define ALL_PICTURE_BLOCKS  8           /* block number that writes all eight blocks */
#define LAST_PAIR_BLOCK     5           /* blocks 0..5 hold every value as a register pair */

/* In blocks 6 and 7 these two values are one 8-bit register at another number. */
#define PAIR_REG_A0         0xa0        /* -> single register 0x60 */
#define SINGLE_REG_60       0x60
#define PAIR_REG_BE         0xbe        /* -> single register 0x5D */
#define SINGLE_REG_5D       0x5d

/*
 * Write a 16-bit value to register reg (low byte) and reg + 1 (high byte) of one picture block.
 *   block  0..7, or ALL_PICTURE_BLOCKS for all eight (each written as a pair, blocks 6 and 7 too).
 *          Numbers above 8 are not checked and read a base past the end of the table.
 *   reg    register number of the low byte
 *   value  value to write; for registers 0xA0 and 0xBE of blocks 6 and 7 only its low byte is written
 *
 * Callers: the panel output timing and clock code (panel_output_setup_channel_timing, panel_output_apply_timing,
 * panel_calc_output_pixel_clock, panel_correct_clock_first_step / _second_step, panel_output_setup_block4),
 * the pq_block_set_* and pq_block5_* routines, input_bring_up_set_pixel_clock and input_csc_write_range_values.
 */
void pq_block_write16(unsigned char block, unsigned char reg, unsigned short value)
{
    unsigned char i; unsigned int index;
    if (block == ALL_PICTURE_BLOCKS) { for (i = 0; i <= 7; i++) { index = pq_block_reg_bases[i] + reg; BLOCK_REG(index) = (unsigned char)value; BLOCK_REG(index + 1) = value >> 8; } }
    else if (block <= LAST_PAIR_BLOCK) { index = pq_block_reg_bases[block] + reg; BLOCK_REG(index) = (unsigned char)value; BLOCK_REG(index + 1) = value >> 8; }
    else if (reg == PAIR_REG_A0) BLOCK_REG(pq_block_reg_bases[block] + SINGLE_REG_60) = (unsigned char)value;
    else if (reg == PAIR_REG_BE) BLOCK_REG(pq_block_reg_bases[block] + SINGLE_REG_5D) = (unsigned char)value;
    else { index = pq_block_reg_bases[block] + reg; BLOCK_REG(index) = (unsigned char)value; BLOCK_REG(index + 1) = value >> 8; }
}
