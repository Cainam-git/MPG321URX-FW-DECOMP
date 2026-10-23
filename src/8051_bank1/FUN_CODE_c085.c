/* 8051_bank1 FUN_CODE_c085 @ 0xc085  OPTIMIZE(7,SPEED)
 * XDATA 0xF021 = (0xF021 & 0xF0) | byte 0xA1E7; 0xF022 = (0xF022 & 0xF0) | byte 0xA1E7 (0xA1E7 read once).
 */
extern xdata unsigned char DAT_EXTMEM_f021;
extern xdata unsigned char DAT_EXTMEM_f022;
extern xdata unsigned char DAT_EXTMEM_a1e7;

void FUN_CODE_c085(void) {
    DAT_EXTMEM_f021 = (DAT_EXTMEM_f021 & 0xF0) | DAT_EXTMEM_a1e7;
    DAT_EXTMEM_f022 = (DAT_EXTMEM_f022 & 0xF0) | DAT_EXTMEM_a1e7;
}
