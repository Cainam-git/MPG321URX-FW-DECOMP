/* hdmi_port_reg_read8  (FUN_a00a7e98)
 *
 * Read a byte register of any HDMI receiver (ports 0..3).
 *   port: HDMI port 0..3
 *   reg: register
 * Returns: byte, 0 for an invalid unit
 * Name basis: proven - block table 0xA00B4D64, ports 0..3
 *
 * Matching notes
 * --------------
 * FUN_a00a7e98 (leon2s 0xa00a7e98), flags -mcpu=v8 -Os -g.
 * Leaf. The base table is declared as a byte symbol and indexed by byte offset (port * 2). The callers in
 * 0xa00c0000-0xa00df000 reach this routine through calls linked 0xF10000 above it.
 */
extern unsigned char hdmi_port_reg_bases;      /* 16-bit register bases of HDMI ports 0..3 */

/* Read the low byte of register reg of HDMI port 0..3 (address 0xCF000000 | ((base + reg) * 4)). Larger port
   numbers read 0. */
unsigned int hdmi_port_reg_read8(unsigned int port, unsigned short reg)
{
    unsigned int value = 0;

    if ((port & 0xff) < 4)
        value = *(volatile unsigned int *)(((*(unsigned short *)(&hdmi_port_reg_bases + (port & 0xff) * 2) + reg) * 4)
                | 0xcf000000) & 0xff;
    return value;
}
