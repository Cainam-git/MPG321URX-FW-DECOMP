/* 8051_bank1 FUN_CODE_c2d3 @ 0xc2d3  OPTIMIZE(8,SPEED) LARGE
 * For each bit i (0..7) set in m: sets bit 6 of XDATA 0xF039, 0xF041, 0xF089, 0xF091, 0xF09B, 0xF0B8, 0xF140, 0xF014
 * (bit 0 .. bit 7, separate tests).
 */
extern unsigned char xdata DAT_EXTMEM_f039;
extern unsigned char xdata DAT_EXTMEM_f041;
extern unsigned char xdata DAT_EXTMEM_f089;
extern unsigned char xdata DAT_EXTMEM_f091;
extern unsigned char xdata DAT_EXTMEM_f09b;
extern unsigned char xdata DAT_EXTMEM_f0b8;
extern unsigned char xdata DAT_EXTMEM_f140;
extern unsigned char xdata DAT_EXTMEM_f014;

void FUN_CODE_c2d3(unsigned char param_1)
{
    unsigned char mask;
    
    mask = param_1;
    if (mask & 0x01) {
        DAT_EXTMEM_f039 |= 0x40;
    }
    if (mask & 0x02) {
        DAT_EXTMEM_f041 |= 0x40;
    }
    if (mask & 0x04) {
        DAT_EXTMEM_f089 |= 0x40;
    }
    if (mask & 0x08) {
        DAT_EXTMEM_f091 |= 0x40;
    }
    if (mask & 0x10) {
        DAT_EXTMEM_f09b |= 0x40;
    }
    if (mask & 0x20) {
        DAT_EXTMEM_f0b8 |= 0x40;
    }
    if (mask & 0x40) {
        DAT_EXTMEM_f140 |= 0x40;
    }
    if (mask & 0x80) {
        DAT_EXTMEM_f014 |= 0x40;
    }
}
