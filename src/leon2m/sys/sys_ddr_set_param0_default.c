/* sys_ddr_set_param0_default  (FUN_a00e0c68)
 *
 * Store the first training parameter unless it was set explicitly.
 * Name basis: descriptive - only when its 'set' flag is 0; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0c68 @ 0xa00e0c68-0xa00e0c88 (8 words).
 * Source form: a leaf routine with two extern words.
 */
extern unsigned int sys_ddr_param0_set_flag;
extern unsigned int sys_ddr_param0;

/*
 * Set the first training parameter to `value`, but only when sys_ddr_set_param0 has not set it explicitly (its
 * flag is still 0). Nothing in the image calls it.
 */
void sys_ddr_set_param0_default(unsigned int value)
{
    if (sys_ddr_param0_set_flag == 0)
        sys_ddr_param0 = value;
}
