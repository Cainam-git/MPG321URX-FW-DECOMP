/* H_Total (leon2s 0xa009e00c-0xa009e368, 860 bytes), flags -mcpu=v8 -Os -g.
 * int (port, m, mode); p = port as unsigned char. DAT_a807db00 holds 0x34-byte port records whose words +0, +0x20
 * and +0x2c point to register blocks r0, r20 and r2c; DAT_a807d7e0 holds 400-byte records with a ModeInfo block at
 * +0x18 (the caller DRV_HDMI_ModeDetect_FSM_Complete passes &DAT_a807d7e0[port] + 0x18 as m).
 * Byte +0 of m = FUN_a0097ed0(p). mode == 1: halfwords +6 / +8 / +0xc / +0x10 / +0xe from bytes of r2c[3], r2c[4],
 * r2c[0x21], r2c[0x22] and r0[0x18] / r0[0x19], +0x12 = FUN_a009dfa8(p), +2 = +6 + +0xc + +0x10 + (bytes of
 * r2c[0x23] / r2c[0x22]), +4 = FUN_a009c09c(p, byte +1 of the ModeInfo block of DAT_a807d7e0[p]), byte +0x15 = 1.
 * Otherwise: halfwords +2 / +4 / +6 / +8 / +0xc / +0xe / +0x10 / +0x12 from r0[0x0e], r0[0x0f], r0[0x13],
 * r0[0x14], r0[0x16..0x19] (+2, +6, +0xc and +0x10 shifted left by DAT_a80790a8[p]), byte +0x15 = 0.
 * Then byte +0xa = FUN_a009c3bc(p), halfword +0x1c = (r20[0x15] >> 2) << DAT_a80790a8[p], byte +0x16 = bits 6..7
 * of r0[2], byte +1 = byte +1 of the ModeInfo block of DAT_a807d7e0[p]. Prints "[MODEDET]: Port%c Update ModeInfo
 * ..." (bit 2 of _DAT_a8078634). Returns 0 when +2, +4, +6 or +8 is 0 (printing "[MODEDET]: There Is Invalid
 * Value of H_Total/V_Total/DE/DE_Line!!" under the same bit) or +4 == 1, 0 when +0x12 == 0 and mode == 1, else 1.
 * Source form: the record bytes are read through the ModeInfo block member of the DAT_a807d7e0 record type (the
 * same struct type as m).
 */
struct port_rec {
    volatile unsigned int *r0;
    unsigned int _04[7];
    volatile unsigned int *r20;
    unsigned int _24[2];
    volatile unsigned int *r2c;
    unsigned int _30;
};
struct ModeInfo {
    unsigned char b0;
    unsigned char b1;
    unsigned short h2;
    unsigned short h4;
    unsigned short h6;
    unsigned short h8;
    unsigned char ba;
    unsigned char _b;
    unsigned short hc;
    unsigned short he;
    unsigned short h10;
    unsigned short h12;
    unsigned char _14;
    unsigned char b15;
    unsigned char b16;
    unsigned char _17[5];
    unsigned short h1c;
};
struct R190 {
    unsigned char _0[0x18];
    struct ModeInfo mi;
    unsigned char _x[0x190 - 0x18 - sizeof(struct ModeInfo)];
};
extern struct port_rec DAT_a807db00[];
extern struct R190 DAT_a807d7e0[];
extern unsigned char DAT_a80790a8[];
extern unsigned int _DAT_a8078634;
extern int FUN_a0073044(const char *, ...);
extern int FUN_a00734c4(const char *);
extern unsigned char FUN_a0097ed0(unsigned char);
extern unsigned short FUN_a009dfa8(unsigned char);
extern unsigned short FUN_a009c09c(unsigned char, unsigned char);
extern unsigned char FUN_a009c3bc(unsigned char);

int H_Total(unsigned int port, struct ModeInfo *m, unsigned char mode)
{
    unsigned char p = port;

    m->b0 = FUN_a0097ed0(p);
    if (mode == 1) {
        m->h6 = ((DAT_a807db00[p].r2c[3] >> 24) << 8) + (DAT_a807db00[p].r2c[4] & 0xff);
        m->h8 = (((DAT_a807db00[p].r2c[3] >> 8) & 0xff) << 8) + ((DAT_a807db00[p].r2c[3] >> 16) & 0xff);
        m->hc = (((DAT_a807db00[p].r2c[0x22] >> 16) & 0xff) << 8) + ((DAT_a807db00[p].r2c[0x22] >> 8) & 0xff);
        m->h10 = ((DAT_a807db00[p].r2c[0x22] & 0xff) << 8) + (DAT_a807db00[p].r2c[0x21] >> 24);
        m->he = ((DAT_a807db00[p].r0[0x19] & 3) << 8) | (DAT_a807db00[p].r0[0x18] >> 24);
        m->h12 = FUN_a009dfa8(p);
        m->h2 = m->h6 + m->hc + m->h10 + (((DAT_a807db00[p].r2c[0x23] & 0xff) << 8) + (DAT_a807db00[p].r2c[0x22] >> 24));

        m->h4 = FUN_a009c09c(p, DAT_a807d7e0[p].mi.b1);
        m->b15 = 1;
    } else {
        m->h2 = (DAT_a807db00[p].r0[0xe] >> 16) << DAT_a80790a8[p];
        m->h4 = DAT_a807db00[p].r0[0xf];
        m->h6 = (DAT_a807db00[p].r0[0x13] >> 16) << DAT_a80790a8[p];
        m->h8 = DAT_a807db00[p].r0[0x14];
        m->hc = (((DAT_a807db00[p].r0[0x17] & 3) << 8) | (DAT_a807db00[p].r0[0x16] >> 24)) << DAT_a80790a8[p];
        m->he = ((DAT_a807db00[p].r0[0x19] & 3) << 8) | (DAT_a807db00[p].r0[0x18] >> 24);
        m->h10 = (((DAT_a807db00[p].r0[0x16] >> 8) & 0x3ff) + 1) << DAT_a80790a8[p];
        m->h12 = ((DAT_a807db00[p].r0[0x18] >> 8) & 0x300) | ((DAT_a807db00[p].r0[0x18] >> 8) & 0xff);
        m->b15 = 0;
    }
    m->ba = FUN_a009c3bc(p);
    m->h1c = (DAT_a807db00[p].r20[0x15] >> 2) << DAT_a80790a8[p];
    m->b16 = (DAT_a807db00[p].r0[2] & 0xc0) >> 6;
    m->b1 = DAT_a807d7e0[p].mi.b1;
    if (_DAT_a8078634 & 4)
        FUN_a0073044("[MODEDET]: Port%c Update ModeInfo HDMI Mode = %d, Color Depth = %d, H_Total = %d, V_Total = %d, DE = %d, DE_Line = %d, P/I = %d\n",
                     (char)(port + 'A'), m->b0, m->b1, m->h2, m->h4, m->h6, m->h8, m->ba);
    if (m->h2 == 0 || m->h4 == 0 || m->h6 == 0 || m->h8 == 0) {
        if (_DAT_a8078634 & 4)
            FUN_a00734c4("[MODEDET]: There Is Invalid Value of H_Total/V_Total/DE/DE_Line!!");
        return 0;
    }
    if (m->h4 == 1)
        return 0;
    if (m->h12 == 0 && mode == 1)
        return 0;
    return 1;
}
