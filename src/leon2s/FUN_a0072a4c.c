/* leon2s FUN_a0072a4c @ 0xa0072a4c  MailBox_Write(portal, offset, buf, count) of the Small chip (hand;
 * BYTE-EXACT at -Os).
 *
 * Writes <count> 32-bit words from buf to a mailbox portal through FUN_a00618cc(addr, value) (32-bit register write):
 * portal 0 = 0x9F0A0100 + offset + 4*i, portal 1 = 0x9F130100 + offset + 4*i; any other portal: nothing.
 * Counterpart of the Big chip's MailBox_Read FUN_a002c4d0 (portal 1 = 0x9F130100 there too). Only caller:
 * FUN_a006fad4 (portal 1, offset = 16 * slot + 4 * word), which publishes the port descriptors (FUN_a00700cc /
 * FUN_a006fbac) to the Big chip.
 * BYTE-EXACT key: a switch on portal (cases 0, 1), not if/else-if.
 */
extern void FUN_a00618cc(unsigned int addr, unsigned int val);

void FUN_a0072a4c(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count)
{
    unsigned char i;

    switch (portal) {
    case 0:
        for (i = 0; i < count; i++)
            FUN_a00618cc(offset + i * 4 + 0x9f0a0100, buf[i]);
        break;
    case 1:
        for (i = 0; i < count; i++)
            FUN_a00618cc(offset + i * 4 + 0x9f130100, buf[i]);
        break;
    }
}
