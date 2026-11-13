/* hdmi_rx21_set_deep_color_enable  (FUN_a00a2010)
 *
 * Set or clear the deep-colour bit of the pixel PLL register.
 *   port: receiver
 *   on: 1 = deep colour
 * Name basis: derived - bit 2 / 6 of register 0xCF0147F0; set for 10..16 bits, cleared for 8 bits by
 *   hdmi_rx21_modedet_set_pll_mode
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2010, flags -mcpu=v8 -Os -g (section default). Both parameters are bytes ('and %o0, 0xff',
 * 'btst 0xff, %o1'); the 'mov %o4, %o5' in the delay slots carries the shared register address.
 */
#define REG_CF0147F0 (*(volatile unsigned int *)0xcf0147f0)

/*
 * Set (`on` != 0) or clear (`on` == 0) one bit of register 0xCF0147F0: bit 2 for receiver 0, bit 6 for receiver
 * 1. Called by hdmi_rx21_modedet_set_pll_mode: set for 10, 12 and 16 bits per colour, clear for 8 bits.
 *   port  HDMI 2.1 receiver 0/1
 *   on    non-zero = set
 */
void hdmi_rx21_set_deep_color_enable(unsigned char port, unsigned char on)
{
    if (on != 0) {
        if (port == 0) {
            REG_CF0147F0 = REG_CF0147F0 | 4;
        } else {
            REG_CF0147F0 = REG_CF0147F0 | 0x40;
        }
    } else {
        if (port == 0) {
            REG_CF0147F0 = REG_CF0147F0 & 0xfffffffb;
        } else {
            REG_CF0147F0 = REG_CF0147F0 & 0xffffffbf;
        }
    }
}
