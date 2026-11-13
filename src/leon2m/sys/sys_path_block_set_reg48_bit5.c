/* sys_path_block_set_reg48_bit5  (FUN_a011fcac)
 *
 * Write bit 5 of register 0x48 of a signal path block.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * FUN_a011fcac, flags -mcpu=v8 -O3 -g.
 * Source form: the read and the write helper are static and inlined by GCC at -O3.
 */
#define R(a) (*(volatile unsigned int *)(a))
/* Register `a` of the register area: address 0xCF000000 + 4 * a. */
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern const unsigned short sys_path_block_bases[2];     /* register base of each of the two path blocks */

#define PATH_BLOCK_BOTH    2            /* block argument that stands for both path blocks; above 2 nothing is written */
#define PATH_ACCESS_REG    0xcf011428   /* bits 0..1 are set before every path block register access */

/* Read one byte of register `reg` of path block `block`; a block number above 1 reads block 0. */
static unsigned char read_byte(unsigned int block, unsigned char reg)
{
    R(PATH_ACCESS_REG) |= 3;
    if (block > 1)
        block = 0;
    return RB(sys_path_block_bases[block] + reg);
}

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

/*
 * Set bit 5 of register 0x48 of path block `block` (0 or 1, or PATH_BLOCK_BOTH for both) to `bit`, keeping the
 * other bits. The old value is read from the block itself (from block 0 when `block` is PATH_BLOCK_BOTH) and the
 * result is written to the selected block or blocks.
 * Called by sys_set_channel_path_mode (with the register 0x48 bit 5 value of the selected row).
 */
void sys_path_block_set_reg48_bit5(unsigned int block, unsigned char bit)
{
    write_byte(block, 0x48, (read_byte(block, 0x48) & 0xdf) | (bit << 5));
}
