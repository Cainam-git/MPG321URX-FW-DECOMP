/* FUN_CODE_cdcd, 8051_bank1, range 0xCDCD..0xCE0D (64 B).
 * Options: OPTIMIZE(8,SPEED) (also with REGFILE(R.ORC) added).
 * Code facts: the generic pointer DAT_EXTMEM_a76d (3 bytes at 0xA76D, declared as in the other bank-1 files) points
 * to a record; it writes record bytes 0x48..0x4D = 00 08 7F 04 00 00 (each through ?C?CSTOPTR with a DPTR offset,
 * the pointer is loaded once into R3/R2/R1) and then sets bit 2 of XDATA 0xF030. Caller: FUN_CODE_dc92 (0xDCA1).
 * No aids.
 */
extern unsigned char * xdata DAT_EXTMEM_a76d;
extern unsigned char xdata DAT_EXTMEM_f030;
void FUN_CODE_cdcd(void)
{
    DAT_EXTMEM_a76d[0x48] = 0;
    DAT_EXTMEM_a76d[0x49] = 8;
    DAT_EXTMEM_a76d[0x4a] = 0x7f;
    DAT_EXTMEM_a76d[0x4b] = 4;
    DAT_EXTMEM_a76d[0x4c] = 0;
    DAT_EXTMEM_a76d[0x4d] = 0;
    DAT_EXTMEM_f030 |= 4;
}
