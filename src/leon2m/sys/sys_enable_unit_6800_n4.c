/* sys_enable_unit_6800_n4  (FUN_a01077dc)
 *
 * Switch unit 4 of the five units at 0xCF016800 on or off.
 * Name basis: descriptive - three registers at 0xCF016A28.. when on, else the first one cleared
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01077dc @ 0xa01077dc, flags -mcpu=v8 -O3 -g.
 * Source form: as sys_enable_unit_6800_n0 (the register addresses are set up before the test), with other constants.
 */
#define REG_cf00ed14 (*(volatile unsigned int *)0xcf00ed14)
#define REG_cf016a28 (*(volatile unsigned int *)0xcf016a28)
#define REG_cf016a38 (*(volatile unsigned int *)0xcf016a38)
#define REG_cf016a40 (*(volatile unsigned int *)0xcf016a40)

/*
 * Switch unit 4 of the five units at 0xCF016800 on (on == 1) or off.
 *
 * On: clear bit 7 of register 0xCF00ED14, then write 0x33, 0x90 and 0x4e to the registers 0xCF016A28, 0xCF016A38
 * and 0xCF016A40. Off: write 0 to 0xCF016A28. Same code as sys_enable_unit_6800_n0 with other registers.
 */
void sys_enable_unit_6800_n4(unsigned char on)
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
