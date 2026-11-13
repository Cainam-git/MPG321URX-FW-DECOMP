/* ipc_step_poll_slot  (FUN_CODE_ddf4)
 *
 * Advance the mailbox poll slot counter through 0..3.
 * Name basis: descriptive - counter 0xA3E2; only caller the mailbox service ipc_service_mailbox
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_ddf4 @ 0xddf4
 * Byte-exact with OPTIMIZE(8,SPEED) (also level 7).
 */
#define IPC_SLOT_COUNT 4   /* mailbox slots towards the main processor */

extern unsigned char xdata ipc_tx_slot_index;

/* Move ipc_tx_slot_index on by one, back to 0 after the last slot (3).
 * Only caller: ipc_service_mailbox (ipc_service_mailbox). */
void ipc_step_poll_slot(void)
{
    ipc_tx_slot_index++;
    if (ipc_tx_slot_index >= IPC_SLOT_COUNT) ipc_tx_slot_index = 0;
}
