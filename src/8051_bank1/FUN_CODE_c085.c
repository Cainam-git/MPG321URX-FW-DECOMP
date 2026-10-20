/* 8051_bank1 FUN_CODE_c085 @ 0xc085  MATCH (OPTIMIZE(7,SPEED))
 * The function reads two xdata registers at 0xf021 and 0xf022, masks each with 0xF0, and ORs in a shared value from 0xa1e7, then writes back to the respective registers. The main uncertainty is whether the value at 0xa1e7 is read once or twice — the assembly reads it once into R6 and reuses it for both OR operations, which matches the C above.
 */
extern xdata unsigned char DAT_EXTMEM_f021;
extern xdata unsigned char DAT_EXTMEM_f022;
extern xdata unsigned char DAT_EXTMEM_a1e7;

void FUN_CODE_c085(void) {
    DAT_EXTMEM_f021 = (DAT_EXTMEM_f021 & 0xF0) | DAT_EXTMEM_a1e7;
    DAT_EXTMEM_f022 = (DAT_EXTMEM_f022 & 0xF0) | DAT_EXTMEM_a1e7;
}
