/* osd_increase_detection_level  (FUN_a00a1cf0)
 *
 * Raise the detection level on the slider one step (right key)
 * Note: Up to the maximum from osd_get_detection_field.
 * Name basis: derived - handler table 0xA802422C: right on states 0xF7..0xF9
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a1cf0 @ 0xa00a1cf0, flags -mcpu=v8 -O3 -g.
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
extern unsigned char osd_edit_value;
extern void osd_draw_detection_level_slider(unsigned char, unsigned char, unsigned char);

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
 * Right key on a detection level slider: raise the level by one, up to the maximum of the setting
 * (Multi Logo 2, Taskbar and Boundary 3), and redraw the slider.
 *
 * The level is edited in osd_edit_value; this routine does not write the settings record.
 * The bar position drawn is the level scaled from DETECT_LEVEL_MIN..DETECT_LEVEL_MAX to 1..100.
 * Reached through the key table for the states 0xF7..0xF9.
 */
void osd_increase_detection_level(void)
{
    osd_edit_value++;
    if (osd_edit_value > osd_get_detection_field(DETECT_LEVEL_MAX))
        osd_edit_value = osd_get_detection_field(DETECT_LEVEL_MAX);
    osd_draw_detection_level_slider(1, 99 * (osd_edit_value - osd_get_detection_field(DETECT_LEVEL_MIN)) / (osd_get_detection_field(DETECT_LEVEL_MAX) - osd_get_detection_field(DETECT_LEVEL_MIN)) + 1,
                 osd_edit_value);
}
