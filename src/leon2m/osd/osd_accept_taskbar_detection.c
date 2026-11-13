/* osd_accept_taskbar_detection  (FUN_a00a23a4)
 *
 * Switch Taskbar Detection off or on as highlighted, or open its level slider (OK)
 * Note: Stores settings byte +0x1EA for rows 0 and 1 only (row 2 opens the slider); always ends with
 *   oled_user_apply_task_bar.
 * Name basis: derived - handler table 0xA802422C: OK on state 0xC1; OLED Care texts 0x185BC0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a23a4 @ 0xa00a23a4, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: osd_get_detection_field is a static copy written with the cases in
 * ascending record-offset order (0xC0, 0xF7, 0xC1 into 0xF8, 0xC2, 0xF9; all values read as bytes of
 * user_settings); the compiler inlines it twice.
 * The switch on the row gives the signed compare chain (ble / bne).
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

#define OSD_REQUEST_SETTINGS_CHANGED 0x02   /* bit of osd_request_bits */
extern unsigned char user_settings[];
extern unsigned int osd_menu_state;
extern unsigned char osd_request_bits;
extern unsigned char osd_edit_value;
extern unsigned char osd_choice_row;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_update_key_guide(unsigned int, unsigned int);
extern void osd_show_detection_level_slider(void);
extern void oled_user_apply_task_bar(void);

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
 * OK key in the Taskbar Detection choice list (state 0xC1).
 *
 * Row 0 or 1 (OFF or ON): the old mark is cleared, the row is stored in the setting byte
 * user_settings[SETTINGS_TASKBAR_DETECTION], and the menu goes back to the OLED Care item list (the state
 * becomes PAGE_OLED_CARE_ITEMS + item row 5): the new mark is drawn, the item row is highlighted and the
 * standard key guide is drawn. Row 2 (the level): the stored level is copied to osd_edit_value and the level
 * slider is opened (osd_show_detection_level_slider). After either, the setting is applied
 * (oled_user_apply_task_bar) and the settings-changed request is raised. Any other row returns at once.
 */
void osd_accept_taskbar_detection(void)
{
    switch (osd_choice_row) {
    case 0:
    case 1:
        /* Clear the mark of the old choice before the new one is stored. */
        osd_draw_choice_mark(CHOICE_MARK_LIST, osd_get_detection_field(DETECT_ENABLED), CHOICE_MARK_OFF);
        user_settings[SETTINGS_TASKBAR_DETECTION] = osd_choice_row;
        osd_clear_choice_highlight(user_settings[SETTINGS_TASKBAR_DETECTION]);
        osd_menu_state = osd_get_detection_field(DETECT_ITEM_ROW) + PAGE_OLED_CARE_ITEMS;
        osd_highlight_choice_row(osd_choice_row, CHOICE_ROW_PLAIN);
        osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row, CHOICE_MARK_ON);
        osd_highlight_item_row(osd_menu_state - PAGE_OLED_CARE_ITEMS, HIGHLIGHT_ITEM_ACTIVE);
        osd_draw_key_guide(1, 2);
        osd_update_key_guide(0, 1);
        break;
    case 2:
        osd_edit_value = user_settings[SETTINGS_TASKBAR_LEVEL];
        osd_show_detection_level_slider();
        break;
    default:
        return;
    }
    oled_user_apply_task_bar();
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
