/* osd_set_cell_size_mode  (FUN_a0119698)
 *
 * Select one of five character cell modes for a menu layer.
 * Name basis: descriptive - stores two per-layer bytes and updates registers 0xA2/0xA3 by mode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0119698 @ 0xa0119698-0xa01198a0 (130 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: osd_update_reg_bits (osd_update_reg_bits) is defined in this file (it is
 * the firmware's own routine and GCC inlines it) with a static 8-bit write helper whose value parameter is an
 * 'unsigned int' and which clamps the layer; the case blocks are in ascending order; the masks are the ints
 * 0xffffffc0 / 0xffffff80 as the firmware ORs them before the byte truncation.
 */
/* Register n of a menu layer is the word at 0xCF000000 + 4 * n; the layer's first register number is
   osd_layer_bases[layer]. */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short osd_layer_bases[2];
extern unsigned char osd_cell_widths[];
extern unsigned char osd_cell_heights[];

#define LAYER_REG_CELL_SIZE_A 0xa2      /* bits 6..7 select the mode; bits 0..5 are kept */
#define LAYER_REG_CELL_SIZE_B 0xa3      /* bits 6..7: 0 for modes 0..3, 3 for mode 4 */
#define BITS_6_7              0xffffffc0

/* Set (set == 1) or clear the bits of mask in register reg of a layer; no check of layer. */
void osd_update_reg_bits(unsigned char layer, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int value = R(osd_layer_bases[layer] + reg);
    if (set == 1) value |= mask; else value &= ~mask;
    R(osd_layer_bases[layer] + reg) = (unsigned char)value;
}

static void write_reg8(unsigned char layer, unsigned char reg, unsigned int value)
{
    if (layer > 1)
        layer = 0;
    R(osd_layer_bases[layer] + reg) = (unsigned char)value;
}

/*
 * Choose the character cell size of a menu layer from five modes (0..4); any other mode changes nothing.
 *
 *   mode   0..4, see the table below
 *   layer  menu layer 0 or 1
 *
 * The mode stores the layer's cell height code and cell width code (osd_cell_widths /
 * osd_cell_heights) and changes two layer registers (0xA2 and 0xA3). The low six bits of 0xA2 come from
 * the register osd_layer_bases[0] + layer (read before the change).
 *
 *   mode   height code  width code   register 0xA2                      register 0xA3
 *     0      0x0a         0x10        bits 6 and 7 set                   bits 6 and 7 cleared
 *     1      0x0a         0x12        bit 6 set                          bits 6 and 7 cleared
 *     2      0x0c         0x10        bit 7 set                          bits 6 and 7 cleared
 *     3      0x0c         0x12        written: the six kept bits only    bits 6 and 7 cleared
 *     4      0x18         0x24        not touched                        bits 6 and 7 set
 *
 * Called by osd_api_set_cell_size_mode. Its callers use mode 4 for the main menu layer and the crosshair
 * layer, and mode 3 for layers 0 and 1 in ShowLogo.
 */
void osd_set_cell_size_mode(unsigned int mode, unsigned char layer)
{
    unsigned int kept = R(osd_layer_bases[0] + layer) & 0x3f;

    switch (mode) {
    case 0:
        osd_cell_widths[layer] = 0xa;
        osd_cell_heights[layer] = 0x10;
        osd_update_reg_bits(layer, LAYER_REG_CELL_SIZE_A, kept | BITS_6_7, 1);
        osd_update_reg_bits(layer, LAYER_REG_CELL_SIZE_B, BITS_6_7, 0);
        break;
    case 1:
        osd_cell_widths[layer] = 0xa;
        osd_cell_heights[layer] = 0x12;
        osd_update_reg_bits(layer, LAYER_REG_CELL_SIZE_A, kept | 0x40, 1);
        osd_update_reg_bits(layer, LAYER_REG_CELL_SIZE_B, BITS_6_7, 0);
        break;
    case 2:
        osd_cell_widths[layer] = 0xc;
        osd_cell_heights[layer] = 0x10;
        osd_update_reg_bits(layer, LAYER_REG_CELL_SIZE_A, kept | 0xffffff80, 1);
        osd_update_reg_bits(layer, LAYER_REG_CELL_SIZE_B, BITS_6_7, 0);
        break;
    case 3:
        osd_cell_widths[layer] = 0xc;
        osd_cell_heights[layer] = 0x12;
        write_reg8(layer, LAYER_REG_CELL_SIZE_A, kept);
        osd_update_reg_bits(layer, LAYER_REG_CELL_SIZE_B, BITS_6_7, 0);
        break;
    case 4:
        osd_cell_widths[layer] = 0x18;
        osd_cell_heights[layer] = 0x24;
        osd_update_reg_bits(layer, LAYER_REG_CELL_SIZE_B, BITS_6_7, 1);
        break;
    }
}
