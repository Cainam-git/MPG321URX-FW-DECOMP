/* hdmi_set_descramble_auto_mode  (FUN_a007ed0c)
 *
 * Set or clear bit 1 of receiver register 0x2F6 (HDMI 2.1: bit 17 of block-3 word +0x74).
 *   phy
 *   on: 1 = set
 * Note: Not the bit hdmi_get_scramble_status reads (bit 2 / bit 18).
 * Name basis: derived - the caller sets the bit to 1 next to the print
 *   'HDMI_LINK_DESCRAMBLE_BIT_RATIO_AUTO_MODE ENABLE' and clears it where it forces the mode with
 *   hdmi_set_descramble_mode
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007ed0c @ 0xa007ed0c-0xa007ed88, flags -mcpu=v8 -Os -g.
 * Source forms: 'on' is a raw word parameter tested and passed as a byte (fw: separate 'and 0xff' for the call and
 * 'btst 0xff' for the test); the row index is a byte local (gives the smul).
 */
extern unsigned char hdmi_is_hdmi21_phy(unsigned char);
extern void hdmi_reg_update_bits(unsigned char, unsigned short, unsigned int, unsigned char);
extern void reg_set_bit(unsigned int, int);
extern void reg_clear_bit(unsigned int, int);
/* One row of hdmi_rx21_reg_blocks: the register block addresses of an HDMI 2.1 receiver (0x34 bytes, 13 words). */
struct hdmi_rx21_reg_blocks { unsigned int block0, block1, block2, block3; unsigned char rest[0x34 - 16]; };
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];

/*
 * Set or clear one bit of a PHY's receiver: bit 17 of the word at offset 0x74 of register block 3 on an HDMI 2.1
 * PHY (row 0 of hdmi_rx21_reg_blocks for PHY 2, row 1 for PHY 3), bit 1 of register 0x2F6 on an HDMI 2.0 PHY.
 *   phy: PHY index.  on: non-zero = set, 0 = clear.
 * Called by DRV_HDMI_EQScan_FSM_PHY_Init.
 */
void hdmi_set_descramble_auto_mode(unsigned char phy, unsigned int on)
{
    if (hdmi_is_hdmi21_phy(phy) != 0) {
        unsigned char row = phy != 2;
        if ((unsigned char)on != 0)
            reg_set_bit(0x11, ARR_a807db00[row].block3 + 0x74);
        else
            reg_clear_bit(0x11, ARR_a807db00[row].block3 + 0x74);
    } else {
        hdmi_reg_update_bits(phy, 0x2f6, 2, on);
    }
}
