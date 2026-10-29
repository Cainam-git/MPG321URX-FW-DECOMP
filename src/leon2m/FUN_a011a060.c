/* leon2m FUN_a011a060 @ 0xa011a060 (-mcpu=v8 -O3 -g)
 * Register writes into block blk (blk > 1 treated as 0; block base = DAT_a8027aa8[blk], register n at
 * 0xCF000000 + 4 * n): a to registers base + 0x81 / + 0x82 (low / high byte), ARR_a802c9ca[blk] - 1 to
 * base + 0x83 / + 0xd3, b to base + 0x84 / + 0x85, the byte ARR_a802c9c8[blk] - 1 to base + 0x86; then
 * calls func_0x4008e2a4. Caller: FUN_a014654c.
 * Source form: FUN_a011919c, FUN_a0119910 and the byte-write helper are inlined (static copies with the
 * bodies of the matched functions).
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];
extern unsigned short ARR_a802c9ca[];
extern unsigned char ARR_a802c9c8[];
extern void func_0x4008e2a4(void);

static void wr16(unsigned int a, unsigned short v) { R(a) = (unsigned char)v; R(a + 1) = (unsigned char)(v >> 8); }

static void FUN_a011919c(unsigned char blk, unsigned char reg, unsigned short v)
{
    if (blk > 1) blk = 0;
    wr16(DAT_a8027aa8[blk] + reg, v);
}

static void wr8(unsigned char blk, unsigned int reg, unsigned char v)
{
    if (blk > 1)
        blk = 0;
    R(DAT_a8027aa8[blk] + reg) = v;
}

static void FUN_a0119910(unsigned int blk, int v)
{
    wr8(blk, 0x83, v & 0xff);
    wr8(blk, 0xd3, (v >> 8) & 0xff);
}

void FUN_a011a060(unsigned short a, unsigned short b, unsigned char blk)
{
    FUN_a011919c(blk, 0x81, a);
    FUN_a0119910(blk, ARR_a802c9ca[blk] - 1);
    FUN_a011919c(blk, 0x84, b);
    wr8(blk, 0x86, ARR_a802c9c8[blk] - 1);
    func_0x4008e2a4();
}
