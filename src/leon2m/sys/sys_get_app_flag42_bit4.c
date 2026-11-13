/* sys_get_app_flag42_bit4  (FUN_a0082c20)
 *
 * Return bit 4 of the application flag halfword 0xA802AF42.
 * Returns: 0 or 1
 * Note: Nothing calls it.
 * Name basis: descriptive - code only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0082c20 @ 0xa0082c20, flags -mcpu=v8 -O3 -g. Leaf.
 * Source form: the masked value in its own unsigned int local ('m = app_port_flags & 0x10; return m != 0;') gives the
 * and/cmp/addx sequence; '(x & 0x10) != 0' in one expression becomes srl/and.
 */
extern unsigned short app_port_flags;

#define APP_PORT_FLAG_ALL_PORTS_0 0x0010        /* bit 4: the first of the three all-port bits (4, 9, 14) */

/* Return bit 4 of app_port_flags (1 or 0). */
int sys_get_app_flag42_bit4(void)
{
    unsigned int masked = app_port_flags & APP_PORT_FLAG_ALL_PORTS_0;

    return masked != 0;
}
