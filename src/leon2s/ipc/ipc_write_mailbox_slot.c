/* ipc_write_mailbox_slot  (FUN_a006fad4)
 *
 * Write words to a mailbox slot shared with the main processor.
 *   slot
 *   word
 *   buffer
 *   count: word count
 * Name basis: proven - forwards to ipc_mailbox_write (portal 1); the main processor reads these slots
 *
 * Matching notes
 * --------------
 * FUN_a006fad4 (leon2s 0xa006fad4), flags -mcpu=v8 -Os -g.
 * Source form: the arguments are not declared with their narrow types; the '& 0xff' and '& 0xfc' masks are in
 * the expression.
 */
extern int ipc_mailbox_write();

#define IPC_PORTAL_INPUT_CPU 1          /* mailbox portal between the main processor and the input processor */

/*
 * Write words to a slot of the input-processor mailbox (portal 1); the main processor reads them there.
 *
 *   slot    slot number; a slot is 4 words (16 bytes) long
 *   word    first word inside the slot
 *   buffer  the words to write
 *   count   number of words
 *
 * Byte offset in the portal = (slot * 4 + word) * 4, kept to 8 bits and to a multiple of 4 (& 0xfc).
 */
void ipc_write_mailbox_slot(unsigned int slot, int word, int buffer, unsigned int count)
{
  ipc_mailbox_write(IPC_PORTAL_INPUT_CPU, (word + (slot & 0xff) * 4) * 4 & 0xfc, buffer, count & 0xff);
}
