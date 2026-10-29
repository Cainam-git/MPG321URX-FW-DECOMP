/* leon2m FUN_a00c49b8 @ 0xa00c49b8-0xa00c4ec4 (1292 bytes), flags -mcpu=v8 -O3 -g. Called by FUN_a00ccf34.
 * Reads bytes of the port's receive record (0xa802d040 for port 2, 0xa802d098 for port 3, 0xa802d0d0 otherwise)
 * as ASCII digits; R below is the structure at 0xa802d290. For n = 0..3 the byte pair 6 + 2n / 7 + 2n gives two
 * digits a, b (each above 99 after subtracting '0' returns 0xff); a is stored in R+0x198+n, b in R+0x19c+n. Byte
 * 0xe gives d (above 4 returns 0xff), stored in R+0x1a0; when d is not 0, bit 14 of the halfword 0xa802cff4 is set
 * and R+0x1a1 / R+0x1a2 are copied from R+0x198 / R+0x19c at index d - 1. Then FUN_a00b88cc(); when bits 13..14
 * of the halfword 0xa802cff8 are clear: FUN_a0090fd8(), four calls of func_0x4008e2a4(), FUN_a0090fac(), and
 * FUN_a0090fd8() again when R+0x190 == 0, bit 12 of word R+0xa8 is clear, R+0x1a0 == 0 and bit 22 of word R+0xac
 * is clear. Finally the reply "5600+\r" is written into the port's transmit buffer (FUN_a00baa6c), the port's
 * receive state is cleared (FUN_a00ba950), the 6-byte reply is sent (FUN_a00bab80) and the function returns 0.
 * Source form: the three port helpers are defined in this file and inlined by GCC at -O3 (as in FUN_a00c7e3c).
 * The first byte of each pair is read through the inlined static rec_byte() (one return per port), the second
 * byte and byte 0xe through an explicit port if-chain into an unsigned char that is copied into an int before
 * the first digit's test; the second digit is computed into an unsigned short. The digit d is tested through an
 * unsigned char copy for both tests. 0xa802cff4 / 0xa802cff8 are one structure with bit-fields.
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
struct Scff4 { unsigned short b15 : 1, b14 : 1, r0 : 14; unsigned short h002; unsigned short c15 : 1, susp : 2, rest : 13; };
extern struct Scff4 DAT_a802cff4;
struct R290 { unsigned char p000[0xa8]; unsigned int w0a8; unsigned int w0ac; unsigned char p0b0[0x190 - 0xb0];
              unsigned char b190; unsigned char p191[0x198 - 0x191]; unsigned char b198[4]; unsigned char b19c[4];
              unsigned char b1a0; unsigned char b1a1; unsigned char b1a2; };
extern struct R290 DAT_a802d290;
extern void FUN_a01487e8(unsigned char, int, unsigned char *);
extern void FUN_a00b88cc(void);
extern void FUN_a0090fd8(void);
extern void FUN_a0090fac(void);
extern void func_0x4008e2a4(void);

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
static unsigned char rec_byte(unsigned char port, int k)
{
    if (port == 2)
        return DAT_a802d040[k];
    if (port == 3)
        return DAT_a802d098[k];
    return DAT_a802d0d0[k];
}
int FUN_a00c49b8(unsigned char port)
{
    unsigned char a, b, c, j;
    unsigned short da, db;
    unsigned char k;
    int x;

    a = rec_byte(port, 6);
    if (port == 2)
        b = DAT_a802d040[7];
    else if (port == 3)
        b = DAT_a802d098[7];
    else
        b = DAT_a802d0d0[7];
    x = b;
    a -= 0x30;
    if (a > 99)
        return 0xff;
    db = x - 0x30;
    if ((unsigned char)db > 99)
        return 0xff;
    DAT_a802d290.b198[0] = a;
    DAT_a802d290.b19c[0] = db;
    a = rec_byte(port, 8);
    if (port == 2)
        b = DAT_a802d040[9];
    else if (port == 3)
        b = DAT_a802d098[9];
    else
        b = DAT_a802d0d0[9];
    x = b;
    a -= 0x30;
    if (a > 99)
        return 0xff;
    db = x - 0x30;
    if ((unsigned char)db > 99)
        return 0xff;
    DAT_a802d290.b198[1] = a;
    DAT_a802d290.b19c[1] = db;
    a = rec_byte(port, 10);
    if (port == 2)
        b = DAT_a802d040[11];
    else if (port == 3)
        b = DAT_a802d098[11];
    else
        b = DAT_a802d0d0[11];
    x = b;
    a -= 0x30;
    if (a > 99)
        return 0xff;
    db = x - 0x30;
    if ((unsigned char)db > 99)
        return 0xff;
    DAT_a802d290.b198[2] = a;
    DAT_a802d290.b19c[2] = db;
    a = rec_byte(port, 12);
    if (port == 2)
        b = DAT_a802d040[13];
    else if (port == 3)
        b = DAT_a802d098[13];
    else
        b = DAT_a802d0d0[13];
    x = b;
    a -= 0x30;
    if (a > 99)
        return 0xff;
    db = x - 0x30;
    if ((unsigned char)db > 99)
        return 0xff;
    DAT_a802d290.b198[3] = a;
    DAT_a802d290.b19c[3] = db;
    if (port == 2)
        c = DAT_a802d040[0xe];
    else if (port == 3)
        c = DAT_a802d098[0xe];
    else
        c = DAT_a802d0d0[0xe];
    x = c;
    da = x - 0x30;
    k = da;
    if (k > 4)
        return 0xff;
    DAT_a802d290.b1a0 = da;
    if (k != 0) {
        DAT_a802cff4.b14 = 1;
        j = x - 0x31;
        DAT_a802d290.b1a1 = DAT_a802d290.b198[j];
        DAT_a802d290.b1a2 = DAT_a802d290.b19c[j];
    }
    FUN_a00b88cc();
    if (DAT_a802cff4.susp == 0) {
        FUN_a0090fd8();
        func_0x4008e2a4();
        func_0x4008e2a4();
        func_0x4008e2a4();
        func_0x4008e2a4();
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
