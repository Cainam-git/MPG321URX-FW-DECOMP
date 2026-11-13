/* hdcp_tx_reg_write  (FUN_a00c7654)
 *
 * Write a register of an output's protection block.
 * Name basis: derived - block base table for outputs 0..2; prints an error for another index
 *
 * Matching notes
 * --------------
 * FUN_a00c7654 (leon2s 0xa00c7654-0xa00c76c0, 27 words), flags -mcpu=v8 -Os -g.
 * Write twin of hdcp_tx_reg_read. Source forms: the table and the print strings are symbols (the hdcp_tx_reg_read
 * form), the value is an unsigned char, the return type is void; volatile only on the 0xcf... hardware register.
 * The 'sll idx,2' in the delay slot of the output-number test is the table offset of the other path.
 */
extern unsigned int hdcp_tx_reg_bases[];
extern int dbg_printf(const char *, ...);

#define HDCP_TX_OUTPUTS 3                       /* outputs 0..2: two HDMI, one DisplayPort */

/*
 * Write a byte to register reg of the protection block of video output `output` (0..2). The register is the
 * word at 0xCF000000 | ((hdcp_tx_reg_bases[output] + reg) << 2). For any other output number nothing is written
 * and the firmware prints "!!!WRONG ACCESS - SC_SetByteHDCPTX(output, reg, value)".
 */
void hdcp_tx_reg_write(unsigned char output, unsigned short reg, unsigned char value)
{
    if (output >= HDCP_TX_OUTPUTS) {
        dbg_printf("!!!WRONG ACCESS - %s(%02x, %02x, %02x)\r\n", "SC_SetByteHDCPTX", output, reg, value);
        return;
    }
    *(volatile unsigned int *)(((hdcp_tx_reg_bases[output] + reg) << 2) | 0xcf000000) = value;
}
