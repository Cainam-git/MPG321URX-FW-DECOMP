/* 8051_bank1 FUN_CODE_d75e @ 0xd75e  OPTIMIZE(8,SPEED)
 * Clears bit 0 of XDATA 0xDCDE, 0xDCDF, 0xDCCE and 0xDCCF, sets bits 0-1 of XDATA 0xF161 and clears bits 3-4 of
 * XDATA 0xCC87.
 * Source form: Ghidra's symbol names are kept.
 */
unsigned char xdata DAT_EXTMEM_cc87 _at_ 0xcc87;
unsigned char xdata DAT_EXTMEM_dcce _at_ 0xdcce;
unsigned char xdata DAT_EXTMEM_dccf _at_ 0xdccf;
unsigned char xdata DAT_EXTMEM_dcde _at_ 0xdcde;
unsigned char xdata DAT_EXTMEM_dcdf _at_ 0xdcdf;
unsigned char xdata DAT_EXTMEM_f161 _at_ 0xf161;

void FUN_CODE_d75e(void)

{
  DAT_EXTMEM_dcde = DAT_EXTMEM_dcde & 0xfe;
  DAT_EXTMEM_dcdf = DAT_EXTMEM_dcdf & 0xfe;
  DAT_EXTMEM_dcce = DAT_EXTMEM_dcce & 0xfe;
  DAT_EXTMEM_dccf = DAT_EXTMEM_dccf & 0xfe;
  DAT_EXTMEM_f161 = DAT_EXTMEM_f161 | 3;
  DAT_EXTMEM_cc87 = DAT_EXTMEM_cc87 & 0xe7;
  return;
}