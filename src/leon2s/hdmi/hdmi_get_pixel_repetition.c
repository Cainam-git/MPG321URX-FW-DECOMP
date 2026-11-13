/* hdmi_get_pixel_repetition  (FUN_a0090d7c)
 *
 * Return the pixel repetition factor (1, 2 or 4) from the AVI InfoFrame.
 *   port: HDMI 2.0 receiver 0/1
 * Name basis: derived - low nibble of reg 0x148 (AVI byte 5): 1 -> 2, 3 -> 4; divisor in hdmi_calc_pixel_clock
 *
 * Matching notes
 * --------------
 * FUN_a0090d7c (leon2s, 0xa0090d7c-0xa0090dcc, 20 words). Flags -mcpu=v8 -Os -g.
 * Source form: a switch with the cases 0, 1, 3 and default, on a signed int (the firmware compares with 1, then
 * 0 / 3); an if/else chain gives the unsigned compare form. The result is masked with 7 on return ('and 7').
 */

#define RX_AVI_DATA_5   0x148           /* AVI packet area starts at 0x140 */

extern unsigned int hdmi_reg_read8(unsigned char, unsigned int);

/* The low four bits of register 0x148 give the factor: 1 -> 2, 3 -> 4, anything else (0 included) -> 1.
   hdmi_calc_pixel_clock divides the measured clock by it. */
unsigned char hdmi_get_pixel_repetition(unsigned char port)
{
    int field = hdmi_reg_read8(port, RX_AVI_DATA_5) & 0xf;
    unsigned char factor;

    switch (field) {
    case 0: factor = 1; break;
    case 1: factor = 2; break;
    case 3: factor = 4; break;
    default: factor = 1; break;
    }
    return factor & 7;
}
