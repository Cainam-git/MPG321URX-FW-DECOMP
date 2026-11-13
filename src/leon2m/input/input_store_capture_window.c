/* input_store_capture_window  (FUN_a013d1b4)
 *
 * Store a capture window in a channel record after limiting it.
 * Name basis: derived - input capture window -> channel record
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013d1b4 @ 0xa013d1b4-0xa013d670 (1212 bytes, 303 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three routines in front of this one, sys_call_frc_callbacks (sys_call_frc_callbacks), sys_is_pip_mode_above_4
 *    (sys_is_pip_mode_above_4) and sys_is_channel_value_below_default (sys_is_channel_value_below_default), are static functions of this file
 *    and are inlined here; their unsigned char results are tested with '== 1', the sys_is_pip_mode_above_4
 *    result through a local;
 *  - sys_config is a union (word 0, bytes 0..3, word 4); bit 30 of channel record word +0x40 is a 1-bit
 *    bit-field;
 *  - the rounding to 64 is the nested 'else if (sys_config.s.word_0x04 & 0xF0000000) { if (channel != 0)';
 *  - the final stores are written as channel_records[channel].field.
 */

/* The window handed in: eight halfwords in the layout APP_ConfigDispSize fills (its struct disp_win). */
struct capture_window
{
  unsigned short shown_width;           /* size of the window actually shown */
  unsigned short shown_height;
  unsigned short base_width;            /* size of the base window */
  unsigned short base_height;
  unsigned short base_x;                /* position of the base window on the panel */
  unsigned short base_y;
  short offset_x;                       /* offset of the shown window inside the base window */
  unsigned short offset_y;
};

/* A channel record (0x78 bytes at channel_records), the fields used here. +0x4A, +0x52 and +0x54 are the
   width, lines and lines_part of the channel's output timing (struct output_timing at +0x48). */
struct channel_record
{
  unsigned int status_word;             /* +0x00: bit 0 tested here */
  unsigned char pad04[0x3c];
  unsigned int word_0x40_bit31 : 1;     /* +0x40 */
  unsigned int word_0x40_bit30 : 1;
  unsigned int word_0x40_rest : 30;
  unsigned char pad44[6];
  unsigned short width;                 /* +0x4A */
  unsigned short width_2;               /* +0x4C */
  unsigned short x_extra;               /* +0x4E */
  unsigned short x_offset;              /* +0x50: offset_x + x_extra */
  unsigned short lines;                 /* +0x52 */
  unsigned short lines_part;            /* +0x54 */
  unsigned short y_offset;              /* +0x56: offset_y + y_extra */
  unsigned short y_extra;               /* +0x58 */
  unsigned short x_position;            /* +0x5A */
  unsigned short y_position;            /* +0x5C */
  unsigned char pad5e[0x1a];
};

/* The panel timing row in use (panel_active_row), the fields read here. */
struct panel_timing_row
{
  unsigned int flags;
  unsigned short half_0x04;
  unsigned char display_mode;
  unsigned char bpc;
  unsigned short active_size0;          /* +0x08: active width */
  unsigned short active_size1;          /* +0x0A: active lines */
  unsigned char pad0c[0x1a];
  unsigned short hblank_part;           /* +0x26 */
  unsigned short hblank_part2;          /* +0x28 */
  unsigned short vtotal_min;
  unsigned short vtotal;
  unsigned short vtotal_max;
  unsigned short half_0x30;
  unsigned short half_0x32;
};

/* The first two words of the system configuration record (stSysConfig). */
union sys_config_record
{
  unsigned int word_0x00;               /* bits 21, 26 and 27 used here */
  struct
  {
    unsigned char byte_0;
    unsigned char byte_1;
    unsigned char byte_2;
    unsigned char byte_3;               /* sys_config_byte_3 */
    unsigned int word_0x04;
  } s;
};

/* The callback table registered at start-up; entries +0x24 and +0x28 are used here. */
struct callback_table
{
  unsigned char pad00[0x24];
  void (*fn24)(void);
  void (*fn28)(void);
};

#define SYS_CONFIG_BIT21      0x200000      /* bit 21 of sys_config word 0: fixed window for channel 3 */
#define SYS_CONFIG_BIT26      0x4000000     /* bit 26: cleared when callback fn28 is not registered */
#define SYS_CONFIG_BIT27      0x8000000     /* bit 27: cleared when callback fn24 is not registered */

#define DEFAULT_X_EXTRA       0x18
#define DEFAULT_Y_EXTRA       3
#define FIXED_WINDOW_WIDTH    0x80          /* the window channel 3 gets with SYS_CONFIG_BIT21 */
#define FIXED_WINDOW_LINES    0xa0
#define FIXED_WINDOW_Y_EXTRA  2
#define Y_OFFSET_LIMIT        0x800         /* a y offset at or above this is stored as 0 */

extern struct channel_record channel_records[4];
extern struct panel_timing_row panel_active_row;
extern union sys_config_record sys_config;
extern struct callback_table sys_callback_table;
extern unsigned char device_settings_pip_mode;
extern const unsigned short panel_default_row_active_lines;    /* active_size1 (+0xA) of the default panel row */

/* For channel 0: call callbacks fn28 and fn24 when they are registered; for each one that is not, clear its
   bit of sys_config word 0. */
static void sys_call_frc_callbacks(unsigned char channel)
{
  if (channel == 0)
  {
    if (sys_callback_table.fn28 != 0)
      sys_callback_table.fn28();
    else
      sys_config.word_0x00 &= ~SYS_CONFIG_BIT26;
    if (sys_callback_table.fn24 != 0)
      sys_callback_table.fn24();
    else
      sys_config.word_0x00 &= ~SYS_CONFIG_BIT27;
  }
}
/* 1 when the picture-in-picture mode is above 4. */
static unsigned char sys_is_pip_mode_above_4(void)
{
  if (device_settings_pip_mode <= 4)
    return 0;
  return 1;
}
/* 1 when lines_part of channel 0 is below the active lines of the default panel row. */
static unsigned char sys_is_channel_value_below_default(void)
{
  return channel_records[0].lines_part < panel_default_row_active_lines;
}

/*
 * Take a capture window, adjust it and store the values in the channel record.
 *
 *   channel  picture channel 0..3
 *   window   the window (changed in place: some values are scaled, rounded or cleared)
 *
 * Called by input_api_set_capture_window and by input_channel_bring_up_task (state 8, with the window from
 * callback 0x0C of sys_callback_table).
 *
 * Phases:
 *   1. Scaling. Channel 0 with sys_config byte 3 set: offset_x, shown_width, base_x and base_width are
 *      multiplied by active_size1 and divided by active_size0 of the active panel row. Otherwise, when any of
 *      the top 4 bits of sys_config word 4 is set, channels 1..3 get shown_width, base_width and base_x rounded
 *      up to a multiple of 64 and offset_x = (base_width - shown_width) / 2.
 *   2. lines_part = shown_height (the test of channel 0 below reads it).
 *   3. The values to store. Width/lines (W/L), width_2/lines_part (W2/L2), x/y position (P), x/y extra (E):
 *      channel 0 (fn28 and fn24 are called first):
 *        PIP mode above 4, or shown_height below the default row's lines: W, W2 = shown size; E = 0x18 / 3;
 *          P = base position + offset, with the offset cleared, when the base window is at least as wide or
 *          at least as high as the shown window; else P = base position;
 *        else W = base size, W2 = shown size, and P = base position with E = 0x18 / 3, or, when bit 0 of the
 *          status word, bit 30 of word +0x40 or SYS_CONFIG_BIT26 is set, P = 0 with E = hblank_part +
 *          hblank_part2 / half_0x30 + half_0x32 of the active panel row;
 *      channel 3 with SYS_CONFIG_BIT21: W = W2 = 0x80 / 0xA0, P = 0, E = 0x18 / 2, offset cleared;
 *      every other case: as the first channel 0 case.
 *   4. x_offset = offset_x + x extra, at least 0; y_offset = offset_y + y extra, 0 when 0x800 or more.
 *   5. All ten values are stored in the channel record.
 */
void input_store_capture_window(unsigned char channel, struct capture_window *window)
{
  unsigned short shown_width_64;
  unsigned short base_width_64;
  unsigned short width;
  unsigned short lines;
  unsigned short width_2;
  unsigned short lines_part;
  unsigned short x_position;
  unsigned short y_position;
  unsigned short x_extra;
  unsigned short y_extra;
  unsigned short y_offset;
  short x_offset;
  unsigned char pip_above_4;
  struct channel_record *chan;

  /* 1. Scale to the panel row, or round the widths to 64. */
  if ((channel == 0) && (sys_config.s.byte_3 != 0))
  {
    window->offset_x = (window->offset_x * panel_active_row.active_size1) / panel_active_row.active_size0;
    window->shown_width = (window->shown_width * panel_active_row.active_size1) / panel_active_row.active_size0;
    window->base_x = (window->base_x * panel_active_row.active_size1) / panel_active_row.active_size0;
    window->base_width = (window->base_width * panel_active_row.active_size1) / panel_active_row.active_size0;
  }
  else
    if (sys_config.s.word_0x04 & 0xf0000000)
  {
    if (channel != 0)
    {
      shown_width_64 = (window->shown_width + 0x3f) >> 6;
      base_width_64 = (window->base_width + 0x3f) >> 6;
      window->shown_width = shown_width_64 << 6;
      window->base_x = (window->base_x + 0x3f) & 0xffc0;
      window->base_width = base_width_64 << 6;
      window->offset_x = (window->base_width - window->shown_width) >> 1;
    }
  }

  /* 2. */
  channel_records[channel].lines_part = window->shown_height;

  /* 3. The values to store. */
  if (channel == 0)
  {
    sys_call_frc_callbacks(channel);
    pip_above_4 = sys_is_pip_mode_above_4();
    chan = &channel_records[channel];
    if (pip_above_4 == 1 || sys_is_channel_value_below_default() == 1)
    {
      if ((window->base_width >= window->shown_width) || (window->base_height >= window->shown_height))
      {
        /* The offset moves into the position. */
        x_position = window->base_x + window->offset_x;
        y_position = window->base_y + window->offset_y;
        window->offset_x = 0;
        window->offset_y = 0;
        width = window->shown_width;
        lines = window->shown_height;
        width_2 = window->shown_width;
        lines_part = window->shown_height;
        x_extra = DEFAULT_X_EXTRA;
        y_extra = DEFAULT_Y_EXTRA;
      }
      else
      {
        width = window->shown_width;
        lines = window->shown_height;
        width_2 = window->shown_width;
        lines_part = window->shown_height;
        x_extra = DEFAULT_X_EXTRA;
        y_extra = DEFAULT_Y_EXTRA;
        x_position = window->base_x;
        y_position = window->base_y;
      }
    }
    else
      if (((!(chan->status_word & 1)) && (!chan->word_0x40_bit30)) && !(sys_config.word_0x00 & SYS_CONFIG_BIT26))
    {
      width = window->base_width;
      lines = window->base_height;
      width_2 = window->shown_width;
      lines_part = window->shown_height;
      x_extra = DEFAULT_X_EXTRA;
      y_extra = DEFAULT_Y_EXTRA;
      x_position = window->base_x;
      y_position = window->base_y;
    }
    else
    {
      /* The extras come from the panel row; the position is 0. */
      x_extra = panel_active_row.hblank_part + panel_active_row.hblank_part2;
      y_extra = panel_active_row.half_0x30 + panel_active_row.half_0x32;
      width = window->base_width;
      lines = window->base_height;
      width_2 = window->shown_width;
      lines_part = window->shown_height;
      x_position = 0;
      y_position = 0;
    }
    x_offset = window->offset_x + x_extra;
    y_offset = window->offset_y + y_extra;
  }
  else
    if ((channel == 3) && (sys_config.word_0x00 & SYS_CONFIG_BIT21))
  {
    /* Channel 3: a fixed window. */
    window->offset_x = 0;
    window->offset_y = 0;
    width = FIXED_WINDOW_WIDTH;
    lines = FIXED_WINDOW_LINES;
    width_2 = FIXED_WINDOW_WIDTH;
    lines_part = FIXED_WINDOW_LINES;
    x_extra = DEFAULT_X_EXTRA;
    y_extra = FIXED_WINDOW_Y_EXTRA;
    x_position = 0;
    y_position = 0;
    x_offset = window->offset_x + x_extra;
    y_offset = window->offset_y + y_extra;
  }
  else
  {
    if ((window->base_width < window->shown_width) && (window->base_height < window->shown_height))
    {
      width = window->shown_width;
      lines = window->shown_height;
      width_2 = window->shown_width;
      lines_part = window->shown_height;
      x_extra = DEFAULT_X_EXTRA;
      y_extra = DEFAULT_Y_EXTRA;
      x_position = window->base_x;
      y_position = window->base_y;
    }
    else
    {
      /* The offset moves into the position. */
      x_position = window->base_x + window->offset_x;
      y_position = window->base_y + window->offset_y;
      window->offset_x = 0;
      window->offset_y = 0;
      width = window->shown_width;
      lines = window->shown_height;
      width_2 = window->shown_width;
      lines_part = window->shown_height;
      x_extra = DEFAULT_X_EXTRA;
      y_extra = DEFAULT_Y_EXTRA;
    }
    x_offset = window->offset_x + x_extra;
    y_offset = window->offset_y + y_extra;
  }

  /* 4. Limits. */
  if (x_offset < 0)
  {
    x_offset = 0;
  }
  if (y_offset >= Y_OFFSET_LIMIT)
  {
    y_offset = 0;
  }

  /* 5. Store. */
  channel_records[channel].width = width;
  channel_records[channel].lines = lines;
  channel_records[channel].x_extra = x_extra;
  channel_records[channel].y_extra = y_extra;
  channel_records[channel].x_offset = x_offset;
  channel_records[channel].y_offset = y_offset;
  channel_records[channel].width_2 = width_2;
  channel_records[channel].lines_part = lines_part;
  channel_records[channel].x_position = x_position;
  channel_records[channel].y_position = y_position;
}
