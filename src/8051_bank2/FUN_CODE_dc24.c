/* 8051_bank2 FUN_CODE_dc24 @ 0xdc24
 * Copies the unsigned long at XDATA 0x0109 byte by byte, LSB first, to XDATA 0xF19C..0xF19F (>> 8 / 16 / 24 with
 * ?C?ULSHR at 0x343e; the LSB is read directly at 0x010C). Only caller 0x7223. Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 */
extern unsigned long xdata DAT_EXTMEM_0109;
extern unsigned char xdata DAT_EXTMEM_f19c, DAT_EXTMEM_f19d, DAT_EXTMEM_f19e, DAT_EXTMEM_f19f;
void FUN_CODE_dc24(void)
{
    DAT_EXTMEM_f19c = DAT_EXTMEM_0109;
    DAT_EXTMEM_f19d = DAT_EXTMEM_0109 >> 8;
    DAT_EXTMEM_f19e = DAT_EXTMEM_0109 >> 16;
    DAT_EXTMEM_f19f = DAT_EXTMEM_0109 >> 24;
}
