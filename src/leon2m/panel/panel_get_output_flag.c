/* panel_get_output_flag  (FUN_a0105c78)
 *
 * Return the output driver's flag byte.
 * Returns: byte
 * Name basis: descriptive - byte at 0xA8027A80; unused
 *
 * Matching notes
 * --------------
 * FUN_a0105c78, flags -mcpu=v8 -O2 -g. Leaf. Nothing in the image calls or points to it.
 * Source form: a direct read of the extern symbol.
 */
extern unsigned short panel_output_flag;

/* Return the 16-bit value at panel_output_flag. */
unsigned short panel_get_output_flag(void)
{
    return panel_output_flag;
}
