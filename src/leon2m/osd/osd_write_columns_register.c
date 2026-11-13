/* osd_write_columns_register  (FUN_a0119910)
 *
 * Write a 16-bit value to the two column-count registers of a menu layer.
 * Name basis: descriptive - bits 0..7 to register 0x83, bits 8..15 to register 0xD3; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0119910, flags -mcpu=v8 -O3 -g.
 * No routine calls it; osd_set_origin_and_size contains the same code inline.
 * The block clamp (a layer above 1 counts as 0) sits in an inlined byte-write helper that is called twice; the
 * compiler merges the two clamps.
 */
/* Registers of a menu layer: word n at 0xCF000000 + 4 * n, with n = osd_layer_bases[layer] + register number. */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

#define LAYER_REG_COLUMNS_LOW  0x83     /* low byte of the column value; osd_set_origin_and_size writes columns - 1 */
#define LAYER_REG_COLUMNS_HIGH 0xd3     /* high byte of the same value */

extern unsigned short osd_layer_bases[2];

/* Write one byte to register reg of a layer; a layer above 1 counts as layer 0. */
static void wr8(unsigned char layer, unsigned int reg, unsigned char v)
{
    if (layer > 1)
        layer = 0;
    R(osd_layer_bases[layer] + reg) = v;
}

/* Write a 16-bit value to the two column registers of a menu layer (low byte, then bits 8..15).
 *   layer: menu layer number
 *   value: low byte to register 0x83, bits 8..15 to register 0xD3
 */
void osd_write_columns_register(unsigned int layer, int value)
{
    wr8(layer, LAYER_REG_COLUMNS_LOW, value & 0xff);
    wr8(layer, LAYER_REG_COLUMNS_HIGH, (value >> 8) & 0xff);
}
