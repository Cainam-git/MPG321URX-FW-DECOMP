/* leon2m FUN_a00ee964 @ 0xa00ee964-0xa00eec44 (736 bytes), flags -mcpu=v8 -O3. Callers: FUN_a00e0e44, FUN_a00eec44.
 * FUN_a00ee964(ch, p2, p3, p4, speed, up, step): speed selects t = 0 (<= 1333), 1 (<= 1866), 2 (<= 2400) or
 * 3 (<= 2667), as FUN_a00ee188 does; larger speed calls FUN_a00df80c(), FUN_a00e0bc0(), prints "Error: Undefined MR6
 * tCCD_L for DDR speed = %d.\n" with speed and returns -1.
 * vref = (pct(e1) + pct(e2)) >> 1 with pct(e) = byte 1 * 100 + byte 2 of the three-byte entries of DAT_a8026998
 * selected by word ch of DAT_a802b730 and of DAT_a802698c. v = vref + step * 65 when up is nonzero, else
 * vref - step * 65. mr6(x) = (x - 6000) / 65 for x in 6000..9250, (x - 4500) / 65 | 0x40 for x in 4500..7750, else
 * 0xff. c = mr6(v); c == 0xff, or mr6(vref) == 0xff: FUN_a00e03b0(ch, 0x28e, 0xff), FUN_a00df80c(), FUN_a00e0bc0(),
 * "Error: vref_op %d.%d%% is neither in MR6 range 1 (60%% - 92.5%%), nor in MR6 range 2 (45%% - 77.5%%).\n" with
 * x / 100, x % 100 (x = v, or vref), returns -1. Otherwise FUN_a00e03b0(ch, 0x28e, c | 0x80),
 * FUN_a00e406c(ch, 6, 6, t << 10 | 0x80), FUN_a00dffa4(1), FUN_a00e406c(ch, 6, 6, t << 10 | c | 0x80),
 * FUN_a00e406c(ch, 6, 6, t << 10 | c), FUN_a00dffa4(1), returns 0.
 * Source form: the speed chain is written in place with v as the temporary ('t = v;' after it, v is set again
 * later), which keeps the copy into t; step * 65 is written in each arm of the up test; pct and mr6 are static
 * helpers.
 */
struct Vr { unsigned char b0, b1, b2; };
extern struct Vr DAT_a8026998[];
extern int DAT_a802b730[], DAT_a802698c[];
extern void FUN_a00df80c(void);
extern void FUN_a00e0bc0(void);
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a00e03b0(unsigned int, unsigned int, unsigned int);
extern void FUN_a00e406c(unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00dffa4(unsigned int);

static int pct(struct Vr *r)
{
    return r->b1 * 100 + r->b2;
}

static int mr6(int v)
{
    if ((unsigned int)(v - 6000) <= 3250)
        return (v - 6000) / 65;
    if ((unsigned int)(v - 4500) <= 3250)
        return (v - 4500) / 65 | 0x40;
    return 0xff;
}

int FUN_a00ee964(unsigned int ch, unsigned int p2, unsigned int p3, unsigned int p4, int speed, int up, int step)
{
    int t, vref, v, c;

    if (speed <= 1333)
        v = 0;
    else if (speed <= 1866)
        v = 1;
    else if (speed <= 2400)
        v = 2;
    else if (speed <= 2667)
        v = 3;
    else {
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170("Error: Undefined MR6 tCCD_L for DDR speed = %d.\n", speed);
        return -1;
    }
    t = v;
    vref = (pct(&DAT_a8026998[DAT_a802b730[ch]]) + pct(&DAT_a8026998[DAT_a802698c[ch]])) >> 1;
    if (up)
        v = vref + step * 65;
    else
        v = vref - step * 65;
    c = mr6(v);
    if (c == 0xff) {
        FUN_a00e03b0(ch, 0x28e, 0xff);
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170("Error: vref_op %d.%d%% is neither in MR6 range 1 (60%% - 92.5%%), nor in MR6 range 2 (45%% - 77.5%%).\n", v / 100, v % 100);
        return -1;
    }
    if (mr6(vref) == 0xff) {
        FUN_a00e03b0(ch, 0x28e, 0xff);
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170("Error: vref_op %d.%d%% is neither in MR6 range 1 (60%% - 92.5%%), nor in MR6 range 2 (45%% - 77.5%%).\n", vref / 100, vref % 100);
        return -1;
    }
    FUN_a00e03b0(ch, 0x28e, c | 0x80);
    FUN_a00e406c(ch, 6, 6, (t << 10) | 0x80);
    FUN_a00dffa4(1);
    FUN_a00e406c(ch, 6, 6, (t << 10) | c | 0x80);
    FUN_a00e406c(ch, 6, 6, (t << 10) | c);
    FUN_a00dffa4(1);
    return 0;
}
