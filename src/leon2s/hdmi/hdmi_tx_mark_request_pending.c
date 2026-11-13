/* hdmi_tx_mark_request_pending  (FUN_a00918ec)
 *
 * Mark the HDMI TX request of a channel as pending.
 *   port: HDMI TX port 0/1
 * Name basis: derived - sets word 4 bit 2 read by hdmi_tx_apply_pending_request; mailbox commands 0x41..0x44
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00918ec @ 0xa00918ec (-mcpu=v8 -Os -g)
 * The index expression offset / 4 + 4 on the word array gives sll %o5, 2 and folds the +16 bytes into the
 * displacement (ld / st [%o5 + 0x10]), as in hdmi_tx_clear_frl_mode.
 */
extern unsigned int hdmi_tx_output_records[];

#define CHANNEL_SIZE 0x1c               /* bytes per HDMI TX channel record */
#define CHANNEL_REQUEST_PENDING 4       /* word 4 (+0x10), bit 2: request_pending */

/* Set request_pending, bit 2 of word 4 (+0x10) of the record of HDMI TX channel 'port'. */
void hdmi_tx_mark_request_pending(unsigned int port)
{
    unsigned int offset;
    
    offset = (port & 0xff) * CHANNEL_SIZE;
    hdmi_tx_output_records[offset / 4 + 4] |= CHANNEL_REQUEST_PENDING;
    return;
}
