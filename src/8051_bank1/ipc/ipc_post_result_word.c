/* ipc_post_result_word  (FUN_CODE_dbdf)
 *
 * Post a 32-bit result word to the main chip's mailbox portal.
 *   result
 * Name basis: derived - portal word 0xB0; used after the flash read job and with the 0xA800 buffer sum
 *   (message type 7)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dbdf @ 0xdbdf
 * Options: OPTIMIZE(8,SPEED) LARGE.
 * The parameter is the LARGE parameter at XDATA 0xA4B3 (stored with ?C?LSTXDATA); n = 1 goes to ipc_portal_write's XDATA
 * parameter 0xA4BF; the call is a tail LJMP. ('x = result; ipc_portal_write(0xb0, &x, 1)' also matches.)
 */
#define IPC_PORTAL_RESULT_OFFSET 0xb0   /* portal offset of the result word */

void ipc_portal_write(unsigned char off, unsigned long *src, unsigned char n);

/* Write one 32-bit word to the mailbox portal at offset 0xB0.
 *   result: the word
 * Callers: ipc_run_message (jump at 0x21b3) and the case body at 0x244b. */
void ipc_post_result_word(unsigned long result)
{
    ipc_portal_write(IPC_PORTAL_RESULT_OFFSET, &result, 1);
}
