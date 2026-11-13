/* ipc_set_hdr_option_byte  (FUN_a0138f2c)
 *
 * Ask the input processor to store an HDR option byte.
 * Name basis: derived - command 0xA3 through the mailbox portal 1 sender; unused; mailbox command 0xA3, whose
 *   handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0138f2c @ 0xa0138f2c-0xa0138fb8 (35 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * The message is an initialised 4-byte array; the four bits are ored into byte 0 after the clear (the byte is
 * read back from the stack).
 */
extern void ipc_send_command(int, int, unsigned char *, int);

#define IPC_CMD_SET_HDR_OPTION_BYTE 0xa3        /* mailbox command 0xA3 */
#define IPC_SEND_NO_WAIT            0           /* do not wait for the reply slot */

/*
 * Send mailbox command 0xA3 to the input processor. Bits 0 to 3 of the option byte are set when option_0 to
 * option_3 equal 1; the other bits and bytes of the message are 0.
 * The routine has no direct caller; it is reached through a table.
 */
void ipc_set_hdr_option_byte(unsigned char option_0, unsigned char option_1, unsigned char option_2, unsigned char option_3)
{
    unsigned char msg[4] = {0};

    msg[0] |= option_0 == 1;
    msg[0] |= (option_1 == 1) << 1;
    msg[0] |= (option_2 == 1) << 2;
    msg[0] |= (option_3 == 1) << 3;
    ipc_send_command(IPC_CMD_SET_HDR_OPTION_BYTE, 4, msg, IPC_SEND_NO_WAIT);
}
