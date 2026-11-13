/* osd_api_set_blend_level  (FUN_a0146570)
 *
 * Set the level in the first level field of a menu layer.
 * Name basis: descriptive - forwards to osd_set_blend_level; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146570, flags -mcpu=v8 -O2 -g (section default).
 * Tail call: the caller's return address is handed on, so the callee returns straight to this routine's caller. The
 * last word is the nop the compiler places behind such a call sequence. Nothing in the image calls it.
 */
extern void osd_set_blend_level(unsigned char level, unsigned char layer);

/* Set the level of the first level field of a menu layer: calls osd_set_blend_level.
 *   level: 0..8, 0xFF = change nothing
 *   layer: menu layer number
 */
void osd_api_set_blend_level(unsigned char level, unsigned char layer)
{
    osd_set_blend_level(level, layer);
}
