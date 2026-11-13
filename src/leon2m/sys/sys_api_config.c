/* sys_api_config  (FUN_a014c7bc)
 *
 * Apply one system configuration command (0..32) with its arguments.
 * Name basis: proven - variable-argument command switch on stSysConfig; cases print
 *   SYSAPI_ConfigSystemPostFRCLockMode and ...MainBypass; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014c7bc @ 0xa014c7bc-0xa014ce84 (434 words). Flags -mcpu=v8 -O3 -g. The five variable arguments
 * are spilled at %fp+0x48 (va_list). The command switch builds a jump table of 33 entries (its entries are code
 * addresses - 0xA0060000).
 * Source forms the exact build depends on:
 *  - case order 17, 0, 4, 5, 6, 7, 12, 13, 9, 14, 15, 16, 18, 19, 20, 21, 22, 23, 24, 31, 32, 8 gives the firmware's
 *    block layout;
 *  - inner switches on the colour in 21 / 22 (a signed compare tree on the promoted byte); unsigned '/ 100U';
 *  - case 32 as an if-chain (a switch merges 0 / 1 into a range test);
 *  - case 14: apply_path_mode is a static copy in this file of sys_api_set_channel_scaling_mode (sys_api_set_channel_scaling_mode,
 *    which lives in another source file and cannot be inlined from there), inlined: an identity switch on the
 *    mode, then a switch on the channel where case 0 stores path_mode_ch0 and breaks, case 1 stores path_mode_ch1 and calls
 *    sys_set_channel_path_mode(1, mode), and the default jumps with 'goto out' to the shared call. That goto puts
 *    the case 1 arm before the mode switch's blocks; a plain fall-through gives the mode blocks first.
 */
#include <stdarg.h>

/* The commands. Each sets one part of the system configuration record (sys_config) and applies it. The
   numbers 1..3, 10, 11 and 25..30 do nothing. */
enum sys_config_command {
    SYS_CFG_BIT31             = 0,      /* word 0 bit 31, and channel 0 flag bit 23 */
    SYS_CFG_FRC_LOCK_MODE     = 4,      /* word 0 bit 27 */
    SYS_CFG_MAIN_BYPASS       = 5,      /* word 0 bit 26 */
    SYS_CFG_BIT25             = 6,      /* word 0 bit 25; restarts all channels */
    SYS_CFG_BIT24             = 7,      /* word 0 bit 24 */
    SYS_CFG_LINK_OPTION_ENABLE = 8,
    SYS_CFG_CHANNEL_LINK_OPTION = 9,
    SYS_CFG_BYTE_3            = 12,     /* sys_config_byte_3 */
    SYS_CFG_CONVERTER_MODE    = 13,     /* word +4 bits 28..31; restarts all channels */
    SYS_CFG_PATH_MODE         = 14,     /* word +4 bits 24..27 (channel 0) or 20..23 (channel 1) */
    SYS_CFG_OPTION_BYTE       = 15,     /* byte +6 */
    SYS_CFG_AUTO_LEVEL_MODE   = 16,     /* byte +7 */
    SYS_CFG_BRIGHTNESS        = 17,
    SYS_CFG_COLOR_GAIN        = 18,     /* byte +9 */
    SYS_CFG_COLOR_MATRIX_PARAM = 19,    /* byte +0xA */
    SYS_CFG_PICTURE_MODE      = 20,     /* byte +0xB */
    SYS_CFG_RGB_GAIN          = 21,     /* bytes +0xC..+0xE */
    SYS_CFG_RGB_OFFSET        = 22,     /* bytes +0xF..+0x11 */
    SYS_CFG_GAMMA_SELECTION   = 23,     /* byte +0x18 */
    SYS_CFG_RESPONSE_LEVEL    = 24,     /* byte +0x1C */
    SYS_CFG_BYTE_0x2E         = 31,     /* byte +0x2E */
    SYS_CFG_BLURFREE_MODE     = 32      /* word +0x38 */
};

/* Byte offsets of the system configuration record that are written through its byte view. */
#define SYS_CONFIG_BYTE_3           3
#define SYS_CONFIG_OPTION_BYTE      6
#define SYS_CONFIG_PICTURE_MODE     0xb
#define SYS_CONFIG_GAMMA_SELECTION  0x18
#define SYS_CONFIG_RESPONSE_LEVEL   0x1c

#define DEVICE_SETTINGS_BIT27   0x8000000   /* word 0 of the device settings: keeps sys_config bit 31 at 0 */
#define CHANNEL_FLAG_23         0x800000    /* channel 0 flag word (+0x70) bit 23: set while sys_config bit 31 is 0 */
#define FRC_LOCK_ACTIVE_LINES_MAX 0xfff     /* rows with more active lines never get the lock mode */
#define RATE_240HZ              0x960       /* 2400 tenths of a hertz */
#define RESPONSE_LEVEL_5        5           /* level for which only picture block 8 is stopped */

/* Second argument of sys_restart_channel: the state the channel goes back to. */
#define RESTART_MODESEARCH      1
#define RESTART_CAPTURE         2
#define RESTART_WAIT2SHOW       4

#define RGB_RED   0
#define RGB_GREEN 1
#define RGB_BLUE  2
#define GAIN_BASE    0x38               /* register value of gain 0; each gain step adds 2 */
#define OFFSET_BASE  0x1c               /* register value of offset 0; each offset step adds 2 */

/* Words 0 and +4 of the system configuration record. */
struct sys_config_bits {
    unsigned int bit31:1, bit30:1, bit29:1, bit28:1;
    unsigned int frc_lock_mode:1;       /* bit 27 */
    unsigned int main_bypass:1;         /* bit 26 */
    unsigned int bit25:1, bit24:1, bits_0_23:24;
    unsigned int converter_mode:4;      /* word +4 bits 28..31 */
    unsigned int path_mode_ch0:4;       /* bits 24..27 */
    unsigned int path_mode_ch1:4;       /* bits 20..23 */
    unsigned int bits_0_19:20;
};
union sys_config_record { struct sys_config_bits f; unsigned char b[0x30]; };

/* Channel record 0: only its flag word. */
struct channel_record { unsigned char pad[0x70]; unsigned int flags; };

/* The working copy of the active panel timing row, its first fields. */
struct panel_timing_row { unsigned int flags; unsigned short half_0x04; unsigned char display_mode, bpc; unsigned short active_size0; unsigned short active_size1; };

extern struct panel_timing_row *panel_working_row_ptr;
extern union sys_config_record sys_config;
extern struct channel_record channel_records;
extern unsigned int device_settings, sys_config_blurfree_mode;
extern unsigned char sys_config_auto_level_mode, sys_config_color_gain, sys_config_color_matrix_param, sys_config_picture_mode, sys_config_red_gain, sys_config_green_gain,
    sys_config_blue_gain, sys_config_red_offset, sys_config_green_offset, sys_config_blue_offset, sys_config_panel_power_all_channels;
extern int dbg_printf();
extern void panel_blurfree_set_mode(int on, int mode);
extern void pq_block8_stop(void);
extern void pq_apply_response_level(unsigned char);
extern void pq_load_gamma(unsigned char);
extern void pq_apply_picture_mode(unsigned char);
extern void pq_color_matrix_set_red_gain(unsigned short), pq_color_matrix_set_green_gain(unsigned short), pq_color_matrix_set_blue_gain(unsigned short);
extern void pq_color_matrix_set_red_offset(unsigned char), pq_color_matrix_set_green_offset(unsigned char), pq_color_matrix_set_blue_offset(unsigned char);
extern void pq_color_matrix_set_param_second(unsigned char);
extern void sys_restart_channel(int channel, int mode);
extern void FRCConfigPostFRC(int timing_form, unsigned short rate, int force);
extern void input_api_set_channel_link_option(unsigned char, unsigned char);
extern void input_api_set_link_option_enable(unsigned char);
extern void input_power_on_ports_by_mask(int, int);
extern int input_set_port_link_byte3(unsigned int, unsigned int);
extern void pq_auto_level_task(int);
extern void sys_poll_events_stub_copy14(void);
extern void sys_set_channel_path_mode(unsigned char channel, unsigned char mode);
extern void pq_color_matrix_rebuild(unsigned char);
extern void panel_api_set_brightness(unsigned char);
extern void osd_set_option_field(unsigned int, unsigned char);

/* Command 14: store the path mode of channel 0 or 1 and apply it with sys_set_channel_path_mode; for any other
   channel only sys_set_channel_path_mode is called. The mode switch maps 0..4 to themselves. */
static void apply_path_mode(unsigned char channel, unsigned char mode)
{
    switch (mode) {
    case 0: mode = 0; break;
    case 1: mode = 1; break;
    case 2: mode = 2; break;
    case 3: mode = 3; break;
    case 4: mode = 4; break;
    }
    switch (channel) {
    case 0:
        sys_config.f.path_mode_ch0 = mode;
        break;
    case 1:
        sys_config.f.path_mode_ch1 = mode;
        sys_set_channel_path_mode(1, mode);
        return;
    default:
        goto out;
    }
out:
    sys_set_channel_path_mode(channel, mode);
}

/*
 * Apply one system configuration command. The arguments that follow `command` depend on it (one byte value
 * unless noted). No routine calls it by name.
 *
 *   0  BIT31             bit 31 = value, or 0 when device settings bit 27 is set; channel 0 flag bit 23 is
 *                        set while bit 31 is 0 and cleared while it is 1
 *   4  FRC_LOCK_MODE     print; bit 27 = 1 when value is not 0 and the working panel row has at most 0xFFF active
 *                        lines, else 0 (as SYSAPI_ConfigSystemPostFRCLockMode)
 *   5  MAIN_BYPASS       print; bit 26 = value
 *   6  BIT25             bit 25 = value; channels 0..3 back to MODE_MODESEARCH
 *   7  BIT24             bit 24 = value; input_power_on_ports_by_mask(0x10, 1); port 0's link byte 3 = bit 24
 *   8  LINK_OPTION_ENABLE   input_api_set_link_option_enable(value)
 *   9  CHANNEL_LINK_OPTION  two values: input_api_set_channel_link_option(first, second)
 *  12  BYTE_3            when it changes: from non-zero to non-zero, channel 0 back to MODE_WAIT2SHOW; otherwise
 *                        the output is programmed for 240.0 Hz and channel 0 goes back to MODE_CAPTURE
 *  13  CONVERTER_MODE    converter_mode = value; channels 0..3 back to MODE_CAPTURE
 *  14  PATH_MODE         channel, mode: apply_path_mode
 *  15  OPTION_BYTE       byte +6 = value; osd_set_option_field with it for fields 0 and 1
 *  16  AUTO_LEVEL_MODE   byte +7 = value; 1 runs pq_auto_level_task(1)
 *  17  BRIGHTNESS        panel_api_set_brightness(value); nothing is stored here
 *  18..20                colour gain, colour matrix parameter, picture mode: store and apply
 *  21  RGB_GAIN          colour (0..2), gain: store the gain, register value 0x38 + 2 * gain
 *  22  RGB_OFFSET        colour (0..2), offset: store the offset, register value 0x1C + 2 * offset
 *  23  GAMMA_SELECTION   byte +0x18 = value; load that gamma set, then apply the picture mode again
 *  24  RESPONSE_LEVEL    byte +0x1C = value; stop picture block 8, and for any level but 5 apply the level
 *  31  BYTE_0x2E         byte +0x2E = value (GlobalModeHandler: panel power followed for channel 0 or all)
 *  32  BLURFREE_MODE     one word, stored at +0x38: 0 = blur reduction off, 1 = on in GEN1, 2 and 3 = on in GEN2
 *                        (panel_blurfree_set_mode(value, 0) for 0 and 1, (1, 1) for 2 and 3)
 * Any other command does nothing.
 */
void sys_api_config(unsigned int command, ...)
{
    va_list ap;
    unsigned char value, second; unsigned int m;   /* m is not used */
    unsigned int word;

    va_start(ap, command);
    switch (command) {
    case SYS_CFG_BRIGHTNESS:
        value = va_arg(ap, int);
        panel_api_set_brightness(value);
        break;
    case SYS_CFG_BIT31:
        value = va_arg(ap, int);
        if (device_settings & DEVICE_SETTINGS_BIT27) sys_config.f.bit31 = 0;
        else sys_config.f.bit31 = value;
        if (sys_config.f.bit31) channel_records.flags &= ~CHANNEL_FLAG_23;
        else channel_records.flags |= CHANNEL_FLAG_23;
        break;
    case SYS_CFG_FRC_LOCK_MODE:
        value = va_arg(ap, int);
        dbg_printf("SYSAPI_ConfigSystemPostFRCLockMode = %d \r\n", value);
        if (value && panel_working_row_ptr->active_size1 <= FRC_LOCK_ACTIVE_LINES_MAX) sys_config.f.frc_lock_mode = 1;
        else sys_config.f.frc_lock_mode = 0;
        break;
    case SYS_CFG_MAIN_BYPASS:
        value = va_arg(ap, int);
        dbg_printf("SYSAPI_ConfigSystemPostFRCMainBypass = %d \r\n", value);
        sys_config.f.main_bypass = value;
        break;
    case SYS_CFG_BIT25:
        value = va_arg(ap, int);
        sys_config.f.bit25 = value;
        sys_restart_channel(0, RESTART_MODESEARCH);
        sys_restart_channel(1, RESTART_MODESEARCH);
        sys_restart_channel(2, RESTART_MODESEARCH);
        sys_restart_channel(3, RESTART_MODESEARCH);
        break;
    case SYS_CFG_BIT24:
        value = va_arg(ap, int);
        sys_config.f.bit24 = value;
        input_power_on_ports_by_mask(0x10, 1);
        input_set_port_link_byte3(0, sys_config.f.bit24);
        break;
    case SYS_CFG_BYTE_3:
        value = va_arg(ap, int);
        if (sys_config.b[SYS_CONFIG_BYTE_3] != value) {
            if (sys_config.b[SYS_CONFIG_BYTE_3] != 0 && value != 0) sys_restart_channel(0, RESTART_WAIT2SHOW);
            else {
                FRCConfigPostFRC(0, RATE_240HZ, 1);
                sys_restart_channel(0, RESTART_CAPTURE);
            }
            sys_config.b[SYS_CONFIG_BYTE_3] = value;
        }
        break;
    case SYS_CFG_CONVERTER_MODE:
        value = va_arg(ap, int);
        sys_config.f.converter_mode = value;
        sys_restart_channel(0, RESTART_CAPTURE);
        sys_restart_channel(1, RESTART_CAPTURE);
        sys_restart_channel(2, RESTART_CAPTURE);
        sys_restart_channel(3, RESTART_CAPTURE);
        break;
    case SYS_CFG_CHANNEL_LINK_OPTION:
        value = va_arg(ap, int);
        second = va_arg(ap, int);
        input_api_set_channel_link_option(value, second);
        break;
    case SYS_CFG_PATH_MODE:
        apply_path_mode(va_arg(ap, int), va_arg(ap, int));
        break;
    case SYS_CFG_OPTION_BYTE:
        value = va_arg(ap, int);
        sys_config.b[SYS_CONFIG_OPTION_BYTE] = value;
        osd_set_option_field(value, 0);
        osd_set_option_field(sys_config.b[SYS_CONFIG_OPTION_BYTE], 1);
        break;
    case SYS_CFG_AUTO_LEVEL_MODE:
        value = va_arg(ap, int);
        sys_config_auto_level_mode = value;
        if (value == 1) pq_auto_level_task(1);
        else sys_poll_events_stub_copy14();
        break;
    case SYS_CFG_COLOR_GAIN:
        value = va_arg(ap, int);
        sys_config_color_gain = value;
        pq_color_matrix_rebuild(value);
        break;
    case SYS_CFG_COLOR_MATRIX_PARAM:
        value = va_arg(ap, int);
        sys_config_color_matrix_param = value;
        pq_color_matrix_set_param_second(value);
        break;
    case SYS_CFG_PICTURE_MODE:
        value = va_arg(ap, int);
        sys_config_picture_mode = value;
        pq_apply_picture_mode(value);
        break;
    case SYS_CFG_RGB_GAIN:
        value = va_arg(ap, int);         /* colour */
        second = va_arg(ap, int);        /* gain; (gain * 200 + 50) / 100 is 2 * gain */
        switch (value) {
        case RGB_RED:
            sys_config_red_gain = second;
            pq_color_matrix_set_red_gain((second * 200 + 50) / 100U + GAIN_BASE);
            break;
        case RGB_GREEN:
            sys_config_green_gain = second;
            pq_color_matrix_set_green_gain((second * 200 + 50) / 100U + GAIN_BASE);
            break;
        case RGB_BLUE:
            sys_config_blue_gain = second;
            pq_color_matrix_set_blue_gain((second * 200 + 50) / 100U + GAIN_BASE);
            break;
        }
        break;
    case SYS_CFG_RGB_OFFSET:
        value = va_arg(ap, int);         /* colour */
        second = va_arg(ap, int);        /* offset */
        switch (value) {
        case RGB_RED:
            sys_config_red_offset = second;
            pq_color_matrix_set_red_offset((second * 200 + 50) / 100U + OFFSET_BASE);
            break;
        case RGB_GREEN:
            sys_config_green_offset = second;
            pq_color_matrix_set_green_offset((second * 200 + 50) / 100U + OFFSET_BASE);
            break;
        case RGB_BLUE:
            sys_config_blue_offset = second;
            pq_color_matrix_set_blue_offset((second * 200 + 50) / 100U + OFFSET_BASE);
            break;
        }
        break;
    case SYS_CFG_GAMMA_SELECTION:
        value = va_arg(ap, int);
        sys_config.b[SYS_CONFIG_GAMMA_SELECTION] = value;
        pq_load_gamma(value);
        pq_apply_picture_mode(sys_config.b[SYS_CONFIG_PICTURE_MODE]);
        break;
    case SYS_CFG_RESPONSE_LEVEL:
        value = va_arg(ap, int);
        sys_config.b[SYS_CONFIG_RESPONSE_LEVEL] = value;
        if (value == RESPONSE_LEVEL_5) pq_block8_stop();
        else {
            pq_block8_stop();
            pq_apply_response_level(sys_config.b[SYS_CONFIG_RESPONSE_LEVEL]);
        }
        break;
    case SYS_CFG_BYTE_0x2E:
        value = va_arg(ap, int);
        sys_config_panel_power_all_channels = value;
        break;
    case SYS_CFG_BLURFREE_MODE:
        word = va_arg(ap, unsigned int);
        sys_config_blurfree_mode = word;
        if (word == 0) panel_blurfree_set_mode(word, 0);
        else if (word == 1) panel_blurfree_set_mode(word, 0);
        else if (word == 2) panel_blurfree_set_mode(1, 1);
        else if (word == 3) panel_blurfree_set_mode(1, 1);
        break;
    case SYS_CFG_LINK_OPTION_ENABLE:
        value = va_arg(ap, int);
        input_api_set_link_option_enable(value);
        break;
    }
    va_end(ap);
}
