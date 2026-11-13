/* osd_write_reg_cc  (FUN_a011cc44)
 *
 * Write a 16-bit value to registers 0xCC/0xCD of a menu layer.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011cc44, flags -mcpu=v8 -O3 -g.
 * Same form as osd_write_reg16 (osd_write_reg16) with the register number fixed; the 16-bit write helper is inlined.
 */
/* Registers of a menu layer: word n at 0xCF000000 + 4 * n, with n = osd_layer_bases[layer] + register number. */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

#define LAYER_REG_CC 0xcc               /* low byte; the high byte is in register 0xCD */

extern unsigned short osd_layer_bases[2];

static void wr16(unsigned int a, unsigned short v) { R(a) = (unsigned char)v; R(a + 1) = (unsigned char)(v >> 8); }

/* Write a 16-bit value to registers 0xCC (low byte) and 0xCD (high byte) of a menu layer.
 *   layer: menu layer number; a value above 1 counts as layer 0
 *   value: the value
 * Called by osd_api_write_reg_cc.
 */
void osd_write_reg_cc(unsigned char layer, unsigned short value)
{
    if (layer > 1) layer = 0;
    wr16(osd_layer_bases[layer] + LAYER_REG_CC, value);
}
