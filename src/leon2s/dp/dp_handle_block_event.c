/* dp_handle_block_event  (FUN_a00aeb6c)
 *
 * Note a block event for a port and pulse its control bit when one of two event bits is set.
 * Name basis: descriptive - flag byte at 0xA8079310; register 0x463 bits
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00aeb6c @ 0xa00aeb6c (-mcpu=v8 -Os)
 * Source form: the first test jumps over the second with a goto; the parameters stay unsigned int with the
 * port masked into its own local.
 */
extern void dp_set_reg30_bit6(unsigned int);
extern void dp_reg_update_bits();
extern int dp_block_get_reg88_bit15();
extern int dp_block_get_reg88_bit7();
extern unsigned char dp_block_event_handled_flags[];            /* per port: 1 once dp_handle_block_event has handled the event */

/*
 * When dp_block_get_reg88_bit15 or dp_block_get_reg88_bit7 returns non-zero (tested in that order), mark the
 * event as handled for the port, set bits 0 and 1 of register 0x463 with bit 7 of register 0x30 set around
 * the two writes, and pulse bit 6 of register 0x30 (dp_set_reg30_bit6). Otherwise do nothing.
 *   port: DP receiver (0 or 1)
 *   unused: not used
 * Called by dp_port_task while the port's byte 0x11F is 1 and the handled mark is still 0.
 */
void dp_handle_block_event(unsigned int port, unsigned int unused)
{
    unsigned int masked_port;
    unsigned int event;

    masked_port = port & 0xff;
    event = dp_block_get_reg88_bit15(masked_port);
    if ((event & 0xff) != 0) goto handle;
    if ((dp_block_get_reg88_bit7(masked_port) & 0xff) == 0) return;
handle:
    dp_block_event_handled_flags[masked_port] = 1;
    dp_reg_update_bits(masked_port, 0x30, 0x80, 1);
    dp_reg_update_bits(masked_port, 0x463, 1, 1);
    dp_reg_update_bits(masked_port, 0x463, 2, 1);
    dp_reg_update_bits(masked_port, 0x30, 0x80, 0);
    dp_set_reg30_bit6(masked_port);
}
