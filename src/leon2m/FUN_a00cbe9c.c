/* leon2m FUN_a00cbe9c @ 0xa00cbe9c-0xa00cc140 (169 words), flags -mcpu=v8 -O3 -g. Called by FUN_a00ccf34.
 * Command handler: adds bytes 6..17 of the port's receive record (0xa802d040 for port 2, 0xa802d098 for
 * port 3, 0xa802d0d0 otherwise) as an 8-bit sum and compares it with byte 18 of the record. When they are equal,
 * the reply "5600+\r" is written into the port's transmit buffer (FUN_a00baa6c) and FUN_a0082c0c() runs. When
 * they differ, "5600" 0xee "\r" is written into the buffer at 0xa802d078 for every port. Then the port's receive
 * state is cleared (FUN_a00ba950), the 6-byte reply is sent from the port's buffer (FUN_a00bab80) and the
 * function returns 0.
 * Source form: the receive-record byte getter and the three port helpers are defined in this file and inlined by
 * GCC at -O3, which unswitches the summing loop per port.
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
extern void FUN_a0082c0c(void);

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
int FUN_a00cbe9c(unsigned char port)
{
    unsigned char i;
    unsigned char sum = 0;

    for (i = 6; i < 0x12; i++)
        sum += rx(port, i);
    if (sum == rx(port, 0x12)) {
        FUN_a00baa6c(port);
        FUN_a0082c0c();
    } else {
        DAT_a802d078[0] = '5';
        DAT_a802d078[1] = '6';
        DAT_a802d078[2] = '0';
        DAT_a802d078[3] = '0';
        DAT_a802d078[4] = 0xee;
        DAT_a802d078[5] = '\r';
    }
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}
