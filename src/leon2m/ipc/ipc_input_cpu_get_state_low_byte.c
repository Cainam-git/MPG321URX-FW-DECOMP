/* ipc_input_cpu_get_state_low_byte  (FUN_a0137754)
 *
 * Return the low byte of the input processor's state word.
 * Returns: byte
 * Name basis: descriptive - word at offset 0xC of mailbox portal 1; read by the main-loop task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0137754, flags -mcpu=v8 -O2 -g. ipc_mailbox_read is declared without a prototype, as the firmware's
 * own calls need. The byte is read at offset +3 of the 4-byte local (the low byte on this big-endian target).
 */
extern int ipc_mailbox_read();

#define IPC_PORTAL_INPUT_CPU  1     /* mailbox portal of the input processor */
#define STATE_WORD_OFFSET     0xc   /* word 3 of slot 0: the state word the input program publishes */

/*
 * Return the low byte of the state word: the port event flags in bits 0..5 and the DisplayPort transmitter status in
 * bits 6..7 (ipc_publish_port_status). Caller: sys_main_loop_periodic_task, which passes a changed value on with
 * ipc_set_status_byte_88dd.
 */
int ipc_input_cpu_get_state_low_byte(void)
{
    unsigned int state;
    
    state = 0;
    ipc_mailbox_read(IPC_PORTAL_INPUT_CPU, STATE_WORD_OFFSET, &state, 1);
    return *((unsigned char *)&state + 3);
}
