/* osd_enter_scope_size_choices  (FUN_a00999ec)
 *
 * Open the Optix Scope size list on the current size.
 * Note: States 0xE7..0xE9; size = settings byte +0x4B, saved in 0xA8025C55.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x44 = 'Scope Size'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00999ec @ 0xa00999ec-0xa0099a34 (18 words), flags -mcpu=v8 -O3 -g.
 * Family of the other list entry routines. osd_draw_scope_size_choices takes no argument (the second argument
 * of the following tail call is set in its delay slot). Source form: the base is the real settings record
 * user_settings; the tail call re-reads the record byte.
 */
struct user_settings_record { unsigned char pad[0x4b]; unsigned char scope_size; /* +0x4B: 0..2, Small, Medium, Large */ };
extern struct user_settings_record user_settings;
extern unsigned char osd_edit_value;
extern unsigned int osd_menu_state;
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_scope_size_choices(void);

#define MENU_STATE_SCOPE_SIZE_LIST 0xe7 /* + size: the Optix Scope size list (states 0xE7..0xE9) */
#define CHOICE_ROW_PLAIN         0      /* osd_highlight_choice_row style: plain */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */

/*
 * OK or right on Scope Size in the Optix Scope list: open the size choices (Small, Medium, Large) on the size now
 * stored (settings byte +0x4B).
 *
 * The choices are drawn, the size is saved in osd_edit_value for the left key, the menu state becomes 0xE7 plus
 * the size and the size's row is highlighted, first in the plain style and then with edge glyphs.
 */
void osd_enter_scope_size_choices(void)
{
  struct user_settings_record *p;
  unsigned char size;

  osd_draw_scope_size_choices();
  p = &user_settings;
  size = p->scope_size;
  osd_edit_value = size;
  osd_menu_state = size + MENU_STATE_SCOPE_SIZE_LIST;
  osd_highlight_choice_row(size, CHOICE_ROW_PLAIN);
  osd_highlight_choice_row(p->scope_size, CHOICE_ROW_EDGED);
}
