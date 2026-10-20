/* leon2m FUN_a0107554 @ 0xa0107554-0xa01075a8 (21 words).
 * Clears bit 4 of hardware register 0xcf00eac8. Then, when on is 1, writes 0x33, 0x90 and 0x4e to the registers
 * 0xcf00e9e8, 0xcf00e9f8 and 0xcf00ea00; otherwise writes 0 to 0xcf00e9e8. Same form as FUN_a010765c.
 * Called from FUN_a00dd6c8 and FUN_a015202c.
 */
#define REG_cf00eac8 (*(volatile unsigned int *)0xcf00eac8)
#define REG_cf00e9e8 (*(volatile unsigned int *)0xcf00e9e8)
#define REG_cf00e9f8 (*(volatile unsigned int *)0xcf00e9f8)
#define REG_cf00ea00 (*(volatile unsigned int *)0xcf00ea00)

void FUN_a0107554(unsigned char on)
{
    REG_cf00eac8 &= ~0x10;
    if (on == 1) {
        REG_cf00e9e8 = 0x33;
        REG_cf00e9f8 = 0x90;
        REG_cf00ea00 = 0x4e;
    } else {
        REG_cf00e9e8 = 0;
    }
}
