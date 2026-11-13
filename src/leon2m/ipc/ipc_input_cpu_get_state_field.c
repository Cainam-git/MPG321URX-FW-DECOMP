/* ipc_input_cpu_get_state_field  (FUN_a0137724)
 *
 * Return the 2-bit field at bits 6-7 of the input processor's state word.
 * Returns: 0..3
 * Name basis: descriptive - word at offset 0xC of mailbox portal 1; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0137724, flags -mcpu=v8 -O3 -g. ipc_mailbox_read is declared without a prototype, as the firmware's
 * own calls need.
 */
extern int ipc_mailbox_read();

#define IPC_PORTAL_INPUT_CPU  1     /* mailbox portal of the input processor */
#define STATE_WORD_OFFSET     0xc   /* word 3 of slot 0: the state word the input program publishes */

/*
 * Return bits 6..7 of the state word, a value 0..3. The input program fills them with the low two bits of
 * dp_tx_get_status_byte (ipc_publish_port_status). Nothing in the firmware calls this routine.
 */
int ipc_input_cpu_get_state_field(void)
{
    unsigned int state;
    
    state = 0;
    ipc_mailbox_read(IPC_PORTAL_INPUT_CPU, STATE_WORD_OFFSET, &state, 1);
    return (state >> 6) & 3;
}
