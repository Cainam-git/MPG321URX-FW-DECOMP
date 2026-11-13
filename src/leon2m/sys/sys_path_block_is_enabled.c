/* sys_path_block_is_enabled  (FUN_a01207ac)
 *
 * Return whether a signal path block is switched on.
 * Returns: 0 or 1
 * Name basis: descriptive - bit 0 of the block's first register
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01207ac @ 0xa01207ac-0xa01207f4 (18 words).
 * Written as a byte read helper read_block_reg8(block, reg) inlined with reg 0: the sum base + reg is an int, so
 * the halfword base is not narrowed again before the shift.
 */
#define PATH_BLOCK_CTRL (*(volatile unsigned int *)0xcf011428)
/* Register number r of the register file (0xcf000000 + 4 * r). */
#define REG_FILE(r) (*(volatile unsigned int *)(0xcf000000 | ((r) << 2)))
extern const unsigned short sys_path_block_bases[2];

/* Read register reg of a block; a block number above 1 is taken as block 0. */
static unsigned char read_block_reg8(unsigned int block, unsigned char reg)
{
    if (block > 1)
        block = 0;
    PATH_BLOCK_CTRL |= 3;
    return REG_FILE(sys_path_block_bases[block] + reg);
}

/*
 * Return bit 0 of register 0 of signal path block 0 or 1 (the block's on/off bit).
 * Called with 0 and with 1 by input_adc_step_width_to_target.
 */
unsigned char sys_path_block_is_enabled(unsigned int block)
{
    return read_block_reg8(block, 0) & 1;
}
