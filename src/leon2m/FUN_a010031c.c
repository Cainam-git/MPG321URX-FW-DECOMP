/* leon2m FUN_a010031c @ 0xa010031c-0xa01003b4 (38 words).
 * Writes the 3-bit value v (ignored when above 7) into one field of two hardware registers, chosen by sel:
 * 0 = bits 0-2 of 0xcf03c158, 1 = bits 3-5 of 0xcf03c158, 2 = bits 0-2 of 0xcf03c144, 3 = bits 3-5 of 0xcf03c144;
 * other sel values do nothing. Written as an if/else chain. Called from FUN_a015209c.
 */
#define REG_cf03c158 (*(volatile unsigned int *)0xcf03c158)
#define REG_cf03c144 (*(volatile unsigned int *)0xcf03c144)

void FUN_a010031c(unsigned char sel, unsigned char v)
{
    if (v > 7)
        return;
    if (sel == 0)
        REG_cf03c158 = (REG_cf03c158 & ~7) | v;
    else if (sel == 1)
        REG_cf03c158 = (REG_cf03c158 & ~0x38) | (v << 3);
    else if (sel == 2)
        REG_cf03c144 = (REG_cf03c144 & ~7) | v;
    else if (sel == 3)
        REG_cf03c144 = (REG_cf03c144 & ~0x38) | (v << 3);
}
