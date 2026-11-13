/* sys_get_app_flag42_bit14  (FUN_a0082c38)
 *
 * Return bit 14 of the application flag halfword 0xA802AF42.
 * Returns: 0 or 1
 * Note: Nothing calls it.
 * Name basis: descriptive - code only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0082c38 @ 0xa0082c38, flags -mcpu=v8 -O2 -g (section default). Leaf.
 * Source form: '(app_port_flags >> 14) & 1'.
 */
extern unsigned short app_port_flags;

/* Return bit 14 of app_port_flags (1 or 0): the third of the three all-port bits (4, 9, 14). */
unsigned int sys_get_app_flag42_bit14(void)
{
    return (app_port_flags >> 14) & 1;
}
