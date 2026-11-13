/* sys_ddr_set_param2  (FUN_a00e0d18)
 *
 * Store the third training parameter and mark it as set explicitly.
 * Name basis: descriptive - value and its 'set' flag; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0d18 @ 0xa00e0d18-0xa00e0d30 (6 words, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: two extern words (each store has its own sethi).
 */
extern unsigned int sys_ddr_register_trace_enabled;       /* third training parameter; non-zero turns the register trace on */
extern unsigned int sys_ddr_param2_set_flag;

/*
 * Set the third training parameter to `value` and remember that it was set explicitly, so that
 * sys_ddr_set_param2_default leaves it alone. The parameter is the word that the register routines of the
 * memory interface test before they print each access. Nothing in the image calls this routine.
 */
void sys_ddr_set_param2(unsigned int value)
{
    sys_ddr_register_trace_enabled = value;
    sys_ddr_param2_set_flag = 1;
}
