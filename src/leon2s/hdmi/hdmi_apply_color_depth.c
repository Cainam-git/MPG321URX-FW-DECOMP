/* hdmi_apply_color_depth  (FUN_a008fb7c)
 *
 * Apply the colour depth sent by an HDMI source and return its bits per colour.
 *   port: HDMI 2.0 receiver 0/1
 * Returns: bits per colour
 * Name basis: derived - reg 0x45 bits 0..2 = deep colour code 4..7 (GCP); returns 8/10/12/16
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008fb7c @ 0xa008fb7c-0xa008fdc8, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the port tests are switches; hdmi_reg_read8 is declared with an int result (signed case compare);
 *  - phy is declared with the default value port ('unsigned char phy = port;') and the first switch then sets
 *    it to 0 or 1. The default is dead after the switch, but GCC only drops it at combine, after it has made
 *    phy's value unknown there: the firmware keeps 'and %l0, 0xff' on the PHY arguments of the
 *    hdmi_phy_update_reg calls (a value known to be 0/1 compiles to 'and %l0, 1').
 */
extern int hdmi_reg_read8(unsigned char, unsigned short);
extern unsigned char hdmi_get_avi_color_space(unsigned char);
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);
extern void hdmi_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);

/* Receiver registers (hdmi_reg_read8 / hdmi_reg_update_bits). */
#define RX_REG_45       0x45        /* bits 0..2: colour depth code, read the same way by hdmi_get_color_depth */
#define RX_REG_D9       0xd9
#define RX_REG_D9_BIT1  0x02
#define BITS_CLEAR      0           /* mode argument of hdmi_reg_update_bits: anything but 1 clears */

/* Colour depth codes in bits 0..2 of RX_REG_45 (hdmi_get_color_depth gives the same bit counts). */
enum colour_depth_code {
    COLOUR_DEPTH_8_BITS  = 4,
    COLOUR_DEPTH_10_BITS = 5,
    COLOUR_DEPTH_12_BITS = 6,
    COLOUR_DEPTH_16_BITS = 7
};
#define COLOUR_DEPTH_MASK  7

/* PHY register whose bits 0..2 receive the colour depth code; all other bits are kept. */
#define PHY_REG_1F08        0x1f08
#define PHY_REG_1F08_KEEP   0xfffffff8

/* The value of the AVI colour space field on which hdmi_read_hactive and hdmi_read_htotal double the
   horizontal values. */
#define AVI_COLOR_SPACE_3   3

/* Two shared registers with one bit pair per receiver. */
#define REG_F224    (*(volatile unsigned int *)0xcf00f224)  /* rx 0: bits 0 and 4, rx 1: bits 1 and 5 */
#define REG_11640   (*(volatile unsigned int *)0xcf011640)  /* rx 0: bits 0 and 4, rx 1: bits 1 and 5 */

/*
 * Read the colour depth code a receiver reports and set the receiver, its PHY and two shared registers for
 * it. Called once by the HDMI 2.0 link state machine (hdmi_tmds_run_link_state) when the link has settled; the
 * result is stored as the colour depth of the port record.
 *
 *   port   HDMI 2.0 receiver 0 or 1; any other number returns 8 without touching anything
 *
 * Returns the bits per colour: 8, 10, 12 or 16 for the codes 4..7, and 8 for any other code.
 *
 * In order:
 *  1. Code 4 (8 bits per colour) sets both bits of the receiver in REG_F224; any other code clears only the
 *     low one (bit 0 or 1) and leaves the high one as it was.
 *  2. AVI colour space field 3 sets the high bit of the receiver in REG_11640; any other value clears both
 *     of its bits.
 *  3. The code is written to bits 0..2 of PHY register 0x1F08 (codes outside 4..7 are written as 4).
 *  4. Bit 1 of receiver register 0xD9 is cleared.
 * Register 0x45 is read twice, once for step 1 and once for step 3.
 */
unsigned char hdmi_apply_color_depth(unsigned char port)
{
    unsigned char phy = port;       /* receiver 0 / 1 uses PHY 0 / 1 */
    unsigned char bits = 8;

    switch (port) {
    case 0:
        phy = 0;
        break;
    case 1:
        phy = 1;
        break;
    default:
        return 8;
    }
    if ((hdmi_reg_read8(port, RX_REG_45) & COLOUR_DEPTH_MASK) == COLOUR_DEPTH_8_BITS) {
        switch (port) {
        case 0:
            REG_F224 |= 0x11;
            break;
        case 1:
            REG_F224 |= 0x22;
            break;
        }
    } else {
        switch (port) {
        case 0:
            REG_F224 &= ~1;
            break;
        case 1:
            REG_F224 &= ~2;
            break;
        }
    }
    if (hdmi_get_avi_color_space(port) == AVI_COLOR_SPACE_3) {
        switch (port) {
        case 0:
            REG_11640 |= 0x10;
            break;
        case 1:
            REG_11640 |= 0x20;
            break;
        }
    } else {
        switch (port) {
        case 0:
            REG_11640 &= ~0x10;
            REG_11640 &= ~1;
            break;
        case 1:
            REG_11640 &= ~0x20;
            REG_11640 &= ~2;
            break;
        }
    }
    switch (hdmi_reg_read8(port, RX_REG_45) & COLOUR_DEPTH_MASK) {
    case COLOUR_DEPTH_8_BITS:
        hdmi_phy_update_reg(phy, PHY_REG_1F08, PHY_REG_1F08_KEEP, COLOUR_DEPTH_8_BITS);
        bits = 8;
        break;
    case COLOUR_DEPTH_10_BITS:
        hdmi_phy_update_reg(phy, PHY_REG_1F08, PHY_REG_1F08_KEEP, COLOUR_DEPTH_10_BITS);
        bits = 10;
        break;
    case COLOUR_DEPTH_12_BITS:
        hdmi_phy_update_reg(phy, PHY_REG_1F08, PHY_REG_1F08_KEEP, COLOUR_DEPTH_12_BITS);
        bits = 12;
        break;
    case COLOUR_DEPTH_16_BITS:
        hdmi_phy_update_reg(phy, PHY_REG_1F08, PHY_REG_1F08_KEEP, COLOUR_DEPTH_16_BITS);
        bits = 16;
        break;
    default:
        hdmi_phy_update_reg(phy, PHY_REG_1F08, PHY_REG_1F08_KEEP, COLOUR_DEPTH_8_BITS);
        break;
    }
    hdmi_reg_update_bits(port, RX_REG_D9, RX_REG_D9_BIT1, BITS_CLEAR);
    return bits;
}
