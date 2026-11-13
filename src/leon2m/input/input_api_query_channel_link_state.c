/* input_api_query_channel_link_state  (FUN_a014489c)
 *
 * Ask the other side for a link value when the channel's block reports code 0xB1, else 8.
 * Returns: reply byte or 8
 * Name basis: descriptive - mailbox request for the active port; called from APPActionDispatcher
 *
 * Matching notes
 * --------------
 * leon2m input_api_query_channel_link_state @ 0xa014489c-0xa01448fc (96 bytes, 24 words), flags -mcpu=v8 -O3 -g.
 * Source form: keep one return of link_value set in both arms; the 'mov 8,%o0' sits in the bne delay slot and both paths meet at one 'and %o0,0xff,%i0'. Two returns give 'mov 8,%i0'.
 */
extern unsigned char channel_records;
extern int input_block_get_signal_code(unsigned char);
extern unsigned char sys_get_active_port_code(void);
extern int input_port_id_to_entry_index(unsigned char);
extern int ipc_get_input_setting_byte(unsigned char);

/*
 * Ask the input processor for a setting byte when the channel's input block reports signal code 0xB1.
 *
 * channel: only its low byte is used, as an index into channel_records (not range-checked).
 * Bits 12-15 of the channel record's status word (its port) are passed to input_block_get_signal_code. If
 * the code is 0xB1, the mode byte of the active port (sys_get_active_port_code) is converted to a port entry
 * index and ipc_get_input_setting_byte asks the input processor for that entry's setting byte, which is
 * returned. Otherwise 8 is returned.
 *
 * Caller: APPActionDispatcher.
 */
unsigned char input_api_query_channel_link_state(unsigned int channel)
{
    unsigned int port;
    unsigned int link_value;

    /* Bits 12-15 of the channel record's status word: the channel's port. */
    port = (*(unsigned int *)(&channel_records + (channel & 0xff) * 0x78) >> 0xc) & 0xf;
    /* 0xB1 selects the path that asks the input processor for a setting byte. */
    if ((input_block_get_signal_code(port) & 0xff) == 0xb1) {
        link_value = sys_get_active_port_code() & 0xff;
        link_value = input_port_id_to_entry_index(link_value) & 0xff;
        link_value = ipc_get_input_setting_byte(link_value);
    } else
        link_value = 8;
    return link_value;
}
