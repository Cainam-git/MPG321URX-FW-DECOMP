/* osd_leave_detection_choices  (FUN_a00a192c)
 *
 * Leave the detection choices and return to the OLED Care item (left key)
 * Note: Returns to state 0x34 + item row.
 * Name basis: derived - handler table 0xA802422C: left on states 0xC0..0xC2
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a192c @ 0xa00a192c, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: osd_get_detection_field is a static copy written with the cases in
 * ascending record-offset order (0xC0, 0xF7, 0xC1 into 0xF8, 0xC2, 0xF9; all values read as bytes of
 * user_settings); the compiler inlines it twice.
 */

/* Menu states of the three detection settings of the OLED Care page. In a choices state the list has three rows:
 * OFF, ON and the level; the level is set on a slider state. */
enum {
    MENU_STATE_MULTI_LOGO_CHOICES = 0xC0,
    MENU_STATE_TASKBAR_CHOICES    = 0xC1,
    MENU_STATE_BOUNDARY_CHOICES   = 0xC2,
    MENU_STATE_MULTI_LOGO_LEVEL   = 0xF7,
    MENU_STATE_TASKBAR_LEVEL      = 0xF8,
    MENU_STATE_BOUNDARY_LEVEL     = 0xF9
};

/* The state of an item row of the OLED Care page is PAGE_OLED_CARE_ITEMS + the row. */
#define PAGE_OLED_CARE_ITEMS            0x34
#define OLED_CARE_ITEM_MULTI_LOGO       4
#define OLED_CARE_ITEM_TASKBAR          5
#define OLED_CARE_ITEM_BOUNDARY         6

/* Bytes of the user settings record (docs/RECORDS.md). */
#define SETTINGS_MULTI_LOGO_DETECTION   0x1e8
#define SETTINGS_MULTI_LOGO_LEVEL       0x1e9
#define SETTINGS_TASKBAR_DETECTION      0x1ea
#define SETTINGS_TASKBAR_LEVEL          0x1eb
#define SETTINGS_BOUNDARY_DETECTION     0x1ec
#define SETTINGS_BOUNDARY_LEVEL         0x1ed

/* What osd_get_detection_field returns. */
enum {
    DETECT_ENABLED   = 1,   /* the on/off byte (0 off, 1 on) */
    DETECT_LEVEL     = 2,   /* the level byte */
    DETECT_ITEM_ROW  = 3,   /* row of the setting in the OLED Care item list */
    DETECT_LEVEL_MIN = 4,   /* lowest level */
    DETECT_LEVEL_MAX = 5    /* highest level */
};

/* Arguments of the menu drawing routines. */
#define CHOICE_MARK_LIST        1       /* osd_draw_choice_mark: the mark in a choice list (0 = in the item list) */
#define CHOICE_MARK_ON          1
#define CHOICE_MARK_OFF         0
#define CHOICE_ROW_PLAIN        0       /* osd_highlight_choice_row: plain highlight */
#define CHOICE_ROW_EDGED        1       /* highlight with edge glyphs */
#define HIGHLIGHT_ITEM_ACTIVE   1       /* osd_highlight_item_row: the cursor is in the item list */
extern unsigned int osd_menu_state;   // 0xa802afec
extern unsigned char user_settings[]; // base 0xa802d290
extern unsigned char osd_choice_row;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_update_key_guide(unsigned int, unsigned int);

/* Return one value of the detection setting that the menu state names.
 * Multi Logo is state 0xC0 (choices) / 0xF7 (level slider), Taskbar 0xC1 / 0xF8, Boundary 0xC2 / 0xF9; any other
 * state gives 0. A choices state fills the on/off byte and the item row; a slider state fills the level and its
 * range (Multi Logo 1..2, the other two 1..3). Taskbar choices (0xC1) continue into the Taskbar slider case, so
 * they give the level and range as well. `which` is one of the DETECT_ constants.
 * The firmware has this routine once (osd_get_detection_field); each file that uses it carries its own copy of the
 * source, because the compiler inlines it and the case order below is what builds to the firmware's bytes. */
static unsigned char osd_get_detection_field(unsigned char which)
{
    unsigned int enabled = 0, level = 0, item_row = 0, level_min = 0, level_max = 0;

    switch (osd_menu_state) {
    case MENU_STATE_MULTI_LOGO_CHOICES:
        enabled = user_settings[SETTINGS_MULTI_LOGO_DETECTION];
        item_row = OLED_CARE_ITEM_MULTI_LOGO;
        break;
    case MENU_STATE_MULTI_LOGO_LEVEL:
        level = user_settings[SETTINGS_MULTI_LOGO_LEVEL];
        level_min = 1;
        level_max = 2;
        break;
    case MENU_STATE_TASKBAR_CHOICES:
        enabled = user_settings[SETTINGS_TASKBAR_DETECTION];
        item_row = OLED_CARE_ITEM_TASKBAR;
        /* continues into the Taskbar slider case */
    case MENU_STATE_TASKBAR_LEVEL:
        level = user_settings[SETTINGS_TASKBAR_LEVEL];
        level_min = 1;
        level_max = 3;
        break;
    case MENU_STATE_BOUNDARY_CHOICES:
        enabled = user_settings[SETTINGS_BOUNDARY_DETECTION];
        item_row = OLED_CARE_ITEM_BOUNDARY;
        break;
    case MENU_STATE_BOUNDARY_LEVEL:
        level = user_settings[SETTINGS_BOUNDARY_LEVEL];
        level_min = 1;
        level_max = 3;
        break;
    default:
        return 0;
    }
    switch (which) {
    case DETECT_ENABLED:   return enabled;
    case DETECT_LEVEL:     return level;
    case DETECT_ITEM_ROW:  return item_row;
    case DETECT_LEVEL_MIN: return level_min;
    case DETECT_LEVEL_MAX: return level_max;
    default: return 0;
    }
}

/*
 * Left key in a detection choice list: leave the list without changing the setting and go back to the
 * OLED Care item list.
 *
 * The highlight of the cursor row is removed, the mark of the stored choice is drawn again, and the menu state
 * becomes the item row of the open setting (PAGE_OLED_CARE_ITEMS + item row: Multi Logo 4, Taskbar 5, Boundary 6).
 * That item row is highlighted as the active row and the standard key guide is drawn.
 * Reached through the key table for the states 0xC0..0xC2.
 */
void osd_leave_detection_choices(void)
{
    osd_clear_choice_highlight(osd_choice_row);
    osd_draw_choice_mark(CHOICE_MARK_LIST, osd_get_detection_field(DETECT_ENABLED), CHOICE_MARK_ON);
    osd_menu_state = osd_get_detection_field(DETECT_ITEM_ROW) + PAGE_OLED_CARE_ITEMS;
    osd_highlight_item_row(osd_menu_state - PAGE_OLED_CARE_ITEMS, HIGHLIGHT_ITEM_ACTIVE);
    osd_draw_key_guide(1, 2);
    osd_update_key_guide(0, 1);
}
