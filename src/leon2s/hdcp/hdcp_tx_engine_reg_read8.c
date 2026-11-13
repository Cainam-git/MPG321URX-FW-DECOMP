/* hdcp_tx_engine_reg_read8  (FUN_a00a7fa0)
 *
 * Read a byte register of a copy-protection engine unit.
 *   port: unit 0..3
 *   reg: register
 * Returns: low byte of the register; port is not checked
 * Name basis: derived - block table 0xA00B4D5C; callers hdcp_tx_engine_exchange_tables
 *
 * Matching notes
 * --------------
 * FUN_a00a7fa0 (leon2s 0xa00a7fa0-0xa00a7fd8, 56 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Register read helper without a port check: returns the low byte of the word at
 * 0xcf000000 | ((base[port] + reg) * 4), base = the 16-bit table at 0xa00b4d5c. Callers in 0xa00c0000-0xa00df000
 * reach it through calls linked 0xF10000 above this address (func_0xa0fb7fa0 in their sources).
 */
extern unsigned char hdcp_tx_engine_reg_bases;

/*
 * Read register reg of copy-protection engine unit port (0..3) and return its low byte. The register address
 * is built as in hdcp_tx_engine_reg_write8. Unlike hdcp_tx_engine_reg_update_bits this does not check port.
 */
unsigned int hdcp_tx_engine_reg_read8(unsigned int port, unsigned short reg)
{
    return *(volatile unsigned int *)(((*(unsigned short *)(&hdcp_tx_engine_reg_bases + (port & 0xff) * 2) + reg) * 4)
            | 0xcf000000) & 0xff;
}
