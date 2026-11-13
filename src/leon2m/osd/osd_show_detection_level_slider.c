/* osd_show_detection_level_slider  (FUN_a00a1a68)
 *
 * Open the level slider of the open detection setting.
 * Note: States 0xC0..0xC2 -> 0xF7..0xF9; prints 'State 1/2/3'; slider value in 0xA8025C55.
 * Name basis: derived - called by the accept and right-key routines of states 0xC0..0xC2
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a1a68 @ 0xa00a1a68, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: osd_get_detection_field is a static copy written with the cases in the
 * order 0xF7, 0xC0, 0xC1 (into 0xF8), 0xC2, 0xF9 and the levels of 0xF7 / 0xF9 read through the named bytes
 * user_settings_multi_logo_level / user_settings_boundary_level; the compiler inlines it five times.
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
extern unsigned int osd_menu_state;
extern unsigned char user_settings[];
extern unsigned char user_settings_multi_logo_level;
extern unsigned char user_settings_boundary_level;
extern unsigned char osd_choice_row;
extern int dbg_printf();
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_clear_choice_column(void);
extern void osd_draw_detection_level_slider(unsigned char, unsigned char, unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_choice_notes(unsigned char, int);

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
    case MENU_STATE_MULTI_LOGO_LEVEL:
        level = user_settings_multi_logo_level;
        level_min = 1;
        level_max = 2;
        break;
    case MENU_STATE_MULTI_LOGO_CHOICES:
        enabled = user_settings[SETTINGS_MULTI_LOGO_DETECTION];
        item_row = OLED_CARE_ITEM_MULTI_LOGO;
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
        level = user_settings_boundary_level;
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
 * Open the level slider of the detection setting whose choice list is open.
 *
 * The choice highlight and the choice column are cleared. The menu state moves from the choices state to the
 * slider state of the same setting (0xC0 -> 0xF7, 0xC1 -> 0xF8, 0xC2 -> 0xF9) and prints "State 1", "State 2" or
 * "State 3". The slider is drawn at the stored level of the setting (read from the settings record, not from
 * osd_edit_value); its bar position is the level scaled from the setting's range
 * (DETECT_LEVEL_MIN..DETECT_LEVEL_MAX) to 1..100. Last the notes under the list are drawn for the new state.
 * Called by the OK handlers of the three settings, which copy the stored level to osd_edit_value first.
 */
void osd_show_detection_level_slider(void)
{
    osd_clear_choice_highlight(osd_choice_row);
    osd_clear_choice_column();
    switch (osd_menu_state) {
    case MENU_STATE_MULTI_LOGO_CHOICES:
        dbg_printf("State 1  \r\n");
        osd_menu_state = MENU_STATE_MULTI_LOGO_LEVEL;
        break;
    case MENU_STATE_TASKBAR_CHOICES:
        dbg_printf("State 2  \r\n");
        osd_menu_state = MENU_STATE_TASKBAR_LEVEL;
        break;
    case MENU_STATE_BOUNDARY_CHOICES:
        dbg_printf("State 3  \r\n");
        osd_menu_state = MENU_STATE_BOUNDARY_LEVEL;
        break;
    }
    /* The slider value comes from osd_get_detection_field(DETECT_LEVEL), the stored level of the new state. */
    osd_draw_detection_level_slider(1, 99 * (osd_get_detection_field(DETECT_LEVEL) - osd_get_detection_field(DETECT_LEVEL_MIN)) / (osd_get_detection_field(DETECT_LEVEL_MAX) - osd_get_detection_field(DETECT_LEVEL_MIN)) + 1,
                 osd_get_detection_field(DETECT_LEVEL));
    osd_highlight_choice_row(0, 1);
    osd_draw_choice_notes(osd_menu_state, 0);
}
