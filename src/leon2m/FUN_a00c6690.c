/* leon2m FUN_a00c6690 @ 0xa00c6690-0xa00c68d8 (146 words), flags -mcpu=v8 -O3 -g. Called by FUN_a00ccf34.
 * Command handler: converts the three ASCII digits at bytes 7-9 of the port's receive record (0xa802d040 for
 * port 2, 0xa802d098 for port 3, 0xa802d0d0 otherwise) with FUN_a00bae38. A result of 0xff (not digits) or above
 * 100 returns 0xff. Otherwise the value is stored in byte 0xa802d29a, FUN_a00d7de0(), FUN_a00d4998() and
 * FUN_a00b88cc() run, the reply "5600+\r" is written into the port's transmit buffer (FUN_a00baa6c), the port's
 * receive state is cleared (FUN_a00ba950), the 6-byte reply is sent (FUN_a00bab80) and the function returns 0.
 * Source form: FUN_a00bae38 and the three port helpers are defined in this file and inlined by GCC at -O3, which
 * repeats the port test in each of them (as in FUN_a00c604c).
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
extern unsigned char DAT_a802d29a;
extern void FUN_a00d7de0(void);
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
unsigned char FUN_a00bae38(unsigned char port)
{
    unsigned char h, t, o;
    unsigned short r;

    if (port == 2) {
        h = DAT_a802d040[7];
        t = DAT_a802d040[8];
        o = DAT_a802d040[9];
    } else if (port == 3) {
        h = DAT_a802d098[7];
        t = DAT_a802d098[8];
        o = DAT_a802d098[9];
    } else {
        h = DAT_a802d0d0[7];
        t = DAT_a802d0d0[8];
        o = DAT_a802d0d0[9];
    }
    if (h < '0' || h > '1')
        return 0xff;
    if (t < '0' || t > '9')
        return 0xff;
    if (o < '0' || o > '9')
        return 0xff;
    h -= '0';
    t -= '0';
    o -= '0';
    r = h * 100 + t * 10 + o;
    return r;
}
int FUN_a00c6690(unsigned char port)
{
    unsigned char v;

    v = FUN_a00bae38(port);
    if (v == 0xff)
        return 0xff;
    if (v > 100)
        return 0xff;
    DAT_a802d29a = v;
    FUN_a00d7de0();
    FUN_a00d4998();
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}
