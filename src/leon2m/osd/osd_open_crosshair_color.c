/* osd_open_crosshair_color  (FUN_a00957e8)
 *
 * Open the crosshair colour list (White, Red, Auto) on the current colour.
 * Note: States 0xED..0xEF; current colour = settings byte +0x17B.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x40 = 'Color'; texts 0x18E54C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00957e8, flags -mcpu=v8 -O3 -g.
 * Source form: the colour is an unsigned char local (the firmware masks it with 0xff before adding 0xED, while
 * the store to osd_edit_value uses the loaded byte); the settings record is a struct, no volatile;
 * osd_clear_choice_column and osd_update_key_guide are called with no and two arguments (the last is a tail call).
 */
#define MENU_STATE_CROSSHAIR_COLOR_LIST 0xed    /* + colour (2 = Auto): the colour choices White, Red, Auto */
#define KEY_TEXT_MOVE                   0       /* key guide texts: Move, Select */
#define KEY_TEXT_SELECT                 4

/* The Smart Crosshair colour in the user settings record. */
struct user_settings_record {
  unsigned char pad[0x17b];
  unsigned char crosshair_color;                /* +0x17B: 2 = automatic */
};
extern struct user_settings_record user_settings;
extern unsigned char osd_edit_value;
extern unsigned int osd_menu_state;
extern void osd_clear_choice_column(void);
extern void osd_draw_key_guide(int, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_update_key_guide(unsigned int, unsigned int);
extern void osd_draw_crosshair_color_choices(void);

/*
 * OK or right key on the Color item of the Smart Crosshair items: open the colour choices (White, Red, Auto).
 * The choice column is cleared, the menu state becomes the state of the present colour, the colour is saved
 * in osd_edit_value so that the left key can restore it, the choices are drawn and the colour's row is
 * highlighted (both styles), and the key guide is drawn with the texts Move and Select.
 */
void osd_open_crosshair_color(void)
{
  struct user_settings_record *settings;
  unsigned char color;

  osd_clear_choice_column();
  settings = &user_settings;
  color = settings->crosshair_color;
  osd_menu_state = color + MENU_STATE_CROSSHAIR_COLOR_LIST;
  osd_edit_value = color;
  osd_draw_crosshair_color_choices();
  osd_highlight_choice_row(settings->crosshair_color, 0);
  osd_highlight_choice_row(settings->crosshair_color, 1);
  osd_draw_key_guide(1, 3);
  osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_SELECT);
}
