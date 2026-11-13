/* dp_isr_port0  (FUN_a00ae850)
 *
 * Interrupt work for port 0: copy and clear the status registers into a ring when signalled.
 * Name basis: descriptive - ring of 16 rows of 0x30 registers; then a register pulse
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ae850 @ 0xa00ae850-0xa00aea0c (-mcpu=v8 -Os -g).
 * Source form: the inline reg_addr() helper keeps (n + 0xe00) * 4 unfolded; each access calls it. The final
 * dp_ack_link_events call is a tail call.
 */
extern unsigned char dp_input_record0_byte_0x11f;
extern unsigned char dp_mst_message_state_rx_write_indexes;
extern unsigned char dp_mst_message_state_status_row;
extern unsigned char dp_mst_chunk_rings[][0x30];
extern unsigned char dp_status_copy_rows[][0x30];
extern unsigned int dp_read_status_block(unsigned int);
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void dp_ack_link_events(unsigned char);

#define REG_CF003800 (*(volatile unsigned int *)0xcf003800)     /* non-zero: a message arrived (first group) */
#define REG_CF003980 (*(volatile unsigned int *)0xcf003980)     /* non-zero: a message arrived (second group) */
#define REG_CF004680 (*(volatile unsigned int *)0xcf004680)     /* bit 1 set: the work below runs; 0x22 is written at its end */

#define CHUNK_REGS_FIRST  0xe00                 /* first of the 0x30 registers copied to the ring dp_mst_chunk_rings */
#define CHUNK_REGS_SECOND 0xe60                 /* first of the 0x30 registers copied to dp_status_copy_rows */
#define CHUNK_REG_COUNT   0x30
#define CHUNK_RING_ROWS   16

/* Register n of the receiver block: address (n * 4) | 0xCF000000. */
static __inline__ volatile unsigned int *reg_addr(unsigned int a)
{
    return (volatile unsigned int *)((a * 4) | 0xcf000000);
}

/*
 * Interrupt work for DP receiver 0.
 *
 * When byte 0x11F of the port 0 record is 1, the status block is read first (dp_read_status_block). When bit 1
 * of hardware word 0xCF004680 is set: wait a fixed count of 60000 idle loops; then, if word 0xCF003800 is not 0,
 * copy the 0x30 registers 0xE00.. into row dp_mst_message_state_rx_write_indexes of the 16-row ring
 * dp_mst_chunk_rings, clearing each register as it is copied, and step the row index 0..15 round the ring; else if
 * word 0xCF003980 is not 0, copy the 0x30 registers 0xE60.. the same way into row
 * dp_mst_message_state_status_row of dp_status_copy_rows (this row index is not stepped here). Then bit 3 of register
 * 0xF7 is set, 0x22 is written to 0xCF004680 (with bit 7 of register 0x30 set around the write).
 * The last step is dp_ack_link_events for port 0.
 */
void dp_isr_port0(void)
{
    unsigned short i;

    if (dp_input_record0_byte_0x11f == 1)
        dp_read_status_block(0);
    if (REG_CF004680 & 2) {
        for (i = 0; i < 60000; i++)
            __asm__("nop");
        if (REG_CF003800 != 0) {
            for (i = 0; i < CHUNK_REG_COUNT; i++) {
                dp_mst_chunk_rings[dp_mst_message_state_rx_write_indexes][i] = *reg_addr(i + CHUNK_REGS_FIRST);
                *reg_addr(i + CHUNK_REGS_FIRST) = 0;
            }
            if (dp_mst_message_state_rx_write_indexes <= CHUNK_RING_ROWS - 2)
                dp_mst_message_state_rx_write_indexes++;
            else
                dp_mst_message_state_rx_write_indexes = 0;
        } else if (REG_CF003980 != 0) {
            for (i = 0; i < CHUNK_REG_COUNT; i++) {
                dp_status_copy_rows[dp_mst_message_state_status_row][i] = *reg_addr(i + CHUNK_REGS_SECOND);
                *reg_addr(i + CHUNK_REGS_SECOND) = 0;
            }
        }
        dp_reg_update_bits(0, 0xf7, 8, 1);
        dp_reg_update_bits(0, 0x30, 0x80, 1);
        REG_CF004680 = 0x22;
        dp_reg_update_bits(0, 0x30, 0x80, 0);
    }
    dp_ack_link_events(0);
}
