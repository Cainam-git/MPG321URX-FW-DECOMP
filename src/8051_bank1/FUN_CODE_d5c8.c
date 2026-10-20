/* 8051_bank1 FUN_CODE_d5c8 @ 0xd5c8  MATCH (OPTIMIZE(7,SPEED))
 * This function writes a constant to one xdata register, clears bit 7 of another, then branches on whether a third register equals 0x20 (space): if equal, it keeps only bit 0 of a fourth register; otherwise keeps the low nibble. It then sets bit 0 of a fifth register and tail-calls `FUN_CODE_daad`. The main uncertainty is whether the final call is truly a tail call (LJMP) rather than a call followed by return; the assembly uses LJMP, so this should match.
 */
extern xdata unsigned char DAT_EXTMEM_d929;
extern xdata unsigned char DAT_EXTMEM_d90b;
extern xdata unsigned char DAT_EXTMEM_d511;
extern xdata unsigned char DAT_EXTMEM_d904;
extern xdata unsigned char DAT_EXTMEM_d90c;

void FUN_CODE_daad(void);  // at 0xdaad

void FUN_CODE_d5c8(void)
{
    DAT_EXTMEM_d929 = 0x71;
    DAT_EXTMEM_d90b = DAT_EXTMEM_d90b & 0x7f;
    if (DAT_EXTMEM_d511 == 0x20) {
        DAT_EXTMEM_d904 = DAT_EXTMEM_d904 & 0x01;
    } else {
        DAT_EXTMEM_d904 = DAT_EXTMEM_d904 & 0x0f;
    }
    DAT_EXTMEM_d90c = DAT_EXTMEM_d90c | 0x01;
    FUN_CODE_daad();
}
