/* 8051_bank1 FUN_CODE_dd63 @ 0xdd63  OPTIMIZE(8,SPEED) LARGE
 * Writes 1 to XDATA 0xA70C if the parameter equals 1, else writes 0. The if/else form produces the target's
 * compare and the two separate store paths.
 */
extern xdata unsigned char DAT_EXTMEM_a70c;

void FUN_CODE_dd63(char param_1)
{
    if (param_1 == 0x01) {
        DAT_EXTMEM_a70c = 0x01;
    } else {
        DAT_EXTMEM_a70c = 0x00;
    }
}
