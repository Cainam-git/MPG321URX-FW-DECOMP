/* leon2m FUN_a01213a4 @ 0xa01213a4 (-mcpu=v8 -O3 -g)
 * c = ch & 0xff; t = FUN_a00fd820(c); r = FUN_a0120de4(t, c). When bit c of DAT_a802c9e4 is set: clears that
 * bit, calls FUN_a012127c(c, h, 0), sets r = 1 and prints "Mode(%d) Change Flag !!!!" with c through FUN_a00df170.
 * When (unsigned char)(r - 2) < 4 and (unsigned char)r != prev: v1 = 0x3c and v2 by t (0x11-0x13, 0x21 and any
 * other value: 7; 0x31, 0x41, 0x51, 0x61: 0x13; 0x71, 0x81, 0xb1, 0xe1, 0xe2: 3; 0x91: 2 when byte 9 of entry c of
 * the 12-byte table DAT_a8027aac is non-zero, else 3; 0xe8: v1 = v2 = 0); v1 &= 0xdf when byte 8 of entry ch is
 * non-zero; then FUN_a00f1fe0(ch, 0x1e, 0x3f), (ch, 0x1f, 0x1f), (ch, 0x1c, v1) and (ch, 0x1d, v2 & 0x17).
 * Returns r as a byte. Called by FUN_a0142910.
 * Source form: old-style definition; the parameter ch itself receives the FUN_a0120de4 result (declared without a
 * prototype, so the int result is not zero-extended) and the value 1, which is set before the FUN_a00df170 call;
 * the final block reads ch through an unsigned short copy b taken at entry.
 */
struct PortCfg { unsigned int w0, w4; unsigned char b8, b9, b10, b11; };
extern struct PortCfg DAT_a8027aac[];
extern unsigned int DAT_a802c9e4;
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned char FUN_a00fd820(unsigned char);
extern int FUN_a0120de4();
extern void FUN_a012127c(unsigned char blk, unsigned short h, unsigned char on);
extern void FUN_a00f1fe0(unsigned char blk, unsigned char reg, unsigned char val);

unsigned char FUN_a01213a4(ch, h, prev)
    unsigned int ch;
    unsigned char h, prev;
{
    unsigned char c = ch;
    unsigned short b = ch;
    unsigned char t, m, v1, v2, d;
    unsigned int bit;

    t = FUN_a00fd820(c);
    ch = FUN_a0120de4(t, c);
    bit = (DAT_a802c9e4 >> c) & 1;
    if (bit == 1) {
        DAT_a802c9e4 &= ~(bit << c);
        FUN_a012127c(c, h, 0);
        ch = 1;
        FUN_a00df170("\r\n----------Mode(%d) Change Flag !!!!----------\r\n", c);
    }
    d = ch - 2;
    m = ch;
    if (d < 4 && m != prev) {
        unsigned char q = b;
        v1 = 0x3c;
        v2 = 7;
        switch (t) {
        case 0x11: case 0x12: case 0x13: case 0x21:
            v2 = 7;
            break;
        case 0x31: case 0x41: case 0x51: case 0x61:
            v2 = 0x13;
            break;
        case 0x71: case 0x81: case 0xb1: case 0xe1: case 0xe2:
            v2 = 3;
            break;
        case 0x91:
            v2 = 3;
            if (DAT_a8027aac[c].b9 != 0)
                v2 = 2;
            break;
        case 0xe8:
            v1 = 0;
            v2 = 0;
            break;
        }
        if (DAT_a8027aac[q].b8 != 0)
            v1 &= 0xdf;
        FUN_a00f1fe0(q, 0x1e, 0x3f);
        FUN_a00f1fe0(q, 0x1f, 0x1f);
        FUN_a00f1fe0(q, 0x1c, v1);
        FUN_a00f1fe0(q, 0x1d, v2 & 0x17);
    }
    return m;
}
