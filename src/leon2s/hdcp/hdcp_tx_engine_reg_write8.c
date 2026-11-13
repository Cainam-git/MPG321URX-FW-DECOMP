/* hdcp_tx_engine_reg_write8  (FUN_a00a7ee0)
 *
 * Write a byte register of a copy-protection engine unit.
 *   port: unit 0..3
 *   reg: register
 *   value
 * Name basis: derived - block table 0xA00B4D5C (0x4100..0x4130, 4 units); callers hdcp_tx_engine_*
 *
 * Matching notes
 * --------------
 * FUN_a00a7ee0 (leon2s 0xa00a7ee0-0xa00a7f1c, 60 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Register write helper without a port check: writes (v & 0xff) to the word at
 * 0xcf000000 | ((base[port] + reg) * 4), base = the 16-bit table at 0xa00b4d5c (same table as hdcp_tx_engine_reg_update_bits).
 * Callers in 0xa00c0000-0xa00df000 reach it through calls linked 0xF10000 above this address (func_0xa0fb7ee0 in
 * their sources). The store is volatile (hardware register); a plain store would be moved into the retl delay slot.
 */
extern unsigned char hdcp_tx_engine_reg_bases;

/*
 * Write one byte to register reg of copy-protection engine unit port (0..3). The unit's base is read from
 * hdcp_tx_engine_reg_bases; the register lives at 0xCF000000 | ((base + reg) * 4), one word per register.
 * Unlike hdcp_tx_engine_reg_update_bits this does not check port.
 */
void hdcp_tx_engine_reg_write8(unsigned int port, unsigned short reg, unsigned int value)
{
    *(volatile unsigned int *)(((*(unsigned short *)(&hdcp_tx_engine_reg_bases + (port & 0xff) * 2) + reg) * 4)
            | 0xcf000000) = value & 0xff;
}
