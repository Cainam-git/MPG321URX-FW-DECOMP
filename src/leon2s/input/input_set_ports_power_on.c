/* input_set_ports_power_on  (FUN_a006d39c)
 *
 * Set ports 0..6 to the power-on link state.
 * Name basis: derived - state 2 of the link state machines = power on (TMDS_PowerOn)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a006d39c @ 0xa006d39c, flags -mcpu=v8 -Os -g.
 * Seven separate stores in ascending order; the compiler schedules the last one first.
 */

/* Port records: 20 bytes per input stream, byte +0 is the link state (see docs/DATA.md). */
struct port_record { unsigned char state; unsigned char rest[19]; };
extern struct port_record input_port_records[];

/* Link state values of the port records. */
#define LINK_STATE_POWER_OFF 1
#define LINK_STATE_POWER_ON  2

/* Set the link state of the port records 0..6 to power on. Called from input_set_ports_power_on_wrapper. */
void input_set_ports_power_on(void)
{
    input_port_records[0].state = LINK_STATE_POWER_ON;
    input_port_records[1].state = LINK_STATE_POWER_ON;
    input_port_records[2].state = LINK_STATE_POWER_ON;
    input_port_records[3].state = LINK_STATE_POWER_ON;
    input_port_records[4].state = LINK_STATE_POWER_ON;
    input_port_records[5].state = LINK_STATE_POWER_ON;
    input_port_records[6].state = LINK_STATE_POWER_ON;
}
