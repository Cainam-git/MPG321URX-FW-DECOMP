/* osd_update_crosshair_color  (FUN_a00ba184)
 *
 * Recolour the crosshair, picking a contrasting colour in automatic mode.
 *   force: 1 = recolour even when unchanged
 * Note: Colour mode = settings byte +0x17B (2 = automatic: hue under the crosshair + 180 degrees); last choice
 *   0xA802B090.
 * Name basis: derived - uses lib_rgb_to_hue of the zone average; callers osd_accept_crosshair_color,
 *   osd_run_periodic_task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ba184 @ 0xa00ba184-0xa00ba3e8 (153 words), flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: old-style (K&R) definition, so force arrives as int and is masked
 * where it is used; idx is an unsigned short; the 24-entry table is copied to the stack first (memcpy of 0x30
 * bytes) and read from the copy; the second test of v against 0xffff (after v is set to 180) stays.
 */
#define CROSSHAIR_LAYER        1        /* menu layer that holds the crosshair icon */
#define ICON_COLUMNS           4        /* the icon is 4 cells wide and 3 rows high */
#define ICON_ROWS              3
#define CROSSHAIR_COLOR_AUTO   2        /* settings crosshair colour: follow the picture */
#define CELL_COLOR_FIRST       0x1702   /* cell value of the icon for colour 1 */
#define CELL_COLOR_OTHER       0x1802   /* cell value of the icon for every other fixed colour */
#define COLOR_STEPS            24       /* colour wheel steps of 15 degrees */
#define DEGREES_PER_STEP       15
#define HUE_NONE               0xffff   /* lib_rgb_to_hue: grey, no hue */
#define HUE_OPPOSITE_STEPS     12       /* 180 degrees */

/* The user settings fields used here. */
struct user_settings_record {
    unsigned char p000[0x17b];
    unsigned char crosshair_color;              /* +0x17B: 2 = automatic */
    unsigned char p17c[0x190 - 0x17c];
    unsigned char crosshair_icon;               /* +0x190: icon 1..6; 0 = none */
};
extern struct user_settings_record user_settings;
extern unsigned char osd_crosshair_color_step, osd_crosshair_icon_last;
extern const unsigned short osd_crosshair_color_table[24];
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern void osd_get_crosshair_zone_range(unsigned char *p1, unsigned char *p2, unsigned char *p3, unsigned char *p4);
extern void pq_average_zone_color(int *a, int *b, int *c, unsigned char d, unsigned char e, unsigned char f, unsigned char g);
extern unsigned short lib_rgb_to_hue(short a, short b, short c);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);

/*
 * Colour the Smart Crosshair icon (settings crosshair_icon) according to the colour setting.
 *
 *   force  1: recolour in automatic mode even if the new colour is the one already shown
 *
 * Does nothing while no icon is chosen (crosshair_icon is 0). Colour 1 fills the icon's cells with 0x1702, any
 * other fixed colour except 2 with 0x1802. In automatic mode (2) the average colour of the picture zones
 * around the crosshair is turned into a hue; the icon gets the colour of the opposite hue (180 degrees
 * further) from a table of 24 cell values, one per 15 degrees; a grey (no hue) counts as 180 degrees. The
 * icon is recoloured when force is set, when the new step is more than one step (on the circle of 24) from
 * the last applied step osd_crosshair_color_step, when no step was stored (0), or when the icon differs from
 * the one stored in osd_crosshair_icon_last. The new step and the icon are then stored.
 *
 * Called from osd_accept_crosshair_color and osd_run_periodic_task, among others.
 */
void osd_update_crosshair_color(force)
    unsigned char force;
{
    unsigned short colors[COLOR_STEPS];
    unsigned char zone_first, zone_last, zone_third, zone_fourth;  /* ranges from osd_get_crosshair_zone_range */
    int red = 0, green = 0, blue = 0;           /* zone averages */
    unsigned char i, distance;
    unsigned short step;                        /* new colour step 0..23 */
    unsigned short hue, hue_step;

    memcpy(colors, osd_crosshair_color_table, 0x30);
    if (user_settings.crosshair_icon == 0)
        return;
    if (user_settings.crosshair_color == CROSSHAIR_COLOR_AUTO) {
        osd_get_crosshair_zone_range(&zone_first, &zone_last, &zone_third, &zone_fourth);
        pq_average_zone_color(&red, &green, &blue, zone_first, zone_last, zone_third, zone_fourth);
        hue = lib_rgb_to_hue(red, green, blue);
        if (hue == HUE_NONE)
            hue = 180;
        if (hue == HUE_NONE)
            return;
        hue_step = hue / DEGREES_PER_STEP;
        step = (hue_step + HUE_OPPOSITE_STEPS) % COLOR_STEPS;
        /* Distance to the last applied step, the short way round the circle. */
        if (osd_crosshair_color_step < step)
            distance = step - osd_crosshair_color_step;
        else if (osd_crosshair_color_step > step)
            distance = osd_crosshair_color_step - step;
        else
            distance = 0;
        if (distance > 0xb)
            distance = COLOR_STEPS - distance;
        if (force != 0 || distance > 1 || osd_crosshair_color_step == 0 || user_settings.crosshair_icon != osd_crosshair_icon_last) {
            hue = colors[step];
            for (i = 0; i <= ICON_ROWS - 1; i++)
                osd_api_fill_cells(0, i, ICON_COLUMNS, hue, CROSSHAIR_LAYER);
            osd_crosshair_color_step = step;
            osd_crosshair_icon_last = user_settings.crosshair_icon;
        }
    } else if (user_settings.crosshair_color == 1) {
        for (i = 0; i <= ICON_ROWS - 1; i++)
            osd_api_fill_cells(0, i, ICON_COLUMNS, CELL_COLOR_FIRST, CROSSHAIR_LAYER);
    } else {
        for (i = 0; i <= ICON_ROWS - 1; i++)
            osd_api_fill_cells(0, i, ICON_COLUMNS, CELL_COLOR_OTHER, CROSSHAIR_LAYER);
    }
}
