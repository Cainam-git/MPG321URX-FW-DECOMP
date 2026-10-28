/* FUN_a00cef6c (leon2s 0xa00cef6c-0xa00cf6bc, 1872 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port). Works on the 24-byte record DAT_a8078bb0[port] (layout as in FUN_a00cbb50: st = bits 16..17
 * of word 0, bytes +3..+8, word +0xc wc) and two 16-byte stack buffers b and buf. Sets st = 1, then:
 * - (u8)FUN_a00c0a04(port) != 0: st = 3, return.
 * - func_0xa0f96400(0, 0x90, 0x69493, 0, b); b[0] & 8: st = 0, return; b[0] bit 0 clear: st = 3, return.
 * - prints "\nRxstatus = %02X" with b[0]; reads 0x69493 (0) and 0x69330 (4) into b; copies b[0..4] to
 *   DAT_a807ce50. wc == 0xffffff with b[2..4] all 0, or wc == 0 with any of them non-zero: st = 0, return.
 *   wc = b[2] << 16 | b[3] << 8 | b[4] (1 if that is 0).
 * - reads 0x69335 (0xf) into buf and copies it to DAT_a807cd88[0..15]; FUN_a00c87e8(port, 0xb, 0x8000), 0xb6
 *   writes FUN_a00c7654(port, 1, 0); FUN_a00c87e8(port, 0xb, 0x8000), writes b[0..4].
 * - n = ((b[0] & 1) << 4) + (b[1] >> 4); for i < n: reads 0x69345 + i * 5 (4) into buf,
 *   FUN_a00c87e8(port, 0xb, i * 5 + 0x4015) and writes buf[0..4]. Then writes DAT_a807ce50[0..4], 0x80 to reg 1,
 *   0 to reg 2, 0xe0 to reg 6, and waits while bit 7 of FUN_a00c7770(port, 6) is set.
 * - b[1] & 0xc sets st = 2; b[0] bit 0 set and b[1] high nibble 0xf: byte +5 = 1, b[1] |= 8; else high nibble
 *   0xf: b[1] &= 0xf, b[0] |= 1; else b[1] += 0x10. (b[0] & 0xe) < 8: b[0] += 2, else byte +6 = 1, b[0] |= 4.
 *   Then byte +3 = (b[0] & 1) << 4 | b[1] >> 4, +4 = (b[0] & 0xe) >> 1, +5 |= b[1] bit 3, +6 |= b[1] bit 2,
 *   +7 = b[1] bit 0, +8 = b[1] bit 1.
 * - st != 2: st = 1, FUN_a00c87e8(port, 0xb, 0x4005), reads 16 bytes FUN_a00c7770(port, 1) into buf; the first
 *   that differs from DAT_a807cd88 sets st = 0 and returns; then 0 to reg 2.
 * - FUN_a00c87e8(port, 0xb, n * 5 + 0x4010), writes the 5 bytes of row port of DAT_a807ce38, and copies
 *   DAT_a807ce38[0][10..14] to DAT_a807cda8[10..14].
 * Source forms: the first b[1] test reads b[1] into a u8 variable with an unsigned int copy for the 0xc test;
 * the high-nibble test after b[0] bit 0 reads b[1] again (as does the else-if test), so the else-if test
 * keeps its own load. The address of the n-loop read is 'a + i * 5' with a = 0x69345 set before the loop.
 * The record bytes use b[0] directly and b[1] through a u8 with an int copy, as in FUN_a00cbb50.
 */
struct Rec24 {
    unsigned int top:4;
    unsigned int cnt:4;
    unsigned int f23:1;
    unsigned int mid:5;
    unsigned int st:2;
    unsigned int low:8;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    unsigned char b8;
    unsigned char pad9[3];
    unsigned int wc;
    unsigned char pad10[8];
};
extern struct Rec24 DAT_a8078bb0[];
extern unsigned char DAT_a807ce50[];
extern unsigned char DAT_a807cd88[];
extern unsigned char DAT_a807cda8[];
extern unsigned char DAT_a807ce38[][5];
extern const char DAT_9f1c2190[];
extern unsigned char FUN_a00c0a04(int);
extern void FUN_a00c87e8(unsigned char, unsigned char, unsigned short);
extern void FUN_a00c7654(unsigned char, unsigned short, unsigned char);
extern unsigned char FUN_a00c7770(unsigned char, unsigned short);
extern int func_0xa0f96400(int, int, int, int, unsigned char *);
extern int func_0xa0f83044(const char *, ...);

void FUN_a00cef6c(unsigned char port)
{
    unsigned char b[16];
    unsigned char buf[16];
    unsigned short i;
    unsigned short j;
    unsigned char n;
    unsigned char v;
    unsigned int w;
    unsigned int a;
    unsigned char c;
    int x;

    DAT_a8078bb0[port].st = 1;
    if ((unsigned char)FUN_a00c0a04(port) != 0) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    func_0xa0f96400(0, 0x90, 0x69493, 0, b);
    if (b[0] & 8) {
        DAT_a8078bb0[port].st = 0;
        return;
    }
    if ((b[0] & 1) == 0) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    func_0xa0f83044(DAT_9f1c2190, b[0]);
    func_0xa0f96400(0, 0x90, 0x69493, 0, b);
    func_0xa0f96400(0, 0x90, 0x69330, 4, b);
    for (i = 0; i < 5; i++)
        DAT_a807ce50[i] = b[i];
    if (DAT_a8078bb0[port].wc == 0xffffff && b[2] == 0 && b[3] == 0 && b[4] == 0) {
        DAT_a8078bb0[port].st = 0;
        return;
    }
    if (DAT_a8078bb0[port].wc == 0 && (b[2] != 0 || b[3] != 0 || b[4] != 0)) {
        DAT_a8078bb0[port].st = 0;
        return;
    }
    DAT_a8078bb0[port].wc = (b[2] << 16) | (b[3] << 8) | b[4];
    if (DAT_a8078bb0[port].wc == 0)
        DAT_a8078bb0[port].wc = 1;
    func_0xa0f96400(0, 0x90, 0x69335, 0xf, buf);
    for (i = 0; i < 16; i++)
        DAT_a807cd88[i] = buf[i];
    FUN_a00c87e8(port, 0xb, 0x8000);
    for (i = 0; i < 0xb6; i++)
        FUN_a00c7654(port, 1, 0);
    FUN_a00c87e8(port, 0xb, 0x8000);
    for (i = 0; i < 5; i++)
        FUN_a00c7654(port, 1, b[i]);
    n = ((b[0] & 1) << 4) + (b[1] >> 4);
    a = 0x69345;
    for (i = 0; i < n; i++) {
        func_0xa0f96400(0, 0x90, a + i * 5, 4, buf);
        FUN_a00c87e8(port, 0xb, i * 5 + 0x4015);
        for (j = 0; j < 5; j++)
            FUN_a00c7654(port, 1, buf[j]);
    }
    for (i = 0; i < 5; i++)
        FUN_a00c7654(port, 1, DAT_a807ce50[i]);
    FUN_a00c7654(port, 1, 0x80);
    FUN_a00c7654(port, 2, 0);
    FUN_a00c7654(port, 6, 0xe0);
    while (FUN_a00c7770(port, 6) & 0x80)
        ;
    v = b[1];
    w = v;
    if (w & 0xc)
        DAT_a8078bb0[port].st = 2;
    if ((b[0] & 1) && (b[1] & 0xf0) == 0xf0) {
        DAT_a8078bb0[port].b5 = 1;
        b[1] = v | 8;
    } else if ((b[1] & 0xf0) == 0xf0) {
        b[1] &= 0xf;
        b[0] |= 1;
    } else {
        b[1] += 0x10;
    }
    if ((b[0] & 0xe) < 8) {
        b[0] += 2;
    } else {
        DAT_a8078bb0[port].b6 = 1;
        b[0] |= 4;
    }
    c = b[1];
    x = c;
    DAT_a8078bb0[port].b3 = ((b[0] & 1) << 4) | (c >> 4);
    DAT_a8078bb0[port].b4 = (b[0] & 0xe) >> 1;
    DAT_a8078bb0[port].b5 |= (x & 8) >> 3;
    DAT_a8078bb0[port].b6 |= (x & 4) >> 2;
    DAT_a8078bb0[port].b7 = c & 1;
    DAT_a8078bb0[port].b8 = (x & 2) >> 1;
    if (DAT_a8078bb0[port].st != 2) {
        DAT_a8078bb0[port].st = 1;
        FUN_a00c87e8(port, 0xb, 0x4005);
        for (i = 0; i < 16; i++) {
            buf[i] = FUN_a00c7770(port, 1);
            if (buf[i] != DAT_a807cd88[i]) {
                DAT_a8078bb0[port].st = 0;
                return;
            }
        }
        FUN_a00c7654(port, 2, 0);
    }
    FUN_a00c87e8(port, 0xb, n * 5 + 0x4010);
    for (i = 0; i < 5; i++)
        FUN_a00c7654(port, 1, DAT_a807ce38[port][i]);
    for (i = 0; i < 5; i++)
        DAT_a807cda8[i + 10] = DAT_a807ce38[0][i + 10];
}
