/* DPTX_SetBrilliantMode (leon2s 0xa0089a38-0xa0089d38, 768 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port). Returns unless byte 0 of the 8-byte record DAT_a807cd04[port] is set. clk =
 * FUN_a0089898(port); lanes = FUN_a00a78b4(port, 3) & 0xf; bpp = 0x1e when bits 5..7 of
 * FUN_a00a78b4(port, 0x66) are 0x40, 0x12 when they are 0, else 0x18. Returns when clk is 0, or when clk is
 * within 2 of DAT_a8078a10[port] and DAT_a8078a28[port] == bpp and DAT_a80761c8[port] == lanes. Otherwise stores
 * the three values there, prints them, maps FUN_a00a78b4(port, 2) to k (6: 0xa2, 0xa: 0x10e, 0x1e: 0x32a, else
 * 0x21c) and writes FUN_a00a78fc(port, 0x7e, (((clk * bpp >> 5) * lanes * 8 / k) >> 1) + 1) and
 * FUN_a00a78fc(port, 0x7c, k * lanes * 3 / (clk * 2) + 5). When FUN_a008d800() > 0x83 and port != 0:
 * FUN_a00a7940(port, 0x7c, 0x80, 1). Register 0x7b gets 0x12 when clk > 0x2bb and k == 0x21c, else 0x20 when
 * bits 0..5 of FUN_a00a78b4(port, 0x7e) are above 0x10, else (those bits + 1) * 2; then
 * FUN_a00a7940(port, 0x7b, 1, 1), the record's halfword +2 = FUN_a00b2064() and byte +1 = 1.
 * Source form: one unsigned int temporary v for the 0x66 read and both computed values; the clk distance as
 * nested ifs (a combined test folds to one unsigned range check); k is unsigned short.
 */
struct Rec8 {
    unsigned char b0;
    unsigned char b1;
    unsigned short h2;
    unsigned int w4;
};
extern struct Rec8 DAT_a807cd04[];
extern unsigned int DAT_a8078a10[];
extern unsigned char DAT_a8078a28[];
extern unsigned char DAT_a80761c8[];
extern int FUN_a0073044(const char *, ...);
extern unsigned int FUN_a0089898(unsigned char);
extern unsigned char FUN_a00a78b4(unsigned int, unsigned short);
extern void FUN_a00a78fc(unsigned char, unsigned short, unsigned char);
extern unsigned char FUN_a008d800(void);
extern void FUN_a00a7940(unsigned int, short, unsigned int, unsigned int);
extern unsigned int FUN_a00b2064(void);

void DPTX_SetBrilliantMode(unsigned char port)
{
    unsigned int clk;
    unsigned char lanes;
    unsigned char bpp;
    unsigned short k;
    int d;
    unsigned int v;

    if (DAT_a807cd04[port].b0 == 0)
        return;
    clk = FUN_a0089898(port);
    lanes = FUN_a00a78b4(port, 3) & 0xf;
    v = FUN_a00a78b4(port, 0x66) & 0xe0;
    bpp = 0x1e;
    if (v != 0x40)
        bpp = v == 0 ? 0x12 : 0x18;
    if (clk == 0)
        return;
    d = DAT_a8078a10[port] - clk;
    if (d >= -2) {
        if (d <= 2) {
            if (DAT_a8078a28[port] == bpp && DAT_a80761c8[port] == lanes)
                return;
        }
    }
    DAT_a8078a10[port] = clk;
    DAT_a8078a28[port] = bpp;
    DAT_a80761c8[port] = lanes;
    FUN_a0073044("\r\n Start DPTX_SetBrilliantMode %d  = %ld\r\n", port, clk);
    FUN_a0073044("ucbpp  = %d\r\n", bpp);
    FUN_a0073044("uclanecount  = %d\r\n", lanes);
    switch (FUN_a00a78b4(port, 2)) {
    case 6:
        k = 0xa2;
        break;
    case 0xa:
        k = 0x10e;
        break;
    case 0x14:
        k = 0x21c;
        break;
    case 0x1e:
        k = 0x32a;
        break;
    default:
        k = 0x21c;
        break;
    }
    FUN_a0073044("\r\nDPTX_SetBrilliantMode  = %ld\r\n", clk);
    v = ((clk * bpp >> 5) * lanes * 8 / k >> 1) + 1;
    FUN_a00a78fc(port, 0x7e, v);
    v = k * lanes * 3 / (clk * 2) + 5;
    FUN_a00a78fc(port, 0x7c, v);
    if (FUN_a008d800() > 0x83 && port != 0)
        FUN_a00a7940(port, 0x7c, 0x80, 1);
    if (clk > 0x2bb && k == 0x21c)
        FUN_a00a78fc(port, 0x7b, 0x12);
    else if ((FUN_a00a78b4(port, 0x7e) & 0x3f) > 0x10)
        FUN_a00a78fc(port, 0x7b, 0x20);
    else
        FUN_a00a78fc(port, 0x7b, ((FUN_a00a78b4(port, 0x7e) & 0x3f) + 1) << 1);
    FUN_a00a7940(port, 0x7b, 1, 1);
    DAT_a807cd04[port].h2 = FUN_a00b2064();
    DAT_a807cd04[port].b1 = 1;
}
