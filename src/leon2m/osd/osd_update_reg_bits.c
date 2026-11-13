/* osd_update_reg_bits  (FUN_a01191fc)
 *
 * Set or clear bits of one register of menu layer 0 or 1.
 * Name basis: derived - layer base addresses from the table at 0xA8027AA8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01191fc @ 0xa01191fc (-mcpu=v8 -O3 -g).
 * Source form: the register is read and the result written back as a byte; the address expression is repeated
 * for the read and the write.
 */
/* Register n of the menu layers is the word at 0xCF000000 + 4 * n. */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short osd_layer_bases[2];       /* register number of the first register of each menu layer */

/*
 * Set or clear bits of one register of a menu layer.
 *
 *   layer  0 or 1 (not range checked, unlike osd_write_reg16)
 *   reg    register number relative to the layer's base
 *   mask   the bits to change
 *   set    1: set the bits of mask; any other value: clear them
 *
 * Caller: FRCConfigPostFRC, which sets bit 3 of register 0xA5 in both layers.
 */
void osd_update_reg_bits(unsigned char layer, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int value = R(osd_layer_bases[layer] + reg);
    if (set == 1) value |= mask; else value &= ~mask;
    R(osd_layer_bases[layer] + reg) = (unsigned char)value;
}
