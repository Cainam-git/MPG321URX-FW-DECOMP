/* 8051_bank1 FUN_CODE_d785 @ 0xd785..0xd7ac (39 bytes), OPTIMIZE(7,SPEED).
 * Bit result (carry): clears bit 0x1E (BITS_23_6), sets it when one of the bytes XDATA 0xA672 / 0xA673 is
 * above 0xD4 while the other is below 0x41 (tested in both orders), and returns it.
 * No caller: nothing in bank 1 calls, jumps to or stores the address 0xD785.
 */
extern unsigned char xdata DAT_EXTMEM_a672[2];
extern bit BITS_23_6;

bit FUN_CODE_d785(void)
{
    BITS_23_6 = 0;
    if (DAT_EXTMEM_a672[0] > 0xd4 && DAT_EXTMEM_a672[1] < 0x41)
        BITS_23_6 = 1;
    if (DAT_EXTMEM_a672[1] > 0xd4 && DAT_EXTMEM_a672[0] < 0x41)
        BITS_23_6 = 1;
    return BITS_23_6;
}
