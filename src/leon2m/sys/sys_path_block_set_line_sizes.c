/* sys_path_block_set_line_sizes  (FUN_a01200f8)
 *
 * Write two 16-bit sizes to registers 0x42..0x45 of a signal path block.
 * Name basis: descriptive - used by the low-resolution line size set-up
 *
 * Matching notes
 * --------------
 * FUN_a01200f8, flags -mcpu=v8 -O3 -g.
 * Source form: the 16-bit write helper of sys_path_block_set_reg36 / sys_path_block_set_width, inlined at -O3;
 * both values are unsigned short parameters (an unsigned int second value moves the high-byte shift of the
 * second write).
 */
#define R(a) (*(volatile unsigned int *)(a))
/* Register `a` of the register area: address 0xCF000000 + 4 * a. */
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern const unsigned short sys_path_block_bases[2];     /* register base of each of the two path blocks */

#define PATH_BLOCK_BOTH    2            /* block argument that stands for both path blocks; above 2 nothing is written */
#define PATH_ACCESS_REG    0xcf011428   /* bits 0..1 are set before every path block register access */

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
 * Write two 16-bit sizes to path block `block` (0 or 1, or PATH_BLOCK_BOTH for both).
 *
 * Registers 0x42 / 0x43 get the low / high byte of `first_size`; registers 0x44 / 0x45 get the low / high
 * byte of `second_size`. sys_setup_low_resolution_path passes its padding as the first and its line count
 * (halved in one case) as the second.
 */
void sys_path_block_set_line_sizes(unsigned int block, unsigned short first_size, unsigned short second_size)
{
    write_halfword(block, 0x42, first_size);
    write_halfword(block, 0x44, second_size);
}
