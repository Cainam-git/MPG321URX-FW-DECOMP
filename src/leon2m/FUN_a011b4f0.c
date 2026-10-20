/* FUN_a011b4f0: sends a block to the serial register port of side sel (0 or other). x points to a record
 * { u16 n; u16 addr; u8 *data; }. Bit 7 of register base + 0 of block sel of the second register family is
 * cleared first (FUN_a01191fc). Register set of side 0 / other: command 0xcf011780 / 0xcf011794, address bytes
 * 0xcf011784+0xcf011788 / 0xcf011798+0xcf01179c, strobe 0xcf00bfcc / 0xcf00c3cc (written 0), data byte
 * 0xcf01178c / 0xcf0117a0; each step is followed by a 160-nop delay loop. Sequence: command 0xd0, address
 * x->addr, then the n bytes x->data[0..n-1] through FUN_a011b3e8. Caller: FUN_a01461a8.
 * The command and address steps are static helpers and FUN_a01191fc / FUN_a011b3e8 are defined here; GCC inlines
 * all of them at -O3. x->n is read before the command step.
 * Compiler aid: the empty statement 'if (a) { }' in the address helper emits no instructions; as in FUN_a011c6c8
 * it keeps the firmware's 16-bit narrowing of the address before the register writes.
 */
#define R(a) (*(volatile unsigned int *)(a))
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];

struct Xfer { unsigned short n; unsigned short addr; unsigned char *data; };

void FUN_a01191fc(unsigned char blk, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int v = RB(DAT_a8027aa8[blk] + reg);
    if (set == 1) v |= mask; else v &= ~mask;
    RB(DAT_a8027aa8[blk] + reg) = (unsigned char)v;
}

static void cmd(unsigned char sel, unsigned char c)
{
    int i;

    if (sel == 0)
        R(0xcf011780) = c;
    else
        R(0xcf011794) = c;
    for (i = 0; i < 0xa0; i++)
        __asm__("nop");
}

static void addr16(unsigned char sel, unsigned short a)
{
    int i;

    if (a) {
    }
    if (sel == 0) {
        R(0xcf011784) = a & 0xff;
        R(0xcf011788) = a >> 8;
        R(0xcf00bfcc) = 0;
    } else {
        R(0xcf011798) = a & 0xff;
        R(0xcf01179c) = a >> 8;
        R(0xcf00c3cc) = 0;
    }
    for (i = 0; i < 0xa0; i++)
        __asm__("nop");
}

void FUN_a011b3e8(unsigned char sel, unsigned char v)
{
    int i;

    if (sel == 0)
        R(0xcf01178c) = v;
    else
        R(0xcf0117a0) = v;
    for (i = 0; i < 0xa0; i++)
        __asm__("nop");
}

void FUN_a011b4f0(struct Xfer *x, unsigned char sel)
{
    unsigned short i, n;

    FUN_a01191fc(sel, 0, 0x80, 0);
    n = x->n;
    cmd(sel, 0xd0);
    addr16(sel, x->addr);
    for (i = 0; i < n; i++)
        FUN_a011b3e8(sel, x->data[i]);
}
