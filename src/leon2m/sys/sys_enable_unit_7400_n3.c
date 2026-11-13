/* sys_enable_unit_7400_n3  (FUN_a0107914)
 *
 * Switch unit 3 of the four units at 0xCF017400 on or off.
 * Name basis: descriptive - enable bit, then 0x33/0x90 when on, else the first register cleared
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0107914 @ 0xa0107914, flags -mcpu=v8 -O3 -g.
 * Source form: as sys_enable_unit_7400_n0 (the register addresses are set up before the test), with other constants.
 */
#define REG_cf0175cc (*(volatile unsigned int *)0xcf0175cc)
#define REG_cf0175a8 (*(volatile unsigned int *)0xcf0175a8)
#define REG_cf0175b8 (*(volatile unsigned int *)0xcf0175b8)

/*
 * Switch unit 3 of the four units at 0xCF017400 on (on == 1) or off.
 *
 * Both ways set bit 0 of register 0xCF0175CC first. On: write 0x33 to register 0xCF0175A8 and 0x90 to
 * 0xCF0175B8. Off: write 0 to 0xCF0175A8. Same code as sys_enable_unit_7400_n0 with other registers.
 */
void sys_enable_unit_7400_n3(unsigned char on)
{
    REG_cf0175cc |= 1;
    if (on == 1) {
        REG_cf0175a8 = 0x33;
        REG_cf0175b8 = 0x90;
    } else {
        REG_cf0175a8 = 0;
    }
}
