/* osd_enable  (FUN_a011cca0)
 *
 * Switch a menu layer on or off.
 * Name basis: derived - bit 0 of register 0x80, the bit osd_is_enabled reads
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011cca0, flags -mcpu=v8 -O3 -g.
 * osd_update_reg_bits (osd_update_reg_bits, no layer check) is defined here because GCC inlines it at -O3; it is called
 * with a constant set argument in each arm.
 */
/* Registers of a menu layer: word n at 0xCF000000 + 4 * n, with n = osd_layer_bases[layer] + register number. */
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

#define LAYER_REG_WINDOWS_0_3 0x80      /* bit 0 = layer on (osd_is_enabled reads it) */
#define LAYER_ON_BIT          1

extern unsigned short osd_layer_bases[2];

/* Set (set == 1) or clear the bits of mask in register reg of a layer; no layer check. */
void osd_update_reg_bits(unsigned char layer, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int v = RB(osd_layer_bases[layer] + reg);
    if (set == 1) v |= mask; else v &= ~mask;
    RB(osd_layer_bases[layer] + reg) = (unsigned char)v;
}

/* Switch a menu layer on (on != 0) or off by setting or clearing bit 0 of register 0x80.
 *   layer: menu layer number
 * Called by osd_api_enable.
 */
void osd_enable(unsigned char layer, unsigned char on)
{
    if (on)
        osd_update_reg_bits(layer, LAYER_REG_WINDOWS_0_3, LAYER_ON_BIT, 1);
    else
        osd_update_reg_bits(layer, LAYER_REG_WINDOWS_0_3, LAYER_ON_BIT, 0);
}
