/* osd_set_rega0_fields  (FUN_a011cdb8)
 *
 * Program the two fields of register 0xA0 of a menu layer, or clear its enable bit.
 * Name basis: descriptive - bit 6 = enable, fields from two arguments; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011cdb8, flags -mcpu=v8 -O3 -g.
 * osd_update_reg_bits (osd_update_reg_bits) and the rd8 and wr8 helpers of osd_set_mode_bits are static copies inlined by the
 * compiler: rd8 clamps with "if (layer > 1) layer = 0", wr8 with a separate copy k, osd_update_reg_bits has no
 * layer check. a << 2 | b is computed into a local before the en test, and the written value is one expression.
 */
/* Registers of a menu layer: word n at 0xCF000000 + 4 * n, with n = osd_layer_bases[layer] + register number. */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

#define LAYER_REG_A0 0xa0               /* bit 6 = enable; bits 0..4 = the two fields set here; bit 5 is kept */

extern unsigned short osd_layer_bases[2];

static void osd_update_reg_bits(unsigned char layer, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int v = R(osd_layer_bases[layer] + reg);
    if (set == 1) v |= mask; else v &= ~mask;
    R(osd_layer_bases[layer] + reg) = (unsigned char)v;
}

static unsigned char rd8(unsigned char layer, unsigned char reg)
{
    if (layer > 1)
        layer = 0;
    return R(osd_layer_bases[layer] + reg);
}

static void wr8(unsigned char layer, unsigned char reg, unsigned char v)
{
    unsigned char k = layer;
    if (layer > 1)
        k = 0;
    R(osd_layer_bases[k] + reg) = v;
}

/* Program register 0xA0 of a menu layer. With en == 0 only bit 6 is cleared. Otherwise bits 5..7 stay as they
 * are, bit 6 is set, and the low bits become (field_a << 2 | field_b).
 *   en:      0 = clear the enable bit, any other value = set it and write the fields
 *   field_a, field_b: the two field values (not masked)
 *   layer:   menu layer number
 * Nothing in the image refers to it.
 */
void osd_set_rega0_fields(unsigned char en, unsigned int field_a, unsigned int field_b, unsigned char layer)
{
    unsigned int v = field_a << 2 | field_b;

    if (en == 0)
        osd_update_reg_bits(layer, LAYER_REG_A0, 0x40, 0);
    else
        wr8(layer, LAYER_REG_A0, (rd8(layer, LAYER_REG_A0) & 0xe0) | v | 0x40);
}
