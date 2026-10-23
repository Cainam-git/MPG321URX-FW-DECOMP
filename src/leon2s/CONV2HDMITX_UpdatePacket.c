/*
 * CONV2HDMITX_UpdatePacket (leon2s, 0xa00a9870-0xa00a9c4c, 988 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port, u8 type). Clears three stack packets with FUN_a00b15ac (0x1f, 0xe, 0xe bytes);
 * sel = 1 for type 0x81, else 0.
 * - type 0x31, 0x41, 0x51, 0x61: FUN_a0093060(port, 0), FUN_a0092608(port, 0), FUN_a009270c(port, 0).
 * - type 0x71, 0x81: updates the four 3-byte groups (a, b, c) of the 12-byte record DAT_a8079290.r[port]
 *   (records from byte 6) from the getters FUN_a00b0248..FUN_a00b0340(sel) (b fields or-ed, a and c
 *   replaced). Group 0: c == 0, a == 1, b == 1 builds a packet with FUN_a00a8ec4(FUN_a00b02f0(sel), pkt0)
 *   and passes it to FUN_a00926e0(port, pkt0); c == 0, a == 0 calls FUN_a0092608(port, 0); both clear b.
 *   Group 2: the same with FUN_a00b035c / FUN_a00a8f28 / FUN_a0093138 and FUN_a0093060; otherwise group 3
 *   with c == 0, a == 0 calls FUN_a009270c(port, 0) and clears its b. Group 1: c == 0, a == 1, b == 1
 *   calls FUN_a0092890(port, 0); c == 0, a == 0 builds FUN_a00a9380(FUN_a00b048c(sel & 1), pkt2) and passes
 *   it to FUN_a0093034(port, pkt2); both clear b.
 * - other types: FUN_a00734c4(s_a006c410), the firmware string
 *   "CONV2HDMITX_UpdatePacket NOT support this input!!!\r".
 * Source forms: sel is set by its own two-case switch before the type switch.
 */
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
extern const char s_a006c410[];
extern void *FUN_a00b15ac(unsigned char *, unsigned char, int);
extern void FUN_a00734c4(const char *);
extern void FUN_a0093060(unsigned char, unsigned char);
extern void FUN_a0092608(unsigned char, unsigned char);
extern void FUN_a009270c(unsigned char, unsigned char);
extern void FUN_a0092890(unsigned char, unsigned char);
extern void FUN_a00926e0(unsigned char, unsigned char *);
extern void FUN_a0093138(unsigned char, unsigned char *);
extern void FUN_a0093034(unsigned char, unsigned char *);
extern void FUN_a00a8ec4(void *, unsigned char *);
extern void FUN_a00a8f28(void *, unsigned char *);
extern void FUN_a00a9380(unsigned char, unsigned char *);
extern void *FUN_a00b02f0(unsigned int);
extern void *FUN_a00b035c(unsigned int);
extern unsigned char FUN_a00b048c(unsigned int);
extern unsigned char FUN_a00b0308(unsigned int);
extern unsigned char FUN_a00b0324(unsigned int);
extern unsigned char FUN_a00b0340(unsigned int);
extern unsigned char FUN_a00b029c(unsigned int);
extern unsigned char FUN_a00b02b8(unsigned int);
extern unsigned char FUN_a00b02d4(unsigned int);
extern unsigned char FUN_a00b0248(unsigned int);
extern unsigned char FUN_a00b0264(unsigned int);
extern unsigned char FUN_a00b0280(unsigned int);

void CONV2HDMITX_UpdatePacket(unsigned char port, unsigned char type)
{
    unsigned char pkt0[32];
    unsigned char pkt1[16];
    unsigned char pkt2[16];
    unsigned char sel;

    FUN_a00b15ac(pkt0, 0, 0x1f);
    FUN_a00b15ac(pkt1, 0, 0xe);
    FUN_a00b15ac(pkt2, 0, 0xe);
    sel = 0;
    switch (type) {
    case 0x71:
        sel = 0;
        break;
    case 0x81:
        sel = 1;
        break;
    }
    switch (type) {
    case 0x31:
    case 0x41:
    case 0x51:
    case 0x61:
        FUN_a0093060(port, 0);
        FUN_a0092608(port, 0);
        FUN_a009270c(port, 0);
        break;
    case 0x71:
    case 0x81:
        DAT_a8079290.r[port].g2b |= FUN_a00b0308(sel);
        DAT_a8079290.r[port].g2a = FUN_a00b0324(sel);
        DAT_a8079290.r[port].g2c = FUN_a00b0340(sel);
        DAT_a8079290.r[port].g0b |= FUN_a00b029c(sel);
        DAT_a8079290.r[port].g0a = FUN_a00b02b8(sel);
        DAT_a8079290.r[port].g0c = FUN_a00b02d4(sel);
        DAT_a8079290.r[port].g3b |= FUN_a00b0248(sel);
        DAT_a8079290.r[port].g3a = FUN_a00b0264(sel);
        DAT_a8079290.r[port].g3c = FUN_a00b0280(sel);
        if (DAT_a8079290.r[port].g0c == 0 && DAT_a8079290.r[port].g0a == 1 && DAT_a8079290.r[port].g0b == 1) {
            FUN_a00a8ec4(FUN_a00b02f0(sel), pkt0);
            FUN_a00926e0(port, pkt0);
            DAT_a8079290.r[port].g0b = 0;
        } else if (DAT_a8079290.r[port].g0c == 0 && DAT_a8079290.r[port].g0a == 0) {
            FUN_a0092608(port, 0);
            DAT_a8079290.r[port].g0b = 0;
        }
        if (DAT_a8079290.r[port].g2c == 0 && DAT_a8079290.r[port].g2a == 1 && DAT_a8079290.r[port].g2b == 1) {
            FUN_a00a8f28(FUN_a00b035c(sel), pkt1);
            FUN_a0093138(port, pkt1);
            DAT_a8079290.r[port].g2b = 0;
        } else if (DAT_a8079290.r[port].g2c == 0 && DAT_a8079290.r[port].g2a == 0) {
            FUN_a0093060(port, 0);
            DAT_a8079290.r[port].g2b = 0;
        } else if (DAT_a8079290.r[port].g3c == 0 && DAT_a8079290.r[port].g3a == 0) {
            FUN_a009270c(port, 0);
            DAT_a8079290.r[port].g3b = 0;
        }
        if (DAT_a8079290.r[port].g1c == 0 && DAT_a8079290.r[port].g1a == 1 && DAT_a8079290.r[port].g1b == 1) {
            FUN_a0092890(port, 0);
            DAT_a8079290.r[port].g1b = 0;
        } else if (DAT_a8079290.r[port].g1c == 0 && DAT_a8079290.r[port].g1a == 0) {
            FUN_a00a9380(FUN_a00b048c(sel & 1), pkt2);
            FUN_a0093034(port, pkt2);
            DAT_a8079290.r[port].g1b = 0;
        }
        break;
    default:
        FUN_a00734c4(s_a006c410);
        break;
    }
}
