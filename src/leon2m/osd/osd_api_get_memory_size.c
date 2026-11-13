/* osd_api_get_memory_size  (FUN_a014611c)
 *
 * Return 0x14000 for menu layer 0 and 0x6000 for the other.
 * Returns: size
 * Name basis: descriptive - constants; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014611c, flags -mcpu=v8 -O3 -g.
 * Nothing in the image refers to it. A conditional expression with the layer == 0 arm first; GCC turns it into
 * subx/and/add arithmetic.
 */
/* Return the memory size of a menu layer: 0x14000 for layer 0, 0x6000 for any other value.
 *   layer: menu layer number
 */
unsigned int osd_api_get_memory_size(unsigned char layer)
{
    return layer == 0 ? 0x14000 : 0x6000;
}
