/* leon2m FUN_a00f896c @ 0xa00f896c-0xa00f8a98 (75 words), flags -mcpu=v8 -O3 -g. Called by FUN_a013c144.
 * w and h are divided by 8, rounded up. t = FUN_a00fd820(p) selects the value written to register 0 of block p
 * through FUN_a00f1e50: 0 for t == 0xb1, 1 for 0x31, 0x41, 0x51, 0x61, 2 for 0x71, 0x81, else 1. Then
 * FUN_a00f1ed8(p, reg, v) writes w to 0x10, h to 0x12 and x to 0x14, and FUN_a00f1e50(p, 0x16, 0x4a) ends it.
 * Source form: as the next function, FUN_a00f8a98 (which divides by 4): each value of t has its own FUN_a00f1e50
 * call (GCC merges them), the rounding written as an if/else per value.
 */
extern unsigned char FUN_a00fd820(unsigned char);
extern void FUN_a00f1e50(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a00f1ed8(unsigned char blk, unsigned char reg, unsigned short val);

void FUN_a00f896c(unsigned char p, unsigned short w, unsigned short h, unsigned short x)
{
    unsigned char t;

    if (w % 8)
        w = w / 8 + 1;
    else
        w = w / 8;
    if (h % 8)
        h = h / 8 + 1;
    else
        h = h / 8;
    t = FUN_a00fd820(p);
    if (t == 0xb1)
        FUN_a00f1e50(p, 0, 0);
    else if (t == 0x31 || t == 0x41 || t == 0x51 || t == 0x61)
        FUN_a00f1e50(p, 0, 1);
    else if (t == 0x71 || t == 0x81)
        FUN_a00f1e50(p, 0, 2);
    else
        FUN_a00f1e50(p, 0, 1);
    FUN_a00f1ed8(p, 0x10, w);
    FUN_a00f1ed8(p, 0x12, h);
    FUN_a00f1ed8(p, 0x14, x);
    FUN_a00f1e50(p, 0x16, 0x4a);
}
