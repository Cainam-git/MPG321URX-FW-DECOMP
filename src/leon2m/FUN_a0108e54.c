/* leon2m FUN_a0108e54 @ 0xa0108e54 (-mcpu=v8 -O2 -g)
 * Returns 1 when bit 7 of the register 0xCF011AA0 is set, else 0 (the FRC register block 0xCF0118xx..0xCF011Exx).
 * Callers: the row picker FUN_a00dac38 prints it as the first value of "hfrq(%d) = %d", "active_in(%d) = %d" and
 * "vfreq(%d) = %d"; the OLED FRC handler FUN_a01295e4 and FUN_a0129810 / FUN_a014d504 test it.
 */

#define _DAT_cf011aa0 (*(volatile unsigned int *)0xcf011aa0)

unsigned int FUN_a0108e54(void)
{
    unsigned int val = _DAT_cf011aa0 & 0x80;
    return val != 0;
}
