/* pq_average_zone_color  (FUN_a00b9f30)
 *
 * Average the red, green and blue zone statistics over a rectangle of zones.
 *   red: in: start value, the red zone sum is added to it; out: the average red value
 *   green: in: start value, the green zone sum is added to it; out: the average green value
 *   blue: in: start value, the blue zone sum is added to it; out: the average blue value
 *   first_column
 *   first_row
 *   last_column
 *   last_row
 * Note: Zones form a 16 x 16 grid (pq_api_get_zone_average_table 0 / 1 / 2).
 * Name basis: derived - sums three 256-entry byte tables over x0..x1, y0..y1; caller
 *   osd_update_crosshair_color
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b9f30 @ 0xa00b9f30-0xa00ba068 (78 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: first_column, first_row and last_column are int parameters
 * converted to unsigned char where they are used; last_row (the seventh argument, passed on the stack) is an
 * unsigned char parameter. The zone count comes from an inlined static helper zone_count() with unsigned char
 * parameters and an int result, so each operand is masked separately.
 */

#define ZONE_COUNT        0x100     /* 16 rows of 16 zones, one byte per zone */
#define ZONE_ROW_SHIFT    4         /* zone index = row * 16 + column */
#define ZONE_COLUMN_MASK  0xf

extern unsigned char *pq_api_get_zone_average_table(int);

/* Number of zones in the rectangle. */
static int zone_count(unsigned char first_column, unsigned char first_row, unsigned char last_column, unsigned char last_row)
{
    return (last_column - first_column + 1) * (last_row - first_row + 1);
}

/*
 * Add up the red, green and blue averages of the zones in a rectangle of the 16 x 16 zone grid and divide
 * each sum by the number of zones. The three sums are added to what *red, *green and *blue already hold;
 * the only caller, osd_update_crosshair_color, starts them at 0 and passes the zones around the crosshair
 * (osd_get_crosshair_zone_range) to pick a contrasting crosshair colour.
 *   red, green, blue           in: start values; out: the averages
 *   first_column, first_row    top-left zone of the rectangle
 *   last_column, last_row      bottom-right zone, included
 */
void pq_average_zone_color(unsigned int *red, unsigned int *green, unsigned int *blue, int first_column, int first_row, int last_column, unsigned char last_row)
{
    unsigned char *red_zones = pq_api_get_zone_average_table(0);
    unsigned char *green_zones = pq_api_get_zone_average_table(1);
    unsigned char *blue_zones = pq_api_get_zone_average_table(2);
    unsigned short i, zones;

    zones = zone_count(first_column, first_row, last_column, last_row);
    for (i = 0; i < ZONE_COUNT; i++) {
        if ((unsigned char)first_row <= (unsigned)(i >> ZONE_ROW_SHIFT) && (unsigned)(i >> ZONE_ROW_SHIFT) <= last_row &&
            (unsigned char)first_column <= (unsigned)(i & ZONE_COLUMN_MASK) && (unsigned char)last_column >= (unsigned)(i & ZONE_COLUMN_MASK)) {
            *red += red_zones[i];
            *green += green_zones[i];
            *blue += blue_zones[i];
        }
    }
    *red /= zones;
    *green /= zones;
    *blue /= zones;
}
