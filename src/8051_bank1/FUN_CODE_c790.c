/* 8051_bank1 FUN_CODE_c790 @ 0xc790  OPTIMIZE(8,SPEED) LARGE
 * For each bit i (0..6) set in m: clears bit 7 of XDATA 0xF01C, 0xF01E, 0xF085, 0xF087, 0xF099, 0xF0A3, 0xF076.
 */
extern xdata unsigned char DAT_EXTMEM_f01c;
extern xdata unsigned char DAT_EXTMEM_f01e;
extern xdata unsigned char DAT_EXTMEM_f085;
extern xdata unsigned char DAT_EXTMEM_f087;
extern xdata unsigned char DAT_EXTMEM_f099;
extern xdata unsigned char DAT_EXTMEM_f0a3;
extern xdata unsigned char DAT_EXTMEM_f076;

void FUN_CODE_c790(unsigned char param_1)
{
    unsigned char mask = param_1;
    
    if (mask & 0x01) {
        DAT_EXTMEM_f01c &= 0x7f;
    }
    if (mask & 0x02) {
        DAT_EXTMEM_f01e &= 0x7f;
    }
    if (mask & 0x04) {
        DAT_EXTMEM_f085 &= 0x7f;
    }
    if (mask & 0x08) {
        DAT_EXTMEM_f087 &= 0x7f;
    }
    if (mask & 0x10) {
        DAT_EXTMEM_f099 &= 0x7f;
    }
    if (mask & 0x20) {
        DAT_EXTMEM_f0a3 &= 0x7f;
    }
    if (mask & 0x40) {
        DAT_EXTMEM_f076 &= 0x7f;
    }
}
