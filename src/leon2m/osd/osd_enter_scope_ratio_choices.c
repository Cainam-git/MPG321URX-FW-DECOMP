/* osd_enter_scope_ratio_choices  (FUN_a0099a34)
 *
 * Open the Optix Scope ratio list on the current ratio.
 * Note: States 0xEA..0xEC; ratio = settings byte +0x4C, saved in 0xA8025C55.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x45 = 'Scope Ratio'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099a34 @ 0xa0099a34-0xa0099a7c (18 words), flags -mcpu=v8 -O3 -g.
 * Same code as osd_enter_scope_size_choices with other constants. osd_draw_scope_ratio_choices takes no
 * argument. Source form: the base is the real settings record user_settings; the second highlight call re-reads
 * the record byte.
 */
struct user_settings_record { unsigned char pad[0x4c]; unsigned char scope_ratio; /* +0x4C: the Optix Scope zoom ratio (list row 0..2) */ };
extern struct user_settings_record user_settings;
extern unsigned char osd_edit_value;
extern unsigned int osd_menu_state;
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_scope_ratio_choices(void);

#define MENU_STATE_SCOPE_RATIO_LIST 0xea /* + ratio: the Optix Scope ratio list (states 0xEA..0xEC) */
#define CHOICE_ROW_PLAIN         0      /* osd_highlight_choice_row style: plain */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */

/*
 * OK or right on Scope Ratio in the Optix Scope list: open the ratio choices on the ratio now stored (settings
 * byte +0x4C).
 *
 * The choices are drawn, the ratio is saved in osd_edit_value for the left key, the menu state becomes 0xEA plus
 * the ratio and the ratio's row is highlighted, first in the plain style and then with edge glyphs.
 */
void osd_enter_scope_ratio_choices(void)
{
  struct user_settings_record *p;
  unsigned char ratio;

  osd_draw_scope_ratio_choices();
  p = &user_settings;
  ratio = p->scope_ratio;
  osd_edit_value = ratio;
  osd_menu_state = ratio + MENU_STATE_SCOPE_RATIO_LIST;
  osd_highlight_choice_row(ratio, CHOICE_ROW_PLAIN);
  osd_highlight_choice_row(p->scope_ratio, CHOICE_ROW_EDGED);
}
