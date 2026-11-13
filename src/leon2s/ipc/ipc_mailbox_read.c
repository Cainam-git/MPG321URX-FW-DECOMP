/* ipc_mailbox_read  (FUN_a0072970)
 *
 * Read words from mailbox portal 0 or 1.
 *   portal
 *   offset: byte offset
 *   buf: words
 *   count
 * Name basis: proven - portal 0 = 0x9F0A0100, portal 1 = 0x9F130100; counterpart of the main processor's
 *   ipc_mailbox_read
 *
 * Matching notes
 * --------------
 * FUN_a0072970 (leon2s 0xa0072970, 220 bytes), flags -mcpu=v8 -Os -g.
 * A switch on the portal (an if/else chain gives a different test order).
 */
extern unsigned int reg_read32_copy(volatile unsigned int *param_1);

#define MAILBOX_8051_BASE   0x9f0a0100  /* portal 0: main processor and 8051 */
#define MAILBOX_LEON2S_BASE 0x9f130100  /* portal 1: main processor and input processor */

/*
 * Read words from a mailbox portal.
 *
 *   portal  0 or 1; any other value fills the buffer with zeros
 *   offset  byte offset inside the portal
 *   buf     receives the words
 *   count   number of words
 */
void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count)
{
    unsigned char i;

    switch (portal) {
    case 0:
        for (i = 0; i < count; i++)
            buf[i] = reg_read32_copy((volatile unsigned int *)(MAILBOX_8051_BASE + offset + i * 4));
        break;
    case 1:
        for (i = 0; i < count; i++)
            buf[i] = reg_read32_copy((volatile unsigned int *)(MAILBOX_LEON2S_BASE + offset + i * 4));
        break;
    default:
        for (i = 0; i < count; i++)
            buf[i] = 0;
        break;
    }
}
