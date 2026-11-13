/* ipc_8051_get_status_byte2  (FUN_a013353c)
 *
 * Return the third byte of the 8051 status word.
 * Returns: byte
 * Name basis: descriptive - word at offset 0xC of mailbox portal 0; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013353c @ 0xa013353c, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the mailbox read is declared without a prototype and reads into a zero-initialised word; the
 * expression '(status_word >> 16) & 0xff' compiles to a byte load.
 */
extern int ipc_mailbox_read();

#define IPC_PORTAL_8051         0       /* mailbox portal between the main processor and the 8051 */
#define IPC_STATUS_WORD_OFFSET  0x0c    /* portal word 0x0C */

/*
 * Read portal word 0x0C of the 8051 mailbox and return its bits 16..23. Only the low byte of this word is
 * described in docs/MAILBOX.md. Nothing calls this routine.
 */
int ipc_8051_get_status_byte2(void)
{
    unsigned int status_word;

    status_word = 0;
    ipc_mailbox_read(IPC_PORTAL_8051, IPC_STATUS_WORD_OFFSET, &status_word, 1);
    return (status_word >> 16) & 0xff;
}
