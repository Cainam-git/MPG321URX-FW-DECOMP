/* leon2m FUN_a00d8100 @ 0xa00d8100-0xa00d8b30 (2608 bytes), flags -mcpu=v8 -O3 -g. Callers: FUN_a00db738,
 * FUN_a00dbcf0 (arguments 0..8).
 * m = byte DAT_a802d290+0x182 when bit 11 of word +0xa8 is clear; else 1 when byte +0x181 is 0, otherwise byte
 * +0x181 + 5 (m is a byte, zero-extended at each use). Then, by the parameter byte n (0..8; other values do
 * nothing), with bit 7 of halfword DAT_a802cffe selecting the second table when set:
 *   n = 0, 1, 2, 3, 6: byte +0x09 / +0x0a / +0x19 / +0x15b / +0x49 = byte table +0x58 / +0x72 / +0x90 / +0x15c /
 *   +0x123 [m] (bit clear) or +0x65 / +0x7f / +0x9d / +0x169 / +0x130 [m] (bit set);
 *   n = 5: bits 16..19 of word +0x34 = byte table +0x1bb [m] (clear) or +0x1c8 [m] (set);
 *   n = 4: for m = 0..12 (if-chain), word +0xb0 = one word of +0xb4..+0xe4 (clear) or +0xe8..+0x118 (set);
 *   n = 7: for m = 0..12, bit 31 of word +0x11c = one of its bits 30..18 (clear) or 17..5 (set);
 *   n = 8: for m = 0..12, bit 4 of word +0x11c = one of bits 3..0 of +0x11c / 31..23 of +0x120 (clear) or bits
 *   22..10 of word +0x120 (set). The m -> word / bit assignment is listed in the code.
 * Layout: the 54 one-bit fields from +0x11c are followed directly by the byte table at +0x123.
 * Source form: the case bodies are written in the order 6, 0, 2, 1, 3, 5, 7, 8, 4 (the jump table fixes the block
 * layout; the source order decides the register names); the bit 11 test is written with the clear arm first, every
 * bit 7 test with the set arm first. Compiler aids: none.
 */
struct R290 {
    unsigned char p000[9];
    unsigned char b009;
    unsigned char b00a;
    unsigned char p00b[0x19 - 0xb];
    unsigned char b019;
    unsigned char p01a[0x34 - 0x1a];
    struct {
        unsigned int p : 12;
        unsigned int n : 4;
        unsigned int q : 16;
    } w034;
    unsigned char p038[0x49 - 0x38];
    unsigned char b049;
    unsigned char p04a[0x58 - 0x4a];
    unsigned char a058[13];
    unsigned char a065[13];
    unsigned char a072[13];
    unsigned char a07f[13];
    unsigned char p08c[0x90 - 0x8c];
    unsigned char a090[13];
    unsigned char a09d[11];
    unsigned int w0a8;
    unsigned int w0ac;
    unsigned int w0b0;
    unsigned int w0b4;
    unsigned int w0b8;
    unsigned int w0bc;
    unsigned int w0c0;
    unsigned int w0c4;
    unsigned int w0c8;
    unsigned int w0cc;
    unsigned int w0d0;
    unsigned int w0d4;
    unsigned int w0d8;
    unsigned int w0dc;
    unsigned int w0e0;
    unsigned int w0e4;
    unsigned int w0e8;
    unsigned int w0ec;
    unsigned int w0f0;
    unsigned int w0f4;
    unsigned int w0f8;
    unsigned int w0fc;
    unsigned int w100;
    unsigned int w104;
    unsigned int w108;
    unsigned int w10c;
    unsigned int w110;
    unsigned int w114;
    unsigned int w118;
    unsigned int w11c_b31 : 1;
    unsigned int w11c_b30 : 1;
    unsigned int w11c_b29 : 1;
    unsigned int w11c_b28 : 1;
    unsigned int w11c_b27 : 1;
    unsigned int w11c_b26 : 1;
    unsigned int w11c_b25 : 1;
    unsigned int w11c_b24 : 1;
    unsigned int w11c_b23 : 1;
    unsigned int w11c_b22 : 1;
    unsigned int w11c_b21 : 1;
    unsigned int w11c_b20 : 1;
    unsigned int w11c_b19 : 1;
    unsigned int w11c_b18 : 1;
    unsigned int w11c_b17 : 1;
    unsigned int w11c_b16 : 1;
    unsigned int w11c_b15 : 1;
    unsigned int w11c_b14 : 1;
    unsigned int w11c_b13 : 1;
    unsigned int w11c_b12 : 1;
    unsigned int w11c_b11 : 1;
    unsigned int w11c_b10 : 1;
    unsigned int w11c_b9 : 1;
    unsigned int w11c_b8 : 1;
    unsigned int w11c_b7 : 1;
    unsigned int w11c_b6 : 1;
    unsigned int w11c_b5 : 1;
    unsigned int w11c_b4 : 1;
    unsigned int w11c_b3 : 1;
    unsigned int w11c_b2 : 1;
    unsigned int w11c_b1 : 1;
    unsigned int w11c_b0 : 1;
    unsigned int w120_b31 : 1;
    unsigned int w120_b30 : 1;
    unsigned int w120_b29 : 1;
    unsigned int w120_b28 : 1;
    unsigned int w120_b27 : 1;
    unsigned int w120_b26 : 1;
    unsigned int w120_b25 : 1;
    unsigned int w120_b24 : 1;
    unsigned int w120_b23 : 1;
    unsigned int w120_b22 : 1;
    unsigned int w120_b21 : 1;
    unsigned int w120_b20 : 1;
    unsigned int w120_b19 : 1;
    unsigned int w120_b18 : 1;
    unsigned int w120_b17 : 1;
    unsigned int w120_b16 : 1;
    unsigned int w120_b15 : 1;
    unsigned int w120_b14 : 1;
    unsigned int w120_b13 : 1;
    unsigned int w120_b12 : 1;
    unsigned int w120_b11 : 1;
    unsigned int w120_b10 : 1;
    unsigned char a123[13];
    unsigned char a130[13];
    unsigned char p13d[0x15b - 0x13d];
    unsigned char b15b;
    unsigned char a15c[13];
    unsigned char a169[11];
    unsigned char p174[0x181 - 0x174];
    unsigned char b181;
    unsigned char b182;
    unsigned char p183[0x1bb - 0x183];
    unsigned char a1bb[13];
    unsigned char a1c8[13];
};
extern struct R290 DAT_a802d290;
extern unsigned short DAT_a802cffe;

void FUN_a00d8100(unsigned char n)
{
    unsigned char m;

    if (!(DAT_a802d290.w0a8 & 0x800))
        m = DAT_a802d290.b182;
    else if (DAT_a802d290.b181 == 0)
        m = 1;
    else
        m = DAT_a802d290.b181 + 5;
    switch (n) {
    case 6:
        if (DAT_a802cffe & 0x80)
            DAT_a802d290.b049 = DAT_a802d290.a130[m];
        else
            DAT_a802d290.b049 = DAT_a802d290.a123[m];
        break;
    case 0:
        if (DAT_a802cffe & 0x80)
            DAT_a802d290.b009 = DAT_a802d290.a065[m];
        else
            DAT_a802d290.b009 = DAT_a802d290.a058[m];
        break;
    case 2:
        if (DAT_a802cffe & 0x80)
            DAT_a802d290.b019 = DAT_a802d290.a09d[m];
        else
            DAT_a802d290.b019 = DAT_a802d290.a090[m];
        break;
    case 1:
        if (DAT_a802cffe & 0x80)
            DAT_a802d290.b00a = DAT_a802d290.a07f[m];
        else
            DAT_a802d290.b00a = DAT_a802d290.a072[m];
        break;
    case 3:
        if (DAT_a802cffe & 0x80)
            DAT_a802d290.b15b = DAT_a802d290.a169[m];
        else
            DAT_a802d290.b15b = DAT_a802d290.a15c[m];
        break;
    case 5:
        if (DAT_a802cffe & 0x80)
            DAT_a802d290.w034.n = DAT_a802d290.a1c8[m];
        else
            DAT_a802d290.w034.n = DAT_a802d290.a1bb[m];
        break;
    case 7:
        if (m == 0) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b17;
            else
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b30;
        } else if (m == 1) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b16;
            else
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b29;
        } else if (m == 2) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b15;
            else
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b28;
        } else if (m == 3) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b14;
            else
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b27;
        } else if (m == 4) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b13;
            else
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b26;
        } else if (m == 5) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b12;
            else
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b25;
        } else if (m == 6) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b10;
            else
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b23;
        } else if (m == 7) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b9;
            else
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b22;
        } else if (m == 8) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b8;
            else
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b21;
        } else if (m == 9) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b7;
            else
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b20;
        } else if (m == 10) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b6;
            else
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b19;
        } else if (m == 11) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b5;
            else
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b18;
        } else if (m == 12) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b11;
            else
                DAT_a802d290.w11c_b31 = DAT_a802d290.w11c_b24;
        }
        break;
    case 8:
        if (m == 0) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b4 = DAT_a802d290.w120_b22;
            else
                DAT_a802d290.w11c_b4 = DAT_a802d290.w11c_b3;
        } else if (m == 1) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b4 = DAT_a802d290.w120_b21;
            else
                DAT_a802d290.w11c_b4 = DAT_a802d290.w11c_b2;
        } else if (m == 2) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b4 = DAT_a802d290.w120_b20;
            else
                DAT_a802d290.w11c_b4 = DAT_a802d290.w11c_b1;
        } else if (m == 3) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b4 = DAT_a802d290.w120_b19;
            else
                DAT_a802d290.w11c_b4 = DAT_a802d290.w11c_b0;
        } else if (m == 4) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b4 = DAT_a802d290.w120_b18;
            else
                DAT_a802d290.w11c_b4 = DAT_a802d290.w120_b31;
        } else if (m == 5) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b4 = DAT_a802d290.w120_b17;
            else
                DAT_a802d290.w11c_b4 = DAT_a802d290.w120_b30;
        } else if (m == 6) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b4 = DAT_a802d290.w120_b15;
            else
                DAT_a802d290.w11c_b4 = DAT_a802d290.w120_b28;
        } else if (m == 7) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b4 = DAT_a802d290.w120_b14;
            else
                DAT_a802d290.w11c_b4 = DAT_a802d290.w120_b27;
        } else if (m == 8) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b4 = DAT_a802d290.w120_b13;
            else
                DAT_a802d290.w11c_b4 = DAT_a802d290.w120_b26;
        } else if (m == 9) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b4 = DAT_a802d290.w120_b12;
            else
                DAT_a802d290.w11c_b4 = DAT_a802d290.w120_b25;
        } else if (m == 10) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b4 = DAT_a802d290.w120_b11;
            else
                DAT_a802d290.w11c_b4 = DAT_a802d290.w120_b24;
        } else if (m == 11) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b4 = DAT_a802d290.w120_b10;
            else
                DAT_a802d290.w11c_b4 = DAT_a802d290.w120_b23;
        } else if (m == 12) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w11c_b4 = DAT_a802d290.w120_b16;
            else
                DAT_a802d290.w11c_b4 = DAT_a802d290.w120_b29;
        }
        break;
    case 4:
        if (m == 0) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w0b0 = DAT_a802d290.w0e8;
            else
                DAT_a802d290.w0b0 = DAT_a802d290.w0b4;
        } else if (m == 1) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w0b0 = DAT_a802d290.w0ec;
            else
                DAT_a802d290.w0b0 = DAT_a802d290.w0b8;
        } else if (m == 2) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w0b0 = DAT_a802d290.w0f0;
            else
                DAT_a802d290.w0b0 = DAT_a802d290.w0bc;
        } else if (m == 3) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w0b0 = DAT_a802d290.w0f4;
            else
                DAT_a802d290.w0b0 = DAT_a802d290.w0c0;
        } else if (m == 4) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w0b0 = DAT_a802d290.w0f8;
            else
                DAT_a802d290.w0b0 = DAT_a802d290.w0c4;
        } else if (m == 5) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w0b0 = DAT_a802d290.w0fc;
            else
                DAT_a802d290.w0b0 = DAT_a802d290.w0c8;
        } else if (m == 6) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w0b0 = DAT_a802d290.w104;
            else
                DAT_a802d290.w0b0 = DAT_a802d290.w0cc;
        } else if (m == 7) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w0b0 = DAT_a802d290.w108;
            else
                DAT_a802d290.w0b0 = DAT_a802d290.w0d4;
        } else if (m == 8) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w0b0 = DAT_a802d290.w10c;
            else
                DAT_a802d290.w0b0 = DAT_a802d290.w0d8;
        } else if (m == 9) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w0b0 = DAT_a802d290.w110;
            else
                DAT_a802d290.w0b0 = DAT_a802d290.w0dc;
        } else if (m == 10) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w0b0 = DAT_a802d290.w114;
            else
                DAT_a802d290.w0b0 = DAT_a802d290.w0e0;
        } else if (m == 11) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w0b0 = DAT_a802d290.w118;
            else
                DAT_a802d290.w0b0 = DAT_a802d290.w0e4;
        } else if (m == 12) {
            if (DAT_a802cffe & 0x80)
                DAT_a802d290.w0b0 = DAT_a802d290.w100;
            else
                DAT_a802d290.w0b0 = DAT_a802d290.w0d0;
        }
        break;
    }
}
