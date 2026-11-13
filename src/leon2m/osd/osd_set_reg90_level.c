/* osd_set_reg90_level  (FUN_a011abcc)
 *
 * Set the level byte of register group 0x90, or switch the group off for level 0.
 * Name basis: descriptive - bits 0-1 of register 0x90 and level * 0x55 to register 0x95
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011abcc, flags -mcpu=v8 -O3 -g.
 * osd_update_reg_bits (osd_update_reg_bits, no layer check) and the byte write (a layer above 1 counts as 0) are defined
 * here because GCC inlines them at -O3.
 */
/* Registers of a menu layer: word n at 0xCF000000 + 4 * n, with n = osd_layer_bases[layer] + register number. */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

extern unsigned short osd_layer_bases[2];

/* Set (set == 1) or clear the bits of mask in register reg of a layer; no layer check. */
void osd_update_reg_bits(unsigned char layer, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int v = R(osd_layer_bases[layer] + reg);
    if (set == 1) v |= mask; else v &= ~mask;
    R(osd_layer_bases[layer] + reg) = (unsigned char)v;
}

static void wr8(unsigned char layer, unsigned char reg, unsigned char v)
{
    if (layer > 1) layer = 0;
    R(osd_layer_bases[layer] + reg) = v;
}

/* Set the level of register group 0x90 of a menu layer. Level 0 clears bits 0..1 of register 0x90 and writes 0 to
 * register 0x95; any other level sets those bits and writes level * 0x55 to register 0x95.
 *   level: new level
 *   layer: menu layer number
 * Called by osd_api_set_reg90_level.
 */
void osd_set_reg90_level(unsigned char level, unsigned char layer)
{
    if (level == 0) {
        osd_update_reg_bits(layer, 0x90, 3, 0);
        wr8(layer, 0x95, 0);
    } else {
        osd_update_reg_bits(layer, 0x90, 3, 1);
        wr8(layer, 0x95, level * 0x55);
    }
}
