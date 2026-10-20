/* 8051_bank1 FUN_CODE_c790 @ 0xc790  MATCH (OPTIMIZE(8,SPEED) LARGE, judged with the LARGE memory model) */
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
