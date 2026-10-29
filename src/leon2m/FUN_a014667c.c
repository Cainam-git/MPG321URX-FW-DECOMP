/* leon2m FUN_a014667c @ 0xa014667c-0xa0146870 (125 words).
 * Fills a 5-byte record r and passes it by value, with blk, to FUN_a011a574 (which reads it through a byte pointer).
 * For n 0..7 (jump table at 0xe32dc, 9 entries) it first calls func_0x4008e6e4(n, blk); n 8 and larger skip the call.
 * r.b0 starts at 0; its bits 0, 2, 1 and 3 are set when bit0, bit2, bit1 and bit3 are non-zero and cleared otherwise.
 * r.b1 = v1, r.b2 = ((x << 4) & 0x30) | (y & 0x0f), r.b3 = v3, r.b4 = v4.
 * Source form: r.b0 and r.b2 are cleared before the switch, and every case 0..8 clears r.b1, r.b3 and r.b4 (GCC keeps
 * these clears before the calls and drops them for case 8, which keeps its own jump table entry). r.b2 is written as
 * two field updates (bits 4-7, then bits 0-3); their reads of r.b2 keep its clear before the switch.
 */
struct Rec
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
};

extern void func_0x4008e6e4(unsigned int v, unsigned char blk);
extern void FUN_a011a574(struct Rec r, unsigned char blk);

void FUN_a014667c(unsigned char n, unsigned char bit0, unsigned char bit2, unsigned char bit1, unsigned char bit3,
                  unsigned char v1, unsigned char x, unsigned char y, unsigned char v3, unsigned char v4,
                  unsigned char blk)
{
    struct Rec r;

    r.b0 = 0;
    r.b2 = 0;
    switch (n) {
    case 0:
        r.b1 = 0;
        r.b3 = 0;
        r.b4 = 0;
        func_0x4008e6e4(0, blk);
        break;
    case 1:
        r.b1 = 0;
        r.b3 = 0;
        r.b4 = 0;
        func_0x4008e6e4(1, blk);
        break;
    case 2:
        r.b1 = 0;
        r.b3 = 0;
        r.b4 = 0;
        func_0x4008e6e4(2, blk);
        break;
    case 3:
        r.b1 = 0;
        r.b3 = 0;
        r.b4 = 0;
        func_0x4008e6e4(3, blk);
        break;
    case 4:
        r.b1 = 0;
        r.b3 = 0;
        r.b4 = 0;
        func_0x4008e6e4(4, blk);
        break;
    case 5:
        r.b1 = 0;
        r.b3 = 0;
        r.b4 = 0;
        func_0x4008e6e4(5, blk);
        break;
    case 6:
        r.b1 = 0;
        r.b3 = 0;
        r.b4 = 0;
        func_0x4008e6e4(6, blk);
        break;
    case 7:
        r.b1 = 0;
        r.b3 = 0;
        r.b4 = 0;
        func_0x4008e6e4(7, blk);
        break;
    case 8:
        r.b1 = 0;
        r.b3 = 0;
        r.b4 = 0;
        break;
    }

    if (bit0)
        r.b0 |= 1;
    else
        r.b0 &= ~1;
    if (bit2)
        r.b0 |= 4;
    else
        r.b0 &= ~4;
    if (bit1)
        r.b0 |= 2;
    else
        r.b0 &= ~2;
    if (bit3)
        r.b0 |= 8;
    else
        r.b0 &= ~8;
    r.b1 = v1;
    r.b2 = (r.b2 & ~0xf0) | ((x << 4) & 0x30);
    r.b2 = (r.b2 & ~0x0f) | (y & 0x0f);
    r.b3 = v3;
    r.b4 = v4;
    FUN_a011a574(r, blk);
}
