/* osd_api_get_columns  (FUN_a0146164)
 *
 * Return the number of columns of a menu layer.
 * Returns: columns (low byte)
 * Name basis: derived - forwards to osd_get_columns; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146164, flags -mcpu=v8 -O2 -g (section default).
 * The second parameter and the CONCAT44 form are the decompiler's; they keep the exact build.
 */
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern unsigned short osd_get_columns(unsigned int layer);

/* Return the number of columns of a menu layer (low byte of osd_get_columns).
 *   layer:   menu layer number (low byte)
 *   ignored: second parameter, not used for the result
 * Nothing in the image calls it.
 */
int osd_api_get_columns(unsigned int layer, unsigned int ignored)
{
  unsigned short columns;

  columns = osd_get_columns(layer & 0xff);
  return CONCAT44(ignored, (unsigned int)columns) & 0xffffffff000000ff;
}
