/* FUN_a01012a8 (leon2m 0xa01012a8-0xa01016a4, 1020 bytes), flags -mcpu=v8 -O3 -g.
 * void (p1, u8 port, p3, u8 p4); p1 and p3 are not read. t = FUN_a00fd820(port), replaced by FUN_a00fe6c8() when it
 * is 0xb1. DAT_a8027a75 is set from DAT_a8027a78: 2 -> 1; other than 1 -> DAT_a8027a74; 1 -> by t: 0x31, 0x41, 0x51,
 * 0x61, 0x71, 0x81 -> p4; 0x21 -> h = FUN_a00f8dd4(port), v = FUN_a00f8df0(port), FUN_a00f1ad4(port, 1, 0x24) for
 * (h, v) = (0x780, 0x438) or (0x500, 0x2d0) else FUN_a00f1ad4(port, 1, 1), func_0x4008d1a0(0x14), then 9 or 3 by the
 * same test; others -> 1. Then FUN_a01006e4(port) for port < 4, FUN_a0100a40(port) for port < 5, registers 0xf2
 * and 0xf3 of block port cleared with FUN_a00f1ad4. For port 0 and DAT_a8027a75 in 0x1c..0x27: three 30-byte tables
 * copied with FUN_a013c910 from DAT_0019a5da / DAT_0019a5f8 / DAT_0019a616, a 9-halfword local m initialised,
 * register 0xf2 bits 2 and 3 cleared (FUN_a00f1b5c), registers 0xf2/0xf3 = 1, and for rows i = 0..2: register
 * 0xf4 = i and registers 0xf5, 0xf7, 0xf9, 0xfb, 0xfd = the five halfwords of row i of the first table
 * (FUN_a00f1d48); finally bit 2 of register 0xf2 set.
 * Source forms the exact build depends on: FUN_a00f8dd4/FUN_a00f8df0 declared with one parameter and an unsigned
 * short result (they return 12 and 11 masked bits); separate else-ifs for 0x71 and 0x81; the tables as extern
 * array symbols; m declared after the three copies.
 */
extern unsigned char DAT_a8027a74, DAT_a8027a75;
extern unsigned int DAT_a8027a78;
extern unsigned char FUN_a00fd820(unsigned char blk);
extern unsigned char FUN_a00fe6c8(void);
extern unsigned short FUN_a00f8dd4(unsigned int);
extern unsigned short FUN_a00f8df0(unsigned int);
extern void FUN_a00f1ad4(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a00f1b5c(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern void FUN_a00f1d48(unsigned char blk, unsigned char reg, unsigned short val);
extern void FUN_a01006e4(unsigned char port);
extern void FUN_a0100a40(unsigned char blk);
extern void *FUN_a013c910(void *dst, const void *src, unsigned int n);
extern void func_0x4008d1a0(int);
extern const unsigned short DAT_0019a5da[], DAT_0019a5f8[], DAT_0019a616[];

void FUN_a01012a8(unsigned int p1, unsigned char port, unsigned int p3, unsigned char p4)
{
    unsigned char t;
    unsigned short h, v;
    unsigned char i;
    unsigned short t1[3][5];
    unsigned short t2[3][5];
    unsigned short t3[3][5];

    t = FUN_a00fd820(port);
    if (t == 0xb1)
        t = FUN_a00fe6c8();
    if (DAT_a8027a78 == 1) {
        if (t == 0x31 || t == 0x41)
            DAT_a8027a75 = p4;
        else if (t == 0x51 || t == 0x61)
            DAT_a8027a75 = p4;
        else if (t == 0x21) {
            h = FUN_a00f8dd4(port);
            v = FUN_a00f8df0(port);
            if ((h == 0x780 && v == 0x438) || (h == 0x500 && v == 0x2d0))
                FUN_a00f1ad4(port, 1, 0x24);
            else
                FUN_a00f1ad4(port, 1, 1);
            func_0x4008d1a0(0x14);
            if ((h == 0x780 && v == 0x438) || (h == 0x500 && v == 0x2d0))
                DAT_a8027a75 = 9;
            else
                DAT_a8027a75 = 3;
        } else if (t == 0x71)
            DAT_a8027a75 = p4;
        else if (t == 0x81)
            DAT_a8027a75 = p4;
        else
            DAT_a8027a75 = 1;
    } else if (DAT_a8027a78 == 2)
        DAT_a8027a75 = 1;
    else
        DAT_a8027a75 = DAT_a8027a74;
    if (port < 4)
        FUN_a01006e4(port);
    if (port < 5)
        FUN_a0100a40(port);
    FUN_a00f1ad4(port, 0xf2, 0);
    FUN_a00f1ad4(port, 0xf3, 0);
    if (port == 0 && ((unsigned char)(DAT_a8027a75 - 0x22) < 6 || DAT_a8027a75 == 0x1c || DAT_a8027a75 == 0x1d
                      || DAT_a8027a75 == 0x1e || DAT_a8027a75 == 0x1f || DAT_a8027a75 == 0x20
                      || DAT_a8027a75 == 0x21)) {
        FUN_a013c910(t1, DAT_0019a5da, 0x1e);
        FUN_a013c910(t2, DAT_0019a5f8, 0x1e);
        FUN_a013c910(t3, DAT_0019a616, 0x1e);
        unsigned short m[9] = {0x1000, 0, 0, 0x4633, 0x1799, 0x4166, 0, 0, 0x1000};
        FUN_a00f1b5c(0, 0xf2, 4, 0);
        FUN_a00f1b5c(0, 0xf2, 8, 0);
        FUN_a00f1ad4(0, 0xf2, 1);
        FUN_a00f1ad4(0, 0xf3, 1);
        for (i = 0; i < 3; i++) {
            FUN_a00f1ad4(0, 0xf4, i);
            FUN_a00f1d48(0, 0xf5, t1[i][0]);
            FUN_a00f1d48(0, 0xf7, t1[i][1]);
            FUN_a00f1d48(0, 0xf9, t1[i][2]);
            FUN_a00f1d48(0, 0xfb, t1[i][3]);
            FUN_a00f1d48(0, 0xfd, t1[i][4]);
        }
        FUN_a00f1b5c(0, 0xf2, 4, 1);
    }
}
