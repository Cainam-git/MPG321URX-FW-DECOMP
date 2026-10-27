/* leon2m FUN_a01218c8 @ 0xa01218c8-0xa0121b50 (162 words), flags -mcpu=v8 -O3 -g. Called by FUN_a015209c.
 * Register set-up of block 8 and the eight channel blocks 0..7: FUN_a00f1ad4(8, reg, val) for (0x54, 0x24),
 * (0x55, 0xc0), (0x56, 0x42); FUN_a00f1fe0(8, reg, val) for (0x16, 0x80), (0x17, 0x1f), (0x1a, 4). v = 0x20 when
 * word 4 of the first 12-byte record at 0xa8027aac is 1, else 4. For each channel i = 0..7: FUN_a00f1fe0(i, 0x29,
 * v | 4) when word 4 of record i is 1, else FUN_a00f1fe0(i, 0x29, v & 0xe0); then FUN_a00f1fe0(i, 0x1b,
 * (v & 0x1e) | 0x20). Then FUN_a00f1fe0(8, ...) for (0x18, 0x13), (0x19, 0x42), (0x1c, 0), (0x1d, 0), (0x1e, 0x3f),
 * (0x1f, 0x1f), (0x10, 0xc5); FUN_a00f2068(8, 0x2e, 5, 1); FUN_a00f1ad4(8, ...) for (0x5b, 0x4a), (0x5c, 2);
 * FUN_a0121714(i, 0) for i = 0..7; register 0xcf011408 = 0; func_0x4008a880(5, bit, handler) for the handlers
 * FUN_a002ef0c (1), FUN_a002efd4 (2), FUN_a002f010 (4), FUN_a002f04c (8), FUN_a002f088 (0x4000), FUN_a002f0b4
 * (0x1000), FUN_a002f0e0 (0x2000); func_0x40089820(5, m) for m = 0xf, 0x1000, 0x2000 and 0x4000 (the last a tail
 * call).
 * Source form: v is an unsigned char that is reused as the counter of the second loop (so GCC does not fold
 * (v & 0x1e) | 0x20); the first loop's counter is set to 0 before the record test.
 */
struct Rec12 { unsigned int w0, w4, w8; };
extern struct Rec12 DAT_a8027aac[];
extern void FUN_a00f1ad4(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a00f1fe0(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a00f2068(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern void FUN_a0121714(unsigned char ch, unsigned char on);
extern void func_0x4008a880(int, int, void (*)(void));
extern void func_0x40089820(int, int);
extern void FUN_a002ef0c(void);
extern void FUN_a002efd4(void);
extern void FUN_a002f010(void);
extern void FUN_a002f04c(void);
extern void FUN_a002f088(void);
extern void FUN_a002f0b4(void);
extern void FUN_a002f0e0(void);

#define R(a) (*(volatile unsigned int *)(a))

void FUN_a01218c8(void)
{
    unsigned char i;
    unsigned char v;

    FUN_a00f1ad4(8, 0x54, 0x24);
    FUN_a00f1ad4(8, 0x55, 0xc0);
    FUN_a00f1ad4(8, 0x56, 0x42);
    FUN_a00f1fe0(8, 0x16, 0x80);
    FUN_a00f1fe0(8, 0x17, 0x1f);
    FUN_a00f1fe0(8, 0x1a, 4);
    v = 4;
    i = 0;
    if (DAT_a8027aac[0].w4 == 1)
        v = 0x20;
    for (; i <= 7; i++) {
        if (DAT_a8027aac[i].w4 == 1)
            FUN_a00f1fe0(i, 0x29, v | 4);
        else
            FUN_a00f1fe0(i, 0x29, v & 0xe0);
        FUN_a00f1fe0(i, 0x1b, (v & 0x1e) | 0x20);
    }
    FUN_a00f1fe0(8, 0x18, 0x13);
    FUN_a00f1fe0(8, 0x19, 0x42);
    FUN_a00f1fe0(8, 0x1c, 0);
    FUN_a00f1fe0(8, 0x1d, 0);
    FUN_a00f1fe0(8, 0x1e, 0x3f);
    FUN_a00f1fe0(8, 0x1f, 0x1f);
    FUN_a00f1fe0(8, 0x10, 0xc5);
    FUN_a00f2068(8, 0x2e, 5, 1);
    FUN_a00f1ad4(8, 0x5b, 0x4a);
    FUN_a00f1ad4(8, 0x5c, 2);
    for (v = 0; v <= 7; v++)
        FUN_a0121714(v, 0);
    R(0xcf011408) = 0;
    func_0x4008a880(5, 1, FUN_a002ef0c);
    func_0x4008a880(5, 2, FUN_a002efd4);
    func_0x4008a880(5, 4, FUN_a002f010);
    func_0x4008a880(5, 8, FUN_a002f04c);
    func_0x4008a880(5, 0x4000, FUN_a002f088);
    func_0x4008a880(5, 0x1000, FUN_a002f0b4);
    func_0x4008a880(5, 0x2000, FUN_a002f0e0);
    func_0x40089820(5, 0xf);
    func_0x40089820(5, 0x1000);
    func_0x40089820(5, 0x2000);
    func_0x40089820(5, 0x4000);
}
