/* leon2s FUN_a008e0f0 @ 0xa008e0f0-0xa008e200 (68 words), flags -mcpu=v8 -Os -g.
 * Code facts: (port, mode, p3, +3 unused words). mode &= 0xff; v = 0 / 4 / p3 / 0xf for mode 0 / 1 / 3 /
 * other (a switch: the fw case tree compares signed, so mode is an int); port &= 0xff after the switch.
 * Through FUN_a00a7fd8 (read) / FUN_a00a8054 (write) of page 1: reg 8 = (rd & 0xf) | (v & 0xff) << 4;
 * reg 0x98 = (rd & ~0xf) | v; reg 0x98 = (rd & 0xf) | (v & 0xff) << 4; then r = rd(0x99) & ~0xf and the
 * sibcall write of reg 0x99 = mode == 2 ? (r | 8) & 0xf8 : r | v. void.
 * Fixes vs the autoc draft (76.47, did not compile): int params kept in their registers (mode / port masked
 * in place: fw 'and %i1,0xff,%i1'), 6 params (v lands in the free %i3), a7fd8 returns a full word here
 * (the fw keeps 'and -16'; a u8 prototype folds it to 0xf0), and the last write duplicated into both arms
 * (crossjumped; this keeps the u8 conversion 'and 0xff' in the else arm only). Aids: none.
 */
extern unsigned int FUN_a00a7fd8(unsigned char, unsigned char, unsigned short);
extern void FUN_a00a8054(unsigned char, unsigned char, unsigned short, unsigned char);

void FUN_a008e0f0(unsigned int port, int mode, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6)
{
    unsigned int v;
    unsigned int hi;
    unsigned int r;

    mode &= 0xff;
    v = 0;
    switch (mode) {
    case 0:
        break;
    case 1:
        v = 4;
        break;
    case 3:
        v = p3;
        break;
    default:
        v = 0xf;
        break;
    }
    port &= 0xff;
    hi = (v & 0xff) << 4;
    FUN_a00a8054(port, 1, 8, (FUN_a00a7fd8(port, 1, 8) & 0xf) | hi);
    FUN_a00a8054(port, 1, 0x98, (FUN_a00a7fd8(port, 1, 0x98) & ~0xf) | v);
    FUN_a00a8054(port, 1, 0x98, (FUN_a00a7fd8(port, 1, 0x98) & 0xf) | hi);
    r = FUN_a00a7fd8(port, 1, 0x99) & ~0xf;
    if (mode == 2)
        FUN_a00a8054(port, 1, 0x99, (r | 8) & 0xf8);
    else
        FUN_a00a8054(port, 1, 0x99, r | v);
}
