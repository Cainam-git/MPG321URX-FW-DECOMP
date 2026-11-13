/* ddc_tool_set_fill_or_inspection  (FUN_a00d25f4)
 *
 * Tool command: show a fill colour or select the panel's inspection mode and pattern.
 * Name basis: derived - oled_set_inspection_mode / _pattern, pq_api_set_fill_color and brightness
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d25f4 @ 0xa00d25f4, flags -mcpu=v8 -O3 -g (also matches with -msoft-float).
 * Source form: the saved Contrast byte is a local declared inside the white-fill branch; the inspection
 * choices are an if / else-if chain on a local copy of request byte 7, one arm per value.
 */

/* The one field of the user settings record (docs/RECORDS.md) used here. */
struct user_settings_record {
    unsigned char pad000[0xa];
    unsigned char contrast;                     /* +0x0A: Contrast */
};
extern void pq_api_set_fill_color();
extern void pq_api_set_color_triple(unsigned short red, unsigned short green, unsigned short blue);
extern void SetBrightness(unsigned short level);
extern void pq_user_apply_color_gain(void);
extern void sys_api_restart_channel_at_level(int channel, int level);
extern void sys_user_apply_brightness(void);
extern void pq_user_apply_color_settings(void);
extern void oled_set_inspection_mode(unsigned char on);
extern void oled_set_inspection_pattern(unsigned char pattern);
extern struct user_settings_record user_settings;

#define TOOL_RESULT_DONE     0xe0               /* the command was carried out */

/* Request byte 6: what the command is about. */
#define TOOL_TARGET_FILL       0                /* byte 7: FILL_WHITE or FILL_OFF */
#define TOOL_TARGET_INSPECTION 1                /* byte 7: INSPECTION_OFF, or a pattern choice 1..7 */
#define FILL_OFF               0
#define FILL_WHITE             1
#define INSPECTION_OFF         0

#define MAIN_CHANNEL         0                  /* channel 0: the main picture */
#define SECOND_CHANNEL       1
#define RESTART_LEVEL_1      1                  /* sys_api_restart_channel_at_level */
#define COLOR_FULL           0xff               /* white: 0xFF for red, green and blue */
#define FILL_BLANK_FIRST     1                  /* pq_api_set_fill_color: blank the picture block first */
#define COLOR_GAIN_FULL      0x100              /* all three matrix gains, as ShowLogo sets them */
#define LEVEL_MAX            0x3ff              /* SetBrightness: the highest panel level */
#define OLED_INSPECTION_ON   1                  /* oled_set_inspection_mode argument */
#define OLED_INSPECTION_OFF  0

/*
 * Factory tool command 0x72 (TOOL_CMD_FILL_OR_INSPECTION): show a white screen, or switch the OLED panel's
 * inspection mode and pick its pattern.
 *
 *   request  the tool request; byte 6 = TOOL_TARGET_FILL or TOOL_TARGET_INSPECTION, byte 7 = the choice
 *
 * TOOL_TARGET_FILL:
 *   FILL_WHITE  channel 0 is filled with white (blanking its picture block first), the three colour matrix
 *               gains go to 0x100 and the panel level to LEVEL_MAX. pq_user_apply_color_gain then applies the
 *               Contrast setting; that routine limits the setting byte to 100 and writes it back, and this
 *               routine puts the byte back as it was before the call.
 *   FILL_OFF    channels 0 and 1 are restarted at level 1, then Brightness, Contrast and the colour settings
 *               are applied again from the user settings.
 * TOOL_TARGET_INSPECTION:
 *   0     the panel's inspection mode is switched off;
 *   1..6  inspection mode on and pattern 1..6;
 *   7     inspection mode on and pattern 0.
 * Any other value of byte 6 or byte 7 does nothing. Nothing is saved.
 *
 * Returns TOOL_RESULT_DONE in every case. Called by ddc_tool_dispatch_command; the factory menu
 * (osd_factory_increase_value / _decrease_value) is the other place that sets the inspection pattern.
 */
int ddc_tool_set_fill_or_inspection(unsigned char *request)
{
    if (request[6] == TOOL_TARGET_FILL) {
        if (request[7] == FILL_WHITE) {
            unsigned char contrast;
            pq_api_set_fill_color(MAIN_CHANNEL, COLOR_FULL, COLOR_FULL, COLOR_FULL, FILL_BLANK_FIRST);
            pq_api_set_color_triple(COLOR_GAIN_FULL, COLOR_GAIN_FULL, COLOR_GAIN_FULL);
            SetBrightness(LEVEL_MAX);
            /* Keep the Contrast byte exactly as it is across the call. */
            contrast = user_settings.contrast;
            pq_user_apply_color_gain();
            user_settings.contrast = contrast;
        } else if (request[7] == FILL_OFF) {
            sys_api_restart_channel_at_level(MAIN_CHANNEL, RESTART_LEVEL_1);
            sys_api_restart_channel_at_level(SECOND_CHANNEL, RESTART_LEVEL_1);
            sys_user_apply_brightness();
            pq_user_apply_color_gain();
            pq_user_apply_color_settings();
        }
    } else if (request[6] == TOOL_TARGET_INSPECTION) {
        unsigned char choice = request[7];
        if (choice == INSPECTION_OFF) {
            oled_set_inspection_mode(OLED_INSPECTION_OFF);
        } else if (choice == 1) {
            oled_set_inspection_mode(OLED_INSPECTION_ON); oled_set_inspection_pattern(1);
        } else if (choice == 2) {
            oled_set_inspection_mode(OLED_INSPECTION_ON); oled_set_inspection_pattern(2);
        } else if (choice == 3) {
            oled_set_inspection_mode(OLED_INSPECTION_ON); oled_set_inspection_pattern(3);
        } else if (choice == 4) {
            oled_set_inspection_mode(OLED_INSPECTION_ON); oled_set_inspection_pattern(4);
        } else if (choice == 5) {
            oled_set_inspection_mode(OLED_INSPECTION_ON); oled_set_inspection_pattern(5);
        } else if (choice == 6) {
            oled_set_inspection_mode(OLED_INSPECTION_ON); oled_set_inspection_pattern(6);
        } else if (choice == 7) {
            /* The last choice selects pattern 0. */
            oled_set_inspection_mode(OLED_INSPECTION_ON); oled_set_inspection_pattern(0);
        }
    }
    return TOOL_RESULT_DONE;
}
