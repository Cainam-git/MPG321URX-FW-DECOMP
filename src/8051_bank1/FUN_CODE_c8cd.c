/* 8051_bank1 FUN_CODE_c8cd @ 0xC8CD..0xC919 (76 bytes; unlisted code found in a gap of the function table).
 * n above 1 is treated as 0. n == 0: XDATA 0xA77E = FUN_CODE_aeb2(XDATA 0xA755); n == 1: 0xA77E = aeb2(0xA756). Returns
 * 1 (carry, local bit) when 0xA77E is above 0xA0 and the byte passed to aeb2 is 0x0C or less, else 0.
 * No caller in the image (0xC919..0xC965 after it holds strings). No aids.
 */
extern unsigned char xdata DAT_EXTMEM_a755, DAT_EXTMEM_a756, DAT_EXTMEM_a77e;
extern unsigned char FUN_CODE_aeb2(unsigned char v);
bit FUN_CODE_c8cd(unsigned char n)
{
    bit b;
    b = 0;
    if (n > 1) n = 0;
    if (n == 0) {
        DAT_EXTMEM_a77e = FUN_CODE_aeb2(DAT_EXTMEM_a755);
        if (DAT_EXTMEM_a77e > 0xa0 && DAT_EXTMEM_a755 <= 0x0c) b = 1;
    } else {
        DAT_EXTMEM_a77e = FUN_CODE_aeb2(DAT_EXTMEM_a756);
        if (DAT_EXTMEM_a77e > 0xa0 && DAT_EXTMEM_a756 <= 0x0c) b = 1;
    }
    return b;
}
