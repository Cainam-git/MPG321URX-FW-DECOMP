/* leon2m FUN_a00cc140 @ 0xa00cc140-0xa00cc760 (392 words), flags -mcpu=v8 -O3 -g.
 * UART command handler: copies bytes 6..18 of the port's receive record (0xa802d040 for port 2, 0xa802d098 for
 * port 3, 0xa802d0d0 otherwise) to bytes 3..15 of 0xa802d274, then adds bytes 6..18 as an 8-bit sum and compares
 * it with byte 19 of the record. When they are equal, the reply "5600+\r" is written into the port's transmit
 * buffer (FUN_a00baa6c) and FUN_a014aed0(0x30, 0xa802d274, 0x2e0, 0x1c) runs. When they differ, "5600" 0xee "\r"
 * is written into the buffer at 0xa802d078 for every port. Then the port's receive state is cleared
 * (FUN_a00ba950), the 6-byte reply is sent from the port's buffer (FUN_a00bab80) and the function returns 0.
 * Source form: the receive-record byte getter and the three port helpers are defined in this file and inlined by
 * GCC at -O3; the copy is 13 separate statements, the sum a loop that GCC unswitches per port.
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
extern unsigned char DAT_a802d274[];
extern int FUN_a014aed0(int, void *, int, int);

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
int FUN_a00cc140(unsigned char port)
{
    unsigned char i;
    unsigned char sum = 0;

    DAT_a802d274[3] = rx(port, 6);
    DAT_a802d274[4] = rx(port, 7);
    DAT_a802d274[5] = rx(port, 8);
    DAT_a802d274[6] = rx(port, 9);
    DAT_a802d274[7] = rx(port, 10);
    DAT_a802d274[8] = rx(port, 11);
    DAT_a802d274[9] = rx(port, 12);
    DAT_a802d274[10] = rx(port, 13);
    DAT_a802d274[11] = rx(port, 14);
    DAT_a802d274[12] = rx(port, 15);
    DAT_a802d274[13] = rx(port, 16);
    DAT_a802d274[14] = rx(port, 17);
    DAT_a802d274[15] = rx(port, 18);
    for (i = 6; i < 0x13; i++)
        sum += rx(port, i);
    if (sum == rx(port, 0x13)) {
        FUN_a00baa6c(port);
        FUN_a014aed0(0x30, DAT_a802d274, 0x2e0, 0x1c);
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
