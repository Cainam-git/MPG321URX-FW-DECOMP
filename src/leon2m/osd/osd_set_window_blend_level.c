/* osd_set_window_blend_level  (FUN_a011a848)
 *
 * Set the 0..8 level in the second level field and its enable bit in register 0xAA.
 * Name basis: descriptive - bits 3-5 of register 0xA1 = level - 1, bit 4 of 0xAA; level 0 clears both
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011a848, flags -mcpu=v8 -O3 -g.
 * osd_update_reg_bits (osd_update_reg_bits, no layer check) and the byte read and write helpers (which treat a layer above
 * 1 as 0) are defined here because GCC inlines them at -O3.
 */
/* Registers of a menu layer: word n at 0xCF000000 + 4 * n, with n = osd_layer_bases[layer] + register number. */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

#define BLEND_NONE 0xff                 /* level value that makes the routine write nothing */
#define BLEND_MAX  8                    /* largest level; larger values are cut to it */

extern unsigned short osd_layer_bases[2];

/* Set (set == 1) or clear the bits of mask in register reg of a layer; no layer check. */
void osd_update_reg_bits(unsigned char layer, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int v = R(osd_layer_bases[layer] + reg);
    if (set == 1) v |= mask; else v &= ~mask;
    R(osd_layer_bases[layer] + reg) = (unsigned char)v;
}

static unsigned char rd8(unsigned char layer, unsigned char reg)
{
    if (layer > 1) layer = 0;
    return R(osd_layer_bases[layer] + reg);
}

static void wr8(unsigned char layer, unsigned char reg, unsigned char v)
{
    if (layer > 1) layer = 0;
    R(osd_layer_bases[layer] + reg) = v;
}

/* Set the level (0..8) of the second level field of a menu layer. Level 0 clears bits 3..5 of register 0xA1
 * and bit 4 of register 0xAA; level 1..8 stores level - 1 in bits 3..5 of 0xA1 and sets bit 4 of 0xAA.
 *   level: 0..8; larger values count as 8; 0xFF = change nothing
 *   layer: menu layer number
 * Called by osd_api_set_window_blend_level and osd_api_set_level_all_windows.
 */
void osd_set_window_blend_level(unsigned char level, unsigned char layer)
{
    if (level == BLEND_NONE)
        return;
    if (level > BLEND_MAX)
        level = BLEND_MAX;
    if (level == 0) {
        osd_update_reg_bits(layer, 0xa1, 0x38, 0);
        osd_update_reg_bits(layer, 0xaa, 0x10, 0);
    } else {
        wr8(layer, 0xa1, (rd8(layer, 0xa1) & 0xc7) | ((level - 1) << 3));
        osd_update_reg_bits(layer, 0xaa, 0x10, 1);
    }
}
