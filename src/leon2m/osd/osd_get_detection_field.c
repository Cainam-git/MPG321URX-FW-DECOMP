/* osd_get_detection_field  (FUN_a00a14bc)
 *
 * Return one field of the open detection setting: switch, level, row, minimum or maximum.
 *   sel: 1 switch, 2 level, 3 item row, 4 minimum, 5 maximum
 * Returns: the field value
 * Note: Chosen by the menu state (0xC0..0xC2, sliders 0xF7..0xF9); settings bytes +0x1E8..+0x1ED.
 * Name basis: derived - switch over states 0xC0..0xF9 used by the detection handlers
 *
 * Matching notes
 * --------------
 * leon2m, flags -mcpu=v8 -O3 -g. No direct callers (reached through a table).
 * Source form: both are switches with jump tables (menu state 0xc0..0xf9, sel 0..5). The case order above is the
 * one that gives the firmware's block layout, and case 0xc1 falls through into case 0xf8.
 */

/* Menu states of the three detection items of the MSI OLED Care page (on/off choice) and of their level sliders. */
enum detection_state {
    STATE_MULTI_LOGO_CHOICE = 0xc0,
    STATE_TASKBAR_CHOICE = 0xc1,
    STATE_BOUNDARY_CHOICE = 0xc2,
    STATE_MULTI_LOGO_LEVEL = 0xf7,
    STATE_TASKBAR_LEVEL = 0xf8,
    STATE_BOUNDARY_LEVEL = 0xf9
};
/* What the caller asks for (parameter sel). */
enum detection_field {
    DETECTION_SWITCH = 1,
    DETECTION_LEVEL = 2,
    DETECTION_ITEM_ROW = 3,
    DETECTION_LEVEL_MIN = 4,
    DETECTION_LEVEL_MAX = 5
};
#define USER_SETTINGS_TASKBAR_DETECTION 0x1ea   /* settings bytes +0x1EA (on/off) and +0x1EB (level) */
#define USER_SETTINGS_TASKBAR_LEVEL     0x1eb

extern unsigned int osd_menu_state;   // 0xa802afec
extern unsigned char user_settings[]; // base 0xa802d290
extern unsigned char user_settings_multi_logo_detection;   // 0xa802d478
extern unsigned char user_settings_multi_logo_level;   // 0xa802d479
extern unsigned char user_settings_boundary_detection;   // 0xa802d47c
extern unsigned char user_settings_boundary_level;   // 0xa802d47d

/*
 * Return one field of the Multi Logo, Taskbar or Boundary Detection setting that the menu state refers to.
 * sel: DETECTION_SWITCH (the on/off byte), DETECTION_LEVEL (the level byte), DETECTION_ITEM_ROW (row of the item on
 * the OLED Care page: 4 Multi Logo, 5 Taskbar, 6 Boundary), DETECTION_LEVEL_MIN, DETECTION_LEVEL_MAX (level range
 * 1..2 for Multi Logo, 1..3 for the other two). A field the menu state does not provide, any other menu state and
 * any other sel give 0.
 * The choice state of Taskbar (0xC1) provides the switch and the item row and then falls through into its level
 * slider case, so it also provides the level and the range; the Multi Logo and Boundary choice states provide only
 * the switch and the item row.
 */
unsigned char osd_get_detection_field(unsigned char sel)
{
    unsigned int switch_value = 0, level = 0, item_row = 0, level_min = 0, level_max = 0;

    switch (osd_menu_state) {
    case STATE_MULTI_LOGO_CHOICE:
        switch_value = user_settings_multi_logo_detection;
        item_row = 4;
        break;
    case STATE_BOUNDARY_CHOICE:
        switch_value = user_settings_boundary_detection;
        item_row = 6;
        break;
    case STATE_MULTI_LOGO_LEVEL:
        level = user_settings_multi_logo_level;
        level_min = 1;
        level_max = 2;
        break;
    case STATE_TASKBAR_CHOICE:
        switch_value = user_settings[USER_SETTINGS_TASKBAR_DETECTION];
        item_row = 5;
        /* falls through: the level of Taskbar Detection is provided too */
    case STATE_TASKBAR_LEVEL:
        level = user_settings[USER_SETTINGS_TASKBAR_LEVEL];
        level_min = 1;
        level_max = 3;
        break;
    case STATE_BOUNDARY_LEVEL:
        level = user_settings_boundary_level;
        level_min = 1;
        level_max = 3;
        break;
    default:
        return 0;
    }
    switch (sel) {
    case DETECTION_SWITCH: return switch_value;
    case DETECTION_LEVEL: return level;
    case DETECTION_ITEM_ROW: return item_row;
    case DETECTION_LEVEL_MIN: return level_min;
    case DETECTION_LEVEL_MAX: return level_max;
    default: return 0;
    }
}
