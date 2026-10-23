/* leon2m FUN_a01295d0 @ 0xa01295d0-0xa01295e4 (5 words), flags -mcpu=v8 -O3 -g (this leaf was not in
 * Ghidra's function list: entry added to symbols/leon2m.functions.json and asm/leon2m/FUN_a01295d0.s).
 * Code facts: leaf; sets bit 10 (0x400) of the 16-bit OLED frame-rate-control state word DAT_a802d892 (its low byte
 * 0xa802d893 holds the selected panel row). FUN_a008454c calls it right after
 * FUN_a00dac38, and the OLED FRC handler FUN_a01295e4 sees the 0x400 request and sends the row number to the panel's
 * frame-rate-control chip (I2C 0x60, register 0xB2) through FUN_a0126704. Aids: none.
 */
extern unsigned short DAT_a802d892;

void FUN_a01295d0(void)
{
    DAT_a802d892 |= 0x400;
}
