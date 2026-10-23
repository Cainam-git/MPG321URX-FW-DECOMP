/* 8051_bank1 FUN_CODE_dc0d @ 0xdc0d..0xdc24 (23 bytes), OPTIMIZE(7,SPEED).
 * Bit result (carry): clears bit 0x1A (BITS_23_2), sets it when both bytes XDATA 0xA672 and 0xA673 are below
 * 0x13, and returns it.
 * No caller: nothing in bank 1 calls, jumps to or stores the address 0xDC0D.
 */
extern unsigned char xdata DAT_EXTMEM_a672[2];
extern bit BITS_23_2;

bit FUN_CODE_dc0d(void)
{
    BITS_23_2 = 0;
    if (DAT_EXTMEM_a672[0] < 0x13 && DAT_EXTMEM_a672[1] < 0x13)
        BITS_23_2 = 1;
    return BITS_23_2;
}
