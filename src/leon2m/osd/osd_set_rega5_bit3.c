/* osd_set_rega5_bit3  (FUN_a011cd10)
 *
 * Set or clear bit 3 of register 0xA5 of a menu layer.
 * Name basis: descriptive - set together with osd_enable when the layer is switched on
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011cd10, flags -mcpu=v8 -O3 -g.
 * osd_update_reg_bits (osd_update_reg_bits, no layer check) is defined here because GCC inlines it at -O3; it is called
 * with a constant set argument in each arm.
 */
/* Registers of a menu layer: word n at 0xCF000000 + 4 * n, with n = osd_layer_bases[layer] + register number. */
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

#define LAYER_REG_WINDOWS_4_7 0xa5      /* windows 4..7 = bits 4..7; bit 3 is set here */

extern unsigned short osd_layer_bases[2];

/* Set (set == 1) or clear the bits of mask in register reg of a layer; no layer check. */
void osd_update_reg_bits(unsigned char layer, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int v = RB(osd_layer_bases[layer] + reg);
    if (set == 1) v |= mask; else v &= ~mask;
    RB(osd_layer_bases[layer] + reg) = (unsigned char)v;
}

/* Set (on != 0) or clear bit 3 of register 0xA5 of a menu layer.
 *   layer: menu layer number
 * Called by osd_api_enable, which also calls osd_enable.
 */
void osd_set_rega5_bit3(unsigned char layer, unsigned char on)
{
    if (on)
        osd_update_reg_bits(layer, LAYER_REG_WINDOWS_4_7, 8, 1);
    else
        osd_update_reg_bits(layer, LAYER_REG_WINDOWS_4_7, 8, 0);
}
