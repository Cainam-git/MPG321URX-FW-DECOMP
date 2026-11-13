/* sys_enable_unit_6800_n1  (FUN_a01076bc)
 *
 * Switch unit 1 of the five units at 0xCF016800 on or off.
 * Name basis: descriptive - three registers at 0xCF0168A8.. when on, else the first one cleared
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01076bc @ 0xa01076bc, flags -mcpu=v8 -O3 -g.
 * Source form: as sys_enable_unit_6800_n0 (the register addresses are set up before the test), with other constants.
 */
#define REG_cf00ed14 (*(volatile unsigned int *)0xcf00ed14)
#define REG_cf0168a8 (*(volatile unsigned int *)0xcf0168a8)
#define REG_cf0168b8 (*(volatile unsigned int *)0xcf0168b8)
#define REG_cf0168c0 (*(volatile unsigned int *)0xcf0168c0)

/*
 * Switch unit 1 of the five units at 0xCF016800 on (on == 1) or off.
 *
 * On: clear bit 7 of register 0xCF00ED14, then write 0x33, 0x90 and 0x4e to the registers 0xCF0168A8, 0xCF0168B8
 * and 0xCF0168C0. Off: write 0 to 0xCF0168A8. Same code as sys_enable_unit_6800_n0 with other registers.
 */
void sys_enable_unit_6800_n1(unsigned char on)
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
