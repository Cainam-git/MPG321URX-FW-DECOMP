/* dp_flag_port_stream_reset  (FUN_a006d568)
 *
 * Flag a DP port for a stream reset and clear its status bit 6.
 *   record: port record
 *   port
 * Name basis: descriptive - sets bit port of a pending byte, clears record bit 6, calls the port reset helper;
 *   caller dp_run_link_state
 *
 * Matching notes
 * --------------
 * FUN_a006d568 (leon2s, 0xa006d568-0xa006d5a8, 64 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the port is masked into the parameter itself ('orcc %i1,0,%i0' copies it into the argument of
 * the tail call and tests it); the result of dp_get_regc1_bit0 is dropped.
 */
extern int audio_flag_dp_resync();
extern void irq_empty_vector_handler_copy8(int);
extern int dp_get_regc1_bit0();

/*
 * Flag a port for a stream reset: calls audio_flag_dp_resync for the port, clears bit 6 (0x40) of the
 * halfword at +0x12 of the port record, then calls irq_empty_vector_handler_copy8 for the port.
 * For port 0 it first calls dp_get_regc1_bit0(0) and drops the result.
 *   record: the port's record (flags halfword at +0x12)
 *   port:   port number
 * Called by dp_run_link_state.
 */
void dp_flag_port_stream_reset(int record, int port)
{
    unsigned short *flags;

    port = port & 0xff;
    if (port == 0) {
        dp_get_regc1_bit0(0);
    }
    audio_flag_dp_resync(port);
    flags = (unsigned short *)(record + 0x12);
    *flags = *flags & 0xffbf;
    irq_empty_vector_handler_copy8(port);
}
