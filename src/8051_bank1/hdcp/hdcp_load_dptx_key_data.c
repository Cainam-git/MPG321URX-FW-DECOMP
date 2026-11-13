/* hdcp_load_dptx_key_data  (FUN_CODE_d171)
 *
 * Copy the 282-byte HDCP data block into the DP transmitter's key port.
 * Name basis: derived - only use is command 0x21, printed name 'CMD_WRITE_DPTXHDCP'; 0x11A bytes from 0x3E00
 *   to port byte 0xD5E3
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d171 @ 0xd171 (55 B)  Byte-exact with OPTIMIZE(7,SPEED).
 * Source form: the index is a 16-bit counter in R4:R5 ('i < 0x11a' compiles to the two CJNE tests on R4 and R5).
 */
extern unsigned char xdata reg_hdcp_dptx_key_ctrl, DAT_EXTMEM_d5e1, DAT_EXTMEM_d5e2, reg_hdcp_dptx_key_data, DAT_EXTMEM_bff3;
extern unsigned char xdata hdcp_dptx_key_block[];

/* Length of the HDCP data block (0x3E00..0x3F19). */
#define HDCP_DPTX_KEY_BLOCK_BYTES 0x11a

/*
 * Copy the 0x11A-byte block hdcp_dptx_key_block, one byte after another, to
 * the single data register reg_hdcp_dptx_key_data of the DP transmitter.
 * 0xD5E0 is saved, set to 0x22 for the copy and restored; 0xD5E1, 0xD5E2 and
 * 0xBFF3 are cleared first. Only caller: command 0x21 of the command switch
 * (its own text: "CMD_WRITE_DPTXHDCP").
 */
void hdcp_load_dptx_key_data(void)
{
    unsigned char saved_ctrl;
    unsigned int i;

    saved_ctrl = reg_hdcp_dptx_key_ctrl;
    reg_hdcp_dptx_key_ctrl = 0x22;
    DAT_EXTMEM_d5e1 = 0;
    DAT_EXTMEM_d5e2 = 0;
    DAT_EXTMEM_bff3 = 0;
    for (i = 0; i < HDCP_DPTX_KEY_BLOCK_BYTES; i++)
        reg_hdcp_dptx_key_data = hdcp_dptx_key_block[i];
    reg_hdcp_dptx_key_ctrl = saved_ctrl;
}
