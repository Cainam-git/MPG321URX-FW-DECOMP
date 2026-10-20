/* leon2m FUN_a00c7818 @ 0xa00c7818-0xa00c7a5c (145 words), flags -mcpu=v8 -O3 -g. Called by FUN_a00ccf34.
 * UART command handler: takes byte 9 of the port's receive record (0xa802d040 for port 2, 0xa802d098 for port 3,
 * 0xa802d0d0 otherwise) as an ASCII digit d. A value above 1 returns 0xff.
 * Otherwise, when byte 0xa802d290+0x1f is 0: d is stored in bit 20 of the word 0xa802d290+0xac, and when
 * FUN_a01445fc(byte 0xa802d290+0x1e) returns 0, FUN_a00d91fc(0), FUN_a01439d8(1, 1), FUN_a0148268(0, 1) and
 * FUN_a0148268(1, 1) run. Then FUN_a00b88cc() runs.
 * Then the reply "5600+\r" is written into the port's transmit buffer (FUN_a00baa6c), the receive state is
 * cleared (FUN_a00ba950), the 6-byte reply is sent (FUN_a00bab80) and the function returns 0.
 * Source form: the three port helpers are defined in this file and inlined by GCC at -O3 (as in FUN_a00c604c).
 * Bit 20 of the word is a 1-bit bit-field.
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
struct R290 { unsigned char p000[0x1e]; unsigned char b01e; unsigned char b01f; unsigned char p020[0xac - 0x20]; unsigned int hi : 11, b20 : 1, lo : 20; };
extern struct R290 DAT_a802d290;
extern unsigned char FUN_a01445fc(unsigned char);
extern void FUN_a00d91fc(int);
extern void FUN_a01439d8(int, int);
extern void FUN_a0148268(int, int);
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
int FUN_a00c7818(unsigned char port)
{
    unsigned char value;
    unsigned short diff;

    if (port == 2)
        value = DAT_a802d040[9];
    else if (port == 3)
        value = DAT_a802d098[9];
    else
        value = DAT_a802d0d0[9];
    diff = value - 0x30;
    if ((unsigned char)diff > 1)
        return 0xff;
    if (DAT_a802d290.b01f == 0) {
        DAT_a802d290.b20 = (unsigned char)diff;
        if (FUN_a01445fc(DAT_a802d290.b01e) == 0) {
            FUN_a00d91fc(0);
            FUN_a01439d8(1, 1);
            FUN_a0148268(0, 1);
            FUN_a0148268(1, 1);
        }
    }
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}
