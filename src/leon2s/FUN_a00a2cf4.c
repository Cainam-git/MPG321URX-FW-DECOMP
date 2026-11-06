/* FUN_a00a2cf4 (leon2s 0xa00a2cf4-0xa00a2e48, 340 bytes), flags -mcpu=v8 -Os -g.
 * (port, p2, p3): PHY page ch = 2 for port 0, 3 for port 1, other ports return 0x23. The 0x34-byte port record
 * DAT_a807db00[port] holds the register block pointer r0 in word 0. a = (r0[0x38 / 4] >> 16) shifted left by
 * DAT_a80790a8[port], b = r0[0x3c / 4], both as halfwords. When a or b is 0, *p2 = *p3 = 0. Otherwise
 * v = FUN_a00a7314(ch, 0x1f1c) (bits 0..9 integer MHz, bits 12..15 sixteenths of a MHz), the clock
 * hz = (v & 0x3ff) * 1000000 + ((v >> 12) & 0xf) * 1000000 / 16 is divided by ((r0[8 / 4] & 0xc0) >> 6) + 1,
 * multiplied by 4 when byte +4 of the 0x18-byte record DAT_a807cc64[ch] is non-zero and stored in word +0xc of
 * that record; *p2 = clock / a, *p3 = (clock / a) * 100 / b. Returns 0.
 * Source form: the clock is accumulated in the member of the zero-initialised local struct clk (fraction
 * first, then 'clk.hz = integer part + clk.hz'); the zero arm reports clk.hz. A member store is expanded
 * through a temporary and a copy, so the sum keeps the integer term as its first operand, and the initialiser
 * makes clk.hz the cse class head, so the copy becomes the add into the fraction's register (firmware
 * 'add %o0, %o4, %o4'). The register block pointer is 'volatile unsigned long *'.
 */
struct port_rec {
    volatile unsigned long *r0;
    unsigned int r4;
    unsigned char _08[0x34 - 8];
};
struct Rec24 {
    unsigned char _0[4];
    unsigned char b4;
    unsigned char _5[7];
    unsigned int w0c;
    unsigned char _10[8];
};
extern struct port_rec DAT_a807db00[];
extern unsigned char DAT_a80790a8[];
extern struct Rec24 DAT_a807cc64[];
extern unsigned int FUN_a00a7314(unsigned int, unsigned short);

unsigned int FUN_a00a2cf4(unsigned char port, unsigned int *p2, unsigned int *p3)
{
    unsigned char ch;
    unsigned short a, b;
    unsigned int v, f, q;
    struct { unsigned int hz; } clk = { 0 };

    if (port == 0)
        ch = 2;
    else if (port == 1)
        ch = 3;
    else
        return 0x23;
    a = (DAT_a807db00[port].r0[0x38 / 4] >> 16) << DAT_a80790a8[port];
    b = DAT_a807db00[port].r0[0x3c / 4];
    if (a == 0 || b == 0) {
        *p2 = clk.hz;
        *p3 = clk.hz;
    } else {
        v = FUN_a00a7314(ch, 0x1f1c);
        clk.hz = ((v >> 12) & 0xf) * 1000000 / 16;
        clk.hz = (v & 0x3ff) * 1000000 + clk.hz;
        f = clk.hz / (((DAT_a807db00[port].r0[8 / 4] & 0xc0) >> 6) + 1);
        if (DAT_a807cc64[ch].b4 != 0)
            f <<= 2;
        DAT_a807cc64[ch].w0c = f;
        q = f / a;
        *p2 = q;
        *p3 = q * 100 / b;
    }
    return 0;
}
