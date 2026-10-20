/* 8051_bank1 FUN_CODE_c965 @ 0xc965 (75 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * Sets the second long of the array at XDATA 0xA70D (0xA711) to element 0 (0xA70D) + the long at 0xA717 + w;
 * FUN_CODE_cd8c computes the reverse difference 0xA711 - 0xA70D - 0xA717. Only caller: the command switch
 * FUN_CODE_224f, command 20, with w = (byte 2 << 8) + byte 3.
 * LARGE: w is stored in its XDATA parameter slot 0xA4B3 at entry and read back for the last addition; the sum is
 * written with a tail jump to ?C?LSTXDATA.
 */
extern unsigned long xdata DAT_EXTMEM_a70d[];
extern unsigned long xdata DAT_EXTMEM_a717;

void FUN_CODE_c965(unsigned int w)
{
    DAT_EXTMEM_a70d[1] = DAT_EXTMEM_a70d[0] + DAT_EXTMEM_a717 + w;
}
