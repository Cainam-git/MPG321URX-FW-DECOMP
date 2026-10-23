/* 8051_bank1 FUN_CODE_d385 @ 0xD385..0xD3B9 (52 bytes).
 * When XDATA 0x3F20 is 1: sets bit 0 of XDATA 0x9324, copies 0x9324 into the 63 bytes XDATA 0x3F22..0x3F60 and
 * writes 1 to 0x3F21; otherwise writes 0 to 0x3F21. No caller in the image. No aids.
 */
extern unsigned char xdata DAT_EXTMEM_3f20, DAT_EXTMEM_3f21, DAT_EXTMEM_9324;
extern unsigned char xdata DAT_EXTMEM_3f22[];
void FUN_CODE_d385(void)
{
    unsigned char i;
    if (DAT_EXTMEM_3f20 == 1) {
        DAT_EXTMEM_9324 |= 1;
        for (i = 0; i < 0x3f; i++) DAT_EXTMEM_3f22[i] = DAT_EXTMEM_9324;
        DAT_EXTMEM_3f21 = 1;
    } else DAT_EXTMEM_3f21 = 0;
}
