/* sys_path_block_set_reg1a  (FUN_a0120678)
 *
 * Write an on/off value to register 0x1A of a signal path block, or of both.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0120678 @ 0xa0120678-0xa01207ac, flags -mcpu=v8 -O3 -g.
 * Source form: a static helper write_block_reg (the register 0xcf011428 update and the write) inlined in each arm.
 */
/* Control register of the signal path blocks; bits 0..1 are set before every block register access. */
#define PATH_BLOCK_CTRL (*(volatile unsigned int *)0xcf011428)
/* Register number r of the register file (0xcf000000 + 4 * r). */
#define REG_FILE(r) (*(volatile unsigned int *)(0xcf000000 | ((r) << 2)))
#define PATH_BLOCK_BOTH 2                       /* block argument 2: both blocks */
#define PATH_BLOCK_REG_1A 0x1a                  /* register 0x1a of a block */
extern const unsigned short sys_path_block_bases[];

/* Write value to register reg of block (0 or 1), or of both blocks when block is 2. Other values write nothing. */
static void write_block_reg(unsigned int block, unsigned int reg, unsigned char value)
{
    unsigned char i;
    PATH_BLOCK_CTRL |= 3;
    if (block == PATH_BLOCK_BOTH) {
        for (i = 0; i <= 1; i++)
            REG_FILE(sys_path_block_bases[i] + reg) = value;
    } else if (block <= 1)
        REG_FILE(sys_path_block_bases[block] + reg) = value;
}

/*
 * Write 1 (on == 1) or 0 (any other value) to register 0x1a of a signal path block.
 * block: 0 or 1 for one block, 2 for both. The register addresses come from the base table
 * sys_path_block_bases. Name basis marks it unused: nothing calls it.
 */
void sys_path_block_set_reg1a(unsigned int block, unsigned char on)
{
    if (on == 1)
        write_block_reg(block, PATH_BLOCK_REG_1A, 1);
    else
        write_block_reg(block, PATH_BLOCK_REG_1A, 0);
}
