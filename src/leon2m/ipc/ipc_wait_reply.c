/* ipc_wait_reply  (FUN_a0137344)
 *
 * Wait for the input processor's reply to the last command.
 * Name basis: proven - prints 'wait reply cmd'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0137344 @ 0xa0137344-0xa0137644 (192 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - one loop for both wait values: the counter is decremented on every pass, the print and the counter test
 *    happen only for limited == 0; GCC unswitches the loop on limited, which gives the two loops of the firmware;
 *  - the counter is an unsigned int tested by its low byte;
 *  - the message check is a static helper returning unsigned char, inlined;
 *  - the reply is copied by two separate loops, one for command 0 and one for the other numbers.
 */
extern unsigned int ipc_reply_words[8];
extern unsigned char dbg_is_print_enabled(unsigned int level);
extern int dbg_printf(const char *fmt, ...);
extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void ipc_mailbox_write(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void timer_sleep_ticks(int ticks);

#define IPC_PORTAL_INPUT_CPU  1         /* mailbox portal of the input processor */
#define IPC_REPLY_SLOT        0xa0      /* the reply slot (slot 10); word 0 is 0 when empty */
#define IPC_REPLY_WORDS       8         /* header word + 7 data words */
#define IPC_WAIT_TRIES        100
#define IPC_MESSAGE_MARKER    0x55      /* low byte of word 0 of every mailbox message */
#define DBG_MAILBOX           0x20      /* debug class of the mailbox prints */

/* 1 when the message has the marker in the low byte of its header and the XOR of all its bytes is 0. */
static unsigned char message_is_valid(unsigned int header, unsigned int *words, unsigned char word_count)
{
    unsigned int checksum = 0;
    unsigned char i;

    if ((header & 0xff) != IPC_MESSAGE_MARKER)
        return 0;
    for (i = 0; i < word_count; i++)
        checksum = checksum ^ words[i] ^ (words[i] >> 8) ^ (words[i] >> 16) ^ (words[i] >> 24);
    return (unsigned char)checksum == 0;
}

/*
 * Wait for a reply in the reply slot of mailbox portal 1 (offset 0xA0, eight words, written by ipc_send_reply in
 * the input program), keep it in ipc_reply_words when it is valid and belongs to a command that answers, and
 * empty the slot.
 *
 *   limited  0: at most 100 reads, printing 'wait reply cmd' (debug class DBG_MAILBOX) after each empty read;
 *            non-zero: read until a reply is there, with no time limit
 *
 * Each empty read is followed by a one-tick sleep. After the wait the whole slot is read, whether or not a reply
 * came. A message without the marker 0x55 or with a bad checksum is left in the slot and the routine returns.
 * A valid message is copied to ipc_reply_words when its command number (bits 8..15 of word 0) is one of
 * 0x00, 0x22, 0x31, 0x45, 0x5C, 0x5D, 0x71, 0x79, 0x7C, 0x83, 0x87, 0xA0, 0xA1, 0xA4, 0xF3, 0xFD; for any other
 * number it is dropped. In both cases word 0 of the slot is then cleared, which lets the input program send its
 * next reply (ipc_send_reply waits for that word to read 0).
 *
 * Called by the routines that send a command with a reply and read the answer from ipc_reply_words.
 */
void ipc_wait_reply(unsigned char limited)
{
    unsigned int reply[8] = {0};
    unsigned int tries = IPC_WAIT_TRIES;
    unsigned int *words = reply;
    unsigned int zero;
    unsigned char i;
    unsigned int header;

    for (;;) {
        ipc_mailbox_read(IPC_PORTAL_INPUT_CPU, IPC_REPLY_SLOT, words, 1);
        if (reply[0] != 0)
            break;
        tries--;
        timer_sleep_ticks(1);
        if (limited == 0) {
            if (dbg_is_print_enabled(DBG_MAILBOX))
                dbg_printf("wait reply cmd\r\n");
            if ((unsigned char)tries == 0)
                break;
        }
    }
    ipc_mailbox_read(IPC_PORTAL_INPUT_CPU, IPC_REPLY_SLOT, words, IPC_REPLY_WORDS);
    header = reply[0];
    if (!message_is_valid(header, words, IPC_REPLY_WORDS))
        return;
    switch ((int)((header & 0xff00) >> 8)) {
    case 0:
        for (i = 0; i < IPC_REPLY_WORDS; i++)
            ipc_reply_words[i] = words[i];
        break;
    case 0x22: case 0x31: case 0x45: case 0x5c: case 0x5d: case 0x71: case 0x79: case 0x7c:
    case 0x83: case 0x87: case 0xa0: case 0xa1: case 0xa4: case 0xf3: case 0xfd:
        for (i = 0; i < IPC_REPLY_WORDS; i++)
            ipc_reply_words[i] = words[i];
        break;
    }
    zero = 0;
    ipc_mailbox_write(IPC_PORTAL_INPUT_CPU, IPC_REPLY_SLOT, &zero, 1);
}
