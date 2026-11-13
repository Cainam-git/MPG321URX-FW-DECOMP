/* ipc_8051_read_word_b4  (FUN_a01344cc)
 *
 * Read the word at offset 0xB4 of the 8051 mailbox.
 * Returns: word
 * Name basis: descriptive - mailbox portal 0; unused
 *
 * Matching notes
 * --------------
 * FUN_a01344cc, flags -mcpu=v8 -O2 -g. ipc_mailbox_read is declared without a prototype, as the firmware's own
 * calls need. The two parameters are declared and not used.
 */

extern int ipc_mailbox_read();

#define IPC_PORTAL_8051         0       /* mailbox portal between the main processor and the 8051 */
#define IPC_FLASH_WINDOW_BASE   0xb4    /* portal word 0xB4: the 8051 writes its flash window base here */

/*
 * Read portal word 0xB4 of the 8051 mailbox and return it. The word is the flash window base that the 8051 writes
 * (flash_update_fe2p_address, docs/MAILBOX.md). No call to this routine is found in the code.
 *   unused_1, unused_2: not used
 */
unsigned int ipc_8051_read_word_b4(unsigned int unused_1, unsigned int unused_2)

{
  unsigned int value;

  value = 0;
  ipc_mailbox_read(IPC_PORTAL_8051, IPC_FLASH_WINDOW_BASE, &value, 1);
  return (unsigned int)value;
}
