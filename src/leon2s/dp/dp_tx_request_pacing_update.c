/* dp_tx_request_pacing_update  (FUN_a0089e24)
 *
 * Enable the pacing update of a DP output and clear its updated and rewritten marks.
 *   port: DP output 0..4
 * Name basis: derived - sets byte 0 of record 0xA807CD04[i] that DPTX_SetBrilliantMode requires; mailbox
 *   command 0x60
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g. A leaf routine.
 * Source form: the three stores are written in field order (enabled, updated, rewritten); the compiler
 * schedules them as enabled, rewritten, updated.
 */
/* 8-byte pacing record of one DP output; same layout as in dp_tx_refresh_reg73. */
struct pacing_record {
    unsigned char enabled;
    unsigned char updated;
    unsigned char byte_0x02[2];
    unsigned char rewritten;
    unsigned char byte_0x05[3];
};
extern struct pacing_record dp_tx_pacing_records[];

/*
 * Enable the pacing update of a DP output (DPTX_SetBrilliantMode skips outputs whose record is not enabled)
 * and clear the updated and rewritten marks, so the next update starts from the beginning.
 *
 *   port: DP output 0..4
 *
 * Called from the mailbox command dispatcher (ipc_dispatch_command).
 */
void dp_tx_request_pacing_update(unsigned char port)
{
    dp_tx_pacing_records[port].enabled = 1;
    dp_tx_pacing_records[port].updated = 0;
    dp_tx_pacing_records[port].rewritten = 0;
}
