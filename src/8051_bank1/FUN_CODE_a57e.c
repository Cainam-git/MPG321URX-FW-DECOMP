/* 8051_bank1 FUN_CODE_a57e @ 0xa57e..0xa627 (169 bytes), OPTIMIZE(8,SPEED) LARGE.
 * When the index XDATA 0xA64D is 0x1F it is set to 0, the 16-bit count from FUN_CODE_d94a is stored to XDATA
 * 0xA64E/0xA64F and FUN_CODE_b802 and FUN_CODE_883d are called. Then a FUN_CODE_52be result other than 0x0D is
 * returned. For 0x0D: when (FUN_CODE_d94a() - stored count) / 10 is greater than byte 1 of entry [0xA64D] of the
 * 3-byte table at 0xA62F, the index advances (back to 0 when the next entry's low five bits are 0x1F or the index
 * reaches 10), the count is stored again and FUN_CODE_b802 is called. Finally the FUN_CODE_52be result is returned
 * (0x0D as the constant).
 * LARGE local: r at XDATA 0xA473 (re-read from there for the return).
 * Source form: the end-marker test compares through a char cast, '(char)m == 0x1f', which gives the firmware's
 *   'MOV R7,A / CJNE R7,#1FH' (a plain compare tests A).
 * Caller: FUN_CODE_3fe7 (LCALL at 0x410E). Table layout as in FUN_CODE_ccc2 and FUN_CODE_b802.
 */
struct ent3 { unsigned char a, b, c; };
extern struct ent3 xdata DAT_EXTMEM_a62f[10];
extern unsigned char xdata DAT_EXTMEM_a64d;
extern unsigned int xdata DAT_EXTMEM_a64e;
extern unsigned int FUN_CODE_d94a(void);
extern void FUN_CODE_b802(void);
extern void FUN_CODE_883d(void);
extern unsigned char FUN_CODE_52be(void);

unsigned char FUN_CODE_a57e(void)
{
    unsigned char m;
    unsigned char r;

    if (DAT_EXTMEM_a64d == 0x1f) {
        DAT_EXTMEM_a64d = 0;
        DAT_EXTMEM_a64e = FUN_CODE_d94a();
        FUN_CODE_b802();
        FUN_CODE_883d();
    }
    if ((r = FUN_CODE_52be()) != 0x0d)
        return r;
    if ((FUN_CODE_d94a() - DAT_EXTMEM_a64e) / 10 > DAT_EXTMEM_a62f[DAT_EXTMEM_a64d].b) {
        DAT_EXTMEM_a64d++;
        DAT_EXTMEM_a64e = FUN_CODE_d94a();
        m = DAT_EXTMEM_a62f[DAT_EXTMEM_a64d].a & 0x1f;
        if ((char)m == 0x1f)
            DAT_EXTMEM_a64d = 0;
        if (DAT_EXTMEM_a64d == 10)
            DAT_EXTMEM_a64d = 0;
        FUN_CODE_b802();
    }
    if ((r = FUN_CODE_52be()) != 0x0d)
        return r;
    return 0x0d;
}
