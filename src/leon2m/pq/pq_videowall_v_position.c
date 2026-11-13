/* pq_videowall_v_position  (FUN_a0082dc4)
 *
 * Compute the vertical crop start and height of this monitor's video-wall tile.
 *   channel
 *   out_height: out: height
 *   out_start: out: start
 * Note: Wall size and order from settings bytes +0x37..+0x39.
 * Name basis: proven - text 'VideoWall V num %d order %d'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0082dc4 @ 0xa0082dc4-0xa0082ec4 (64 words), flags -mcpu=v8 -O3 -g.
 * Source form: the doubled half is computed twice, once into the u16 local even_crop_height for the distance and
 * once by 'crop_height <<= 1' (two separate 'add' instructions).
 */
struct user_settings_record {
    unsigned char pad0[0x37];
    unsigned char wall_columns;   /* +0x37: number of columns in the video wall */
    unsigned char wall_rows;      /* +0x38: number of rows in the video wall */
    unsigned char tile_index;     /* +0x39: 1-based tile index in the wall */
};

/* Fields of the measured input timing (input_api_get_timing_field). */
enum {
    TIMING_HEIGHT  = 8,
    TIMING_START_Y = 15
};

extern struct user_settings_record user_settings;
extern unsigned short input_api_get_timing_field(unsigned char, unsigned int);
extern int dbg_printf(const char *fmt, ...);
extern int abs(int);

/*
 * Compute the vertical crop start and height of this monitor's video-wall tile.
 *
 *   channel     the channel whose timing fields 8 (height) and 15 (start y) are used
 *   out_height  receives the tile height
 *   out_start   receives the tile start
 *
 * row = (tile_index - 1) / wall_columns + 1. The base height is input_height / wall_rows rounded down to an even
 * number; the leftover is |input_height - base height * wall_rows|. Rows 1 .. leftover / 2 are 2 lines taller
 * (base + 2) and start at (base + 2) * (row - 1) + 2 * (row - 1); the other rows have the base height and start
 * at base * (row - 1) + leftover. input_start is added to the start (unlike pq_videowall_h_position there is no
 * correction by 1 at the end). Prints the wall rows and the row.
 *
 * Caller: pq_update_input_window.
 */
void pq_videowall_v_position(unsigned char channel, unsigned short *out_height, unsigned short *out_start)
{
    unsigned char cols = user_settings.wall_columns;
    unsigned char rows = user_settings.wall_rows;
    unsigned char row;
    unsigned char row_offset;
    unsigned short even_crop_height;
    unsigned short input_height;
    unsigned short input_start;
    unsigned short crop_height;
    int distance;

    row = (user_settings.tile_index - 1) / cols + 1;
    input_height = input_api_get_timing_field(channel, TIMING_HEIGHT);
    input_start = input_api_get_timing_field(channel, TIMING_START_Y);
    dbg_printf("VideoWall V num %d order %d\r\n", rows, row);
    crop_height = (unsigned int)(input_height / rows) >> 1;
    even_crop_height = crop_height << 1;
    distance = abs(input_height - even_crop_height * rows);
    row_offset = distance;
    crop_height <<= 1;
    /* The first leftover / 2 rows take 2 extra lines each; the others are offset by the whole leftover. */
    if (row <= row_offset >> 1) {
        row_offset = row * 2 - 2;
        crop_height += 2;
    }
    *out_start = crop_height * (row - 1) + row_offset + input_start;
    *out_height = crop_height;
}
