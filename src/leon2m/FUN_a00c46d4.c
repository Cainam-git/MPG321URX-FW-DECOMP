/* leon2m FUN_a00c46d4 @ 0xa00c46d4-0xa00c49b8 (185 words), flags -mcpu=v8 -O3 -g.
 * Command handler: takes byte 9 of the port's receive record (0xa802d040 for port 2, 0xa802d098 for port 3,
 * 0xa802d0d0 otherwise) as an ASCII digit d. A value above 1 returns 0xff. Otherwise d is stored in byte
 * 0xa802d290+0x4a. For d == 1: when the word 0xa802d290+0xb0 is nonzero it is cleared and FUN_a00d4998() and
 * FUN_a00d5f3c() run; when FUN_a00837e4() returns 1, FUN_a00d91fc(0) runs, byte 0xa802d290+0x1a4 is cleared,
 * FUN_a0148268(0, 1), FUN_a0148268(1, 1), FUN_a00da254() and FUN_a00830f4(0) run; when byte 0xa802d290+0x1f is
 * nonzero it is cleared and FUN_a0090fd8(), FUN_a0124f44(), FUN_a00d91fc(0) and FUN_a00da254() run; when bit 7 of
 * the word 0xa802d290+0xa8 is set it is cleared and FUN_a0090fd8(), FUN_a0124f44(), FUN_a00d91fc(0) and
 * FUN_a00da184() run. Both values then call FUN_a00d5eac(0); the reply "5600+\r" is written into the port's
 * transmit buffer (FUN_a00baa6c), the port's receive state is cleared (FUN_a00ba950), the 6-byte reply is sent
 * (FUN_a00bab80) and the function returns 0.
 * Source form: the three port helpers are defined in this file and inlined by GCC at -O3 (as in FUN_a00c604c).
 * The globals from 0xa802d290 on are members of one structure; bit 7 of the word at 0xa8 is a 1-bit bit-field.
 * FUN_a00d5eac(0) is written in both arms of the d == 1 test (one common call gives a different block layout).
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
struct R290 { unsigned char p000[0x1f]; unsigned char b01f; unsigned char p020[0x4a - 0x20]; unsigned char b04a;
              unsigned char p04b[0xa8 - 0x4b]; unsigned int hi : 24, b7 : 1, lo : 7; unsigned int w0ac;
              unsigned int w0b0; unsigned char p0b4[0x1a4 - 0xb4]; unsigned char b1a4; };
extern struct R290 DAT_a802d290;
extern void FUN_a0090fd8(void);
extern void FUN_a0124f44(void);
extern void FUN_a00d91fc(int);
extern void FUN_a00da184(void);
extern void FUN_a00da254(void);
extern unsigned char FUN_a00837e4(void);
extern void FUN_a00830f4(int);
extern void FUN_a00d5eac(int);
extern void FUN_a00d4998(void);
extern void FUN_a00d5f3c(void);
extern void FUN_a0148268(int, int);
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
int FUN_a00c46d4(unsigned char port)
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
    if ((unsigned char)diff > 1)
        return 0xff;
    DAT_a802d290.b04a = diff;
    if ((unsigned char)diff == 1) {
        if (DAT_a802d290.w0b0 != 0) {
            DAT_a802d290.w0b0 = 0;
            FUN_a00d4998();
            FUN_a00d5f3c();
        }
        if (FUN_a00837e4() == 1) {
            FUN_a00d91fc(0);
            DAT_a802d290.b1a4 = 0;
            FUN_a0148268(0, 1);
            FUN_a0148268(1, 1);
            FUN_a00da254();
            FUN_a00830f4(0);
        }
        if (DAT_a802d290.b01f != 0) {
            DAT_a802d290.b01f = 0;
            FUN_a0090fd8();
            FUN_a0124f44();
            FUN_a00d91fc(0);
            FUN_a00da254();
        }
        if (DAT_a802d290.b7) {
            DAT_a802d290.b7 = 0;
            FUN_a0090fd8();
            FUN_a0124f44();
            FUN_a00d91fc(0);
            FUN_a00da184();
        }
        FUN_a00d5eac(0);
    } else {
        FUN_a00d5eac(0);
    }
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}
