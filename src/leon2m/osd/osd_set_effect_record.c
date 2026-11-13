/* osd_set_effect_record  (FUN_a011a574)
 *
 * Copy a five-byte effect record into the registers of a menu layer.
 * Name basis: descriptive - registers 0xAA, 0xAB, 0xAD, 0xAE, 0xAF and 0xCF; bits of the first byte switch
 *   single bits
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011a574, flags -mcpu=v8 -O3 -g.
 * osd_update_reg_bits (osd_update_reg_bits) and the byte write are defined here because GCC inlines them at -O3. Each bit
 * of record[0] is tested with an if/else that calls osd_update_reg_bits with a constant set argument; bit 7 is the
 * char constant (char)0x80.
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

/* Copy a five-byte record into registers 0xAA, 0xAB, 0xAD, 0xAE, 0xAF and 0xCF of a menu layer.
 *   record: byte 0 bit 0 -> bit 7 of reg 0xAA, bit 1 -> bit 0 of 0xAA, bit 2 -> bit 1 of 0xAA,
 *           bit 3 -> bit 2 of 0xCF; byte 1 -> reg 0xAB; byte 2 bits 4..5 -> bits 5..6 of 0xAA (set only,
 *           never cleared), bits 0..2 -> reg 0xAD; byte 3 -> reg 0xAE; byte 4 -> reg 0xAF
 *   layer:  menu layer number
 * Called by osd_api_set_window_effect.
 */
void osd_set_effect_record(unsigned char *record, unsigned char layer)
{
    wr8(layer, 0xab, record[1]);
    if (record[0] & 1)
        osd_update_reg_bits(layer, 0xaa, (char)0x80, 1);
    else
        osd_update_reg_bits(layer, 0xaa, (char)0x80, 0);
    if (record[0] & 2)
        osd_update_reg_bits(layer, 0xaa, 1, 1);
    else
        osd_update_reg_bits(layer, 0xaa, 1, 0);
    if (record[0] & 4)
        osd_update_reg_bits(layer, 0xaa, 2, 1);
    else
        osd_update_reg_bits(layer, 0xaa, 2, 0);
    if (record[0] & 8)
        osd_update_reg_bits(layer, 0xcf, 4, 1);
    else
        osd_update_reg_bits(layer, 0xcf, 4, 0);
    osd_update_reg_bits(layer, 0xaa, (record[2] & 0x30) << 1, 1);
    wr8(layer, 0xad, record[2] & 7);
    wr8(layer, 0xae, record[3]);
    wr8(layer, 0xaf, record[4]);
}
