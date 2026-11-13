/* ipc_mailbox_read  (FUN_a002c4d0)
 *
 * Copy count words from mailbox portal 0 (8051), 1 (Leon2S) or 2 (Tensilica) into buf.
 *   portal: 0 = 8051, 1 = Leon2S, 2 = Tensilica
 *   offset: byte offset in the portal
 *   buf: destination
 *   count: number of words
 * Note: Unknown portal clears buf.
 * Name basis: proven - header: portal addresses 0x9F0A0100 / 0x9F130100 / 0xB7091000; >100 callers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002c4d0 @ 0xa002c4d0 (RAM copy, run-time address 0x4008c4d0), flags -mcpu=v8 -O3 -g.
 * Source form: one loop per portal, each with its own base address; the register read is the 32-bit read routine.
 */
extern unsigned int reg_read32(unsigned int addr);

/* Base addresses of the three mailbox portals (see docs/DATA.md, Mailboxes). */
#define MAILBOX_8051_BASE      0x9f0a0100u      /* portal 0: main processor and 8051 */
#define MAILBOX_LEON2S_BASE    0x9f130100u      /* portal 1: main processor and input processor */
#define MAILBOX_TENSILICA_BASE 0xb7091000u      /* portal 2: main processor and Tensilica program */

/*
 * Copy words out of a mailbox portal into a buffer.
 *   portal: 0 = 8051, 1 = input processor (leon2s), 2 = Tensilica program; for any other value buf is filled
 *           with zeros.
 *   offset: byte offset inside the portal; word i is read from base + offset + 4 * i.
 *   buf:    destination, count words.
 *   count:  number of 32-bit words.
 */
void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count)
{
    unsigned char i;

    switch (portal) {
    case 0:
        for (i = 0; i < count; i++)
            buf[i] = reg_read32(MAILBOX_8051_BASE + offset + i * 4);
        break;
    case 1:
        for (i = 0; i < count; i++)
            buf[i] = reg_read32(MAILBOX_LEON2S_BASE + offset + i * 4);
        break;
    case 2:
        for (i = 0; i < count; i++)
            buf[i] = reg_read32(MAILBOX_TENSILICA_BASE + offset + i * 4);
        break;
    default:
        for (i = 0; i < count; i++)
            buf[i] = 0;
        break;
    }
}
