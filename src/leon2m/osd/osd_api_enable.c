/* osd_api_enable  (FUN_a0146dc0)
 *
 * Switch a menu layer on or off.
 * Name basis: derived - forwards to osd_enable; sets bit 3 of register 0xA5 first when switching on
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146dc0 @ 0xa0146dc0, flags -mcpu=v8 -O2 -g.
 * Source form: both callees are declared without a prototype and return int. The four trailing parameters are
 * passed on to osd_enable although it takes only two (the layer and the on/off value); they have to stay for the
 * exact build.
 */
extern int osd_enable();
extern int osd_set_rega5_bit3();

/* Switch the menu layer (0 or 1) on (on != 0) or off. Switching on first sets bit 3 of register 0xA5, then sets
 * bit 0 of register 0x80; switching off only clears bit 0 of register 0x80. extra3..extra6 are passed on to
 * osd_enable, which does not use them. */
void osd_api_enable(unsigned char on,unsigned char layer,unsigned int extra3,unsigned int extra4,
                 unsigned int extra5,unsigned int extra6)

{
  if (on != '\0') {
    osd_set_rega5_bit3(layer,1);
    osd_enable(layer,1,extra3,extra4,extra5,extra6);
    return;
  }
  osd_enable(layer,0,extra3,extra4,extra5,extra6);
  return;
}
