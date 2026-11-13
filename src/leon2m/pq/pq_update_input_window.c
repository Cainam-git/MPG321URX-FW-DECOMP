/* pq_update_input_window  (FUN_a00830f4)
 *
 * Recompute and store a channel's input crop window (video wall, margins, Optix Scope, PBP match).
 *   port: channel number, 0xFF = none
 * Note: The parameter is a channel number (0xFF = none). Writes four window fields through
 *   sys_api_set_channel_position_field.
 * Name basis: derived - calls the video-wall routines and the input timing getter/setter; the channel-1 step
 *   uses the Optix Scope size and ratio settings
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00830f4 @ 0xa00830f4-0xa00837e4 (444 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the 'switch' on the scope size has the default arm written first (the firmware compares 1, then 2 at
 *    0xa00831b0..0xa00831b8 and places the arms default, 2, 1 at 0xa00831c4, 0xa00835c4, 0xa0083634); each arm
 *    has the same statements, horizontal before vertical, with the panel_api_get_active_size(PANEL_SIZE_WIDTH)
 *    call inside the horizontal expression and the line count read again for the vertical one;
 *  - the four stores of the scope window in the order width, x, height, y, through new_x / new_y;
 *  - y is updated inside each arm of the sys_api_get_channel_block_flag2 test; the divisions of the margin
 *    block are signed, through the int copy 'value';
 *  - pq_match_ch1_timing_table is a static copy of the text of src/leon2m/pq/pq_match_ch1_timing_table.c, inlined here.
 * The labels behind pq_ch1_measured_height and pq_ch1_timing_table carry a word after the address in the list
 * of names (..._vactive, ..._mode_table) and must keep exactly that spelling: the compiler orders the two
 * hoisted %hi parts of their addresses by a hash of the label text (firmware 0xa0083404 %l1, 0xa0083448 %l2).
 */

/* The fields of the user settings record read here (docs/RECORDS.md). */
struct user_settings_record {
    unsigned int word_0x0;              /* +0: bit 5 = video wall crop, bit 6 = margin crop (see below) */
    unsigned char pad004[0x1b];
    unsigned char pip_pbp_mode;         /* +0x1F: 0 off, 1 PIP, 2 PBP */
    unsigned char pad020[0x0f];
    unsigned char pbp_layout;           /* +0x2F */
    unsigned char pad030[0x1b];
    unsigned char scope_size;           /* +0x4B: Optix Scope size, menu texts Small / Medium / Large */
    unsigned char scope_ratio;          /* +0x4C: Optix Scope ratio, menu texts x1.5 / x2 / x3 */
};

#define SETTINGS_VIDEO_WALL   0x20      /* word +0 bit 5: crop by the video-wall tile */
#define SETTINGS_MARGIN_CROP  0x40      /* word +0 bit 6: crop a margin of 1/80 of the picture */

#define PIP_PBP_OFF           0
#define PIP_PBP_PBP           2

#define SCOPE_SIZE_MEDIUM     1         /* square of a third of the panel lines */
#define SCOPE_SIZE_LARGE      2         /* square of half the panel lines; Small (0) = a quarter */

/* The scope ratio in tenths: x1.5, x2, x3. */
#define SCOPE_RATIO_X1_5      15
#define SCOPE_RATIO_X2        20
#define SCOPE_RATIO_X3        30

#define NO_CHANNEL            0xff
#define SCOPE_CHANNEL         1         /* the channel that the Optix Scope and the PBP table match work on */
#define PORT_CODE_0D          0xd       /* port code (input_api_get_channel_port_code) for the PBP table match */

/* Fields of input_api_get_timing_field read here (channel record +0x12, +0x14, +0x1A, +0x1C). */
enum {
    TIMING_WIDTH   = 7,                 /* horizontal size that the video-wall routine divides */
    TIMING_HEIGHT  = 8,
    TIMING_START_X = 11,                /* horizontal start that the video-wall routine adds to */
    TIMING_START_Y = 15
};

/* Fields of sys_api_set_channel_position_field written here (channel record +0x1E, +0x20, +0x16, +0x18). */
enum {
    POSITION_START_X = 12,
    POSITION_START_Y = 16,
    POSITION_WIDTH   = 9,
    POSITION_HEIGHT  = 10               /* the last write passes 1: the channel is restarted with the new window */
};

/* panel_api_get_active_size selectors: halfwords +8 and +0xA of the active panel timing row. */
#define PANEL_SIZE_WIDTH  0
#define PANEL_SIZE_LINES  1

/* One row of the 12-row ROM table at 0xFEB30 (18 bytes). */
struct ch1_size_row {
    unsigned short width;               /* compared with timing field 7 */
    unsigned short height;              /* compared with timing field 8 */
    unsigned short word_0x4;
    unsigned short height_out;          /* +6: the height taken over on a match */
    unsigned short rest[5];
};
#define CH1_SIZE_ROWS       12
#define CH1_SIZE_TOLERANCE  10          /* a row matches when width and height are both within 10 */

extern struct user_settings_record user_settings;
extern unsigned short pq_ch1_measured_height, pq_ch1_measured_width, pq_ch1_measured_fourth_value, pq_ch1_measured_third_value;
extern const struct ch1_size_row pq_ch1_timing_table[];
extern unsigned short input_api_get_timing_field(unsigned char channel, unsigned int field);
extern void sys_api_set_channel_position_field(unsigned char channel, unsigned int field, unsigned short value, unsigned char restart);
extern unsigned char sys_api_get_channel_block_flag2(unsigned char channel);
extern unsigned short panel_api_get_active_size(unsigned char selector);
extern unsigned char input_api_get_channel_port_code(unsigned char channel);
extern void sys_api_enable_channel_port(unsigned char channel, unsigned int enable);
extern void pq_videowall_h_position(unsigned char channel, unsigned short *width, unsigned short *start);
extern void pq_videowall_v_position(unsigned char channel, unsigned short *height, unsigned short *start);
extern int abs(int);

/*
 * Channel 1's window from the measured picture size (the same text as pq_match_ch1_timing_table in
 * src/leon2m/pq/pq_match_ch1_timing_table.c, kept here as a static copy).
 *
 * The channel's timing width and height are first compared with the measured values pq_ch1_measured_width and
 * pq_ch1_measured_height (within a sixth of the timing value counts as equal), then looked up in the 12-row table.
 * Without a matching row nothing is written. With a row:
 *   width differs from the measured width:  width = measured + 8, x = third measured value - 8,
 *                                           height = the row's height_out;
 *   width equal, height differs:            measured width above pq_ch1_measured_height: width = measured + 8,
 *                                           x = third value, height = height_out, y = 0;
 *                                           else width = measured, x = third value,
 *                                           height = pq_ch1_measured_height, y = fourth measured value.
 * When both are equal nothing is written.
 */
static void pq_match_ch1_timing_table(unsigned short *start_x, unsigned short *start_y, unsigned short *width_out, unsigned short *height_out)
{
  unsigned short width, height, width_tolerance, height_tolerance;
  unsigned char found, width_equal, height_equal, i;
  int distance;

  width = input_api_get_timing_field(1, TIMING_WIDTH);
  height = input_api_get_timing_field(1, TIMING_HEIGHT);
  found = 0;
  width_tolerance = width / 6;
  if (abs(width - pq_ch1_measured_width) > width_tolerance)
    width_equal = 0;
  else
    width_equal = 1;
  height_tolerance = height / 6;
  if (abs(height - pq_ch1_measured_height) > height_tolerance)
    height_equal = 0;
  else
    height_equal = 1;
  for (i = 0; i < CH1_SIZE_ROWS; i++) {
    distance = abs(width - pq_ch1_timing_table[i].width);
    if (distance > CH1_SIZE_TOLERANCE)
      continue;
    distance = abs(height - pq_ch1_timing_table[i].height);
    if (distance > CH1_SIZE_TOLERANCE)
      continue;
    found = 1;
    break;
  }
  if (found == 1) {
    if (width_equal == 0) {
      *width_out = pq_ch1_measured_width + 8;
      *start_x = pq_ch1_measured_third_value - 8;
      *height_out = pq_ch1_timing_table[i].height_out;
    } else if (width_equal == 1 && height_equal == 0) {
      if (pq_ch1_measured_width > pq_ch1_measured_height) {
        *width_out = pq_ch1_measured_width + 8;
        *start_x = pq_ch1_measured_third_value;
        *height_out = pq_ch1_timing_table[i].height_out;
        *start_y = 0;
      } else {
        *width_out = pq_ch1_measured_width;
        *start_x = pq_ch1_measured_third_value;
        *height_out = pq_ch1_measured_height;
        *start_y = pq_ch1_measured_fourth_value;
      }
    }
  }
}

/*
 * Work out the part of a channel's input picture that is shown, and store it in the channel record.
 *
 *   port  the channel number (it is passed as the channel to input_api_get_timing_field and
 *         sys_api_set_channel_position_field); 0xFF = no channel, nothing is done.
 *
 * Callers: the menu (Optix Scope, PIP/PBP layout, PBP split, screen size, Adaptive-Sync), the PC-tool commands
 * (Optix Scope, PIP/PBP, blur free, Adaptive-Sync, picture settings, screen size), the factory reset and
 * pq_user_update_input_window pass channel 0; pq_detect_ch1_input_change passes channel 1 when channel 1's
 * measured size has changed.
 *
 * Phases, in order:
 *   1. Start from the channel's timing window: start x / y (fields 11 / 15), width / height (fields 7 / 8).
 *   2. Crop by settings word +0 bit 5 (the video-wall tile, pq_videowall_h_position / _v_position) or, when
 *      that bit is clear, by bit 6 (a margin of 1/80 of the width on each side, 1/80 or 1/160 of the height).
 *   3. Channel 1 with PIP/PBP off: the Optix Scope window. The scope size gives a side of a quarter, a third
 *      or half of the panel lines (Small, Medium, Large). That side divided by the ratio (x1.5, x2, x3), taken
 *      as a share of the panel width and of the panel lines, gives the share of the window that is kept:
 *      rounded down to 8 pixels and 2 lines and centred in the window of phase 2. Then channel 1's port is
 *      enabled (sys_api_enable_channel_port).
 *      Channel 1 in PBP with layout 0 and port code 0x0D instead: the window from the measured size
 *      (pq_match_ch1_timing_table above).
 *   4. Store start x, start y, width, height (position fields 12, 16, 9, 10); the last store restarts the
 *      channel with the new window.
 */
void pq_update_input_window(unsigned char port)
{
    unsigned short width;
    unsigned short start_x;
    unsigned short height;
    unsigned short start_y;
    unsigned short width_share;         /* scope part of the panel width, in thousandths */
    unsigned short lines_share;         /* scope part of the panel lines, in thousandths */
    int value;
    unsigned int scope_width;
    unsigned int scope_height;
    unsigned int scope_side;            /* side of the scope square in panel lines, times 1000 */
    unsigned short new_x;
    unsigned short new_y;
    unsigned char ratio;

    start_x = 0;
    start_y = 0;
    width = 0;
    height = 0;
    if (port == NO_CHANNEL)
        return;

    /* 1. The channel's timing window. */
    start_x = input_api_get_timing_field(port, TIMING_START_X);
    start_y = input_api_get_timing_field(port, TIMING_START_Y);
    width = input_api_get_timing_field(port, TIMING_WIDTH);
    height = input_api_get_timing_field(port, TIMING_HEIGHT);

    /* 2. Video-wall tile or margin crop. */
    if (user_settings.word_0x0 & SETTINGS_VIDEO_WALL) {
        pq_videowall_h_position(port, &width, &start_x);
        pq_videowall_v_position(port, &height, &start_y);
    } else if (user_settings.word_0x0 & SETTINGS_MARGIN_CROP) {
        value = width;
        start_x = value / 80;
        width = width - start_x * 2;
        /* The vertical margin is halved when flag 2 of the channel's register block is set. */
        if (sys_api_get_channel_block_flag2(port) == 1) {
            value = height;
            start_y = value / 160 + start_y;
        } else {
            value = height;
            start_y = value / 80 + start_y;
        }
        if (sys_api_get_channel_block_flag2(port) == 1)
            height = height - start_y * 4;
        else
            height = height - start_y * 2;
    }

    if (user_settings.pip_pbp_mode == PIP_PBP_OFF && port == SCOPE_CHANNEL) {
        /* 3. Optix Scope window of channel 1. */
        if (user_settings.scope_ratio != 0)
            ratio = user_settings.scope_ratio == 1 ? SCOPE_RATIO_X2 : SCOPE_RATIO_X3;
        else
            ratio = SCOPE_RATIO_X1_5;
        /* share = side * 1000 * 10 / panel size / ratio in tenths, i.e. (side / ratio) / panel size * 1000. */
        switch (user_settings.scope_size) {
        default:
            scope_side = (panel_api_get_active_size(PANEL_SIZE_LINES) >> 2) * 1000;
            width_share = scope_side * 10 / panel_api_get_active_size(PANEL_SIZE_WIDTH) / ratio;
            scope_side = (panel_api_get_active_size(PANEL_SIZE_LINES) >> 2) * 1000;
            lines_share = scope_side * 10 / panel_api_get_active_size(PANEL_SIZE_LINES) / ratio;
            break;
        case SCOPE_SIZE_MEDIUM:
            scope_side = panel_api_get_active_size(PANEL_SIZE_LINES) / 3 * 1000;
            width_share = scope_side * 10 / panel_api_get_active_size(PANEL_SIZE_WIDTH) / ratio;
            scope_side = panel_api_get_active_size(PANEL_SIZE_LINES) / 3 * 1000;
            lines_share = scope_side * 10 / panel_api_get_active_size(PANEL_SIZE_LINES) / ratio;
            break;
        case SCOPE_SIZE_LARGE:
            scope_side = (panel_api_get_active_size(PANEL_SIZE_LINES) >> 1) * 1000;
            width_share = scope_side * 10 / panel_api_get_active_size(PANEL_SIZE_WIDTH) / ratio;
            scope_side = (panel_api_get_active_size(PANEL_SIZE_LINES) >> 1) * 1000;
            lines_share = scope_side * 10 / panel_api_get_active_size(PANEL_SIZE_LINES) / ratio;
            break;
        }
        /* That share of the window, rounded down to a multiple of 8 pixels and 2 lines, centred. */
        scope_width = (unsigned int)(width * width_share) / 8000 * 8;
        scope_height = (unsigned int)(height * lines_share) / 2000 * 2;
        new_x = ((width - scope_width) >> 1) + start_x;
        new_y = ((height - scope_height) >> 1) + start_y;
        width = scope_width;
        start_x = new_x;
        height = scope_height;
        start_y = new_y;
        sys_api_enable_channel_port(SCOPE_CHANNEL, 1);
    } else if (user_settings.pip_pbp_mode == PIP_PBP_PBP && user_settings.pbp_layout == 0 && port == SCOPE_CHANNEL) {
        /* 3. PBP, layout 0: channel 1's window from its measured size. */
        if (input_api_get_channel_port_code(1) == PORT_CODE_0D)
            pq_match_ch1_timing_table(&start_x, &start_y, &width, &height);
    }

    /* 4. Store the window; the last store restarts the channel. */
    sys_api_set_channel_position_field(port, POSITION_START_X, start_x, 0);
    sys_api_set_channel_position_field(port, POSITION_START_Y, start_y, 0);
    sys_api_set_channel_position_field(port, POSITION_WIDTH, width, 0);
    sys_api_set_channel_position_field(port, POSITION_HEIGHT, height, 1);
}
