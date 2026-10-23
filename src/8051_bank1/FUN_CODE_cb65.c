/* 8051_bank1 FUN_CODE_cb65 @ 0xCB65..0xCBAC (71 bytes; unlisted code found in a gap of the function table).
 * For each set bit 0..6 of m writes 0x10 to one XDATA register: bit 0 0xF03D, 1 0xF045, 2 0xF08D, 3 0xF095,
 * 4 0xF09F, 5 0xF0BC, 6 0xF144 (JNB ACC.n tests on m). No caller in the image. No aids.
 */
extern unsigned char xdata DAT_EXTMEM_f03d, DAT_EXTMEM_f045, DAT_EXTMEM_f08d, DAT_EXTMEM_f095, DAT_EXTMEM_f09f;
extern unsigned char xdata DAT_EXTMEM_f0bc, DAT_EXTMEM_f144;
void FUN_CODE_cb65(unsigned char m)
{
    if (m & 0x01) DAT_EXTMEM_f03d = 0x10;
    if (m & 0x02) DAT_EXTMEM_f045 = 0x10;
    if (m & 0x04) DAT_EXTMEM_f08d = 0x10;
    if (m & 0x08) DAT_EXTMEM_f095 = 0x10;
    if (m & 0x10) DAT_EXTMEM_f09f = 0x10;
    if (m & 0x20) DAT_EXTMEM_f0bc = 0x10;
    if (m & 0x40) DAT_EXTMEM_f144 = 0x10;
}
