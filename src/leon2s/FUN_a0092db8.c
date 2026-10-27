/* leon2s FUN_a0092db8 @ 0xa0092db8-0xa0093034 (159 words), flags -mcpu=v8 -Os -g.
 * void (u8 port). Stack buffer s[0x80] (fp-136): bytes 0..0x5f are the 24 words DAT_a807955c[] split
 * most significant byte first, bytes 0x60..0x7f are cleared. q = ((s[14] << 8) + s[15]) (u16) / 3.
 * Halfwords h[3] (fp-144): h[0] = total - a - c - d, h[1] = c, h[2] = d, from the halfwords +8, +0xa, +0xc,
 * +0xe of DAT_a8079538. Stack block m (fp-312): m[0..9] = 7f 80 00 06 00 01 00 02 00 88, m[10..30] = s[0..20];
 * then four groups 0x7f, 0, n (n = 1..4) followed by s[21..48], s[49..76], s[77..104] (28 bytes each) and
 * s[105..127] (23 bytes); m[150..160] = h[0], h[1], h[2] (low byte first), 0x7f, 0x40, 5, h[2] high byte,
 * q (low byte first). Then FUN_a0092944(port, m).
 * Source form: q is computed right after s is filled; the independent byte and halfword stores are written
 * in the order the firmware schedules them.
 */
struct Rec538 {
    unsigned char b[8];
    unsigned short total;
    unsigned short a;
    unsigned short c;
    unsigned short d;
};
extern struct Rec538 DAT_a8079538;
extern unsigned int DAT_a807955c[];
extern void FUN_a0092944(unsigned char port, unsigned char *p);

void FUN_a0092db8(unsigned char port)
{
    unsigned char s[0x80];
    unsigned short h[3];
    unsigned char m[168];
    unsigned char i;
    unsigned short v;
    unsigned short q;

    for (i = 0; i < 0x18; i++) {
        s[i * 4] = DAT_a807955c[i] >> 24;
        s[i * 4 + 1] = DAT_a807955c[i] >> 16;
        s[i * 4 + 2] = DAT_a807955c[i] >> 8;
        s[i * 4 + 3] = DAT_a807955c[i];
    }
    for (i = 0x60; i < 0x80; i++)
        s[i] = 0;
    v = (s[14] << 8) + s[15];
    q = v / 3;
    m[2] = 0;
    h[0] = DAT_a8079538.total - DAT_a8079538.a - DAT_a8079538.c - DAT_a8079538.d;
    m[0] = 0x7f;
    m[4] = 0;
    m[1] = 0x80;
    m[3] = 6;
    h[1] = DAT_a8079538.c;
    h[2] = DAT_a8079538.d;
    m[6] = 0;
    m[8] = 0;
    m[5] = 1;
    m[7] = 2;
    m[9] = 0x88;
    for (i = 0; i < 21; i++)
        m[10 + i] = s[i];
    m[31] = 0x7f;
    m[33] = 1;
    m[32] = 0;
    for (i = 0; i < 28; i++)
        m[34 + i] = s[21 + i];
    m[62] = 0x7f;
    m[64] = 2;
    m[63] = 0;
    for (i = 0; i < 28; i++)
        m[65 + i] = s[49 + i];
    m[93] = 0x7f;
    m[95] = 3;
    m[94] = 0;
    for (i = 0; i < 28; i++)
        m[96 + i] = s[77 + i];
    m[124] = 0x7f;
    m[126] = 4;
    m[125] = 0;
    for (i = 0; i < 23; i++)
        m[127 + i] = s[105 + i];
    m[150] = h[0];
    m[151] = h[0] >> 8;
    m[155] = 0x7f;
    m[152] = h[1];
    m[153] = h[1] >> 8;
    m[156] = 0x40;
    m[154] = h[2];
    m[159] = q;
    m[157] = 5;
    m[158] = h[2] >> 8;
    m[160] = q >> 8;
    FUN_a0092944(port, m);
}
