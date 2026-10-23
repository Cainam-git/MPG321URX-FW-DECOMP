/* 8051_bank1 FUN_CODE_dc51 @ 0xdc51  OPTIMIZE(8,SPEED)
 * Mechanical: Ghidra's C cleaned by tools/auto8051.py; Ghidra's symbol names are kept.
 */
unsigned char xdata DAT_EXTMEM_d511 _at_ 0xd511;
unsigned char xdata DAT_EXTMEM_f1a8 _at_ 0xf1a8;
unsigned char xdata DAT_EXTMEM_f1df _at_ 0xf1df;

void FUN_CODE_dc51(void)

{
  DAT_EXTMEM_f1df = DAT_EXTMEM_f1df | 0x80;
  if (DAT_EXTMEM_d511 == '\x1a') {
    DAT_EXTMEM_f1a8 = DAT_EXTMEM_f1a8 & 0xfe;
  }
  return;
}