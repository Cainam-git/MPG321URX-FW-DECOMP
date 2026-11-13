/* osd_disable_window  (FUN_a011a378)
 *
 * Switch off one of the eight windows of a menu layer, or all of them.
 * Name basis: derived - clears the bits that osd_enable_window sets; other values clear all
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011a378 @ 0xa011a378, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: osd_update_reg_bits (osd_update_reg_bits) is defined in this file because
 * GCC inlines it; window 7 passes its mask as the char constant (char)0x80 (sign-extended, as in
 * osd_enable_window, osd_enable_window).
 */
/* Register n of a menu layer is the word at 0xCF000000 + 4 * n; the layer's first register number is
   osd_layer_bases[layer]. */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short osd_layer_bases[2];

#define LAYER_REG_WINDOWS_0_3  0x80     /* bits 1..4 = windows 0..3 (bit 0 is the layer's own on switch) */
#define LAYER_REG_WINDOWS_4_7  0xa5     /* bits 4..7 = windows 4..7 */

/* Set (set == 1) or clear the bits of mask in register reg of a layer; no check of layer. */
void osd_update_reg_bits(unsigned char layer, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int value = R(osd_layer_bases[layer] + reg);
    if (set == 1) value |= mask; else value &= ~mask;
    R(osd_layer_bases[layer] + reg) = (unsigned char)value;
}

/*
 * Switch off one window (0..7) of a menu layer, or every window for any other number.
 *
 *   window  0..7: the window to switch off; anything else: all eight
 *   layer   menu layer 0 or 1
 *
 * Windows 0..3 are bits 1..4 of layer register 0x80, windows 4..7 are bits 4..7 of register 0xA5. Counterpart
 * of osd_enable_window. Called by osd_api_set_window_enable.
 */
void osd_disable_window(unsigned int window, unsigned char layer)
{
    switch (window) {
    case 0:
        osd_update_reg_bits(layer, LAYER_REG_WINDOWS_0_3, 2, 0);
        break;
    case 1:
        osd_update_reg_bits(layer, LAYER_REG_WINDOWS_0_3, 4, 0);
        break;
    case 2:
        osd_update_reg_bits(layer, LAYER_REG_WINDOWS_0_3, 8, 0);
        break;
    case 3:
        osd_update_reg_bits(layer, LAYER_REG_WINDOWS_0_3, 0x10, 0);
        break;
    case 4:
        osd_update_reg_bits(layer, LAYER_REG_WINDOWS_4_7, 0x10, 0);
        break;
    case 5:
        osd_update_reg_bits(layer, LAYER_REG_WINDOWS_4_7, 0x20, 0);
        break;
    case 6:
        osd_update_reg_bits(layer, LAYER_REG_WINDOWS_4_7, 0x40, 0);
        break;
    case 7:
        osd_update_reg_bits(layer, LAYER_REG_WINDOWS_4_7, (char)0x80, 0);
        break;
    default:
        osd_update_reg_bits(layer, LAYER_REG_WINDOWS_0_3, 0x1e, 0);
        osd_update_reg_bits(layer, LAYER_REG_WINDOWS_4_7, 0xf0, 0);
        break;
    }
}
