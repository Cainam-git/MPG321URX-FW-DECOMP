/* input_set_bring_up_port  (FUN_a00eef7c)
 *
 * Store the port that is being brought up and set its hardware select bit.
 * Name basis: descriptive - bytes at 0xA8026A78/79 and bit 0 or 2 of 0xCF014750
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00eef7c @ 0xa00eef7c, flags -mcpu=v8 -O3 -g.
 * Source form: R() is a volatile 32-bit register access; the cases are separate bodies in the firmware's order.
 */

extern unsigned char input_bring_up_lane, input_bring_up_port;
#define REG32(a) (*(volatile unsigned int *)(a))

/* Register that takes one select bit for the ports 2/6 (bit 0) and the ports 3/7 (bit 2). */
#define BRING_UP_PORT_SELECT_REG 0xcf014750

/*
 * Remember the port that is being brought up and the lane it uses:
 *   port 0 -> lane 0,  port 1 -> lane 1,  ports 2 and 6 -> lane 2,  ports 3 and 7 -> lane 3.
 * Ports 2 and 3 clear the port's bit in BRING_UP_PORT_SELECT_REG, ports 6 and 7 set it.
 * Other port numbers are stored without changing the lane.
 */
void input_set_bring_up_port(unsigned char port)
{
    input_bring_up_port = port;
    switch (port) {
    case 0: input_bring_up_lane = 0; break;
    case 1: input_bring_up_lane = 1; break;
    case 2: input_bring_up_lane = 2; REG32(BRING_UP_PORT_SELECT_REG) &= ~1; break;
    case 6: input_bring_up_lane = 2; REG32(BRING_UP_PORT_SELECT_REG) |= 1; break;
    case 3: input_bring_up_lane = 3; REG32(BRING_UP_PORT_SELECT_REG) &= ~4; break;
    case 7: input_bring_up_lane = 3; REG32(BRING_UP_PORT_SELECT_REG) |= 4; break;
    }
}
