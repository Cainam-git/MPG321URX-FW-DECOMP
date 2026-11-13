/* sys_path_block_start_readout  (FUN_a01202c0)
 *
 * Program the read-out register of a signal path block and start it.
 * Name basis: descriptive - register 0x50 fields and bit 0 of 0x51; unused
 *
 * Matching notes
 * --------------
 * FUN_a01202c0 (leon2m 0xa01202c0-0xa012043c, 380 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: static put/set helpers (the form of the register-area helper at sys_path_block_set_reg1a) inlined; the loops
 * and the block test are written with `<= 1` as in that helper.
 */
#define PATH_ACCESS_REG (*(volatile unsigned int *)0xcf011428)  /* bits 0..1 are set before every path block register access */
/* Register `i` of the register area: address 0xCF000000 + 4 * i. */
#define REGI(i) (*(volatile unsigned int *)(0xcf000000 | ((i) << 2)))
extern const unsigned short sys_path_block_bases[];     /* register base of each of the two path blocks */

#define PATH_BLOCK_BOTH 2       /* block argument that stands for both path blocks; above 2 nothing is written */
#define PATH_REG_READOUT_SETUP 0x50
#define PATH_REG_READOUT_START 0x51     /* bit 0 */

/* Write one byte to register `reg` of path block `block` (or of both). */
static void write_byte(unsigned int block, unsigned int reg, unsigned char value)
{
    unsigned char i;
    PATH_ACCESS_REG |= 3;
    if (block == PATH_BLOCK_BOTH) {
        for (i = 0; i <= 1; i++)
            REGI(sys_path_block_bases[i] + reg) = value;
    } else if (block <= 1)
        REGI(sys_path_block_bases[block] + reg) = value;
}

/* Set the bits of `mask` in register `reg` of path block `block` (or of both). */
static void set_bits(unsigned int block, unsigned int reg, unsigned char mask)
{
    unsigned char i;
    PATH_ACCESS_REG |= 3;
    if (block == PATH_BLOCK_BOTH) {
        for (i = 0; i <= 1; i++)
            REGI(sys_path_block_bases[i] + reg) = (unsigned char)(REGI(sys_path_block_bases[i] + reg) | mask);
    } else if (block <= 1)
        REGI(sys_path_block_bases[block] + reg) = (unsigned char)(REGI(sys_path_block_bases[block] + reg) | mask);
}

/*
 * Write the read-out set-up byte of path block `block` (0 or 1, or PATH_BLOCK_BOTH for both) and set bit 0 of
 * the next register.
 *
 * Register 0x50 gets (high_field << 6) | low_field | (mid_field << 3). Bits 6..7 of that register are what
 * sys_path_block_fetch_readout reads back to get the number of words, 4 << field. Then bit 0 of register 0x51
 * is set; sys_path_block_fetch_readout returns without data while that bit is set. Nothing calls this routine.
 */
void sys_path_block_start_readout(unsigned int block, unsigned int low_field, unsigned int high_field, unsigned int mid_field)
{
    write_byte(block, PATH_REG_READOUT_SETUP, (high_field << 6) | low_field | (mid_field << 3));
    set_bits(block, PATH_REG_READOUT_START, 1);
}
