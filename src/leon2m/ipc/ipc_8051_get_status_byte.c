/* ipc_8051_get_status_byte  (FUN_a0133cbc)
 *
 * Return byte n (0..3) of the 8051 status word, portal word 0x0C of the 8051 mailbox.
 *   byte_index: which byte of the word, 0 = lowest
 * Returns: the byte, (word >> (8 * n)) & 0xFF
 * Name basis: descriptive - word at offset 0xC of mailbox portal 0, shifted right by 8 * n and masked with
 *   0xFF; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0133cbc @ 0xa0133cbc, flags -mcpu=v8 -O3 -g.
 * Source form: the mailbox read is declared without a prototype and reads into a zero-initialised word. The
 * decompiler shows a second parameter; the assembly never reads it, so it is left out.
 */
extern void ipc_mailbox_read();

#define IPC_PORTAL_8051         0       /* mailbox portal between the main processor and the 8051 */
#define IPC_STATUS_WORD_OFFSET  0x0c    /* portal word 0x0C */

/*
 * Read portal word 0x0C of the 8051 mailbox and return one of its four bytes.
 *   byte_index: 0..3; the result is (word >> (8 * byte_index)) & 0xFF. Index 0 is the byte described in
 *               docs/MAILBOX.md (ports whose EDID/DDC was accessed).
 * Nothing calls this routine.
 */
int ipc_8051_get_status_byte(unsigned char byte_index)
{
    unsigned int status_word;

    status_word = 0;
    ipc_mailbox_read(IPC_PORTAL_8051, IPC_STATUS_WORD_OFFSET, &status_word, 1);
    return (status_word >> (byte_index << 3)) & 0xff;
}
