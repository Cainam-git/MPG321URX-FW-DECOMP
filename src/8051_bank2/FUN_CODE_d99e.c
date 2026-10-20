/* 8051_bank2 FUN_CODE_d99e @ 0xd99e  BYTE-EXACT under OPTIMIZE(8,SPEED) LARGE (first C, MATCH exact None
 * 100/100). Only caller: FUN_CODE_9f8f at 0xa0d4, 'FUN_CODE_d99e((i >> 5) & 1)'.
 * When XDATA 0x06F2 == 1: reg = (0x06F3 << 8) | 0x06F4 (16-bit scaler register address, built in the LARGE local
 * at XDATA 0x08FE; param a at 0x08FD) and FUN_CODE_da8a(reg, v) (service-bus register write, see FUN_CODE_e21d)
 * with v = XDATA 0x06F5 for a == 0 and XDATA 0x06F6 for a == 1; any other a or 0x06F2 != 1: nothing.
 * So 0x06F2..0x06F6 = enable flag, register address hi / lo, value for state 0, value for state 1 (a record of
 * five bytes).
 * Tail 'LCALL da8a; RET': the two arms end the same (MOVX A,@DPTR; MOV R5,A; LCALL da8a) and Keil cross-jumps
 * them (SJMP 0xd9fc), the failing tests jump to the RET (0xda01) -> no tail LJMP, no aid needed. The early-return
 * form 'if (0x06F2 != 1) return;' also matches. '(reg << 8) + 0x06F4' is 108 B.
 */
extern unsigned char xdata DAT_EXTMEM_06f2, DAT_EXTMEM_06f3, DAT_EXTMEM_06f4, DAT_EXTMEM_06f5, DAT_EXTMEM_06f6;
unsigned char FUN_CODE_da8a(unsigned int reg, unsigned char val);
void FUN_CODE_d99e(unsigned char a)
{
    unsigned int reg;
    if (DAT_EXTMEM_06f2 == 1) {
        if (a == 0) {
            reg = DAT_EXTMEM_06f3;
            reg = (reg << 8) | DAT_EXTMEM_06f4;
            FUN_CODE_da8a(reg, DAT_EXTMEM_06f5);
        } else if (a == 1) {
            reg = DAT_EXTMEM_06f3;
            reg = (reg << 8) | DAT_EXTMEM_06f4;
            FUN_CODE_da8a(reg, DAT_EXTMEM_06f6);
        }
    }
}
