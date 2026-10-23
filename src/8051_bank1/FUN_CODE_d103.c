/* 8051_bank1 FUN_CODE_d103 @ 0xD103..0xD13A (55 bytes).
 * Timer 0 interrupt (vector 0x000B jumps here), register bank 2: reloads TL0 / TH0 from XDATA 0xA773 / 0xA772,
 * starts timer 0 (TR0), increments the 16-bit IDATA counter 0x57..0x58 and steps XDATA 0xA1E4 through 0..9.
 * DAT_INTMEM_57 is volatile as in its other users (it is changed by this interrupt). No aids.
 */
sfr TL0 = 0x8A;
sfr TH0 = 0x8C;
sbit TR0 = 0x8C;
extern unsigned char xdata DAT_EXTMEM_a773, DAT_EXTMEM_a772, DAT_EXTMEM_a1e4;
extern unsigned int volatile idata DAT_INTMEM_57;
void FUN_CODE_d103(void) interrupt 1 using 2
{
    TL0 = DAT_EXTMEM_a773;
    TH0 = DAT_EXTMEM_a772;
    TR0 = 1;
    DAT_INTMEM_57++;
    if (++DAT_EXTMEM_a1e4 > 9) DAT_EXTMEM_a1e4 = 0;
}
