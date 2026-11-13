/* hdmi_phy_write_reg  (FUN_a00a72c0)
 *
 * Write a paged register of an HDMI receiver PHY.
 *   ch: PHY 0..3
 *   reg: register
 *   val: value
 * Name basis: proven - page register 0xCF000000 | ((PHY + 0xF401) << 2) = reg >> 8, data 0xCE008100 + (PHY <<
 *   8) + low byte
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a72c0 @ 0xa00a72c0, flags -mcpu=v8 -Os -g.
 * Leaf. Source forms: volatile only on the 0xcf... / 0xce... hardware accesses; the low byte of the register
 * is its own local (it keeps the firmware's and-before-shift order); the old page value is kept in a local.
 */
/* Paged register access of the HDMI receiver PHYs: the page register of PHY ch is at
   0xCF000000 | ((ch + 0xF401) << 2), and the registers of the selected page are the words from
   0xCE008100 + (ch << 8). */
/*
 * Write val to register reg of PHY ch (0..3). The high byte of reg is the page and the low byte the word in
 * the page: the old page value is saved, the page is selected, the word is written, and the old page value
 * is put back (low byte only).
 */
void hdmi_phy_write_reg(unsigned char ch, unsigned int reg, unsigned int val)
{
  volatile unsigned int *page_reg = (volatile unsigned int *)(((ch + 0xf401) << 2) | 0xcf000000);
  unsigned int old_page = *page_reg;

  *page_reg = (unsigned short)reg >> 8;
  { unsigned int word = reg & 0xff;
  *(volatile unsigned int *)(0xce008100 + (ch << 8) + word) = val; }
  *page_reg = old_page & 0xff;
}
