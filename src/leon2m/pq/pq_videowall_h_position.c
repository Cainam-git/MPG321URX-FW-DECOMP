/* pq_videowall_h_position  (FUN_a0082c5c)
 *
 * Compute the horizontal crop start and width of this monitor's video-wall tile.
 *   channel
 *   width_out: out: width
 *   start_out: out: start
 * Note: Wall size and order from settings bytes +0x37 / +0x39.
 * Name basis: proven - text 'VideoWall H num %d order %d'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0082c5c @ 0xa0082c5c-0xa0082dc4 (90 words), flags -mcpu=v8 -O3 -g.
 * Source forms, each point read from the firmware code:
 * - input_width is widened once (0xa0082cd4) and that value serves the division, the distance and the last
 *   compare (0xa0082d98): an int copy width_int.
 * - the doubled half is computed twice (0xa0082cf8 into the u16 tile_width for the distance, 0xa0082d20 for the
 *   width), as in pq_videowall_v_position (pq_videowall_v_position).
 * - distance is the routine's int scratch: the leftover (0xa0082d0c), then the width, set in both arms of the test
 *   (copy at 0xa0082d44, '+ 2' at 0xa0082d4c) and copied to the u16 tile_width for the product and the second
 *   print (0xa0082d54).
 * - after the second print the width is kept in kept_width and distance takes 'start - input_start'
 *   (0xa0082d84) and then the 16-bit width (widened again at 0xa0082d80 / 0xa0082d88, added at 0xa0082d90); the
 *   store at 0xa0082db4 reads kept_width.
 * - the result of the last test goes to a second u16 (copy at 0xa0082da0, 'start - 1' at 0xa0082da4): if / else
 *   into result.
 */
struct user_settings_record {
    unsigned char pad0[0x37];
    unsigned char wall_columns;   /* +0x37: number of columns in the video wall */
    unsigned char wall_rows;      /* +0x38: number of rows in the video wall */
    unsigned char tile_index;     /* +0x39: 1-based tile index in the wall */
};

/* Fields of the measured input timing (input_api_get_timing_field). */
enum {
    TIMING_WIDTH   = 7,     /* horizontal size that the video-wall routine divides */
    TIMING_START_X = 11     /* horizontal start that the video-wall routine adds to */
};

extern struct user_settings_record user_settings;
extern unsigned short input_api_get_timing_field(unsigned char, unsigned int);
extern int dbg_printf(const char *fmt, ...);
extern int abs(int);

/*
 * Compute the horizontal crop start and width of this monitor's video-wall tile.
 *
 *   channel    the channel whose timing fields 7 (width) and 11 (start x) are used
 *   width_out  receives the tile width
 *   start_out  receives the tile start
 *
 * column = (tile_index - 1) % wall_columns + 1. The base width is input_width / wall_columns rounded down to
 * an even number; the leftover is |input_width - base width * wall_columns|. Columns 1 .. leftover / 2 are 2
 * wider (base + 2) and start at (base + 2) * (column - 1) + 2 * (column - 1); the other columns have the base
 * width and start at base * (column - 1) + leftover. input_start is added to the start, and the start is 1
 * less when start - input_start + width exceeds input_width. Prints the wall size and column, the values, and
 * the result.
 *
 * Caller: pq_update_input_window.
 */
void pq_videowall_h_position(unsigned char channel, unsigned short *width_out, unsigned short *start_out)
{
    unsigned char wall_columns = user_settings.wall_columns;
    unsigned char column;
    unsigned char column_offset;
    unsigned short tile_width;
    unsigned short input_width;
    unsigned short input_start;
    unsigned int half;
    int kept_width;
    unsigned short result;
    unsigned short start;
    int distance;
    int width_int;

    column = (user_settings.tile_index - 1) % wall_columns + 1;
    input_width = input_api_get_timing_field(channel, TIMING_WIDTH);
    input_start = input_api_get_timing_field(channel, TIMING_START_X);
    dbg_printf("VideoWall H num %d order %d\r\n", wall_columns, column);
    width_int = input_width;
    /* Base width: the column width rounded down to an even number; distance = the leftover pixels. */
    half = (unsigned int)(width_int / wall_columns) >> 1;
    tile_width = half << 1;
    distance = abs(width_int - tile_width * wall_columns);
    column_offset = distance;
    /* The first leftover / 2 columns take 2 extra pixels each. */
    if (column <= column_offset >> 1) {
        column_offset = column * 2 - 2;
        distance = (half << 1) + 2;
    } else
        distance = half << 1;
    tile_width = distance;
    start = tile_width * (column - 1) + column_offset + input_start;
    dbg_printf("%d %d %d %d %d\r\n", start, tile_width, column, column_offset, input_start);
    kept_width = distance;
    distance = start - input_start;
    distance += (unsigned short)kept_width;
    if (distance <= width_int)
        result = start;
    else
        result = start - 1;
    dbg_printf("%d \r\n", result);
    *width_out = kept_width;
    *start_out = result;
}
