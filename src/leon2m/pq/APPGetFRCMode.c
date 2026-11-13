/* APPGetFRCMode  (FUN_a008380c)
 *
 * Choose the frame-rate conversion mode 0..3 for channel 0 from the input rate.
 * Returns: mode: bit 0 = lock mode, bit 1 = main bypass
 * Name basis: proven - prints 'APPGetFRCMode %x' (original name from the text)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008380c @ 0xa008380c (165 words), flags -mcpu=v8 -O3 without -g (with -g one trailing nop after the
 * last call differs).
 * Source forms the exact build depends on:
 *  - the input values are held as int and cast to unsigned short at each use;
 *  - a natural if / else-if chain (GCC predicts '== const' false, which puts the status bit 19 path out of line);
 *  - '(width == 800) & (height == 600)' and the size-4 test with a bitwise &;
 *  - the 4..6 test as an unsigned char flag set in an if; screen_size is an unsigned char local;
 *  - the two identical "4..6 or 8" bodies are ONE body under 'if (size_4_to_6 || user_settings.screen_size == 8)':
 *    re-reading the field in the second operand keeps the || as two branches (a plain '== 8' lets GCC merge it
 *    into an orcc), and the 8 test then zero-extends the byte again, which gives the firmware's 'and %o5,0xff';
 *  - 'goto done' where the firmware leaves the chain early.
 */

struct PanelParam {
    unsigned char b00[0x4e];
    unsigned short vf_min, vf_max;      /* vertical-frequency window of the active row, tenths of Hz (+0x4E/+0x50) */
    unsigned char b52[6];
};
struct user_settings_record {
    unsigned char b00[5];
    unsigned char output_mode;          /* +5: the output mode setting */
    unsigned char b06[0x19];
    unsigned char pip_pbp_mode;         /* +0x1F: 0 off, 1 PIP, 2 PBP */
    unsigned char b20[0x14];
    unsigned int image_enhancement;     /* +0x34: bits 12..15 are tested here */
    unsigned char b38[0x16c];
    unsigned char screen_size;          /* +0x1A4: the Screen Size setting */
};
extern struct PanelParam *panel_working_row_ptr;
extern struct user_settings_record user_settings;
extern int input_api_get_timing_field(int, int);
extern int panel_api_get_active_size(int);
extern unsigned char sys_get_channel0_flag_bit19(void);
extern unsigned char sys_api_get_channel_port_flag_alt(int);
extern unsigned char sys_api_get_channel_port_flag(int);
extern unsigned char sys_get_chip_revision(void);
extern int dbg_printf();

/* Fields of the measured input timing (input_api_get_timing_field). */
enum {
    TIMING_REFRESH_RATE = 1,    /* tenths of a hertz */
    TIMING_WIDTH        = 7,    /* picture width in pixels */
    TIMING_HEIGHT       = 8     /* picture height in lines */
};

#define PANEL_SIZE_LINES 1          /* panel_api_get_active_size: halfword +0x0A of the active row */

/* The window around the active row's vertical frequency that counts as "in range", in tenths of Hz. */
#define VF_WINDOW_HALF_WIDTH 20     /* 2.0 Hz, added to vf_max and subtracted from vf_min */

#define INPUT_800X600_WIDTH  800    /* in the status bit 19 path an 800x600 input needs a rate above 61.9 Hz */
#define INPUT_800X600_HEIGHT 600
#define FRC_800X600_LIMIT    0x26b  /* tenths of Hz: 61.9 Hz; at or below it an 800x600 input stays in mode 0 */
#define FRC_240HZ_LIMIT      0x95f  /* tenths of Hz: 239.9 Hz; mode 3 needs a rate at or below it */
#define CHIP_REVISION_82     0x82   /* revision cap for the mode-3 case */

/* The modes the frame-rate converter can take, as bits of the returned byte. */
enum {
    FRC_MODE_NONE   = 0,
    FRC_MODE_LOCK   = 1,     /* bit 0: output locked to a frame rate (FRC Lock) */
    FRC_MODE_BYPASS = 2,     /* bit 1: main picture bypasses the converter */
    FRC_MODE_BOTH   = 3      /* bits 0 and 1 */
};

/*
 * Choose the frame-rate-conversion mode for channel 0 and print it.
 *
 * Bit 0 of the result is the lock mode, used by pq_apply_frc_lock_mode; bit 1 the main bypass, used by
 * pq_apply_frc_main_bypass. Those two are the only callers (both reached through a pointer).
 *
 * The window is the active row's vertical-frequency range widened by 2.0 Hz on both sides (vf_min - 2.0 Hz to
 * vf_max + 2.0 Hz); the input rate is timing field 1. Timing field 0 is read and its value dropped.
 *
 * When status bit 19 of channel 0 is set: mode 1 when the rate lies strictly inside the window, except that an
 * 800x600 input at 61.9 Hz or below gets mode 0; mode 0 when it does not.
 *
 * Otherwise the mode starts at 2 with PIP/PBP off and at 0 with it on. Mode 0 when the channel's bit of the
 * port mask at 0xA802CBD3 is set (sys_api_get_channel_port_flag_alt) or the rate lies outside the window (the
 * limits themselves count as inside). Then:
 *   - only with PIP/PBP off, screen sizes 4..6 and 8 end the choice: size 4 with an input height equal to the
 *     panel's active lines keeps mode 2, sizes 4..6 otherwise give mode 1, size 8 gives mode 0;
 *   - mode 3 when the channel's bit of the port mask at 0xA802CBD4 is set (sys_api_get_channel_port_flag), the
 *     rate is at or below 239.9 Hz and the chip revision is at most 0x82;
 *   - else mode 2 when that port bit is set or the output mode (+5) is not 0, bits 12..15 of the image
 *     enhancement word are clear and the PIP/PBP mode is at most 1;
 *   - otherwise the starting mode stays.
 */
unsigned char APPGetFRCMode(void)
{
    int refresh_rate, input_width, input_height, panel_lines;
    unsigned char mode = 0;
    refresh_rate = input_api_get_timing_field(0, TIMING_REFRESH_RATE);
    input_api_get_timing_field(0, 0);
    input_width = input_api_get_timing_field(0, TIMING_WIDTH);
    input_height = input_api_get_timing_field(0, TIMING_HEIGHT);
    panel_lines = panel_api_get_active_size(PANEL_SIZE_LINES);
    if (sys_get_channel0_flag_bit19() == 1) {
        if ((unsigned short)refresh_rate > panel_working_row_ptr->vf_min - VF_WINDOW_HALF_WIDTH && (unsigned short)refresh_rate < panel_working_row_ptr->vf_max + VF_WINDOW_HALF_WIDTH) {
            if (((unsigned short)input_width == INPUT_800X600_WIDTH) & ((unsigned short)input_height == INPUT_800X600_HEIGHT)) { if ((unsigned short)refresh_rate > FRC_800X600_LIMIT) mode = FRC_MODE_LOCK; }
            else mode = FRC_MODE_LOCK;
        } else mode = FRC_MODE_NONE;
    } else {
        if (user_settings.pip_pbp_mode == 0) mode = FRC_MODE_BYPASS;
        if (sys_api_get_channel_port_flag_alt(0)) mode = FRC_MODE_NONE;
        else if ((unsigned short)refresh_rate < panel_working_row_ptr->vf_min - VF_WINDOW_HALF_WIDTH || (unsigned short)refresh_rate > panel_working_row_ptr->vf_max + VF_WINDOW_HALF_WIDTH) mode = FRC_MODE_NONE;
        else {
            if (user_settings.pip_pbp_mode == 0) {
                unsigned char screen_size = user_settings.screen_size;
                unsigned char size_4_to_6 = 0;
                if ((unsigned char)(screen_size - 4) <= 2) size_4_to_6 = 1;
                if (size_4_to_6 || user_settings.screen_size == 8) {
                    unsigned char size4_with_panel_height = (screen_size == 4) & ((unsigned short)input_height == (unsigned short)panel_lines);
                    if (!size4_with_panel_height) { mode = FRC_MODE_NONE; if ((unsigned char)(screen_size - 4) <= 2) mode = FRC_MODE_LOCK; }
                    goto done;
                }
            }
            if (sys_api_get_channel_port_flag(0) && (unsigned short)refresh_rate <= FRC_240HZ_LIMIT && sys_get_chip_revision() <= CHIP_REVISION_82) mode = FRC_MODE_BOTH;
            else if ((sys_api_get_channel_port_flag(0) || user_settings.output_mode) && !(user_settings.image_enhancement & 0xf000) && user_settings.pip_pbp_mode <= 1) mode = FRC_MODE_BYPASS;
        }
    }
done:
    dbg_printf("\033[0;35mAPPGetFRCMode %x\r\n\033[m", mode);
    return mode;
}
