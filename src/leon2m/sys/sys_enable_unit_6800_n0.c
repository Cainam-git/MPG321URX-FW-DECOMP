/* sys_enable_unit_6800_n0  (FUN_a010765c)
 *
 * Switch unit 0 of the five units at 0xCF016800 on or off.
 * Name basis: descriptive - three registers at 0xCF016828.. when on, else the first one cleared
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010765c @ 0xa010765c, flags -mcpu=v8 -O3 -g.
 * Source form: the register addresses are set up before the test (the compiler hoists them out of both arms).
 */
#define REG_cf00ed14 (*(volatile unsigned int *)0xcf00ed14)
#define REG_cf016828 (*(volatile unsigned int *)0xcf016828)
#define REG_cf016838 (*(volatile unsigned int *)0xcf016838)
#define REG_cf016840 (*(volatile unsigned int *)0xcf016840)

/*
 * Switch unit 0 of the five units at 0xCF016800 on (on == 1) or off.
 *
 * On: clear bit 7 of register 0xCF00ED14 (shared by all five units), then write 0x33, 0x90 and 0x4e to the
 * registers 0xCF016828, 0xCF016838 and 0xCF016840. Off: write 0 to 0xCF016828.
 *
 * Called by dbg_switch_dithering and sys_init_enable_output_blocks. Units 1 to 4 have the same code with other registers.
 */
void sys_enable_unit_6800_n0(unsigned char on)
{
    if (on == 1) {
        REG_cf00ed14 &= ~0x80;
        REG_cf016828 = 0x33;
        REG_cf016838 = 0x90;
        REG_cf016840 = 0x4e;
    } else {
        REG_cf016828 = 0;
    }
}
