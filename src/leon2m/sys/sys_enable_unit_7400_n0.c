/* sys_enable_unit_7400_n0  (FUN_a010783c)
 *
 * Switch unit 0 of the four units at 0xCF017400 on or off.
 * Name basis: descriptive - enable bit, then 0x33/0x90 when on, else the first register cleared
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010783c @ 0xa010783c, flags -mcpu=v8 -O3 -g.
 * Source form: the register addresses are set up before the test.
 */
#define REG_cf01744c (*(volatile unsigned int *)0xcf01744c)
#define REG_cf017428 (*(volatile unsigned int *)0xcf017428)
#define REG_cf017438 (*(volatile unsigned int *)0xcf017438)

/*
 * Switch unit 0 of the four units at 0xCF017400 on (on == 1) or off.
 *
 * Both ways set bit 0 of register 0xCF01744C first. On: write 0x33 to register 0xCF017428 and 0x90 to 0xCF017438.
 * Off: write 0 to 0xCF017428.
 *
 * Called by dbg_switch_dithering and sys_init_enable_output_blocks. Units 1 to 3 have the same code with other registers.
 */
void sys_enable_unit_7400_n0(unsigned char on)
{
    REG_cf01744c |= 1;
    if (on == 1) {
        REG_cf017428 = 0x33;
        REG_cf017438 = 0x90;
    } else {
        REG_cf017428 = 0;
    }
}
