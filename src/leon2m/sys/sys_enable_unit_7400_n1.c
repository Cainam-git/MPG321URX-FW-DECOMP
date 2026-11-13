/* sys_enable_unit_7400_n1  (FUN_a0107884)
 *
 * Switch unit 1 of the four units at 0xCF017400 on or off.
 * Name basis: descriptive - enable bit, then 0x33/0x90 when on, else the first register cleared
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0107884 @ 0xa0107884, flags -mcpu=v8 -O3 -g.
 * Source form: as sys_enable_unit_7400_n0 (the register addresses are set up before the test), with other constants.
 */
#define REG_cf0174cc (*(volatile unsigned int *)0xcf0174cc)
#define REG_cf0174a8 (*(volatile unsigned int *)0xcf0174a8)
#define REG_cf0174b8 (*(volatile unsigned int *)0xcf0174b8)

/*
 * Switch unit 1 of the four units at 0xCF017400 on (on == 1) or off.
 *
 * Both ways set bit 0 of register 0xCF0174CC first. On: write 0x33 to register 0xCF0174A8 and 0x90 to
 * 0xCF0174B8. Off: write 0 to 0xCF0174A8. Same code as sys_enable_unit_7400_n0 with other registers.
 */
void sys_enable_unit_7400_n1(unsigned char on)
{
    REG_cf0174cc |= 1;
    if (on == 1) {
        REG_cf0174a8 = 0x33;
        REG_cf0174b8 = 0x90;
    } else {
        REG_cf0174a8 = 0;
    }
}
