/* FUN_a00caf0c (leon2m 0xa00caf0c-0xa00cb1c8, 700 bytes), flags -mcpu=v8 -O3 -g.
 * Reads byte 9 of the receive record of the port (0xa802d040 for port 2, 0xa802d098 for port 3, else
 * 0xa802d0d0) and takes d = byte - '0'. d > 2 returns 0xff. d == 1 sets bit 15 of the halfword 0xa802cff4+0xe,
 * d == 0 clears it, d == 2 clears it, sets byte 0xa802d290+0x1ee to 1, sets bits 31 and 30 of the word
 * 0xa802d290+0x1dc and sets bit 1 of byte 0xa802b08e. Then bit 15 of the halfword 0xa802cff4+0x14 is cleared,
 * FUN_a00b2d04() and FUN_a00b88cc() run, followed by FUN_a00baa6c(port) (writes "5600+\r" into the port's
 * transmit buffer), FUN_a00ba950(port) (clears the port's receive bytes) and FUN_a00bab80(port, 6); returns 0.
 * The three port helpers (FUN_a00baa6c, FUN_a00ba950, FUN_a00bab80, written as in their own sources) are
 * inlined, so each copy repeats the port test. Source form: bit 15 of the halfwords at +0xe and +0x14 and
 * bits 31/30 of the word at +0x1dc are single-bit bit-fields; bit 31 is set before bit 30.
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
struct Scff4 { unsigned char p00[0xe]; unsigned short b15 : 1, r0e : 15; unsigned char p10[4]; unsigned short b15_14 : 1, r14 : 15; };
extern struct Scff4 DAT_a802cff4;
struct R290 { unsigned char p000[0x1dc]; unsigned int b31 : 1, b30 : 1, w1dc_lo : 30; unsigned char p1e0[0x1ee - 0x1e0];
              unsigned char b1ee; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802b08e;
extern void FUN_a00b2d04(void);
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
int FUN_a00caf0c(unsigned char port)
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
    if (d > 2)
        return 0xff;
    if (d == 1) {
        DAT_a802cff4.b15 = 1;
    } else if (d == 0) {
        DAT_a802cff4.b15 = 0;
    } else {
        DAT_a802cff4.b15 = 0;
        DAT_a802d290.b1ee = 1;
        DAT_a802d290.b31 = 1;
        DAT_a802d290.b30 = 1;
        DAT_a802b08e |= 2;
    }
    DAT_a802cff4.b15_14 = 0;
    FUN_a00b2d04();
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}
