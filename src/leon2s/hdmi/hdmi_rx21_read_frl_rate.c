/* hdmi_rx21_read_frl_rate  (FUN_a00735e8)
 *
 * Return the FRL rate field (bits 24..27 of register word 0x90) of an HDMI 2.1 PHY; 0 for other PHYs.
 *   phy
 * Returns: FRL rate 0..15
 * Name basis: derived - bits 24..27 of word +0x90 of register block 6, the field hdmi_rx21_frl_rate_is_zero
 *   tests and hdmi_rx21_update_frl_rate prints as 'FRL_Rate'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00735e8 @ 0xa00735e8, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: the register-block pointer points to volatile data (the
 * firmware loads the full word with ld, then shifts; a plain pointer narrows it to ldub); the index is in
 * its own local 'i = port != 2'.
 */
/* Entry of hdmi_rx21_reg_blocks: register block bases of one receiver (0x34 bytes); block 6 is word 6. */
struct rx21_reg_blocks { unsigned char pad[0x18]; volatile unsigned int *block6; unsigned char rest[0x34 - 0x1c]; };
extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern unsigned char hdmi_is_hdmi21_phy(unsigned char);

/* For an HDMI 2.1 PHY (2 or 3) returns bits 24..27 of register 0x90 of its receiver's register block 6;
 * for any other PHY returns 0. hdmi_rx21_frl_rate_is_zero reads the same field.
 *   phy: PHY index */
unsigned int hdmi_rx21_read_frl_rate(unsigned char phy)
{
    unsigned int r = 0;

    if (hdmi_is_hdmi21_phy(phy) != 0) {
        unsigned int i = phy != 2;   /* receiver number: PHY 2 -> 0, PHY 3 -> 1 */
        r = (hdmi_rx21_reg_blocks[i].block6[0x24] >> 24) & 0xf;
    }
    return r;
}
