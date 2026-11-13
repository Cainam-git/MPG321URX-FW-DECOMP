/* ipc_input_cpu_test_port_mask  (FUN_a01377a4)
 *
 * Return whether a port mask overlaps bits 8-15 of the input processor's state word.
 * Returns: 0 or 1
 * Name basis: descriptive - word at offset 0xC of mailbox portal 1; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01377a4, flags -mcpu=v8 -O3 -g. ipc_mailbox_read is declared without a prototype, as the firmware's
 * own calls need. The second parameter is declared and not used.
 */
extern void ipc_mailbox_read();

#define IPC_PORTAL_INPUT_CPU  1     /* mailbox portal of the input processor */
#define STATE_WORD_OFFSET     0xc   /* word 3 of slot 0: the state word the input program publishes */

/*
 * Return 1 when any bit of the mask is set in bits 8..15 of the state word, else 0. The input program fills those
 * bits with dp_tx_get_hpd_status (ipc_publish_port_status). Nothing in the firmware calls this routine.
 *   mask:   bits to test
 *   unused: not used
 */
unsigned int ipc_input_cpu_test_port_mask(unsigned short mask, unsigned int unused)
{
    unsigned int state;
    
    state = 0;
    ipc_mailbox_read(IPC_PORTAL_INPUT_CPU, STATE_WORD_OFFSET, &state, 1);
    return (mask & ((state & 0xff00) >> 8)) != 0;
}
