/* osd_api_get_text_mode  (FUN_a0146bb4)
 *
 * Return the text drawing mode of a menu layer as 1, 2 or 0.
 * Returns: 1, 2 or 0
 * Name basis: descriptive - forwards to osd_get_text_mode; used by osd_draw_text
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146bb4 @ 0xa0146bb4, flags -mcpu=v8 -O2 -g.
 * Source form: the routine returns a 64-bit value built with CONCAT44 from its unused second parameter and the
 * mode; the caller reads only the low word. Both CONCAT44 and the second parameter are kept because the compiled
 * code depends on them.
 */
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern unsigned int osd_get_text_mode(unsigned int layer);

/* Return the text mode of the menu layer (0 or 1): 1 when it is stored as 1, 2 when it is stored as 2, otherwise
 * 0. The modes are TEXT_ALIGN_LEFT 0, TEXT_ALIGN_RIGHT 1 and TEXT_ALIGN_CENTRE 2. Called by osd_draw_text.
 * The second parameter is not used. */
int osd_api_get_text_mode(unsigned int layer,unsigned int unused)

{
  unsigned int stored_mode;
  int mode;
  
  stored_mode = osd_get_text_mode(layer & 0xff);
  mode = 1;
  if ((stored_mode & 0xff) != 1) {
    mode = (unsigned int)((stored_mode & 0xff) == 2) * 2;
  }
  return CONCAT44(unused,mode);
}
