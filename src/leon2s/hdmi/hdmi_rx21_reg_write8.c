/* hdmi_rx21_reg_write8  (FUN_a00a69fc)
 *
 * Write a byte register of one or both HDMI 2.1 receivers.
 *   receiver: receiver 0/1, 2 = both
 *   reg: register
 *   value
 * Name basis: derived - block table 0xA00B4D98, port 2 = both; mailbox commands 0x13 / 0xF1, register 0x9C8 in
 *   the interrupt service
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a69fc @ 0xa00a69fc, flags -mcpu=v8 -Os -g.
 * The base table must be declared as an array: the firmware indexes it with halfword loads.
 */
extern unsigned short hdmi_rx21_reg_bases[];

/* Write the low byte of value to register reg of HDMI 2.1 receiver 0 or 1; receiver 2 writes both receivers,
   receiver 0 first. Larger numbers write nothing. */
void hdmi_rx21_reg_write8(unsigned int receiver, unsigned short reg, unsigned int value)
{
    unsigned char i;

    receiver &= 0xff;
    if (receiver > 2)
        return;

    if (receiver == 2) {
        i = 0;
        do {
            *(volatile unsigned int *)(0xcf000000 |
                ((hdmi_rx21_reg_bases[i] + (unsigned short)reg) * 4)) = value & 0xff;
            i++;
        } while (i <= 1);
    } else if (receiver < 2) {
        *(volatile unsigned int *)(0xcf000000 |
            ((hdmi_rx21_reg_bases[receiver] + (unsigned short)reg) * 4)) = value & 0xff;
    }
}
