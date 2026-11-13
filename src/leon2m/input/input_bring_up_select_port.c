/* input_bring_up_select_port  (FUN_a00ef048)
 *
 * Select a port for bring-up and set its registers up.
 * Name basis: derived - step of bring-up state 5
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ef048 @ 0xa00ef048, flags -mcpu=v8 -O3 -g.
 * Source form: REG32 and LANE_REG are volatile 32-bit register accesses; the switch cases keep the firmware's
 * order (the lane is stored after the select-bit write).
 */

extern void pq_block_update_bits(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern unsigned char input_bring_up_lane, input_bring_up_port;
extern const unsigned short input_bring_up_lane_regs[4];
#define REG32(a) (*(volatile unsigned int *)(a))
#define LANE_REG(i) (*(volatile unsigned int *)(0xcf000000 | (input_bring_up_lane_regs[i] << 2)))

/* Register that takes one select bit for the ports 2/6 (bit 0) and the ports 3/7 (bit 2). */
#define BRING_UP_PORT_SELECT_REG 0xcf014750

/*
 * Choose the port to bring up, as input_set_bring_up_port does (lane 0 for port 0, 1 for port 1, 2 for
 * the ports 2 and 6, 3 for the ports 3 and 7; ports 2 and 3 clear the select bit, ports 6 and 7 set it).
 * Then write 0x16 into the register of that lane, or into the registers of all four lanes when the lane
 * is 8, and clear bit 5 of register 0x88 of the port's picture block.
 */
void input_bring_up_select_port(unsigned char port)
{
    unsigned char i;

    input_bring_up_port = port;
    switch (port) {
    case 0: input_bring_up_lane = 0; break;
    case 1: input_bring_up_lane = 1; break;
    case 2: REG32(BRING_UP_PORT_SELECT_REG) &= ~1; input_bring_up_lane = 2; break;
    case 6: REG32(BRING_UP_PORT_SELECT_REG) |= 1; input_bring_up_lane = 2; break;
    case 3: REG32(BRING_UP_PORT_SELECT_REG) &= ~4; input_bring_up_lane = 3; break;
    case 7: REG32(BRING_UP_PORT_SELECT_REG) |= 4; input_bring_up_lane = 3; break;
    }
    if (input_bring_up_lane == 8) {
        for (i = 0; i < 4; i++)
            LANE_REG(i) = 0x16;
    } else if (input_bring_up_lane < 4) {
        LANE_REG(input_bring_up_lane) = 0x16;
    }
    pq_block_update_bits(input_bring_up_port, 0x88, 0x20, 0);
}
