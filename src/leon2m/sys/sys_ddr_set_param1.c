/* sys_ddr_set_param1  (FUN_a00e0cf0)
 *
 * Store the second training parameter and mark it as set explicitly.
 * Name basis: descriptive - value and its 'set' flag; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0cf0 @ 0xa00e0cf0-0xa00e0d08 (6 words, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: two extern words (each store has its own sethi).
 */
extern unsigned int sys_ddr_param1;
extern unsigned int sys_ddr_param1_set_flag;

/*
 * Set the second training parameter to `value` and remember that it was set explicitly, so that
 * sys_ddr_set_param1_default leaves it alone. Nothing in the image calls it.
 */
void sys_ddr_set_param1(unsigned int value)
{
    sys_ddr_param1 = value;
    sys_ddr_param1_set_flag = 1;
}
