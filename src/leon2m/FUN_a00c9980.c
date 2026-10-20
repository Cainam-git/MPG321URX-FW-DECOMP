/* leon2m FUN_a00c9980 @ 0xa00c9980-0xa00c9be0 (152 words), flags -mcpu=v8 -O3 -g. Called by FUN_a00ccf34.
 * UART command handler: takes byte 9 of the port's receive record (0xa802d040 for port 2, 0xa802d098 for port 3,
 * 0xa802d0d0 otherwise) as an ASCII digit d. A value above 3, or byte 0xa802d2af == 0, returns 0xff. Otherwise
 * d selects the action: 0 FUN_a00a10c8(), 1 FUN_a009811c(), 2 FUN_a00a0ff0() then FUN_a00d47b0(), 3 FUN_a00a105c()
 * then FUN_a00d47b0(). Then FUN_a00b88cc() runs, the reply "5600+\r" is written into the port's transmit buffer
 * (FUN_a00baa6c), the port's receive state is cleared (FUN_a00ba950), the 6-byte reply is sent (FUN_a00bab80) and
 * the function returns 0.
 * Source form: the three port helpers are defined in this file and inlined by GCC at -O3 (as in FUN_a00c604c).
 * The digit value is copied into an unsigned char local and the actions are an if/else chain on it (a switch
 * gives a compare tree; testing the cast directly gives btst for the 0 case).
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
extern unsigned char DAT_a802d2af;
extern void FUN_a00a10c8(void);
extern void FUN_a009811c(void);
extern void FUN_a00a0ff0(void);
extern void FUN_a00a105c(void);
extern void FUN_a00d47b0(void);
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
int FUN_a00c9980(unsigned char port)
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
    if (d > 3)
        return 0xff;
    if (DAT_a802d2af == 0)
        return 0xff;
    if (d == 0)
        FUN_a00a10c8();
    else if (d == 1)
        FUN_a009811c();
    else if (d == 2) {
        FUN_a00a0ff0();
        FUN_a00d47b0();
    } else if (d == 3) {
        FUN_a00a105c();
        FUN_a00d47b0();
    }
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}
