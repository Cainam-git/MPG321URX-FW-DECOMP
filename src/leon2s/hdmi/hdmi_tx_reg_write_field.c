/* hdmi_tx_reg_write_field  (FUN_a00a8184)
 *
 * Replace the masked bits of an HDMI transmitter bank register with new bits.
 *   port: HDMI TX port
 *   bank
 *   reg: register
 *   mask
 *   new_bits: bits
 * Name basis: proven - block table 0xA00B4D44; (old & ~mask) | (bits & mask)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a8184 @ 0xa00a8184, flags -mcpu=v8 -Os -g.
 * Source forms: the function has the implicit int return type with plain 'return;' statements (the return
 * register counts as live, which gives the firmware's register allocation; no value is returned and callers do
 * not read one); the range test uses two flag variables; the merged value is computed first, as
 * 'merged = bits; merged &= mask' into an unsigned char.
 */
/* Base of the registers of each bank of each HDMI transmitter port: 16-bit entries, six banks per port
   (index port * 6 + bank). Bank 1 is the PHY, bank 2 the HDR dynamic metadata packet, bank 3 the VTEM packet. */
extern unsigned char hdmi_tx_reg_bases;

/* Replace the bits of mask in register reg of a bank (0..5) of HDMI transmitter port 0 or 1 by the same bits
   of new_bits: the register is set to (old value & ~mask) | (new_bits & mask) and its low byte written
   back. Any other port or bank changes nothing. */
hdmi_tx_reg_write_field(unsigned int port, unsigned int bank, unsigned short reg, unsigned char mask, unsigned int new_bits)
{
    unsigned int index;
    unsigned int bad_port;
    unsigned int bad_bank;
    unsigned char merged;
    volatile unsigned int *reg_addr;

    merged = new_bits;
    merged &= mask;
    bad_port = (port & 0xff) > 1;
    index = (port & 0xff) * 6 + (bank & 0xff);
    bad_bank = (bank & 0xff) > 5;
    if (bad_port || bad_bank)
        return;
    reg_addr = (volatile unsigned int *)((*(unsigned short *)(&hdmi_tx_reg_bases + index * 2) + (reg & 0xffff)) * 4 | 0xcf000000);
    *reg_addr = (unsigned char)(merged | (*reg_addr & ~mask));
    return;
}
