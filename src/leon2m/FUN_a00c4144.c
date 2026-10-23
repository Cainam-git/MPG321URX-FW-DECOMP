/* leon2m FUN_a00c4144 @ 0xa00c4144-0xa00c4430 (187 words), flags -mcpu=v8 -O3 -g.
 * Command handler: takes byte 9 of the port's receive record (0xa802d040 for port 2, 0xa802d098 for port 3,
 * 0xa802d0d0 otherwise) as an ASCII digit d. A value above 2, or FUN_a00d8bd8() returning 0, returns 0xff. When
 * the word 0xa802d290+0xb0 differs from d it is set to d; then byte 0xa802d290+0x4a, when nonzero, is cleared and
 * FUN_a00d5eac(0) runs; when bit 31 of the word 0xa802d290+0x11c is set and the word at 0xb0 is nonzero, the bit
 * is cleared and FUN_a00d8ffc() runs; then FUN_a00d5f3c() runs. FUN_a00d4998() always runs. When byte
 * 0xa802d290+0x1f and the word at 0xb0 are both nonzero, the byte is cleared and FUN_a00d91fc(0),
 * FUN_a0148268(0, 1), FUN_a0148268(1, 1) and FUN_a00da254() run. When FUN_a00837e4() returns 1 and the word at
 * 0xb0 is nonzero, FUN_a00d91fc(0) runs, byte 0xa802d290+0x1a4 is cleared and FUN_a00830f4(0) runs. Then
 * FUN_a00b88cc() runs, the reply "5600+\r" is written into the port's transmit buffer (FUN_a00baa6c), the port's
 * receive state is cleared (FUN_a00ba950), the 6-byte reply is sent (FUN_a00bab80) and the function returns 0.
 * Source form: the three port helpers are defined in this file and inlined by GCC at -O3 (as in FUN_a00c604c).
 * The two early failures are one || condition. Bit 31 of the word at 0x11c is a 1-bit bit-field.
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
struct R290 { unsigned char p000[0x1f]; unsigned char b01f; unsigned char p020[0x4a - 0x20]; unsigned char b04a;
              unsigned char p04b[0xb0 - 0x4b]; unsigned int w0b0; unsigned char p0b4[0x11c - 0xb4];
              unsigned int b31 : 1, rest : 31; unsigned char p120[0x1a4 - 0x120]; unsigned char b1a4; };
extern struct R290 DAT_a802d290;
extern unsigned char FUN_a00d8bd8(void);
extern void FUN_a00d5eac(int);
extern void FUN_a00d8ffc(void);
extern void FUN_a00d5f3c(void);
extern void FUN_a00d4998(void);
extern void FUN_a00d91fc(int);
extern void FUN_a0148268(int, int);
extern void FUN_a00da254(void);
extern unsigned char FUN_a00837e4(void);
extern void FUN_a00830f4(int);
extern void FUN_a01487e8(unsigned char, int, unsigned char *);
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
int FUN_a00c4144(unsigned char port)
{
    unsigned char value;
    unsigned short diff;
    unsigned char d;

    if (port == 2)
        value = DAT_a802d040[9];
    else if (port == 3)
        value = DAT_a802d098[9];
    else
        value = DAT_a802d0d0[9];
    diff = value - 0x30;
    d = diff;
    if (d > 2 || FUN_a00d8bd8() == 0)
        return 0xff;
    if (DAT_a802d290.w0b0 != d) {
        DAT_a802d290.w0b0 = d;
        if (DAT_a802d290.b04a != 0) {
            DAT_a802d290.b04a = 0;
            FUN_a00d5eac(0);
        }
        if (DAT_a802d290.b31 && DAT_a802d290.w0b0 != 0) {
            DAT_a802d290.b31 = 0;
            FUN_a00d8ffc();
        }
        FUN_a00d5f3c();
    }
    FUN_a00d4998();
    if (DAT_a802d290.b01f != 0 && DAT_a802d290.w0b0 != 0) {
        DAT_a802d290.b01f = 0;
        FUN_a00d91fc(0);
        FUN_a0148268(0, 1);
        FUN_a0148268(1, 1);
        FUN_a00da254();
    }
    if (FUN_a00837e4() == 1) {
        if (DAT_a802d290.w0b0 != 0) {
            FUN_a00d91fc(0);
            DAT_a802d290.b1a4 = 0;
            FUN_a00830f4(0);
        }
    }
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}
