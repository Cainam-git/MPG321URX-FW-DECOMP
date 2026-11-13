/* hdcp_tx_reg_update_bits  (FUN_a00c76c0)
 *
 * Set or clear bits of a register of an output's protection block.
 * Name basis: derived - block base table for outputs 0..2
 *
 * Matching notes
 * --------------
 * FUN_a00c76c0 (leon2s 0xa00c76c0-0xa00c7770, 176 bytes), flags -mcpu=v8 -Os -g.
 * Source forms: same address form as hdcp_tx_reg_read and hdcp_tx_reg_write (table and strings as symbols,
 * volatile only on the 0xcf... register); the address is computed again for the store.
 */
extern unsigned int hdcp_tx_reg_bases[];
extern int dbg_printf(const char *, ...);

#define HDCP_TX_OUTPUTS 3                       /* outputs 0..2: two HDMI, one DisplayPort */

/*
 * Set (set == 1) or clear (any other value) the bits of mask in register reg of the protection block of video
 * output `output` (0..2), with the register address of hdcp_tx_reg_write. For any other output number
 * nothing is changed and the firmware prints "!!!WRONG ACCESS - SC_SetBitHDCPTX(output, reg, mask, set)".
 */
void hdcp_tx_reg_update_bits(unsigned char output, unsigned short reg, unsigned char mask, unsigned char set)
{
    unsigned char value;

    if (output >= HDCP_TX_OUTPUTS) {
        dbg_printf("!!!WRONG ACCESS - %s(%02x, %02x, %02x, %02x)\r\n", "SC_SetBitHDCPTX", output, reg, mask, set);
        return;
    }
    value = *(volatile unsigned int *)(((hdcp_tx_reg_bases[output] + reg) << 2) | 0xcf000000);
    if (set == 1)
        value |= mask;
    else
        value &= ~mask;
    *(volatile unsigned int *)(((hdcp_tx_reg_bases[output] + reg) << 2) | 0xcf000000) = value;
}
