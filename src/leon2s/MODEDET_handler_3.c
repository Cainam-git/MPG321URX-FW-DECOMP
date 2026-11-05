/* MODEDET_handler_3 (leon2s 0xa009dd40-0xa009dfa8, 616 bytes), flags -mcpu=v8 -Os -g.
 * int (port), K&R unsigned char parameter p; sel = 2, or 3 for port 1. DAT_a807db00 holds 0x34-byte port
 * records whose words +0 and +0x20 point to register blocks r0 and r20; DAT_a807d650 holds 0x18-byte records
 * (word +0 state, byte +4 count, byte +5); DAT_a807d7e0 holds 400-byte records.
 * Calls FUN_a00a73ac(2, r0 + 0x2d). Count 0: state = 0, byte +1 of ARR_a807cc64[sel] = 0, prints "PLL Checking
 * Timeout, Restart EQ Flow" (bit 2 of _DAT_a8078634) and returns 0. Otherwise decrements the count (printed under
 * the same bit), passes 4 (FUN_a00a03c8(p) == 1) or bits 8..11 of r0[0x11] to FUN_a009d87c(p, ..) and stores the
 * same choice in byte +0x2c of the record, replaces halfword +0x20 with r0[0x14] and compares a second read of
 * r0[0x14] with the old value: a difference above 1 returns 0. A count above 2 is set to 3, prints "Speed Up PLL
 * Checking" and returns 0. Else byte +5 = 0, state = 5, halfwords +0x1a / +0x1e = upper halves of r0[0x0e] /
 * r0[0x13] shifted left by DAT_a80790a8[p], +0x1c = r0[0x0f]; FUN_a009fe98(p), FUN_a009740c(p), byte +6 = 0,
 * FUN_a00a73ac(0x18, r20 + 0xe), returns 1.
 * Source form: the tests after the halfword compare are nested in 'if (difference <= 1)' with one 'return 0' at
 * the end of the function for every other path.
 */
struct port_rec {
    volatile unsigned int *r0;
    volatile unsigned int *r4;
    unsigned char _08[0x18];
    volatile unsigned int *r20;
    unsigned char _24[0x34 - 0x24];
};
struct st_rec {
    unsigned int st;
    unsigned char cnt;
    unsigned char b5;
    unsigned char _6[0x18 - 6];
};
struct mode_rec {
    unsigned char _00[6];
    unsigned char b6;
    unsigned char _07[0x1a - 7];
    unsigned short h1a;
    unsigned short h1c;
    unsigned short h1e;
    unsigned short h20;
    unsigned char _22[0x2c - 0x22];
    unsigned char b2c;
    unsigned char _2d[0x190 - 0x2d];
};
struct sel_rec {
    unsigned char b0;
    unsigned char b1;
    unsigned char _2[0x18 - 2];
};
extern struct port_rec DAT_a807db00[];
extern struct st_rec DAT_a807d650[];
extern struct mode_rec DAT_a807d7e0[];
extern struct sel_rec ARR_a807cc64[];
extern unsigned char DAT_a80790a8[];
extern unsigned int _DAT_a8078634;
extern int FUN_a0073044(const char *, ...);
extern void FUN_a00a73ac(unsigned int, volatile unsigned int *);
extern unsigned char FUN_a00a03c8(unsigned char);
extern void FUN_a009d87c(unsigned int, unsigned int);
extern void FUN_a009fe98(unsigned int);
extern void FUN_a009740c(unsigned int);

int MODEDET_handler_3(p)
    unsigned char p;
{
    unsigned char sel = 2;
    unsigned int a, b, c;
    unsigned short o;

    if (p == 1)
        sel = 3;
    FUN_a00a73ac(2, DAT_a807db00[p].r0 + 0x2d);
    if (DAT_a807d650[p].cnt != 0) {
        DAT_a807d650[p].cnt--;
        if (_DAT_a8078634 & 4)
            FUN_a0073044("[MODEDET]: Port%c : Mode Detect Check PLL Count = %d \n", (char)(p + 'A'),
                         DAT_a807d650[p].cnt);
        FUN_a009d87c(p, FUN_a00a03c8(p) == 1 ? 4 : (DAT_a807db00[p].r0[0x44 / 4] >> 8) & 0xf);
        DAT_a807d7e0[p].b2c = FUN_a00a03c8(p) == 1 ? 4 : (DAT_a807db00[p].r0[0x44 / 4] >> 8) & 0xf;
        o = DAT_a807d7e0[p].h20;
        DAT_a807d7e0[p].h20 = DAT_a807db00[p].r0[0x50 / 4];
        if (__builtin_abs((unsigned short)DAT_a807db00[p].r0[0x50 / 4] - o) <= 1) {
            if (DAT_a807d650[p].cnt > 2) {
                DAT_a807d650[p].cnt = 3;
                if (_DAT_a8078634 & 4)
                    FUN_a0073044("[MODEDET]: Port%c Speed Up PLL Checking\n", (char)(p + 'A'));
            } else {
                DAT_a807d650[p].b5 = 0;
                a = DAT_a807db00[p].r0[0x38 / 4];
                b = DAT_a807db00[p].r0[0x3c / 4];
                c = DAT_a807db00[p].r0[0x4c / 4];
                DAT_a807d650[p].st = 5;
                DAT_a807d7e0[p].h1a = (a >> 16) << DAT_a80790a8[p];
                DAT_a807d7e0[p].h1c = b;
                DAT_a807d7e0[p].h1e = (c >> 16) << DAT_a80790a8[p];
                FUN_a009fe98(p);
                FUN_a009740c(p);
                DAT_a807d7e0[p].b6 = 0;
                FUN_a00a73ac(0x18, DAT_a807db00[p].r20 + 0xe);
                return 1;
            }
        }
    } else {
        DAT_a807d650[p].st = 0;
        ARR_a807cc64[sel].b1 = 0;
        if (_DAT_a8078634 & 4)
            FUN_a0073044("[MODEDET]: Port%c PLL Checking Timeout, Restart EQ Flow\n", (char)(p + 'A'));
    }
    return 0;
}
