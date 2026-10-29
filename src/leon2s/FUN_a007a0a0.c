/* FUN_a007a0a0 (leon2s 0xa007a0a0-0xa007a630, 1424 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port, mask). Calls FUN_a00a7424(1, 0x12, port, 0x2034); for each bit i = 0..3 set in the low byte of
 * mask it records i in the next entry of a 4-halfword lane list and makes FUN_a00a7424(1, 0x12, port,
 * DAT_a00b3b60[i]), FUN_a00a7424(1, 0x12, port, DAT_a00b3b58[i]) and FUN_a00a7488(port, DAT_a00b3b50[i] /
 * DAT_a00b3b48[i], 0xffff00ff, 0xc800). Then, for each recorded lane l, fourteen FUN_a00a7488(port, table[l],
 * mask, value) writes on the halfword register tables DAT_a00b3b28 .. DAT_a00b3b50; then, for each lane, four
 * more writes (b40 / b38 mask 0xffffff value 0x8000000, b50 / b48 mask 0xffffff00 value 8) and, with base 0x2000,
 * 0x2400, 0x2800 for lanes 0, 1, 2 and 0x3000 otherwise, FUN_a00a7424(1, 0xc, port, base | 0x310) and
 * FUN_a00a7424(0, 0xc, port, base | 0x330) (static helper set_base, inlined).
 * Source form: every table write has its own 'lane < 4' bound check (macro WR, as in FUN_a0079e00).
 * Compiler aid: 'if (port) {}' in the lane 0 and lane 1 arms emits no instructions; it puts the port conversion
 * before the base constant in those arms, so each of them keeps its own 'and %i0,0xff' (cross-jumping does not
 * merge it into the shared call sequence).
 */
extern void FUN_a00a7424(int mode, unsigned int bit, unsigned char reg, unsigned short val);
extern void FUN_a00a7488(unsigned int param_1, unsigned short param_2, unsigned int param_3, unsigned int param_4);
extern const unsigned short DAT_a00b3b28[4];
extern const unsigned short DAT_a00b3b30[4];
extern const unsigned short DAT_a00b3b38[4];
extern const unsigned short DAT_a00b3b40[4];
extern const unsigned short DAT_a00b3b48[4];
extern const unsigned short DAT_a00b3b50[4];
extern const unsigned short DAT_a00b3b58[4];
extern const unsigned short DAT_a00b3b60[4];

static inline void set_base(unsigned char port, unsigned short base)
{
    FUN_a00a7424(1, 0xc, port, base | 0x310);
    FUN_a00a7424(0, 0xc, port, base | 0x330);
}

#define WR(tab, m, v) if (lane[j] < 4) FUN_a00a7488(port, tab[lane[j]], m, v)

void FUN_a007a0a0(unsigned char port, int mask)
{
    unsigned short lane[4] = {0, 0, 0, 0};
    unsigned short n, i, j;

    FUN_a00a7424(1, 0x12, port, 0x2034);
    n = 0;
    for (i = 0; i < 4; i++) {
        if (((mask & 0xff) >> i) & 1) {
            lane[n++] = i;
            if (i < 4)
                FUN_a00a7424(1, 0x12, port, DAT_a00b3b60[i]);
            if (i < 4)
                FUN_a00a7424(1, 0x12, port, DAT_a00b3b58[i]);
            if (i < 4)
                FUN_a00a7488(port, DAT_a00b3b50[i], 0xffff00ff, 0xc800);
            if (i < 4)
                FUN_a00a7488(port, DAT_a00b3b48[i], 0xffff00ff, 0xc800);
        }
    }
    for (j = 0; j < n; j++) {
        WR(DAT_a00b3b40, 0xffffff, 0x88000000);
        WR(DAT_a00b3b50, 0xffffff00, 0x88);
        WR(DAT_a00b3b38, 0xffffff, 0x88000000);
        WR(DAT_a00b3b48, 0xffffff00, 0x88);
        WR(DAT_a00b3b30, 0xffffff00, 3);
        WR(DAT_a00b3b28, 0xffffff00, 3);
        WR(DAT_a00b3b30, 0xffff00ff, 0);
        WR(DAT_a00b3b28, 0xffff00ff, 0);
        WR(DAT_a00b3b30, 0xff00ffff, 0);
        WR(DAT_a00b3b28, 0xff00ffff, 0);
        WR(DAT_a00b3b30, 0xffffff, 0xb8000000);
        WR(DAT_a00b3b28, 0xffffff, 0xf8000000);
        WR(DAT_a00b3b50, 0xffff00ff, 0x8800);
        WR(DAT_a00b3b48, 0xffff00ff, 0x8800);
    }
    for (j = 0; j < n; j++) {
        WR(DAT_a00b3b40, 0xffffff, 0x8000000);
        WR(DAT_a00b3b50, 0xffffff00, 8);
        WR(DAT_a00b3b38, 0xffffff, 0x8000000);
        WR(DAT_a00b3b48, 0xffffff00, 8);
        if (lane[j] == 0) {
            if (port) {}
            set_base(port, 0x2000);
        } else if (lane[j] == 1) {
            if (port) {}
            set_base(port, 0x2400);
        } else if (lane[j] == 2)
            set_base(port, 0x2800);
        else
            set_base(port, 0x3000);
    }
}
