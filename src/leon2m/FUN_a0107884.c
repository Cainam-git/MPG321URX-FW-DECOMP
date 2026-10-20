/* leon2m FUN_a0107884 @ 0xa0107884-0xa01078cc (18 words).
 * Template FUN_a010783c: Sets bit 0 of register 0xcf01744c, then writes 0x33/0x90 to 0xcf017428/0xcf017438 when on
 * is 1, else clears 0xcf017428.
 * This function is the same code as FUN_a010783c (its source comment explains the details), compiled with
 * other constants (template -> this function):
 * 0xcf017428 -> 0xcf0174a8, 0xcf017438 -> 0xcf0174b8, 0xcf01744c -> 0xcf0174cc
 */
#define REG_cf0174cc (*(volatile unsigned int *)0xcf0174cc)
#define REG_cf0174a8 (*(volatile unsigned int *)0xcf0174a8)
#define REG_cf0174b8 (*(volatile unsigned int *)0xcf0174b8)

void FUN_a0107884(unsigned char on)
{
    REG_cf0174cc |= 1;
    if (on == 1) {
        REG_cf0174a8 = 0x33;
        REG_cf0174b8 = 0x90;
    } else {
        REG_cf0174a8 = 0;
    }
}
