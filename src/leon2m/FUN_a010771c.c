/* leon2m FUN_a010771c @ 0xa010771c-0xa010777c (24 words).
 * Template FUN_a010765c: Sets three registers at 0xcf016828.. (and clears bit 7 of 0xcf00ed14) when on is 1, else
 * clears 0xcf016828.
 * This function is the same code as FUN_a010765c (its source comment explains the details), compiled with
 * other constants (template -> this function):
 * 0xcf016828 -> 0xcf016928, 0xcf016838 -> 0xcf016938, 0xcf016840 -> 0xcf016940
 */
#define REG_cf00ed14 (*(volatile unsigned int *)0xcf00ed14)
#define REG_cf016928 (*(volatile unsigned int *)0xcf016928)
#define REG_cf016938 (*(volatile unsigned int *)0xcf016938)
#define REG_cf016940 (*(volatile unsigned int *)0xcf016940)

void FUN_a010771c(unsigned char on)
{
    if (on == 1) {
        REG_cf00ed14 &= ~0x80;
        REG_cf016928 = 0x33;
        REG_cf016938 = 0x90;
        REG_cf016940 = 0x4e;
    } else {
        REG_cf016928 = 0;
    }
}
