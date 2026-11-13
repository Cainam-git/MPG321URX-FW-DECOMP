/* input_apply_port_enable_mask  (FUN_a006d46c)
 *
 * Power on the ports whose bit is set in the mask and power off the others.
 *   enable_mask: one bit per port
 * Name basis: derived - bit set and state 1 -> 2 (power on), bit clear -> 1 (power off); caller
 *   ipc_dispatch_command
 *
 * Matching notes
 * --------------
 * leon2s FUN_a006d46c @ 0xa006d46c, flags -mcpu=v8 -Os -g.
 * The counter is an unsigned char; the loop ends at nine passes.
 */

struct port_record { unsigned char state; unsigned char rest[19]; };
extern struct port_record input_port_records[];

#define LINK_STATE_POWER_OFF 1
#define LINK_STATE_POWER_ON  2

/*
 * Bit n of 'enable_mask' is port record n (0..8). A record whose bit is set and whose state is power off goes to
 * power on; a record whose bit is clear goes to power off. The mask has 8 bits, so record 8 always goes to power off.
 * Called from ipc_dispatch_command.
 */
void input_apply_port_enable_mask(unsigned char enable_mask)
{
  unsigned char port;

  for (port = 0; port < 9; port++) {
    if ((enable_mask >> port) & 1) {
      if (input_port_records[port].state == LINK_STATE_POWER_OFF)
        input_port_records[port].state = LINK_STATE_POWER_ON;
    } else
      input_port_records[port].state = LINK_STATE_POWER_OFF;
  }
}
