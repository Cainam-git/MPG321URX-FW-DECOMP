/* leon2s FUN_a00abbc4 @ 0xa00abbc4-0xa00abe20, -mcpu=v8 -Os -g.
 * (u8 port), void. With r = the 0x12c-byte record ARR_a807dc18[port], writes through FUN_a00a6c00 (port, reg, v)
 * and FUN_a00a6c98: 0x3b0 = 0x14; 0x3b1 = 0x1e / 0x14 / 10 / 6 for byte +0x110 = 3 / 2 / 1 / other; 0x3b2 =
 * 0xc4 / 0xc2 / 0xc1 for byte +0x111 = 2 / 1 / other; 0x3b3 = 0x81 when byte +0x110 is 3, else 1; 0x3b4 = 1,
 * 0x3b6 = 1, FUN_a00a6c98(port, 0x3ba, 4, 1), 0x3bd = 0. For port 0 with byte +0x112 set: 0x3b5 = 1,
 * 0x3b7 = 0x81, 0x3b8 = 0, 0x3b9 = 0, 0x3ba = 4, 0x3bb = 0. Byte +0x115 set: FUN_a00a6c98(port, 0x3b7, 0x40, 1);
 * byte +0x123 set: 0x3c0 = 0xf0, 0x3c2 = 0x10, 0x3c3 = 0x10; byte +0x124 set: 0x3c4 = 1 (tail call).
 * Called by FUN_a00abe20. Source form: each arm holds its complete call (as in FUN_a00abe20).
 */
struct Port {
    unsigned char pad[0x110];
    unsigned char b110;
    unsigned char b111;
    unsigned char b112;
    unsigned char pad113[2];
    unsigned char b115;
    unsigned char pad116[0x123 - 0x116];
    unsigned char b123;
    unsigned char b124;
    unsigned char rest[0x12c - 0x125];
};
extern struct Port ARR_a807dc18[];
extern void FUN_a00a6c98(unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a00a6c00(unsigned char, unsigned short, unsigned char);

void FUN_a00abbc4(unsigned char port)
{
    FUN_a00a6c00(port, 0x3b0, 0x14);
    if (ARR_a807dc18[port].b110 == 3)
        FUN_a00a6c00(port, 0x3b1, 0x1e);
    else if (ARR_a807dc18[port].b110 == 2)
        FUN_a00a6c00(port, 0x3b1, 0x14);
    else if (ARR_a807dc18[port].b110 == 1)
        FUN_a00a6c00(port, 0x3b1, 10);
    else
        FUN_a00a6c00(port, 0x3b1, 6);
    if (ARR_a807dc18[port].b111 == 2)
        FUN_a00a6c00(port, 0x3b2, 0xc4);
    else if (ARR_a807dc18[port].b111 == 1)
        FUN_a00a6c00(port, 0x3b2, 0xc2);
    else
        FUN_a00a6c00(port, 0x3b2, 0xc1);
    if (ARR_a807dc18[port].b110 == 3)
        FUN_a00a6c00(port, 0x3b3, 0x81);
    else
        FUN_a00a6c00(port, 0x3b3, 1);
    FUN_a00a6c00(port, 0x3b4, 1);
    FUN_a00a6c00(port, 0x3b6, 1);
    FUN_a00a6c98(port, 0x3ba, 4, 1);
    FUN_a00a6c00(port, 0x3bd, 0);
    if (port == 0 && ARR_a807dc18[port].b112 != 0) {
        FUN_a00a6c00(port, 0x3b5, 1);
        FUN_a00a6c00(port, 0x3b7, 0x81);
        FUN_a00a6c00(port, 0x3b8, 0);
        FUN_a00a6c00(port, 0x3b9, 0);
        FUN_a00a6c00(port, 0x3ba, 4);
        FUN_a00a6c00(port, 0x3bb, 0);
    }
    if (ARR_a807dc18[port].b115 != 0)
        FUN_a00a6c98(port, 0x3b7, 0x40, 1);
    if (ARR_a807dc18[port].b123 != 0) {
        FUN_a00a6c00(port, 0x3c0, 0xf0);
        FUN_a00a6c00(port, 0x3c2, 0x10);
        FUN_a00a6c00(port, 0x3c3, 0x10);
    }
    if (ARR_a807dc18[port].b124 != 0)
        FUN_a00a6c00(port, 0x3c4, 1);
}
