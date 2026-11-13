/* osd_write_reg24_group  (FUN_a011932c)
 *
 * Write a 24-bit value to one of three register groups of a menu layer, chosen by four group codes.
 * Name basis: derived - group codes 0xA0, 0xB0, 0xC0 and 0xC1; 0xC0 and 0xC1 write the same registers after
 *   setting or clearing bit 7 of register 0x9F
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011932c @ 0xa011932c, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the 16-bit write (osd_write_reg16, osd_write_reg16), the bit update
 * (osd_update_reg_bits, osd_update_reg_bits) and a static byte write are defined in this file; GCC inlines all three,
 * so the layer check (layer > 1 counts as 0) is repeated for every access. The mask for register 0x9F is the
 * int ~0x7f (0xffffff80): the firmware ORs -128 before the byte truncation; only bit 7 reaches the register.
 */
/* Register n of a menu layer is the word at 0xCF000000 + 4 * n; the layer's first register number is
   osd_layer_bases[layer]. */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short osd_layer_bases[2];

/* The four register groups, as codes (osd_api_write_reg24_group maps group 0..3 to them). */
#define GROUP_0     0xa0
#define GROUP_1     0xb0
#define GROUP_2     0xc0        /* bit 7 of LAYER_REG_GROUP2_SWITCH is set first */
#define GROUP_2_OFF 0xc1        /* the same registers, bit 7 of LAYER_REG_GROUP2_SWITCH is cleared first */

/* Register numbers inside a layer: bits 0..15 of the value go to a register pair, bits 16..23 to one register. */
#define LAYER_REG_GROUP0_LOW    0x88
#define LAYER_REG_GROUP0_HIGH   0xf0
#define LAYER_REG_GROUP1_LOW    0x8a
#define LAYER_REG_GROUP1_HIGH   0xf1
#define LAYER_REG_GROUP2_LOW    0x8c
#define LAYER_REG_GROUP2_HIGH   0xf2
#define LAYER_REG_GROUP2_SWITCH 0x9f

/* Write the low byte of value to register reg and its second byte to the next register. */
static void write_reg_pair(unsigned int a, unsigned short value) { R(a) = (unsigned char)value; R(a + 1) = (unsigned char)(value >> 8); }

/* Write a 16-bit value to registers reg and reg + 1 of a layer (layer > 1 counts as 0). */
void osd_write_reg16(unsigned char layer, unsigned char reg, unsigned short value)
{
    if (layer > 1) layer = 0;
    write_reg_pair(osd_layer_bases[layer] + reg, value);
}

/* Set (set == 1) or clear the bits of mask in register reg of a layer; no check of layer. */
void osd_update_reg_bits(unsigned char layer, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int value = R(osd_layer_bases[layer] + reg);
    if (set == 1) value |= mask; else value &= ~mask;
    R(osd_layer_bases[layer] + reg) = (unsigned char)value;
}

static void write_reg8(unsigned char layer, unsigned char reg, unsigned char value)
{
    if (layer > 1) layer = 0;
    R(osd_layer_bases[layer] + reg) = value;
}

/*
 * Write a 24-bit value into one of three register groups of menu layer 0 or 1.
 *
 *   group_code  GROUP_0, GROUP_1, GROUP_2 or GROUP_2_OFF; any other code writes nothing
 *   value       bits 0..15 go to the register pair of the group, bits 16..23 to the group's third register
 *   layer       menu layer 0 or 1 (a larger number counts as 0, except for the bit update of register 0x9F)
 *
 * Group 2 first sets (GROUP_2) or clear (GROUP_2_OFF) bit 7 of register 0x9F, then write the same registers.
 * Called by osd_api_write_reg24_group, whose callers write group 0 with the number of cells of the layer plus
 * one (osd_api_cell_count_plus_one).
 */
void osd_write_reg24_group(unsigned int group_code, unsigned int value, unsigned char layer)
{
    switch (group_code) {
    case GROUP_0:
        osd_write_reg16(layer, LAYER_REG_GROUP0_LOW, value);
        write_reg8(layer, LAYER_REG_GROUP0_HIGH, value >> 16);
        break;
    case GROUP_1:
        osd_write_reg16(layer, LAYER_REG_GROUP1_LOW, value);
        write_reg8(layer, LAYER_REG_GROUP1_HIGH, value >> 16);
        break;
    case GROUP_2:
        osd_update_reg_bits(layer, LAYER_REG_GROUP2_SWITCH, ~0x7f, 1);
        osd_write_reg16(layer, LAYER_REG_GROUP2_LOW, value);
        write_reg8(layer, LAYER_REG_GROUP2_HIGH, value >> 16);
        break;
    case GROUP_2_OFF:
        osd_update_reg_bits(layer, LAYER_REG_GROUP2_SWITCH, ~0x7f, 0);
        osd_write_reg16(layer, LAYER_REG_GROUP2_LOW, value);
        write_reg8(layer, LAYER_REG_GROUP2_HIGH, value >> 16);
        break;
    }
}
