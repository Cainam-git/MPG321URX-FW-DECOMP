/* osd_is_enabled  (FUN_a011996c)
 *
 * Return whether a menu layer is switched on.
 * Returns: 0 or 1
 * Name basis: derived - bit 0 of register 0x80 of the layer; polled by the main-loop task
 *
 * Matching notes
 * --------------
 * FUN_a011996c, flags -mcpu=v8 -O3 -g.
 */
/* Registers of a menu layer: word n at 0xCF000000 + 4 * n, with n = osd_layer_bases[layer] + register number. */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

#define LAYER_REG_WINDOWS_0_3 0x80      /* bit 0 = layer on (osd_enable sets and clears it); bits 1..4 = windows 0..3 */

extern unsigned short osd_layer_bases[2];

/* Return 1 when the menu layer is switched on (bit 0 of register 0x80), else 0.
 *   layer: menu layer number; a value above 1 counts as layer 0
 */
unsigned int osd_is_enabled(unsigned char layer)
{
    if (layer > 1) layer = 0;
    return R(osd_layer_bases[layer] + LAYER_REG_WINDOWS_0_3) & 1;
}
