/* input_used_ports_in_state4  (FUN_a0090f30)
 *
 * Return 1 when every used input port is in application state 4.
 * Returns: 1 = all used ports in state 4
 * Note: State 4 also covers raw states 3, 5 and above 12; reached through a table.
 * Name basis: descriptive - input_is_port_used + port state map sys_api_get_channel_state_code
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0090f30 @ 0xa0090f30, flags -mcpu=v8 -O2 -g (section default).
 * Source form: the result is returned as 'settled & 1'.
 */

extern unsigned char input_is_port_used(unsigned char port);
extern unsigned char sys_api_get_channel_state_code(unsigned char ch);

/*
 * Return 1 when every port of the present layout (input_is_port_used) has state code 4, else 0.
 * No routine calls it directly; it is reached through a table.
 */
unsigned char input_used_ports_in_state4(void)
{
    unsigned char settled = 1;
    unsigned char i;

    for (i = 0; i <= 3; i++)
        if (input_is_port_used(i) && sys_api_get_channel_state_code(i) != 4) {
            settled = 0;
            break;
        }
    return settled & 1;
}
