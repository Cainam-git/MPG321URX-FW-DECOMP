/* leon2m FUN_a0127b24 @ 0xa0127b24  recover mode 0/2 decision of the OLED power state machine (RecoverOFF).
 * Flags -mcpu=v8 -O3 -msoft-float (also matches with -mcpu=v8 -O3 -g).
 * Stand-alone copy of a small static helper that FUN_a0127c78 (OLED power / panel state machine) also
 * inlines.
 */
struct OledState {
    unsigned char state, sub;
    unsigned short t2, t4, cnt;
    unsigned char b8, b9, ba, bb;
    union { unsigned char b; unsigned short h; } c;
    unsigned char be, target;
    unsigned char b10, b11, b12, b13;
    unsigned short h14;
    unsigned char b16;
};
struct G290 {
    unsigned char p000[0x1d5];
    unsigned char b1d5;
    unsigned char p1d6[0x1e2 - 0x1d6];
    unsigned char b1e2, b1e3, b1e4, b1e5, b1e6, b1e7;
    unsigned char p1e8[0x1f4 - 0x1e8];
    union { unsigned int w; struct { unsigned short hi, lo; } h; } u1f4;
};
extern struct OledState DAT_a802d896;
extern struct G290 DAT_a802d290;
#define S DAT_a802d896
#define G DAT_a802d290
extern unsigned short FUN_a0145af8(unsigned int);
unsigned char FUN_a0127ab8(void)
{
    unsigned char f;
    if (G.u1f4.h.lo == 0x55aa && G.b1d5 != 0 && FUN_a0145af8(0x11) == 1) {
        S.b9 = 1;
        S.target = 0;
        f = 1;
    } else
        f = 0;
    return f;
}

unsigned char FUN_a0127a34(void)
{
    unsigned char r;
    if (FUN_a0145af8(0x10) == 0) {
        if (FUN_a0145af8(0xd) >= 4) r = 1; else r = 0;
    } else {
        if (FUN_a0145af8(0xd) * 60 + FUN_a0145af8(0xb) > 19) r = 1; else r = 0;
    }
    return r;
}

unsigned char FUN_a0127b24(void)
{
    unsigned char m;
    if (S.ba == 1) m = 2;
    else if (FUN_a0127a34()) m = 2;
    else if (FUN_a0127ab8() == 1 && FUN_a0145af8(0xd) * 60 + FUN_a0145af8(0xb) >= 0) m = 2;
    else m = 0;
    return m;
}
