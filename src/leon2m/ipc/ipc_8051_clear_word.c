/* ipc_8051_clear_word  (FUN_a013480c)
 *
 * Write a zero word to an offset of the 8051 mailbox.
 * Name basis: derived - one word to mailbox portal 0; unused
 *
 * Matching notes
 * --------------
 * FUN_a013480c, flags -mcpu=v8 -O2 -g. ipc_mailbox_write is declared without a prototype, as the firmware's own
 * calls need.
 */
extern int ipc_mailbox_write();

#define IPC_PORTAL_8051  0  /* mailbox portal between the main processor and the 8051 */

/* Write the value 0 into the word at the given offset of the 8051 mailbox portal. No call to this routine is found in the code.
     offset: byte offset of the portal word */
void ipc_8051_clear_word(unsigned char offset)
{
    unsigned int zero;
    zero = 0;
    ipc_mailbox_write(IPC_PORTAL_8051, offset, &zero, 1);
}
