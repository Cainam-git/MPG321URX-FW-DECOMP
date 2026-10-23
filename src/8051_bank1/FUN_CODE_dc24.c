/* 8051_bank1 FUN_CODE_dc24 @ 0xdc24..0xdc3b (23 bytes), OPTIMIZE(7,SPEED).
 * Bit result (carry): clears bit 0x1C (BITS_23_4), sets it when both bytes XDATA 0xA672 and 0xA673 are above
 * 0xD4, and returns it.
 * No caller: nothing in bank 1 calls, jumps to or stores the address 0xDC24.
 */
extern unsigned char xdata DAT_EXTMEM_a672[2];
extern bit BITS_23_4;

bit FUN_CODE_dc24(void)
{
    BITS_23_4 = 0;
    if (DAT_EXTMEM_a672[0] > 0xd4 && DAT_EXTMEM_a672[1] > 0xd4)
        BITS_23_4 = 1;
    return BITS_23_4;
}
