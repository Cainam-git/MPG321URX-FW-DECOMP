/* leon2m FUN_a00ca878 @ 0xa00ca878-0xa00cab68 (188 words), flags -mcpu=v8 -O3 -g.
 * Command handler: reads bytes 6, 7, 8 and 9 of the port's receive record (0xa802d040 for port 2, 0xa802d098
 * for port 3, 0xa802d0d0 otherwise) one after the other as ASCII digits. Byte 6 must be 0 or 1 and goes to bit 15
 * of the word 0xa802d290+0x1dc; byte 7 (0 or 1) to byte 0xa802d290+0x1e0; byte 8 (0 or 1) to byte
 * 0xa802d290+0x1e1; byte 9 (0..8) to byte 0xa802d290+0x1df. The first digit out of range returns 0xff (the
 * earlier values stay stored). Then FUN_a00dab20() and FUN_a00b88cc() run, the reply "5600+\r" is written into
 * the port's transmit buffer (FUN_a00baa6c), the port's receive state is cleared (FUN_a00ba950), the 6-byte reply
 * is sent (FUN_a00bab80) and the function returns 0.
 * Source form: the three port helpers are defined in this file and inlined by GCC at -O3 (as in FUN_a00c604c).
 * Each digit has its own port selection. Byte 0x1df is the low 8-bit field of the word at 0x1dc, so all four
 * destinations are members of one structure at 0xa802d290.
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
struct R290 { unsigned char p000[0x1dc]; unsigned int hi : 16, b15 : 1, mid : 7, f1df : 8;
              unsigned char b1e0; unsigned char b1e1; };
extern struct R290 DAT_a802d290;
extern void FUN_a00dab20(void);
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
int FUN_a00ca878(unsigned char port)
{
    unsigned char value;
    unsigned short diff;

    if (port == 2)
        value = DAT_a802d040[6];
    else if (port == 3)
        value = DAT_a802d098[6];
    else
        value = DAT_a802d0d0[6];
    diff = value - 0x30;
    if ((unsigned char)diff > 1)
        return 0xff;
    DAT_a802d290.b15 = (unsigned char)diff;
    if (port == 2)
        value = DAT_a802d040[7];
    else if (port == 3)
        value = DAT_a802d098[7];
    else
        value = DAT_a802d0d0[7];
    diff = value - 0x30;
    if ((unsigned char)diff > 1)
        return 0xff;
    DAT_a802d290.b1e0 = diff;
    if (port == 2)
        value = DAT_a802d040[8];
    else if (port == 3)
        value = DAT_a802d098[8];
    else
        value = DAT_a802d0d0[8];
    diff = value - 0x30;
    if ((unsigned char)diff > 1)
        return 0xff;
    DAT_a802d290.b1e1 = diff;
    if (port == 2)
        value = DAT_a802d040[9];
    else if (port == 3)
        value = DAT_a802d098[9];
    else
        value = DAT_a802d0d0[9];
    diff = value - 0x30;
    if ((unsigned char)diff > 8)
        return 0xff;
    DAT_a802d290.f1df = diff;
    FUN_a00dab20();
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}
