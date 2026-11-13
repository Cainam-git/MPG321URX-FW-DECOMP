/* hdmi_rx21_write_pll_params  (FUN_a00964d0)
 *
 * Write the three FRL PLL parameter registers of an HDMI 2.1 receiver.
 *   port: receiver
 *   low_part: field
 *   high_part: field
 *   value: 16-bit value
 * Name basis: derived - 0xCF0146C0/C8/CC or 0xCF014700/08/0C; caller FRL_PLL
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00964d0 @ 0xa00964d0-0xa0096538 (26 words), flags -mcpu=v8 -Os -g.
 * Source form: all six register addresses are set up before the receiver test; volatile only on the 0xcf...
 * hardware registers.
 */
#define R(a) (*(volatile unsigned int *)(a))

/* Three PLL parameter registers per HDMI 2.1 receiver. */
#define PLL_PARAMS_RX0   0xcf0146c0     /* receives (high_part << 4) | low_part */
#define PLL_VALUE_LOW_RX0  0xcf0146c8   /* receives the low byte of the value */
#define PLL_VALUE_HIGH_RX0 0xcf0146cc   /* receives the high byte of the value */
#define PLL_PARAMS_RX1   0xcf014700
#define PLL_VALUE_LOW_RX1  0xcf014708
#define PLL_VALUE_HIGH_RX1 0xcf01470c

/*
 * Write the FRL PLL parameters of an HDMI 2.1 receiver: (high_part << 4) | low_part to the first register, the
 * low byte of value to the second and its high byte to the third.
 *   port: HDMI 2.1 receiver; 0 uses the registers at 0xCF0146C0.., any other value those at 0xCF014700..
 *   low_part, high_part: the two parts of the first register value
 *   value: 16-bit value
 * Called by FRL_PLL with (4, 2, 0x117) or (5, 2, 0x100).
 */
void hdmi_rx21_write_pll_params(unsigned char port, unsigned char low_part, unsigned char high_part, unsigned short value)
{
    if (port == 0) {
        R(PLL_PARAMS_RX0) = (high_part << 4) | low_part;
        R(PLL_VALUE_LOW_RX0) = (unsigned char)value;
        R(PLL_VALUE_HIGH_RX0) = value >> 8;
    } else {
        R(PLL_PARAMS_RX1) = (high_part << 4) | low_part;
        R(PLL_VALUE_LOW_RX1) = (unsigned char)value;
        R(PLL_VALUE_HIGH_RX1) = value >> 8;
    }
}
