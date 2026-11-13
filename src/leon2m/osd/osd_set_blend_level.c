/* osd_set_blend_level  (FUN_a011acac)
 *
 * Set the 0..8 level in the first level field and its two enable bits.
 * Name basis: descriptive - bits 0-2 of register 0xA1 = level - 1, bits 4-5 of 0xCF; used by the menu's 0..5
 *   level setting
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011acac, flags -mcpu=v8 -O3 -g.
 * osd_update_reg_bits (osd_update_reg_bits, no layer check) and the byte read and write helpers (a layer above 1 counts as
 * 0) are defined here because GCC inlines them at -O3.
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

/* Set the level of the first level field of a menu layer: bits 0..2 of register 0xA1 become level - 1, and bits
 * 4..5 of register 0xCF are set. Level 0 sets bits 0..2 of 0xA1 to 0 and clears bits 4..5 of 0xCF.
 * The twin osd_set_blend_level_second uses bits 3..5 of 0xA1 and bit 5 of 0xCF.
 *   level: 0..8; larger values count as 8; 0xFF = change nothing
 *   layer: menu layer number
 * Called by osd_api_set_blend_level and osd_api_set_level_all_windows.
 */
void osd_set_blend_level(unsigned char level, unsigned char layer)
{
    unsigned char v;

    if (level == BLEND_NONE)
        return;
    if (level > BLEND_MAX)
        level = BLEND_MAX;
    v = rd8(layer, 0xa1) & 0xf8;
    if (level == 0) {
        wr8(layer, 0xa1, v);
        osd_update_reg_bits(layer, 0xcf, 0x30, 0);
    } else {
        wr8(layer, 0xa1, v | (level - 1));
        osd_update_reg_bits(layer, 0xcf, 0x30, 1);
    }
}
