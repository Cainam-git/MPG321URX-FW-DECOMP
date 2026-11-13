/* ipc_mailbox_write  (FUN_a0072a4c)
 *
 * Write words to mailbox portal 0 or 1.
 *   portal
 *   offset: byte offset
 *   buf: words
 *   count
 * Name basis: proven - MailBox_Write of the input processor; portal 1 = 0x9F130100 read by the main processor
 *
 * Matching notes
 * --------------
 * FUN_a0072a4c (leon2s 0xa0072a4c), flags -mcpu=v8 -Os -g.
 * A switch on the portal (cases 0 and 1), not if / else if. The address is written 'offset + i * 4 + base'.
 */
extern void reg_write32_copy(unsigned int addr, unsigned int val);

#define MAILBOX_8051_BASE   0x9f0a0100  /* portal 0: main processor and 8051 */
#define MAILBOX_LEON2S_BASE 0x9f130100  /* portal 1: main processor and input processor */

/*
 * Write words to a mailbox portal. Any portal other than 0 or 1 writes nothing.
 *
 *   portal  0 or 1
 *   offset  byte offset inside the portal
 *   buf     the words to write
 *   count   number of words
 *
 * Its only caller is ipc_write_mailbox_slot (portal 1, offset = 16 * slot + 4 * word).
 */
void ipc_mailbox_write(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count)
{
    unsigned char i;

    switch (portal) {
    case 0:
        for (i = 0; i < count; i++)
            reg_write32_copy(offset + i * 4 + MAILBOX_8051_BASE, buf[i]);
        break;
    case 1:
        for (i = 0; i < count; i++)
            reg_write32_copy(offset + i * 4 + MAILBOX_LEON2S_BASE, buf[i]);
        break;
    }
}
