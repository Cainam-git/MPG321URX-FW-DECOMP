/* leon2m FUN_a00c68d8 @ 0xa00c68d8-0xa00c762c (3412 bytes), flags -mcpu=v8 -O3 -g. Called by FUN_a00ccf34.
 * Bytes k of the port's record (0xa802d040 for port 2, 0xa802d098 for port 3, 0xa802d0d0 otherwise) are read
 * one by one; a byte that is 0 or 0xff is skipped, any other byte is an ASCII digit d = byte - '0' and a digit
 * above the field's limit returns 0xff. R below is the structure at 0xa802d290.
 *   0x15 (<= 3) -> R+0x11; when that digit (or the skipped byte) is 3: 0x16, 0x17, 0x18 (<= 100) -> R+0x12..0x14.
 *   0x10 (<= 1) -> bit 4 of word R+0x11c; when set, byte R+0x178 = 0.  0x13 (<= 100) -> R+0x0a.
 *   FUN_a00d7de0(), FUN_a00d9764().  0x11 (<= 4) -> bits 16..19 of word R+0x34, FUN_a00d58f8(), FUN_a00d58d8().
 *   0x14 (no limit) -> R+0x49, FUN_a00d4084().  0x9 (<= 1) -> bit 31 of R+0x11c; when set and word R+0xb0 is not 0:
 *   R+0xb0 = 0, FUN_a00d5f3c(). Then FUN_a00d8ffc().
 *   0x8 (<= 1): when it differs from word R+0xb0 it is stored there, byte R+0x4a (if set) is cleared with
 *   FUN_a00d5eac(0), bit 31 of R+0x11c (if set while R+0xb0 != 0) is cleared with FUN_a00d8ffc(), and
 *   FUN_a00d5f3c() runs; then R+0x1f != 0 and R+0xb0 != 0: R+0x1f = 0, FUN_a00d91fc(0), FUN_a0148268(0, 1),
 *   FUN_a0148268(1, 1), FUN_a00da254(); FUN_a00837e4() == 1 and R+0xb0 != 0: FUN_a00d91fc(0), R+0x1a4 = 0,
 *   FUN_a00830f4(0).
 *   0x7 (<= 2): when (R+0xb0 == 0 or FUN_a00d7d48() != 0), R+0x1f == 0 and the digit differs from R+0x19: stored
 *   there, FUN_a00d8c1c().  0x6 (<= 10) -> R+0x140, FUN_a00d8b30().  0x12 (<= 100): when R+0xb0 == 0 and bit 31
 *   of R+0x11c is clear -> R+0x09, FUN_a00d8cd4().  0xa (<= 1) -> bit 12 of word R+0xa8.  0xb (<= 4) -> R+0x13e.
 *   0xc (<= 4) -> R+0x1a0, R+0x1a1 = R[0x197 + d], R+0x1a2 = R[0x19b + d], bit 14 of halfword 0xa802cff4 set.
 *   0xd (<= 4) -> R+0x13f.  0xe (<= 12) -> R+0x190.
 *   Bits 13..14 of halfword 0xa802cff8 clear: FUN_a0090fd8(), FUN_a0090fac(). R+0x190 == 0, bit 12 of R+0xa8
 *   clear, R+0x1a0 == 0, bit 22 of R+0xac clear and bits 13..14 of 0xa802cff8 clear: FUN_a0090fd8().
 *   0xf (<= 1) -> bit 7 of R+0xa8. When bit 7 differs from its value at entry: FUN_a0124f44(), FUN_a00d91fc(0),
 *   FUN_a00da184(), and R+0xb0 = 0 when bit 7 is set and R+0xb0 != 0.
 *   Then FUN_a00d4998(), FUN_a00b88cc(); the reply "5600+\r" is written into the port's transmit buffer
 *   (FUN_a00baa6c), the port's receive state is cleared (FUN_a00ba950), the 6-byte reply is sent (FUN_a00bab80)
 *   and the function returns 0.
 * Source form: the three port helpers are defined in this file and inlined by GCC at -O3 (as in FUN_a00c7e3c);
 * each record byte is read through the inlined static rec_byte() into an unsigned int and tested through the
 * inlined static valid(unsigned char); the digit is computed into an unsigned short and bit-fields are assigned
 * its unsigned char value. The first field's result is kept in an unsigned char copied before the test. The
 * bit-7 change is tested as (bit ^ old) & 1. Bit 14 of 0xa802cff4 is set through a 1-bit field.
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
struct Scff4 { unsigned short b15 : 1, b14 : 1, r0 : 14; unsigned short h002; unsigned short c15 : 1, susp : 2, rest : 13; };
extern struct Scff4 DAT_a802cff4;
struct R290 {
    unsigned char p000[9];
    unsigned char b009, b00a;
    unsigned char p00b[0x11 - 0xb];
    unsigned char b011, b012, b013, b014;
    unsigned char p015[0x19 - 0x15];
    unsigned char b019;
    unsigned char p01a[0x1f - 0x1a];
    unsigned char b01f;
    unsigned char p020[0x34 - 0x20];
    unsigned int f034 : 12, nib : 4, f034b : 16;
    unsigned char p038[0x49 - 0x38];
    unsigned char b049, b04a;
    unsigned char p04b[0xa8 - 0x4b];
    union { unsigned int w; struct { unsigned int p : 19, b12 : 1, q : 4, b7 : 1, r : 7; } f; } u0a8;
    unsigned int w0ac;
    unsigned int w0b0;
    unsigned char p0b4[0x11c - 0xb4];
    struct { unsigned int b31 : 1, p : 26, b4 : 1, r : 4; } f11c;
    unsigned char p120[0x13e - 0x120];
    unsigned char b13e, b13f, b140;
    unsigned char p141[0x178 - 0x141];
    unsigned char b178;
    unsigned char p179[0x190 - 0x179];
    unsigned char b190;
    unsigned char p191[0x197 - 0x191];
    unsigned char t197[4];
    unsigned char t19b[5];
    unsigned char b1a0, b1a1, b1a2;
    unsigned char p1a3;
    unsigned char b1a4;
};
extern struct R290 DAT_a802d290;
extern int FUN_a00d7d48(void);
extern int FUN_a00d7de0(void);
extern void FUN_a00d9764(void);
extern void FUN_a00d58f8(void);
extern void FUN_a00d58d8(void);
extern int FUN_a00d4084(void);
extern void FUN_a00d8ffc(void);
extern void FUN_a00d5f3c(void);
extern void FUN_a00d5eac(int);
extern void FUN_a00d8b30(void);
extern void FUN_a00d8cd4(void);
extern void FUN_a00d8c1c(void);
extern void FUN_a0090fac(void);
extern void FUN_a0090fd8(void);
extern unsigned char FUN_a00d4998();
extern void FUN_a0124f44(void);
extern void FUN_a00da184(void);
extern void FUN_a00d91fc(int);
extern void FUN_a0148268(int, int);
extern void FUN_a00da254(void);
extern unsigned char FUN_a00837e4(void);
extern void FUN_a00830f4(int);
extern void FUN_a00b88cc(void);
extern void FUN_a01487e8(unsigned char, unsigned short, unsigned char *);

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
static int valid(unsigned char v)
{
    return v != 0 && v != 0xff;
}
static unsigned char rec_byte(unsigned char port, int k)
{
    if (port == 2)
        return DAT_a802d040[k];
    if (port == 3)
        return DAT_a802d098[k];
    return DAT_a802d0d0[k];
}
int FUN_a00c68d8(unsigned char port)
{
    unsigned char sel;
    unsigned char old;
    unsigned int c;
    unsigned short diff;

    old = DAT_a802d290.u0a8.f.b7;
    c = rec_byte(port, 0x15);
    sel = c;
    if (valid(c)) {
        diff = c - 0x30;
        sel = diff;
        if (sel > 3)
            return 0xff;
        DAT_a802d290.b011 = diff;
    }
    if (sel == 3) {
        c = rec_byte(port, 0x16);
        if (valid(c)) {
            diff = c - 0x30;
            if ((unsigned char)diff > 100)
                return 0xff;
            DAT_a802d290.b012 = diff;
        }
        c = rec_byte(port, 0x17);
        if (valid(c)) {
            diff = c - 0x30;
            if ((unsigned char)diff > 100)
                return 0xff;
            DAT_a802d290.b013 = diff;
        }
        c = rec_byte(port, 0x18);
        if (valid(c)) {
            diff = c - 0x30;
            if ((unsigned char)diff > 100)
                return 0xff;
            DAT_a802d290.b014 = diff;
        }
    }
    c = rec_byte(port, 0x10);
    if (valid(c)) {
        diff = c - 0x30;
        if ((unsigned char)diff > 1)
            return 0xff;
        DAT_a802d290.f11c.b4 = (unsigned char)diff;
        if (DAT_a802d290.f11c.b4)
            DAT_a802d290.b178 = 0;
    }
    c = rec_byte(port, 0x13);
    if (valid(c)) {
        diff = c - 0x30;
        if ((unsigned char)diff > 100)
            return 0xff;
        DAT_a802d290.b00a = diff;
    }
    FUN_a00d7de0();
    FUN_a00d9764();
    c = rec_byte(port, 0x11);
    if (valid(c)) {
        diff = c - 0x30;
        if ((unsigned char)diff > 4)
            return 0xff;
        DAT_a802d290.nib = (unsigned char)diff;
        FUN_a00d58f8();
        FUN_a00d58d8();
    }
    c = rec_byte(port, 0x14);
    if (valid(c)) {
        DAT_a802d290.b049 = c - 0x30;
        FUN_a00d4084();
    }
    c = rec_byte(port, 0x9);
    if (valid(c)) {
        diff = c - 0x30;
        if ((unsigned char)diff > 1)
            return 0xff;
        DAT_a802d290.f11c.b31 = (unsigned char)diff;
        if (DAT_a802d290.f11c.b31 && DAT_a802d290.w0b0 != 0) {
            DAT_a802d290.w0b0 = 0;
            FUN_a00d5f3c();
        }
    }
    FUN_a00d8ffc();
    c = rec_byte(port, 0x8);
    if (valid(c)) {
        diff = c - 0x30;
        if ((unsigned char)diff > 1)
            return 0xff;
        if (DAT_a802d290.w0b0 != (unsigned char)diff) {
            DAT_a802d290.w0b0 = (unsigned char)diff;
            if (DAT_a802d290.b04a != 0) {
                DAT_a802d290.b04a = 0;
                FUN_a00d5eac(0);
            }
            if (DAT_a802d290.f11c.b31 && DAT_a802d290.w0b0 != 0) {
                DAT_a802d290.f11c.b31 = 0;
                FUN_a00d8ffc();
            }
            FUN_a00d5f3c();
        }
        if (DAT_a802d290.b01f != 0 && DAT_a802d290.w0b0 != 0) {
            DAT_a802d290.b01f = 0;
            FUN_a00d91fc(0);
            FUN_a0148268(0, 1);
            FUN_a0148268(1, 1);
            FUN_a00da254();
        }
        if (FUN_a00837e4() == 1 && DAT_a802d290.w0b0 != 0) {
            FUN_a00d91fc(0);
            DAT_a802d290.b1a4 = 0;
            FUN_a00830f4(0);
        }
    }
    c = rec_byte(port, 0x7);
    if (valid(c)) {
        diff = c - 0x30;
        if ((unsigned char)diff > 2)
            return 0xff;
        if ((DAT_a802d290.w0b0 == 0 || FUN_a00d7d48() != 0) && DAT_a802d290.b01f == 0
            && DAT_a802d290.b019 != (unsigned char)diff) {
            DAT_a802d290.b019 = diff;
            FUN_a00d8c1c();
        }
    }
    c = rec_byte(port, 0x6);
    if (valid(c)) {
        diff = c - 0x30;
        if ((unsigned char)diff > 10)
            return 0xff;
        DAT_a802d290.b140 = diff;
        FUN_a00d8b30();
    }
    c = rec_byte(port, 0x12);
    if (valid(c)) {
        diff = c - 0x30;
        if ((unsigned char)diff > 100)
            return 0xff;
        if (DAT_a802d290.w0b0 == 0 && !DAT_a802d290.f11c.b31) {
            DAT_a802d290.b009 = diff;
            FUN_a00d8cd4();
        }
    }
    c = rec_byte(port, 0xa);
    if (valid(c)) {
        diff = c - 0x30;
        if ((unsigned char)diff > 1)
            return 0xff;
        DAT_a802d290.u0a8.f.b12 = (unsigned char)diff;
    }
    c = rec_byte(port, 0xb);
    if (valid(c)) {
        diff = c - 0x30;
        if ((unsigned char)diff > 4)
            return 0xff;
        DAT_a802d290.b13e = diff;
    }
    c = rec_byte(port, 0xc);
    if (valid(c)) {
        diff = c - 0x30;
        if ((unsigned char)diff > 4)
            return 0xff;
        DAT_a802d290.b1a0 = diff;
        DAT_a802d290.b1a1 = DAT_a802d290.t197[(unsigned char)diff];
        DAT_a802d290.b1a2 = DAT_a802d290.t19b[(unsigned char)diff];
        DAT_a802cff4.b14 = 1;
    }
    c = rec_byte(port, 0xd);
    if (valid(c)) {
        diff = c - 0x30;
        if ((unsigned char)diff > 4)
            return 0xff;
        DAT_a802d290.b13f = diff;
    }
    c = rec_byte(port, 0xe);
    if (valid(c)) {
        diff = c - 0x30;
        if ((unsigned char)diff > 12)
            return 0xff;
        DAT_a802d290.b190 = diff;
    }
    if (DAT_a802cff4.susp == 0) {
        FUN_a0090fd8();
        FUN_a0090fac();
    }
    if (DAT_a802d290.b190 == 0 && !(DAT_a802d290.u0a8.w & 0x1000) && DAT_a802d290.b1a0 == 0
        && !(DAT_a802d290.w0ac & 0x400000) && DAT_a802cff4.susp == 0)
        FUN_a0090fd8();
    c = rec_byte(port, 0xf);
    if (valid(c)) {
        diff = c - 0x30;
        if ((unsigned char)diff > 1)
            return 0xff;
        DAT_a802d290.u0a8.f.b7 = (unsigned char)diff;
    }
    if ((DAT_a802d290.u0a8.f.b7 ^ old) & 1) {
        FUN_a0124f44();
        FUN_a00d91fc(0);
        FUN_a00da184();
        if ((DAT_a802d290.u0a8.w & 0x80) && DAT_a802d290.w0b0 != 0)
            DAT_a802d290.w0b0 = 0;
    }
    FUN_a00d4998();
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}
