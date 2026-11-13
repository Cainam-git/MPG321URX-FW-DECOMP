/* osd_get_crosshair_zone_range  (FUN_a00ba068)
 *
 * Work out which picture zones lie around the crosshair position.
 *   first_column: out: first column
 *   first_row: out: first row
 *   last_column: out: last column
 *   last_row: out: last row
 * Note: Position = settings halfwords +0x1AC/+0x1AE; zone size = panel size / 16.
 * Name basis: derived - only caller osd_update_crosshair_color
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ba068 @ 0xa00ba068-0xa00ba184 (71 words), flags -mcpu=v8 -O3 -g.
 * Source form: the two crosshair halfwords are members of the user settings record (offsets 0x1ac and 0x1ae);
 * all four results are bytes; the quotient is an unsigned char.
 */
#define CROSSHAIR_X_OFFSET    30                /* added to the crosshair x before the zone is found */
#define CROSSHAIR_Y_OFFSET    36                /* added to the crosshair y */
#define ZONE_SHIFT            4                 /* zone size = active panel size >> 4 (16 zones each way) */
#define ZONE_COUNT            16
#define PANEL_SIZE_WIDTH      0                 /* selector of panel_api_get_active_size */
#define PANEL_SIZE_HEIGHT     1

struct user_settings_record {
    unsigned char pad[0x1ac];
    unsigned short crosshair_x;                 /* +0x1AC */
    unsigned short crosshair_y;                 /* +0x1AE */
};
extern struct user_settings_record user_settings;
extern unsigned short panel_api_get_active_size(int);

/*
 * Find the zones of the picture that the crosshair position touches, in a grid of 16 x 16 zones.
 *
 *   first_column, first_row, last_column, last_row   results (zone numbers 0..15)
 *
 * The position is the crosshair x and y of the settings (+0x1AC, +0x1AE) plus 30 and 36. Each is divided by
 * the zone size (active panel width or height >> 4, with half a zone added before the division). With q the
 * quotient: for 0 both zones are 0; for 16 both are 15; otherwise the zones are q - 1 and q.
 * For the row, a quotient of 0 gives last_row the value just stored in first_column (not 0).
 * Called by osd_update_crosshair_color.
 */
void osd_get_crosshair_zone_range(unsigned char *first_column, unsigned char *first_row, unsigned char *last_column, unsigned char *last_row)
{
    unsigned short x, y, zone_width, zone_height;
    unsigned char q;

    x = user_settings.crosshair_x + CROSSHAIR_X_OFFSET;
    y = user_settings.crosshair_y + CROSSHAIR_Y_OFFSET;
    zone_width = panel_api_get_active_size(PANEL_SIZE_WIDTH) >> ZONE_SHIFT;
    zone_height = panel_api_get_active_size(PANEL_SIZE_HEIGHT) >> ZONE_SHIFT;
    q = (x + zone_width / 2) / zone_width;
    if (q == 0) {
        *first_column = q;
        *last_column = q;
    } else if (q == ZONE_COUNT) {
        *first_column = q - 1;
        *last_column = q - 1;
    } else {
        *first_column = q - 1;
        *last_column = q;
    }
    q = (y + zone_height / 2) / zone_height;
    if (q == 0) {
        *first_row = q;
        *last_row = *first_column;
    } else if (q == ZONE_COUNT) {
        *first_row = q - 1;
        *last_row = q - 1;
    } else {
        *first_row = q - 1;
        *last_row = q;
    }
}
