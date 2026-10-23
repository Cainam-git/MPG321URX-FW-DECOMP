/* leon2m FUN_a00c8c38 @ 0xa00c8c38-0xa00c91dc (361 words), flags -mcpu=v8 -O3 -g.
 * Command handler. When byte 0xa802d290+0x1f is 0 it returns 0xff. Otherwise it reads two 4-digit ASCII
 * decimal numbers from the port's receive record (bytes 6..9 and 10..13 of the record at 0xa802d040 for port 2,
 * 0xa802d098 for port 3, 0xa802d0d0 otherwise) into the halfwords 0xa802d290+0x54 and +0x56. Each halfword is
 * then limited to FUN_a014837c(0) - L0 and FUN_a014837c(1) - L1 respectively, where (L0, L1) depends on byte
 * 0xa802d290+0x31: 0 -> (1728, 972), 1 -> (1344, 756), other -> (960, 540). Then FUN_a00d7a70(1) and
 * FUN_a00b88cc() run, the reply "5600+\r" is written into the port's transmit buffer (FUN_a00baa6c), the port's
 * receive state is cleared (FUN_a00ba950), the 6-byte reply is sent (FUN_a00bab80) and the function returns 0.
 * Source form: the receive-record byte getter and the three port helpers are defined in this file and inlined by
 * GCC at -O3 (as in FUN_a00c1d54). The globals from 0xa802d290 on are members of one structure.
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
struct R290 { unsigned char p000[0x1f]; unsigned char b01f; unsigned char p020[0x31 - 0x20]; unsigned char b031;
              unsigned char p032[0x54 - 0x32]; unsigned short h054; unsigned short h056; };
extern struct R290 DAT_a802d290;
extern unsigned short FUN_a014837c(int);
extern void FUN_a00d7a70(int);

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
int FUN_a00c8c38(unsigned char port)
{
    unsigned short a, b;

    if (DAT_a802d290.b01f == 0)
        return 0xff;
    a = rx(port, 6) * 1000 + rx(port, 7) * 100 + rx(port, 8) * 10 + rx(port, 9) - '0' * 1111;
    b = rx(port, 10) * 1000 + rx(port, 11) * 100 + rx(port, 12) * 10 + rx(port, 13) - '0' * 1111;
    DAT_a802d290.h054 = a;
    DAT_a802d290.h056 = b;
    if (DAT_a802d290.b031 == 0) {
        if (DAT_a802d290.h054 > FUN_a014837c(0) - 1728)
            DAT_a802d290.h054 = FUN_a014837c(0) - 1728;
        if (DAT_a802d290.h056 > FUN_a014837c(1) - 972)
            DAT_a802d290.h056 = FUN_a014837c(1) - 972;
    } else if (DAT_a802d290.b031 == 1) {
        if (DAT_a802d290.h054 > FUN_a014837c(0) - 1344)
            DAT_a802d290.h054 = FUN_a014837c(0) - 1344;
        if (DAT_a802d290.h056 > FUN_a014837c(1) - 756)
            DAT_a802d290.h056 = FUN_a014837c(1) - 756;
    } else {
        if (DAT_a802d290.h054 > FUN_a014837c(0) - 960)
            DAT_a802d290.h054 = FUN_a014837c(0) - 960;
        if (DAT_a802d290.h056 > FUN_a014837c(1) - 540)
            DAT_a802d290.h056 = FUN_a014837c(1) - 540;
    }
    FUN_a00d7a70(1);
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}
