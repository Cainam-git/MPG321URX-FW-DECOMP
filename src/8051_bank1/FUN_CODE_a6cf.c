/* 8051_bank1 FUN_CODE_a6cf @ 0xa6cf (166 B, byte-exact with OPTIMIZE(8,SPEED) LARGE).
 * bit FUN_CODE_a6cf(ch): LARGE parameter ch at XDATA 0xA476, local k at 0xA477. Clears bit 0x01 (BITS_20_1); ch values
 * above 1 become 0. k = FUN_CODE_aeb2(XDATA[0xA755]) for ch 0, FUN_CODE_aeb2(XDATA[0xA756]) for ch 1. While the count
 * XDATA[0xA753 + ch] is below 2: XDATA[0xA751 + ch] = k and the count is incremented. Otherwise k replaces
 * XDATA[0xA751 + ch] when it is smaller; when it is larger by more than 0x50 (8-bit difference) BITS_20_1 is set.
 * Returns BITS_20_1 in the carry. Callers: LCALL at 0x53C6, 0x53D8, 0x53EA, 0x53FC, 0x5440, 0x545D, 0x547A, 0x5497.
 * No aids.
 */
extern unsigned char xdata DAT_EXTMEM_a751[2], DAT_EXTMEM_a753[2];
extern unsigned char xdata DAT_EXTMEM_a755, DAT_EXTMEM_a756;
extern bit BITS_20_1;
extern unsigned char FUN_CODE_aeb2(unsigned char v);

bit FUN_CODE_a6cf(unsigned char ch)
{
    unsigned char k;
    BITS_20_1 = 0;
    if (ch > 1) ch = 0;
    if (ch == 0) k = FUN_CODE_aeb2(DAT_EXTMEM_a755); else k = FUN_CODE_aeb2(DAT_EXTMEM_a756);
    if (DAT_EXTMEM_a753[ch] < 2) {
        DAT_EXTMEM_a751[ch] = k;
        DAT_EXTMEM_a753[ch]++;
    } else if (k < DAT_EXTMEM_a751[ch]) {
        DAT_EXTMEM_a751[ch] = k;
    } else if (k > DAT_EXTMEM_a751[ch] && (unsigned char)(k - DAT_EXTMEM_a751[ch]) > 0x50) {
        BITS_20_1 = 1;
    }
    return BITS_20_1;
}
