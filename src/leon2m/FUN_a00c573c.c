/* leon2m FUN_a00c573c @ 0xa00c573c-0xa00c5a00 (177 words), flags -mcpu=v8 -O3 -g. Called by FUN_a00ccf34.
 * Sets byte 0xa802d290+0x11 to 3 when it is not 3 already. Then the bytes 7, 8 and 9 of the port's receive record
 * (0xa802d040 for port 2, 0xa802d098 for port 3, 0xa802d0d0 otherwise) are read as ASCII digits with
 * FUN_a00c0adc, FUN_a00c0b34 and FUN_a00c0b8c (value - '0', 0xff when above 100) and stored to bytes
 * 0xa802d290+0x12, +0x13 and +0x14; the first 0xff returns 0xff (the earlier values stay stored). Then
 * FUN_a00d9764() and FUN_a00b88cc() run, the reply "5600+\r" is written into the port's transmit buffer
 * (FUN_a00baa6c), the port's receive state is cleared (FUN_a00ba950), the 6-byte reply is sent (FUN_a00bab80) and
 * the function returns 0.
 * Source form: the three digit functions and the three port helpers are the matched same-file functions, defined
 * here and inlined by GCC at -O3 (as in FUN_a00ca878); the digit results go into an unsigned char local.
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
struct R290 { unsigned char p000[0x11]; unsigned char b011; unsigned char b012; unsigned char b013; unsigned char b014; };
extern struct R290 DAT_a802d290;
extern void FUN_a00d9764(void);

int FUN_a00c0adc(unsigned char port)
{
    unsigned int value;
    unsigned short diff;

    if (port == 2)
        value = DAT_a802d040[7];
    else if (port == 3)
        value = DAT_a802d098[7];
    else
        value = DAT_a802d0d0[7];
    diff = value - 0x30;
    if ((unsigned char)diff > 100)
        return 0xff;
    return diff & 0xff;
}

int FUN_a00c0b34(unsigned char port)
{
    unsigned int value;
    unsigned short diff;

    if (port == 2)
        value = DAT_a802d040[8];
    else if (port == 3)
        value = DAT_a802d098[8];
    else
        value = DAT_a802d0d0[8];
    diff = value - 0x30;
    if ((unsigned char)diff > 100)
        return 0xff;
    return diff & 0xff;
}

int FUN_a00c0b8c(unsigned char port)
{
    unsigned int value;
    unsigned short diff;

    if (port == 2)
        value = DAT_a802d040[9];
    else if (port == 3)
        value = DAT_a802d098[9];
    else
        value = DAT_a802d0d0[9];
    diff = value - 0x30;
    if ((unsigned char)diff > 100)
        return 0xff;
    return diff & 0xff;
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
int FUN_a00c573c(unsigned char port)
{
    unsigned char v;

    if (DAT_a802d290.b011 != 3)
        DAT_a802d290.b011 = 3;
    v = FUN_a00c0adc(port);
    if (v == 0xff)
        return 0xff;
    DAT_a802d290.b012 = v;
    v = FUN_a00c0b34(port);
    if (v == 0xff)
        return 0xff;
    DAT_a802d290.b013 = v;
    v = FUN_a00c0b8c(port);
    if (v == 0xff)
        return 0xff;
    DAT_a802d290.b014 = v;
    FUN_a00d9764();
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}
