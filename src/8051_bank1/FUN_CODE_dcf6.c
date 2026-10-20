/* 8051_bank1 FUN_CODE_dcf6 @ 0xdcf6  MATCH (OPTIMIZE(7,SPEED))
 * The issue is the argument order in the call. Keil C51 passes the first byte parameter in R7 and the second in R5. The target has `MOV R5,#0` then `MOV R7,#1`, meaning the first argument is 1 and the second is 0. Ghidra's decompilation showed `FUN_CODE_c389(0,1)` but the actual assembly shows R7=1, R5=0, so the arguments are reversed.
 */
extern xdata unsigned char DAT_EXTMEM_f053;
extern xdata unsigned char DAT_EXTMEM_f055;
void FUN_CODE_c389(unsigned char, unsigned char);

void FUN_CODE_dcf6(void)
{
    DAT_EXTMEM_f053 = 0x83;
    DAT_EXTMEM_f055 = 0x06;
    FUN_CODE_c389(1, 0);
}
