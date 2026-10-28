/* leon2m FUN_a00ce5dc @ 0xa00ce5dc-0xa00ce958 (223 words), flags -mcpu=v8 -O3 -g.
 * Command handler: takes bytes 6 and 7 of the port's receive record (0xa802d040 for port 2, 0xa802d098 for port 3,
 * 0xa802d0d0 otherwise) as ASCII digits. Returns 0xff when the first digit is above 1, the word 0xa802d290+0xb0 or
 * the byte 0xa802d290+0x1f is nonzero, or FUN_a00837e4() returns 1; then when the second digit is above 8, byte
 * 0x1f is 2, or the second digit is 4 while byte 0x1f is 1. Otherwise the second digit is stored in byte 0x1a4.
 * Three FUN_a00837e4() == 1 tests follow: the first clears a nonzero word 0xb0 and calls FUN_a00d5f3c(); the second
 * clears a nonzero byte 0x1f and calls FUN_a00da254(); the third, when bit 7 of the word 0xa8 is set, calls
 * FUN_a0090fd8(), clears the bit, calls FUN_a0124f44(), FUN_a00d91fc(0), FUN_a00da184() and sets bit 1 of byte
 * 0xa802b08e. Then FUN_a00830f4(0), FUN_a00da254(), FUN_a00d5cd8() when bit 0x4000 of the word 0xa8 is set, and
 * FUN_a00b88cc(). The reply "5600+\r" is written into the port's transmit buffer (FUN_a00baa6c), the port's
 * receive state is cleared (FUN_a00ba950), the 6-byte reply is sent (FUN_a00bab80) and the function returns 0.
 * Source form: the three port helpers are defined in this file and inlined by GCC at -O3 (as in FUN_a00c604c).
 * The early-return tests of each digit are one || chain per digit (separate ifs give a different block layout).
 * The globals from 0xa802d290 on are members of one structure.
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802b08e;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
struct R290 { unsigned char p000[0x1f]; unsigned char b01f; unsigned char p020[0xa8 - 0x20];
              unsigned int w0a8; unsigned int w0ac;
              unsigned int w0b0; unsigned char p0b4[0x1a4 - 0xb4]; unsigned char b1a4; };
extern struct R290 DAT_a802d290;
extern void FUN_a0090fd8(void);
extern void FUN_a0124f44(void);
extern void FUN_a00d91fc(int);
extern void FUN_a00da184(void);
extern void FUN_a00da254(void);
extern unsigned char FUN_a00837e4(void);
extern void FUN_a00830f4(int);
extern void FUN_a00d5cd8(void);
extern void FUN_a00d5f3c(void);
extern void FUN_a01487e8(unsigned char, unsigned short, unsigned char *);
extern void FUN_a00b88cc(void);

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
int FUN_a00ce5dc(unsigned char port)
{
    unsigned char value;
    unsigned short diff;

    if (port == 2)
        value = DAT_a802d040[6];
    else if (port == 3)
        value = DAT_a802d098[6];
    else
        value = DAT_a802d0d0[6];
    diff = value - 0x30;
    if ((unsigned char)diff > 1 || DAT_a802d290.w0b0 != 0 || DAT_a802d290.b01f != 0 || FUN_a00837e4() == 1)
        return 0xff;
    if (port == 2)
        value = DAT_a802d040[7];
    else if (port == 3)
        value = DAT_a802d098[7];
    else
        value = DAT_a802d0d0[7];
    diff = value - 0x30;
    if ((unsigned char)diff > 8 || DAT_a802d290.b01f == 2 || ((unsigned char)diff == 4 && DAT_a802d290.b01f == 1))
        return 0xff;
    DAT_a802d290.b1a4 = diff;
    if (FUN_a00837e4() == 1) {
        if (DAT_a802d290.w0b0 != 0) {
            DAT_a802d290.w0b0 = 0;
            FUN_a00d5f3c();
        }
    }
    if (FUN_a00837e4() == 1) {
        if (DAT_a802d290.b01f != 0) {
            DAT_a802d290.b01f = 0;
            FUN_a00da254();
        }
    }
    if (FUN_a00837e4() == 1) {
        if (DAT_a802d290.w0a8 & 0x80) {
            FUN_a0090fd8();
            DAT_a802d290.w0a8 &= ~0x80;
            FUN_a0124f44();
            FUN_a00d91fc(0);
            FUN_a00da184();
            DAT_a802b08e |= 2;
        }
    }
    FUN_a00830f4(0);
    FUN_a00da254();
    if (DAT_a802d290.w0a8 & 0x4000)
        FUN_a00d5cd8();
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}
