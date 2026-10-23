/* 8051_bank1 FUN_CODE_c9b0 @ 0xc9b0  OPTIMIZE(8,SPEED) LARGE */
extern xdata unsigned char DAT_EXTMEM_f0f6;
extern xdata unsigned char DAT_EXTMEM_f0fa;
extern xdata unsigned char DAT_EXTMEM_f02c;
extern xdata unsigned char DAT_EXTMEM_f032;
extern xdata unsigned char DAT_EXTMEM_f036;
extern xdata unsigned char DAT_EXTMEM_f06e;
extern xdata unsigned char DAT_EXTMEM_f072;
extern xdata unsigned char DAT_EXTMEM_f030;

void FUN_CODE_c9b0(unsigned char param_1)
{
    unsigned char tmp = param_1;
    
    if (tmp & 0x04) {
        DAT_EXTMEM_f0f6 &= 0x7f;
        DAT_EXTMEM_f0fa = 0xf0;
        DAT_EXTMEM_f02c &= 0xbf;
    }
    if (tmp & 0x08) {
        DAT_EXTMEM_f032 &= 0x7f;
        DAT_EXTMEM_f036 = 0xf0;
        DAT_EXTMEM_f02c &= 0x7f;
    }
    if (tmp & 0x10) {
        DAT_EXTMEM_f06e &= 0x7f;
        DAT_EXTMEM_f072 = 0xf0;
        DAT_EXTMEM_f030 &= 0xbf;
    }
}
