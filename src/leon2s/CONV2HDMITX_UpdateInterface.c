/* CONV2HDMITX_UpdateInterface (leon2s 0xa00a94f4-0xa00a9870, 892 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port, record p). Clears the 19-byte stack packet pkt with FUN_a00b15ac; in[4] = 0. type = byte 1 of
 * p, or byte 0x17 (alt = 1) when byte 1 is 0xe1 or 0xe2. Types 0x31/0x41 (a = 0/1): bit 5 of p's word 0 =
 * FUN_a0090f28(a), byte 0x11 = FUN_a0090f44(a), bit 7 = FUN_a0090f60(a), bit 6 = FUN_a0090f7c(a), word 8 =
 * FUN_a0090f98(a); then FUN_a00924dc(port, 0). Types 0x51/0x61 (b = 0/1): the same with FUN_a00a26e0,
 * FUN_a00a26fc, FUN_a00a2718, FUN_a00a2734, and word 8 = FUN_a00a2750(b) / 10 only when alt is 0. Types
 * 0x71/0x81 (c = 0/1): bit 5 = 1, byte 0x11 = FUN_a00b03e4(c), bit 7 = FUN_a00b0400(c), bit 6 = FUN_a00b041c(c),
 * word 8 = FUN_a00b0438(c) * FUN_a00b03e4(c) >> 3, in[0..3] = FUN_a00b0374/FUN_a00b0390/FUN_a00b03ac/
 * FUN_a00b03c8(c), FUN_a00a9020(FUN_a00b0438(c), in, pkt) and FUN_a00925b8(port, pkt). Other types print
 * s_a006c3d8 ("CONV2HDMITX_UpdateInterface NOT support this input!!!") with FUN_a00734c4. Finally clears bytes
 * g3b, g2b and g0b of DAT_a8079290.r[port].
 * Source forms the exact build depends on: type assigned in both arms of the e1/e2 test, which reads byte 1
 * itself; a, b, c set by a first switch whose default arm clears all three, then a second switch on type;
 * in[] declared and zero-initialised after the FUN_a00b15ac call; the final clears in the order g2b, g0b, g3b.
 */
struct Iface {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned int f7 : 1;
    unsigned int f6 : 1;
    unsigned int f5 : 1;
    unsigned int f0 : 5;
    unsigned int w4;
    unsigned int w8;
    unsigned char pad[5];
    unsigned char b11;
    unsigned char pad2[5];
    unsigned char b17;
};
struct Rec12 {
    unsigned char g0a, g0b, g0c;
    unsigned char g1a, g1b, g1c;
    unsigned char g2a, g2b, g2c;
    unsigned char g3a, g3b, g3c;
};
struct PktState {
    unsigned char pad[6];
    struct Rec12 r[4];
};
extern struct PktState DAT_a8079290;
extern const char s_a006c3d8[];
extern void *FUN_a00b15ac(void *, int, unsigned int);
extern int FUN_a00734c4(const char *);
extern unsigned char FUN_a0090f28(unsigned int);
extern unsigned char FUN_a0090f44(unsigned int);
extern unsigned char FUN_a0090f60(unsigned int);
extern unsigned char FUN_a0090f7c(unsigned int);
extern unsigned short FUN_a0090f98(unsigned int);
extern unsigned char FUN_a00a26e0(unsigned int);
extern unsigned char FUN_a00a26fc(unsigned int);
extern unsigned char FUN_a00a2718(unsigned int);
extern unsigned char FUN_a00a2734(unsigned int);
extern unsigned short FUN_a00a2750(unsigned int);
extern unsigned char FUN_a00b03e4(unsigned int);
extern unsigned char FUN_a00b0400(unsigned int);
extern unsigned char FUN_a00b041c(unsigned int);
extern unsigned int FUN_a00b0438(unsigned int);
extern unsigned char FUN_a00b0374(unsigned int);
extern unsigned char FUN_a00b0390(unsigned int);
extern unsigned char FUN_a00b03ac(unsigned int);
extern unsigned char FUN_a00b03c8(unsigned int);
extern void FUN_a00a9020(unsigned int, unsigned char *, unsigned char *);
extern void FUN_a00924dc(unsigned char, unsigned char);
extern void FUN_a00925b8(unsigned char, unsigned char *);

void CONV2HDMITX_UpdateInterface(unsigned char port, struct Iface *p)
{
    unsigned char pkt[19];
    unsigned char type;
    unsigned char alt;
    unsigned char a, b, c;
    unsigned short v;
    unsigned int t;

    FUN_a00b15ac(pkt, 0, 0x13);
    unsigned char in[4] = {0, 0, 0, 0};
    alt = 0;
    if ((unsigned char)(p->b1 - 0xe1) < 2) {
        type = p->b17;
        alt = 1;
    } else
        type = p->b1;
    switch (type) {
    case 0x31:
        a = 0;
        break;
    case 0x41:
        a = 1;
        break;
    case 0x51:
        b = 0;
        break;
    case 0x61:
        b = 1;
        break;
    case 0x71:
        c = 0;
        break;
    case 0x81:
        c = 1;
        break;
    default:
        a = 0;
        b = 0;
        c = 0;
        break;
    }
    switch (type) {
    case 0x31:
    case 0x41:
        p->f5 = FUN_a0090f28(a);
        p->b11 = FUN_a0090f44(a);
        p->f7 = FUN_a0090f60(a);
        p->f6 = FUN_a0090f7c(a);
        v = FUN_a0090f98(a);
        p->w8 = v;
        FUN_a00924dc(port, 0);
        break;
    case 0x51:
    case 0x61:
        p->f5 = FUN_a00a26e0(b);
        p->b11 = FUN_a00a26fc(b);
        p->f7 = FUN_a00a2718(b);
        p->f6 = FUN_a00a2734(b);
        if (!alt) {
            v = FUN_a00a2750(b) / 10;
            p->w8 = v;
        }
        FUN_a00924dc(port, 0);
        break;
    case 0x71:
    case 0x81:
        p->f5 = 1;
        p->b11 = FUN_a00b03e4(c);
        p->f7 = FUN_a00b0400(c);
        p->f6 = FUN_a00b041c(c);
        t = FUN_a00b0438(c);
        p->w8 = t * FUN_a00b03e4(c) >> 3;
        in[0] = FUN_a00b0374(c);
        in[1] = FUN_a00b0390(c);
        in[2] = FUN_a00b03ac(c);
        in[3] = FUN_a00b03c8(c);
        FUN_a00a9020(FUN_a00b0438(c), in, pkt);
        FUN_a00925b8(port, pkt);
        break;
    default:
        FUN_a00734c4(s_a006c3d8);
        break;
    }
    DAT_a8079290.r[port].g2b = 0;
    DAT_a8079290.r[port].g0b = 0;
    DAT_a8079290.r[port].g3b = 0;
}
