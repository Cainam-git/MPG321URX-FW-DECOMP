/* ipc_mailbox_write  (FUN_a002c5f8)
 *
 * Copy count words from buf into mailbox portal 0 (8051), 1 (Leon2S) or 2 (Tensilica)
 *   portal: 0 = 8051, 1 = Leon2S, 2 = Tensilica
 *   offset: byte offset in the portal
 *   buf: source
 *   count: number of words
 * Note: Unknown portal writes nothing.
 * Name basis: proven - header: counterpart of the mailbox read
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002c5f8 @ 0xa002c5f8 (RAM copy, run-time address 0x4008c5f8), flags -mcpu=v8 -O3 -g.
 * Source form: one loop per portal, each with its own base address; the register write is the 32-bit write routine.
 */
extern void reg_write32(unsigned int addr, unsigned int value);

/* Base addresses of the three mailbox portals (see docs/DATA.md, Mailboxes). */
#define MAILBOX_8051_BASE      0x9f0a0100u      /* portal 0: main processor and 8051 */
#define MAILBOX_LEON2S_BASE    0x9f130100u      /* portal 1: main processor and input processor */
#define MAILBOX_TENSILICA_BASE 0xb7091000u      /* portal 2: main processor and Tensilica program */

/*
 * Copy words from a buffer into a mailbox portal (counterpart of ipc_mailbox_read).
 *   portal: 0 = 8051, 1 = input processor (leon2s), 2 = Tensilica program; for any other value nothing is
 *           written.
 *   offset: byte offset inside the portal; word i goes to base + offset + 4 * i.
 *   buf:    source, count words.
 *   count:  number of 32-bit words.
 */
void ipc_mailbox_write(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count)
{
    unsigned char i;

    switch (portal) {
    case 0:
        for (i = 0; i < count; i++)
            reg_write32(MAILBOX_8051_BASE + offset + i * 4, buf[i]);
        break;
    case 1:
        for (i = 0; i < count; i++)
            reg_write32(MAILBOX_LEON2S_BASE + offset + i * 4, buf[i]);
        break;
    case 2:
        for (i = 0; i < count; i++)
            reg_write32(MAILBOX_TENSILICA_BASE + offset + i * 4, buf[i]);
        break;
    }
}
