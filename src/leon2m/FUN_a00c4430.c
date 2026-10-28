/* leon2m FUN_a00c4430 @ 0xa00c4430-0xa00c46d4 (169 words), flags -mcpu=v8 -O3 -g. Called by FUN_a00ccf34.
 * Command handler: takes byte 9 of the port's receive record (0xa802d040 for port 2, 0xa802d098 for port 3,
 * 0xa802d0d0 otherwise) as an ASCII digit d. A value above 1 returns 0xff. When d differs from bit 7 of the word
 * 0xa802d290+0xa8, the bit is set to d and FUN_a0090fd8(), FUN_a0124f44(), FUN_a00d91fc(0) and FUN_a00da184()
 * run. When the bit is set: a nonzero byte +0x1f is cleared with FUN_a0090fd8(), FUN_a0124f44(), FUN_a00d91fc(0)
 * and FUN_a00da254(); FUN_a00837e4() == 1 clears byte +0x1a4 and calls FUN_a00830f4(0); byte +0x4a = 0 and
 * FUN_a00d5eac(0). Bit 1 of byte 0xa802b08e is set in both cases. Then the reply "5600+\r" is written into the
 * port's transmit buffer (FUN_a00baa6c), the receive state is cleared (FUN_a00ba950), the 6-byte reply is sent
 * (FUN_a00bab80) and the function returns 0.
 * Source form: the three port helpers are defined in this file and inlined by GCC at -O3 (as in FUN_a00c604c);
 * the digit is copied into an unsigned char d; the word at 0xa8 is a union of a plain word and a bit-field view:
 * the compare and store use the 1-bit field, the later test the word mask (no common load); 0xa802b08e |= 2 is
 * written in both arms of that test.
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
struct R290 { unsigned char p000[0x1f]; unsigned char b01f; unsigned char p020[0x4a - 0x20]; unsigned char b04a;
              unsigned char p04b[0xa8 - 0x4b]; union { unsigned int w; struct { unsigned int hi : 24, b7 : 1, lo : 7; } b; } a8;
              unsigned char p0ac[0x1a4 - 0xac]; unsigned char b1a4; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802b08e;
extern void FUN_a0090fd8(void);
extern void FUN_a0124f44(void);
extern void FUN_a00d91fc(int);
extern void FUN_a00da184(void);
extern void FUN_a00da254(void);
extern unsigned char FUN_a00837e4(void);
extern void FUN_a00830f4(int);
extern void FUN_a00d5eac(int);
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
int FUN_a00c4430(unsigned char port)
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
    if (d > 1)
        return 0xff;
    if (d != DAT_a802d290.a8.b.b7) {
        DAT_a802d290.a8.b.b7 = d;
        FUN_a0090fd8();
        FUN_a0124f44();
        FUN_a00d91fc(0);
        FUN_a00da184();
    }
    if (DAT_a802d290.a8.w & 0x80) {
        if (DAT_a802d290.b01f != 0) {
            DAT_a802d290.b01f = 0;
            FUN_a0090fd8();
            FUN_a0124f44();
            FUN_a00d91fc(0);
            FUN_a00da254();
        }
        if (FUN_a00837e4() == 1) {
            DAT_a802d290.b1a4 = 0;
            FUN_a00830f4(0);
        }
        DAT_a802d290.b04a = 0;
        FUN_a00d5eac(0);
        DAT_a802b08e |= 2;
    } else {
        DAT_a802b08e |= 2;
    }
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}
