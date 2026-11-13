/* sys_path_block_set_width  (FUN_a011ff28)
 *
 * Write a 16-bit width to a signal path block, and a quarter of it to a second pair.
 * Name basis: descriptive - registers 0x40/0x41 and 0x53/0x54; stepped by the caller towards a target
 *
 * Matching notes
 * --------------
 * FUN_a011ff28, flags -mcpu=v8 -O3 -g.
 * Source form: the 16-bit write helper is the static helper of sys_path_block_set_reg36, inlined at -O3.
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
 * Write a 16-bit width to path block `block` (0 or 1, or PATH_BLOCK_BOTH for both).
 *
 * Registers 0x40 / 0x41 get the low / high byte of `width`; registers 0x53 / 0x54 get the low / high byte of
 * width / 4.
 * Called by input_adc_step_width_to_target and sys_setup_low_resolution_path.
 */
void sys_path_block_set_width(unsigned int block, unsigned short width)
{
    write_halfword(block, 0x40, width);
    write_halfword(block, 0x53, width >> 2);
}
