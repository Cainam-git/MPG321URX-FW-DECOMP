/* ipc_send_8051_command  (FUN_a002f3f4)
 *
 * Send command cmd with three argument bytes to the 8051 through mailbox portal 0.
 *   cmd: 8051 command number
 *   a1: argument 1
 *   a2: argument 2
 *   a3: argument 3
 *   mode: 0 no wait, handshake, wait until taken, 3 = stop here after sending
 * Note: Waits up to 100 polls for the previous command to be taken; mode 3 sends regardless.
 * Name basis: proven - header; docs/MAP.md update path (commands 7 and 0x29 to the 8051)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002f3f4 @ 0xa002f3f4..0xa002f550 (348 bytes, RAM copy: CPU 0x4008f3f4), flags -mcpu=v8 -O3 -g.
 * Source form: two nested blocks with their own locals (command_word, handshake_word); mode 3 ends in an empty
 * endless loop.
 */
extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void ipc_mailbox_write(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);

#define IPC_PORTAL_8051          0      /* mailbox portal between the main processor and the 8051 */
#define IPC_COMMAND_WORD_OFFSET  0x00   /* portal word 0: the command; the 8051 clears it when it has taken it */
#define IPC_HANDSHAKE_OFFSET     0xb8   /* portal word 0xB8: low byte is the flash job handshake */
#define IPC_HANDSHAKE_REQUEST    1      /* written by the main processor */
#define IPC_HANDSHAKE_DONE       2      /* written by the 8051 when the job is finished */
#define IPC_SEND_TRIES           100    /* reads of the command word while waiting for the 8051 to take the last one */

/* Values of the mode argument (see docs/MAILBOX.md). */
#define IPC_SEND_NO_WAIT          0     /* send and return at once */
#define IPC_SEND_WAIT_TAKEN       1     /* send, then wait until the 8051 has cleared the command word */
#define IPC_SEND_FLASH_HANDSHAKE  2     /* flash jobs: handshake on word 0xB8, then wait as in mode 1 */
#define IPC_SEND_NEVER_RETURNS    3     /* send, then loop forever (commands 0x16 and 0x17, which are not acknowledged) */

/*
 * Send one command to the 8051 through mailbox portal 0 (the mailbox commands are listed in docs/MAILBOX.md).
 *   cmd:  command number, goes into bits 0..7 of the command word
 *   a1:   byte 1 of the command word (bits 8..15)
 *   a2:   byte 2 (bits 16..23)
 *   a3:   byte 3 (bits 24..31)
 *   mode: IPC_SEND_* value that says how long to wait.
 * First the command word is read up to IPC_SEND_TRIES times until it is 0. If it never becomes 0 the command is not
 * sent, except in mode IPC_SEND_NEVER_RETURNS. The waits in modes 1 and 2 have no time limit, so a missing 8051
 * keeps the caller here for good.
 */
void ipc_send_8051_command(unsigned char cmd, unsigned char a1, unsigned char a2, unsigned char a3, unsigned char mode)
{
    unsigned int command_word = 0;
    unsigned char tries = IPC_SEND_TRIES;
    do {
        ipc_mailbox_read(IPC_PORTAL_8051, IPC_COMMAND_WORD_OFFSET, &command_word, 1);
        tries--;
        if (tries == 0)
            break;
    } while (command_word != 0);
    if (tries != 0 || mode == IPC_SEND_NEVER_RETURNS) {
        command_word = (a3 << 24) + (a2 << 16) + (a1 << 8) + cmd;
        ipc_mailbox_write(IPC_PORTAL_8051, IPC_COMMAND_WORD_OFFSET, &command_word, 1);
        if (mode == IPC_SEND_NEVER_RETURNS)
            for (;;)
                ;
        if (mode == IPC_SEND_FLASH_HANDSHAKE) {
            unsigned int handshake_word = 0;
            ipc_mailbox_read(IPC_PORTAL_8051, IPC_HANDSHAKE_OFFSET, &handshake_word, 1);
            handshake_word = (handshake_word & ~0xffu) | IPC_HANDSHAKE_REQUEST;
            ipc_mailbox_write(IPC_PORTAL_8051, IPC_HANDSHAKE_OFFSET, &handshake_word, 1);
            do
                ipc_mailbox_read(IPC_PORTAL_8051, IPC_HANDSHAKE_OFFSET, &handshake_word, 1);
            while ((unsigned char)handshake_word != IPC_HANDSHAKE_DONE);
        }
        if ((unsigned char)(mode - 1) < 2) {
            do
                ipc_mailbox_read(IPC_PORTAL_8051, IPC_COMMAND_WORD_OFFSET, &command_word, 1);
            while (command_word != 0);
        }
    }
}
