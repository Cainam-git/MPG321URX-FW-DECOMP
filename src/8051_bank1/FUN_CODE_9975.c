/* 8051_bank1 FUN_CODE_9975 @ 0x9975..0x9a43 (206 B)  OPTIMIZE(8,SPEED) LARGE.
 * FUN_CODE_9975(a, b): when bit 0 of a is set, TH1 = TL1 = -(unsigned char)((float)FUN_CODE_d7d2() * 2 / 384 / b
 * + 0.5); then m = 12000000.0 / b - 1 (unsigned int) is written high byte first to XDATA 0xF0F7/0xF0F8 when bit 2
 * of a is set, to 0xF033/0xF034 for bit 3 and to 0xF06F/0xF070 for bit 4. Float work through ?C?FCASTL, ?C?FPMUL,
 * ?C?FPDIV, ?C?FPADD, ?C?CASTF. References: 0xA816, 0xCD48, 0xCE66, 0xDAC5, 0xDAE0 (FUN_CODE_cd07 and FUN_CODE_ce4b
 * pass b = 4800).
 * LARGE block: a 0xA4B9, b 0xA4BA..0xA4BD; m and n in R4:R5.
 * Source forms: n = 0x9C3 (= 12000000 / 4800 - 1) is set at entry and never used for a result; the firmware keeps
 *   its 'MOV R5,#C3H; MOV R4,#09H' before the bit 0 test. The result of m is copied high byte first
 *   ('MOV R4,AR6; MOV R5,AR7').
 * Compiler aids (no code; each '?:' has two identical outcomes, Keil merges them and drops the test):
 *   - '(n == 0x9c3 ? FUN_CODE_d7d2() : FUN_CODE_d7d2())': this read of n before the first call gives n a register
 *     (R4:R5) with its store kept; without a read n gets an XDATA slot.
 *   - 'm = m == m ? m : m;' after the m assignment gives the high-byte-first copy (Keil otherwise copies R7 first).
 */
sfr TL1 = 0x8B;
sfr TH1 = 0x8D;
extern unsigned char xdata DAT_EXTMEM_f0f7, DAT_EXTMEM_f0f8, DAT_EXTMEM_f033, DAT_EXTMEM_f034, DAT_EXTMEM_f06f, DAT_EXTMEM_f070;
extern unsigned long FUN_CODE_d7d2(void);

void FUN_CODE_9975(unsigned char a, unsigned long b)
{
    unsigned int m, n;
    n = 0x9c3;
    if (a & 0x01) {
        TH1 = TL1 = -(unsigned char)((float)(n == 0x9c3 ? FUN_CODE_d7d2() : FUN_CODE_d7d2()) * 2 / 384 / b + 0.5);
    }
    m = 12000000.0 / b - 1;
    m = m == m ? m : m;
    if (a & 0x04) { DAT_EXTMEM_f0f7 = m >> 8; DAT_EXTMEM_f0f8 = m; }
    if (a & 0x08) { DAT_EXTMEM_f033 = m >> 8; DAT_EXTMEM_f034 = m; }
    if (a & 0x10) { DAT_EXTMEM_f06f = m >> 8; DAT_EXTMEM_f070 = m; }
}
