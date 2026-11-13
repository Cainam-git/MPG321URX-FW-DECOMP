/* sys_path_block_set_reg24  (FUN_a011fd84)
 *
 * Program register 0x24 and the 12-bit value behind it of a signal path block.
 * Name basis: descriptive - value 0x500 for both blocks at start-up
 *
 * Matching notes
 * --------------
 * FUN_a011fd84, flags -mcpu=v8 -O3 -g.
 * Source form: the byte and 16-bit write helpers are the static helpers of sys_path_block_set_reg48_bit5 and
 * sys_path_block_set_reg36, inlined at -O3.
 */
#define R(a) (*(volatile unsigned int *)(a))
/* Register `a` of the register area: address 0xCF000000 + 4 * a. */
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern const unsigned short sys_path_block_bases[2];     /* register base of each of the two path blocks */

#define PATH_BLOCK_BOTH    2            /* block argument that stands for both path blocks; above 2 nothing is written */
#define PATH_ACCESS_REG    0xcf011428   /* bits 0..1 are set before every path block register access */

/* Write one byte to register `reg` of path block `block` (or of both). */
static void write_byte(unsigned int block, unsigned char reg, unsigned char value)
{
    unsigned char i;

    R(PATH_ACCESS_REG) |= 3;
    if (block == PATH_BLOCK_BOTH) {
        for (i = 0; i < 2; i++)
            RB(sys_path_block_bases[i] + reg) = value;
    } else if (block < 2) {
        RB(sys_path_block_bases[block] + reg) = value;
    }
}

/* Write a 16-bit value to registers `reg` (low byte) and `reg` + 1 (high byte) of path block `block` (or of both). */
static void write_halfword(unsigned int block, unsigned char reg, unsigned short value)
{
    unsigned char i;

    R(PATH_ACCESS_REG) |= 3;
    if (block == PATH_BLOCK_BOTH) {
        for (i = 0; i < 2; i++) {
            RB(sys_path_block_bases[i] + reg) = (unsigned char)value;
            RB(sys_path_block_bases[i] + reg + 1) = (unsigned char)(value >> 8);
        }
    } else if (block < 2) {
        RB(sys_path_block_bases[block] + reg) = (unsigned char)value;
        RB(sys_path_block_bases[block] + reg + 1) = (unsigned char)(value >> 8);
    }
}

/*
 * Write register 0x24 and the 12-bit value in registers 0x25 / 0x26 of path block `block` (0 or 1, or
 * PATH_BLOCK_BOTH for both).
 *
 * Register 0x24 gets (first & ~1) | (second << 1) | 4: `first` with bit 0 cleared, `second` shifted up by one
 * place, and bit 2 always set (only the low byte is written).
 * Registers 0x25 and 0x26 get the low and high byte of the low 12 bits of `third`.
 * Called by startup_init_path_blocks (for each block, with 0, 0 and 0x500).
 */
void sys_path_block_set_reg24(unsigned int block, unsigned int first, unsigned int second, unsigned int third)
{
    write_byte(block, 0x24, (first & ~1) | (second << 1) | 4);
    write_halfword(block, 0x25, third & 0xfff);
}
