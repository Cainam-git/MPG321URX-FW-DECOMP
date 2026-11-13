/* osd_set_reg8e_params  (FUN_a011aee4)
 *
 * Program the two parameter registers 0x8E/0x8F and a 2-bit field of register 0xCF.
 * Name basis: descriptive - both registers 0 when the third and fourth values are 0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011aee4, flags -mcpu=v8 -O3 -g.
 * The byte read and write helpers (a layer above 1 counts as 0) are defined here because GCC inlines them at -O3.
 */
/* Registers of a menu layer: word n at 0xCF000000 + 4 * n, with n = osd_layer_bases[layer] + register number. */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

extern unsigned short osd_layer_bases[2];

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

/* Program registers 0x8E and 0x8F of a menu layer. When c and d are both 0 both registers are set to 0.
 * Otherwise register 0x8E = (c & 0xF) << 4 | (d & 0xF), register 0x8F = 0x80 | (a & 7) << 4 | (b & 0xF), and
 * (e & 3) is ORed into bits 6..7 of register 0xCF (those bits are not cleared first).
 *   a, b, c, d, e: the five values
 *   layer:         menu layer number
 * Called by osd_api_set_reg8e_params.
 */
void osd_set_reg8e_params(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e,
                  unsigned char layer)
{
    if (c == 0 && d == 0) {
        wr8(layer, 0x8e, 0);
        wr8(layer, 0x8f, 0);
    } else {
        wr8(layer, 0xcf, rd8(layer, 0xcf) | ((e & 3) << 6));
        wr8(layer, 0x8e, ((c & 0xf) << 4) | (d & 0xf));
        wr8(layer, 0x8f, ((a & 7) << 4) | (b & 0xf) | 0x80);
    }
}
