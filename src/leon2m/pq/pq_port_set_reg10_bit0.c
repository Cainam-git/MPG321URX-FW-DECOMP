/* pq_port_set_reg10_bit0  (FUN_a0118a28)
 *
 * Set or clear bit 0 of register 0x10 of a port block.
 * Name basis: descriptive - reads and writes register 0x10 through pq_port_read8 / pq_port_write8; used by the
 *   colour-fill and channel routines
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0118a28 @ 0xa0118a28, flags -mcpu=v8 -O2 -g.
 * Source form: the callees are declared without prototypes and returning int; the block number is cut to
 * its low byte once before the test; both arms read the register and end in a tail call.
 */
extern int pq_port_read8();
extern int pq_port_write8();

#define PORT_REG_10 0x10            /* register 0x10 of a port block (as in pq_load_block8_config) */

/*
 * Set (on != 0) or clear bit 0 of register 0x10 of a port block, by read-modify-write through
 * pq_port_read8 / pq_port_write8.
 *
 *   block   port block 0..3, or 8 for all four: the value is read from block 0 and written to all four
 *   on      1 sets the bit, 0 clears it
 *
 * Called by pq_block_blank, pq_block_blank_with_color, panel_correct_clock_first_step,
 * input_channel_bring_up_task and the memory test routines (dbg_ddr_*). pq_load_block8_config has its own
 * copy of this routine.
 */
void pq_port_set_reg10_bit0(unsigned char block, unsigned char on)
{
    unsigned char reg10;

    block &= 0xff;
    if (on != 0) {
        reg10 = pq_port_read8(block, PORT_REG_10);
        pq_port_write8(block, PORT_REG_10, (reg10 | 1) & 0xff);
    } else {
        reg10 = pq_port_read8(block, PORT_REG_10);
        pq_port_write8(block, PORT_REG_10, reg10 & 0xfe);
    }
}
