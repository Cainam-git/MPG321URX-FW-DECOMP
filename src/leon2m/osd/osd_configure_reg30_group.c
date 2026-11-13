/* osd_configure_reg30_group  (FUN_a011a9e4)
 *
 * Program register 0x30 and one of the two parameter triples behind it.
 * Name basis: descriptive - registers 0x31..0x33 or 0x34..0x36 by selector
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011a9e4, flags -mcpu=v8 -O3 -g.
 * osd_update_reg_bits (osd_update_reg_bits, no layer check) and the byte write (a layer above 1 counts as 0) are defined
 * here because GCC inlines them at -O3; sel is tested with an if/else chain.
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

/* Clear register 0x30 of a menu layer, set its bits 0..3 and 5, set bit 4 from bit 0 of b, then fill one
 * of the three register pairs (0x31/0x34, 0x32/0x35, 0x33/0x36).
 *   sel:   0, 1 or 2 = the pair to fill; any other value stops after register 0x30
 *   b:     bit 0 goes to bit 4 of register 0x30
 *   c:     bit 0 goes to bit 7 of the first register of the pair
 *   d:     value of the second register of the pair
 *   e:     bits 0..4 go to bits 0..4 of the first register of the pair
 *   layer: menu layer number
 * Called by osd_api_configure_window_reg30.
 */
void osd_configure_reg30_group(unsigned char sel, unsigned int b, unsigned int c, unsigned char d, unsigned int e,
                  unsigned char layer)
{
    wr8(layer, 0x30, 0);
    osd_update_reg_bits(layer, 0x30, 0x2f, 1);
    osd_update_reg_bits(layer, 0x30, (b & 1) << 4, 1);
    if (sel == 0) {
        wr8(layer, 0x31, (e & 0x1f) | ((c & 1) << 7));
        wr8(layer, 0x34, d);
    } else if (sel == 1) {
        wr8(layer, 0x32, (e & 0x1f) | ((c & 1) << 7));
        wr8(layer, 0x35, d);
    } else if (sel == 2) {
        wr8(layer, 0x33, (e & 0x1f) | ((c & 1) << 7));
        wr8(layer, 0x36, d);
    }
}
