/* DRV_HDMI_ModeDetect_FSM_FRL_Init (leon2s 0xa0096b08-0xa0096f60, 1112 bytes), flags -mcpu=v8 -Os -g.
 * u8 port; returns 0. DAT_a807db00 = 0x34-byte port records whose words +0, +0xc and +0x18 point to the
 * register word blocks r0, rc and r18 (volatile: every read-modify-write reloads); single bits are cleared by
 * FUN_a00a73d4 and set by FUN_a00a73ac (bit, address). Prints the "With Check Reset Flow" line (bit 2 of
 * DAT_a8078634), clears DAT_a807d650[port].st unless DAT_a807d648[port] is 9, clears DAT_a80790a8[port];
 * r0 + 2: bit 0xc clear, 0xd set, 0xf clear; r0 + 0x21 bit 0x14 clear. Bit 8 of r18[0] is cleared when byte
 * +1 of the 0xb0-byte record ARR_a807d680[port] is 1, 2 or 10, else set; bits 0xd, 0xc of r18[0] set;
 * r18[1] bits 16..31 = 0x3400; r0 + 2 bit 0xb set; r18 + 3 bit 1 cleared, bit 3 set. r18[5] bits 0..2 / 4..6:
 * 7 / 7 (and the "Set lock Weighting to 0x7 !!" print) when DAT_a8079048[port] is 1, else 2 / 2 when
 * DAT_a8079040[port] is 1, else 3 / 3; both flags cleared. Then a fixed sequence of field writes to r18[3],
 * [4], [5], [0x10..0x13], [6]; bit 0xe of r18[0] and 8 of r18[0x12] set, bit 8 of r18[0x1b] cleared, bit
 * 0x1d of r18[5] set, FUN_a00b160c(1), bit 0x1d cleared again, rc[0x19] bits 16..23 = 0xff, r18[0x14] =
 * 0x1000, r18[0x10] bits 24..31 cleared, r18[0x11] low byte = 0x60. Ends with DAT_a807909c[port] =
 * DAT_a8079094[port] = 0, DAT_a8079090[port] = 0 and DAT_a807d650[port].st = 2.
 * Source forms: the byte test is 'int x = (u8)(b - 1) < 2, y = b == 10; if (x | y)' (flag arithmetic); the
 * last four stores are written in the order that schedules to the firmware's order.
 */
struct port_rec {
    volatile unsigned int *r0;
    unsigned int _04[2];
    volatile unsigned int *rc;
    unsigned int _10[2];
    volatile unsigned int *r18;
    unsigned char _1c[0x34 - 0x1c];
};
struct eq_state {
    unsigned int st;
    unsigned char cnt;
    unsigned char _5[0x18 - 5];
};
extern struct port_rec DAT_a807db00[];
extern unsigned int DAT_a807d648[];
extern struct eq_state DAT_a807d650[];
extern unsigned char ARR_a807d680[];
extern unsigned char DAT_a80790a8[];
extern unsigned char DAT_a8079048[];
extern unsigned char DAT_a8079040[];
extern unsigned int DAT_a8079094[];
extern unsigned int DAT_a807909c[];
extern unsigned char DAT_a8079090[];
extern unsigned int DAT_a8078634;
extern int FUN_a0073044(const char *, ...);
extern int FUN_a00734c4(const char *);
extern void FUN_a00a73d4(unsigned int bit, volatile unsigned int *p);
extern void FUN_a00a73ac(unsigned int bit, volatile unsigned int *p);
extern void FUN_a00b160c(unsigned int);

int DRV_HDMI_ModeDetect_FSM_FRL_Init(unsigned char port)
{
    volatile unsigned int *p;
    unsigned char b;
    int x, y;

    if (DAT_a8078634 & 4)
        FUN_a0073044("[MODEDET]: Port%c With Check Reset Flow DRV_HDMI_ModeDetect_FSM_FRL_Init\n",
                     (char)(port + 'A'));
    if (DAT_a807d648[port] != 9)
        DAT_a807d650[port].st = 0;
    DAT_a80790a8[port] = 0;
    FUN_a00a73d4(0xc, DAT_a807db00[port].r0 + 2);
    FUN_a00a73ac(0xd, DAT_a807db00[port].r0 + 2);
    FUN_a00a73d4(0xf, DAT_a807db00[port].r0 + 2);
    FUN_a00a73d4(0x14, DAT_a807db00[port].r0 + 0x21);
    b = ARR_a807d680[port * 0xb0 + 1];
    x = (unsigned char)(b - 1) < 2;
    y = b == 10;
    if (x | y)
        FUN_a00a73d4(8, DAT_a807db00[port].r18);
    else
        FUN_a00a73ac(8, DAT_a807db00[port].r18);
    FUN_a00a73ac(0xd, DAT_a807db00[port].r18);
    FUN_a00a73ac(0xc, DAT_a807db00[port].r18);
    DAT_a807db00[port].r18[1] = (DAT_a807db00[port].r18[1] & 0xffff) | 0x34000000;
    FUN_a00a73ac(0xb, DAT_a807db00[port].r0 + 2);
    FUN_a00a73d4(1, DAT_a807db00[port].r18 + 3);
    FUN_a00a73ac(3, DAT_a807db00[port].r18 + 3);
    if (DAT_a8079048[port] == 1) {
        DAT_a807db00[port].r18[5] |= 7;
        DAT_a807db00[port].r18[5] |= 0x70;
        FUN_a00734c4("Set lock Weighting to 0x7 !!");
    } else if (DAT_a8079040[port] == 1) {
        DAT_a807db00[port].r18[5] = (DAT_a807db00[port].r18[5] & ~7) | 2;
        DAT_a807db00[port].r18[5] = (DAT_a807db00[port].r18[5] & ~0x70) | 0x20;
    } else {
        DAT_a807db00[port].r18[5] = (DAT_a807db00[port].r18[5] & ~7) | 3;
        DAT_a807db00[port].r18[5] = (DAT_a807db00[port].r18[5] & ~0x70) | 0x30;
    }
    DAT_a8079048[port] = 0;
    DAT_a8079040[port] = 0;
    DAT_a807db00[port].r18[3] = (DAT_a807db00[port].r18[3] & 0xfe00ffff) | 0x200000;
    DAT_a807db00[port].r18[4] = (DAT_a807db00[port].r18[4] & ~0x1ff) | 0x20;
    DAT_a807db00[port].r18[5] = (DAT_a807db00[port].r18[5] & 0xfe00ffff) | 0x10000;
    FUN_a00a73ac(0xe, DAT_a807db00[port].r18);
    DAT_a807db00[port].r18[0x11] = (DAT_a807db00[port].r18[0x11] & 0xffffff) | 0xb8000000;
    DAT_a807db00[port].r18[0x12] &= ~0xff;
    DAT_a807db00[port].r18[4] = (DAT_a807db00[port].r18[4] & 0xffff81ff) | 0x400;
    DAT_a807db00[port].r18[0x13] = (DAT_a807db00[port].r18[0x13] & 0xffff0000) | 0x100;
    FUN_a00a73ac(8, DAT_a807db00[port].r18 + 0x12);
    DAT_a807db00[port].r18[0x13] = (DAT_a807db00[port].r18[0x13] & 0xffffff) | 0x3000000;
    DAT_a807db00[port].r18[4] = (DAT_a807db00[port].r18[4] & ~0x1ff) | 4;
    DAT_a807db00[port].r18[4] = (DAT_a807db00[port].r18[4] & 0xffff81ff) | 0xa00;
    DAT_a807db00[port].r18[4] = (DAT_a807db00[port].r18[4] & ~0x7f0000) | 0x70000;
    DAT_a807db00[port].r18[4] = (DAT_a807db00[port].r18[4] & ~0x7f000000) | 0x5000000;
    DAT_a807db00[port].r18[6] = (DAT_a807db00[port].r18[6] & ~0xf) | 3;
    DAT_a807db00[port].r18[0x10] = (DAT_a807db00[port].r18[0x10] & 0xff0000ff) | 0x80000;
    FUN_a00a73d4(8, DAT_a807db00[port].r18 + 0x1b);
    FUN_a00a73ac(0x1d, DAT_a807db00[port].r18 + 5);
    FUN_a00b160c(1);
    FUN_a00a73d4(0x1d, DAT_a807db00[port].r18 + 5);
    DAT_a807db00[port].rc[0x19] = (DAT_a807db00[port].rc[0x19] & ~0xff0000) | 0xff0000;
    p = DAT_a807db00[port].r18;
    p[0x14] = 0x1000;
    p[0x10] &= 0xffffff;
    p[0x11] = (p[0x11] & ~0xff) | 0x60;
    DAT_a807909c[port] = 0;
    DAT_a8079094[port] = 0;
    DAT_a8079090[port] = 0;
    DAT_a807d650[port].st = 2;
    return 0;
}
