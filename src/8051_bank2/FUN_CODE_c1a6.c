/* 8051_bank2 FUN_CODE_c1a6 @ 0xc1a6  MATCH (OPTIMIZE(8,SPEED) LARGE, hand)
 *
 * Per-region loop of the update agent, selected by mode (R7, kept in the LARGE-model XDATA block at 0x08EE):
 *   bit 0 set        : FUN_CODE_e384(), then tail call e4bf with the XDATA buffer 0x0436.
 *   bit 2 and !bit 1 : tail call FUN_CODE_dd1a(1).
 *   bit 2 and bit 1  : n = (XDATA[0x0644] << 8) >> 3 (0x0644 = byte 4 of the flash-chip record at 0x0640, see
 *                      FUN_CODE_0003); FUN_CODE_e331(8 if that byte is 0x10 else 0); then i = n/2 .. n-1 step 16.
 *   otherwise        : i = 0 .. n-1 step 16 with the same n.
 *   Loop body: if (i % 16 == 0) LCALL e1b5; LCALL df76; LCALL e4b9.
 * IMPORTANT for readers: e1b5 / df76 / e4b9 / e4bf are not C functions but shared code fragments that fall into the
 * real callee (the image was built with code packing):
 *   e1b5 = R7 = (unsigned char)(R4:R5 >> 4) -> falls into FUN_CODE_e1c1; R4:R5 hold i there, so = e1c1(i >> 4).
 *   df76 = R7 = XDATA[0x08F2] (low byte of this function's i), R5 = R7 + 0x0E -> falls into FUN_CODE_df7f,
 *          so = df7f(i, i + 14).
 *   e4b9 = R1..R3 = xdata 0x0436; e4bf = R7 = 0x6E, LCALL FUN_CODE_bba9(0x6E, buf), LJMP FUN_CODE_e44b(2).
 * They are declared void(void) here because that is exactly what the call sites do; the compiled code leaves i in
 * R4:R5 and in XDATA 0x08F1..0x08F2 at those calls just as the firmware does (LARGE block base 0x08EE agrees).
 * Keil idiom: the two e331 calls 'if (x == 0x10) e331(8); else e331(0);' (a ?: gives MOV R7,#0 instead of CLR A /
 * MOV R7,A); n written as (x << 8) >> 3 gives the 3-step RRC loop (x << 5 gives MUL AB).
 */
extern unsigned char xdata DAT_EXTMEM_0436[];
extern unsigned char xdata DAT_EXTMEM_0644;
extern void FUN_CODE_e384(void);
extern void FUN_CODE_e4bf(unsigned char *p);
extern void FUN_CODE_dd1a(unsigned char a);
extern void FUN_CODE_e331(unsigned char a);
extern void FUN_CODE_e1b5(void);
extern void FUN_CODE_df76(void);
extern void FUN_CODE_e4b9(void);

void FUN_CODE_c1a6(unsigned char mode)
{
    unsigned int n;
    unsigned int i;
    if (mode & 1) {
        FUN_CODE_e384();
        FUN_CODE_e4bf(DAT_EXTMEM_0436);
        return;
    }
    if ((mode & 4) && !(mode & 2)) {
        FUN_CODE_dd1a(1);
        return;
    }
    if ((mode & 4) && (mode & 2)) {
        n = ((unsigned int)DAT_EXTMEM_0644 << 8) >> 3;
        if (DAT_EXTMEM_0644 == 0x10) FUN_CODE_e331(8); else FUN_CODE_e331(0);
        for (i = n >> 1; i < n; i += 16) {
            if ((i & 0x0f) == 0) FUN_CODE_e1b5();
            FUN_CODE_df76();
            FUN_CODE_e4b9();
        }
    } else {
        n = ((unsigned int)DAT_EXTMEM_0644 << 8) >> 3;
        for (i = 0; i < n; i += 16) {
            if ((i & 0x0f) == 0) FUN_CODE_e1b5();
            FUN_CODE_df76();
            FUN_CODE_e4b9();
        }
    }
}
