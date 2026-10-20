/* leon2m FUN_a010777c @ 0xa010777c-0xa01077dc (24 words).
 * Template FUN_a010765c: Sets three registers at 0xcf016828.. (and clears bit 7 of 0xcf00ed14) when on is 1, else
 * clears 0xcf016828.
 * This function is the same code as FUN_a010765c (its source comment explains the details), compiled with
 * other constants (template -> this function):
 * 0xcf016828 -> 0xcf0169a8, 0xcf016838 -> 0xcf0169b8, 0xcf016840 -> 0xcf0169c0
 */
#define REG_cf00ed14 (*(volatile unsigned int *)0xcf00ed14)
#define REG_cf0169a8 (*(volatile unsigned int *)0xcf0169a8)
#define REG_cf0169b8 (*(volatile unsigned int *)0xcf0169b8)
#define REG_cf0169c0 (*(volatile unsigned int *)0xcf0169c0)

void FUN_a010777c(unsigned char on)
{
    if (on == 1) {
        REG_cf00ed14 &= ~0x80;
        REG_cf0169a8 = 0x33;
        REG_cf0169b8 = 0x90;
        REG_cf0169c0 = 0x4e;
    } else {
        REG_cf0169a8 = 0;
    }
}
