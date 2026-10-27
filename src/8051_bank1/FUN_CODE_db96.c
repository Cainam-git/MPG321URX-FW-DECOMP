/* 8051_bank1 FUN_CODE_db96 @ 0xdb96 (25 B)
 * Sets bit 0x16 (BITS_22_6), stores 1 in XDATA 0xA780 when FUN_CODE_da74() returns non-zero, else 0, and calls
 * FUN_CODE_a959 (which reads both).
 * No LCALL or LJMP to 0xDB96 occurs in the bank-1 image. Options: OPTIMIZE(8,SPEED).
 * Source form: the call is written in both arms; Keil then shares the tail 'MOVX @DPTR,A / LCALL / RET' of the
 * two arms (SJMP from the first) and keeps LCALL + RET instead of a tail LJMP.
 */
extern unsigned char xdata DAT_EXTMEM_a780;
extern bit BITS_22_6;
extern unsigned char FUN_CODE_da74(void);
extern void FUN_CODE_a959(void);

void FUN_CODE_db96(void)
{
    if (!FUN_CODE_da74()) {
        BITS_22_6 = 1;
        DAT_EXTMEM_a780 = 0;
        FUN_CODE_a959();
    } else {
        BITS_22_6 = 1;
        DAT_EXTMEM_a780 = 1;
        FUN_CODE_a959();
    }
}
