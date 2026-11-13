/* sys_path_block_enable  (FUN_a011f1c8)
 *
 * Switch a signal path block on or off.
 * Name basis: descriptive - bit 0 of the block's first register, then a bit of the mapped input block
 *
 * Matching notes
 * --------------
 * FUN_a011f1c8, flags -mcpu=v8 -O3 -g.
 * Exact form: the on != 0 arm first; the bit helper is static and inlined at -O3. The off arm tests for
 * "!= 5" first and calls input_capture_update_bits twice, once per outcome.
 */
#define R(a) (*(volatile unsigned int *)(a))
/* Register `a` of the register area: address 0xCF000000 + 4 * a. */
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern const unsigned short sys_path_block_bases[2];     /* register base of each of the two path blocks */

#define PATH_BLOCK_BOTH    2            /* block argument that stands for both path blocks; above 2 nothing is written */
#define PATH_ACCESS_REG    0xcf011428   /* bits 0..1 are set before every path block register access */
#define ANALOG_REG_114     0xcf020114   /* bits 0..2 equal to ANALOG_MODE_5 */
#define ANALOG_MODE_5      5
#define PATH_REG_CONTROL   0            /* register 0 of a path block: bit 0 is the enable bit */
#define CAPTURE_REG_3      3            /* register 3 of the input capture block: bit 7 follows the enable */
#define CAPTURE_BIT_7      0x80

extern void input_capture_update_bits(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);

/* Set (set != 0) or clear the bits of `mask` in register `reg` of path block `block` (or of both). */
static void update_bits(unsigned int block, unsigned char reg, unsigned char mask, unsigned char set)
{
    unsigned char i;

    R(PATH_ACCESS_REG) |= 3;
    if (block == PATH_BLOCK_BOTH) {
        for (i = 0; i < 2; i++) {
            if (set)
                RB(sys_path_block_bases[i] + reg) = (unsigned char)(RB(sys_path_block_bases[i] + reg) | mask);
            else
                RB(sys_path_block_bases[i] + reg) = (unsigned char)(RB(sys_path_block_bases[i] + reg) & ~mask);
        }
    } else if (block < 2) {
        if (set)
            RB(sys_path_block_bases[block] + reg) = (unsigned char)(RB(sys_path_block_bases[block] + reg) | mask);
        else
            RB(sys_path_block_bases[block] + reg) = (unsigned char)(RB(sys_path_block_bases[block] + reg) & ~mask);
    }
}

/*
 * Switch a signal path block on or off.
 *
 * block          path block 0 or 1, or PATH_BLOCK_BOTH for both
 * capture_block  input capture block whose register 3 bit 7 is updated along with it
 * on             non-zero: on, 0: off
 *
 * On: sets bit 0 of path block register 0 and sets bit 7 of capture register 3.
 * Off: clears bit 0 of path block register 0; bit 7 of capture register 3 is then set when bits 0..2 of
 * 0xCF020114 equal ANALOG_MODE_5, and cleared otherwise.
 * Called by sys_set_channel_path_mode.
 */
void sys_path_block_enable(unsigned int block, unsigned char capture_block, unsigned char on)
{
    if (on) {
        update_bits(block, PATH_REG_CONTROL, 1, 1);
        input_capture_update_bits(capture_block, CAPTURE_REG_3, CAPTURE_BIT_7, 1);
    } else {
        update_bits(block, PATH_REG_CONTROL, 1, 0);
        if ((R(ANALOG_REG_114) & 7) != ANALOG_MODE_5)
            input_capture_update_bits(capture_block, CAPTURE_REG_3, CAPTURE_BIT_7, 0);
        else
            input_capture_update_bits(capture_block, CAPTURE_REG_3, CAPTURE_BIT_7, 1);
    }
}
