/* ipc_input_cpu_get_state_bit24  (FUN_a0136ff0)
 *
 * Return state bit 24 of the input processor (its OSD unzip busy flag).
 * Returns: 0 or 1
 * Note: No routine calls it.
 * Name basis: derived - word at offset 0xC of mailbox portal 1, lowest bit of its top byte; the input
 *   program's ipc_publish_status_flags puts its OSD unzip busy flag there
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0136ff0, flags -mcpu=v8 -O2 -g. ipc_mailbox_read is declared without a prototype, as the firmware's
 * own calls need. The byte is read at offset +0 of the 4-byte local (the top byte on this big-endian target).
 */
extern int ipc_mailbox_read();

#define IPC_PORTAL_INPUT_CPU  1     /* mailbox portal of the input processor */
#define STATE_WORD_OFFSET     0xc   /* word 3 of slot 0: the state word the input program publishes */

/*
 * Return bit 24 of the state word (the lowest bit of its top byte). The input program fills that byte in
 * ipc_publish_status_flags; bit 0 of the byte is its osd_unzip_busy_flag. Nothing in the firmware calls this
 * routine.
 */
int ipc_input_cpu_get_state_bit24(void)
{
    unsigned int state;
    
    state = 0;
    ipc_mailbox_read(IPC_PORTAL_INPUT_CPU, STATE_WORD_OFFSET, &state, 1);
    return *((unsigned char *)&state) & 1;
}
