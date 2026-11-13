/* sys_enable_unit_6800_n2  (FUN_a010771c)
 *
 * Switch unit 2 of the five units at 0xCF016800 on or off.
 * Name basis: descriptive - three registers 0xCF016928, 0xCF016938, 0xCF016940 when on, else the first one
 *   cleared
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010771c @ 0xa010771c, flags -mcpu=v8 -O3 -g.
 * Source form: as sys_enable_unit_6800_n0 (the register addresses are set up before the test), with other constants.
 */
#define REG_cf00ed14 (*(volatile unsigned int *)0xcf00ed14)
#define REG_cf016928 (*(volatile unsigned int *)0xcf016928)
#define REG_cf016938 (*(volatile unsigned int *)0xcf016938)
#define REG_cf016940 (*(volatile unsigned int *)0xcf016940)

/*
 * Switch unit 2 of the five units at 0xCF016800 on (on == 1) or off.
 *
 * On: clear bit 7 of register 0xCF00ED14, then write 0x33, 0x90 and 0x4e to the registers 0xCF016928, 0xCF016938
 * and 0xCF016940. Off: write 0 to 0xCF016928. Same code as sys_enable_unit_6800_n0 with other registers.
 */
void sys_enable_unit_6800_n2(unsigned char on)
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
