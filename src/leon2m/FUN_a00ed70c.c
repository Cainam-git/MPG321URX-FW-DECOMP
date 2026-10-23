/* leon2m FUN_a00ed70c @ 0xa00ed70c-0xa00edc70 (345 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a00e0e44.
 * FUN_a00ed70c(unit, p1, type, b, p4, p5, p6, p7). saved = FUN_a00e02ec(unit, 0x149); FUN_a00dffb4(5, unit, b);
 * FUN_a00dfc50(unit, p1, type). Register fields are read with FUN_a00e0754 and written with FUN_a00e0774, with
 * (reg, mask, shift) from entry b of three word tables (b == -1 passes the table addresses themselves). The field of
 * tables 0xa8026978/0xa8026968/0xa8026958 is set to 1, then FUN_a00ed530(unit, b, 6), FUN_a00e0774(unit, 0x281, 0x80,
 * 7, 1), FUN_a00e05d8(unit, 0x149, 0xff, 0xff), FUN_a00e0774(unit, 0x8e, 2, 1, 1). type 4 with bit 0 of
 * FUN_a00e3ff4(unit) clear, or type 3 with it set: FUN_a00df80c(), FUN_a00e0bc0(), "Error: DDR4 MR1 Bit0 is not 1.\n"
 * or "Error: DDR3 MR1 Bit0 is not 0.\n" to FUN_a00df170, returns -1. Then FUN_a00e406c(unit, 6, 1,
 * FUN_a00e3ff4(unit) | 0x80) and for i = 0..15: FUN_a00e0774(unit, 0x8e, 1, 0, 1) and (.., 0); with the counter
 * cnt[0][b] at 0, the field of tables 0xa8026888/0xa8026878/0xa802b718 (v) being 0 increments the counter, and
 * FUN_a00ed530(unit, b, i + 7) follows; with the counter at 1, v != 0 increments it and found, and sets flg[0][b]
 * when i > p4, v == 0 calls FUN_a00ed530(unit, b, i + 7). found == 1 leaves the loop; after 16 rounds with the
 * counter at most 1: FUN_a00ed530(unit, b, 6), flg[0][b]++, FUN_a00e0ba8(), "WL phy%d wr_msg_b%d=1\n" with unit, b.
 * When p7 != 0 (negated when p6 != 0): r = FUN_a00ed530(unit, b, field(0xa8026918/0xa8026908/0xa80268f8) + p7),
 * returned when non-zero. Then field(0xa80268e8/0xa80268d8/0xa80268c8) = field(0xa8026918..) + p5,
 * field(0xa80268b8/0xa80268a8/0xa8026898) = field(0xa80268e8..) - 4, FUN_a00e406c(unit, 6, 1, FUN_a00e3ff4(unit) &
 * 0xfff7f), FUN_a00e03b0(unit, 0x149, 0), FUN_a00e0774(unit, 0x8e, 2, 1, 0), FUN_a00e0090(unit),
 * FUN_a00e03b0(unit, 0x149, saved); returns 0.
 * Source form: each read/write is its own if (b == -1)/else statement (as in FUN_a00e9c80); two zero-initialised
 * int[2][2] arrays (store order of the clears). Compiler aid: 'goto next; next:;' at the end of the v != 0 block
 * emits no instructions; it marks that path as not taken, which keeps the shared FUN_a00ed530 call block in the
 * firmware's layout.
 */
extern int FUN_a00e02ec(unsigned int, unsigned int);
extern void FUN_a00dffb4(unsigned int, unsigned int, unsigned int);
extern int FUN_a00dfc50(unsigned int, unsigned int, unsigned int);
extern void FUN_a00df80c(void);
extern void FUN_a00e0bc0(void);
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned int FUN_a00e0754(unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00e0774(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern int FUN_a00ed530(unsigned int, int, unsigned char);
extern unsigned int FUN_a00e3ff4(unsigned int);
extern void FUN_a00e406c(unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00e05d8(unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00e03b0(unsigned int, unsigned int, unsigned int);
extern void FUN_a00e0090(unsigned int);
extern void FUN_a00e0ba8(void);
extern unsigned int DAT_a8026978[], DAT_a8026968[], DAT_a8026958[];
extern unsigned int DAT_a8026888[], DAT_a8026878[], DAT_a802b718[];
extern unsigned int DAT_a8026918[], DAT_a8026908[], DAT_a80268f8[];
extern unsigned int DAT_a80268e8[], DAT_a80268d8[], DAT_a80268c8[];
extern unsigned int DAT_a80268b8[], DAT_a80268a8[], DAT_a8026898[];

int FUN_a00ed70c(unsigned int unit, unsigned int p1, unsigned int type, int b, int p4, int p5, int p6, int p7)
{
    int cnt[2][2] = {{0}};
    int flg[2][2] = {{0}};
    int saved, i, found, r;
    unsigned int v;

    saved = FUN_a00e02ec(unit, 0x149);
    FUN_a00dffb4(5, unit, b);
    FUN_a00dfc50(unit, p1, type);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026978, (unsigned int)DAT_a8026968, (unsigned int)DAT_a8026958, 1);
    else
        FUN_a00e0774(unit, DAT_a8026978[b], DAT_a8026968[b], DAT_a8026958[b], 1);
    FUN_a00ed530(unit, b, 6);
    FUN_a00e0774(unit, 0x281, 0x80, 7, 1);
    FUN_a00e05d8(unit, 0x149, 0xff, 0xff);
    FUN_a00e0774(unit, 0x8e, 2, 1, 1);
    if (type == 4) {
        if (!(FUN_a00e3ff4(unit) & 1)) {
            FUN_a00df80c();
            FUN_a00e0bc0();
            FUN_a00df170("Error: DDR4 MR1 Bit0 is not 1.\n");
            return -1;
        }
    } else if (type == 3) {
        if (FUN_a00e3ff4(unit) & 1) {
            FUN_a00df80c();
            FUN_a00e0bc0();
            FUN_a00df170("Error: DDR3 MR1 Bit0 is not 0.\n");
            return -1;
        }
    }
    FUN_a00e406c(unit, 6, 1, FUN_a00e3ff4(unit) | 0x80);
    found = 0;
    for (i = 0; i <= 15; i++) {
        FUN_a00e0774(unit, 0x8e, 1, 0, 1);
        FUN_a00e0774(unit, 0x8e, 1, 0, 0);
        if (cnt[0][b] == 0) {
            if (b == -1)
                v = FUN_a00e0754(unit, (unsigned int)DAT_a8026888, (unsigned int)DAT_a8026878, (unsigned int)DAT_a802b718);
            else
                v = FUN_a00e0754(unit, DAT_a8026888[b], DAT_a8026878[b], DAT_a802b718[b]);
            if (v == 0)
                cnt[0][b]++;
            FUN_a00ed530(unit, b, i + 7);
        } else if (cnt[0][b] == 1) {
            if (b == -1)
                v = FUN_a00e0754(unit, (unsigned int)DAT_a8026888, (unsigned int)DAT_a8026878, (unsigned int)DAT_a802b718);
            else
                v = FUN_a00e0754(unit, DAT_a8026888[b], DAT_a8026878[b], DAT_a802b718[b]);
            if (v != 0) {
                cnt[0][b]++;
                found++;
                if (i > p4)
                    flg[0][b] = 1;
                goto next;
            next:;
            } else {
                FUN_a00ed530(unit, b, i + 7);
            }
        }
        if (found == 1)
            goto done;
    }
    if (cnt[0][b] <= 1) {
        FUN_a00ed530(unit, b, 6);
        flg[0][b]++;
        FUN_a00e0ba8();
        FUN_a00df170("WL phy%d wr_msg_b%d=1\n", unit, b);
    }
done:
    if (p7 != 0) {
        if (p6 != 0)
            p7 = -p7;
        if (b == -1)
            v = FUN_a00e0754(unit, (unsigned int)DAT_a8026918, (unsigned int)DAT_a8026908, (unsigned int)DAT_a80268f8);
        else
            v = FUN_a00e0754(unit, DAT_a8026918[b], DAT_a8026908[b], DAT_a80268f8[b]);
        r = FUN_a00ed530(unit, b, v + p7);
        if (r != 0)
            return r;
    }
    if (b == -1)
        v = FUN_a00e0754(unit, (unsigned int)DAT_a8026918, (unsigned int)DAT_a8026908, (unsigned int)DAT_a80268f8);
    else
        v = FUN_a00e0754(unit, DAT_a8026918[b], DAT_a8026908[b], DAT_a80268f8[b]);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a80268e8, (unsigned int)DAT_a80268d8, (unsigned int)DAT_a80268c8, v + p5);
    else
        FUN_a00e0774(unit, DAT_a80268e8[b], DAT_a80268d8[b], DAT_a80268c8[b], v + p5);
    if (b == -1)
        v = FUN_a00e0754(unit, (unsigned int)DAT_a80268e8, (unsigned int)DAT_a80268d8, (unsigned int)DAT_a80268c8);
    else
        v = FUN_a00e0754(unit, DAT_a80268e8[b], DAT_a80268d8[b], DAT_a80268c8[b]);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a80268b8, (unsigned int)DAT_a80268a8, (unsigned int)DAT_a8026898, v - 4);
    else
        FUN_a00e0774(unit, DAT_a80268b8[b], DAT_a80268a8[b], DAT_a8026898[b], v - 4);
    FUN_a00e406c(unit, 6, 1, FUN_a00e3ff4(unit) & 0xfff7f);
    FUN_a00e03b0(unit, 0x149, 0);
    FUN_a00e0774(unit, 0x8e, 2, 1, 0);
    FUN_a00e0090(unit);
    FUN_a00e03b0(unit, 0x149, saved);
    return 0;
}
