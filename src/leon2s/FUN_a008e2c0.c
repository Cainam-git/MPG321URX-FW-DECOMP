/* FUN_a008e2c0 (leon2s 0xa008e2c0-0xa008e3c0, 256 bytes), flags -mcpu=v8 -Os -g.
 * (port, mode, p3, three unused words). mode &= 0xff; v = 1 for mode 0, 1 and 2, p3 for mode 3, 3 for any
 * other mode; port &= 0xff after the switch. Through FUN_a00a7fd8 (read) / FUN_a00a8054 (write) of page 1:
 * reg 0x0a = (rd & 0x3f) | (v & 0xff) << 6; reg 0x0a = (rd & ~3) | v; reg 0x99 = (rd & 0x3f) | (v & 0xff) << 6;
 * reg 0x99 = (rd & ~0x30) | (v & 0xff) << 4 (sibling call). void.
 * Same source form as FUN_a008e0f0 (int mode, six parameters, read results kept as full words). The three
 * case bodies with v = 1 are written separately: grouped labels let GCC fold the switch into a range test.
 * vb = v & 0xff is one variable shared by both shifts.
 */
extern unsigned int FUN_a00a7fd8(unsigned char, unsigned char, unsigned short);
extern void FUN_a00a8054(unsigned char, unsigned char, unsigned short, unsigned char);

void FUN_a008e2c0(unsigned int port, int mode, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6)
{
    unsigned int v;
    unsigned int hi;
    unsigned int vb;

    mode &= 0xff;
    switch (mode) {
    case 0:
        v = 1;
        break;
    case 1:
        v = 1;
        break;
    case 2:
        v = 1;
        break;
    case 3:
        v = p3;
        break;
    default:
        v = 3;
        break;
    }
    port &= 0xff;
    vb = v & 0xff;
    hi = vb << 6;
    FUN_a00a8054(port, 1, 10, (FUN_a00a7fd8(port, 1, 10) & 0x3f) | hi);
    FUN_a00a8054(port, 1, 10, (FUN_a00a7fd8(port, 1, 10) & ~3) | v);
    FUN_a00a8054(port, 1, 0x99, (FUN_a00a7fd8(port, 1, 0x99) & 0x3f) | hi);
    FUN_a00a8054(port, 1, 0x99, (FUN_a00a7fd8(port, 1, 0x99) & ~0x30) | (vb << 4));
}
