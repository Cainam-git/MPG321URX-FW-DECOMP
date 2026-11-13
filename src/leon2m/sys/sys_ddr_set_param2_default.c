/* sys_ddr_set_param2_default  (FUN_a00e0cb8)
 *
 * Store the third training parameter unless it was set explicitly.
 * Name basis: descriptive - only when its 'set' flag is 0; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0cb8 @ 0xa00e0cb8-0xa00e0cd8 (8 words, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: two extern words; the third parameter is the word sys_ddr_register_trace_enabled, which the register routines of
 * the memory interface read as their trace switch.
 */
extern unsigned int sys_ddr_param2_set_flag;
extern unsigned int sys_ddr_register_trace_enabled;       /* third training parameter; non-zero turns the register trace on */

/*
 * Set the third training parameter to `value`, but only when sys_ddr_set_param2 has not set it explicitly
 * (its flag is still 0). The parameter is the word that sys_ddr_phy_read, sys_ddr_phy_write and the other
 * register routines test before they print each access. Nothing in the image calls this routine.
 */
void sys_ddr_set_param2_default(unsigned int value)
{
    if (sys_ddr_param2_set_flag == 0)
        sys_ddr_register_trace_enabled = value;
}
