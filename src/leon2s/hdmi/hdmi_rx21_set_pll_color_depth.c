/* hdmi_rx21_set_pll_color_depth  (FUN_a00a1f84)
 *
 * Set the pixel PLL colour-depth field for colour depth code 4..7.
 *   sel: receiver
 *   code: colour depth code
 * Name basis: derived - code 4..7 (24/30/36/48-bit) -> 2-bit field of register 0xCF0147F0; caller
 *   hdmi_rx21_modedet_set_pll_mode
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a1f84, flags -mcpu=v8 -Os -g (section default). Leaf.
 */
#define REG_CF0147F0 (*(volatile unsigned int *)0xcf0147f0)

/* Colour depth codes 4..7 (8, 10, 12 and 16 bits per colour). */
#define COLOUR_DEPTH_8_BITS  4
#define COLOUR_DEPTH_10_BITS 5
#define COLOUR_DEPTH_12_BITS 6
#define COLOUR_DEPTH_16_BITS 7

/*
 * Write the 2-bit field for colour depth `code` into register 0xCF0147F0: 4 -> 0, 5 -> 1, 6 -> 2, 7 -> 3 (any
 * other code 0). Receiver 0 uses bits 0-1, receiver 1 bits 4-5; the other bits of the low byte are kept and
 * bits 8-31 are written as 0. Called by hdmi_rx21_modedet_set_pll_mode.
 *   sel   HDMI 2.1 receiver 0/1
 *   code  colour depth code
 */
void hdmi_rx21_set_pll_color_depth(unsigned char sel, unsigned char code)
{
    unsigned char field;

    switch (code) {
    case COLOUR_DEPTH_8_BITS: field = 0; break;
    case COLOUR_DEPTH_10_BITS: field = 1; break;
    case COLOUR_DEPTH_12_BITS: field = 2; break;
    case COLOUR_DEPTH_16_BITS: field = 3; break;
    default: field = 0; break;
    }
    if (sel == 0)
        REG_CF0147F0 = (REG_CF0147F0 & 0xfc) | field;
    else
        REG_CF0147F0 = (REG_CF0147F0 & 0xcf) | (field << 4);
}
