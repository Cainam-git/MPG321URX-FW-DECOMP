/* osd_set_reg30_bits  (FUN_a011a974)
 *
 * Set or clear the control bits of register 0x30 of a menu layer.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011a974, flags -mcpu=v8 -O3 -g.
 * Nothing in the image refers to it (no call, branch or address constant). The register address is computed
 * separately in each arm.
 */
extern unsigned short osd_layer_bases[];

/* Set or clear the control bits of register 0x30 of a menu layer.
 *   on:    non-zero = set bits 0..3 and 5 (OR with 0x2f); 0 = keep only bits 4 and 6..7 (AND with 0xd0)
 *   layer: menu layer number (no range check)
 */
void osd_set_reg30_bits(unsigned char on, unsigned char layer)
{
    volatile unsigned int *reg;

    if (on) {
        reg = (volatile unsigned int *)(0xcf000000 | ((osd_layer_bases[layer] + 0x30) << 2));
        *reg = (unsigned char)(*reg | 0x2f);
    } else {
        reg = (volatile unsigned int *)(0xcf000000 | ((osd_layer_bases[layer] + 0x30) << 2));
        *reg &= 0xd0;
    }
}
