/* 8051_bank1 FUN_CODE_dc67 @ 0xdc67  OPTIMIZE(8,SPEED)
 * Sets bit 0 of XDATA 0xF1A8 when XDATA 0xD511 == 0x1A, then clears bit 7 of XDATA 0xF1DF.
 * Source form: Ghidra's symbol names are kept.
 */
unsigned char xdata DAT_EXTMEM_d511 _at_ 0xd511;
unsigned char xdata DAT_EXTMEM_f1a8 _at_ 0xf1a8;
unsigned char xdata DAT_EXTMEM_f1df _at_ 0xf1df;

void FUN_CODE_dc67(void)

{
  if (DAT_EXTMEM_d511 == '\x1a') {
    DAT_EXTMEM_f1a8 = DAT_EXTMEM_f1a8 | 1;
  }
  DAT_EXTMEM_f1df = DAT_EXTMEM_f1df & 0x7f;
  return;
}