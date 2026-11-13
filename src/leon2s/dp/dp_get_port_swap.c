/* dp_get_port_swap  (FUN_a0083ec4)
 *
 * Return the DP receiver port swap flag.
 * Name basis: descriptive - flag set by dp_set_port_swap
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0083ec4 @ 0xa0083ec4 (-mcpu=v8 -Os)
 * Leaf routine without a register window. The flags carry no -g.
 */
extern unsigned char dp_port_swap_flag;

/* Return dp_port_swap_flag, the flag that dp_set_port_swap sets (1) or clears (0). */
unsigned char dp_get_port_swap(void)
{
    return dp_port_swap_flag;
}
