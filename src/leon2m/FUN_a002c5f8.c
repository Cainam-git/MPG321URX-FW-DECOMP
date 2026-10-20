/* leon2m FUN_a002c5f8 @ 0xa002c5f8 (RAM copy, run-time address func_0x0008c5f8 / 0x4008c5f8)
 * MailBox_Write(portal, offset, buf, count): copy <count> 32-bit words from buf into a mailbox portal.
 *   portal 0 = 0x9F0A0100 (helper chip / 8051 STBC), 1 = 0x9F130100 (Small chip), 2 = 0xB7091000 (Tensilica);
 *   any other portal: nothing is written. Word i goes to base + offset + 4*i through the 32-bit register
 *   write FUN_a002c25c(addr, value). Counterpart of MailBox_Read FUN_a002c4d0. Portal names: reference docs
 *   (mpg-341cqpx glossary.md), addresses: this code.
 */
extern void FUN_a002c25c(unsigned int addr, unsigned int value);

void FUN_a002c5f8(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count)
{
    unsigned char i;

    switch (portal) {
    case 0:
        for (i = 0; i < count; i++)
            FUN_a002c25c(0x9f0a0100 + offset + i * 4, buf[i]);
        break;
    case 1:
        for (i = 0; i < count; i++)
            FUN_a002c25c(0x9f130100 + offset + i * 4, buf[i]);
        break;
    case 2:
        for (i = 0; i < count; i++)
            FUN_a002c25c(0xb7091000 + offset + i * 4, buf[i]);
        break;
    }
}
