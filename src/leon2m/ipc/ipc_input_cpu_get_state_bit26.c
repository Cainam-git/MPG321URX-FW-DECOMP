/* ipc_input_cpu_get_state_bit26  (FUN_a013701c)
 *
 * Return state bit 26 of the input processor.
 * Returns: 0 or 1
 * Name basis: descriptive - word at offset 0xC of mailbox portal 1; called from start-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013701c, flags -mcpu=v8 -O3 -g. ipc_mailbox_read is declared without a prototype, as the firmware's
 * own calls need.
 */
extern int ipc_mailbox_read();

#define IPC_PORTAL_INPUT_CPU  1     /* mailbox portal of the input processor */
#define STATE_WORD_OFFSET     0xc   /* word 3 of slot 0: the state word the input program publishes */

/*
 * Return bit 26 of the state word. The input program sets it from its sys_otp_shared_loaded_flag
 * (ipc_publish_status_flags). Caller: startup_bring_up_system, which waits for it ('wait otp ready').
 */
int ipc_input_cpu_get_state_bit26(void)
{
    unsigned int state;
    
    state = 0;
    ipc_mailbox_read(IPC_PORTAL_INPUT_CPU, STATE_WORD_OFFSET, &state, 1);
    return (state >> 0x1a) & 1;
}
