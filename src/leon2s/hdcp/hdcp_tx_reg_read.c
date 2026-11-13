/* hdcp_tx_reg_read  (FUN_a00c7770)
 *
 * Read a register of an output's protection block.
 * Returns: value
 * Name basis: derived - block base table for outputs 0..2
 *
 * Matching notes
 * --------------
 * FUN_a00c7770 (leon2s 0xa00c7770-0xa00c77dc, 27 words), flags -mcpu=v8 -Os -g.
 * Source forms: the print strings and the table are symbol addresses (own sethi each; the table is an extern
 * unsigned int array, which gives the firmware's [base + idx*4] order); the print is variadic; the register is
 * volatile.
 */
extern unsigned int hdcp_tx_reg_bases[];
extern int dbg_printf(const char *, ...);

#define HDCP_TX_OUTPUTS 3                       /* outputs 0..2: two HDMI, one DisplayPort */

/*
 * Read the low byte of register reg of the protection block of video output `output` (0..2); the register is
 * the word at 0xCF000000 | ((hdcp_tx_reg_bases[output] + reg) << 2). For any other output number it
 * returns 0 and the firmware prints "!!!WRONG ACCESS - SC_GetByteHDCPTX(output, reg)".
 */
unsigned char hdcp_tx_reg_read(unsigned char output, unsigned short reg)
{
    if (output >= HDCP_TX_OUTPUTS) {
        dbg_printf("!!!WRONG ACCESS - %s(%02x, %02x)\r\n", "SC_GetByteHDCPTX", output, reg);
        return 0;
    }
    return *(volatile unsigned int *)(((hdcp_tx_reg_bases[output] + reg) << 2) | 0xcf000000);
}
