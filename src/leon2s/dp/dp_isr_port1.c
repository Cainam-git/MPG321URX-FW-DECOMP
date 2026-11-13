/* dp_isr_port1  (FUN_a00aea0c)
 *
 * Interrupt work for port 1: read the status block when enabled, then the common step.
 * Name basis: descriptive - flag byte at 0xA807DE63
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00aea0c @ 0xa00aea0c (-mcpu=v8 -Os -g)
 * Source form: the unused parameters 2 to 6 are handed on to dp_ack_link_events, which is declared without a
 * parameter list.
 */
extern unsigned char dp_input_record1_byte_0x11f;       /* byte 0x11F of the record of port 1 */
extern int dp_ack_link_events();
extern int dp_read_status_block();

/*
 * Interrupt work of DP receiver 1: when byte 0x11F of its record is 1, read the status block
 * (dp_read_status_block); then acknowledge the link events (dp_ack_link_events). The other parameters are
 * only handed on to dp_ack_link_events.
 */
void dp_isr_port1(unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                  unsigned int arg5, unsigned int arg6)
{
    if (dp_input_record1_byte_0x11f == 1) {
        dp_read_status_block(1);
    }
    dp_ack_link_events(1, arg2, arg3, arg4, arg5, arg6);
    return;
}
