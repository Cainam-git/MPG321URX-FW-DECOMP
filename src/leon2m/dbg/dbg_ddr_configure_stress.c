/* dbg_ddr_configure_stress  (FUN_a00dd814)
 *
 * Switch the memory stress test on or off and store its parameter.
 * Name basis: derived - flag and word at 0xA802B0A8; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dd814 @ 0xa00dd814-0xa00dd83c, 40 bytes, leaf, flags -mcpu=v8 -O3 -g.
 * Its CPU address 0x7d814 is stored in the word at 0xa01f8df4; no call to it was found.
 */
extern unsigned char dbg_ddr_stress_enabled;
extern unsigned int dbg_ddr_stress_param;

/*
 * Set the on/off byte of the memory stress test to 1 when enable is 1 and to 0 otherwise, and store param as
 * the test's parameter word.
 */
void dbg_ddr_configure_stress(int enable, unsigned int param)
{
    if (enable == 1)
        dbg_ddr_stress_enabled = 1;
    else
        dbg_ddr_stress_enabled = 0;
    dbg_ddr_stress_param = param;
}
