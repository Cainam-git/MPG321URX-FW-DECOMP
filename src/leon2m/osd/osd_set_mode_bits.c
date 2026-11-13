/* osd_set_mode_bits  (FUN_a011cae0)
 *
 * Set the 3-bit mode field of a menu layer to one of four values.
 * Name basis: descriptive - bits 5..7 of register 0x80 = 0, 4, 3 or 7 by mode; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011cae0, flags -mcpu=v8 -O3 -g.
 * Nothing in the image refers to it (no call, branch or address constant). The static read and write helpers are
 * inlined per case; the read clamps the layer with "if (layer > 1) layer = 0", the write with a separate copy.
 */
#define LAYER_REG_WINDOWS_0_3 0x80      /* bit 0 = layer on; bits 1..4 = windows 0..3; bits 5..7 = the field set here */

extern unsigned short osd_layer_bases[];

static unsigned char rd(unsigned char layer)
{
    if (layer > 1)
        layer = 0;
    return *(volatile unsigned int *)(0xcf000000 | ((osd_layer_bases[layer] + LAYER_REG_WINDOWS_0_3) << 2));
}

static void wr(unsigned char layer, unsigned char v)
{
    unsigned char k = layer;

    if (layer > 1)
        k = 0;
    *(volatile unsigned int *)(0xcf000000 | ((osd_layer_bases[k] + LAYER_REG_WINDOWS_0_3) << 2)) = v;
}

/* Set bits 5..7 of register 0x80 of a menu layer by mode; bits 0..4 stay as they are.
 *   layer: menu layer number
 *   mode:  0 = bits 5..7 become 0, 1 = 4 (0x80), 2 = 3 (0x60), 3 = 7 (0xE0); other modes do nothing
 */
void osd_set_mode_bits(unsigned char layer, unsigned int mode)
{
    switch (mode) {
    case 0:
        wr(layer, rd(layer) & 0x1f);
        break;
    case 1:
        wr(layer, (rd(layer) & 0x1f) | 0x80);
        break;
    case 2:
        wr(layer, (rd(layer) & 0x1f) | 0x60);
        break;
    case 3:
        wr(layer, rd(layer) | 0xe0);
        break;
    }
}
