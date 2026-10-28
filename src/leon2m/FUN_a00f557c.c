/* leon2m FUN_a00f557c @ 0xa00f557c-0xa00f59c4, flags -mcpu=v8 -O3 -g.
 * Runs three measurement steps for block 'port' and returns 1 when FUN_a00f51b4 and FUN_a00f4e60 both return
 * nonzero, else 0.
 *   Saves block register 0x2a (FUN_a00f2254) and 0x4a (FUN_a00f1a90), sets 0x2a = 0 and clears bit 0x20 of 0x4a
 *   (FUN_a00f1b5c), FUN_a0121714(port, 1); saves the three values of FUN_a00f3960/3974/3988 (s0).
 *   Register 0xcf02010c = (port << 4 | port) & 0xff for port <= 7, else 0.
 *   calib (inlined static helper): saves the three values again (s1), FUN_a00f31bc(2), block registers
 *   0x5e/0x5f/0x60 = 0x71/0xff/0, the three values written as 0xff (FUN_a00f38d4/38ec/3904), registers
 *   0x65/0x66/0x67 = 0xf5/0xf4/0xf0, 0x63 = 0x80, 0x64 = 3. Sampling loop (timer start func_0x4008d588,
 *   func_0x4008d1a0(2) per pass): FUN_a0121374(blk) == 1 ends it with n = 3; a new value that differs from the
 *   previous one by more than 2 sets n = 3; n == 3 restarts the three 16-bit sums, otherwise the values are added;
 *   when --n reaches 0 the averages sum / 3 are taken; the loop runs while n != 0 and func_0x4008d594(t0) <= 0x12b.
 *   Registers 0x63..0x67 and 0x5e = 0, FUN_a00f31bc(3); the averages are written when n reached 0, else s1.
 *   Then FUN_a00f31bc(0); FUN_a00f51b4(port), and when nonzero FUN_a00f31bc(2) and FUN_a00f4e60(port); result 1
 *   when both are nonzero, otherwise s0 is written back. FUN_a00f31bc(3), FUN_a0121714(port, 0), registers 0x2a
 *   and 0x4a restored (FUN_a00f2298, FUN_a00f1ad4). Returns the result as 'ok & 1'.
 * Source form: int parameter passed to the unsigned char callee parameters; an unsigned char copy 'b = port'
 *   taken before the 0xcf02010c value and passed to calib (the firmware keeps it as a raw register copy and
 *   zero-extends it at calib's entry); the averaging inside the loop ('if (--n == 0) { ... }' with 'n != 0' in
 *   the loop condition, as in FUN_a00f4e60).
 * Compiler aid: 'for (;;) break;' before the calib call emits no instructions; it ends the common-subexpression
 *   region there, so b stays a separate copy instead of being replaced by port.
 */
extern int abs(int);
#define R(a) (*(volatile unsigned int *)(a))
extern unsigned char FUN_a00f2254(unsigned char blk, unsigned char reg);
extern unsigned char FUN_a00f1a90(unsigned char blk, unsigned char reg);
extern void FUN_a00f2298(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a00f1b5c(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern void FUN_a00f1ad4(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a0121714(unsigned char, int);
extern unsigned char FUN_a0121374(unsigned char blk);
extern unsigned char FUN_a00f3960(void);
extern unsigned char FUN_a00f3974(void);
extern unsigned char FUN_a00f3988(void);
extern void FUN_a00f38d4(unsigned char);
extern void FUN_a00f38ec(unsigned char);
extern void FUN_a00f3904(unsigned char);
extern void FUN_a00f31bc(int);
extern unsigned char FUN_a00f51b4(unsigned char);
extern unsigned char FUN_a00f4e60(unsigned char);
extern unsigned short func_0x4008d588(void);
extern unsigned short func_0x4008d594(unsigned short start);
extern void func_0x4008d1a0(int ms);

static void calib(unsigned char blk)
{
    unsigned short acc[3];
    unsigned char cur[3], s1[3];
    unsigned char n, c;
    unsigned short t0;

    s1[0] = FUN_a00f3960();
    s1[1] = FUN_a00f3974();
    s1[2] = FUN_a00f3988();
    FUN_a00f31bc(2);
    FUN_a00f1ad4(blk, 0x5e, 0x71);
    FUN_a00f1ad4(blk, 0x5f, 0xff);
    FUN_a00f1ad4(blk, 0x60, 0);
    cur[0] = 0;
    cur[1] = 0;
    cur[2] = 0;
    FUN_a00f38d4(0xff);
    FUN_a00f38ec(0xff);
    FUN_a00f3904(0xff);
    FUN_a00f1ad4(blk, 0x65, 0xf5);
    FUN_a00f1ad4(blk, 0x66, 0xf4);
    FUN_a00f1ad4(blk, 0x67, 0xf0);
    FUN_a00f1ad4(blk, 0x63, 0x80);
    FUN_a00f1ad4(blk, 0x64, 3);
    acc[0] = 0;
    acc[1] = 0;
    acc[2] = 0;
    t0 = func_0x4008d588();
    n = 3;
    do {
        func_0x4008d1a0(2);
        if (FUN_a0121374(blk) == 1) {
            n = 3;
            break;
        }
        c = FUN_a00f3960();
        if (abs(cur[0] - c) > 2)
            n = 3;
        cur[0] = c;
        c = FUN_a00f3974();
        if (abs(cur[1] - c) > 2)
            n = 3;
        cur[1] = c;
        c = FUN_a00f3988();
        if (abs(cur[2] - c) > 2)
            n = 3;
        cur[2] = c;
        if (n == 3) {
            acc[0] = cur[0];
            acc[1] = cur[1];
            acc[2] = cur[2];
        } else {
            acc[0] += cur[0];
            acc[1] += cur[1];
            acc[2] += cur[2];
        }
        if (--n == 0) {
            cur[0] = acc[0] / 3;
            cur[1] = acc[1] / 3;
            cur[2] = acc[2] / 3;
        }
    } while (n != 0 && func_0x4008d594(t0) <= 0x12b);
    FUN_a00f1ad4(blk, 0x63, 0);
    FUN_a00f1ad4(blk, 0x64, 0);
    FUN_a00f1ad4(blk, 0x65, 0);
    FUN_a00f1ad4(blk, 0x66, 0);
    FUN_a00f1ad4(blk, 0x67, 0);
    FUN_a00f1ad4(blk, 0x5e, 0);
    FUN_a00f31bc(3);
    if (n != 0) {
        FUN_a00f38d4(s1[0]);
        FUN_a00f38ec(s1[1]);
        FUN_a00f3904(s1[2]);
    } else {
        FUN_a00f38d4(cur[0]);
        FUN_a00f38ec(cur[1]);
        FUN_a00f3904(cur[2]);
    }
}

int FUN_a00f557c(int port)
{
    unsigned char s0[3];
    unsigned char old1, old2, v;
    unsigned char ok;
    unsigned char b;

    old1 = FUN_a00f2254(port, 0x2a);
    old2 = FUN_a00f1a90(port, 0x4a);
    FUN_a00f2298(port, 0x2a, 0);
    FUN_a00f1b5c(port, 0x4a, 0x20, 0);
    FUN_a0121714(port, 1);
    ok = 0;
    s0[0] = FUN_a00f3960();
    s0[1] = FUN_a00f3974();
    s0[2] = FUN_a00f3988();
    b = port;
    v = 0;
    if ((unsigned char)port <= 7) {
        v = port << 4;
        v |= port;
    }
    R(0xcf02010c) = v;
    for (;;) break;
    calib(b);
    FUN_a00f31bc(0);
    if (FUN_a00f51b4(port) && (FUN_a00f31bc(2), FUN_a00f4e60(port))) {
        ok = 1;
    } else {
        FUN_a00f38d4(s0[0]);
        FUN_a00f38ec(s0[1]);
        FUN_a00f3904(s0[2]);
    }
    FUN_a00f31bc(3);
    FUN_a0121714(port, 0);
    FUN_a00f2298(port, 0x2a, old1);
    FUN_a00f1ad4(port, 0x4a, old2);
    return ok & 1;
}
