/* SYSAPI_GetPanelParamStruct  (FUN_a00dac38)
 *
 * Choose the panel timing row that fits the incoming refresh rate and make it active.
 * Name basis: proven - prints 'SYSAPI_GetPanelParamStruct %x,%x' (original name)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dac38 @ 0xa00dac38, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - panel_line_rate is one expression ((u16)line_rate * 2160 / lines * 1000, with lines = (u16)active_lines
 *    held in an unsigned int), so the compiler reuses the zero-extended active_lines from its print;
 *  - the callees' return types (oled_frc_get_row unsigned char, oled_get_frame_rate_control unsigned short,
 *    nvram_get_device_setting unsigned short), but input_api_get_timing_field declared int-returning (the
 *    firmware extends its results at the uses);
 *  - timing fields 8 and 7 are read and their values dropped.
 * The four limits are the immediates 600 (0x258), 1200, 699 (0x2bb) and 1299. FW.012 had only the refresh-rate
 * branch and no 60 Hz row.
 */

/* The panel can be driven in three modes. Each mode is one row of panel_mode_rows. */
enum {
    PANEL_MODE_240HZ = 0,
    PANEL_MODE_120HZ = 1,
    PANEL_MODE_60HZ  = 2
};

/* Fields of the measured input timing (input_api_get_timing_field). */
enum {
    TIMING_LINE_RATE    = 0,
    TIMING_REFRESH_RATE = 1,    /* in tenths of a hertz: 600 = 60.0 Hz */
    TIMING_FIELD_7      = 7,
    TIMING_FIELD_8      = 8,
    TIMING_ACTIVE_LINES = 10    /* printed below as active_in; the mode rows in ROM give the picture height here */
};

#define DEVICE_SETTING_PHY_CTS_AUTO 2       /* factory menu switch "PHY CTS AUTO" */

#define PANEL_LINES          2160           /* picture lines of the panel */
#define PANEL_TOTAL_LINES    2348           /* shortest frame of every panel mode, in lines */

/* Upper limits of the 60 Hz and the 120 Hz mode, in tenths of a hertz. */
#define REFRESH_LIMIT_60HZ   600            /* measured refresh rate; the margin is added to it */
#define REFRESH_LIMIT_120HZ  1200
#define COMPUTED_LIMIT_60HZ  699            /* refresh rate computed from the line rate */
#define COMPUTED_LIMIT_120HZ 1299

struct panel_mode_row { unsigned long long words[11]; };      /* 0x58 bytes: the whole timing of one mode */

extern struct panel_mode_row panel_mode_rows[];
extern unsigned char device_settings_pip_mode, sys_config_byte_3;
extern unsigned short panel_output_rate;
extern unsigned short nvram_get_device_setting(unsigned int);
extern int input_api_get_timing_field(int, int);
extern unsigned int sys_frc_is_active(void);
extern int dbg_printf();
extern unsigned char sys_api_get_channel_port_flag(unsigned char);
extern unsigned char oled_frc_get_row(void);
extern void oled_frc_set_row(unsigned char);
extern void panel_api_set_active_row(struct panel_mode_row *, unsigned char);
extern unsigned short oled_get_frame_rate_control(void);
extern void FRCConfigPostFRC(int, unsigned short, int);

/*
 * Pick the panel mode (240, 120 or 60 Hz) for the signal on the main picture and switch to it.
 *
 *   scaler_line_rate_out  only printed; the callers pass 0 or 1
 *   unused                not used
 *   force_120hz_mode      1: take the 120 Hz mode without looking at the signal
 *
 * Called from APPActionDispatcher, from the OLED power state machine (oled_power_task) and, with
 * force_120hz_mode set, from oled_frc_task.
 *
 * In picture mode 0 (one picture) and in picture mode 2 the panel mode follows the input: up to about 62 Hz
 * the 60 Hz mode, up to about 122 Hz the 120 Hz mode, above that the 240 Hz mode. In every other
 * picture-in-picture mode it is always the 120 Hz mode.
 *
 * The four limits below are the only thing the two files in firmware/custom change. With the panel's
 * timing locked to the input, a signal slightly faster than the mode it lands in (60.0988 Hz in the 60 Hz mode,
 * 120.198 Hz in the 120 Hz mode) leaves each frame too few lines. Lowering the limits moves such signals into
 * the next faster mode, where they fit.
 */
void SYSAPI_GetPanelParamStruct(unsigned int scaler_line_rate_out, int unused, unsigned char force_120hz_mode)
{
    struct panel_mode_row row;
    unsigned char margin = 20;                  /* 2.0 Hz above each limit still counts as that mode */
    int refresh_rate, line_rate, active_lines;
    unsigned int panel_line_rate;
    unsigned char mode;
    int reported_row;

    /* For signal compliance tests the factory menu narrows the margin to 0.5 Hz. */
    if ((unsigned short)nvram_get_device_setting(DEVICE_SETTING_PHY_CTS_AUTO) == 1) margin = 5;

    /* The measured timing of the input on channel 0. */
    input_api_get_timing_field(0, TIMING_FIELD_8);
    input_api_get_timing_field(0, TIMING_FIELD_7);
    refresh_rate = input_api_get_timing_field(0, TIMING_REFRESH_RATE);
    line_rate = input_api_get_timing_field(0, TIMING_LINE_RATE);
    active_lines = input_api_get_timing_field(0, TIMING_ACTIVE_LINES);

    if (force_120hz_mode == 1) {
        if ((unsigned char)oled_frc_get_row() != PANEL_MODE_120HZ) {
            oled_frc_set_row(PANEL_MODE_120HZ);
            row = panel_mode_rows[(unsigned char)oled_frc_get_row()];
            panel_api_set_active_row(&row, 1);
            /* Program the output clock and timing again for the new row. */
            FRCConfigPostFRC(sys_config_byte_3 != 0, panel_output_rate, 1);
        }
    } else {
        dbg_printf("\033[1;31mhfrq(%d) = %d\r\n\033[m", (unsigned char)sys_frc_is_active(), (unsigned short)line_rate);
        dbg_printf("\033[1;31mactive_in(%d) = %d\r\n\033[m", (unsigned char)sys_frc_is_active(), (unsigned short)active_lines);
        dbg_printf("\033[1;31mvfreq(%d) = %d\r\n\033[m", (unsigned char)sys_frc_is_active(), (unsigned short)refresh_rate);
        dbg_printf("\033[1;31mscaler_hfrq_out = %d\r\n\033[m", scaler_line_rate_out / 1000);
        dbg_printf("\033[1;31mVfreq %d %d %d\r\n\033[m", scaler_line_rate_out / PANEL_TOTAL_LINES, scaler_line_rate_out / PANEL_TOTAL_LINES, scaler_line_rate_out / PANEL_TOTAL_LINES);

        if (device_settings_pip_mode == 0 || device_settings_pip_mode == 2) {
            /* The input's line rate, scaled from the input's picture lines to the panel's 2160 lines. */
            { unsigned int lines = (unsigned short)active_lines;
            if (lines != 0) panel_line_rate = (unsigned short)line_rate * PANEL_LINES / lines * 1000; else panel_line_rate = (unsigned short)line_rate * 1000; }

            if (sys_api_get_channel_port_flag(0) != 0) {
                /* This port is judged by its line rate: divided by the lines of a panel frame it gives a
                   refresh rate for the panel. */
                if (panel_line_rate / PANEL_TOTAL_LINES <= COMPUTED_LIMIT_60HZ) mode = PANEL_MODE_60HZ;
                else if (panel_line_rate / PANEL_TOTAL_LINES <= COMPUTED_LIMIT_120HZ) mode = PANEL_MODE_120HZ;
                else mode = PANEL_MODE_240HZ;
            } else {
                /* Every other port is judged by its measured refresh rate. */
                if ((unsigned short)refresh_rate < margin + REFRESH_LIMIT_60HZ) mode = PANEL_MODE_60HZ;
                else if ((unsigned short)refresh_rate < margin + REFRESH_LIMIT_120HZ) mode = PANEL_MODE_120HZ;
                else mode = PANEL_MODE_240HZ;
            }

            /* Switch only when the mode changes. */
            if ((unsigned char)oled_frc_get_row() != mode) {
                oled_frc_set_row(mode);
                row = panel_mode_rows[(unsigned char)oled_frc_get_row()];
                panel_api_set_active_row(&row, 1);
            }
        } else if ((unsigned char)oled_frc_get_row() != PANEL_MODE_120HZ) {
            /* The other picture-in-picture modes: always the 120 Hz mode. */
            oled_frc_set_row(PANEL_MODE_120HZ);
            row = panel_mode_rows[(unsigned char)oled_frc_get_row()];
            panel_api_set_active_row(&row, 0);
            FRCConfigPostFRC(sys_config_byte_3 != 0, panel_output_rate, 1);
        }
    }

    /* Show what the panel controller reports next to what was chosen here. */
    reported_row = oled_get_frame_rate_control();
    dbg_printf("\033[1;32mSYSAPI_GetPanelParamStruct %x,%x\r\n\033[m", (unsigned short)reported_row, (unsigned char)oled_frc_get_row());
}
