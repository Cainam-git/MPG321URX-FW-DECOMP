/* leon2m FUN_a00c6424 @ 0xa00c6424-0xa00c6690 (620 bytes), flags -mcpu=v8 -O3 -g. Called by FUN_a00ccf34.
 * Converts the three ASCII digits at bytes 7-9 of the port's receive record (0xa802d040 for port 2, 0xa802d098
 * for port 3, 0xa802d0d0 otherwise) with FUN_a00bae38. A result of 0xff (not digits), a non-zero word
 * 0xa802d290+0xb0, a set bit 31 of word 0xa802d290+0x11c or a value above 100 returns 0xff. Otherwise the value
 * is stored in byte 0xa802d290+0x09, FUN_a00d8cd4(), FUN_a00d4998() and FUN_a00b88cc() run, the reply "5600+\r"
 * is written into the port's transmit buffer (FUN_a00baa6c), the port's receive state is cleared (FUN_a00ba950),
 * the 6-byte reply is sent (FUN_a00bab80) and the function returns 0.
 * Source form: FUN_a00bae38 and the three port helpers are defined in this file and inlined by GCC at -O3 (as in
 * FUN_a00c6690); the two record tests are one '&&' condition nested inside the 0xff test, with bit 31 read as a
 * 1-bit bit-field, and the shared 0xff return is the last statement.
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
struct R290 {
    unsigned char p000[9];
    unsigned char b009;
    unsigned char p00a[0xb0 - 0xa];
    unsigned int w0b0;
    unsigned char p0b4[0x11c - 0xb4];
    struct { unsigned int b31 : 1, p : 26, b4 : 1, r : 4; } f11c;
};
extern struct R290 DAT_a802d290;
extern void FUN_a00d8cd4(void);
extern void FUN_a00d4998(void);
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
int FUN_a00c6424(unsigned char port)
{
    unsigned char v;

    v = FUN_a00bae38(port);
    if (v != 0xff) {
        if (DAT_a802d290.w0b0 == 0 && !DAT_a802d290.f11c.b31) {
            if (v > 100)
                return 0xff;
            DAT_a802d290.b009 = v;
            FUN_a00d8cd4();
            FUN_a00d4998();
            FUN_a00b88cc();
            FUN_a00baa6c(port);
            FUN_a00ba950(port);
            FUN_a00bab80(port, 6);
            return 0;
        }
    }
    return 0xff;
}
