/* leon2m FUN_a002c4d0 @ 0xa002c4d0 (RAM copy, run-time address func_0x0008c4d0 / 0x4008c4d0)
 * MailBox_Read(portal, offset, buf, count): copy <count> 32-bit words from a mailbox portal into buf.
 *   portal 0 = 0x9F0A0100 (helper chip / 8051 STBC), 1 = 0x9F130100 (Small chip), 2 = 0xB7091000 (Tensilica);
 *   any other portal: buf is cleared. Word i is read from base + offset + 4*i through the 32-bit register
 *   read FUN_a002c250 (ld [addr]). Portal names: reference docs (mpg-341cqpx glossary.md), addresses: this code.
 * Callers: >100, e.g. the main-loop task FUN_a01387a4 (ulMailBoxData dump) and FUN_a002f388.
 */
extern unsigned int FUN_a002c250(unsigned int addr);

void FUN_a002c4d0(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count)
{
    unsigned char i;

    switch (portal) {
    case 0:
        for (i = 0; i < count; i++)
            buf[i] = FUN_a002c250(0x9f0a0100 + offset + i * 4);
        break;
    case 1:
        for (i = 0; i < count; i++)
            buf[i] = FUN_a002c250(0x9f130100 + offset + i * 4);
        break;
    case 2:
        for (i = 0; i < count; i++)
            buf[i] = FUN_a002c250(0xb7091000 + offset + i * 4);
        break;
    default:
        for (i = 0; i < count; i++)
            buf[i] = 0;
        break;
    }
}
