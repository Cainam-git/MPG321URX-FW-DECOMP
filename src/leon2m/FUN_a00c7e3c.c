/* leon2m FUN_a00c7e3c @ 0xa00c7e3c-0xa00c8410 (373 words), flags -mcpu=v8 -O3 -g. Called by FUN_a00ccf34.
 * Bytes k of the port's record (0xa802d040 for port 2, 0xa802d098 for port 3,
 * 0xa802d0d0 otherwise) are read as ASCII digits; any digit out of range returns 0xff.
 * Byte 0x6 (0..2) is stored in byte 0xa802d290+0x1f (m below). For m != 0, byte 0x8 (m == 1) or byte 0x11 (m == 2)
 * (0..3) is passed through FUN_a014459c into byte 0x20, then FUN_a00d5938(1) runs.
 * m == 1: byte 0x9 (0..2) is stored as 2 - digit in byte 0x31, byte 0xa (0..4) in bits 4..7 of the word at 0x30.
 * m == 2: byte 0xf (0..2) is stored in byte 0x2f, byte 0x10 (0..3) is passed through FUN_a014459c into byte 0x1e;
 * when that byte changes, FUN_a00d9238() runs and bit 0x400 of the halfword 0xa802cff4 is set.
 * Then FUN_a00d91fc(0), and for m != 0: bit 0x100000 of word 0xac set: cleared, FUN_a01439d8(1, 1) when
 * FUN_a01445fc(byte 0x1e) returns 0; byte 0x4a == 1: cleared, FUN_a00d5eac(0); word 0xb0 != 0: cleared,
 * FUN_a00d5f3c(); FUN_a00837e4() == 1: byte 0x1a4 cleared, FUN_a00830f4(0); bit 0x80 of word 0xa8 set:
 * FUN_a0090fd8(), bit cleared, FUN_a0124f44(), FUN_a00da184(). Then FUN_a0148268(0, 1), FUN_a0148268(1, 1),
 * FUN_a00da254(), FUN_a00d8c1c(), FUN_a00d4998(), FUN_a00d5cd8() when bit 0x4000 of word 0xa8 is set, and
 * FUN_a00b88cc(). The reply "5600+\r" is written into the port's transmit buffer (FUN_a00baa6c), the port's
 * receive state is cleared (FUN_a00ba950), the 6-byte reply is sent (FUN_a00bab80) and the function returns 0.
 * Source form: the three port helpers are defined in this file and inlined by GCC at -O3 (as in FUN_a00c604c);
 * the reads of bytes 0x8 and 0x11 go through a static helper with one return per port (inlined), the other reads
 * are written out per port. The first digit is copied from the unsigned short difference into the unsigned char
 * value, which is reused for the second digit. The globals from 0xa802d290 on are members of one structure; the
 * word at 0x30 is a bit-field word (byte 0x31 and bits 4..7 are fields of it).
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
extern unsigned short DAT_a802cff4;
struct R290 { unsigned char p000[0x1e]; unsigned char b01e; unsigned char b01f; unsigned char b020;
              unsigned char p021[0x2f - 0x21]; unsigned char b02f;
              unsigned int f30 : 8, b031 : 8, f32 : 8, nib : 4, f33 : 4;
              unsigned char p034[0x4a - 0x34]; unsigned char b04a;
              unsigned char p04b[0xa8 - 0x4b]; unsigned int w0a8; unsigned int w0ac; unsigned int w0b0;
              unsigned char p0b4[0x1a4 - 0xb4]; unsigned char b1a4; };
extern struct R290 DAT_a802d290;
extern unsigned char FUN_a014459c(unsigned char);
extern void FUN_a00d5938(int);
extern void FUN_a00d9238(void);
extern void FUN_a00d5eac(int);
extern void FUN_a00d91fc(int);
extern void FUN_a0090fd8(void);
extern void FUN_a0124f44(void);
extern void FUN_a00da184(void);
extern unsigned char FUN_a01445fc(unsigned char);
extern void FUN_a01439d8(int, int);
extern void FUN_a0148268(int, int);
extern void FUN_a00d5f3c(void);
extern void FUN_a00da254(void);
extern unsigned char FUN_a00837e4(void);
extern void FUN_a00830f4(int);
extern void FUN_a00d8c1c(void);
extern void FUN_a00d5cd8(void);
extern void FUN_a00d4998(void);
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
static unsigned char rec_byte(unsigned char port, int k)
{
    if (port == 2)
        return DAT_a802d040[k];
    if (port == 3)
        return DAT_a802d098[k];
    return DAT_a802d0d0[k];
}
int FUN_a00c7e3c(unsigned char port)
{
    unsigned char value, old;
    unsigned short diff;

    if (port == 2)
        value = DAT_a802d040[6];
    else if (port == 3)
        value = DAT_a802d098[6];
    else
        value = DAT_a802d0d0[6];
    diff = value - 0x30;
    value = diff;
    if (value > 2)
        return 0xff;
    DAT_a802d290.b01f = diff;
    if (value != 0) {
        if (value == 1)
            value = rec_byte(port, 8);
        else if (value == 2)
            value = rec_byte(port, 0x11);
        value = value - 0x30;
        if (value > 3)
            return 0xff;
        DAT_a802d290.b020 = FUN_a014459c(value);
        FUN_a00d5938(1);
    }
    if (DAT_a802d290.b01f == 1) {
        if (port == 2)
            value = DAT_a802d040[9];
        else if (port == 3)
            value = DAT_a802d098[9];
        else
            value = DAT_a802d0d0[9];
        diff = value - 0x30;
        if ((unsigned char)diff > 2)
            return 0xff;
        DAT_a802d290.b031 = 2 - diff;
        if (port == 2)
            value = DAT_a802d040[10];
        else if (port == 3)
            value = DAT_a802d098[10];
        else
            value = DAT_a802d0d0[10];
        diff = value - 0x30;
        if ((unsigned char)diff > 4)
            return 0xff;
        DAT_a802d290.nib = (unsigned char)diff;
    }
    if (DAT_a802d290.b01f == 2) {
        if (port == 2)
            value = DAT_a802d040[0xf];
        else if (port == 3)
            value = DAT_a802d098[0xf];
        else
            value = DAT_a802d0d0[0xf];
        diff = value - 0x30;
        if ((unsigned char)diff > 2)
            return 0xff;
        DAT_a802d290.b02f = diff;
        if (port == 2)
            value = DAT_a802d040[0x10];
        else if (port == 3)
            value = DAT_a802d098[0x10];
        else
            value = DAT_a802d0d0[0x10];
        diff = value - 0x30;
        if ((unsigned char)diff > 3)
            return 0xff;
        old = DAT_a802d290.b01e;
        DAT_a802d290.b01e = FUN_a014459c((unsigned char)diff);
        if (DAT_a802d290.b01e != old) {
            FUN_a00d9238();
            DAT_a802cff4 |= 0x400;
        }
    }
    FUN_a00d91fc(0);
    if (DAT_a802d290.b01f != 0) {
        if (DAT_a802d290.w0ac & 0x100000) {
            DAT_a802d290.w0ac &= ~0x100000;
            if (FUN_a01445fc(DAT_a802d290.b01e) == 0)
                FUN_a01439d8(1, 1);
        }
        if (DAT_a802d290.b04a == 1) {
            DAT_a802d290.b04a = 0;
            FUN_a00d5eac(0);
        }
        if (DAT_a802d290.w0b0 != 0) {
            DAT_a802d290.w0b0 = 0;
            FUN_a00d5f3c();
        }
        if (FUN_a00837e4() == 1) {
            DAT_a802d290.b1a4 = 0;
            FUN_a00830f4(0);
        }
        if (DAT_a802d290.w0a8 & 0x80) {
            FUN_a0090fd8();
            DAT_a802d290.w0a8 &= ~0x80;
            FUN_a0124f44();
            FUN_a00da184();
        }
    }
    FUN_a0148268(0, 1);
    FUN_a0148268(1, 1);
    FUN_a00da254();
    FUN_a00d8c1c();
    FUN_a00d4998();
    if (DAT_a802d290.w0a8 & 0x4000)
        FUN_a00d5cd8();
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}
