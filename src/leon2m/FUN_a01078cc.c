/* leon2m FUN_a01078cc @ 0xa01078cc-0xa0107914 (18 words).
 * Template FUN_a010783c: Sets bit 0 of register 0xcf01744c, then writes 0x33/0x90 to 0xcf017428/0xcf017438 when on
 * is 1, else clears 0xcf017428.
 * This function is the same code as FUN_a010783c (its source comment explains the details), compiled with
 * other constants (template -> this function):
 * 0xcf017428 -> 0xcf017528, 0xcf017438 -> 0xcf017538, 0xcf01744c -> 0xcf01754c
 */
#define REG_cf01754c (*(volatile unsigned int *)0xcf01754c)
#define REG_cf017528 (*(volatile unsigned int *)0xcf017528)
#define REG_cf017538 (*(volatile unsigned int *)0xcf017538)

void FUN_a01078cc(unsigned char on)
{
    REG_cf01754c |= 1;
    if (on == 1) {
        REG_cf017528 = 0x33;
        REG_cf017538 = 0x90;
    } else {
        REG_cf017528 = 0;
    }
}
