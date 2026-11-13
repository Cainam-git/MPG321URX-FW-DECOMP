/* sys_enable_unit_e9e8_with_bit4  (FUN_a01075f8)
 *
 * Switch the unit at 0xCF00E9E8 on with bit 4 of 0xCF00EAC8, or off.
 * Name basis: descriptive - writes 0x33 to 0xCF00EAA8, sets bit 4 of 0xCF00EAC8, then writes 0x33/0x90/0x4E to
 *   the unit; off writes 0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01075f8 @ 0xa01075f8, flags -mcpu=v8 -O3 -g.
 */
#define REG_cf00eaa8 (*(volatile unsigned int *)0xcf00eaa8)
#define REG_cf00eac8 (*(volatile unsigned int *)0xcf00eac8)
#define REG_cf00e9e8 (*(volatile unsigned int *)0xcf00e9e8)
#define REG_cf00e9f8 (*(volatile unsigned int *)0xcf00e9f8)
#define REG_cf00ea00 (*(volatile unsigned int *)0xcf00ea00)

/*
 * Switch the unit at 0xCF00E9E8 on (on == 1) or off, second form: it sets bit 4 of register 0xCF00EAC8 where
 * sys_enable_unit_e9e8 clears it, and also writes register 0xCF00EAA8.
 *
 * On: write 0x33 to 0xCF00EAA8, set bit 4 of 0xCF00EAC8, write 0x33, 0x90 and 0x4e to 0xCF00E9E8, 0xCF00E9F8 and
 * 0xCF00EA00. Off: write 0 to 0xCF00E9E8 and 0xCF00EAA8.
 *
 * Called by dbg_switch_dithering and sys_init_enable_output_blocks.
 */
void sys_enable_unit_e9e8_with_bit4(unsigned char on)
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
