/* leon2m FUN_a00c4ec4 @ 0xa00c4ec4-0xa00c5478 (1460 bytes), flags -mcpu=v8 -O3 -g. Called by FUN_a00ccf34.
 * Takes byte 9 of the port's receive record (0xa802d040 for port 2, 0xa802d098 for port 3, 0xa802d0d0 otherwise)
 * as an ASCII digit d; R below is the structure at 0xa802d290. Returns 0xff when d is above 8, when R+0x1f is 2,
 * when d is 3 and R+0x1f is 1, when d is 3, FUN_a0145660(0, 7) equals FUN_a014837c(0), FUN_a0145660(0, 8) is not
 * below FUN_a014837c(1) and FUN_a0143c14(0) returns 10, when d is 5 and the word R+0x1f4 is negative, and for
 * d = 4 or 6. Otherwise d 0, 1, 2, 3, 5, 7, 8 maps to 0, 1, 2, 4, 3, 5, 6, which is stored in R+0x1a4 (its previous
 * value is read first), and FUN_a00d91fc(0) runs. Then: R+0x4a == 1 and FUN_a00837e4() == 1 clear R+0x4a and call
 * FUN_a00d5eac(0); FUN_a00837e4() == 1 with a nonzero word R+0xb0 clears it and calls FUN_a00d5f3c();
 * FUN_a00837e4() == 1, and separately R+0x1a4 == 3, with a nonzero R+0x1f clear it and call FUN_a00da254();
 * FUN_a00837e4() == 1, and separately R+0x1a4 == 3, with bit 7 of the word R+0xa8 set call FUN_a0090fd8(), clear
 * the bit and call FUN_a0124f44(), FUN_a00d91fc(0) and FUN_a00da184(). When the new or the old R+0x1a4 is 3:
 * FUN_a00d99f8(2, 0), FUN_a0148268(0, 1), FUN_a0148268(1, 1) and FUN_a014a8d4(4, 1, 1000). Otherwise
 * FUN_a01437dc(0x32) and FUN_a0148268(0, 1); byte 0xa8025c56 == 5 or 6 calls FUN_a0148268(1, 1), and 5, 6 or 4
 * calls FUN_a0149bf0(2) when FUN_a00837e4() returns 0; FUN_a00837e4() == 1 calls FUN_a0149bf0(0). Finally
 * FUN_a00d4998(), bit 1 of byte 0xa802b08e is set, the reply "5600+\r" is written into the port's transmit
 * buffer (FUN_a00baa6c), the port's receive state is cleared (FUN_a00ba950), the 6-byte reply is sent
 * (FUN_a00bab80) and the function returns 0.
 * Source form: the three port helpers are defined in this file and inlined by GCC at -O3 (as in FUN_a00c46d4).
 * The first three 0xff tests are one '||' condition (a shared return block, so if-conversion does not move the
 * return value set above the tests); the two halfword compares are written 'a == b' / 'a >= b' with a the
 * FUN_a0145660 result; the mode is set by an if/else-if chain after the d == 3 / d == 5 tests.
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
extern unsigned char DAT_a802b08e;
extern unsigned char DAT_a8025c56;
struct R290 { unsigned char p000[0x1f]; unsigned char b01f; unsigned char p020[0x4a - 0x20]; unsigned char b04a;
              unsigned char p04b[0xa8 - 0x4b]; unsigned int hi : 24, b7 : 1, lo : 7; unsigned int w0ac;
              unsigned int w0b0; unsigned char p0b4[0x1a4 - 0xb4]; unsigned char b1a4;
              unsigned char p1a5[0x1f4 - 0x1a5]; int w1f4; };
extern struct R290 DAT_a802d290;
extern unsigned short FUN_a0145660(unsigned char, unsigned int);
extern unsigned short FUN_a014837c(unsigned char);
extern unsigned char FUN_a0143c14(unsigned char);
extern void FUN_a0090fd8(void);
extern void FUN_a0124f44(void);
extern void FUN_a00d91fc(int);
extern void FUN_a00da184(void);
extern void FUN_a00da254(void);
extern unsigned char FUN_a00837e4(void);
extern void FUN_a00d5eac(int);
extern void FUN_a00d4998(void);
extern void FUN_a00d5f3c(void);
extern void FUN_a0148268(int, int);
extern void FUN_a00d99f8(unsigned char, unsigned char);
extern void FUN_a014a8d4(unsigned char, unsigned int, unsigned short);
extern void FUN_a01437dc(unsigned short);
extern void FUN_a0149bf0(unsigned int);
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
int FUN_a00c4ec4(unsigned char port)
{
    unsigned char value, old, mode, d;
    unsigned short diff;

    if (port == 2)
        value = DAT_a802d040[9];
    else if (port == 3)
        value = DAT_a802d098[9];
    else
        value = DAT_a802d0d0[9];
    diff = value - 0x30;
    d = diff;
    old = DAT_a802d290.b1a4;
    if (d > 8 || DAT_a802d290.b01f == 2 || (d == 3 && DAT_a802d290.b01f == 1))
        return 0xff;
    if (d == 3) {
        unsigned short a, b;

        a = FUN_a0145660(0, 7);
        b = FUN_a014837c(0);
        if (a == b) {
            a = FUN_a0145660(0, 8);
            b = FUN_a014837c(1);
            if (a >= b) {
                if (FUN_a0143c14(0) == 10)
                    return 0xff;
            }
        }
    } else if (d == 5) {
        if (DAT_a802d290.w1f4 < 0)
            return 0xff;
    }
    if (d == 0)
        mode = 0;
    else if (d == 1)
        mode = 1;
    else if (d == 2)
        mode = 2;
    else if (d == 3)
        mode = 4;
    else if (d == 5)
        mode = 3;
    else if (d == 7)
        mode = 5;
    else if (d == 8)
        mode = 6;
    else
        return 0xff;
    DAT_a802d290.b1a4 = mode;
    FUN_a00d91fc(0);
    if (DAT_a802d290.b04a == 1 && FUN_a00837e4() == 1) {
        DAT_a802d290.b04a = 0;
        FUN_a00d5eac(0);
    }
    if (FUN_a00837e4() == 1 && DAT_a802d290.w0b0 != 0) {
        DAT_a802d290.w0b0 = 0;
        FUN_a00d5f3c();
    }
    if (FUN_a00837e4() == 1 && DAT_a802d290.b01f != 0) {
        DAT_a802d290.b01f = 0;
        FUN_a00da254();
    }
    if (DAT_a802d290.b1a4 == 3 && DAT_a802d290.b01f != 0) {
        DAT_a802d290.b01f = 0;
        FUN_a00da254();
    }
    if (FUN_a00837e4() == 1 && DAT_a802d290.b7) {
        FUN_a0090fd8();
        DAT_a802d290.b7 = 0;
        FUN_a0124f44();
        FUN_a00d91fc(0);
        FUN_a00da184();
    }
    if (DAT_a802d290.b1a4 == 3 && DAT_a802d290.b7) {
        FUN_a0090fd8();
        DAT_a802d290.b7 = 0;
        FUN_a0124f44();
        FUN_a00d91fc(0);
        FUN_a00da184();
    }
    if (DAT_a802d290.b1a4 == 3 || old == 3) {
        FUN_a00d99f8(2, 0);
        FUN_a0148268(0, 1);
        FUN_a0148268(1, 1);
        FUN_a014a8d4(4, 1, 1000);
    } else {
        FUN_a01437dc(0x32);
        FUN_a0148268(0, 1);
        if (DAT_a8025c56 == 5) {
            FUN_a0148268(1, 1);
            if (FUN_a00837e4() == 0)
                FUN_a0149bf0(2);
        }
        if (DAT_a8025c56 == 6) {
            FUN_a0148268(1, 1);
            if (FUN_a00837e4() == 0)
                FUN_a0149bf0(2);
        }
        if (DAT_a8025c56 == 4) {
            if (FUN_a00837e4() == 0)
                FUN_a0149bf0(2);
        }
        if (FUN_a00837e4() == 1)
            FUN_a0149bf0(0);
    }
    FUN_a00d4998();
    DAT_a802b08e |= 2;
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}
