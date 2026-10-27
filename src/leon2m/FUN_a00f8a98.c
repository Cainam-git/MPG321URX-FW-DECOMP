/* leon2m FUN_a00f8a98 @ 0xa00f8a98-0xa00f8cc4 (139 words), flags -mcpu=v8 -O3 -g. Called by FUN_a013c144.
 * w and h are divided by 4, rounded up. t = FUN_a00fd820(p) selects the value written to register 0 of block p
 * through FUN_a00f1e50: 0 for t == 0xb1, 1 for 0x31, 0x41, 0x51, 0x61, 2 for 0x71, 0x81, else 1. Then
 * FUN_a00f1ed8(p, reg, v) writes w to 0x10, h to 0x12 and x to 0x14. For p != 1 the function ends with
 * FUN_a00f1e50(p, 0x16, 0x42). For p == 1 a loop runs: func_0x4008ced8(); FUN_a00f1e50(p, ...) for (0x48, 1),
 * (0x16, 0x4a), 1 ms delay (func_0x4008d1a0), (0x16, 0x42), (0x48, 0), (0x49, 0xc3), 50 ms delay, (0x49, 1), 5 ms
 * delay; when bits 0..1 of register 0x4a (FUN_a00f1e0c) are set, prints "ESC[1;31mToggle(%d) P1 420/444 for ASYNC
 * FIFO over/under flow(%02x)\r\nESC[m" with the count and those bits read again. The loop repeats while those bits
 * are set and the incremented count is at most 9; then FUN_a00f1e50(p, 0x49, 3).
 * Source form: each value of t has its own FUN_a00f1e50 call (GCC merges them); the count is incremented in the
 * second operand of the loop condition.
 */
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned char FUN_a00fd820(unsigned char);
extern void FUN_a00f1e50(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a00f1ed8(unsigned char blk, unsigned char reg, unsigned short val);
extern unsigned char FUN_a00f1e0c(unsigned char blk, unsigned char reg);
extern void func_0x4008ced8(void);
extern void func_0x4008d1a0(int ms);

void FUN_a00f8a98(unsigned char p, unsigned short w, unsigned short h, unsigned short x)
{
    unsigned char cnt = 0;
    unsigned char t;

    if (w % 4)
        w = w / 4 + 1;
    else
        w = w / 4;
    if (h % 4)
        h = h / 4 + 1;
    else
        h = h / 4;
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
    if (p == 1) {
        do {
            func_0x4008ced8();
            FUN_a00f1e50(p, 0x48, 1);
            FUN_a00f1e50(p, 0x16, 0x4a);
            func_0x4008d1a0(1);
            FUN_a00f1e50(p, 0x16, 0x42);
            FUN_a00f1e50(p, 0x48, 0);
            FUN_a00f1e50(p, 0x49, 0xc3);
            func_0x4008d1a0(0x32);
            FUN_a00f1e50(p, 0x49, 1);
            func_0x4008d1a0(5);
            if (FUN_a00f1e0c(p, 0x4a) & 3)
                FUN_a00df170("\x1b[1;31mToggle(%d) P1 420/444 for ASYNC FIFO over/under flow(%02x)\r\n\x1b[m", cnt,
                             FUN_a00f1e0c(p, 0x4a) & 3);
        } while ((FUN_a00f1e0c(p, 0x4a) & 3) && ++cnt <= 9);
        FUN_a00f1e50(p, 0x49, 3);
    } else
        FUN_a00f1e50(p, 0x16, 0x42);
}
