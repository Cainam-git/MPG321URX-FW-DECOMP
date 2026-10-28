/* leon2m FUN_a00cb7f4 @ 0xa00cb7f4-0xa00cb9d4 (120 words).
 * Command handler: takes byte 9 of the port's receive record (0xa802d040 for port 2, 0xa802d098 for port 3,
 * 0xa802d0d0 otherwise) as an ASCII digit. A value outside '0'..'2' returns 0xff. Otherwise the digit value plus 1 is
 * stored in byte 0xa802d47d, FUN_a00dab90 and FUN_a00b88cc run, the reply "5600+\r" is written into the port's
 * transmit buffer (FUN_a00baa6c), the port's receive state is cleared (FUN_a00ba950), the 6-byte reply is sent
 * (FUN_a00bab80) and the function returns 0.
 * Same code as FUN_a00cb1c8 with another target byte and first callee.
 * Source form: the received byte is read into an unsigned char and widened into an unsigned int before the
 * range check, so the stored value (value - 0x2f) is computed from the widened copy. The three port helpers are defined in this file and inlined by GCC at -O3, which repeats the port
 * test in each of them.
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
extern unsigned char DAT_a802d47d;
extern void FUN_a01487e8(unsigned char, unsigned short, unsigned char *);
extern void FUN_a00dab90(void);
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
int FUN_a00cb7f4(unsigned char port)
{
    unsigned char c;
    unsigned int value;
    unsigned short diff;

    if (port == 2)
        c = DAT_a802d040[9];
    else if (port == 3)
        c = DAT_a802d098[9];
    else
        c = DAT_a802d0d0[9];
    value = c;
    diff = value - 0x30;
    if ((unsigned char)diff > 2)
        return 0xff;
    DAT_a802d47d = value - 0x2f;
    FUN_a00dab90();
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}
