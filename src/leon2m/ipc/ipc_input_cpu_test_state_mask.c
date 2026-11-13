/* ipc_input_cpu_test_state_mask  (FUN_a01376ec)
 *
 * Return whether any of the given bits is set in the input processor's state word.
 * Returns: 0 or 1
 * Name basis: descriptive - word at offset 0xC of mailbox portal 1; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01376ec, flags -mcpu=v8 -O3 -g. The two debug-print declarations are not used by the routine.
 */
extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern unsigned char dbg_is_print_enabled(unsigned int level);
extern int dbg_printf();

#define IPC_PORTAL_INPUT_CPU  1     /* mailbox portal of the input processor */
#define STATE_WORD_OFFSET     0xc   /* word 3 of slot 0: the state word the input program publishes */

/*
 * Return 1 when any bit of the mask is set in the low byte of the state word, else 0. Bits 0..5 of that byte
 * are the input program's port event flags and bits 6..7 the DisplayPort transmitter status (ipc_publish_port_status).
 * No call to this routine is found in the code.
 *   mask: bits to test
 */
unsigned char ipc_input_cpu_test_state_mask(unsigned char mask)
{
    unsigned int state = 0;
    ipc_mailbox_read(IPC_PORTAL_INPUT_CPU, STATE_WORD_OFFSET, &state, 1);
    return (unsigned char)(mask & state) != 0;
}
