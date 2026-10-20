/* leon2m FUN_a01075f8 @ 0xa01075f8-0xa010765c (25 words).
 * When on is 1: writes 0x33 to hardware register 0xcf00eaa8, sets bit 4 of 0xcf00eac8, and writes 0x33, 0x90 and
 * 0x4e to 0xcf00e9e8, 0xcf00e9f8 and 0xcf00ea00. Otherwise writes 0 to 0xcf00e9e8 and 0xcf00eaa8.
 * Called from FUN_a00dd6c8 and FUN_a015202c (next to FUN_a0107554, which has the same form).
 */
#define REG_cf00eaa8 (*(volatile unsigned int *)0xcf00eaa8)
#define REG_cf00eac8 (*(volatile unsigned int *)0xcf00eac8)
#define REG_cf00e9e8 (*(volatile unsigned int *)0xcf00e9e8)
#define REG_cf00e9f8 (*(volatile unsigned int *)0xcf00e9f8)
#define REG_cf00ea00 (*(volatile unsigned int *)0xcf00ea00)

void FUN_a01075f8(unsigned char on)
{
    if (on == 1) {
        REG_cf00eaa8 = 0x33;
        REG_cf00eac8 |= 0x10;
        REG_cf00e9e8 = 0x33;
        REG_cf00e9f8 = 0x90;
        REG_cf00ea00 = 0x4e;
    } else {
        REG_cf00e9e8 = 0;
        REG_cf00eaa8 = 0;
    }
}
