/* dp_tx_phy_set_pll_enable  (FUN_a00aa538)
 *
 * Enable (with set-up values) or disable the PLL of a DP transmitter PHY unit.
 *   port: output
 *   on: 1 = on
 * Name basis: descriptive - registers 0xCF012AD0.. (output 0) or 0xCF012A90.. (eDP) bit 0; caller
 *   dp_tx_phy_set_link_rate
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 */
#define REG32(a) (*(volatile unsigned int *)(a))

/*
 * Switch bit 0 of the register 0xCF012AD0 (output 0) or 0xCF012A90 (outputs 1..4) on or off. Switching on
 * first writes the registers behind it: output 0 writes 0xB0 to 0xCF012AD8 and 1 to 0xCF012ADC; the other
 * outputs write 0xF to 0xCF012A94, 0xB0 to 0xCF012A98 and 3 to 0xCF012A9C.
 *
 *   port: output; 0 selects the first register set, any other value the second
 *   on:   non-zero = switch on, 0 = switch off
 *
 * Called by the PHY link-rate routine dp_tx_phy_set_link_rate.
 */
void dp_tx_phy_set_pll_enable(unsigned char port, unsigned char on)
{
    if (on != 0) {
        if (port == 0) {
            REG32(0xcf012ad8) = 0xb0;
            REG32(0xcf012adc) = 1;
            REG32(0xcf012ad0) |= 1;
        } else {
            REG32(0xcf012a94) = 0xf;
            REG32(0xcf012a98) = 0xb0;
            REG32(0xcf012a9c) = 3;
            REG32(0xcf012a90) |= 1;
        }
    } else {
        if (port == 0)
            REG32(0xcf012ad0) &= ~1;
        else
            REG32(0xcf012a90) &= ~1;
    }
}
