/* sys_poll_port_flag5_holdoff  (FUN_a014e768)
 *
 * Return status bit 5 of a port record and keep the port's hold-off counter up to date.
 * Returns: bit 5 of the port status
 * Name basis: descriptive - counter byte per port set to 2 or counted down; unused
 *
 * Matching notes
 * --------------
 * FUN_a014e768 (leon2m 0xa014e768-0xa014e7bc, 84 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: the status bit is read into an unsigned int; the counter is decremented only when non-zero.
 */
/* Port record (0x2a bytes); only the status halfword at +0 is used here. */
struct port_record { unsigned short status; unsigned char rest[0x28]; };
extern struct port_record port_records[];
extern unsigned char sys_port_holdoff_counts[];

#define PORT_STATUS_BIT5 5
#define HOLDOFF_RELOAD   2      /* value the counter is set to while the bit is 1 */

/*
 * Return status bit 5 of the port record 'port'. While the bit is 1 the hold-off counter of that index is kept at
 * 2; once it is 0 the counter counts down by one per call until it reaches 0.
 *
 *   port  index into port_records and into the counter array
 *
 * Nothing in the firmware calls it.
 */
unsigned int sys_poll_port_flag5_holdoff(unsigned char port)
{
    unsigned int bit = (port_records[port].status >> PORT_STATUS_BIT5) & 1;

    if (bit == 1)
        sys_port_holdoff_counts[port] = HOLDOFF_RELOAD;
    else if (sys_port_holdoff_counts[port] != 0)
        sys_port_holdoff_counts[port]--;
    return bit;
}
