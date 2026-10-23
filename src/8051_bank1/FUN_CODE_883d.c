/* 8051_bank1 module FUN_CODE_883d: FUN_CODE_d9d1 @ 0xd9d1 with its common-entry block FUN_CODE_d9c3 @ 0xd9c3,
 * FUN_CODE_dcd3 @ 0xdcd3 with its common-entry block FUN_CODE_dccf @ 0xdccf, FUN_CODE_883d @ 0x883d..0x8947,
 * FUN_CODE_c0a1 @ 0xc0a1..0xc103 and FUN_CODE_cf38 @ 0xcf38..0xcf73; one compile with OPTIMIZE(8,SPEED) LARGE.
 * FUN_CODE_d9d1(reg, val) / FUN_CODE_dcd3(reg, val): register writes XDATA 0x9A00[reg] = val / 0x9AB0[reg] = val
 *   through a generic pointer (p += reg; tail LJMP ?C?CSTPTR with A = val). The base of d9d1 is the array symbol
 *   (with the constant (xdata *)0x9a00 Keil knows R1 = 0 and emits MOV A,R1 / ADD A,R7).
 * Keil OPTIMIZE(8) reuse of common entry code builds both blocks only from callers in this module:
 *   FUN_CODE_dccf = 'LCALL FUN_CODE_dcd3; INC R7' from the call pairs dcd3(r, v); dcd3(r + 1, v) of FUN_CODE_883d;
 *   FUN_CODE_d9c3 = 'XDATA 0xD500 = A; dcd3(0, A); d9d1(0x54, 0x61)' from c0a1 and cf38 (callers load A = k).
 *   d9d1 and dcd3 are defined before their callers: Keil then knows that they keep R5 and R7 (883d passes
 *   consecutive register numbers with INC R7 and keeps R5 between the calls).
 * FUN_CODE_883d: a fixed sequence of FUN_CODE_d9d1 / FUN_CODE_dcd3 register writes, FUN_CODE_d2b4(1, 4),
 *   FUN_CODE_d61c(0x2E, 5, 1); bit 1 of XDATA 0xDCB0 set around FUN_CODE_d44e(1); XDATA 0xD502 = 0; bit 0 of 0xF400
 *   cleared; the low nibble of 0xF40D cleared when XDATA 0xD511 == 0x20. Then for two key pairs (7, 8) and
 *   (10, 9): r = FUN_CODE_d27f(first), or FUN_CODE_d27f(second) when that is 0xFF; for r != 0xFF the high nibble of
 *   r goes to XDATA 0xA755 / 0xA756, FUN_CODE_ad88(0 / 1) is called and FUN_CODE_8a51(0 / 1) when bit 0 of XDATA
 *   0xDCDF / 0xDCCF is clear. Finally the two bytes at XDATA 0xA753 are cleared.
 *   LARGE local: r at XDATA 0xA474 (stored after each call and read back).
 *   Source form: the bit-0 tests are int-typed, '(unsigned int)(x & 1) != 1', for the firmware's ANL / XRL / JZ
 *   (a char test gives JB ACC.0).
 *   volatile on 0xDCB0: read again between the set and the clear of bit 1 (hardware register).
 *   Caller: FUN_CODE_a57e (LCALL at 0xA595).
 * FUN_CODE_c0a1 (bit): XDATA 0xD523 = 0x83, 0x6033 = 0x40, d500 = 0x18 with dcd3(0, 0x18) and d9d1(0x54, 0x61),
 *   XDATA 0x604D..0x6051 = D0 02 80 80 40, FUN_CODE_d44e(50); returns 1 when bits 7..5 of FUN_CODE_dd74(0x11) are
 *   001, FUN_CODE_760c() is set and FUN_CODE_c3e4() > 100; otherwise 0x6033 = 0, 0xD523 = 0x83,
 *   0x604D/0x604E = 50 22 and returns 0.
 * FUN_CODE_cf38 (bit): XDATA 0xD523 = 0x83 (written twice, volatile), FUN_CODE_de66(), d500 = 0x10 with
 *   dcd3(0, 0x10) and d9d1(0x54, 0x61), FUN_CODE_d44e(50); returns 1 when FUN_CODE_dd74(0x11) & 0xE8 == 0x28 and
 *   FUN_CODE_c3e4() > 100; otherwise FUN_CODE_de71(), 0xD523 = 0x83 and returns 0.
 *   Callers of c0a1 and cf38: FUN_CODE_52be (LCALLs at 0x531B and 0x5329).
 */
extern unsigned char volatile xdata DAT_EXTMEM_dcb0;
extern unsigned char volatile xdata DAT_EXTMEM_d523;
extern unsigned char xdata DAT_EXTMEM_d500, DAT_EXTMEM_d502, DAT_EXTMEM_d511;
extern unsigned char xdata DAT_EXTMEM_f400, DAT_EXTMEM_f40d;
extern unsigned char xdata DAT_EXTMEM_dcdf, DAT_EXTMEM_dccf;
extern unsigned char xdata DAT_EXTMEM_a755, DAT_EXTMEM_a756;
extern unsigned char xdata DAT_EXTMEM_a753[2];
extern unsigned char xdata DAT_EXTMEM_6033;
extern unsigned char xdata DAT_EXTMEM_604d[];
extern unsigned char xdata DAT_EXTMEM_9a00[];
extern void FUN_CODE_d2b4(unsigned char a, unsigned char b);
extern void FUN_CODE_d61c(unsigned char reg, unsigned char mask, unsigned char on);
extern unsigned char FUN_CODE_d27f(unsigned char key);
extern void FUN_CODE_d44e(unsigned int n);
extern void FUN_CODE_ad88(unsigned char ch);
extern void FUN_CODE_8a51(unsigned char m);
extern void FUN_CODE_de66(void);
extern void FUN_CODE_de71(void);
extern unsigned char FUN_CODE_dd74(unsigned char reg);
extern unsigned int FUN_CODE_c3e4(void);
extern bit FUN_CODE_760c(void);

void FUN_CODE_d9d1(unsigned char reg, unsigned char val)
{
    unsigned char *p;
    p = DAT_EXTMEM_9a00;
    p += reg;
    *p = val;
}

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

bit FUN_CODE_c0a1(void)
{
    DAT_EXTMEM_d523 = 0x83;
    DAT_EXTMEM_6033 = 0x40;
    DAT_EXTMEM_d500 = 0x18;
    FUN_CODE_dcd3(0, 0x18);
    FUN_CODE_d9d1(0x54, 0x61);
    DAT_EXTMEM_604d[0] = 0xd0;
    DAT_EXTMEM_604d[1] = 0x02;
    DAT_EXTMEM_604d[2] = 0x80;
    DAT_EXTMEM_604d[3] = 0x80;
    DAT_EXTMEM_604d[4] = 0x40;
    FUN_CODE_d44e(0x32);
    if ((FUN_CODE_dd74(0x11) & 0xe0) == 0x20 && FUN_CODE_760c() && FUN_CODE_c3e4() > 100) return 1;
    DAT_EXTMEM_6033 = 0;
    DAT_EXTMEM_d523 = 0x83;
    DAT_EXTMEM_604d[0] = 0x50;
    DAT_EXTMEM_604d[1] = 0x22;
    return 0;
}

bit FUN_CODE_cf38(void)
{
    DAT_EXTMEM_d523 = 0x83;
    DAT_EXTMEM_d523 = 0x83;
    FUN_CODE_de66();
    DAT_EXTMEM_d500 = 0x10;
    FUN_CODE_dcd3(0, 0x10);
    FUN_CODE_d9d1(0x54, 0x61);
    FUN_CODE_d44e(0x32);
    if ((FUN_CODE_dd74(0x11) & 0xe8) == 0x28 && FUN_CODE_c3e4() > 100) return 1;
    FUN_CODE_de71();
    DAT_EXTMEM_d523 = 0x83;
    return 0;
}
