/* leon2m FUN_a00e7254 @ 0xa00e7254-0xa00e7dc8 (2932 bytes), flags -mcpu=v8 -O3 -g. Calls FUN_a00e5fc8.
 * FUN_a00e7254(unit, p1, gen, b, p5, p6, p7, p8): keeps FUN_a00e02ec(unit, r) of the registers 0x54, 0x149, 0x14b,
 * 0x14a, 0x14c, 0x142, 0x11a, 0x121 and 0x102, calls FUN_a00dffb4(6, unit, b) and FUN_a00dfc50(unit, p1, gen); b > 3
 * (unsigned) prints "Error: byte_idx sould be 0 ~ 3. Please check !!!\n" and returns -1.
 * Register fields are written with FUN_a00e0774 and read with FUN_a00e0754, with (reg, mask, shift) from entry b of
 * three word tables (b == -1 passes the table addresses themselves, as in FUN_a00ec340); fields below are named by
 * their first table.
 * p5 != 0: fields 0xa80265d8 = 0, 0xa80265a8 = 2, 0xa8026578 = 0, 0xa8026548 = 0, 0xa80266f8 = 0, 0xa80266c8 = 1,
 * 0xa8026698 = 0xd; FUN_a00e05d8(unit, 0x149, 0xff, 0xff), (0x14a, 0xff, 0xff), (0xde, 0xc0, 0xc0), (0xe1, 0xc0,
 * 0xc0). Loop: FUN_a00e406c(unit, 5, 0, 0x1000), idx + 1, cnt + 1 when field 0xa8026488 is nonzero, else cnt = 0.
 * gen 3 and cnt > 5: idx < 16 prints "idx < 16, cannot -16.\n" and leaves the loop; else field 0xa80266f8 =
 * (idx >> 4) - 1. gen 4 and cnt > 9: field 0xa80266f8 = idx >> 4. Both then set field 0xa8026698 = (idx + 13) & 0xf
 * and field 0xa80266c8 = ((idx & 8) >> 2) | 1; p6 == 0 then ends the loop through the four FUN_a00e05d8 calls above,
 * else gen becomes 0. Fields 0xa8026698 == 0xc, 0xa80266c8 == 3 and 0xa80266f8 == 0xf end the loop the same way;
 * otherwise it repeats while FUN_a00e55ec(unit, b, 1) returns 0.
 * p5 == 0: FUN_a00e406c(unit, 2, 0, 0x400); gen 3: FUN_a00e406c(unit, 6, 3, 4) and FUN_a00e05d8 (0x142, 7, 0),
 * (0x11a, 0x70, 0), (0x121, 7, 0), (0x102, 0x70, 0); gen 4: FUN_a00e406c(unit, 6, 3, (FUN_a00e4030(unit) & 0x7f8) |
 * 4). Then gen 3: FUN_a00e05d8 (0xde, 0xc0, 0xc0), (0xe1, 0xc0, 0xc0), FUN_a00e03b0 (0x149, 0xff), (0x14a, 0),
 * (0x14c, 0), a = FUN_a00e0514(unit, 0x241, 0x1f), c = FUN_a00e0514(unit, 0x242, 0x1f), FUN_a00e05d8 (0x240, 0x80,
 * 0x80), (0x241, 0x1f, 0x1f), (0x242, 0x1f, 0x1f); gen 4: FUN_a00e406c(unit, 0xb, 0, byte DAT_a802698b).
 * r = FUN_a00e5fc8(unit, gen, b); r != 0 is returned. gen 3: FUN_a00e05d8 (0xde, 0xc0, 0), (0xe1, 0xc0, 0),
 * FUN_a00e03b0 (0x149, 0), (0x14a, 0), (0x14c, 0), FUN_a00e05d8 (0x142, 7, 1), (0x11a, 0x70, 0x10), (0x121, 7, 1),
 * (0x102, 0x70, 0x10), (0x241, 0x1f, a), (0x242, 0x1f, c), FUN_a00dff94(1). Then FUN_a00e406c(unit, 6, 3,
 * FUN_a00e4030(unit) & 0x1ff8).
 * All paths except the two returns above write the nine kept values back with FUN_a00e03b0; then p8 == 0 returns
 * 0, else p8 is negated when p7 != 0 and a nonzero FUN_a00e55ec(unit, b, p8) is returned, otherwise 0.
 * Source form: each table access is its own if (b == -1)/else statement; the reads compared in a condition are
 * conditional expressions of two calls ('(b == -1 ? FUN_a00e0754(..) : FUN_a00e0754(..)) != 0'); the count update is
 * 'if (..) cnt++; else cnt = 0;'; FUN_a00e05d8 is declared void; the table at 0xa8026468 is declared as
 * ARR_a8026468 (the symbol name sets the order of the loop-invariant address pseudos); the loop counter idx is
 * also the variable of the final 'return idx;' (idx = 0 before the p8 test), which sets the register choice of the
 * three loop-invariant 0xa8026698/0xa8026688/0xa8026678 table addresses.
 */
extern int FUN_a00e02ec(unsigned int, unsigned int);
extern void FUN_a00e03b0();
extern unsigned int FUN_a00e0514(unsigned int, unsigned int, unsigned int);
extern void FUN_a00e05d8(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int FUN_a00e0754(unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00e0774(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00e406c(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int FUN_a00e4030(unsigned int);
extern int FUN_a00e55ec(unsigned int, int, int);
extern int FUN_a00e5fc8();
extern void FUN_a00dffb4(unsigned int, unsigned int, unsigned int);
extern int FUN_a00dfc50(unsigned int, unsigned int, unsigned int);
extern void FUN_a00dff94(int);
extern void FUN_a00df80c(void);
extern void FUN_a00e0bc0(void);
extern int FUN_a00df170(const char *, ...);
extern unsigned char DAT_a802698b;
extern unsigned int DAT_a80265d8[], DAT_a80265c8[], DAT_a80265b8[], DAT_a80265a8[], DAT_a8026598[], DAT_a8026588[];
extern unsigned int DAT_a8026578[], DAT_a8026568[], DAT_a8026558[], DAT_a8026548[], DAT_a8026538[], DAT_a8026528[];
extern unsigned int DAT_a80266f8[], DAT_a80266e8[], DAT_a80266d8[], DAT_a80266c8[], DAT_a80266b8[], DAT_a80266a8[];
extern unsigned int DAT_a8026698[], DAT_a8026688[], DAT_a8026678[], DAT_a8026488[], DAT_a8026478[], ARR_a8026468[];

int FUN_a00e7254(unsigned int unit, unsigned int p1, unsigned int gen, unsigned int b, unsigned int p5,
                 unsigned int p6, int p7, int p8)
{
    unsigned int s54, s149, s14b, s14a, s14c, s142, s11a, s121, s102;
    unsigned int a, c, idx, cnt;
    int r;

    s54 = FUN_a00e02ec(unit, 0x54);
    s149 = FUN_a00e02ec(unit, 0x149);
    s14b = FUN_a00e02ec(unit, 0x14b);
    s14a = FUN_a00e02ec(unit, 0x14a);
    s14c = FUN_a00e02ec(unit, 0x14c);
    s142 = FUN_a00e02ec(unit, 0x142);
    s11a = FUN_a00e02ec(unit, 0x11a);
    s121 = FUN_a00e02ec(unit, 0x121);
    s102 = FUN_a00e02ec(unit, 0x102);
    FUN_a00dffb4(6, unit, b);
    FUN_a00dfc50(unit, p1, gen);
    a = 0;
    c = 0;
    if (b > 3) {
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170("Error: byte_idx sould be 0 ~ 3. Please check !!!\n");
        return -1;
    }
    if (p5 != 0) {
        if (b == -1)
            FUN_a00e0774(unit, (unsigned int)DAT_a80265d8, (unsigned int)DAT_a80265c8, (unsigned int)DAT_a80265b8, 0);
        else
            FUN_a00e0774(unit, DAT_a80265d8[b], DAT_a80265c8[b], DAT_a80265b8[b], 0);
        if (b == -1)
            FUN_a00e0774(unit, (unsigned int)DAT_a80265a8, (unsigned int)DAT_a8026598, (unsigned int)DAT_a8026588, 2);
        else
            FUN_a00e0774(unit, DAT_a80265a8[b], DAT_a8026598[b], DAT_a8026588[b], 2);
        if (b == -1)
            FUN_a00e0774(unit, (unsigned int)DAT_a8026578, (unsigned int)DAT_a8026568, (unsigned int)DAT_a8026558, 0);
        else
            FUN_a00e0774(unit, DAT_a8026578[b], DAT_a8026568[b], DAT_a8026558[b], 0);
        if (b == -1)
            FUN_a00e0774(unit, (unsigned int)DAT_a8026548, (unsigned int)DAT_a8026538, (unsigned int)DAT_a8026528, 0);
        else
            FUN_a00e0774(unit, DAT_a8026548[b], DAT_a8026538[b], DAT_a8026528[b], 0);
        if (b == -1)
            FUN_a00e0774(unit, (unsigned int)DAT_a80266f8, (unsigned int)DAT_a80266e8, (unsigned int)DAT_a80266d8, 0);
        else
            FUN_a00e0774(unit, DAT_a80266f8[b], DAT_a80266e8[b], DAT_a80266d8[b], 0);
        if (b == -1)
            FUN_a00e0774(unit, (unsigned int)DAT_a80266c8, (unsigned int)DAT_a80266b8, (unsigned int)DAT_a80266a8, 1);
        else
            FUN_a00e0774(unit, DAT_a80266c8[b], DAT_a80266b8[b], DAT_a80266a8[b], 1);
        if (b == -1)
            FUN_a00e0774(unit, (unsigned int)DAT_a8026698, (unsigned int)DAT_a8026688, (unsigned int)DAT_a8026678, 0xd);
        else
            FUN_a00e0774(unit, DAT_a8026698[b], DAT_a8026688[b], DAT_a8026678[b], 0xd);
        FUN_a00e05d8(unit, 0x149, 0xff, 0xff);
        FUN_a00e05d8(unit, 0x14a, 0xff, 0xff);
        FUN_a00e05d8(unit, 0xde, 0xc0, 0xc0);
        FUN_a00e05d8(unit, 0xe1, 0xc0, 0xc0);
        idx = 0;
        cnt = 0;
        do {
            FUN_a00e406c(unit, 5, 0, 0x1000);
            idx++;
            if ((b == -1 ? FUN_a00e0754(unit, (unsigned int)DAT_a8026488, (unsigned int)DAT_a8026478, (unsigned int)ARR_a8026468) : FUN_a00e0754(unit, DAT_a8026488[b], DAT_a8026478[b], ARR_a8026468[b])) != 0)
                cnt++;
            else
                cnt = 0;
            if (gen == 3) {
                if (cnt > 5) {
                    if (idx < 16) {
                        FUN_a00df80c();
                        FUN_a00e0bc0();
                        FUN_a00df170("idx < 16, cannot -16.\n");
                        goto restore;
                    }
                    if (b == -1)
                        FUN_a00e0774(unit, (unsigned int)DAT_a80266f8, (unsigned int)DAT_a80266e8, (unsigned int)DAT_a80266d8, (idx >> 4) - 1);
                    else
                        FUN_a00e0774(unit, DAT_a80266f8[b], DAT_a80266e8[b], DAT_a80266d8[b], (idx >> 4) - 1);
                    if (b == -1)
                        FUN_a00e0774(unit, (unsigned int)DAT_a8026698, (unsigned int)DAT_a8026688, (unsigned int)DAT_a8026678, (idx + 13) & 0xf);
                    else
                        FUN_a00e0774(unit, DAT_a8026698[b], DAT_a8026688[b], DAT_a8026678[b], (idx + 13) & 0xf);
                    if (b == -1)
                        FUN_a00e0774(unit, (unsigned int)DAT_a80266c8, (unsigned int)DAT_a80266b8, (unsigned int)DAT_a80266a8, (idx & 8) >> 2 | 1);
                    else
                        FUN_a00e0774(unit, DAT_a80266c8[b], DAT_a80266b8[b], DAT_a80266a8[b], (idx & 8) >> 2 | 1);
                    if (p6 == 0)
                        goto finish;
                    gen = 0;
                }
            } else if (gen == 4) {
                if (cnt > 9) {
                    if (b == -1)
                        FUN_a00e0774(unit, (unsigned int)DAT_a80266f8, (unsigned int)DAT_a80266e8, (unsigned int)DAT_a80266d8, idx >> 4);
                    else
                        FUN_a00e0774(unit, DAT_a80266f8[b], DAT_a80266e8[b], DAT_a80266d8[b], idx >> 4);
                    if (b == -1)
                        FUN_a00e0774(unit, (unsigned int)DAT_a8026698, (unsigned int)DAT_a8026688, (unsigned int)DAT_a8026678, (idx + 13) & 0xf);
                    else
                        FUN_a00e0774(unit, DAT_a8026698[b], DAT_a8026688[b], DAT_a8026678[b], (idx + 13) & 0xf);
                    if (b == -1)
                        FUN_a00e0774(unit, (unsigned int)DAT_a80266c8, (unsigned int)DAT_a80266b8, (unsigned int)DAT_a80266a8, (idx & 8) >> 2 | 1);
                    else
                        FUN_a00e0774(unit, DAT_a80266c8[b], DAT_a80266b8[b], DAT_a80266a8[b], (idx & 8) >> 2 | 1);
                    if (p6 == 0)
                        goto finish;
                    gen = 0;
                }
            }
            if ((b == -1 ? FUN_a00e0754(unit, (unsigned int)DAT_a8026698, (unsigned int)DAT_a8026688, (unsigned int)DAT_a8026678) : FUN_a00e0754(unit, DAT_a8026698[b], DAT_a8026688[b], DAT_a8026678[b])) == 0xc && (b == -1 ? FUN_a00e0754(unit, (unsigned int)DAT_a80266c8, (unsigned int)DAT_a80266b8, (unsigned int)DAT_a80266a8) : FUN_a00e0754(unit, DAT_a80266c8[b], DAT_a80266b8[b], DAT_a80266a8[b])) == 3 && (b == -1 ? FUN_a00e0754(unit, (unsigned int)DAT_a80266f8, (unsigned int)DAT_a80266e8, (unsigned int)DAT_a80266d8) : FUN_a00e0754(unit, DAT_a80266f8[b], DAT_a80266e8[b], DAT_a80266d8[b])) == 0xf) {
finish:
                FUN_a00e05d8(unit, 0x149, 0xff, 0xff);
                FUN_a00e05d8(unit, 0x14a, 0xff, 0xff);
                FUN_a00e05d8(unit, 0xde, 0xc0, 0xc0);
                FUN_a00e05d8(unit, 0xe1, 0xc0, 0xc0);
                goto restore;
            }
        } while (FUN_a00e55ec(unit, b, 1) == 0);
        goto restore;
    }
    FUN_a00e406c(unit, 2, 0, 0x400);
    if (gen == 3) {
        FUN_a00e406c(unit, 6, 3, 4);
        FUN_a00e05d8(unit, 0x142, 7, 0);
        FUN_a00e05d8(unit, 0x11a, 0x70, 0);
        FUN_a00e05d8(unit, 0x121, 7, 0);
        FUN_a00e05d8(unit, 0x102, 0x70, 0);
    } else if (gen == 4) {
        FUN_a00e406c(unit, 6, 3, (FUN_a00e4030(unit) & 0x7f8) | 4);
    }
    if (gen == 3) {
        FUN_a00e05d8(unit, 0xde, 0xc0, 0xc0);
        FUN_a00e05d8(unit, 0xe1, 0xc0, 0xc0);
        FUN_a00e03b0(unit, 0x149, 0xff);
        FUN_a00e03b0(unit, 0x14a, 0);
        FUN_a00e03b0(unit, 0x14c, 0);
        a = FUN_a00e0514(unit, 0x241, 0x1f);
        c = FUN_a00e0514(unit, 0x242, 0x1f);
        FUN_a00e05d8(unit, 0x240, 0x80, 0x80);
        FUN_a00e05d8(unit, 0x241, 0x1f, 0x1f);
        FUN_a00e05d8(unit, 0x242, 0x1f, 0x1f);
    } else if (gen == 4) {
        FUN_a00e406c(unit, 0xb, 0, DAT_a802698b);
    }
    r = FUN_a00e5fc8(unit, gen, b);
    if (r != 0)
        return r;
    if (gen == 3) {
        FUN_a00e05d8(unit, 0xde, 0xc0, 0);
        FUN_a00e05d8(unit, 0xe1, 0xc0, 0);
        FUN_a00e03b0(unit, 0x149, 0);
        FUN_a00e03b0(unit, 0x14a, 0);
        FUN_a00e03b0(unit, 0x14c, 0);
        FUN_a00e05d8(unit, 0x142, 7, 1);
        FUN_a00e05d8(unit, 0x11a, 0x70, 0x10);
        FUN_a00e05d8(unit, 0x121, 7, 1);
        FUN_a00e05d8(unit, 0x102, 0x70, 0x10);
        FUN_a00e05d8(unit, 0x241, 0x1f, a);
        FUN_a00e05d8(unit, 0x242, 0x1f, c);
        FUN_a00dff94(1);
    }
    FUN_a00e406c(unit, 6, 3, FUN_a00e4030(unit) & 0x1ff8);
restore:
    FUN_a00e03b0(unit, 0x54, s54);
    FUN_a00e03b0(unit, 0x149, s149);
    FUN_a00e03b0(unit, 0x14b, s14b);
    FUN_a00e03b0(unit, 0x14a, s14a);
    FUN_a00e03b0(unit, 0x14c, s14c);
    FUN_a00e03b0(unit, 0x142, s142);
    FUN_a00e03b0(unit, 0x11a, s11a);
    FUN_a00e03b0(unit, 0x121, s121);
    FUN_a00e03b0(unit, 0x102, s102);
    idx = 0;
    if (p8 != 0) {
        if (p7 != 0)
            p8 = -p8;
        r = FUN_a00e55ec(unit, b, p8);
        if (r != 0)
            return r;
    }
    return idx;
}
