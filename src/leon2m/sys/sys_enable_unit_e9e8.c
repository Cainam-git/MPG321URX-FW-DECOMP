/* sys_enable_unit_e9e8  (FUN_a0107554)
 *
 * Switch the unit at 0xCF00E9E8 on or off (first form).
 * Name basis: descriptive - clears bit 4 of 0xCF00EAC8, then 0x33/0x90/0x4E or 0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0107554 @ 0xa0107554, flags -mcpu=v8 -O3 -g.
 * Same form as sys_enable_unit_6800_n0: the register addresses are set up before the test.
 */
#define REG_cf00eac8 (*(volatile unsigned int *)0xcf00eac8)
#define REG_cf00e9e8 (*(volatile unsigned int *)0xcf00e9e8)
#define REG_cf00e9f8 (*(volatile unsigned int *)0xcf00e9f8)
#define REG_cf00ea00 (*(volatile unsigned int *)0xcf00ea00)

/*
 * Switch the unit at 0xCF00E9E8 on (on == 1) or off.
 *
 * Both ways clear bit 4 of register 0xCF00EAC8 first. On: write 0x33, 0x90 and 0x4e to the registers 0xCF00E9E8,
 * 0xCF00E9F8 and 0xCF00EA00. Off: write 0 to 0xCF00E9E8.
 *
 * Called by dbg_switch_dithering and sys_init_enable_output_blocks; the other form is sys_enable_unit_e9e8_with_bit4.
 */
void sys_enable_unit_e9e8(unsigned char on)
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
