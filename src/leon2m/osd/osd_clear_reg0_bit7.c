/* osd_clear_reg0_bit7  (FUN_a0119578)
 *
 * Clear bit 7 of the first register of a menu layer.
 * Name basis: descriptive - the bit the memory writes also clear before they start; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0119578 @ 0xa0119578-0xa01195ac (52 bytes, leaf), flags -mcpu=v8 -O3 -g.
 */
extern unsigned short osd_layer_bases[];        /* register number of the first register of each menu layer */

/*
 * Clear bit 7 of the first register of a menu layer: the register is ANDed with 0x7f, which keeps bits 0..6.
 * Nothing in the firmware calls this routine.
 *
 *   layer  index into osd_layer_bases (not range checked)
 */
void osd_clear_reg0_bit7(unsigned char layer)
{
    volatile unsigned int *reg = (volatile unsigned int *)(0xcf000000 | (osd_layer_bases[layer] << 2));

    *reg &= 0x7f;
}
