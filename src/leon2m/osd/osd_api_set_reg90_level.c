/* osd_api_set_reg90_level  (FUN_a0146588)
 *
 * Set the level byte of register group 0x90 of a menu layer.
 * Name basis: descriptive - forwards to osd_set_reg90_level; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146588 @ 0xa0146588-0xa01465a0 (6 words), flags -mcpu=v8 -O2 -g.
 * Tail call: the callee returns straight to this routine's caller, and the last word is the nop the compiler
 * places behind such a call sequence.
 */
extern void osd_set_reg90_level(unsigned char level, unsigned char layer);

/* Pass the level and the menu layer (0 or 1) on to osd_set_reg90_level, which writes registers 0x90 and 0x95.
 * Nothing calls this routine and no stored address points at it. */
void osd_api_set_reg90_level(unsigned char level, unsigned char layer)
{
    osd_set_reg90_level(level, layer);
}
