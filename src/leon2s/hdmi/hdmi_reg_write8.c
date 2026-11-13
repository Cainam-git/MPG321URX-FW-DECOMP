/* hdmi_reg_write8  (FUN_a00a65c4)
 *
 * Write a byte register of one or both HDMI 2.0 receivers.
 *   receiver: receiver 0/1, 2 = both
 *   reg: register
 *   value
 * Name basis: proven - block table 0xA00B4D9C, port 2 = both; mailbox commands 0x13 / 0xF1
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a65c4 @ 0xa00a65c4, flags -mcpu=v8 -Os -g.
 * The base table must be declared as an array: the firmware indexes it with halfword loads. The receiver is
 * compared twice (> 2, then == 2 / < 2), as in the firmware.
 */
extern unsigned short hdmi_reg_bases[];

/* Write the low byte of value to register reg of HDMI 2.0 receiver 0 or 1; receiver 2 writes both receivers,
   receiver 0 first. Larger numbers write nothing. Register address = 0xCF000000 | ((base + reg) * 4). */
void hdmi_reg_write8(unsigned int receiver, unsigned short reg, unsigned int value)
{
    unsigned char i;

    receiver &= 0xff;
    if (receiver > 2)
        return;

    if (receiver == 2) {
        i = 0;
        do {
            *(volatile unsigned int *)(0xcf000000 |
                ((hdmi_reg_bases[i] + (unsigned short)reg) * 4)) = value & 0xff;
            i++;
        } while (i <= 1);
    } else if (receiver < 2) {
        *(volatile unsigned int *)(0xcf000000 |
            ((hdmi_reg_bases[receiver] + (unsigned short)reg) * 4)) = value & 0xff;
    }
}
