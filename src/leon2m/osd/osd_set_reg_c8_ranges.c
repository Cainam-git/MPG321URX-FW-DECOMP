/* osd_set_reg_c8_ranges  (FUN_a011b034)
 *
 * Program two pairs of 10-bit limits in registers 0xC8..0xCB and 0xD8..0xDB.
 * Name basis: descriptive - all zero when the first or third value is 0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011b034, flags -mcpu=v8 -O3 -g.
 * The non-zero arm comes first in both ifs; bit 7 is ORed as the char constant (char)0x80 (the firmware ORs -128
 * before the byte truncation); the byte write helper (a layer above 1 counts as 0) is inlined.
 */
/* Registers of a menu layer: word n at 0xCF000000 + 4 * n, with n = osd_layer_bases[layer] + register number. */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

extern unsigned short osd_layer_bases[2];

static void wr8(unsigned char layer, unsigned char reg, unsigned char v)
{
    if (layer > 1) layer = 0;
    R(osd_layer_bases[layer] + reg) = v;
}

/* Program two pairs of limits of a menu layer. A pair is written as zeros when its first value is 0.
 *   first pair:  limit0_a -> reg 0xC8 (low byte, bit 7 set) and 0xD8 (bits 7..9 of limit0_a);
 *                limit0_b -> reg 0xC9 (low byte) and 0xD9 (bits 8..9)
 *   second pair: limit1_a -> reg 0xCA (low byte, bit 7 set) and 0xDA (bit 7 of limit1_a);
 *                limit1_b -> reg 0xCB (low byte) and 0xDB (bits 8..9)
 *   layer:       menu layer number
 * Called by osd_api_set_reg_c8_ranges.
 */
void osd_set_reg_c8_ranges(unsigned short limit0_a, unsigned short limit0_b, unsigned short limit1_a, unsigned short limit1_b,
                  unsigned char layer)
{
    if (limit0_a != 0) {
        wr8(layer, 0xc8, limit0_a | (char)0x80);
        wr8(layer, 0xd8, (limit0_a >> 7) & 7);
        wr8(layer, 0xc9, limit0_b);
        wr8(layer, 0xd9, (limit0_b >> 8) & 3);
    } else {
        wr8(layer, 0xc8, 0);
        wr8(layer, 0xd8, 0);
        wr8(layer, 0xc9, 0);
        wr8(layer, 0xd9, 0);
    }
    if (limit1_a != 0) {
        wr8(layer, 0xca, limit1_a | (char)0x80);
        wr8(layer, 0xda, (limit1_a >> 7) & 1);
        wr8(layer, 0xcb, limit1_b);
        wr8(layer, 0xdb, (limit1_b >> 8) & 3);
    } else {
        wr8(layer, 0xca, 0);
        wr8(layer, 0xda, 0);
        wr8(layer, 0xcb, 0);
        wr8(layer, 0xdb, 0);
    }
}
