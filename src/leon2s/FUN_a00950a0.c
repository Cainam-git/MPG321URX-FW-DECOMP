/* FUN_a00950a0 (leon2s 0xa00950a0-0xa009584c, 1964 bytes), flags -mcpu=v8 -Os -g.
 * void (port, cmd). Switch on cmd 0..17 (jump table 0xa0095058) over the 28-byte record DAT_a807d580[port]
 * (word 0 flags, bytes +1/+2/+0x11/+0x15/+0x17, word +8, word +0x10 enable bits, word +0x14, halfword +0x18):
 *   0: FUN_a0094798; 1: CONV2HDMITX_UpdateInterface, HDMITX_PacketSwitch_Bypass(port, byte +0x17), FUN_a0091f14
 *   (8 when bit 30 or bit 3 of word 0 is set, else byte +0x11); 2: FUN_a0091f14 (8 when bit 3 is set), three
 *   FUN_a00a89c0 calls with byte +0x17 (byte +1 is 0xe1/0xe2) or byte +1, FUN_a0092100; 1 and 2 end with
 *   FUN_a00934c0 when bit 5 of word +0x10 is set, FUN_a00945f0, FUN_a009498c; 3: FUN_a00924dc, FUN_a0092608,
 *   FUN_a0093060, FUN_a00925e4, FUN_a009270c with 0; 4: the same with 1 by the bits of word +0x10, each followed
 *   by its " - ... Packet Enable" message (bit 3 also pulses bit 3 of register 0xcf02dc10 around
 *   FUN_a00b160c(100)); 5, 6, 8: FUN_a008ed50 / FUN_a008e7c0 / FUN_a008e958 / FUN_a008e654;
 *   7: FUN_a008e514 and FUN_a00a80cc(port, 3, 0xf2, 4, 0 / 1) by bits 30 and 4 of word 0 and FUN_a008d800() > 0x81,
 *   then FUN_a008e5ac(port, bit 4, x, y) with x = (byte +0x15 > 3), y = (byte +0x15 >= 5);
 *   9, 13, 14: FUN_a008d8e0 / FUN_a00a8184 sequences (9 also sets bit 11 and clears bit 12 of word +0x14);
 *   10: FUN_a008f270(port, word 8 * byte +0x11 / 8) and FUN_a008f450; 11: FUN_a0094e40 .. FUN_a0094a10 with
 *   DAT_a80785e8 = 0x15e when word 8 > 100, else 0xb4; 12: FUN_a0092db8, func_0x9f1cd37c, FUN_a0091f14(port, 8);
 *   15, 16: FUN_a00943d0 / FUN_a00944e0; 17: halfword +0x18 = DAT_a807954a when bit 3 of word 0 is set, else the
 *   two bytes read by FUN_a00a7fd8(port, 0, 0x63 / 0x62).
 * Source forms: old-style definition with unsigned char port and cmd (masked at every use); in case 7 the
 * bound 5 is held in the local n and y is set to 0 before 'if (b >= n) y = 1;' inside the b > 3 arm, with an
 * explicit else arm setting x and y to 0 (gives the cmp/subx store flag).
 */
struct TxRec {
    unsigned int w0;
    unsigned char b4[4];
    int w8;
    unsigned char _c[4];
    unsigned int w10;
    unsigned int w14;
    unsigned short h18;
    unsigned char _1a[2];
};
struct TxRecB {
    unsigned char b0, b1, b2;
    unsigned char _3[0x11 - 3];
    unsigned char b11;
    unsigned char _12[3];
    unsigned char b15;
    unsigned char _16;
    unsigned char b17;
    unsigned char _18[4];
};
union TxU { struct TxRec r; struct TxRecB b; };
extern union TxU DAT_a807d580[];
extern unsigned int DAT_a80785e8;
extern unsigned short DAT_a807954a;
#define REG_DC10 (*(volatile unsigned int *)0xcf02dc10)
extern void FUN_a0094798(unsigned char);
extern void CONV2HDMITX_UpdateInterface(unsigned char, union TxU *);
extern void HDMITX_PacketSwitch_Bypass(unsigned int, unsigned int);
extern void FUN_a0091f14(unsigned int, int);
extern unsigned char FUN_a00a89c0(unsigned char, unsigned char, unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a0092100(unsigned char);
extern void FUN_a00934c0(unsigned char, unsigned char);
extern void FUN_a00945f0(unsigned char);
extern void FUN_a009498c(unsigned int);
extern void FUN_a00924dc(unsigned char, unsigned char);
extern void FUN_a0092608(unsigned char, unsigned char);
extern void FUN_a0093060(unsigned char, unsigned char);
extern void FUN_a00925e4(unsigned char, unsigned char);
extern void FUN_a009270c(unsigned char, unsigned char);
extern int FUN_a00734c4(const char *);
extern void FUN_a00b160c(unsigned int);
extern void FUN_a008ed50(unsigned char, unsigned char, unsigned char);
extern void FUN_a008e7c0(unsigned char, unsigned char, unsigned char);
extern void FUN_a008e958(unsigned char, unsigned char);
extern void FUN_a008e514(unsigned char, unsigned char, unsigned char);
extern unsigned char FUN_a008d800(void);
extern void FUN_a00a80cc(unsigned int, unsigned int, short, unsigned int, unsigned int);
extern void FUN_a008e5ac(unsigned char, unsigned char, unsigned char, unsigned char);
extern void FUN_a008e654(unsigned char, unsigned char);
extern void FUN_a008e6b8(unsigned char);
extern void FUN_a0094370(unsigned char);
extern void FUN_a008d8e0(unsigned char, unsigned char);
extern void FUN_a00a8184(unsigned char, unsigned char, unsigned short, unsigned int, unsigned int);
extern void FUN_a0091b74(unsigned char);
extern void FUN_a0094f64(unsigned char);
extern void FUN_a008f270(unsigned char, int);
extern void FUN_a008f450(unsigned char, unsigned char, int);
extern void FUN_a0094e40(unsigned char, unsigned char, unsigned char);
extern void FUN_a008ecb8(unsigned char, unsigned char);
extern void FUN_a0094a50(unsigned char, unsigned char);
extern void FUN_a0094ae8(unsigned char, unsigned char);
extern void FUN_a0094b0c(unsigned char, unsigned char);
extern void FUN_a0094b30(unsigned char, unsigned int);
extern void FUN_a0094a10(unsigned char);
extern void FUN_a0092db8(unsigned char);
extern void func_0x9f1cd37c(unsigned char);
extern void FUN_a00943d0(unsigned char);
extern void FUN_a00944e0(unsigned char);
extern short FUN_a00a7fd8(unsigned int, unsigned short, unsigned short);

void FUN_a00950a0(port, cmd)
    unsigned char port, cmd;
{
    unsigned char b, x, y;
    unsigned int lo;
    unsigned int w;
    unsigned char n;

    switch (cmd) {
    case 0:
        FUN_a0094798(port);
        break;
    case 1:
        CONV2HDMITX_UpdateInterface(port, &DAT_a807d580[port]);
        HDMITX_PacketSwitch_Bypass(port, DAT_a807d580[port].b.b17);
        if (((unsigned char)(DAT_a807d580[port].r.w0 >> 30) & 1) || (DAT_a807d580[port].r.w0 & 8))
            FUN_a0091f14(port, 8);
        else
            FUN_a0091f14(port, DAT_a807d580[port].b.b11);
        if (DAT_a807d580[port].r.w10 & 0x20)
            FUN_a00934c0(port, DAT_a807d580[port].b.b2);
        FUN_a00945f0(port);
        FUN_a009498c(port);
        break;
    case 2:
        if (!(DAT_a807d580[port].r.w0 & 8))
            FUN_a0091f14(port, DAT_a807d580[port].b.b11);
        else
            FUN_a0091f14(port, 8);
        if ((unsigned char)(DAT_a807d580[port].b.b1 + 0x1f) <= 1) {
            FUN_a00a89c0(0, DAT_a807d580[port].b.b17, port, 0, 1, 0);
            FUN_a00a89c0(1, DAT_a807d580[port].b.b17, port, 0x27, 0, 0);
            FUN_a00a89c0(2, DAT_a807d580[port].b.b17, port, 0, 0, 0);
        } else {
            FUN_a00a89c0(0, DAT_a807d580[port].b.b1, port, 0, 1, 0);
            FUN_a00a89c0(1, DAT_a807d580[port].b.b1, port, 0x27, 0, 0);
            FUN_a00a89c0(2, DAT_a807d580[port].b.b1, port, 0, 0, 0);
        }
        if ((unsigned char)(DAT_a807d580[port].b.b1 + 0x1f) <= 1 &&
            (DAT_a807d580[port].b.b17 == 0x71 || DAT_a807d580[port].b.b17 == 0x81))
            FUN_a00a89c0(0, DAT_a807d580[port].b.b17, port, 0, 0, 1);
        FUN_a0092100(port);
        if (DAT_a807d580[port].r.w10 & 0x20)
            FUN_a00934c0(port, DAT_a807d580[port].b.b2);
        FUN_a00945f0(port);
        FUN_a009498c(port);
        break;
    case 3:
        FUN_a00924dc(port, 0);
        FUN_a0092608(port, 0);
        FUN_a0093060(port, 0);
        FUN_a00925e4(port, 0);
        FUN_a009270c(port, 0);
        break;
    case 4:
        FUN_a00924dc(port, 1);
        FUN_a00734c4("\033[0m\t\t - AVI Packet Enable \n");
        if (DAT_a807d580[port].r.w10 & 0x40) {
            FUN_a0092608(port, 1);
            FUN_a00734c4("\033[0m\t\t - SPD Packet Enable \n");
        }
        if (DAT_a807d580[port].r.w10 & 0x20) {
            FUN_a0093060(port, 1);
            FUN_a00734c4("\033[0m\t\t - Audio INFO Packet Enable \n");
        }
        if (DAT_a807d580[port].r.w10 & 0x10) {
            FUN_a00925e4(port, 1);
            FUN_a00734c4("\033[0m\t\t - MPEG Packet Enable \n");
        }
        if (DAT_a807d580[port].r.w10 & 8) {
            REG_DC10 |= 8;
            FUN_a00b160c(100);
            REG_DC10 &= ~8;
            FUN_a009270c(port, 1);
            FUN_a00734c4("\033[0m\t\t - PPS Packet Enable \n");
        }
        break;
    case 5:
        FUN_a008ed50(port, DAT_a807d580[port].b.b1, DAT_a807d580[port].r.w0 & 1);
        break;
    case 6:
        FUN_a008ed50(port, DAT_a807d580[port].b.b1, 0);
        FUN_a008e7c0(port, DAT_a807d580[port].b.b1, 0);
        FUN_a008e958(port, DAT_a807d580[port].b.b15);
        break;
    case 7:
        w = DAT_a807d580[port].r.w0;
        if (!((unsigned char)(w >> 30) & 1)) {
            FUN_a008e514(port, (w >> 4) & 1, DAT_a807d580[port].b.b11);
            if (FUN_a008d800() > 0x81)
                FUN_a00a80cc(port, 3, 0xf2, 4, 0);
        } else {
            if (((unsigned char)(w >> 4) & 1) && FUN_a008d800() > 0x81)
                FUN_a00a80cc(port, 3, 0xf2, 4, 1);
            else
                FUN_a00a80cc(port, 3, 0xf2, 4, 0);
            FUN_a008e514(port, (DAT_a807d580[port].r.w0 >> 4) & 1, 8);
        }
        b = DAT_a807d580[port].b.b15;
        n = 5;
        if (b > 3) {
            x = 1;
            y = 0;
            if (b >= n)
                y = 1;
        } else {
            x = 0;
            y = 0;
        }
        FUN_a008e5ac(port, (DAT_a807d580[port].r.w0 >> 4) & 1, x & 1, y & 1);
        break;
    case 8:
        FUN_a008e654(port, (DAT_a807d580[port].r.w0 >> 4) & 1);
        break;
    case 9:
        FUN_a008e6b8(port);
        FUN_a0094370(port);
        FUN_a008d8e0(port, 0);
        FUN_a00a8184(port, 1, 0xd, 0xf8, 0);
        FUN_a0091b74(port);
        DAT_a807d580[port].r.w14 = (DAT_a807d580[port].r.w14 | 0x800) & ~0x1000;
        break;
    case 10:
        FUN_a0094f64(port);
        FUN_a008f270(port, DAT_a807d580[port].r.w8 * DAT_a807d580[port].b.b11 / 8);
        FUN_a008f450(port, DAT_a807d580[port].b.b11, DAT_a807d580[port].r.w8);
        break;
    case 11:
        FUN_a0094e40(port, DAT_a807d580[port].b.b15, (DAT_a807d580[port].r.w0 >> 3) & 1);
        FUN_a008ecb8(port, DAT_a807d580[port].b.b15);
        FUN_a0094a50(port, (DAT_a807d580[port].r.w0 >> 30) & 1);
        FUN_a0094ae8(port, 1);
        FUN_a0094b0c(port, 1);
        if (DAT_a807d580[port].r.w8 > 100)
            DAT_a80785e8 = 0x15e;
        else
            DAT_a80785e8 = 0xb4;
        FUN_a0094b30(port, DAT_a80785e8);
        FUN_a0094a10(port);
        break;
    case 12:
        FUN_a0092db8(port);
        func_0x9f1cd37c(port);
        FUN_a0091f14(port, 8);
        break;
    case 13:
        FUN_a008d8e0(port, 1);
        FUN_a00a8184(port, 1, 0xd, 0xf8, 0xf8);
        break;
    case 14:
        FUN_a008d8e0(port, 0);
        FUN_a00a8184(port, 1, 0xd, 0xf8, 0);
        break;
    case 15:
        FUN_a00943d0(port);
        break;
    case 16:
        FUN_a00944e0(port);
        break;
    case 17:
        if (DAT_a807d580[port].r.w0 & 8) {
            DAT_a807d580[port].r.h18 = DAT_a807954a;
        } else {
            lo = (unsigned char)FUN_a00a7fd8(port, 0, 0x62);
            DAT_a807d580[port].r.h18 = ((unsigned char)FUN_a00a7fd8(port, 0, 0x63) << 8) + lo;
        }
        break;
    }
}
