/* hdmi_rx21_reg_update_bits  (FUN_a00a6aa0)
 *
 * Set or clear masked bits of a byte register of one or both HDMI 2.1 receivers.
 *   receiver: receiver, 2 = both
 *   reg: register
 *   mask: bits
 *   mode: 1 = set
 * Name basis: derived - read-modify-write; block table 0xA00B4D98; port 2 = both
 *
 * Matching notes
 * --------------
 * FUN_a00a6aa0 @ 0xa00a6aa0-0xa00a6bb8, flags -mcpu=v8 -Os -g.
 * Source form: the value read and the result are unsigned char locals; the two arms repeat the same step.
 */
extern unsigned short hdmi_rx21_reg_bases[];

#define REG(index) (*(volatile unsigned int *)(0xcf000000 | ((index) * 4)))

/* Set (mode 1) or clear (any other mode) the bits of mask in the low byte of register reg of HDMI 2.1 receiver
   0 or 1; receiver 2 does both receivers, receiver 0 first. Larger numbers change nothing. The register
   is read, changed and written back. */
void hdmi_rx21_reg_update_bits(unsigned char receiver, unsigned short reg, unsigned char mask, unsigned char mode)
{
    unsigned char i;
    unsigned char value;
    unsigned char result;

    if (receiver > 2)
        return;
    if (receiver == 2) {
        i = 0;
        do {
            value = REG(hdmi_rx21_reg_bases[i] + reg);
            if (mode == 1)
                result = value | mask;
            else
                result = value & ~mask;
            REG(hdmi_rx21_reg_bases[i] + reg) = result;
            i++;
        } while (i <= 1);
    } else if (receiver < 2) {
        value = REG(hdmi_rx21_reg_bases[receiver] + reg);
        if (mode == 1)
            result = value | mask;
        else
            result = value & ~mask;
        REG(hdmi_rx21_reg_bases[receiver] + reg) = result;
    }
}
