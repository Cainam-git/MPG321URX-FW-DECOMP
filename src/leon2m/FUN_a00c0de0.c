/* leon2m FUN_a00c0de0 @ 0xa00c0de0-0xa00c0ff4 (133 words). Caller: FUN_a00ccf34.
 * Reads byte 9 of the port's record (0xa802d040 for port 2, 0xa802d098 for port 3, 0xa802d0d0 otherwise) and
 * calls FUN_a0143c14(0). Byte '0': returns 0xff when FUN_a0143c14 returned 0, else sets byte 0xa802b09b to 1.
 * Byte '1': returns 0xff when bit 31 of word 0xa802e1a0 is set, else sets byte 0xa802b09b to 1. Any other byte
 * changes nothing. Then FUN_a00baa6c(port) writes "5600+\r" into the port's 6-byte buffer, FUN_a00ba950(port)
 * clears the port's state bytes, FUN_a00bab80(port, 6) passes the buffer to FUN_a01487e8, and the function
 * returns 0.
 * Source form: the three port helpers are defined in this file and inlined by GCC at -O3; the byte comes from a
 * fourth inlined port helper rx_char(port, 9) (u8) into 'int c' before the FUN_a0143c14 call (and 0xff at
 * 0xa00c0e00), and d = c - '0' (u8) is taken after it; bit 31 of 0xa802e1a0 is read as a 1-bit bit-field.
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
extern unsigned char DAT_a802b09b;
struct InInfo {
    unsigned int b31 : 1, rest : 31;
};
extern struct InInfo DAT_a802e1a0;
extern unsigned char FUN_a0143c14(unsigned char);
extern void FUN_a01487e8(unsigned char, unsigned short, unsigned char *);

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
static unsigned char rx_char(unsigned char port, int i)
{
    if (port == 2)
        return DAT_a802d040[i];
    else if (port == 3)
        return DAT_a802d098[i];
    else
        return DAT_a802d0d0[i];
}

int FUN_a00c0de0(unsigned char port)
{
    int c;
    unsigned char d;
    unsigned char r;

    c = rx_char(port, 9);
    r = FUN_a0143c14(0);
    d = c - '0';
    switch (d) {
    case 0:
        if (r == 0)
            return 0xff;
        DAT_a802b09b = 1;
        break;
    case 1:
        if (DAT_a802e1a0.b31)
            return 0xff;
        DAT_a802b09b = 1;
        break;
    }
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}
