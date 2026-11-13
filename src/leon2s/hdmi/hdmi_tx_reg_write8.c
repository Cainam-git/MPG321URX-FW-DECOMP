/* hdmi_tx_reg_write8  (FUN_a00a8054)
 *
 * Write a byte register of a bank of an HDMI transmitter.
 *   port: HDMI TX port 0/1
 *   bank: bank 0..5
 *   reg: register
 *   value
 * Name basis: proven - block table 0xA00B4D44, 2 ports x 6 banks
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a8054 @ 0xa00a8054, flags -mcpu=v8 -Os -g.
 * The two range tests are kept as separate flag variables; the base table is a byte symbol indexed by byte
 * offset (index * 2).
 */
/* Base of the registers of each bank of each HDMI transmitter port: 16-bit entries, six banks per port
   (index port * 6 + bank). Bank 1 is the PHY, bank 2 the HDR dynamic metadata packet, bank 3 the VTEM packet. */
extern unsigned char hdmi_tx_reg_bases;

/* Write the low byte of value to register reg of a bank (0..5) of HDMI transmitter port 0 or 1 (address
   0xCF000000 | ((base + reg) * 4)). Any other port or bank writes nothing. */
void hdmi_tx_reg_write8(unsigned int port, unsigned int bank, unsigned short reg, unsigned int value)
{
    unsigned int index;
    unsigned int bad_port;
    unsigned int bad_bank;

    bad_port = (port & 0xff) > 1;
    index = (port & 0xff) * 6 + (bank & 0xff);
    bad_bank = (bank & 0xff) > 5;
    if (bad_port || bad_bank) {
        return;
    }
    *(volatile unsigned int *)((*(unsigned short *)(&hdmi_tx_reg_bases + index * 2) + (reg & 0xffff)) * 4 | 0xcf000000) = value & 0xff;
    return;
}
