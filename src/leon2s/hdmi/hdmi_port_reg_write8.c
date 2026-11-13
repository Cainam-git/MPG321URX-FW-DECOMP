/* hdmi_port_reg_write8  (FUN_a00a7dd0)
 *
 * Write a byte register of any HDMI receiver (ports 0..3, 2.0 and 2.1).
 *   port: HDMI port 0..3
 *   reg: register
 *   v: value
 * Name basis: proven - block table 0xA00B4D64 = 0x0000 / 0x0400 (HDMI 2.0) and 0x9000 / 0xA000 (HDMI 2.1);
 *   callers the HDCP receiver code
 *
 * Matching notes
 * --------------
 * FUN_a00a7dd0 (leon2s 0xa00a7dd0), flags -mcpu=v8 -Os -g.
 * Leaf. The base table is declared as a byte symbol and indexed by byte offset (port * 2) with an unsigned
 * short load. The callers in 0xa00c0000-0xa00df000 reach this routine through calls linked 0xF10000 above it.
 */
/* Base of the registers of each HDMI port 0..3, as 16-bit entries: 0x0000 / 0x0400 for the HDMI 2.0 receivers
   and 0x9000 / 0xA000 for the HDMI 2.1 receivers. */
extern unsigned char hdmi_port_reg_bases;

/* Write the low byte of v to register reg of HDMI port 0..3 (address 0xCF000000 | ((base + reg) * 4)). Larger
   port numbers write nothing. Called by the HDCP receiver code. */
void hdmi_port_reg_write8(unsigned int port, unsigned short reg, unsigned int v)
{
    if ((port & 0xff) < 4)
        *(volatile unsigned int *)(((*(unsigned short *)(&hdmi_port_reg_bases + (port & 0xff) * 2) + reg) * 4)
                | 0xcf000000) = v & 0xff;
}
