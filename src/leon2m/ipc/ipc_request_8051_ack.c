/* ipc_request_8051_ack  (FUN_a002f388)
 *
 * Write 1 to 8051 mailbox word 0xB8 and wait until the 8051 answers 2.
 *   param_1: returned unchanged
 * Returns: param_1
 * Note: Waits without limit.
 * Name basis: descriptive - code: mailbox portal 0 offset 0xB8 handshake
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002f388 @ 0xa002f388, flags -mcpu=v8 -O3 -g.
 * Source form: the two mailbox routines are declared without parameter lists and get the word's address as an
 * int; the second parameter is not used.
 */
extern void ipc_mailbox_read();
extern int ipc_mailbox_write();

#define IPC_PORTAL_8051          0      /* mailbox portal between the main processor and the 8051 */
#define IPC_HANDSHAKE_OFFSET     0xb8   /* portal word 0xB8: low byte is the flash job handshake */
#define IPC_HANDSHAKE_REQUEST    1      /* written by the main processor */
#define IPC_HANDSHAKE_DONE       2      /* written by the 8051 (ipc_finish_flash_handshake) */

/*
 * The flash job handshake of the 8051 mailbox on its own (docs/MAILBOX.md, commands to the 8051): set the low
 * byte of portal word 0xB8 to 1, keeping the other three bytes, then read the word again until its low byte is 2.
 * There is no time limit. ipc_send_8051_command does the same handshake in its mode 2.
 *
 *   value   returned unchanged
 *   unused  not used
 *
 * No direct call to this routine was found in FW.021.
 */
unsigned int ipc_request_8051_ack(unsigned int value, unsigned int unused)

{
  unsigned int handshake_word;

  handshake_word = 0;
  ipc_mailbox_read(IPC_PORTAL_8051, IPC_HANDSHAKE_OFFSET, (int)&handshake_word, 1);
  handshake_word = handshake_word & 0xffffff00 | IPC_HANDSHAKE_REQUEST;
  ipc_mailbox_write(IPC_PORTAL_8051, IPC_HANDSHAKE_OFFSET, (int)&handshake_word, 1);
  do {
    ipc_mailbox_read(IPC_PORTAL_8051, IPC_HANDSHAKE_OFFSET, (int)&handshake_word, 1);
  } while ((unsigned char)handshake_word != IPC_HANDSHAKE_DONE);
  return value;
}
