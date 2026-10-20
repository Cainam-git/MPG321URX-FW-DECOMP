/* leon2m FUN_a00c25ac @ 0xa00c25ac-0xa00c29d8 (267 words).
 * UART command handler. Reads two 4-digit ASCII decimal numbers from the port's receive record (bytes 6..9 and
 * 10..13 of the record at 0xa802d040 for port 2, 0xa802d098 for port 3, 0xa802d0d0 otherwise), sets the first to
 * 3745 when it is above 3744, limits the second to 2052, and stores them in the halfwords 0xa802d43c and
 * 0xa802d43e. When the 2-bit field at bits 13..14 of
 * the halfword 0xa802cff8 is 0, it calls FUN_a0090fd8 and FUN_a0090fac, and calls FUN_a0090fd8 again when byte 0xa802d420
 * is 0, bit 0x1000 of word 0xa802d338 is clear, byte 0xa802d430 is 0 and bit 0x400000 of word 0xa802d33c is clear.
 * Then FUN_a00b88cc runs, the reply "5600+\r" is written, the port's receive state is cleared and the 6-byte reply
 * is sent. Returns 0.
 * Same code as FUN_a00c1d54 with other limits and 16-bit targets.
 * Source form: the receive-record byte getter and the three port helpers are defined in this file and inlined by
 * GCC at -O3, which repeats the port test for every byte read. The globals from 0xa802d290 on are fields of one
 * structure, so a single base register addresses them. The halfword test is a bit-field (a mask test swaps two
 * registers).
 */
struct G290 {
    unsigned char pad0[0xa8];
    unsigned int w0a8;          /* 0xa802d338 */
    unsigned int w0ac;          /* 0xa802d33c */
    unsigned char pad1[0x190 - 0xb0];
    unsigned char b190;         /* 0xa802d420 */
    unsigned char pad2[0x1a0 - 0x191];
    unsigned char b1a0;         /* 0xa802d430 */
    unsigned char pad4[0x1ac - 0x1a1];
    unsigned short h1ac;        /* 0xa802d43c */
    unsigned short h1ae;        /* 0xa802d43e */
};
extern struct G290 DAT_a802d290;
struct Scff8 { unsigned short b15 : 1; unsigned short f13 : 2; unsigned short rest : 13; };
extern struct Scff8 DAT_a802cff8;
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
extern void FUN_a01487e8(unsigned char, int, unsigned char *);
extern void FUN_a0090fd8(void);
extern void FUN_a0090fac(void);
extern void FUN_a00b88cc(void);

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
int FUN_a00c25ac(unsigned char port)
{
    unsigned short a, b;

    a = rx(port, 6) * 1000 + rx(port, 7) * 100 + rx(port, 8) * 10 + rx(port, 9) - '0' * 1111;
    b = rx(port, 10) * 1000 + rx(port, 11) * 100 + rx(port, 12) * 10 + rx(port, 13) - '0' * 1111;
    if (a > 3744)
        a = 3745;
    if (b > 2052)
        b = 2052;
    DAT_a802d290.h1ac = a;
    DAT_a802d290.h1ae = b;
    if (DAT_a802cff8.f13 == 0) {
        FUN_a0090fd8();
        FUN_a0090fac();
        if (DAT_a802d290.b190 == 0 && (DAT_a802d290.w0a8 & 0x1000) == 0 && DAT_a802d290.b1a0 == 0
            && (DAT_a802d290.w0ac & 0x400000) == 0)
            FUN_a0090fd8();
    }
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}
