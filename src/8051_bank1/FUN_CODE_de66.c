/* 8051_bank1 FUN_CODE_de66 @ 0xde66  MATCH (OPTIMIZE(7,SPEED))
 * Writes the constant 0x37 to xdata 0xD507 and 0xD508. The two plain assignments compile to two MOVX stores,
 * each with its own immediate DPTR load, as in the firmware.
 */
extern xdata unsigned char DAT_EXTMEM_d507;
extern xdata unsigned char DAT_EXTMEM_d508;

void FUN_CODE_de66(void) {
    DAT_EXTMEM_d507 = 0x37;
    DAT_EXTMEM_d508 = 0x37;
}
