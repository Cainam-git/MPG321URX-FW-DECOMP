/* sys_enable_unit_6a80  (FUN_a010795c)
 *
 * Switch the unit at 0xCF016A80 on or off.
 * Name basis: descriptive - register bits, then 0x33/0x90 when on
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010795c @ 0xa010795c, flags -mcpu=v8 -O3 -g.
 * Source form: the register addresses are set up before the test. Variant of sys_enable_unit_6800_n0.
 */
#define REG(a) (*(volatile unsigned int *)(a))

/*
 * Switch the unit at 0xCF016A80 on (on == 1) or off.
 *
 * On: set bit 6 of register 0xCF016ACC, clear bits 3 and 4 of register 0xCF00ED18, write 0x33 to 0xCF016AA8 and
 * 0x90 to 0xCF016AB8. Off: write 0 to 0xCF016AA8.
 *
 * Called by dbg_switch_dithering and sys_init_enable_output_blocks (which passes five more arguments that the routine does
 * not use).
 */
void sys_enable_unit_6a80(unsigned char on)
{
    if (on == 1) {
        REG(0xcf016acc) |= 0x40;
        REG(0xcf00ed18) &= ~0x18;
        REG(0xcf016aa8) = 0x33;
        REG(0xcf016ab8) = 0x90;
    } else {
        REG(0xcf016aa8) = 0;
    }
}
