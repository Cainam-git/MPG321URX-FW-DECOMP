/* leon2m FUN_a008c25c @ 0xa008c25c..0xa008cc28 (627 words), flags -mcpu=v8 -O3 -g (-msoft-float gives the same
 * code).
 * Factory menu "+" key: steps the item selected by DAT_a802afbd (0..26) up and redraws it.
 *  1..6, 10..12: u8 values at 0xA802E1F6..E1FB / E202..E204, +1 saturating at 0xFF, redraw a group of 3 items;
 *  7..9: 0xA802D2A2..D2A4 +1 up to 100, item shows v*255/100 rounded; 13/14: 0xA802D299/D29A +1 up to 100 (+apply);
 *  15/16: 0xA802AFB8 (max 7) / AFB9 (max 8) + menu page redraw; 17: factory marker h1f6 0x55AA <-> 0xBB99 + EEPROM save;
 *  19: Burn In byte 0xA802D465 ^= 1; 20: u16 at 0xA802D46A +1 up to 0x3FF; 21: FUN_a01266b0() value 0..2 cyclic;
 *  22: Inspection Mode/Pattern 0xA802AFBA 0..7 cyclic (FUN_a01275b0/FUN_a0127724); 23/24: toggles of setting 0x10 / 2;
 *  25: word 0xA802D464 bit 7 toggle ("HDMI CTS"); 26: byte 0xA8024040 ^= 1 (FUN_a014df68(0xD/0xC)).
 * Then a second switch marks the redraw flags in DAT_a802b08e (gcc bit tests 0x1C7E / 0x380 / 0x80000).
 * Source form: the rename-register choices follow the SOURCE ORDER of the case blocks and of if/else arms
 * (rnreg's LRU ticks follow source block order). First switch case order:
 *   6 2 3 7 9 8 10 11 12 4 5 1 13 14 15 16 17 19 21 22 24 23 25 20 26
 * (the tail 16 17 19 21 22 24 23 25 20 26 is the twin FUN_a008b83c's order);
 * arms: 15 'if (v <= 7) {..} else store 7', 17 'if (h1f6 == 0x55aa) ..' (both ifs), 21 'if ((u8)r != 2) {r++ ..} else ..',
 * 22 'if (v != 7) { if (v == 6) .. else .. } else ..', 16 'if (v > 8) store 8; else {..}', 23 '== 1' / 24 '!= 1';
 * second switch body order 19 / 7-9 / 1..12. Every case ends in break and the case labels are disjoint, every arm swap
 * negates its condition exactly, so behaviour is the same as the firmware's. No no-code aids, no asm, no volatile.
 * Shape facts (all plain C): '== K' arms written as if/else with a full call per arm; groups 1-6/10-12 =
 * 'v8 = &field; if (++*v8 == 0) *v8 = 0xff;' + the 3 draw calls repeated per case (cross-jumped, gives fw
 * 'or %lo,%l0; add %l0,-k'); 13/14 'if (p->b009 < 100) { if (++p->b009 == 0) p->b009 = 0xff; }' (the byte is < 100,
 * so ++ never wraps; the fw keeps the 0xff test), draw argument via DAT_a802d290.bXX (fw reloads it);
 * 7-9 unsigned (v*255u+50)/100.
 */
struct Fac290 {                         /* 0xA802D290 */
    unsigned char b000[9];
    unsigned char b009, b00a;           /* +0x009 */
    unsigned char b00b[7];
    unsigned char b012, b013, b014;     /* +0x012 */
    unsigned char b015[0x1bf];
    union {
        unsigned int w;
        struct { unsigned int hi:24, b7:1, lo:7; } f;
        unsigned char b[4];             /* b[1] = +0x1d5 Burn In */
    } u1d4;                             /* +0x1d4 */
    unsigned short h1d8, h1da;          /* +0x1d8 */
    unsigned char b1dc[0x1a];
    unsigned short h1f6;                /* +0x1f6 */
};
struct Fac1f0 {                         /* 0xA802E1F0 */
    unsigned char b0[6];
    unsigned char f6, f7, f8, f9, fa, fb;     /* +0x06 */
    unsigned char b0c[6];
    unsigned char f12, f13, f14;              /* +0x12 */
};
struct Pos { unsigned char col, row, len; };

extern unsigned char DAT_a802afbd, DAT_a802afbc, DAT_a802afba, DAT_a802afb9, DAT_a802afb8;
extern unsigned char DAT_a802b08e, DAT_a8024040;
extern struct Fac290 DAT_a802d290;
extern struct Fac1f0 DAT_a802e1f0;
extern const struct Pos DAT_00100242[];
extern const char s_001002a0[], s_001002a8[], s_00100330[];

extern void FUN_a008a568(unsigned char, unsigned short);
extern int FUN_a00d8cd4(void);
extern int FUN_a00d7de0(void);
extern int FUN_a00d9764();
extern void FUN_a00d5918(void);
extern unsigned short FUN_a01266b0(void);
extern void FUN_a012653c(unsigned char);
extern unsigned short FUN_a0145af8(unsigned int id);
extern void FUN_a0145c5c(int, int);
extern void FUN_a0145360(int);
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, const char *, unsigned char);
extern void FUN_a01275b0(unsigned char on);
extern void FUN_a0127724(unsigned char pat);
extern int FUN_a014aed0(int, void *, int, int);
extern void FUN_a014df68(unsigned char, unsigned char);
extern void FUN_a008b380(void);
extern void FUN_a008b5e0(void);

void FUN_a008c25c(void)
{
    struct Fac290 *p;
    unsigned char v;
    unsigned char *v8;
    unsigned short r;

    switch (DAT_a802afbd) {
    case 6:
        v8 = &DAT_a802e1f0.f14; if (++*v8 == 0) *v8 = 0xff;
        FUN_a008a568(4, DAT_a802e1f0.f12);
        FUN_a008a568(5, DAT_a802e1f0.f13);
        FUN_a008a568(6, DAT_a802e1f0.f14);
        break;
    case 2:
        v8 = &DAT_a802e1f0.f7; if (++*v8 == 0) *v8 = 0xff;
        FUN_a008a568(1, DAT_a802e1f0.f6);
        FUN_a008a568(2, DAT_a802e1f0.f7);
        FUN_a008a568(3, DAT_a802e1f0.f8);
        break;
    case 3:
        v8 = &DAT_a802e1f0.f8; if (++*v8 == 0) *v8 = 0xff;
        FUN_a008a568(1, DAT_a802e1f0.f6);
        FUN_a008a568(2, DAT_a802e1f0.f7);
        FUN_a008a568(3, DAT_a802e1f0.f8);
        break;
    case 7:
        p = &DAT_a802d290;
        v = p->b012 + 1;
        if (v > 100) p->b012 = 100;
        else { p->b012 = v; FUN_a008a568(7, (v * 255u + 50) / 100); }
        break;
    case 9:
        p = &DAT_a802d290;
        v = p->b014 + 1;
        if (v > 100) p->b014 = 100;
        else { p->b014 = v; FUN_a008a568(9, (v * 255u + 50) / 100); }
        break;
    case 8:
        p = &DAT_a802d290;
        v = p->b013 + 1;
        if (v > 100) p->b013 = 100;
        else { p->b013 = v; FUN_a008a568(8, (v * 255u + 50) / 100); }
        break;
    case 10:
        v8 = &DAT_a802e1f0.f9; if (++*v8 == 0) *v8 = 0xff;
        FUN_a008a568(0xa, DAT_a802e1f0.f9);
        FUN_a008a568(0xb, DAT_a802e1f0.fa);
        FUN_a008a568(0xc, DAT_a802e1f0.fb);
        break;
    case 11:
        v8 = &DAT_a802e1f0.fa; if (++*v8 == 0) *v8 = 0xff;
        FUN_a008a568(0xa, DAT_a802e1f0.f9);
        FUN_a008a568(0xb, DAT_a802e1f0.fa);
        FUN_a008a568(0xc, DAT_a802e1f0.fb);
        break;
    case 12:
        v8 = &DAT_a802e1f0.fb; if (++*v8 == 0) *v8 = 0xff;
        FUN_a008a568(0xa, DAT_a802e1f0.f9);
        FUN_a008a568(0xb, DAT_a802e1f0.fa);
        FUN_a008a568(0xc, DAT_a802e1f0.fb);
        break;
    case 4:
        v8 = &DAT_a802e1f0.f12; if (++*v8 == 0) *v8 = 0xff;
        FUN_a008a568(4, DAT_a802e1f0.f12);
        FUN_a008a568(5, DAT_a802e1f0.f13);
        FUN_a008a568(6, DAT_a802e1f0.f14);
        break;
    case 5:
        v8 = &DAT_a802e1f0.f13; if (++*v8 == 0) *v8 = 0xff;
        FUN_a008a568(4, DAT_a802e1f0.f12);
        FUN_a008a568(5, DAT_a802e1f0.f13);
        FUN_a008a568(6, DAT_a802e1f0.f14);
        break;
    case 1:
        v8 = &DAT_a802e1f0.f6; if (++*v8 == 0) *v8 = 0xff;
        FUN_a008a568(1, DAT_a802e1f0.f6);
        FUN_a008a568(2, DAT_a802e1f0.f7);
        FUN_a008a568(3, DAT_a802e1f0.f8);
        break;
    case 13:
        p = &DAT_a802d290;
        if (p->b009 < 100) { if (++p->b009 == 0) p->b009 = 0xff; }
        FUN_a008a568(0xd, DAT_a802d290.b009);
        FUN_a00d8cd4();
        break;
    case 14:
        p = &DAT_a802d290;
        if (p->b00a < 100) { if (++p->b00a == 0) p->b00a = 0xff; }
        FUN_a008a568(0xe, DAT_a802d290.b00a);
        FUN_a00d7de0();
        break;
    case 15:
        v = DAT_a802afb8 + 1;
        if (v <= 7) { DAT_a802afb8 = v; FUN_a008b380(); FUN_a008b5e0(); }
        else DAT_a802afb8 = 7;
        break;
    case 16:
        v = DAT_a802afb9 + 1;
        if (v > 8) DAT_a802afb9 = 8;
        else { DAT_a802afb9 = v; FUN_a008a568(0x10, v); FUN_a008b5e0(); }
        break;
    case 17:
        if (DAT_a802d290.h1f6 == 0x55aa) DAT_a802d290.h1f6 = 0xbb99;
        else DAT_a802d290.h1f6 = 0x55aa;
        FUN_a0146b50(0xd6, 0);
        if (DAT_a802d290.h1f6 == 0x55aa)
            FUN_a00a31a4(0, 9, 0xd, 3, s_001002a8, 0);
        else
            FUN_a00a31a4(0, 9, 0xd, 3, s_001002a0, 0);
        FUN_a014aed0(0x30, &DAT_a802d290, 0, 0x1fc);
        break;
    case 19:
        p = &DAT_a802d290;
        p->u1d4.b[1] ^= 1;
        FUN_a0146b50(0xca, 0);
        FUN_a0146b6c(0, 0);
        if (p->u1d4.b[1] == 1)
            FUN_a00a31a4(0, DAT_00100242[19].col + 8, 0xf, 3, s_001002a8, 0);
        else
            FUN_a00a31a4(0, DAT_00100242[19].col + 8, 0xf, 3, s_001002a0, 0);
        break;
    case 21:
        v8 = &DAT_a802afbc;
        r = FUN_a01266b0();
        if ((unsigned char)r != 2) { r++; *v8 = r; FUN_a012653c((unsigned char)r); }
        else { *v8 = 0; FUN_a012653c(0); }
        FUN_a008a568(0x15, DAT_a802afbc);
        break;
    case 22:
        v = DAT_a802afba;
        if (v != 7) { if (v == 6) { DAT_a802afba = v + 1; FUN_a01275b0(1); FUN_a0127724(0); } else { DAT_a802afba = v + 1; FUN_a01275b0(1); FUN_a0127724(DAT_a802afba); } }
        else { DAT_a802afba = 0; FUN_a01275b0(0); FUN_a0127724(0); }
        FUN_a008a568(0x16, DAT_a802afba);
        break;
    case 24:
        if (FUN_a0145af8(2) != 1) FUN_a0145c5c(2, 1);
        else FUN_a0145c5c(2, 0);
        FUN_a0146b50(0xd3, 0);
        if (FUN_a0145af8(2))
            FUN_a00a31a4(0, DAT_00100242[24].col + 0xb, 0x14, 3, s_001002a8, 0);
        else
            FUN_a00a31a4(0, DAT_00100242[24].col + 0xb, 0x14, 3, s_001002a0, 0);
        FUN_a0145360(1);
        break;
    case 23:
        if (FUN_a0145af8(0x10) == 1) FUN_a0145c5c(0x10, 0);
        else FUN_a0145c5c(0x10, 1);
        FUN_a0146b50(0xf7, 0);
        if (FUN_a0145af8(0x10))
            FUN_a00a31a4(0, DAT_00100242[23].col + 0xb, 0x13, 3, s_001002a8, 0);
        else
            FUN_a00a31a4(0, DAT_00100242[23].col + 0xb, 0x13, 3, s_001002a0, 0);
        FUN_a0145360(1);
        break;
    case 25:
        p = &DAT_a802d290;
        p->u1d4.f.b7 ^= 1;
        FUN_a00d5918();
        FUN_a0146b50(0xea, 0);
        FUN_a0146b6c(0, 0);
        {
            unsigned char col = DAT_00100242[25].col, row = DAT_00100242[25].row;
            FUN_a00a31a4(0, col, row, 8, s_00100330, 0);
            if (p->u1d4.f.b7)
                FUN_a00a31a4(0, col + 0xc, row, 3, s_001002a8, 0);
            else
                FUN_a00a31a4(0, col + 0xc, row, 3, s_001002a0, 0);
        }
        DAT_a802b08e |= 2;
        break;
    case 20:
        p = &DAT_a802d290;
        if ((unsigned short)(p->h1da + 1) > 0x3ff) p->h1da = 0x3ff;
        else p->h1da = p->h1da + 1;
        FUN_a00d8cd4();
        FUN_a008a568(0x14, p->h1da);
        DAT_a802b08e |= 2;
        break;
    case 26:
        DAT_a8024040 ^= 1;
        FUN_a014df68(0xd, DAT_a8024040);
        FUN_a014df68(0xc, DAT_a8024040);
        FUN_a0146b50(0xf4, 0);
        FUN_a0146b6c(0, 0);
        if (DAT_a8024040 == 1)
            FUN_a00a31a4(0, DAT_00100242[26].col + 8, DAT_00100242[26].row, 3, s_001002a8, 0);
        else
            FUN_a00a31a4(0, DAT_00100242[26].col + 8, DAT_00100242[26].row, 3, s_001002a0, 0);
        break;
    }
    switch (DAT_a802afbd) {
    case 19:
        DAT_a802b08e |= 2;
        break;
    case 7: case 8: case 9:
        FUN_a00d9764();
        DAT_a802b08e |= 6;
        break;
    case 1: case 2: case 3: case 4: case 5: case 6: case 10: case 11: case 12:
        FUN_a00d9764();
        DAT_a802b08e |= 4;
        break;
    }
}
