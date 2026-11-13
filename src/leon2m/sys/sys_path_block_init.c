/* sys_path_block_init  (FUN_a011eadc)
 *
 * Load the start values of both signal path blocks from the ROM tables.
 * Name basis: descriptive - registers 0x12..0x1D, 0x38..0x3F and 0x48..0x4F from three tables, then 16 fixed
 *   registers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011eadc, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the write helper is a static function of the same form as the one in sys_path_block_set_reg48_bit5 (inlined); it sets
 *    bits 0..1 of 0xcf011428 before every write;
 *  - every write is made with block selector 2 (both blocks);
 *  - the 16 fixed registers are written one by one in the order of the listing, including the zero values.
 */
#define R(a) (*(volatile unsigned int *)(a))
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern const unsigned short sys_path_block_bases[2];

extern const unsigned char sys_path_block_start_regs12[12];
extern const unsigned char sys_path_block_start_regs38[8];
extern const unsigned char sys_path_block_start_regs48[8];

#define PATH_BLOCK_BOTH      2          /* block selector: 2 = write to both blocks */
#define PATH_BLOCK_WRITE_CTRL 0xcf011428        /* bits 0..1 are set before every register write */

/* Write one register `reg` of path block `blk` (0 or 1), or of both when blk is PATH_BLOCK_BOTH. */
static void path_block_write_reg(unsigned int blk, unsigned char reg, unsigned char val)
{
    unsigned char i;

    R(PATH_BLOCK_WRITE_CTRL) |= 3;
    if (blk == PATH_BLOCK_BOTH) {
        for (i = 0; i < 2; i++)
            RB(sys_path_block_bases[i] + reg) = val;
    } else if (blk < 2) {
        RB(sys_path_block_bases[blk] + reg) = val;
    }
}

/*
 * Load the start values of both signal path blocks. Registers 0x12..0x1d come from a 12-byte ROM table,
 * 0x38..0x3f from one 8-byte table and 0x48..0x4f from another; then 16 registers get fixed values.
 * Called from startup_init_path_blocks.
 */
void sys_path_block_init(void)
{
    unsigned char i;

    for (i = 0; i < 12; i++)
        path_block_write_reg(PATH_BLOCK_BOTH, 0x12 + i, sys_path_block_start_regs12[i]);
    for (i = 0; i < 8; i++)
        path_block_write_reg(PATH_BLOCK_BOTH, 0x38 + i, sys_path_block_start_regs38[i]);
    for (i = 0; i < 8; i++)
        path_block_write_reg(PATH_BLOCK_BOTH, 0x48 + i, sys_path_block_start_regs48[i]);
    path_block_write_reg(PATH_BLOCK_BOTH, 0x0, 0x40);
    path_block_write_reg(PATH_BLOCK_BOTH, 0x1, 0x80);
    path_block_write_reg(PATH_BLOCK_BOTH, 0xc, 0xcc);
    path_block_write_reg(PATH_BLOCK_BOTH, 0xd, 0x0);
    path_block_write_reg(PATH_BLOCK_BOTH, 0xe, 0x0);
    path_block_write_reg(PATH_BLOCK_BOTH, 0xf, 0x0);
    path_block_write_reg(PATH_BLOCK_BOTH, 0x20, 0x0);
    path_block_write_reg(PATH_BLOCK_BOTH, 0x21, 0x0);
    path_block_write_reg(PATH_BLOCK_BOTH, 0x22, 0xc4);
    path_block_write_reg(PATH_BLOCK_BOTH, 0x23, 0x7);
    path_block_write_reg(PATH_BLOCK_BOTH, 0x2c, 0x23);
    path_block_write_reg(PATH_BLOCK_BOTH, 0x2d, 0x44);
    path_block_write_reg(PATH_BLOCK_BOTH, 0x55, 0x10);
    path_block_write_reg(PATH_BLOCK_BOTH, 0x56, 0x0);
    path_block_write_reg(PATH_BLOCK_BOTH, 0x58, 0x4);
    path_block_write_reg(PATH_BLOCK_BOTH, 0x59, 0x0);
}
