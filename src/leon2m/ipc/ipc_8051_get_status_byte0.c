/* ipc_8051_get_status_byte0  (FUN_a01334ec)
 *
 * Return the low byte of the 8051 status word.
 * Returns: byte
 * Name basis: descriptive - word at offset 0xC of mailbox portal 0; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01334ec @ 0xa01334ec, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the decompiler's form is kept: two unused unsigned int parameters, the mailbox read declared without
 * a prototype, and the word cleared before it is read.
 */
// 0x4008c4d0
extern int ipc_mailbox_read();

#define IPC_PORTAL_8051         0       /* mailbox portal between the main processor and the 8051 */
#define IPC_STATUS_WORD_OFFSET  0x0c    /* portal word 0x0C */

/*
 * Read portal word 0x0C of the 8051 mailbox and return its low byte: the ports whose EDID/DDC was accessed
 * (docs/MAILBOX.md, MailBox_UpdateDDCFlag).
 *   unused0, unused1: not used.
 * Nothing calls this routine.
 */
unsigned int ipc_8051_get_status_byte0(unsigned int unused0, unsigned int unused1)
{
  unsigned int status_word;

  status_word = 0;
  ipc_mailbox_read(IPC_PORTAL_8051, IPC_STATUS_WORD_OFFSET, &status_word, 1);
  return (unsigned int)(unsigned char)status_word;
}
