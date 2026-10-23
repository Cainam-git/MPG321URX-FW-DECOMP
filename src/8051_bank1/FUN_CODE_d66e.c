/* 8051_bank1 FUN_CODE_d66e @ 0xd66e  OPTIMIZE(7,SPEED)
 * Mechanical: Ghidra's C cleaned by tools/auto8051.py; Ghidra's symbol names are kept.
 */
unsigned char xdata DAT_EXTMEM_a6a5 _at_ 0xa6a5;
unsigned char xdata DAT_EXTMEM_a76d _at_ 0xa76d;
unsigned char xdata DAT_EXTMEM_a76e _at_ 0xa76e;
unsigned char xdata DAT_EXTMEM_a76f _at_ 0xa76f;

void FUN_CODE_d66e(void)

{
  if ((DAT_EXTMEM_a6a5 & 3) == 0) {
    DAT_EXTMEM_a76d = 1;
    DAT_EXTMEM_a76e = 0xb2;
    DAT_EXTMEM_a76f = 0x50;
    return;
  }
  if ((DAT_EXTMEM_a6a5 & 3) == 1) {
    DAT_EXTMEM_a76d = 1;
    DAT_EXTMEM_a76e = 0x1a;
    DAT_EXTMEM_a76f = 0x50;
  }
  return;
}