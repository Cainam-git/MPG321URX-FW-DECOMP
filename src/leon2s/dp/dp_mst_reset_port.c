/* dp_mst_reset_port  (FUN_a00dc0a8)
 *
 * Clear the MST service's records for a port and print a line.
 * Name basis: descriptive - record bytes and the per-port byte at 0xA8078838; called from the command
 *   dispatcher, the output hot-plug action and dp_run_link_state
 *
 * Matching notes
 * --------------
 * FUN_a00dc0a8 (leon2s, 0xa00dc0a8-0xa00dc214, 364 bytes, 91 words), flags -mcpu=v8 -Os -g.
 * The local port index is an unsigned char (the type of dp_mst_message_state_port), reloaded from the current port at
 * three points. The print text is the string symbol DAT_9f1ccc30. The register block pointer table
 * dp_mst_ctl_reg_blocks is volatile as in dp_mst_send_up_message_step.
 * Source forms: the first six clears are in the order 830, 828, 80e, 80a, 808, 800; in the last block the u16
 * clears of 7fa / 7f8 come first, then the port is reloaded and the 838 and 760b0 bytes are written (the
 * firmware order is 760b0, 7fa, 7f8, 838). The addressed flag is cleared after the if (the firmware does it
 * in the delay slot of the branch and before the return).
 */
extern unsigned char dp_mst_message_state_up_read_index;
extern unsigned char dp_mst_message_state_up_write_index;
extern unsigned char dp_mst_message_state_fwd_read_index;
extern unsigned char dp_mst_message_state_fwd_write_index;
extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_message_state_addressed_flag;
extern unsigned char dp_mst_message_state_byte_0x4f;
extern unsigned short dp_mst_message_state;
extern unsigned short dp_mst_message_state_half_2;
extern void dp_pulse_reg30e_clear(unsigned char param_1);
extern void dp_mst_queue_clear_payload_table_request(void);
extern int dbg_printf();
extern int dp_tx_get_mode_flag();
extern volatile unsigned int *dp_mst_ctl_reg_blocks[];
extern unsigned short dp_mst_message_state_reply_offsets[];
extern unsigned short dp_mst_reply_body_write_offsets[];
extern unsigned char dp_mst_last_request_numbers[];
extern unsigned char dp_mst_port_reply_flags[];
extern unsigned char dp_mst_message_state_reply_read_indexes[];
extern unsigned char dp_mst_message_state_reply_write_indexes[];
extern unsigned char dp_mst_message_state_rx_read_indexes[];
extern unsigned char dp_mst_message_state_rx_write_indexes[];
extern unsigned char dp_mst_message_state_tx_states[];
extern unsigned char dp_mst_message_state_up_wait_flags[];
extern unsigned char dp_mst_message_state_reply_wait_flags[];
extern const char DAT_9f1ccc30[];

/*
 * Reset the MST message service for the current port (dp_mst_message_state_port).
 * Takes no parameters, returns nothing. Called from the mailbox command that switches MST on or
 * off (0x24), the output hot-plug action (DPTX_IsHPDAction_Off) and dp_run_link_state.
 *
 * Prints a debug line with the port number. Only when the addressed flag is 1 (set by the
 * LINK_ADDRESS answer) does it clear the records: the receive ring indexes, the reply body offsets
 * and reply ring indexes of the port, the forward and up ring indexes, the eight status bytes at
 * dp_mst_last_request_numbers, the two wait flags and the transmit state of the port, and bits 4..5 of register
 * word 0xccc/4 of the port's register block. It then sets the port's reply flag to 1, clears
 * byte 0x4F of the message state, and, when dp_tx_get_mode_flag() is non-zero, queues one message
 * with dp_mst_queue_clear_payload_table_request. Last, it pulses register 0x30E clear for the port.
 * The addressed flag is cleared in every case.
 */
void dp_mst_reset_port(void)
{
    unsigned char port; /* current port, reloaded where the code re-reads it */
    unsigned char i;

    dbg_printf(DAT_9f1ccc30, dp_mst_message_state_port);
    if (dp_mst_message_state_addressed_flag == 1) {
        port = dp_mst_message_state_port;
        dp_mst_message_state_rx_write_indexes[port] = 0;
        dp_mst_message_state_rx_read_indexes[port] = 0;
        dp_mst_reply_body_write_offsets[port] = 0;
        dp_mst_message_state_reply_offsets[port] = 0;
        dp_mst_message_state_reply_write_indexes[port] = 0;
        dp_mst_message_state_reply_read_indexes[port] = 0;
        dp_mst_message_state_fwd_write_index = 0;
        dp_mst_message_state_fwd_read_index = 0;
        dp_mst_message_state_up_write_index = 0;
        dp_mst_message_state_up_read_index = 0;
        /* Four pairs of bytes. */
        i = 0;
        do {
            dp_mst_last_request_numbers[i * 2] = 0;
            dp_mst_last_request_numbers[i * 2 + 1] = 0;
            i++;
        } while (i < 4);
        port = dp_mst_message_state_port;
        dp_mst_message_state_reply_wait_flags[port] = 0;
        dp_mst_message_state_up_wait_flags[port] = 0;
        dp_mst_ctl_reg_blocks[port][0xccc / 4] &= ~0x30;
        dp_mst_message_state_half_2 = 0;
        dp_mst_message_state = 0;
        port = dp_mst_message_state_port;
        dp_mst_message_state_tx_states[port] = 0;
        dp_mst_port_reply_flags[port] = 1; /* down-reply sender flag */
        dp_mst_message_state_byte_0x4f = 0;
        if (dp_tx_get_mode_flag() & 0xff) /* bit 29 of the first path record's mode word */
            dp_mst_queue_clear_payload_table_request();
        dp_pulse_reg30e_clear(dp_mst_message_state_port);
    }
    dp_mst_message_state_addressed_flag = 0;
}
