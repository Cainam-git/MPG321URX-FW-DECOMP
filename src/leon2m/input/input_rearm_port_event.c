/* input_rearm_port_event  (FUN_a00808ac)
 *
 * Reset the last-state byte of port n (4 = all) and optionally force its pending event.
 *   n: port 0..3, 4 = all
 *   force: 1 = also force the delayed event
 * Note: Last states 0xA802AF60[], force bits 0xA802AF45; both read by the event generator.
 * Name basis: derived - event generator sys_app_generate_events uses af60[] = 0xFF as 'unknown' and af45 bit p
 *   as 'post now'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00808ac @ 0xa00808ac, flags -mcpu=v8 -O3 -g.
 * Source form: one if / else-if chain for the single bit (not a shift), and four separate stores for n == 4.
 */

extern unsigned char app_port_last_states[4];
extern unsigned char app_port_rearm_bits;

/*
 * Forget the last state seen for port n (4 = all four ports) by setting it to 0xFF, a value no state
 * code takes. The event generator (sys_app_generate_events) then sees a changed state at its next
 * step. With force == 1 the port's bit in app_port_rearm_bits is set as well: the event generator
 * posts a pending event of that port without waiting for the port's timer and clears the bit.
 *
 *   n      port 0..3, or 4 for all
 *   force  1 = also set the bit
 */
void input_rearm_port_event(unsigned char n, unsigned char force)
{
    if (n == 4) {
        app_port_last_states[0] = 0xff;
        app_port_last_states[1] = 0xff;
        app_port_last_states[2] = 0xff;
        app_port_last_states[3] = 0xff;
        if (force == 1)
            app_port_rearm_bits |= 0xf;
    } else {
        app_port_last_states[n] = 0xff;
        if (force == 1) {
            if (n == 0)
                app_port_rearm_bits |= 1;
            else if (n == 1)
                app_port_rearm_bits |= 2;
            else if (n == 2)
                app_port_rearm_bits |= 4;
            else if (n == 3)
                app_port_rearm_bits |= 8;
        }
    }
}
