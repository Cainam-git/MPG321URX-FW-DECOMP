/* ddc_handle_request  (FUN_a0088724)
 *
 * Decode and answer one DDC/CI request (GetVCP, SetVCP, capabilities, timing)
 * Note: GetVCP and SetVCP are switch statements on the setting code; the compiler turned them into jump
 *   tables.
 * Name basis: proven - texts 'GetVCP', 'DDCCi_SetVCP_Feature', 'CMDOP_SET_CAP'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0088724 @ 0xa0088724-0xa0089f10 (1531 words), flags -mcpu=v8 -O3 -g.
 * Jump tables (before the routine, rt + 0xa0060000): 0x27e58 SetVCP (255), 0x28254 GetVCP (256),
 * 0x27da4 GetVCP 0xcc (11), 0x27dd0 SetVCP 0x14 (12), 0x27e00 GetVCP 0x0c (8), 0x27e20 SetVCP 0xcc (14).
 * Source forms the exact build depends on:
 *  - the case order of the GetVCP and SetVCP switches is the order in which the register choices of the case
 *    blocks come out right (the final block layout is the block reorder pass's);
 *  - professional_flags bit 31 is a bit-field (0xa00893f0 'st [%l0 + 0x11c]' before 0xa00893f8 'ldub [%l0 + 9]');
 *  - the 0xfa read-back byte is a local, last_byte (0xa0089240 'ldub [%fp - 129], %o3', 'cmp %o3, %o0', stored
 *    again 0xa0089278); the reply pointer q is declared at the top of the 0xf8..0xfa block (the firmware forms it
 *    at the inner dispatch, 0xa0088b78), and only the 0xfa replies store through it;
 *  - the colour temperature byte is addressed in two ways: by its own address in SetVCP 0x0c (0xa0089e68
 *    'stb %o5, [%g1 + 0x2a1]') and as record field +0x11 in SetVCP 0x10..0x1a (0xa0089a14 'stb %o0, [%o4 + 0x11]');
 *  - SetVCP 0x62 reads the mute bit into a local before the volume store, and the volume byte is stored through
 *    the record's byte view SETTINGS_BYTE (0xa0089820 'ld [%o4 + 0x290], %o3' before 0xa0089830
 *    'stb %l3, [%l2 + 0x10]'); GetVCP 0x62 reads the same byte by its own address (0xa0089738
 *    'ldub [%l7 + 0x2a0], %o4'). ddc_tool_set_level_percent writes that byte the same way;
 *  - the GetVCP reply bytes 6..9 are stored in ascending order; 16-bit values are formed as
 *    'value = F() * 10; hi = value >> 8; lo = value' with an unsigned short value;
 *  - answer_capabilities and answer_timing take the port through a pointer and read it after their print;
 *  - the four printed texts are the firmware's own, byte for byte.
 */
extern unsigned char ddc_api_get_request_state(void);
extern int ddc_api_take_request();
extern void ddc_api_queue_reply(unsigned char cmd, unsigned short len, unsigned char *buf);
extern int dbg_printf(const char *fmt, ...);
extern unsigned short input_api_get_timing_field(unsigned char ch, unsigned int id);
extern unsigned char sys_api_get_channel_flag29(unsigned char ch);
extern void *memcpy(void *dst, const void *src, int n);
extern unsigned char input_api_is_channel_sync_mode5(unsigned char ch);
extern unsigned char input_api_is_channel_sync_mode_2to4(unsigned char ch);
extern void input_api_set_port_signal(unsigned char p, unsigned char on);
extern int sys_api_return_ff(void);
extern int sys_api_return_ff_copy(void);
extern void irq_empty_handler_copy70();
extern void irq_empty_handler_copy71();
extern int sys_api_get_channel_sync_mode(unsigned char ch);
extern void sys_poll_events_stub_copy20(unsigned char ch);
extern void audio_api_set_mute(unsigned char ch);
extern void ddc_tool_answer_read_request(unsigned char port, unsigned char *req);
extern void ddc_tool_dispatch_command(unsigned char port, unsigned char *req);
extern void osd_close_menu(void);
extern unsigned char sys_api_get_channel_state_code(unsigned char ch);
extern void hdmi_user_send_cec_action4(void);
extern void audio_user_apply_mute(void);
extern void UserSetProMode(void);
extern void pq_api_set_fga_word(unsigned short v);
extern void pq_fga_handle_command(unsigned char *req);
extern void sys_api_copy_channel_position_fields(unsigned char v);
extern void pq_user_apply_color_gain(void);
extern void sys_user_apply_brightness(void);
extern void sys_user_factory_reset(void);
extern void sys_user_reset_settings_keep_source(void);
extern void ddc_apply_maker_vcp_set(unsigned char *req, unsigned char *buf);
extern void ddc_answer_maker_vcp_get(unsigned char *req, unsigned char *buf);
extern void pq_user_apply_gamma(void);
extern void pq_user_apply_blue_offset(void);
extern void pq_user_apply_green_offset(void);
extern void pq_user_apply_red_offset(void);
extern void audio_user_apply_level(void);
extern void sys_api_select_channel_source(unsigned char a, unsigned char b);
extern void sys_user_reset_display_path(void);
extern void sys_vcp_set_field_14_percent(unsigned char v);
extern void sys_vcp_set_field_f_percent(unsigned char v);
extern void sys_vcp_set_field_b_percent(unsigned char v);
extern void sys_vcp_set_field_4_percent(unsigned char v);
extern void pq_user_set_custom_blue(void);
extern void pq_user_apply_custom_green(void);
extern void pq_user_apply_custom_red(void);
extern void pq_user_apply_color_settings(void);
extern void sys_user_save_mode_slot(void);
extern void sys_vcp_reset_positions(void);
extern unsigned char sys_vcp_get_field_4_percent(void);
extern unsigned char sys_vcp_get_field_15(void);
extern unsigned char sys_vcp_return_ff(void);
extern unsigned char sys_vcp_get_field_b_percent(void);
extern unsigned short nvram_get_device_setting(unsigned int id);
extern unsigned char pq_fga_get_status(void);
extern unsigned char pq_fga_get_table_mask(void);
extern unsigned char pq_fga_get_color_mask(void);
extern void *memset(void *dst, int c, unsigned int n);

/* The parts of the user settings record (docs/RECORDS.md) that this file uses through the record. */
struct user_settings_record {
    unsigned int word_0x0;                      /* +0x00: bit 11 SETTINGS_AUDIO_MUTE, bit 15 SETTINGS_WORD0_BIT15 */
    unsigned char pad4[5];
    unsigned char brightness, contrast;         /* +0x09, +0x0A */
    unsigned char pad0b[5];
    unsigned char audio_level;                  /* +0x10, written through SETTINGS_BYTE(0x10) */
    unsigned char color_temperature;            /* +0x11: COLOR_TEMP_* */
    unsigned char red_gain, green_gain, blue_gain; /* +0x12..+0x14: the custom colour values */
    unsigned char pad15[9];
    unsigned char input_source;                 /* +0x1E */
    unsigned char pad1f[0xa8 - 0x1f];
    struct { unsigned int bits_12_31 : 20, pro_selected : 1, : 3, adaptive_sync : 1, bits_0_6 : 7; } gaming_flags; /* +0xA8: bit 11 Pro (1) / Game (0), bit 7 Adaptive-Sync */
    unsigned char padac[0x11c - 0xac];
    struct { unsigned int auto_level : 1, bits_0_30 : 31; } professional_flags; /* +0x11C: bit 31 automatic level */
    unsigned char pad120[0x181 - 0x120];
    unsigned char pro_mode;                     /* +0x181: the Professional mode */
};
extern struct user_settings_record user_settings;
#define SETTINGS_BYTE(n) (((unsigned char *)&user_settings)[n])   /* the record taken as a byte array */
extern unsigned char user_settings_language, user_settings_contrast, user_settings_audio_level, user_settings_color_temperature, user_settings_red_gain, user_settings_green_gain,
    user_settings_blue_gain, user_settings_red_black_level, user_settings_green_black_level, user_settings_blue_black_level, user_settings_theme_mode, user_settings_input_source, user_settings_gamma;
extern unsigned char ddc_pending_events, ddc_reply_checksum, ddc_new_control_value, pq_fga_state_bits;
/* Working record of the 0xF8..0xFA block write (SetVCP 0xFA). */
struct ddc_block_write {
    unsigned char address;                      /* request byte 4, passed on as the first argument */
    unsigned char sum;                          /* sum of the 128 bytes read back */
    unsigned short block_end;                   /* 0x80 or 0x100: end of the 128-byte block the write lies in */
};
extern struct ddc_block_write ddc_request_record;
extern const unsigned char ddc_color_preset_codes[];
extern const char ddc_capability_string[], ddc_capability_string_alt[];

/* Bits of the settings word +0. */
#define SETTINGS_AUDIO_MUTE       0x800     /* bit 11: audio_user_apply_mute passes it to audio_api_set_mute */
#define SETTINGS_WORD0_BIT15      0x8000    /* bit 15: set and read only over VCP 0xCA here */

/* ddc_pending_events: ddc_post_pending_event posts each bit as a DDC/CI application event, and
   APPActionDispatcher runs the action of that event. */
#define DDC_EVENT_SAVE_SETTINGS   0x01      /* event 0xC0: save the user settings record */
#define DDC_EVENT_STORE_MODE_ROW  0x02      /* event 0xC2: store the mode row of the shown channel */
#define DDC_EVENT_POWER_ON        0x10      /* event 0xC4: power on */
#define DDC_EVENT_POWER_OFF       0x20      /* event 0xC5: power off */
#define DDC_EVENT_POWER_SAVING    0x40      /* event 0xC6: power saving */

/* Byte 0 of every reply, and the value the XOR of a whole request must give: the DDC/CI address
   (docs/MAP.md). */
#define DDC_ADDRESS               0x6e
#define DDC_CHECKSUM_SEED         0x50      /* first value of the reply XOR checksum */

/* Request byte 2: the command. Byte 1 holds the length in bits 0..6. */
enum ddc_command {
    DDC_CMD_GET_VCP      = 0x01,            /* "GetVCP" */
    DDC_CMD_SET_VCP      = 0x03,            /* "DDCCi_SetVCP_Feature" */
    DDC_CMD_GET_TIMING   = 0x07,            /* "CMDOP_GET_TIMING"; reply command 0x4E */
    DDC_CMD_SAVE         = 0x0c,            /* raises the settings and mode row save events */
    DDC_CMD_TOOL_COMMAND = 0xc0,            /* factory tool command (ddc_tool_dispatch_command) */
    DDC_CMD_TOOL_READ    = 0xd0,            /* factory tool read (ddc_tool_answer_read_request) */
    DDC_CMD_CAPABILITIES = 0xf3             /* "CMDOP_SET_CAP"; reply command 0xE3 */
};
/* The capability string lists the same commands: cmds(01 02 03 07 0C 4E F3 E3). */

/* Request byte 3 of GetVCP and SetVCP: the setting code. Codes without a name here are answered with
   fixed values, or their purpose is not shown. SetVCP request bytes 4 and 5 carry the value (high, low). */
enum vcp_code {
    VCP_NEW_CONTROL_VALUE  = 0x02,          /* ddc_new_control_value */
    VCP_FACTORY_RESET      = 0x04,          /* SetVCP: sys_user_factory_reset */
    VCP_RESET_05           = 0x05,          /* SetVCP: re-applies contrast and brightness */
    VCP_RESET_POSITIONS    = 0x06,          /* SetVCP: sys_vcp_reset_positions */
    VCP_PICTURE_RESET      = 0x08,          /* SetVCP: sys_user_reset_settings_keep_source */
    VCP_COLOR_TEMPERATURE  = 0x0c,          /* 3000 + 50 * value, see answer_get_vcp / carry_out_set_vcp */
    VCP_POSITION_FIELD_4   = 0x0e,          /* sys_vcp_*_field_4_percent */
    VCP_BRIGHTNESS         = 0x10,          /* docs/MAP.md */
    VCP_CONTRAST           = 0x12,          /* docs/MAP.md */
    VCP_COLOR_PRESET       = 0x14,          /* ddc_color_preset_codes */
    VCP_RED_GAIN           = 0x16,
    VCP_GREEN_GAIN         = 0x18,
    VCP_BLUE_GAIN          = 0x1a,
    VCP_POSITION_FIELD_B   = 0x20,          /* sys_vcp_*_field_b_percent */
    VCP_POSITION_FIELD_F   = 0x30,          /* sys_vcp_set_field_f_percent; GetVCP answers sys_vcp_return_ff */
    VCP_POSITION_FIELD_14  = 0x3e,          /* sys_vcp_*_field_14* */
    VCP_INPUT_SOURCE       = 0x60,          /* docs/MAP.md */
    VCP_VOLUME             = 0x62,          /* docs/MAP.md; the audio level */
    VCP_RED_BLACK_LEVEL    = 0x6c,          /* docs/RECORDS.md */
    VCP_GREEN_BLACK_LEVEL  = 0x6e,
    VCP_BLUE_BLACK_LEVEL   = 0x70,
    VCP_GAMMA              = 0x72,          /* docs/RECORDS.md: 0x50 -> 2, 0x78 -> 1 */
    VCP_AUDIO_MUTE         = 0x8d,          /* SETTINGS_AUDIO_MUTE: 1 muted, 2 not */
    VCP_LINE_RATE          = 0xac,          /* GetVCP: timing field 0 * 100, three bytes */
    VCP_REFRESH_RATE       = 0xae,          /* GetVCP: timing field 1 * 10 */
    VCP_ON_TIME_HOURS      = 0xc0,          /* GetVCP: device setting 7 */
    VCP_WORD0_BIT15        = 0xca,          /* SETTINGS_WORD0_BIT15: 1 set, 2 clear */
    VCP_LANGUAGE           = 0xcc,
    VCP_POWER_MODE         = 0xd6,          /* docs/MAP.md */
    VCP_THEME_MODE         = 0xdc,          /* GetVCP: theme mode; SetVCP: Professional modes 4..6 */
    VCP_ADAPTIVE_SYNC      = 0xec,          /* GetVCP only: gaming flag bit 7 */
    VCP_FGA                = 0xf1,          /* factory colour calibration data (FGA) commands */
    VCP_PORT_SIGNAL_KEYED  = 0xf8,          /* as 0xF9, after the four key bytes 66 99 55 AA */
    VCP_PORT_SIGNAL        = 0xf9,          /* input_api_set_port_signal for all ports */
    VCP_BLOCK_WRITE        = 0xfa,          /* 32-byte block write with read-back check */
    VCP_MAKER              = 0xfe           /* ddc_answer_maker_vcp_get / ddc_apply_maker_vcp_set */
};

#define PERCENT_MAX               100       /* SetVCP values of percent settings are limited to this */
#define PORT_TYPE_5               5         /* port type answered as "not supported" for the position codes */

/* Values of the colour temperature byte (settings +0x11). 0..3 are the menu's Cool, Normal, Warm and
   Customization; the other values are named by the VCP 0x0C value that reads them back. */
#define COLOR_TEMP_COOL           0
#define COLOR_TEMP_NORMAL         1
#define COLOR_TEMP_WARM           2
#define COLOR_TEMP_CUSTOM         3
#define COLOR_TEMP_7500           5
#define COLOR_TEMP_8200           6
#define COLOR_TEMP_11500          7
#define COLOR_TEMP_9              9         /* set by VCP 0x14 value 1; brightness and contrast change it to Normal */

/* Request byte 4 of VCP 0xF1. */
#define FGA_CMD_2A                0x2a      /* stores value * 800 + 0x500 with pq_api_set_fga_word first */
#define FGA_QUERY_STATUS          0x15      /* GetVCP: pq_fga_get_status */
#define FGA_QUERY_MASKS           0x25      /* GetVCP: pq_fga_get_table_mask, pq_fga_get_color_mask */
#define FGA_STATE_DONE            0x20      /* bit of pq_fga_state_bits; prints 'APPUserData.bFGADone' */

#define DEVICE_SETTING_ON_TIME_HOURS 7      /* nvram_get_device_setting field */
#define TIMING_LINE_RATE          0         /* input_api_get_timing_field fields */
#define TIMING_REFRESH_RATE       1         /* in tenths of a hertz */
#define TIMING_FIELD_3            3         /* code 0..3 from channel record byte +0x0A */
#define MAIN_CHANNEL              0
#define ALL_PORTS                 0xfe      /* input_api_set_port_signal: every port */
#define BLOCK_SIZE                0x80      /* bytes read back by SetVCP 0xFA */
#define BLOCK_WRITE_BYTES         0x20      /* data bytes in one SetVCP 0xFA request (request bytes 7..0x26) */


/*
 * Finish a reply and queue it for the 8051: the XOR checksum (seeded with 0x50) of the first `length` bytes
 * goes into byte `length`, and length + 1 bytes are queued.
 */
static void queue_reply(unsigned char port, unsigned char *reply, unsigned char length)
{
    unsigned char i;

    ddc_reply_checksum = DDC_CHECKSUM_SEED;
    for (i = 0; i < length; i++)
        ddc_reply_checksum ^= reply[i];
    reply[i] = ddc_reply_checksum;
    ddc_api_queue_reply(port, length + 1, reply);
}

/*
 * Answer a GetVCP request: read one setting and send its value.
 *
 *   port     the port the request came from (handed to the reply)
 *   request  the request; byte 3 = setting code, byte 4 = sub-code of the maker codes
 *
 * Phases:
 *   1. Clear a 40-byte reply and fill its head: 6E 88 02, result 0, the code, 0.
 *   2. By the code, fill bytes 6..9: bytes 6-7 the largest value (high, low), bytes 8-9 the present value.
 *      An unknown code, and the position codes on a port of type 5, set result byte 3 to 1 with largest value 0xFF.
 *   3. Queue the reply with its checksum: 10 bytes, or 0x1E / 0x22 for the maker sub-codes 0xE1, 0xE9 / 0xEF.
 *
 * Always returns 0, so the menu stays open.
 */
static unsigned char answer_get_vcp(unsigned char port, unsigned char *request)
{
    unsigned char reply[40];
                               /* GetVCP */
    unsigned char length = 10, value;
    unsigned short i, value16;

    /* Phase 1: the reply head. Byte 1 = 0x80 + the number of bytes after it (before the checksum). */
    for (i = 0; i <= 0x27; i++)
        reply[i] = 0;
    reply[0] = DDC_ADDRESS;
    reply[1] = 0x88;
    reply[2] = 2;
    reply[3] = 0;
    reply[4] = request[3];
    reply[5] = 0;
    dbg_printf("\nGetVCP : %d\r\n", request[3]);

    /* Phase 2: the value of the setting. */
    switch (request[3]) {
    case VCP_FGA:
        if (request[4] == FGA_QUERY_STATUS) {
            reply[6] = pq_fga_get_status(); reply[7] = 0xaa; reply[8] = 0xbb; reply[9] = 0xcc;
        } else if (request[4] == FGA_QUERY_MASKS) {
            reply[6] = pq_fga_get_table_mask(); reply[7] = pq_fga_get_color_mask(); reply[8] = 0xbb; reply[9] = 0xcc;
        }
        break;
    case VCP_POSITION_FIELD_14:
        if (input_api_is_channel_sync_mode5(MAIN_CHANNEL) == 1) {
            reply[3] = 1; reply[6] = 0; reply[7] = 0xff; reply[8] = 0; reply[9] = 0;
        } else {
            reply[6] = 0; reply[7] = PERCENT_MAX; reply[8] = 0; reply[9] = sys_vcp_get_field_15();
        }
        break;
    case VCP_INPUT_SOURCE:
        /* Input Source setting -> VCP value; sources 5, 6, 7, 8, 12, 13 have their own values, all others 1. */
        reply[6] = 0; reply[7] = 3; reply[8] = 0;
        value = user_settings_input_source;
        if (value == 5) reply[9] = 0x11;
        else if (value == 6) reply[9] = 0x12;
        else if (value == 7) reply[9] = 0x53;
        else if (value == 8) reply[9] = 0x54;
        else if (value == 0xc) reply[9] = 0x0f;
        else if (value == 0xd) reply[9] = 0x10;
        else reply[9] = 1;
        break;
    case 0xb2:
        reply[6] = 0; reply[7] = 8; reply[8] = 0; reply[9] = 1;
        break;
    case 0xc6:
        reply[6] = 0xff; reply[7] = 0xff; reply[8] = 0; reply[9] = 0x6f;
        break;
    case 0xb6:
        reply[6] = 0; reply[7] = 4; reply[8] = 0; reply[9] = 3;
        break;
    case VCP_VOLUME:
        reply[6] = 0; reply[7] = PERCENT_MAX; reply[8] = 0; reply[9] = user_settings_audio_level;
        break;
    case VCP_CONTRAST:
        reply[6] = 0; reply[7] = PERCENT_MAX; reply[8] = 0; reply[9] = user_settings_contrast;
        break;
    case 0xdf:
        reply[6] = 0xff; reply[7] = 0xff; reply[8] = 2; reply[9] = 1;
        break;
    case VCP_COLOR_TEMPERATURE:
        /* As 3000 + 50 * value: 9300, 5000, 7500, 8200, 11500, else 6500 (the limits of carry_out_set_vcp). */
        reply[6] = 0; reply[7] = 0xaa; reply[8] = 0;
        switch (user_settings_color_temperature) {
        case COLOR_TEMP_COOL: reply[9] = 0x7e; break;
        case COLOR_TEMP_WARM: reply[9] = 0x28; break;
        case COLOR_TEMP_7500: reply[9] = 0x5a; break;
        case COLOR_TEMP_8200: reply[9] = 0x68; break;
        case COLOR_TEMP_11500: reply[9] = 0xaa; break;
        default: reply[9] = 0x46; break;
        }
        break;
    case VCP_POSITION_FIELD_4:
        if (input_api_is_channel_sync_mode5(MAIN_CHANNEL) == 1) {
            reply[3] = 1; reply[6] = 0; reply[7] = 0xff; reply[8] = 0; reply[9] = 0;
        } else {
            reply[6] = 0; reply[7] = PERCENT_MAX; reply[8] = 0; reply[9] = sys_vcp_get_field_4_percent();
        }
        break;
    case 0xf4:
        /* Fixed answers for the sub-codes 0x10, 0x11 and 0x13; any other sub-code gets zeros. */
        value = request[4];
        if (value == 0x10) {
            reply[6] = 5; reply[7] = 0; reply[8] = 0x3d; reply[9] = 0x0c;
        } else if (value == 0x11) {
            reply[6] = 0; reply[7] = 0; reply[8] = 0xbb; reply[9] = 0xcc;
        } else if (value == 0x13) {
            reply[6] = 0xa0; reply[7] = 0x3e; reply[8] = 0xbb; reply[9] = 0xcc;
        }
        break;
    case VCP_NEW_CONTROL_VALUE:
        reply[6] = 0; reply[7] = 0xff; reply[8] = 0; reply[9] = ddc_new_control_value;
        break;
    case VCP_ADAPTIVE_SYNC:
        reply[6] = 0; reply[7] = 1; reply[8] = 0;
        if (!user_settings.gaming_flags.adaptive_sync)
            reply[9] = 0;
        else
            reply[9] = 1;
        break;
    case VCP_RED_GAIN:
        reply[6] = 0; reply[7] = PERCENT_MAX; reply[8] = 0; reply[9] = user_settings_red_gain;
        break;
    case VCP_GREEN_GAIN:
        reply[6] = 0; reply[7] = PERCENT_MAX; reply[8] = 0; reply[9] = user_settings_green_gain;
        break;
    case VCP_BLUE_GAIN:
        reply[6] = 0; reply[7] = PERCENT_MAX; reply[8] = 0; reply[9] = user_settings_blue_gain;
        break;
    case VCP_POSITION_FIELD_B:
        if (input_api_is_channel_sync_mode5(MAIN_CHANNEL) == 1) {
            reply[3] = 1; reply[6] = 0; reply[7] = 0xff; reply[8] = 0; reply[9] = 0;
        } else {
            reply[6] = 0; reply[7] = PERCENT_MAX; reply[8] = 0; reply[9] = sys_vcp_get_field_b_percent();
        }
        break;
    case VCP_POSITION_FIELD_F:
        if (input_api_is_channel_sync_mode5(MAIN_CHANNEL) == 1) {
            reply[3] = 1; reply[6] = 0; reply[7] = 0xff; reply[8] = 0; reply[9] = 0;
        } else {
            reply[6] = 0; reply[7] = PERCENT_MAX; reply[8] = 0; reply[9] = sys_vcp_return_ff();
        }
        break;
    case VCP_BRIGHTNESS:
        /* Reading the brightness also switches the automatic level off. */
        user_settings.professional_flags.auto_level = 0;
        reply[6] = 0; reply[7] = PERCENT_MAX; reply[8] = 0; reply[9] = user_settings.brightness;
        break;
    case VCP_RESET_POSITIONS:
        if (input_api_is_channel_sync_mode5(MAIN_CHANNEL) == 1) {
            reply[3] = 1; reply[7] = 0xff;
        } else
            reply[7] = 1;
        reply[6] = 0; reply[8] = 0; reply[9] = 0;
        break;
    case VCP_LINE_RATE: {
        unsigned int line_rate, line_rate_high;

        /* 24 bits: byte 7 from a second read of the same field. */
        reply[6] = 0xff;
        line_rate = input_api_get_timing_field(MAIN_CHANNEL, TIMING_LINE_RATE) * 100;
        line_rate_high = input_api_get_timing_field(MAIN_CHANNEL, TIMING_LINE_RATE) * 100;
        reply[7] = line_rate_high >> 16; reply[8] = line_rate >> 8; reply[9] = line_rate;
        break;
    }
    case VCP_REFRESH_RATE:
        reply[6] = 0xff; reply[7] = 0xff;
        value16 = input_api_get_timing_field(MAIN_CHANNEL, TIMING_REFRESH_RATE) * 10;
        reply[8] = value16 >> 8; reply[9] = value16;
        break;
    case VCP_RED_BLACK_LEVEL:
        reply[6] = 0; reply[7] = PERCENT_MAX; reply[8] = 0; reply[9] = user_settings_red_black_level;
        break;
    case VCP_GREEN_BLACK_LEVEL:
        reply[6] = 0; reply[7] = PERCENT_MAX; reply[8] = 0; reply[9] = user_settings_green_black_level;
        break;
    case VCP_FACTORY_RESET: case VCP_RESET_05: case VCP_PICTURE_RESET: case 0xff:
        reply[6] = 0; reply[7] = 1; reply[8] = 0; reply[9] = 0;
        break;
    case 0x0b:
        reply[6] = 0xff; reply[7] = 0xff; reply[8] = 0; reply[9] = 0x32;
        break;
    case VCP_POWER_MODE:
        /* State code of the main channel: 0 -> 4, 1 -> 2, any other -> 1. */
        reply[6] = 0; reply[7] = 4; reply[8] = 0;
        if (!sys_api_get_channel_state_code(MAIN_CHANNEL))
            reply[9] = 4;
        else if (sys_api_get_channel_state_code(MAIN_CHANNEL) == 1)
            reply[9] = 2;
        else
            reply[9] = 1;
        break;
    case 0x1e:
    case 0x1f:
        if (sys_api_get_channel_sync_mode(MAIN_CHANNEL) == PORT_TYPE_5) {
            reply[3] = 1; reply[6] = 0; reply[7] = 0xff; reply[8] = 0; reply[9] = 0;
        } else {
            reply[6] = 0; reply[7] = 1; reply[8] = 0; reply[9] = 0;
        }
        break;
    case VCP_AUDIO_MUTE:
        reply[6] = 0; reply[7] = 2; reply[8] = 0; reply[9] = 2 - ((user_settings.word_0x0 >> 11) & 1);
        break;
    case VCP_ON_TIME_HOURS:
        reply[6] = 0xff; reply[7] = 0xff;
        value16 = nvram_get_device_setting(DEVICE_SETTING_ON_TIME_HOURS);
        reply[8] = value16 >> 8; reply[9] = value16;
        break;
    case 0xc9:
        reply[6] = 0xff; reply[7] = 0xff; reply[8] = 0; reply[9] = 0;
        break;
    case VCP_WORD0_BIT15:
        reply[6] = 0; reply[7] = 2; reply[8] = 0; reply[9] = 2 - ((user_settings.word_0x0 >> 15) & 1);
        break;
    case VCP_LANGUAGE:
        /* Menu language -> VCP value (the inverse of the map in carry_out_set_vcp); 1 (English) and any
           language without its own value answer 2. */
        reply[6] = 0; reply[7] = 0xff; reply[8] = 0;
        switch (user_settings_language) {
        case 2: reply[9] = 3; break;
        case 3: reply[9] = 4; break;
        case 4: reply[9] = 5; break;
        case 5: reply[9] = 0x0a; break;
        case 8: reply[9] = 9; break;
        case 9: reply[9] = 8; break;
        case 10: reply[9] = 0x0d; break;
        default: reply[9] = 2; break;
        }
        break;
    case VCP_BLUE_BLACK_LEVEL:
        reply[6] = 0; reply[7] = PERCENT_MAX; reply[8] = 0; reply[9] = user_settings_blue_black_level;
        break;
    case VCP_THEME_MODE:
        reply[6] = 0; reply[7] = 0x13; reply[8] = 0; reply[9] = user_settings_theme_mode;
        break;
    case VCP_COLOR_PRESET:
        reply[6] = 0; reply[7] = 0x0b; reply[8] = 0; reply[9] = ddc_color_preset_codes[user_settings_color_temperature];
        break;
    case VCP_MAKER:
        /* Only a request with more than two bytes after the length byte; ddc_answer_maker_vcp_get fills the
           reply, which is longer for the sub-codes 0xEF, 0xE1 and 0xE9. */
        if (request[1] > 0x82) {
            value = request[4];
            if (value == 0xef)
                length = 0x22;
            else if (value == 0xe1 || value == 0xe9)
                length = 0x1e;
            ddc_answer_maker_vcp_get(request, reply);
        }
        break;
    case 0xc8:
        reply[6] = 0xff; reply[7] = 0xff; reply[8] = 0; reply[9] = 0x12;
        break;
    case 0x52:
        reply[6] = 0; reply[7] = 0xff; reply[8] = 0; reply[9] = 0;
        break;
    default:
        /* Not supported. */
        reply[3] = 1; reply[6] = 0; reply[7] = 0xff; reply[8] = 0; reply[9] = 0;
        break;
    }

    /* Phase 3: send it. */
    queue_reply(port, reply, length);
    return 0;
}

/*
 * Carry out a SetVCP request: change one setting and apply it.
 *
 *   port     the port the request came from (for the replies of 0xF8..0xFA and 0xFE)
 *   request  the request; byte 3 = setting code, bytes 4 and 5 = the value (high, low)
 *
 * Phases:
 *   1. Print the code.
 *   2. By the code: limit the value (percent settings to 100), store it in the user settings record, call the
 *      routine that applies it, and for most codes raise the DDC/CI event that saves it: DDC_EVENT_SAVE_SETTINGS
 *      for record fields, DDC_EVENT_STORE_MODE_ROW for the position fields. VCP 0xD6 raises a power event.
 *   3. Codes 0xF8..0xFA and 0xFE send a reply of their own; all other codes send none.
 *
 * Returns 1 (the caller closes the menu), or 0 for VCP 0xEC, which changes nothing. Unknown codes return 1.
 */
static int carry_out_set_vcp(unsigned char port, unsigned char *request)
{
    unsigned char reply[40], read_back[128];
    int close_menu = 1;
    unsigned char value;
    unsigned char i;

    /* Phase 1. */
    dbg_printf("DDCCi_SetVCP_Feature %d \r\n", request[3]);

    /* Phase 2: the setting. */
    switch (request[3]) {
    case VCP_POSITION_FIELD_4:
        if (request[5] > PERCENT_MAX) request[5] = PERCENT_MAX;
        sys_vcp_set_field_4_percent(request[5]);
        ddc_pending_events |= DDC_EVENT_STORE_MODE_ROW;
        break;
    case VCP_FGA:
        /* Factory colour calibration: command 0x2A stores a value first, then the command is carried out. */
        if (request[4] == FGA_CMD_2A)
            pq_api_set_fga_word(request[5] * 800 + 0x500);
        pq_fga_handle_command(request);
        if (pq_fga_state_bits & FGA_STATE_DONE)
            dbg_printf("\x1b[0;38mAPPUserData.bFGADone\x1b[m");
        ddc_pending_events |= DDC_EVENT_SAVE_SETTINGS;
        break;
    case VCP_NEW_CONTROL_VALUE:
        /* Only the values 1, 2 and 0xFF are taken. */
        if (request[4] == 0 && (request[5] == 1 || request[5] == 2 || request[5] == 0xff))
            ddc_new_control_value = request[5];
        break;
    case VCP_COLOR_TEMPERATURE: {
        /* The value counts as 3000 + 50 * value; a non-zero high byte counts as above every limit. The limits lie
           between the values GetVCP 0x0C answers. */
        unsigned short temperature = request[5] * 50 + 3000;

        if (request[4])
            temperature = 0xffff;

        if (temperature <= 5749)
            user_settings_color_temperature = COLOR_TEMP_WARM;
        else if (temperature <= 6999)
            user_settings_color_temperature = COLOR_TEMP_NORMAL;
        else if (temperature <= 7849)
            user_settings_color_temperature = COLOR_TEMP_7500;
        else if (temperature <= 8749)
            user_settings_color_temperature = COLOR_TEMP_8200;
        else if (temperature <= 10399)
            user_settings_color_temperature = COLOR_TEMP_COOL;
        else
            user_settings_color_temperature = COLOR_TEMP_11500;
        pq_user_apply_color_settings();
        ddc_pending_events |= DDC_EVENT_SAVE_SETTINGS;
        break;
    }
    case VCP_GAMMA:
        /* Any other value keeps the gamma; it is applied again all the same. */
        if (request[5] == 0x50)
            user_settings_gamma = 2;
        else if (request[5] == 0x78)
            user_settings_gamma = 1;
        pq_user_apply_gamma();
        ddc_pending_events |= DDC_EVENT_SAVE_SETTINGS;
        break;
    case VCP_PICTURE_RESET:
        sys_user_reset_settings_keep_source();
        ddc_pending_events |= DDC_EVENT_SAVE_SETTINGS;
        break;
    case VCP_BRIGHTNESS:
        /* Colour temperature 9 is replaced by Normal before the brightness changes. */
        if (user_settings.color_temperature == COLOR_TEMP_9) {
            user_settings.color_temperature = COLOR_TEMP_NORMAL;
            pq_user_apply_color_settings();
        }
        user_settings.brightness = request[5];
        sys_user_apply_brightness();
        sys_user_save_mode_slot();
        ddc_pending_events |= DDC_EVENT_SAVE_SETTINGS;
        break;
    case VCP_FACTORY_RESET:
        sys_user_factory_reset();
        ddc_pending_events |= DDC_EVENT_SAVE_SETTINGS;
        break;
    case VCP_CONTRAST:
        if (user_settings.color_temperature == COLOR_TEMP_9) {
            user_settings.color_temperature = COLOR_TEMP_NORMAL;
            pq_user_apply_color_settings();
        }
        user_settings.contrast = request[5];
        pq_user_apply_color_gain();             /* applies settings byte +0x0A */
        sys_user_save_mode_slot();
        ddc_pending_events |= DDC_EVENT_SAVE_SETTINGS;
        break;
    case VCP_RESET_05:
        /* sys_api_copy_channel_position_fields acts only on modes 0 and 1, so the two calls change nothing. */
        sys_api_copy_channel_position_fields(2);
        sys_api_copy_channel_position_fields(3);
        pq_user_apply_color_gain();
        sys_user_apply_brightness();
        ddc_pending_events |= DDC_EVENT_SAVE_SETTINGS;
        break;
    case VCP_COLOR_PRESET:
        /* VCP value -> colour temperature; an unknown value keeps the present one. GetVCP 0x14 reads the value
           back through ddc_color_preset_codes, which is not the inverse of this map. */
        switch (request[5]) {
        case 1: value = COLOR_TEMP_9; break;
        case 4: value = COLOR_TEMP_WARM; break;
        case 5: value = COLOR_TEMP_NORMAL; break;
        case 6: value = COLOR_TEMP_7500; break;
        case 7: value = COLOR_TEMP_8200; break;
        case 8: value = COLOR_TEMP_COOL; break;
        case 10: value = COLOR_TEMP_11500; break;
        case 11: value = COLOR_TEMP_CUSTOM; break;
        default: value = user_settings.color_temperature; break;
        }
        if (user_settings.color_temperature != value) {
            user_settings.color_temperature = value;
            pq_user_apply_color_settings();
            ddc_pending_events |= DDC_EVENT_SAVE_SETTINGS;
        }
        break;
    case VCP_RED_GAIN:
        /* A gain switches the colour temperature to Customization. */
        user_settings.color_temperature = COLOR_TEMP_CUSTOM;
        if (request[5] > PERCENT_MAX) request[5] = PERCENT_MAX;
        user_settings.red_gain = request[5];
        pq_user_apply_custom_red();
        ddc_pending_events |= DDC_EVENT_SAVE_SETTINGS;
        break;
    case VCP_RESET_POSITIONS:
        if (sys_api_get_channel_sync_mode(MAIN_CHANNEL) != PORT_TYPE_5)
            sys_vcp_reset_positions();
        break;
    case VCP_GREEN_GAIN:
        user_settings.color_temperature = COLOR_TEMP_CUSTOM;
        if (request[5] > PERCENT_MAX) request[5] = PERCENT_MAX;
        user_settings.green_gain = request[5];
        pq_user_apply_custom_green();
        ddc_pending_events |= DDC_EVENT_SAVE_SETTINGS;
        break;
    case VCP_BLUE_GAIN:
        user_settings.color_temperature = COLOR_TEMP_CUSTOM;
        if (request[5] > PERCENT_MAX) request[5] = PERCENT_MAX;
        user_settings.blue_gain = request[5];
        pq_user_set_custom_blue();
        ddc_pending_events |= DDC_EVENT_SAVE_SETTINGS;
        break;
    case 0x1e:
        /* The called routine is empty; only the save event remains. */
        if (input_api_is_channel_sync_mode_2to4(MAIN_CHANNEL) == 1) {
            sys_poll_events_stub_copy20(MAIN_CHANNEL);
            ddc_pending_events |= DDC_EVENT_STORE_MODE_ROW;
        }
        break;
    case VCP_POSITION_FIELD_B:
        if (request[5] > PERCENT_MAX) request[5] = PERCENT_MAX;
        sys_vcp_set_field_b_percent(request[5]);
        ddc_pending_events |= DDC_EVENT_STORE_MODE_ROW;
        break;
    case VCP_POSITION_FIELD_14:
        if (request[5] > PERCENT_MAX) request[5] = PERCENT_MAX;
        sys_vcp_set_field_14_percent(request[5]);
        ddc_pending_events |= DDC_EVENT_STORE_MODE_ROW;
        break;
    case VCP_POWER_MODE:
        /* Value 1 powers on from state code 0 or 1; 2 enters power saving unless the state code is 1;
           4 and 5 power off unless the state code is 0. Other values do nothing. */
        value = request[5];
        if (value == 1) {
            if (!sys_api_get_channel_state_code(MAIN_CHANNEL) || sys_api_get_channel_state_code(MAIN_CHANNEL) == 1)
                ddc_pending_events |= DDC_EVENT_POWER_ON;
        } else if (value == 2) {
            if (sys_api_get_channel_state_code(MAIN_CHANNEL) != 1)
                ddc_pending_events |= DDC_EVENT_POWER_SAVING;
        } else if (value == 4) {
            if (sys_api_get_channel_state_code(MAIN_CHANNEL))
                ddc_pending_events |= DDC_EVENT_POWER_OFF;
        } else if (value == 5) {
            if (sys_api_get_channel_state_code(MAIN_CHANNEL))
                ddc_pending_events |= DDC_EVENT_POWER_OFF;
        }
        break;
    case VCP_WORD0_BIT15:
        if (request[5] == 1)
            user_settings.word_0x0 |= SETTINGS_WORD0_BIT15;
        else if (request[5] == 2)
            user_settings.word_0x0 &= ~SETTINGS_WORD0_BIT15;
        ddc_pending_events |= DDC_EVENT_SAVE_SETTINGS;
        break;
    case VCP_POSITION_FIELD_F:
        if (request[5] > PERCENT_MAX) request[5] = PERCENT_MAX;
        sys_vcp_set_field_f_percent(request[5]);
        ddc_pending_events |= DDC_EVENT_STORE_MODE_ROW;
        break;
    case VCP_LANGUAGE:
        /* VCP value -> menu language; an unknown value gives 1 (English). */
        switch (request[5]) {
        case 2: value = 1; break;
        case 3: value = 2; break;
        case 4: value = 3; break;
        case 5: value = 4; break;
        case 8: value = 9; break;
        case 9: value = 8; break;
        case 10: value = 5; break;
        case 13: value = 0x0a; break;
        default: value = 1; break;
        }
        user_settings_language = value;
        hdmi_user_send_cec_action4();
        ddc_pending_events |= DDC_EVENT_SAVE_SETTINGS;
        break;
    case VCP_INPUT_SOURCE:
        /* VCP value -> Input Source setting; an unknown value gives source 5. This is not the exact inverse of
           the GetVCP map: source 7 reads back as 0x53 but is set with 0x13, and sources 0 and 2 both read back
           as 1. Then the main channel takes the new source and the display path restarts. */
        value = request[5];
        if (value == 3) user_settings.input_source = 2;
        else if (value == 0x11) user_settings.input_source = 5;
        else if (value == 0x12) user_settings.input_source = 6;
        else if (value == 0x13) user_settings.input_source = 7;
        else if (value == 0xf) user_settings.input_source = 0xc;
        else if (value == 0x10) user_settings.input_source = 0xd;
        else if (value == 1) user_settings.input_source = 0;
        else user_settings.input_source = 5;
        sys_api_select_channel_source(MAIN_CHANNEL, user_settings.input_source);
        sys_user_reset_display_path();
        ddc_pending_events |= DDC_EVENT_SAVE_SETTINGS;
        break;
    case VCP_ADAPTIVE_SYNC:
        /* Read only: nothing changes and the menu stays open. */
        close_menu = 0;
        break;
    case VCP_RED_BLACK_LEVEL:
        if (request[5] > PERCENT_MAX) request[5] = PERCENT_MAX;
        user_settings_red_black_level = request[5];
        pq_user_apply_red_offset();
        ddc_pending_events |= DDC_EVENT_SAVE_SETTINGS;
        break;
    case VCP_GREEN_BLACK_LEVEL:
        if (request[5] > PERCENT_MAX) request[5] = PERCENT_MAX;
        user_settings_green_black_level = request[5];
        pq_user_apply_green_offset();
        ddc_pending_events |= DDC_EVENT_SAVE_SETTINGS;
        break;
    case VCP_BLUE_BLACK_LEVEL:
        if (request[5] > PERCENT_MAX) request[5] = PERCENT_MAX;
        user_settings_blue_black_level = request[5];
        pq_user_apply_blue_offset();
        ddc_pending_events |= DDC_EVENT_SAVE_SETTINGS;
        break;
    case VCP_THEME_MODE:
        /* Values 0x0D, 0x0E and 0x0F select Pro (not Game) with Professional mode 4, 5 or 6. */
        if (request[5] == 0xd) {
            user_settings.gaming_flags.pro_selected = 1; user_settings.pro_mode = 4; UserSetProMode();
        }
        if (request[5] == 0xe) {
            user_settings.gaming_flags.pro_selected = 1; user_settings.pro_mode = 5; UserSetProMode();
        }
        if (request[5] == 0xf) {
            user_settings.gaming_flags.pro_selected = 1; user_settings.pro_mode = 6; UserSetProMode();
        }
        ddc_pending_events |= DDC_EVENT_SAVE_SETTINGS;
        break;
    case VCP_VOLUME:
        /* A new level also ends the mute. */
        {
            unsigned char mute = (user_settings.word_0x0 >> 11) & 1;
            SETTINGS_BYTE(0x10) = request[5];
            if (mute) {
                user_settings.word_0x0 &= ~SETTINGS_AUDIO_MUTE;
                audio_api_set_mute(0);
            }
        }
        audio_user_apply_level();
        ddc_pending_events |= DDC_EVENT_SAVE_SETTINGS;
        break;
    case VCP_AUDIO_MUTE:
        if (request[5] == 1)
            user_settings.word_0x0 |= SETTINGS_AUDIO_MUTE;
        else if (request[5] == 2)
            user_settings.word_0x0 &= ~SETTINGS_AUDIO_MUTE;
        audio_user_apply_mute();
        ddc_pending_events |= DDC_EVENT_SAVE_SETTINGS;
        break;
    case VCP_PORT_SIGNAL_KEYED:
    case VCP_PORT_SIGNAL:
    case VCP_BLOCK_WRITE: {
        unsigned char *q = reply;

        /* Phase 3 for these codes: they answer with replies of their own. The checksum seed is set, but no
           checksum byte is added to these replies. */
        switch (request[3]) {
        case VCP_PORT_SIGNAL_KEYED:
            if (request[4] != 0x66 || request[5] != 0x99 || request[6] != 0x55 || request[7] != 0xaa)
                break;
            /* fall through */
        case VCP_PORT_SIGNAL:
            /* Signal on for every port; the reply is 6E 83 02 FF FF (both called routines return 0xFF). */
            input_api_set_port_signal(ALL_PORTS, 1);
            reply[0] = DDC_ADDRESS;
            reply[1] = 0x83;
            reply[2] = 2;
            reply[3] = sys_api_return_ff();
            reply[4] = sys_api_return_ff_copy();
            ddc_reply_checksum = DDC_CHECKSUM_SEED;
            ddc_api_queue_reply(port, 5, reply);
            break;
        case VCP_BLOCK_WRITE: {
            /* Request bytes: 4 = address, 5 = echoed, 6 = offset, 7..0x26 = 32 data bytes.
               1. Acknowledge at once: 6E 85, bytes 5 and 6, 0x20, the address, and the low byte of the
                  block end of the previous request.
               2. Note the end of the 128-byte block the 32 bytes fall in, and hand the bytes to the write
                  routine (address, 0xA0, offset, 32, data).
               3. When the write reaches that block end, read the block back and check it: its bytes must add
                  up to 0 (else reply 0xEE with the sum), and its last byte must equal the last data byte of the
                  request (else reply 0xEF with both).
               Both the write and the read routine are empty here (they return at once), so read_back keeps the
               zeros of the memset. */
            unsigned char address, echo, offset, last_byte;

            memset(read_back, 0, 0x80);
            address = request[4];
            ddc_request_record.address = address;
            offset = request[6];
            echo = request[5];
            q[0] = DDC_ADDRESS;
            q[1] = 0x85;
            q[2] = echo;
            q[3] = offset;
            q[4] = BLOCK_WRITE_BYTES;
            q[5] = address;
            q[6] = ddc_request_record.block_end;
            ddc_reply_checksum = DDC_CHECKSUM_SEED;
            ddc_api_queue_reply(port, 7, q);
            if (offset + BLOCK_WRITE_BYTES <= BLOCK_SIZE)
                ddc_request_record.block_end = 0x80;
            else
                ddc_request_record.block_end = 0x100;
            irq_empty_handler_copy70(ddc_request_record.address, 0xa0, offset, BLOCK_WRITE_BYTES, request + 7);
            if (offset + BLOCK_WRITE_BYTES < ddc_request_record.block_end)
                break;
            if (ddc_request_record.block_end == 0x80)
                irq_empty_handler_copy71(ddc_request_record.address, 0xa0, 0, BLOCK_SIZE, read_back);
            else
                irq_empty_handler_copy71(ddc_request_record.address, 0xa0, 0x80, BLOCK_SIZE, read_back);
            ddc_request_record.sum = 0;
            for (i = 0; i < 0x80; i++)
                ddc_request_record.sum += read_back[i];
            if (ddc_request_record.sum != 0) {
                q[0] = DDC_ADDRESS; q[1] = 0x85; q[2] = echo; q[3] = offset; q[4] = 0xee; q[5] = ddc_request_record.address;
                q[6] = ddc_request_record.sum;
                ddc_reply_checksum = DDC_CHECKSUM_SEED;
                ddc_api_queue_reply(port, 7, q);
            } else {
                last_byte = read_back[0x7f];
                if (last_byte != request[0x26]) {
                    q[0] = DDC_ADDRESS; q[1] = 0x85; q[2] = echo; q[3] = offset; q[4] = 0xef; q[5] = request[0x26]; q[6] = last_byte;
                    ddc_reply_checksum = DDC_CHECKSUM_SEED;
                    ddc_api_queue_reply(port, 7, q);
                }
            }
            break;
        }
        }
        break;
    }
    case VCP_MAKER:
        /* Phase 3 for the maker code: ddc_apply_maker_vcp_set fills a 10-byte reply. */
        ddc_apply_maker_vcp_set(request, reply);
        queue_reply(port, reply, 10);
        break;
    }
    return close_menu;
}

/*
 * Answer a capabilities request with up to 32 bytes of the capability string.
 *
 *   port_ptr  the port the request came from
 *   request   bytes 3 and 4 = offset into the string (high, low)
 *
 * Phases:
 *   1. Copy both forms of the capability string from ROM; ports of type 5 use the second form.
 *   2. Reply head: 6E, length byte, E3, the offset.
 *   3. Past the end of the string: 32 spaces. Otherwise the bytes from the offset up to the end of the string
 *      (its closing zero not included), at most 32; at the end this is an empty piece.
 *   4. Queue the reply with its checksum. Byte 1 = 0x80 + 3 + the number of string bytes.
 */
static void answer_capabilities(unsigned char *port_ptr, unsigned char *request)
{
    unsigned char reply[40], text[0x137], text_alt[0x128];
    unsigned char port, i;
    unsigned char length;
    unsigned short offset, count, last;

    /* Phase 1. */
    dbg_printf("CMDOP_SET_CAP\r\n");
    port = *port_ptr;
    memcpy(text, ddc_capability_string, sizeof(text));
    memcpy(text_alt, ddc_capability_string_alt, sizeof(text_alt));
    last = input_api_is_channel_sync_mode5(MAIN_CHANNEL) == 1 ? sizeof(text_alt) - 1 : sizeof(text) - 1;
    offset = request[3] << 8 | request[4];

    /* Phase 2. */
    reply[0] = DDC_ADDRESS;
    reply[2] = 0xe3;
    reply[3] = request[3];
    reply[4] = request[4];

    /* Phase 3. */
    if (offset > last) {
        reply[1] = 0xa3;
        count = 0x20;
        for (i = 0; i < count; i++)
            reply[5 + i] = 0x20;
        length = 0x25;
    } else {
        count = last - offset;
        if (count > 0x20) {
            reply[1] = 0xa3;
            count = 0x20;
            length = 0x25;
        } else {
            reply[1] = count + 0x83;
            length = count + 5;
        }
        if (input_api_is_channel_sync_mode5(MAIN_CHANNEL) == 1) {
            for (i = 0; i < count; i++) {
                if (offset + i >= sizeof(text_alt))
                    break;
                reply[5 + i] = text_alt[offset + i];
            }
        } else {
            for (i = 0; i < count; i++) {
                if (offset + i >= sizeof(text))
                    break;
                reply[5 + i] = text[offset + i];
            }
        }
    }

    /* Phase 4. */
    queue_reply(port, reply, length);
}

/*
 * Answer a timing request with the measured timing of the main channel.
 *
 * Reply: 6E 06 4E, a status byte, the line rate * 10 (two bytes) and the refresh rate * 10 (two bytes),
 * then the checksum. Status bits 0..1 = timing field 3 with the codes 1 and 2 swapped; bit 7 = channel
 * flag bit 29.
 */
static void answer_timing(unsigned char *port_ptr)
{
    unsigned char reply[40];
    unsigned char port, field_code;
    unsigned short value16;

    dbg_printf("CMDOP_GET_TIMING\r\n");
    reply[0] = DDC_ADDRESS;
    reply[1] = 6;
    reply[2] = 0x4e;
    port = *port_ptr;
    if (input_api_get_timing_field(MAIN_CHANNEL, TIMING_FIELD_3) == 3)
        field_code = 3;
    else if (input_api_get_timing_field(MAIN_CHANNEL, TIMING_FIELD_3) == 2)
        field_code = 1;
    else if (input_api_get_timing_field(MAIN_CHANNEL, TIMING_FIELD_3) == 1)
        field_code = 2;
    else
        field_code = 0;
    if (!sys_api_get_channel_flag29(MAIN_CHANNEL))
        reply[3] = field_code;
    else
        reply[3] = field_code | 0x80;
    value16 = input_api_get_timing_field(MAIN_CHANNEL, TIMING_LINE_RATE) * 10;
    reply[4] = value16 >> 8;
    reply[5] = value16;
    value16 = input_api_get_timing_field(MAIN_CHANNEL, TIMING_REFRESH_RATE) * 10;
    reply[6] = value16 >> 8;
    reply[7] = value16;
    queue_reply(port, reply, 8);
}

/*
 * Take one DDC/CI request from the 8051 and answer it. Called from ddc_run_request_task, the last of the
 * application main-loop steps.
 *
 * Phases:
 *   1. Return when no request is waiting; otherwise copy it out (port, length, up to 40 bytes).
 *   2. Check it: the XOR of bytes 0 .. (byte 1 & 0x7F) + 2 must be 0x6E; a request that fails is dropped
 *      without an answer.
 *   3. Hand it on by the command in byte 2: GetVCP, SetVCP, timing, capabilities, the factory tool's commands
 *      and reads, or command 0x0C, which raises the events that save the user settings and the mode row.
 *   4. Close the on-screen menu after a SetVCP that returned 1, after command 0x0C and after any unknown
 *      command; GetVCP, timing, capabilities and the factory tool's requests leave it open.
 */
void ddc_handle_request(void)
{
    unsigned char request[40] = { 0 };
    unsigned char port;
    unsigned short length;
    unsigned char checksum = 0, close_menu = 1;

    /* Phase 1: take the request. */
    if (!ddc_api_get_request_state())
        return;
    ddc_api_take_request(&port, &length, request);

    /* Phase 2: the checksum over the whole request; the length the 8051 gave is not used. */
    length = (request[1] & 0x7f) + 3;
    while (length != 0) {
        length--;
        checksum ^= request[length];
    }
    if (checksum != DDC_ADDRESS)
        return;

    /* Phase 3: the command. */
    switch (request[2]) {
    case DDC_CMD_GET_VCP:
        close_menu = answer_get_vcp(port, request);
        break;
    case DDC_CMD_TOOL_READ:
        ddc_tool_answer_read_request(port, request);
        close_menu = 0;
        break;
    case DDC_CMD_TOOL_COMMAND:
        ddc_tool_dispatch_command(port, request);
        close_menu = 0;
        break;
    case DDC_CMD_SET_VCP:
        close_menu = carry_out_set_vcp(port, request);
        break;
    case DDC_CMD_GET_TIMING:
        answer_timing(&port);
        close_menu = 0;
        break;
    case DDC_CMD_SAVE:
        ddc_pending_events |= DDC_EVENT_SAVE_SETTINGS | DDC_EVENT_STORE_MODE_ROW;
        break;
    case DDC_CMD_CAPABILITIES:
        answer_capabilities(&port, request);
        close_menu = 0;
        break;
    }

    /* Phase 4. */
    if (close_menu)
        osd_close_menu();
}
