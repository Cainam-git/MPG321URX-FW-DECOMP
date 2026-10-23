/* 8051_bank1 FUN_CODE_de87 @ 0xde87..0xde92 (11 bytes), OPTIMIZE(8,SPEED).
 * Sets bit 0x16 (BITS_22_6) and XDATA 0xA780 = 2, then tail jump to FUN_CODE_a959 (the same three steps as
 * the end of FUN_CODE_9522).
 * No caller: nothing in bank 1 calls, jumps to or stores the address 0xDE87.
 */
extern unsigned char xdata DAT_EXTMEM_a780;
extern bit BITS_22_6;
extern void FUN_CODE_a959(void);

void FUN_CODE_de87(void)
{
    BITS_22_6 = 1;
    DAT_EXTMEM_a780 = 2;
    FUN_CODE_a959();
}
