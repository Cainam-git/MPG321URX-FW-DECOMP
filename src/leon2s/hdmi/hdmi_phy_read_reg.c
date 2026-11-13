/* hdmi_phy_read_reg  (FUN_a00a7314)
 *
 * Read a paged register of an HDMI receiver PHY.
 *   phy: PHY 0..3
 *   reg: register
 * Returns: register word
 * Name basis: proven - saves and restores the page register; used by the EQ, PHY and lane frequency code
 *
 * Matching notes
 * --------------
 * FUN_a00a7314 (leon2s, 0xa00a7314), flags -mcpu=v8 -Os -g.
 * Leaf. Returns the full word (an 8-bit return type adds an 'and 0xff'). The hardware accesses are volatile.
 * Source form: the low byte of reg is its own variable (the firmware computes it before 'phy << 8').
 */
/*
 * Read register reg of PHY 0..3 (page register at 0xCF000000 | ((phy + 0xF401) << 2), words from
 * 0xCE008100 + (phy << 8)). The high byte of reg is the page and the low byte the word in the page: the old
 * page value is saved, the page is selected, the word is read, and the old page value is put back (low
 * byte only). Used by the equaliser, PHY and lane-frequency code.
 */
unsigned int hdmi_phy_read_reg(unsigned int phy, unsigned short reg)
{
    unsigned int page_index = (phy & 0xff) + 0xf401;
    volatile unsigned int *page_reg = (volatile unsigned int *)((page_index << 2) | 0xcf000000);
    unsigned int old_page = *page_reg;
    unsigned int word = reg & 0xff;
    unsigned int word_addr = 0xce008100 + ((phy & 0xff) << 8) + word;
    unsigned int result;

    *page_reg = (reg >> 8) & 0xff;
    result = *(volatile unsigned int *)word_addr;
    *page_reg = old_page & 0xff;
    return result;
}
