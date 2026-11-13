/* pq_api_get_zone_average_table  (FUN_a014aa48)
 *
 * Return the red (0), green (1) or blue (2) table of the 16 x 16 zone averages.
 * Returns: table address
 * Note: Any value other than 1 or 2 gives the red table.
 * Name basis: derived - returns one of the three tables pq_read_zone_color_averages fills;
 *   pq_average_zone_color sums them as red, green and blue for lib_rgb_to_hue
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014aa48, flags -mcpu=v8 -O3 -g.
 * Source form: a switch that sets a pointer local, returned after the switch.
 */
extern unsigned char pq_zone_averages_blue[], pq_zone_averages_green[], pq_zone_averages_red[];

#define RGB_GREEN 1
#define RGB_BLUE  2

/*
 * Return one of the three 256-byte tables that pq_read_zone_color_averages fills with zone averages (16 rows of
 * 16 zones).
 *
 *   color  RGB_GREEN: pq_zone_averages_green; RGB_BLUE: pq_zone_averages_blue; any other value (red is 0):
 *          pq_zone_averages_red
 *
 * The only caller, pq_average_zone_color, asks for 0, 1 and 2 and adds them up as the red, green and blue
 * averages of the zones around the crosshair.
 */
unsigned char *pq_api_get_zone_average_table(unsigned char color)
{
    unsigned char *table;

    switch (color) {
    case RGB_GREEN:
        table = pq_zone_averages_green;
        break;
    case RGB_BLUE:
        table = pq_zone_averages_blue;
        break;
    default:
        table = pq_zone_averages_red;
        break;
    }
    return table;
}
