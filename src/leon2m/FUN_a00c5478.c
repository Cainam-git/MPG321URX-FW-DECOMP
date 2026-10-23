/* leon2m FUN_a00c5478 @ 0xa00c5478-0xa00c573c (146 words), flags -mcpu=v8 -O3 -g.
 * Command handler: takes byte 9 of the port's receive record (0xa802d040 for port 2, 0xa802d098 for port 3,
 * 0xa802d0d0 otherwise) as an ASCII digit d. A value above 8 returns 0xff. For d = 4, 5 or 6, FUN_a00d7d48() runs
 * and a nonzero result returns 0xff. Then bit 11 (0x800) of the word 0xa802d290+0xa8 is set, and for d = 0..7
 * byte 0xa802d290+0x181 = d (a switch with a jump table at 0xa00ba634, image-relative). Then FUN_a00db738() and
 * FUN_a00b88cc() run, the reply "5600+\r" is written into the port's transmit buffer (FUN_a00baa6c), the port's
 * receive state is cleared (FUN_a00ba950), the 6-byte reply is sent (FUN_a00bab80) and the function returns 0.
 * Source form: the three port helpers are defined in this file and inlined by GCC at -O3 (as in FUN_a00c604c).
 * The digit value is copied into an unsigned char local. The test for 4, 5 and 6 is an if/else chain with the
 * same body three times (an || chain is folded into one range test).
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
struct R290 { unsigned char p000[0xa8]; unsigned int w0a8; unsigned char p0ac[0x181 - 0xac]; unsigned char b181; };
extern struct R290 DAT_a802d290;
extern int FUN_a00d7d48(void);
extern void FUN_a00db738(void);
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
int FUN_a00c5478(unsigned char port)
{
    unsigned char value;
    unsigned short diff;
    unsigned char d;

    if (port == 2)
        value = DAT_a802d040[9];
    else if (port == 3)
        value = DAT_a802d098[9];
    else
        value = DAT_a802d0d0[9];
    diff = value - 0x30;
    d = diff;
    if (d > 8)
        return 0xff;
    if (d == 4) {
        if (FUN_a00d7d48() != 0)
            return 0xff;
    } else if (d == 5) {
        if (FUN_a00d7d48() != 0)
            return 0xff;
    } else if (d == 6) {
        if (FUN_a00d7d48() != 0)
            return 0xff;
    }
    DAT_a802d290.w0a8 |= 0x800;
    switch (d) {
    case 0:
        DAT_a802d290.b181 = 0;
        break;
    case 1:
        DAT_a802d290.b181 = 1;
        break;
    case 2:
        DAT_a802d290.b181 = 2;
        break;
    case 3:
        DAT_a802d290.b181 = 3;
        break;
    case 4:
        DAT_a802d290.b181 = 4;
        break;
    case 5:
        DAT_a802d290.b181 = 5;
        break;
    case 6:
        DAT_a802d290.b181 = 6;
        break;
    case 7:
        DAT_a802d290.b181 = 7;
        break;
    }
    FUN_a00db738();
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}
