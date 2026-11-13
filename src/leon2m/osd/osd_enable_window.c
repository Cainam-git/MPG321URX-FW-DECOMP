/* osd_enable_window  (FUN_a011a1b0)
 *
 * Switch on one of the eight windows of a menu layer.
 * Name basis: derived - windows 0..7: bits 1..4 of register 0x80 or bits 4..7 of register 0xA5
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011a1b0, flags -mcpu=v8 -O3 -g.
 * osd_update_reg_bits (osd_update_reg_bits) is defined here because GCC inlines it at -O3; it has no layer check.
 * Window 7 passes its mask as the char constant (char)0x80, which sign-extends to 0xffffff80 (the firmware ORs
 * -128); only bit 7 reaches the register through the byte write.
 */
/* Registers of a menu layer: word n at 0xCF000000 + 4 * n, with n = osd_layer_bases[layer] + register number. */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

#define LAYER_REG_WINDOWS_0_3 0x80      /* windows 0..3 = bits 1..4 */
#define LAYER_REG_WINDOWS_4_7 0xa5      /* windows 4..7 = bits 4..7 */

extern unsigned short osd_layer_bases[2];

/* Set (set == 1) or clear the bits of mask in register reg of a layer. */
void osd_update_reg_bits(unsigned char layer, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int v = R(osd_layer_bases[layer] + reg);
    if (set == 1) v |= mask; else v &= ~mask;
    R(osd_layer_bases[layer] + reg) = (unsigned char)v;
}

/* Switch on one of the eight windows of a menu layer.
 *   window: window number 0..7; a larger value does nothing
 *   layer:  menu layer number
 */
void osd_enable_window(unsigned int window, unsigned char layer)
{
    switch (window) {
    case 0:
        osd_update_reg_bits(layer, LAYER_REG_WINDOWS_0_3, 2, 1);
        break;
    case 1:
        osd_update_reg_bits(layer, LAYER_REG_WINDOWS_0_3, 4, 1);
        break;
    case 2:
        osd_update_reg_bits(layer, LAYER_REG_WINDOWS_0_3, 8, 1);
        break;
    case 3:
        osd_update_reg_bits(layer, LAYER_REG_WINDOWS_0_3, 0x10, 1);
        break;
    case 4:
        osd_update_reg_bits(layer, LAYER_REG_WINDOWS_4_7, 0x10, 1);
        break;
    case 5:
        osd_update_reg_bits(layer, LAYER_REG_WINDOWS_4_7, 0x20, 1);
        break;
    case 6:
        osd_update_reg_bits(layer, LAYER_REG_WINDOWS_4_7, 0x40, 1);
        break;
    case 7:
        osd_update_reg_bits(layer, LAYER_REG_WINDOWS_4_7, (char)0x80, 1);
        break;
    }
}
