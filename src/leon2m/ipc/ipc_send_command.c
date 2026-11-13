/* ipc_send_command  (FUN_a01370dc)
 *
 * Send a checksummed command with up to 28 data bytes to the input processor.
 * Name basis: proven - eight-word frame at offset 0x80 of mailbox portal 1; optional wait until the command
 *   slot reads empty again
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01370dc @ 0xa01370dc-0xa013730c (560 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the message is reached through a pointer (msg = message) for the
 * mailbox calls, the checksum loop and the checksum store, while the tests and the packing use message[]
 * directly; the checksum loop compares with a limit variable word_count = 8 (cmp 8; bcs); tries = 100 is set
 * before msg.
 */
extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void ipc_mailbox_write(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void timer_sleep_ticks(unsigned short);
extern void irq_raise_software_irq_bit0(void);

#define IPC_PORTAL_INPUT_CPU  1         /* mailbox portal of the input processor */
#define IPC_COMMAND_SLOT      0x80      /* the command slot (slot 8); word 0 is 0 when free */
#define IPC_WAIT_TRIES        100
#define IPC_COMMAND_BYTES     0x1c      /* most data bytes of one command (words 1..7) */
#define IPC_HEADER_BYTES      4         /* the length field counts word 0 as well */
#define IPC_MESSAGE_MARKER    0x55      /* low byte of word 0 of every mailbox message */
#define IPC_COMMAND_WORDS     8

/*
 * Send command number command with length data bytes to the input processor, through the command slot of
 * mailbox portal 1 (offset 0x80, eight words).
 *
 *   command  the command number (docs/MAILBOX.md), placed in bits 8..15 of word 0
 *   length   number of data bytes; more than 28 are cut to 28
 *   data     the data bytes
 *   wait     0 (IPC_SEND_NO_WAIT): return after the write; non-zero: wait until the input program has carried
 *            the command out
 *
 * Word 0 of the slot is the header: the checksum in bits 24..31, length + 4 in bits 16..23, the command number in
 * bits 8..15 and the marker 0x55 in bits 0..7. Data byte k goes into word 1 + k / 4 at bits 8 * (k % 4). The
 * checksum makes the XOR of all 32 bytes of the message 0; ipc_verify_message on the input side checks the
 * marker and that XOR. The input program clears word 0 when it has carried the command out (after its reply, if
 * the command has one).
 *
 * Both waits, for the slot to be free before the write and (with wait set) for word 0 to clear after it, give up
 * after 100 reads with a one-tick sleep between them; the message is written even when the slot is still busy.
 * After the write, software interrupt bit 0 is raised (irq_raise_software_irq_bit0).
 *
 * Called by the small wrappers of the single commands (ipc_set_*, ipc_get_*), by the output record routines
 * (sys_output_record_*, sys_report_output_timing) and by ipc_ack_port_change_bits.
 */
void ipc_send_command(unsigned int command, unsigned char length, unsigned char *data, unsigned char wait)
{
    unsigned int message[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    unsigned char k = 0, i, tries, word_count, whole_words, rest;
    unsigned int *msg;
    unsigned int checksum, word;

    tries = IPC_WAIT_TRIES;
    msg = message;
    /* Wait for the input program to free the slot. */
    do {
        ipc_mailbox_read(IPC_PORTAL_INPUT_CPU, IPC_COMMAND_SLOT, msg, 1);
        if (message[0] == 0)
            break;
        timer_sleep_ticks(1);
    } while (--tries);
    if (length > IPC_COMMAND_BYTES)
        length = IPC_COMMAND_BYTES;
    whole_words = length / 4;
    rest = length % 4;
    for (i = 0; i < whole_words; i++) {
        message[i + 1] = data[k] | (data[k + 1] << 8) | (data[k + 2] << 16) | (data[k + 3] << 24);
        k += 4;
    }
    if (rest != 0) {
        for (i = 0; i < rest; i++)
            message[(length >> 2) + 1] |= data[k + i] << (i * 8);
    }
    message[0] = ((command << 8) | ((unsigned char)(length + IPC_HEADER_BYTES) << 16) | IPC_MESSAGE_MARKER) & 0xffffff;
    /* XOR of all bytes; stored in the top byte of word 0 it makes the XOR of the whole message 0. */
    checksum = 0;
    word_count = IPC_COMMAND_WORDS;
    for (i = 0; i < word_count; i++) {
        word = msg[i];
        checksum = word ^ checksum ^ (word >> 8) ^ (word >> 16) ^ (word >> 24);
    }
    msg[0] |= checksum << 24;
    ipc_mailbox_write(IPC_PORTAL_INPUT_CPU, IPC_COMMAND_SLOT, msg, IPC_COMMAND_WORDS);
    irq_raise_software_irq_bit0();
    tries = IPC_WAIT_TRIES;
    /* Wait for the input program to clear word 0: the command has been carried out. */
    while (wait) {
        ipc_mailbox_read(IPC_PORTAL_INPUT_CPU, IPC_COMMAND_SLOT, msg, 1);
        if (message[0] == 0)
            break;
        timer_sleep_ticks(1);
        if (--tries == 0)
            break;
    }
}
