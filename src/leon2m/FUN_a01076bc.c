/* leon2m FUN_a01076bc @ 0xa01076bc-0xa010771c (24 words).
 * Template FUN_a010765c: Sets three registers at 0xcf016828.. (and clears bit 7 of 0xcf00ed14) when on is 1, else
 * clears 0xcf016828.
 * This function is the same code as FUN_a010765c (its source comment explains the details), compiled with
 * other constants (template -> this function):
 * 0xa010765c -> 0xa01076bc, 0xcf016828 -> 0xcf0168a8, 0xcf016838 -> 0xcf0168b8, 0xcf016840 -> 0xcf0168c0
 */
#define REG_cf00ed14 (*(volatile unsigned int *)0xcf00ed14)
#define REG_cf0168a8 (*(volatile unsigned int *)0xcf0168a8)
#define REG_cf0168b8 (*(volatile unsigned int *)0xcf0168b8)
#define REG_cf0168c0 (*(volatile unsigned int *)0xcf0168c0)

void FUN_a01076bc(unsigned char on)
{
    if (on == 1) {
        REG_cf00ed14 &= ~0x80;
        REG_cf0168a8 = 0x33;
        REG_cf0168b8 = 0x90;
        REG_cf0168c0 = 0x4e;
    } else {
        REG_cf0168a8 = 0;
    }
}
