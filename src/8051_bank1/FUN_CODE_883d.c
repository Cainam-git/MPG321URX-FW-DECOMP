/* 8051_bank1 module FUN_CODE_883d: FUN_CODE_883d @ 0x883d..0x8947 (266 bytes) and FUN_CODE_dcd3 @ 0xdcd3 with its
 * common-entry block FUN_CODE_dccf @ 0xdccf (4 bytes), one compile with OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC).
 * FUN_CODE_dcd3(reg, val): register write, twin of FUN_CODE_dd74: XDATA 0x9AB0[reg] = val through a generic pointer
 *   (p += reg; tail LJMP ?C?CSTPTR at 0x06EA with A = val).
 * FUN_CODE_dccf = 'LCALL FUN_CODE_dcd3; INC R7' in front of dcd3 (Keil OPTIMIZE(8) reuse of common entry code):
 *   built from the three call pairs dcd3(r, v); dcd3(r + 1, v) of FUN_CODE_883d (r = 0x18, 0x1C, 0x1E), which Keil
 *   only shares when FUN_CODE_dcd3 is in the same module; FUN_CODE_883d is its only user.
 * FUN_CODE_883d: a fixed sequence of FUN_CODE_d9d1 / FUN_CODE_dcd3 register writes, FUN_CODE_d2b4(1, 4),
 *   FUN_CODE_d61c(0x2E, 5, 1); bit 1 of XDATA 0xDCB0 set around FUN_CODE_d44e(1); XDATA 0xD502 = 0; bit 0 of 0xF400
 *   cleared; the low nibble of 0xF40D cleared when XDATA 0xD511 == 0x20. Then for two key pairs (7, 8) and
 *   (10, 9): r = FUN_CODE_d27f(first), or FUN_CODE_d27f(second) when that is 0xFF; for r != 0xFF the high nibble of
 *   r goes to XDATA 0xA755 / 0xA756, FUN_CODE_ad88(0 / 1) is called and FUN_CODE_8a51(0 / 1) when bit 0 of XDATA
 *   0xDCDF / 0xDCCF is clear. Finally the two bytes at XDATA 0xA753 are cleared.
 *   LARGE local: r at XDATA 0xA474 (stored after each call and read back). R7 and R5 stay across the calls
 *   (REGFILE(R.ORC)), so consecutive register numbers are passed with INC R7.
 *   Source form: the bit-0 tests are int-typed, '(unsigned int)(x & 1) != 1', for the firmware's ANL / XRL / JZ
 *   (a char test gives JB ACC.0).
 *   volatile on 0xDCB0: read again between the set and the clear of bit 1 (hardware register, as in FUN_CODE_a1fe).
 * Caller of FUN_CODE_883d: FUN_CODE_a57e (LCALL at 0xA595).
 */
extern unsigned char volatile xdata DAT_EXTMEM_dcb0;
extern unsigned char xdata DAT_EXTMEM_d502;
extern unsigned char xdata DAT_EXTMEM_f400;
extern unsigned char xdata DAT_EXTMEM_f40d;
extern unsigned char xdata DAT_EXTMEM_d511;
extern unsigned char xdata DAT_EXTMEM_dcdf;
extern unsigned char xdata DAT_EXTMEM_dccf;
extern unsigned char xdata DAT_EXTMEM_a755, DAT_EXTMEM_a756;
extern unsigned char xdata DAT_EXTMEM_a753[2];
extern void FUN_CODE_d9d1(unsigned char reg, unsigned char val);
extern void FUN_CODE_d2b4(unsigned char a, unsigned char b);
extern void FUN_CODE_d61c(unsigned char reg, unsigned char mask, unsigned char on);
extern unsigned char FUN_CODE_d27f(unsigned char key);
extern void FUN_CODE_d44e(unsigned int n);
extern void FUN_CODE_ad88(unsigned char ch);
extern void FUN_CODE_8a51(unsigned char m);

void FUN_CODE_dcd3(unsigned char reg, unsigned char val)
{
    unsigned char *p;
    p = (unsigned char xdata *)0x9ab0;
    p += reg;
    *p = val;
}

void FUN_CODE_883d(void)
{
    unsigned char r;

    FUN_CODE_d9d1(0x54, 0x24);
    FUN_CODE_d9d1(0x55, 0xc0);
    FUN_CODE_d9d1(0x56, 0x42);
    FUN_CODE_dcd3(0x16, 0x00);
    FUN_CODE_dcd3(0x17, 0x1f);
    FUN_CODE_dcd3(0x1a, 0x04);
    FUN_CODE_d2b4(1, 0x04);
    FUN_CODE_dcd3(0x18, 0x7e);
    FUN_CODE_dcd3(0x19, 0x7e);
    FUN_CODE_dcd3(0x1c, 0x00);
    FUN_CODE_dcd3(0x1d, 0x00);
    FUN_CODE_dcd3(0x1e, 0xff);
    FUN_CODE_dcd3(0x1f, 0xff);
    FUN_CODE_dcd3(0x10, 0xc5);
    FUN_CODE_d61c(0x2e, 0x05, 1);
    FUN_CODE_d9d1(0x5b, 0x4a);
    FUN_CODE_d9d1(0x5c, 0x02);
    DAT_EXTMEM_dcb0 |= 0x02;
    FUN_CODE_d44e(1);
    DAT_EXTMEM_dcb0 &= ~0x02;
    DAT_EXTMEM_d502 = 0;
    DAT_EXTMEM_f400 &= 0xfe;
    if (DAT_EXTMEM_d511 == 0x20)
        DAT_EXTMEM_f40d &= 0xf0;
    r = FUN_CODE_d27f(7);
    if (r == 0xff)
        r = FUN_CODE_d27f(8);
    if (r != 0xff) {
        DAT_EXTMEM_a755 = r >> 4;
        FUN_CODE_ad88(0);
        if ((unsigned int)(DAT_EXTMEM_dcdf & 1) != 1)
            FUN_CODE_8a51(0);
    }
    r = FUN_CODE_d27f(10);
    if (r == 0xff)
        r = FUN_CODE_d27f(9);
    if (r != 0xff) {
        DAT_EXTMEM_a756 = r >> 4;
        FUN_CODE_ad88(1);
        if ((unsigned int)(DAT_EXTMEM_dccf & 1) != 1)
            FUN_CODE_8a51(1);
    }
    DAT_EXTMEM_a753[0] = 0;
    DAT_EXTMEM_a753[1] = 0;
}
