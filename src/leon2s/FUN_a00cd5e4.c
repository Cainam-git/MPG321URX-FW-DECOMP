/*
 * FUN_a00cd5e4 (leon2s, 0xa00cd5e4-0xa00cdb0c, 1320 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port). Works on the 24-byte record DAT_a8078bb0[port] (word 0 bit-fields as in FUN_a00c91f8:
 * f28 = bit 28, cnt = bits 24..27, st = bits 16..17; bytes +3..+6 plain u8 members) and on the hardware
 * registers 0xcf018e00..0xcf018e28. Sets st = 1; when f28 is 0 sets st = 0 and returns. Otherwise reads two
 * bytes h with func_0xa0f96400(0, 0x90, 0x6802a, 1, h): bit 7 of h[0] sets b5 = 1, bit 3 of h[1] sets
 * b6 = 1, each followed by st = 2 and a return. Else b3 = h[0] & 0x7f, b4 = h[1] & 7, b5 = h[0] >> 7,
 * b6 = bit 3 of h[1]; writes the register set-up sequence, n = (h[0] & 0x7f) * 5,
 * FUN_a00c87e8(port, 0xb, 0x4015), then passes n bytes read in blocks of up to 15 from 0x6802c (length
 * argument rem - 1 or 14) to FUN_a00ca074(0xaa, b) and FUN_a00c7654(port, 1, b). Then the low bytes of the
 * register words 0x6350..0x6354 to FUN_a00c7654(port, 1, v); h[0], h[1], the low bytes of the register
 * words 0x637f down to 0x6378 and 0x80 to FUN_a00ca074(0xaa, v). n += 10 is written to e28 (low byte) and
 * e24 (high byte), n * 8 in two bytes to e04 (selected by e0c = 0 / 1). Then reads 16 bytes from 0x68014
 * and 4 bytes from 0x68024 into buf[0..19] and compares buf[i * 4 + 3 - j] (i = 0..4, j = 0..3) with the
 * low byte of register e04; the first difference sets st = 3, decrements cnt and returns.
 * Source forms: the length argument of the block read is a signed char (sign-extended rem - 1), with the
 * 'rem <= 14' call first; the block index is advanced as 'k++; k = k % 15;' (u8); the n += 10 byte writes
 * use (unsigned char) casts.
 */
struct Rec24 {
    unsigned int a:3;
    unsigned int f28:1;
    unsigned int cnt:4;
    unsigned int f23:1;
    unsigned int mid:5;
    unsigned int st:2;
    unsigned int x:8;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char pad[17];
};
extern struct Rec24 DAT_a8078bb0[];
extern void FUN_a00c7654(unsigned char, unsigned short, unsigned char);
extern void FUN_a00c87e8(unsigned char, unsigned char, unsigned short);
extern void FUN_a00ca074(unsigned char, unsigned char);
extern int func_0xa0f96400(int, int, int, signed char, unsigned char *);

#define R(a) (*(volatile unsigned int *)(a))

void FUN_a00cd5e4(unsigned char port)
{
    unsigned char h[2];
    unsigned char buf[20];
    unsigned short n;
    unsigned short rem;
    unsigned char k;
    unsigned char j;

    DAT_a8078bb0[port].st = 1;
    if (DAT_a8078bb0[port].f28 == 0) {
        DAT_a8078bb0[port].st = 0;
        return;
    }
    func_0xa0f96400(0, 0x90, 0x6802a, 1, h);
    if (h[0] & 0x80) {
        DAT_a8078bb0[port].b5 = 1;
        DAT_a8078bb0[port].st = 2;
        return;
    }
    if (h[1] & 8) {
        DAT_a8078bb0[port].b6 = 1;
        DAT_a8078bb0[port].st = 2;
        return;
    }
    DAT_a8078bb0[port].b3 = h[0] & 0x7f;
    DAT_a8078bb0[port].b4 = h[1] & 7;
    DAT_a8078bb0[port].b5 = h[0] >> 7;
    DAT_a8078bb0[port].b6 = (h[1] >> 3) & 1;
    R(0xcf018e10) = 0x1f;
    R(0xcf018e14) |= 0x80;
    while (R(0xcf018e14) & 0x80)
        ;
    R(0xcf018e18) &= ~1;
    R(0xcf018e00) = 0x11;
    R(0xcf018e08) = 0x10;
    R(0xcf018e0c) = 0x3f;
    R(0xcf018e14) |= 2;
    while (R(0xcf018e14) & 2)
        ;
    n = (h[0] & 0x7f) * 5;
    FUN_a00c87e8(port, 0xb, 0x4015);
    k = 0;
    rem = n;
    while (rem != 0) {
        if (k == 0) {
            if (rem <= 14)
                func_0xa0f96400(0, 0x90, 0x6802c, rem - 1, buf);
            else
                func_0xa0f96400(0, 0x90, 0x6802c, 14, buf);
        }
        FUN_a00ca074(0xaa, buf[k]);
        FUN_a00c7654(port, 1, buf[k]);
        k++;
        k = k % 15;
        rem--;
    }
    for (k = 0; k < 5; k++)
        FUN_a00c7654(port, 1, R(0xcf000000 | ((k + 0x6350) << 2)) & 0xff);
    FUN_a00ca074(0xaa, h[0]);
    FUN_a00ca074(0xaa, h[1]);
    for (k = 0; k < 8; k++)
        FUN_a00ca074(0xaa, R(0xcf000000 | ((0x637f - k) << 2)) & 0xff);
    FUN_a00ca074(0xaa, 0x80);
    n = n + 10;
    R(0xcf018e28) = (unsigned char)n;
    R(0xcf018e24) = (unsigned char)(n >> 8);
    if (R(0xcf018e0c) <= 6) {
        R(0xcf018e14) |= 1;
        while (R(0xcf018e14) & 1)
            ;
        R(0xcf018e10) = 0x1f;
        R(0xcf018e14) |= 0x80;
        while (R(0xcf018e14) & 0x80)
            ;
    }
    R(0xcf018e0c) = 0;
    R(0xcf018e04) = (n << 3) & 0xff;
    R(0xcf018e0c) = 1;
    R(0xcf018e04) = ((n << 3) >> 8) & 0xff;
    R(0xcf018e14) |= 1;
    while (R(0xcf018e14) & 1)
        ;
    R(0xcf018e10) = 0x1f;
    R(0xcf018e14) |= 0x80;
    while (R(0xcf018e14) & 0x80)
        ;
    R(0xcf018e08) = 0;
    R(0xcf018e00) = 0x22;
    func_0xa0f96400(0, 0x90, 0x68014, 0xf, buf);
    func_0xa0f96400(0, 0x90, 0x68024, 3, buf + 16);
    R(0xcf018e08) |= 0x80;
    for (k = 0; k < 5; k++)
        for (j = 0; j < 4; j++)
            if (buf[k * 4 + 3 - j] != (R(0xcf018e04) & 0xff)) {
                DAT_a8078bb0[port].st = 3;
                DAT_a8078bb0[port].cnt--;
                return;
            }
}
