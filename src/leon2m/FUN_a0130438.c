/* leon2m FUN_a0130438 @ 0xa0130438 (-mcpu=v8 -O3 -g). Called by FUN_a013129c.
 * Applies the body of FUN_a01302e0 (channel record on/off, see there) to the four channel records
 * DAT_a802df30[0..3] by the byte 0xa802e1a7 (switch, jump table at 0xcf1cc): 0 turns channel 0 on and 1..3 off;
 * 1, 2, 5 turn 0 and 1 on, 2 and 3 off; 3, 6 turn 0..2 on, 3 off; 4, 7 turn all four on; other values change
 * nothing. Then channel 3 is turned on when bit 21 of word 0xa802e3d0 is set, channel 2 when byte 0xa802e3fa is 1
 * and channel 3 when byte 0xa802e3fc is 1.
 * Source form: FUN_a01302e0 (the function just before this one) is copied here as a static function and called
 * with constant arguments; GCC inlines every call.
 */
struct Chan {
    union { unsigned int w; struct { unsigned int state:4, f24:4, step:4, f16:4, port:4, f8:4, f4:4, f1:3, b0:1; } b; } u;
    unsigned char p04[0x70 - 0x04];
    union { unsigned int w; struct { unsigned int r31:7, b24:1, rest:24; } b; } w70;
    unsigned char p74[0x78 - 0x74];
};
struct Port { unsigned char b00, b01, b02; unsigned char p03[7]; unsigned char b0a; unsigned char rest[0x2a - 0x0b]; };
extern struct Chan DAT_a802df30[4];
extern struct Port DAT_a802e224[];
extern unsigned char FUN_a0141ce0(unsigned char t);
extern void FUN_a0141d50(unsigned char t, unsigned char v);
extern void FUN_a00f67d0(int p);
extern unsigned char FUN_a013cda8(unsigned char ch);
extern void FUN_a0109474(unsigned char sel, unsigned char on);

static void chan_set(unsigned char ch, unsigned char on)
{
    int a, b;

    DAT_a802df30[ch].w70.b.b24 = on & 1;
    a = DAT_a802df30[ch].u.b.state == 0;
    b = on != 0;
    if (a & b)
        DAT_a802df30[ch].u.b.state = 5;
    a = DAT_a802e224[DAT_a802df30[ch].u.b.port].b02 == 1;
    if (a & b)
        DAT_a802e224[DAT_a802df30[ch].u.b.port].b02 = 2;
    if (FUN_a0141ce0(DAT_a802e224[DAT_a802df30[ch].u.b.port].b0a) == 1 && on)
        FUN_a0141d50(DAT_a802e224[DAT_a802df30[ch].u.b.port].b0a, 2);
    if (DAT_a802df30[ch].u.b.f4 != 4)
        FUN_a00f67d0(DAT_a802df30[ch].u.b.f4);
    if (!on)
        DAT_a802df30[ch].u.b.state = 0;
    FUN_a0109474(FUN_a013cda8(ch), 0);
}

struct S3d0 {
    unsigned int w0;
    unsigned char p04[0x26];
    unsigned char b2a, b2b, b2c;
};
extern unsigned char DAT_a802e1a7;
extern struct S3d0 DAT_a802e3d0;

void FUN_a0130438(void)
{
    switch (DAT_a802e1a7) {
    case 0:
        chan_set(0, 1);
        chan_set(1, 0);
        chan_set(2, 0);
        chan_set(3, 0);
        break;
    case 1:
    case 2:
    case 5:
        chan_set(0, 1);
        chan_set(1, 1);
        chan_set(2, 0);
        chan_set(3, 0);
        break;
    case 3:
    case 6:
        chan_set(0, 1);
        chan_set(1, 1);
        chan_set(2, 1);
        chan_set(3, 0);
        break;
    case 4:
    case 7:
        chan_set(0, 1);
        chan_set(1, 1);
        chan_set(2, 1);
        chan_set(3, 1);
        break;
    }
    if (DAT_a802e3d0.w0 & 0x200000)
        chan_set(3, 1);
    if (DAT_a802e3d0.b2a == 1)
        chan_set(2, 1);
    if (DAT_a802e3d0.b2c == 1)
        chan_set(3, 1);
}
