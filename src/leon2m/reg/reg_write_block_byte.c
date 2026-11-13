/* reg_write_block_byte  (FUN_a002e69c)
 *
 * Write val to byte register reg of register block blk (0 or 1)
 *   layer: block 0 or 1 (other = 0)
 *   reg: register offset
 *   value
 * Note: Block bases are the halfwords at 0xA8027AA8.
 * Name basis: derived - header; caller panel_output_apply_timing (output timing apply)
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O3 -g. Source form: layer numbers of 2 and above are replaced by 0 before the table lookup.
 */
#define LAYER_REG(offset) (*(volatile unsigned int *)(0xcf000000 | ((offset) << 2)))
extern unsigned short osd_layer_bases[2];

/* Write one register of a menu layer: the register is the 32-bit word at 0xCF000000 + 4 * (base + reg), where
 * base is the layer's entry in osd_layer_bases.
 *   layer: menu layer 0 or 1 (any other value is treated as 0)
 *   reg:   register offset within the layer
 *   value: byte to write
 * Called by panel_output_apply_timing for register 0x5d of both layers. */
void reg_write_block_byte(unsigned char layer, unsigned char reg, unsigned char value)
{
    if (layer >= 2) layer = 0;
    LAYER_REG(osd_layer_bases[layer] + reg) = value;
}
