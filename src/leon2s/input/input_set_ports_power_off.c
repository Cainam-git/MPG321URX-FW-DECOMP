/* input_set_ports_power_off  (FUN_a006d3d8)
 *
 * Set all nine port records to the power-off link state.
 * Name basis: derived - state 1 of the link state machines = power off (TMDS_PowerOff); callers are the
 *   receiver power-off routines
 *
 * Matching notes
 * --------------
 * leon2s FUN_a006d3d8 @ 0xa006d3d8, flags -mcpu=v8 -Os -g.
 * The counter is an unsigned char, which gives the masking (and with 0xff) and the unsigned branch of the firmware.
 */

#define PORT_RECORD_SIZE      20
#define PORT_RECORD_COUNT     9
#define LINK_STATE_POWER_OFF  1

extern unsigned char input_port_records[];      /* byte +0 of each 20-byte record is the link state */

/* Set the link state of all nine port records to power off; called from the receiver power-off routines. */
void input_set_ports_power_off(void)
{
    unsigned char port = 0;
    unsigned int offset;

    do {
        offset = port * PORT_RECORD_SIZE;
        port = port + 1;
        input_port_records[offset] = LINK_STATE_POWER_OFF;
    } while (port <= PORT_RECORD_COUNT - 1);
}
