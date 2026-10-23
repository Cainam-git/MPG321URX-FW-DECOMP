/* 8051_bank1 FUN_CODE_c7e0 @ 0xc7e0  OPTIMIZE(8,SPEED) LARGE
 * For each bit i (0..6) set in m: clears bit 7 of XDATA 0xF181 + 2i (0xF181 .. 0xF18D). FUN_CODE_bbca sets the same bits.
 */
extern xdata unsigned char DAT_EXTMEM_f181 _at_ 0xF181;
extern xdata unsigned char DAT_EXTMEM_f183 _at_ 0xF183;
extern xdata unsigned char DAT_EXTMEM_f185 _at_ 0xF185;
extern xdata unsigned char DAT_EXTMEM_f187 _at_ 0xF187;
extern xdata unsigned char DAT_EXTMEM_f189 _at_ 0xF189;
extern xdata unsigned char DAT_EXTMEM_f18b _at_ 0xF18B;
extern xdata unsigned char DAT_EXTMEM_f18d _at_ 0xF18D;

void FUN_CODE_c7e0(unsigned char param_1) 
{
    if (param_1 & 0x01) {
        DAT_EXTMEM_f181 &= 0x7F;
    }
    if (param_1 & 0x02) {
        DAT_EXTMEM_f183 &= 0x7F;
    }
    if (param_1 & 0x04) {
        DAT_EXTMEM_f185 &= 0x7F;
    }
    if (param_1 & 0x08) {
        DAT_EXTMEM_f187 &= 0x7F;
    }
    if (param_1 & 0x10) {
        DAT_EXTMEM_f189 &= 0x7F;
    }
    if (param_1 & 0x20) {
        DAT_EXTMEM_f18b &= 0x7F;
    }
    if (param_1 & 0x40) {
        DAT_EXTMEM_f18d &= 0x7F;
    }
}
