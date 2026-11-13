/* reg_read_block_byte  (FUN_a002e658)
 *
 * Return byte register reg of register block blk (0 or 1)
 *   layer: block 0 or 1 (other = 0)
 *   reg: register offset
 * Returns: byte value
 * Note: Block bases are the halfwords at 0xA8027AA8; nothing calls it.
 * Name basis: descriptive - code only; counterpart of reg_write_block_byte
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O3 -g. Source form: layer numbers above 1 are replaced by 0 before the table lookup; the
 * register is read through a volatile pointer and its low byte returned.
 */
extern unsigned short osd_layer_bases[];

/* Read one register of a menu layer: the register is the 32-bit word at 0xCF000000 + 4 * (base + reg), where
 * base is the layer's entry in osd_layer_bases.
 *   layer: menu layer 0 or 1 (any other value is treated as 0)
 *   reg:   register offset within the layer
 * Returns the low byte of the register. Nothing in the source calls it; reg_write_block_byte is its
 * counterpart. */
unsigned char reg_read_block_byte(unsigned char layer, unsigned char reg)
{
    if (layer > 1)
        layer = 0;
    return *(volatile unsigned int *)(0xcf000000 | ((osd_layer_bases[layer] + reg) << 2));
}
