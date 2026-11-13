/* sys_ddr_set_param1_default  (FUN_a00e0c88)
 *
 * Store the second training parameter unless it was set explicitly.
 * Name basis: descriptive - only when its 'set' flag is 0; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0c88 @ 0xa00e0c88-0xa00e0ca8 (8 words, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: two extern words.
 */
extern unsigned int sys_ddr_param1_set_flag;
extern unsigned int sys_ddr_param1;

/*
 * Set the second training parameter to `value`, but only when sys_ddr_set_param1 has not set it explicitly
 * (its flag is still 0). Nothing in the image calls it.
 */
void sys_ddr_set_param1_default(unsigned int value)
{
    if (sys_ddr_param1_set_flag == 0)
        sys_ddr_param1 = value;
}
