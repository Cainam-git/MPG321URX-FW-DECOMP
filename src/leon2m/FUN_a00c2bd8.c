/* leon2m FUN_a00c2bd8 @ 0xa00c2bd8-0xa00c2f08 (816 bytes), flags -mcpu=v8 -O3 -g. Called by FUN_a00ccf34.
 * Reads bytes 8 and 9 of the port's receive record (0xa802d040 for port 2, 0xa802d098 for port 3, 0xa802d0d0
 * otherwise) as ASCII digits a, b; R below is the structure at 0xa802d290, S the one at 0xa802cff4. A digit above
 * 99 after subtracting '0' or R+0x1a0 above 4 returns 0xff. When R+0x1a0 and byte S+9 are both 0, S+9 is set to 1.
 * With n = S+9: when R+0x1a0 equals n, bit 14 of the halfword S+0 is set and a, b are stored in R+0x1a1 / R+0x1a2;
 * in every case a, b are stored in R+0x198 / R+0x19c at index n - 1. Then FUN_a00b88cc(); when bits 13..14 of the
 * halfword S+4 are clear: FUN_a0090fd8(), FUN_a0090fac(). Finally the reply "5600+\r" is written into the port's
 * transmit buffer (FUN_a00baa6c), the port's receive state is cleared (FUN_a00ba950), the 6-byte reply is sent
 * (FUN_a00bab80) and the function returns 0.
 * Source form: the record reader and the three port helpers are defined in this file and inlined by GCC at -O3
 * (as in FUN_a00c49b8). n is an int; the R+0x1a0 test is written as '!=' with the index 'i = n - 1' assigned in
 * both arms (first in the equal arm). S+0 bit 14 and S+4 bits 13..14 are bit-fields of one structure.
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
struct R290 { unsigned char p000[0x198]; unsigned char a198[4]; unsigned char a19c[4]; unsigned char b1a0;
              unsigned char b1a1; unsigned char b1a2; };
extern struct R290 DAT_a802d290;
struct Scff4 { unsigned short b15 : 1, b14 : 1, r0 : 14; unsigned short h2; unsigned short c15 : 1, f13 : 2, rest : 13;
               unsigned char p6[3]; unsigned char b9; };
extern struct Scff4 DAT_a802cff4;
extern void FUN_a0090fd8(void);
extern void FUN_a0090fac(void);

static unsigned char rx(unsigned char port, int i)
{
    unsigned char c;

    if (port == 2)
        c = DAT_a802d040[i];
    else if (port == 3)
        c = DAT_a802d098[i];
    else
        c = DAT_a802d0d0[i];
    return c;
}
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
int FUN_a00c2bd8(unsigned char port)
{
    unsigned char a, b;
    unsigned char i;
    int n;

    a = rx(port, 8);
    b = rx(port, 9);
    if ((unsigned char)(a - '0') > 99)
        return 0xff;
    if ((unsigned char)(b - '0') > 99)
        return 0xff;
    if (DAT_a802d290.b1a0 > 4)
        return 0xff;
    if (DAT_a802d290.b1a0 == 0 && DAT_a802cff4.b9 == 0)
        DAT_a802cff4.b9 = 1;
    n = DAT_a802cff4.b9;
    if (DAT_a802d290.b1a0 != n)
        i = n - 1;
    else {
        i = n - 1;
        DAT_a802cff4.b14 = 1;
        DAT_a802d290.b1a1 = a - '0';
        DAT_a802d290.b1a2 = b - '0';
    }
    DAT_a802d290.a198[i] = a - '0';
    DAT_a802d290.a19c[i] = b - '0';
    FUN_a00b88cc();
    if (DAT_a802cff4.f13 == 0) {
        FUN_a0090fd8();
        FUN_a0090fac();
    }
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}
