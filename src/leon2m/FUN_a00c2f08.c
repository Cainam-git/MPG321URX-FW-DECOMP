/* leon2m FUN_a00c2f08 @ 0xa00c2f08-0xa00c3180 (158 words), flags -mcpu=v8 -O3 -g. Called by FUN_a00ccf34.
 * Command handler: takes byte 9 of the port's receive record (0xa802d040 for port 2, 0xa802d098 for port 3,
 * 0xa802d0d0 otherwise) as an ASCII digit d. A value above 4 returns 0xff.
 * Otherwise bit 14 of the halfword 0xa802cff4 is set, byte 0xa802d290+0x1a0 = d, +0x1a1 = byte +0x197 + d and
 * +0x1a2 = byte +0x19b + d. When the 2-bit field at bits 13..14 of the halfword 0xa802cff8 is 0: FUN_a0090fd8(),
 * FUN_a0090fac(), and once more FUN_a0090fd8() when record bytes +0x190 and +0x1a0 are 0, bit 12 of word +0xa8
 * is clear and bit 22 of word +0xac is clear (as in FUN_a00c3380).
 * Then the reply "5600+\r" is written into the port's transmit buffer (FUN_a00baa6c), the receive state is
 * cleared (FUN_a00ba950), the 6-byte reply is sent (FUN_a00bab80) and the function returns 0.
 * Source form: the three port helpers are defined in this file and inlined by GCC at -O3 (as in FUN_a00c604c).
 * The halfwords 0xa802cff4 and 0xa802cff8 are members of one struct (the fw reaches +4 from the 0xa802cff4 base);
 * bit 14 of 0xa802cff4 is set through a 1-bit bit-field (the mask form schedules two instructions differently).
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
struct R290 {
    unsigned char p000[0xa8];
    unsigned int w0a8;
    unsigned int w0ac;
    unsigned char p0b0[0x190 - 0xb0];
    unsigned char b190;
    unsigned char p191[0x197 - 0x191];
    unsigned char b197[4];
    unsigned char b19b[5];
    unsigned char b1a0;
    unsigned char b1a1;
    unsigned char b1a2;
};
struct Scff4 {
    union { unsigned short h000; struct { unsigned short b15 : 1, b14 : 1, rest : 14; } s000; };
    unsigned short h002;
    struct { unsigned short b15 : 1, f13 : 2, rest : 13; } s004;
};
extern struct R290 DAT_a802d290;
extern struct Scff4 DAT_a802cff4;
extern void FUN_a0090fd8(void);
extern void FUN_a0090fac(void);
extern void FUN_a01487e8(unsigned char, int, unsigned char *);

void FUN_a00baa6c(unsigned char port)
{
    if (port == 2) {
        DAT_a802d128[0] = '5';
        DAT_a802d128[1] = '6';
        DAT_a802d128[2] = '0';
        DAT_a802d128[3] = '0';
        DAT_a802d128[4] = '+';
        DAT_a802d128[5] = '\r';
    } else if (port == 3) {
        DAT_a802d108[0] = '5';
        DAT_a802d108[1] = '6';
        DAT_a802d108[2] = '0';
        DAT_a802d108[3] = '0';
        DAT_a802d108[4] = '+';
        DAT_a802d108[5] = '\r';
    } else {
        DAT_a802d078[0] = '5';
        DAT_a802d078[1] = '6';
        DAT_a802d078[2] = '0';
        DAT_a802d078[3] = '0';
        DAT_a802d078[4] = '+';
        DAT_a802d078[5] = '\r';
    }
}
void FUN_a00ba950(unsigned char port)
{
    if (port == 2) {
        DAT_a802b09a = 0;
        DAT_a802d040[0] = 0;
        DAT_a802d040[1] = 0;
        DAT_a802d040[7] = 0;
        DAT_a802d040[10] = 0;
        DAT_a802d040[0x19] = 0;
    } else if (port == 3) {
        DAT_a802b098 = 0;
        DAT_a802d098[0] = 0;
        DAT_a802d098[1] = 0;
        DAT_a802d098[7] = 0;
        DAT_a802d098[10] = 0;
        DAT_a802d098[0x19] = 0;
    } else {
        DAT_a802b09c = 0;
        DAT_a802d0d0[0] = 0;
        DAT_a802d0d0[1] = 0;
        DAT_a802d0d0[7] = 0;
        DAT_a802d0d0[10] = 0;
        DAT_a802d0d0[0x19] = 0;
    }
}
void FUN_a00bab80(unsigned char port, unsigned char len)
{
    if (port == 2)
        FUN_a01487e8(2, len, DAT_a802d128);
    else if (port == 3)
        FUN_a01487e8(3, len, DAT_a802d108);
    else
        FUN_a01487e8(port, len, DAT_a802d078);
}
int FUN_a00c2f08(unsigned char port)
{
    unsigned char value;
    unsigned short diff;

    if (port == 2)
        value = DAT_a802d040[9];
    else if (port == 3)
        value = DAT_a802d098[9];
    else
        value = DAT_a802d0d0[9];
    diff = value - 0x30;
    if ((unsigned char)diff > 4)
        return 0xff;
    DAT_a802cff4.s000.b14 = 1;
    DAT_a802d290.b1a0 = diff;
    DAT_a802d290.b1a1 = DAT_a802d290.b197[(unsigned char)diff];
    DAT_a802d290.b1a2 = DAT_a802d290.b19b[(unsigned char)diff];
    if (DAT_a802cff4.s004.f13 == 0) {
        FUN_a0090fd8();
        FUN_a0090fac();
        if (DAT_a802d290.b190 == 0 && !(DAT_a802d290.w0a8 & 0x1000) && DAT_a802d290.b1a0 == 0 &&
            !(DAT_a802d290.w0ac & 0x400000))
            FUN_a0090fd8();
    }
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}
