/* sys_ddr_set_param0  (FUN_a00e0cd8)
 *
 * Store the first training parameter and mark it as set explicitly.
 * Name basis: descriptive - value and its 'set' flag; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0cd8 @ 0xa00e0cd8-0xa00e0cf0 (6 words, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: two extern words (each store has its own sethi).
 */
extern unsigned int sys_ddr_param0;
extern unsigned int sys_ddr_param0_set_flag;

/*
 * Set the first training parameter to `value` and remember that it was set explicitly, so that
 * sys_ddr_set_param0_default leaves it alone. Nothing in the image calls it.
 */
void sys_ddr_set_param0(unsigned int value)
{
    sys_ddr_param0 = value;
    sys_ddr_param0_set_flag = 1;
}
