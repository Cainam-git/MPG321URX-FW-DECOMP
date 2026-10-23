/* 8051_bank1 FUN_CODE_a4e9 @ 0xa4e9..0xa57e (149 bytes)  MailBox_Read: read n words of the Main <-> helper portal
 *
 * Options: OPTIMIZE(8,SPEED) LARGE
 * (level 7 gives 157 bytes). Twin of the byte-exact MailBox_Write src/8051_bank1/FUN_CODE_b228.c.
 * FUN_CODE_a4e9(off, dst, n): for i = 0..n-1 reads the 32-bit AHB word at 0x9F0A0100 + off + 4*i (only the low address
 *   byte changes, 8-bit add) through the AHB bridge FUN_CODE_bcad (address in XDATA 0xA4E7, returns the word) into
 *   dst[i]. n is passed in memory (XDATA 0xA4BD) because the generic pointer takes R1..R3.
 * The firmware has a Keil common-entry block 0xA4D2..0xA4E9 in front of this function (argument set-up shared by the
 *   calls in FUN_CODE_8512 / FUN_CODE_960f / FUN_CODE_9243). It is judged with that module (the
 *   FUN_CODE_9243 module); this standalone file judges only 0xA4E9..0xA57E.
 * Callers (code): FUN_CODE_9243 (command word +0x00, Big->8051 message slots), 960f / 8512 (slot headers), c103 (+0x0C),
 *   c163, c544 (boot / wake byte word +0xB8), cb1d.
 * This is how the 8051 reads what the Big chip posts (commands, messages).
 */
typedef union { unsigned long l; unsigned char b[4]; } DW;
extern DW xdata DAT_EXTMEM_a4e7;
extern DW FUN_CODE_bcad(void);
void FUN_CODE_a4e9(unsigned char off, unsigned long *dst, unsigned char n)
{
    unsigned char i;
    DW addr;
    DW val;
    addr.l = 0x9F0A0100;
    for (i = 0; i < n; i++) {
        addr.b[3] = off + i * 4;
        DAT_EXTMEM_a4e7 = addr;
        val = FUN_CODE_bcad();
        dst[i] = val.l;
    }
}
