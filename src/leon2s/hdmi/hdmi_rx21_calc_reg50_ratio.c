/* hdmi_rx21_calc_reg50_ratio  (FUN_a009dfa8)
 *
 * Return the ratio of timing registers 0x50 and 0x54 of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: ratio, 0 when the divisor is 0
 * Name basis: descriptive - stored as halfword +0x12 of the mode info by hdmi_rx21_update_mode_info when its
 *   mode argument is 1; meaning of the value not visible
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009dfa8 @ 0xa009dfa8 (-mcpu=v8 -Os -g)
 * The index hdmi_rx21_reg_blocks[port * 13 + 8] gives the firmware's smul %o0, 0x34 followed by ld [%o5 + 0x20]; the divisor
 * test is a compare with 0 and a branch around the division.
 */
#define RX21_BLOCK_WORDS 13             /* words per receiver in the table of register block addresses */
#define BLOCK8_WORD      8              /* index of block 8 in that entry */
#define BLOCK8_REG_50    0x50           /* byte offsets in block 8 */
#define BLOCK8_REG_54    0x54

extern unsigned char hdmi_rx21_two_port_mode_flags[];     /* per receiver, set by FRL_PLL ('2PortMode') */
extern unsigned int hdmi_rx21_reg_blocks[];     /* table of register block addresses */

/*
 * Return the quotient of the register at block 8 + 0x50 and the register at block 8 + 0x54 shifted right by 2,
 * both shifted left by hdmi_rx21_two_port_mode_flags[port] first, as 16 bits. Returns 0 when the divisor is 0.
 *   port: HDMI 2.1 receiver 0/1
 * Called by hdmi_rx21_update_mode_info, which stores it in a mode info field when its mode argument is 1.
 */
unsigned short hdmi_rx21_calc_reg50_ratio(unsigned int port)
{
    unsigned int ratio;
    unsigned int divisor;
    unsigned int block8;
    unsigned char shift;
    
    port &= 0xff;
    block8 = hdmi_rx21_reg_blocks[port * RX21_BLOCK_WORDS + BLOCK8_WORD];
    shift = hdmi_rx21_two_port_mode_flags[port];
    divisor = (*(unsigned int *)(block8 + BLOCK8_REG_54) >> 2) << shift;
    ratio = 0;
    if (divisor != 0) {
        ratio = (*(unsigned int *)(block8 + BLOCK8_REG_50) << shift) / divisor;
    }
    return ratio & 0xffff;
}
