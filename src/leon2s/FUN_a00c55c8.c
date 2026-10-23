/*
 * FUN_a00c55c8 (leon2s, 0xa00c55c8-0xa00c59e0, 1048 bytes), flags -mcpu=v8 -Os -g.
 * void (unsigned int port). dev = port - 4 (passed to the u8 device parameter of the ROM register calls
 * func_0xa0fb6c98 / func_0xa0fb6bb8 / func_0xa0fb6c00). Sets DAT_a807d62a = 1, sets bit 4 of register
 * 0x40e and waits until it reads back clear, writes 0x400 = 0xb, 0x403 = 0x15, 0x402 = 0x40, 0xe9 = 0xf and
 * waits until the low nibble of 0xe9 reads 0.
 * For k = 0..2 with bit k of byte +4 of the 16-byte record DAT_a807d5c8[port & 0xff] set:
 * FUN_a00c87e8(k, 0xb, 0x4015), then b3 * 5 bytes v = FUN_a00c7770(k, 1) of the 24-byte record
 * DAT_a8078bb0[k] are written to 0xe8 and 0x401; FUN_a00c87e8(k, 0, 0); then sum += b3, o5 |= b5,
 * mx = max(mx, b4), o6 |= b6, o8 |= b8, o7 |= b7, and o7 = 1 when bit 4 of byte +2 is set (all u8).
 * Then: bit 7 of sum sets o5; func_0xa0fb6c98(dev, 0x30, 0x80, 1) before and (dev, 0x30, 0x80, 0) after 0x2aa = o5 << 7 | sum and
 * 0x2ab = o6 << 3 | mx; sum > 0x1f sets o5, mx > 4 sets o6; a = mx * 2 | bit 4 of sum,
 * b = (sum & 0xf) << 4 | o5 << 3 | o6 << 2 | o8 << 1 | o7. Writes a, b, bytes 2, 1, 0 of the counter
 * DAT_a8078c60[port & 0xff], 0x80 to 0x401; 0x400 = 0xb, 0x403 = 0, 0x402 = 0x80; a, b and the three counter
 * bytes to 0x401 again; increments the counter and clears DAT_a807d62a.
 * Source forms: port is an unsigned int indexed as port & 0xff; dev is an unsigned int (the calls mask it);
 * the bit test is 'if (((mask >> k) & 1) == 0) continue;'.
 */
struct Rec24 {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    unsigned char b8;
    unsigned char pad[15];
};
struct Rec16 { unsigned char pad[4]; unsigned char mask; unsigned char pad5[11]; };
extern struct Rec24 DAT_a8078bb0[];
extern struct Rec16 DAT_a807d5c8[];
extern unsigned int DAT_a8078c60[];
extern unsigned char DAT_a807d62a;
extern void func_0xa0fb6c98(unsigned char, unsigned short, unsigned char, unsigned char);
extern unsigned char func_0xa0fb6bb8(unsigned char, unsigned short);
extern void func_0xa0fb6c00(unsigned char, unsigned short, unsigned char);
extern void FUN_a00c87e8(unsigned char, unsigned char, unsigned short);
extern unsigned char FUN_a00c7770(unsigned char, unsigned short);

void FUN_a00c55c8(unsigned int port)
{
    unsigned int dev = port - 4;
    unsigned char sum = 0;
    unsigned char mx = 0;
    unsigned char o5 = 0;
    unsigned char o6 = 0;
    unsigned char o8 = 0;
    unsigned char o7 = 0;
    unsigned char k;
    unsigned char i;
    unsigned char v;
    unsigned char a;
    unsigned char b;

    DAT_a807d62a = 1;
    func_0xa0fb6c98(dev, 0x40e, 0x10, 1);
    while (func_0xa0fb6bb8(dev, 0x40e) & 0x10)
        ;
    func_0xa0fb6c00(dev, 0x400, 0xb);
    func_0xa0fb6c00(dev, 0x403, 0x15);
    func_0xa0fb6c00(dev, 0x402, 0x40);
    func_0xa0fb6c00(dev, 0xe9, 0xf);
    while (func_0xa0fb6bb8(dev, 0xe9) & 0xf)
        ;
    for (k = 0; k < 3; k++) {
        if (((DAT_a807d5c8[port & 0xff].mask >> k) & 1) == 0)
            continue;
        FUN_a00c87e8(k, 0xb, 0x4015);
        for (i = 0; i < DAT_a8078bb0[k].b3 * 5; i++) {
            v = FUN_a00c7770(k, 1);
            func_0xa0fb6c00(dev, 0xe8, v);
            func_0xa0fb6c00(dev, 0x401, v);
        }
        FUN_a00c87e8(k, 0, 0);
        sum += DAT_a8078bb0[k].b3;
        o5 |= DAT_a8078bb0[k].b5;
        if (DAT_a8078bb0[k].b4 > mx)
            mx = DAT_a8078bb0[k].b4;
        o6 |= DAT_a8078bb0[k].b6;
        o8 |= DAT_a8078bb0[k].b8;
        o7 |= DAT_a8078bb0[k].b7;
        if (DAT_a8078bb0[k].b2 & 0x10)
            o7 = 1;
    }
    if (sum & 0x80)
        o5 = 1;
    func_0xa0fb6c98(dev, 0x30, 0x80, 1);
    func_0xa0fb6c00(dev, 0x2aa, (o5 << 7) | sum);
    func_0xa0fb6c00(dev, 0x2ab, (o6 << 3) | mx);
    func_0xa0fb6c98(dev, 0x30, 0x80, 0);
    if (sum > 0x1f)
        o5 = 1;
    if (mx > 4)
        o6 = 1;
    a = (mx * 2) | ((sum & 0x10) >> 4);
    func_0xa0fb6c00(dev, 0x401, a);
    b = ((sum & 0xf) << 4) | (o5 << 3) | (o6 << 2) | (o8 * 2) | o7;
    func_0xa0fb6c00(dev, 0x401, b);
    func_0xa0fb6c00(dev, 0x401, DAT_a8078c60[port & 0xff] >> 16);
    func_0xa0fb6c00(dev, 0x401, DAT_a8078c60[port & 0xff] >> 8);
    func_0xa0fb6c00(dev, 0x401, DAT_a8078c60[port & 0xff]);
    func_0xa0fb6c00(dev, 0x401, 0x80);
    func_0xa0fb6c00(dev, 0x400, 0xb);
    func_0xa0fb6c00(dev, 0x403, 0);
    func_0xa0fb6c00(dev, 0x402, 0x80);
    func_0xa0fb6c00(dev, 0x401, a);
    func_0xa0fb6c00(dev, 0x401, b);
    func_0xa0fb6c00(dev, 0x401, DAT_a8078c60[port & 0xff] >> 16);
    func_0xa0fb6c00(dev, 0x401, DAT_a8078c60[port & 0xff] >> 8);
    func_0xa0fb6c00(dev, 0x401, DAT_a8078c60[port & 0xff]);
    DAT_a8078c60[port & 0xff]++;
    DAT_a807d62a = 0;
}
