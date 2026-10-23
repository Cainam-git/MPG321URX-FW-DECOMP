/* leon2m FUN_a00f8f78 @ 0xa00f8f78-0xa00f90fc (97 words).
 * FUN_a0121c6c(3), 5 ms delay (func_0x4008d1a0), register 0x8c of block 3 = 0x80 (FUN_a00f1ad4). With block
 * 6 for p 0, 7 for p 1 and 0 otherwise, takes two readings: register 0x36 is written (0x11, then 0x41), then
 * register 0x36 is polled until bit 0 clears or 100 ticks of func_0x4008d588 have passed, and the 16-bit value
 * (register 0x41 << 8) | register 0x40 is read. Then FUN_a0121c6c(3), 5 ms delay, register 0x8c of block 3 = 0.
 * Returns 1 when both readings are equal, else 0.
 * Source form: the reading is a static helper inlined twice. In blk_of the default 0 is set under
 * 'if ((p & 0x80000000) == 0)', a no-code aid: the test is always true for an unsigned char and combine removes
 * it, but only after recording the block value's possible bits from all its assignments; with the 0 behind the
 * test the conversion of the block number stays 'and 0xff' as in the firmware (unconditional, combine narrows it
 * to 'and 7').
 */
extern void FUN_a0121c6c(unsigned char);
extern void func_0x4008d1a0(int ms);
extern unsigned short func_0x4008d588(void);
extern void FUN_a00f1ad4(unsigned char blk, unsigned char reg, unsigned char val);
extern int FUN_a00f1a90(unsigned char blk, unsigned char reg);

static unsigned short reading(unsigned char blk, unsigned char cmd)
{
    unsigned short t;

    FUN_a00f1ad4(blk, 0x36, cmd);
    t = func_0x4008d588();
    while (FUN_a00f1a90(blk, 0x36) & 1) {
        if ((unsigned short)(func_0x4008d588() - t) > 99)
            break;
    }
    return (FUN_a00f1a90(blk, 0x41) & 0xff) << 8 | (FUN_a00f1a90(blk, 0x40) & 0xff);
}

static unsigned char blk_of(unsigned char p)
{
    unsigned char b;

    if ((p & 0x80000000) == 0)
        b = 0;
    if (p == 0)
        b = 6;
    else if (p == 1)
        b = 7;
    return b;
}

unsigned char FUN_a00f8f78(unsigned char p)
{
    unsigned char blk;
    unsigned short a, b;

    FUN_a0121c6c(3);
    func_0x4008d1a0(5);
    FUN_a00f1ad4(3, 0x8c, 0x80);
    blk = blk_of(p);
    a = reading(blk, 0x11);
    b = reading(blk, 0x41);
    FUN_a0121c6c(3);
    func_0x4008d1a0(5);
    FUN_a00f1ad4(3, 0x8c, 0);
    return (unsigned short)(a ^ b) == 0;
}
