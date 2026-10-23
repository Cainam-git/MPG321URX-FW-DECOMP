/* leon2s FUN_a0087ec8 @ 0xa0087ec8-0xa00883b0 (1256 bytes), flags -mcpu=v8 -Os -g.
 * Arguments: port (low byte used) and p, eight halfwords. Register updates go through FUN_a00a7940
 * (port, reg, mask, mode: 1 sets the mask bits, 0 clears them) and FUN_a00a78fc (port, reg, byte).
 * ARR_a807a928 is an array of 40-byte records; bits 25, 27 and 28 of word 0 are read as bit-fields.
 * Start: sets mask 1 of reg 0x6f, mask 0xd of 0x70, mask 0x88 of 0x6d; FUN_a0087d50(port, bit 25).
 * Bit 27 clear: FUN_a00b1794(0x50), v = FUN_a00a7a5c(port, 0x50), bytes 0..2 of v written to regs 0x52,
 * 0x51, 0x50, then mask 4 of 0x70 cleared.
 * Port 0 only: FUN_a00876ec(0) selects r66 / b = 0x20 / 0x81 (8 and other values), 0 / 0x80 (6),
 * 0x40 / 0x82 (10). FUN_a0087710(0) (0..25, in pairs) then selects: 6, 12, 18, 24 -> r67 = 0x40 and
 * a = 0x30..0x33; 2, 4, 8, 10, 14, 16, 20, 22 -> r66 |= 0xc, 0xa, 0x1c, 0x1a, 4, 2, 0x14, 0x12; 0, 1 and
 * others change nothing. Every value updates mask 4 of reg 0x6f (set for 4, 10, 16, 22, else cleared) and
 * then mask 8 of reg 0x6f (set for 6, 12, 18, 24, else cleared). Then reg 0x66 = r66, 0x67 = r67,
 * FUN_a0087d8c(0, a, b), FUN_a0087db4(0, r67 != 0), FUN_a0085914(0).
 * Bit 28 clear: the low and high bytes of p[0..7] go to regs 0x57/0x56, 0x5f/0x5e, 0x5b/0x5a, 0x63/0x62,
 * 0x5d/0x5c, 0x59/0x58, 0x65/0x64, 0x61/0x60, then mask 1 of 0x70 and mask 0x88 of 0x6d cleared.
 * End: mask 8 of reg 0 set, then cleared.
 * Source forms: the parameter is unsigned int; the first part uses one unsigned char copy, the last part a
 * second copy taken after the port 0 block (the firmware re-extends the parameter there); the selection on
 * FUN_a00876ec is an if/else chain; cases 0 and 1 have their own body equal to the default (it keeps the
 * jump table starting at 0); the cases are listed in the firmware's block order.
 */
struct R928 {
    unsigned int b31 : 3;
    unsigned int b28 : 1;
    unsigned int b27 : 1;
    unsigned int b26 : 1;
    unsigned int b25 : 1;
    unsigned int b0 : 25;
    unsigned char pad[0x24];
};
extern struct R928 ARR_a807a928[];

extern void FUN_a00a7940(unsigned int port, short reg, unsigned int mask, unsigned int mode);
extern int FUN_a00a7a5c(unsigned char port, unsigned short reg);
extern void FUN_a00a78fc(unsigned int port, unsigned short reg, unsigned int v);
extern void FUN_a0087d50(unsigned char port, unsigned char v);
extern unsigned char FUN_a00876ec(unsigned int port);
extern unsigned char FUN_a0087710(unsigned int port);
extern void FUN_a0087d8c(unsigned char port, unsigned char a, unsigned char b);
extern void FUN_a0087db4(unsigned int port, unsigned char en);
extern void FUN_a0085914(unsigned char port);
extern void FUN_a00b1794(int);

void FUN_a0087ec8(unsigned int arg, unsigned short *p)
{
    unsigned char port = arg;
    unsigned char q;
    unsigned int v;
    unsigned char r66;
    unsigned char r67 = 0;
    unsigned char a = 0;
    unsigned char b;
    unsigned char r;

    FUN_a00a7940(port, 0x6f, 1, 1);
    FUN_a00a7940(port, 0x70, 0xd, 1);
    FUN_a00a7940(port, 0x6d, 0x88, 1);
    FUN_a0087d50(port, ARR_a807a928[port].b25);
    if (!ARR_a807a928[port].b27) {
        FUN_a00b1794(0x50);
        v = FUN_a00a7a5c(port, 0x50);
        FUN_a00a78fc(port, 0x52, v & 0xff);
        v >>= 8;
        FUN_a00a78fc(port, 0x51, v & 0xff);
        v >>= 8;
        FUN_a00a78fc(port, 0x50, v & 0xff);
        FUN_a00a7940(port, 0x70, 4, 0);
    }
    if (port == 0) {
        r = FUN_a00876ec(0);
        if (r == 8) {
            r66 = 0x20;
            b = 0x81;
        } else if (r == 6) {
            r66 = 0;
            b = 0x80;
        } else if (r == 10) {
            r66 = 0x40;
            b = 0x82;
        } else {
            r66 = 0x20;
            b = 0x81;
        }
        switch (FUN_a0087710(0)) {
        case 6:
        case 7:
            FUN_a00a7940(0, 0x6f, 4, 0);
            r67 = 0x40;
            a = 0x30;
            FUN_a00a7940(0, 0x6f, 8, 1);
            break;
        case 12:
        case 13:
            FUN_a00a7940(0, 0x6f, 4, 0);
            r67 = 0x40;
            a = 0x31;
            FUN_a00a7940(0, 0x6f, 8, 1);
            break;
        case 18:
        case 19:
            FUN_a00a7940(0, 0x6f, 4, 0);
            r67 = 0x40;
            a = 0x32;
            FUN_a00a7940(0, 0x6f, 8, 1);
            break;
        case 24:
        case 25:
            FUN_a00a7940(0, 0x6f, 4, 0);
            r67 = 0x40;
            a = 0x33;
            FUN_a00a7940(0, 0x6f, 8, 1);
            break;
        case 2:
        case 3:
            FUN_a00a7940(0, 0x6f, 4, 0);
            r66 |= 0xc;
            FUN_a00a7940(0, 0x6f, 8, 0);
            break;
        case 4:
        case 5:
            FUN_a00a7940(0, 0x6f, 4, 1);
            r66 |= 0xa;
            FUN_a00a7940(0, 0x6f, 8, 0);
            break;
        case 8:
        case 9:
            FUN_a00a7940(0, 0x6f, 4, 0);
            r66 |= 0x1c;
            FUN_a00a7940(0, 0x6f, 8, 0);
            break;
        case 10:
        case 11:
            FUN_a00a7940(0, 0x6f, 4, 1);
            r66 |= 0x1a;
            FUN_a00a7940(0, 0x6f, 8, 0);
            break;
        case 14:
        case 15:
            FUN_a00a7940(0, 0x6f, 4, 0);
            r66 |= 4;
            FUN_a00a7940(0, 0x6f, 8, 0);
            break;
        case 16:
        case 17:
            FUN_a00a7940(0, 0x6f, 4, 1);
            r66 |= 2;
            FUN_a00a7940(0, 0x6f, 8, 0);
            break;
        case 20:
        case 21:
            FUN_a00a7940(0, 0x6f, 4, 0);
            r66 |= 0x14;
            FUN_a00a7940(0, 0x6f, 8, 0);
            break;
        case 22:
        case 23:
            FUN_a00a7940(0, 0x6f, 4, 1);
            r66 |= 0x12;
            FUN_a00a7940(0, 0x6f, 8, 0);
            break;
        case 0:
        case 1:
            FUN_a00a7940(0, 0x6f, 4, 0);
            FUN_a00a7940(0, 0x6f, 8, 0);
            break;
        default:
            FUN_a00a7940(0, 0x6f, 4, 0);
            FUN_a00a7940(0, 0x6f, 8, 0);
            break;
        }
        FUN_a00a78fc(0, 0x66, r66);
        FUN_a00a78fc(0, 0x67, r67);
        FUN_a0087d8c(0, a, b);
        if (r67)
            FUN_a0087db4(0, 1);
        else
            FUN_a0087db4(0, 0);
        FUN_a0085914(0);
    }
    q = arg;
    if (!ARR_a807a928[q].b28) {
        FUN_a00a78fc(q, 0x57, p[0] & 0xff);
        FUN_a00a78fc(q, 0x56, p[0] >> 8);
        FUN_a00a78fc(q, 0x5f, p[1] & 0xff);
        FUN_a00a78fc(q, 0x5e, p[1] >> 8);
        FUN_a00a78fc(q, 0x5b, p[2] & 0xff);
        FUN_a00a78fc(q, 0x5a, p[2] >> 8);
        FUN_a00a78fc(q, 0x63, p[3] & 0xff);
        FUN_a00a78fc(q, 0x62, p[3] >> 8);
        FUN_a00a78fc(q, 0x5d, p[4] & 0xff);
        FUN_a00a78fc(q, 0x5c, p[4] >> 8);
        FUN_a00a78fc(q, 0x59, p[5] & 0xff);
        FUN_a00a78fc(q, 0x58, p[5] >> 8);
        FUN_a00a78fc(q, 0x65, p[6] & 0xff);
        FUN_a00a78fc(q, 0x64, p[6] >> 8);
        FUN_a00a78fc(q, 0x61, p[7] & 0xff);
        FUN_a00a78fc(q, 0x60, p[7] >> 8);
        FUN_a00a7940(q, 0x70, 1, 0);
        FUN_a00a7940(q, 0x6d, 0x88, 0);
    }
    FUN_a00a7940(q, 0, 8, 1);
    FUN_a00a7940(q, 0, 8, 0);
}
