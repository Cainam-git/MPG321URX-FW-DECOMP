/* 8051_bank1 FUN_CODE_c644 @ 0xC644..0xC698 (84 bytes; unlisted code found in a gap of the function table).
 * XDATA 0xA77F = 10; FUN_CODE_df14(), FUN_CODE_df16(), FUN_CODE_df17(); 0xA671 = FUN_CODE_aeb2(0xA69C >> 4); then by
 * bits 1..0 of 0xA6A5: 0 -> 0xA672 = aeb2(9), 0xA673 = aeb2(10); 1 -> 0xA672 = aeb2(11), 0xA673 = aeb2(12)
 * (Keil cross-jumps the shared '0xA673 = aeb2(R7)' tail). Exact with OPTIMIZE(8,SPEED) (no register file).
 * No caller in the image. No aids.
 */
extern unsigned char xdata DAT_EXTMEM_a77f, DAT_EXTMEM_a69c, DAT_EXTMEM_a6a5, DAT_EXTMEM_a671;
extern unsigned char xdata DAT_EXTMEM_a672[2];
extern void FUN_CODE_df14(void);
extern void FUN_CODE_df16(void);
extern void FUN_CODE_df17(void);
extern unsigned char FUN_CODE_aeb2(unsigned char v);
void FUN_CODE_c644(void)
{
    DAT_EXTMEM_a77f = 10;
    FUN_CODE_df14();
    FUN_CODE_df16();
    FUN_CODE_df17();
    DAT_EXTMEM_a671 = FUN_CODE_aeb2(DAT_EXTMEM_a69c >> 4);
    if ((DAT_EXTMEM_a6a5 & 3) == 0) {
        DAT_EXTMEM_a672[0] = FUN_CODE_aeb2(9);
        DAT_EXTMEM_a672[1] = FUN_CODE_aeb2(10);
    } else if ((DAT_EXTMEM_a6a5 & 3) == 1) {
        DAT_EXTMEM_a672[0] = FUN_CODE_aeb2(11);
        DAT_EXTMEM_a672[1] = FUN_CODE_aeb2(12);
    }
}
