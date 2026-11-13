/* hdcp_tx_engine_reg_update_bits  (FUN_a00a7f1c)
 *
 * Set or clear masked bits of a byte register of a copy-protection engine unit.
 *   port: unit
 *   reg: register
 *   mask: bits
 *   mode: 1 = set
 * Name basis: derived - block table 0xA00B4D5C; callers hdcp_tx_engine_load_three_tables
 *
 * Matching notes
 * --------------
 * FUN_a00a7f1c (leon2s 0xa00a7f1c-0xa00a7fa0, 132 bytes), flags -mcpu=v8 -Os -g.
 * Read-modify-write of one 8-bit register of a hardware block: port = arg & 0xff, ports 0..3 only.
 * Address = ((u16 base table 0xa00b4d5c[port] + (u16)reg) * 4) | 0xcf000000. The word is read,
 * mode (arg4 & 0xff) == 1 sets the bits of mask, any other mode clears them (andn); the store
 * re-reads the table entry, recomputes the address and writes (v & 0xff).
 * Same code shape as dp_tx_phy_reg_update_bits (table 0xa00b4d6c, 2 ports). Source forms: the load address uses
 * ((u32)reg << 16) >> 16 and the store address (unsigned short)reg, which keeps two separate
 * truncations; the value is held in an unsigned char.
 */
extern unsigned char hdcp_tx_engine_reg_bases;

/*
 * Set (mode 1) or clear (any other mode) the bits of mask in register reg of copy-protection engine unit port.
 * Read-modify-write of the register at 0xCF000000 | ((base + reg) * 4), base from hdcp_tx_engine_reg_bases.
 * Only units 0..3 exist; for any other port nothing happens.
 */
void hdcp_tx_engine_reg_update_bits(unsigned int port, short reg, unsigned int mask, unsigned int mode)
{
    unsigned int addr;
    unsigned char value;

    if ((port & 0xff) < 4) {
        addr = reg;
        addr = ((*(unsigned short *)(&hdcp_tx_engine_reg_bases + (port & 0xff) * 2) + ((addr << 16) >> 16)) * 4) | 0xcf000000;
        value = *(unsigned int *)addr;
        if ((mode & 0xff) == 1)
            value |= mask;
        else
            value &= ~mask;
        *(unsigned int *)(((*(unsigned short *)(&hdcp_tx_engine_reg_bases + (port & 0xff) * 2) + (unsigned short)reg) * 4)
                          | 0xcf000000) = value & 0xff;
    }
}
