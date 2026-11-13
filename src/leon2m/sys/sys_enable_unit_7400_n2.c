/* sys_enable_unit_7400_n2  (FUN_a01078cc)
 *
 * Switch unit 2 of the four units at 0xCF017400 on or off.
 * Name basis: descriptive - enable bit, then 0x33/0x90 when on, else the first register cleared
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01078cc @ 0xa01078cc, flags -mcpu=v8 -O3 -g.
 * Source form: as sys_enable_unit_7400_n0 (the register addresses are set up before the test), with other constants.
 */
#define REG_cf01754c (*(volatile unsigned int *)0xcf01754c)
#define REG_cf017528 (*(volatile unsigned int *)0xcf017528)
#define REG_cf017538 (*(volatile unsigned int *)0xcf017538)

/*
 * Switch unit 2 of the four units at 0xCF017400 on (on == 1) or off.
 *
 * Both ways set bit 0 of register 0xCF01754C first. On: write 0x33 to register 0xCF017528 and 0x90 to
 * 0xCF017538. Off: write 0 to 0xCF017528. Same code as sys_enable_unit_7400_n0 with other registers.
 */
void sys_enable_unit_7400_n2(unsigned char on)
{
    REG_cf01754c |= 1;
    if (on == 1) {
        REG_cf017528 = 0x33;
        REG_cf017538 = 0x90;
    } else {
        REG_cf017528 = 0;
    }
}
