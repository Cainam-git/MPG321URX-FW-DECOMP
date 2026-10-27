/* FUN_a00c4e70 (leon2s 0xa00c4e70-0xa00c55c8, 1880 bytes), flags -mcpu=v8 -Os -g.
 * u8 port, void; called by FUN_a00c601c. Register access: func_0xa0fb7dd0(port, reg, v) write,
 * func_0xa0fb7e14(port, reg, mask, on), func_0xa0fb7e98 / func_0xa0fb657c reads (low byte), func_0xa0fb67b8 and
 * func_0xa0fb65c4 for ports 0, 1. Sets bit 6 of 0x88 and bit 4 of 0x37, DAT_a807d62a = 1. Ports 0, 1: sets bit 3
 * of 0x305 and waits until it reads back clear; then 0x2e to 0x310, bit 7 of 0x310 set, 5 to 0x311, bit 7 of
 * 0x310 cleared. Other ports: window writes 0xa6/0xa4/0xa5 = 9/0/1, bit 3 of 0xa7 set, then 0x21 to 0xa5 until
 * bit 3 of 0xa7 reads clear; 0x50 to 0xa6, 0 to 0xa4.
 * For i = 0..2 with bit i of byte +4 of DAT_a807d5c8[port]: the 0x18-byte record DAT_a8078bb0[i] (bytes +2..+8):
 * fa = 1 when byte +5 is set, fb = 1 when byte +6 is set; with both clear: FUN_a00c87e8(i, 0xb, 0x4005), then
 * byte +3 * 5 values v = FUN_a00c7770(i, 1) written to 0x38 and to 0x312 (ports 0, 1) or with index j + 5 to
 * 0xa5 / 0xa7, FUN_a00c87e8(i, 0, 0); sum += byte +3, fa |= byte +5, max = largest byte +4, fb |= byte +6,
 * fc |= byte +8, fd |= byte +7, fd = 1 when bit 4 of byte +2 is set.
 * DAT_a8078c78 = sum; fa = 1 when sum > 0x7f; 0x2f = fa << 7 | sum, 0x30 = fb << 3 | max, 0x33 = 0x34 = 0,
 * 0x35 = sum * 5 (low byte), 0x36 = sum * 5 >> 8; fa = 1 when sum > 0x1f, fb = 1 when max > 4. Then the bytes
 * max << 1 | bit 4 of sum, (sum & 0xf) << 4 | fa << 3 | fb << 2 | fc << 1 | fd, bits 16..23, 8..15 and 0..7 of
 * the counter DAT_a8078c60[port] are written twice: ports 0, 1 to 0x312 (with 0x80 to 0x312 and 0x2e to 0x310
 * between), other ports through the window 0xa5 (index idx + 1.. idx + 6 with 0x80 last, then 0..4) / 0xa7,
 * then 0x20 to 0xa4. The counter is incremented, bit 4 of 0x37 and bit 6 of 0x88 are cleared.
 * Source forms: the window index is advanced with 'idx++;' statements before each write; the 0x35 value and
 * the two bytes use (unsigned char)sum; the reads are declared with unsigned char results.
 */
struct rec16 { unsigned char _0[4]; unsigned char b4; unsigned char _5[11]; };
struct rec24 { unsigned char _0[2]; unsigned char b2, b3, b4, b5, b6, b7, b8; unsigned char _9[15]; };
extern struct rec16 DAT_a807d5c8[];
extern struct rec24 DAT_a8078bb0[];
extern unsigned int DAT_a8078c60[];
extern unsigned char DAT_a807d62a;
extern unsigned char DAT_a8078c78;
extern void func_0xa0fb7dd0(unsigned char, unsigned short, unsigned char);
extern void func_0xa0fb7e14(unsigned char, unsigned short, unsigned char, unsigned char);
extern unsigned char func_0xa0fb7e98(unsigned char, unsigned short);
extern void func_0xa0fb67b8(unsigned char, unsigned short, unsigned int, unsigned char);
extern unsigned char func_0xa0fb657c(unsigned char, unsigned short);
extern void func_0xa0fb65c4(unsigned char, unsigned short, unsigned char);
extern void FUN_a00c87e8(unsigned char, unsigned char, unsigned short);
extern unsigned char FUN_a00c7770(unsigned char, unsigned short);

void FUN_a00c4e70(unsigned char port)
{
    unsigned char i, idx, max, fa, fb, fc, fd, v;
    unsigned short sum, j;

    func_0xa0fb7e14(port, 0x88, 0x40, 1);
    func_0xa0fb7e14(port, 0x37, 0x10, 1);
    DAT_a807d62a = 1;
    idx = 0;
    sum = 0;
    max = 0;
    fa = 0;
    fb = 0;
    fc = 0;
    fd = 0;
    if (port < 2) {
        func_0xa0fb67b8(port, 0x305, 8, 1);
        while (func_0xa0fb657c(port, 0x305) & 8)
            ;
    } else {
        func_0xa0fb7dd0(port, 0xa6, 9);
        func_0xa0fb7dd0(port, 0xa4, 0);
        func_0xa0fb7dd0(port, 0xa5, 1);
        func_0xa0fb7e14(port, 0xa7, 8, 1);
        do
            func_0xa0fb7dd0(port, 0xa5, 0x21);
        while (func_0xa0fb7e98(port, 0xa7) & 8);
    }
    if (port < 2) {
        func_0xa0fb65c4(port, 0x310, 0x2e);
        func_0xa0fb67b8(port, 0x310, 0x80, 1);
        func_0xa0fb65c4(port, 0x311, 5);
        func_0xa0fb67b8(port, 0x310, 0x80, 0);
    } else {
        func_0xa0fb7dd0(port, 0xa6, 0x50);
        func_0xa0fb7dd0(port, 0xa4, 0);
    }
    for (i = 0; i < 3; i++) {
        if ((DAT_a807d5c8[port].b4 >> i) & 1) {
            if (DAT_a8078bb0[i].b5 != 0)
                fa = 1;
            if (DAT_a8078bb0[i].b6 != 0)
                fb = 1;
            if (fa == 0 && fb == 0) {
                FUN_a00c87e8(i, 0xb, 0x4005);
                for (j = 0; j < DAT_a8078bb0[i].b3 * 5; j++) {
                    v = FUN_a00c7770(i, 1);
                    func_0xa0fb7dd0(port, 0x38, v);
                    if (port < 2) {
                        func_0xa0fb7dd0(port, 0x312, v);
                    } else {
                        idx = j + 5;
                        func_0xa0fb7dd0(port, 0xa5, idx);
                        func_0xa0fb7dd0(port, 0xa7, v);
                    }
                }
                FUN_a00c87e8(i, 0, 0);
                sum += DAT_a8078bb0[i].b3;
                fa |= DAT_a8078bb0[i].b5;
                if (DAT_a8078bb0[i].b4 > max)
                    max = DAT_a8078bb0[i].b4;
                fb |= DAT_a8078bb0[i].b6;
                fc |= DAT_a8078bb0[i].b8;
                fd |= DAT_a8078bb0[i].b7;
                if (DAT_a8078bb0[i].b2 & 0x10)
                    fd = 1;
            }
        }
    }
    DAT_a8078c78 = sum;
    if (sum > 0x7f)
        fa = 1;
    func_0xa0fb7dd0(port, 0x2f, (fa << 7) | sum);
    func_0xa0fb7dd0(port, 0x30, (fb << 3) | max);
    func_0xa0fb7dd0(port, 0x33, 0);
    func_0xa0fb7dd0(port, 0x34, 0);
    func_0xa0fb7dd0(port, 0x35, (unsigned char)sum * 5);
    func_0xa0fb7dd0(port, 0x36, (sum * 5) >> 8);
    if (sum > 0x1f)
        fa = 1;
    if (max > 4)
        fb = 1;
    if (port < 2) {
        func_0xa0fb7dd0(port, 0x312, (max << 1) | (((unsigned char)sum & 0x10) >> 4));
        func_0xa0fb7dd0(port, 0x312, (((unsigned char)sum & 0xf) << 4) | (fa << 3) | (fb << 2) | (fc << 1) | fd);
        func_0xa0fb7dd0(port, 0x312, DAT_a8078c60[port] >> 16);
        func_0xa0fb7dd0(port, 0x312, DAT_a8078c60[port] >> 8);
        func_0xa0fb7dd0(port, 0x312, DAT_a8078c60[port]);
        func_0xa0fb7dd0(port, 0x312, 0x80);
        func_0xa0fb7dd0(port, 0x310, 0x2e);
        func_0xa0fb7dd0(port, 0x312, (max << 1) | (((unsigned char)sum & 0x10) >> 4));
        func_0xa0fb7dd0(port, 0x312, (((unsigned char)sum & 0xf) << 4) | (fa << 3) | (fb << 2) | (fc << 1) | fd);
        func_0xa0fb7dd0(port, 0x312, DAT_a8078c60[port] >> 16);
        func_0xa0fb7dd0(port, 0x312, DAT_a8078c60[port] >> 8);
        func_0xa0fb7dd0(port, 0x312, DAT_a8078c60[port]);
    } else {
        idx++;
        func_0xa0fb7dd0(port, 0xa5, idx);
        func_0xa0fb7dd0(port, 0xa7, (max << 1) | (((unsigned char)sum & 0x10) >> 4));
        idx++;
        func_0xa0fb7dd0(port, 0xa5, idx);
        func_0xa0fb7dd0(port, 0xa7, (((unsigned char)sum & 0xf) << 4) | (fa << 3) | (fb << 2) | (fc << 1) | fd);
        idx++;
        func_0xa0fb7dd0(port, 0xa5, idx);
        func_0xa0fb7dd0(port, 0xa7, DAT_a8078c60[port] >> 16);
        idx++;
        func_0xa0fb7dd0(port, 0xa5, idx);
        func_0xa0fb7dd0(port, 0xa7, DAT_a8078c60[port] >> 8);
        idx++;
        func_0xa0fb7dd0(port, 0xa5, idx);
        func_0xa0fb7dd0(port, 0xa7, DAT_a8078c60[port]);
        idx++;
        func_0xa0fb7dd0(port, 0xa5, idx);
        func_0xa0fb7dd0(port, 0xa7, 0x80);
        func_0xa0fb7dd0(port, 0xa5, 0);
        func_0xa0fb7dd0(port, 0xa7, (max << 1) | (((unsigned char)sum & 0x10) >> 4));
        func_0xa0fb7dd0(port, 0xa5, 1);
        func_0xa0fb7dd0(port, 0xa7, (((unsigned char)sum & 0xf) << 4) | (fa << 3) | (fb << 2) | (fc << 1) | fd);
        func_0xa0fb7dd0(port, 0xa5, 2);
        func_0xa0fb7dd0(port, 0xa7, DAT_a8078c60[port] >> 16);
        func_0xa0fb7dd0(port, 0xa5, 3);
        func_0xa0fb7dd0(port, 0xa7, DAT_a8078c60[port] >> 8);
        func_0xa0fb7dd0(port, 0xa5, 4);
        func_0xa0fb7dd0(port, 0xa7, DAT_a8078c60[port]);
        func_0xa0fb7dd0(port, 0xa4, 0x20);
    }
    DAT_a8078c60[port]++;
    func_0xa0fb7e14(port, 0x37, 0x10, 0);
    func_0xa0fb7e14(port, 0x88, 0x40, 0);
}
