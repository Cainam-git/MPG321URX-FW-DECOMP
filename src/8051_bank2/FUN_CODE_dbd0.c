/* 8051_bank2 FUN_CODE_dbd0 @ 0xdbd0 (84 B).
 * Callers (byte scan, xref.py): FUN_CODE_6e16 (LCALL 0x7217), LJMP at 0xa53b (outside any functions.json entry).
 * Code: the unsigned long at XDATA 0x0717 is written byte by byte, low byte first, to XDATA 0xF19B..0xF19E
 * (shifts by 8 / 16 / 24 via ?C?ULSHR FUN_CODE_343e; the low byte is read straight from 0x071A). Write-only, so no
 * volatile. No aids.
 */
extern unsigned long xdata DAT_EXTMEM_0717;
extern unsigned char xdata DAT_EXTMEM_f19b, DAT_EXTMEM_f19c, DAT_EXTMEM_f19d, DAT_EXTMEM_f19e;
void FUN_CODE_dbd0(void)
{
    DAT_EXTMEM_f19b = DAT_EXTMEM_0717;
    DAT_EXTMEM_f19c = DAT_EXTMEM_0717 >> 8;
    DAT_EXTMEM_f19d = DAT_EXTMEM_0717 >> 16;
    DAT_EXTMEM_f19e = DAT_EXTMEM_0717 >> 24;
}
