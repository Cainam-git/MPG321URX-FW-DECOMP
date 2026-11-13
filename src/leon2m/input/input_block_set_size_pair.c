/* input_block_set_size_pair  (FUN_a00f8ce4)
 *
 * Write two 16-bit sizes into registers 0x60..0x6C of a block, optionally halved and swapped.
 * Name basis: descriptive - by the path selector and a register byte
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f8ce4 @ 0xa00f8ce4, flags -mcpu=v8 -O3 -g.
 * Source form: the switch only selects the register base, and the addresses are written as base | offset.
 * Writing base + offset, or one write per case, gives sethi/%lo addressing instead of the firmware's "or".
 */
#define R(a) (*(volatile unsigned int *)(a))

extern unsigned char sys_get_path_selector(unsigned char blk);
extern unsigned char sys_get_block_5a00_byte(void);

/* Write two 16-bit sizes, each as a low and a high byte, to registers +0x60/+0x64 (size_b) and +0x68/+0x6C
 * (size_a) of the register area of the block. The areas are at 0xCF009800 + 0x400 * block for blocks 0 to 3,
 * 0xCF009000 for block 6 and 0xCF009400 for block 7; the other blocks are not written.
 * Before that size_a is halved when it is above 0x780, the path selector of the block equals the block number and
 * the byte at 0xCF015A00 is not zero. When swap is set the two sizes are exchanged. Called by
 * sys_channel_apply_output_timing. */
void input_block_set_size_pair(unsigned char block, unsigned short size_a, unsigned short size_b, unsigned char swap)
{
    unsigned short tmp;
    unsigned int base;

    if (size_a > 0x780 && sys_get_path_selector(block) == block && sys_get_block_5a00_byte())
        size_a >>= 1;
    if (swap) {
        tmp = size_a;
        size_a = size_b;
        size_b = tmp;
    }
    switch (block) {
    case 0: base = 0xcf009800; break;
    case 1: base = 0xcf009c00; break;
    case 2: base = 0xcf00a000; break;
    case 3: base = 0xcf00a400; break;
    case 6: base = 0xcf009000; break;
    case 7: base = 0xcf009400; break;
    default: return;
    }
    R(base | 0x60) = (unsigned char)size_b;
    R(base | 0x64) = (unsigned char)(size_b >> 8);
    R(base | 0x68) = (unsigned char)size_a;
    R(base | 0x6c) = (unsigned char)(size_a >> 8);
}
