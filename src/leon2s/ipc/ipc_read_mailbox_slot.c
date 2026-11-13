/* ipc_read_mailbox_slot  (FUN_a006faa8)
 *
 * Read words from a mailbox slot shared with the main processor.
 *   slot
 *   word
 *   buffer
 *   count: word count
 * Name basis: proven - portal 1 address (slot * 4 + word) * 4, forwards to ipc_mailbox_read; pair of
 *   ipc_write_mailbox_slot
 *
 * Matching notes
 * --------------
 * FUN_a006faa8 (leon2s 0xa006faa8), flags -mcpu=v8 -Os -g.
 * Source form: the arguments are not declared with their narrow types; the '& 0xff' and '& 0xfc' masks are in
 * the expression.
 */
extern int ipc_mailbox_read();

#define IPC_PORTAL_INPUT_CPU 1          /* mailbox portal between the main processor and the input processor */

/*
 * Read words from a slot of the input-processor mailbox (portal 1).
 *
 *   slot    slot number; a slot is 4 words (16 bytes) long
 *   word    first word inside the slot
 *   buffer  receives the words
 *   count   number of words
 *
 * Byte offset in the portal = (slot * 4 + word) * 4, kept to 8 bits and to a multiple of 4 (& 0xfc).
 * Slot 0 holds the state words the input processor publishes, slot 8 the command, slot 10 the reply
 * (see docs/DATA.md and docs/MAILBOX.md).
 */
void ipc_read_mailbox_slot(unsigned int slot, int word, int buffer, unsigned int count)
{
  ipc_mailbox_read(IPC_PORTAL_INPUT_CPU, (word + (slot & 0xff) * 4) * 4 & 0xfc, buffer, count & 0xff);
}
