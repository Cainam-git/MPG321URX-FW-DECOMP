/* osd_enter_detection_choices  (FUN_a00a13d8)
 *
 * Open the OFF/ON/level choice of the highlighted OLED Care detection item.
 * Note: Item 0x38..0x3A -> state 0xC0..0xC2; Multi Logo (0xC0), Taskbar (0xC1), Boundary (0xC2) Detection.
 * Name basis: derived - handler table 0xA802422C: OK/right on states 0x38..0x3A; OLED Care items texts
 *   0x185BC0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a13d8, flags -mcpu=v8 -O3 -g. No direct callers (reached through the key handler table).
 * Source form: the three cases store the menu state and the choice row in different orders (case 0x39 reads the
 * stored value first); the item row argument is written as state - 52.
 */
extern unsigned int osd_menu_state;
extern unsigned char osd_choice_row;
extern unsigned char user_settings_multi_logo_detection, user_settings_taskbar_detection, user_settings_boundary_detection;
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_choice_mark(int, unsigned char, int);

/* Menu states of the OLED Care items (0x34 + item row) and of their OFF / ON / level choices. */
#define MENU_STATE_MULTI_LOGO_ITEM      0x38
#define MENU_STATE_TASKBAR_ITEM         0x39
#define MENU_STATE_BOUNDARY_ITEM        0x3a
#define MENU_STATE_MULTI_LOGO_CHOICES   0xc0
#define MENU_STATE_TASKBAR_CHOICES      0xc1
#define MENU_STATE_BOUNDARY_CHOICES     0xc2

#define HIGHLIGHT_ITEM_LIST_OPEN  2     /* osd_highlight_item_row mode: the item's choice list is open */
#define CHOICE_ROW_EDGED          1     /* osd_highlight_choice_row style: with edge glyphs */
#define CHOICE_MARK_LIST          1     /* osd_draw_choice_mark: mark in a choice list */
#define CHOICE_MARK_OFF           0

/*
 * OK or right on the Multi Logo, Taskbar or Boundary Detection item of the OLED Care page (menu states 0x38 to
 * 0x3A): open the choices of that item (OFF, ON, level; menu states 0xC0 to 0xC2).
 *
 * The cursor goes to the stored choice of the item (osd_choice_row is the detection setting: 0 OFF, 1 ON, 2
 * level), whose row is highlighted with edge glyphs and whose mark is cleared. Any other menu state leaves the
 * state and the row as they are.
 */
void osd_enter_detection_choices(void)
{
    osd_highlight_item_row(osd_menu_state - 52, HIGHLIGHT_ITEM_LIST_OPEN);
    switch (osd_menu_state) {
    case MENU_STATE_MULTI_LOGO_ITEM:
        osd_menu_state = MENU_STATE_MULTI_LOGO_CHOICES;
        osd_choice_row = user_settings_multi_logo_detection;
        break;
    case MENU_STATE_TASKBAR_ITEM:
        osd_choice_row = user_settings_taskbar_detection;
        osd_menu_state = MENU_STATE_TASKBAR_CHOICES;
        break;
    case MENU_STATE_BOUNDARY_ITEM:
        osd_menu_state = MENU_STATE_BOUNDARY_CHOICES;
        osd_choice_row = user_settings_boundary_detection;
        break;
    }
    osd_highlight_choice_row(osd_choice_row, CHOICE_ROW_EDGED);
    osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row, CHOICE_MARK_OFF);
}
