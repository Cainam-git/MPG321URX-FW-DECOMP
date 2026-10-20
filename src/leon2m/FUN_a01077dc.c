/* leon2m FUN_a01077dc @ 0xa01077dc-0xa010783c (24 words).
 * Template FUN_a010765c: Sets three registers at 0xcf016828.. (and clears bit 7 of 0xcf00ed14) when on is 1, else
 * clears 0xcf016828.
 * This function is the same code as FUN_a010765c (its source comment explains the details), compiled with
 * other constants (template -> this function):
 * 0xa010765c -> 0xa01077dc, 0xcf016828 -> 0xcf016a28, 0xcf016838 -> 0xcf016a38, 0xcf016840 -> 0xcf016a40
 */
#define REG_cf00ed14 (*(volatile unsigned int *)0xcf00ed14)
#define REG_cf016a28 (*(volatile unsigned int *)0xcf016a28)
#define REG_cf016a38 (*(volatile unsigned int *)0xcf016a38)
#define REG_cf016a40 (*(volatile unsigned int *)0xcf016a40)

void FUN_a01077dc(unsigned char on)
{
    if (on == 1) {
        REG_cf00ed14 &= ~0x80;
        REG_cf016a28 = 0x33;
        REG_cf016a38 = 0x90;
        REG_cf016a40 = 0x4e;
    } else {
        REG_cf016a28 = 0;
    }
}
