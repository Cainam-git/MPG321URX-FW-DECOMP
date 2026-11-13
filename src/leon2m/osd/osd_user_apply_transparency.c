/* osd_user_apply_transparency  (FUN_a00d4780)
 *
 * Apply the menu transparency setting 0..5.
 * Name basis: derived - settings byte +0x0F limited to 5, then osd_api_set_level_all_windows
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d4780 @ 0xa00d4780-0xa00d47ac (11 words), flags -mcpu=v8 -O2 -g.
 * Leaf frame; the call is a tail call.
 * Source form: the record is a struct; the clamp variable is an unsigned short (an unsigned char gives an extra
 * mask and branch, an unsigned int gives no re-extension; the short's conversion to the byte parameter is the
 * 'and 0xff').
 */
#define TRANSPARENCY_MAX 5                      /* levels 0..5 */

struct user_settings_record {
    unsigned char pad[0xf];
    unsigned char transparency;                 /* +0xF: menu Transparency */
};
extern struct user_settings_record user_settings;
extern void osd_api_set_level_all_windows(unsigned char);

/* Limit the Transparency setting (+0xF) to 5, store it back and apply it as the level of all windows of both
   menu layers. */
void osd_user_apply_transparency(void)
{
  unsigned short level = user_settings.transparency;

  if (level > TRANSPARENCY_MAX)
    level = TRANSPARENCY_MAX;
  user_settings.transparency = level;
  osd_api_set_level_all_windows(level);
}
