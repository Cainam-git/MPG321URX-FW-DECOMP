/* 8051_bank1 FUN_CODE_dc67 @ 0xdc67  MATCH (OPTIMIZE(8,SPEED), autoc)
 * Mechanical: Ghidra's C cleaned by tools/auto8051.py; Ghidra's symbol names are kept.
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