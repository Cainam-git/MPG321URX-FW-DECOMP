/* ipc_input_cpu_get_ready_bit  (FUN_a0136fc4)
 *
 * Return the ready bit of the input processor's status word.
 * Returns: 0 or 1
 * Name basis: derived - bit 0 of the low byte of the word at offset 0 of mailbox portal 1; called from start-
 *   up ('wait sub init')
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0136fc4, flags -mcpu=v8 -O2 -g. ipc_mailbox_read is declared without a prototype, as the firmware's
 * own calls need. The byte is read at offset +3 of the 4-byte local (the low byte on this big-endian target).
 */
extern int ipc_mailbox_read();

#define IPC_PORTAL_INPUT_CPU  1     /* mailbox portal of the input processor */
#define STATUS_WORD_OFFSET    0     /* word 0 of slot 0: bit 0 is set by the input program when it is ready */

/*
 * Return bit 0 of word 0 of slot 0 of the input processor's mailbox portal. The input program sets this bit
 * (ipc_post_ready_flag). Caller: startup_bring_up_system, which waits for it ('wait sub init').
 */
int ipc_input_cpu_get_ready_bit(void)
{
    unsigned int word;
    
    word = 0;
    ipc_mailbox_read(IPC_PORTAL_INPUT_CPU, STATUS_WORD_OFFSET, &word, 1);
    return *((unsigned char *)&word + 3) & 1;
}
