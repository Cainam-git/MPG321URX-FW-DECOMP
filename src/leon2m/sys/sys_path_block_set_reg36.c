/* sys_path_block_set_reg36  (FUN_a011fbd8)
 *
 * Write a 12-bit value with flag 0x4000 to registers 0x36/0x37 of a signal path block.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * FUN_a011fbd8, flags -mcpu=v8 -O3 -g.
 * Source form: the write is a static 16-bit helper (same shape as the byte helper of
 * sys_path_block_set_reg48_bit5), inlined by GCC at -O3.
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
 * Write (low 12 bits of value) | 0x4000 to registers 0x36 (low byte) and 0x37 (high byte) of path block `block`
 * (0 or 1, or PATH_BLOCK_BOTH for both).
 * Called by sys_set_channel_path_mode (with the register 0x36 value of the selected row).
 */
void sys_path_block_set_reg36(unsigned int block, unsigned int value)
{
    write_halfword(block, 0x36, (value & 0xfff) | 0x4000);
}
