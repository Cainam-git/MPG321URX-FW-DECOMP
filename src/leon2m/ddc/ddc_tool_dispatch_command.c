/* ddc_tool_dispatch_command  (FUN_a00d2a98)
 *
 * Carry out a factory tool command and send its answer.
 * Name basis: proven - switch on the command bytes ('c' functions and 's' values); called from the DDC/CI
 *   request handler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d2a98 @ 0xa00d2a98-0xa00d3650 (3000 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the reply is a structure whose byte 6 is an 8-bit bit-field (reply.value) written by the 's' cases, while
 *    the clear loop and the header stores use the byte view REPLY_BYTES of it (with a plain byte array GCC's
 *    store motion sinks the reply byte 6 = request[6] store into the 's' cases);
 *  - the 'c' routines are static copies of the neighbouring routines, inlined, defined in their address order;
 *    the 'c' cases are listed in the address order of the routines they run;
 *  - the source order of the 's' cases sets the block order;
 *  - the check flag (factory record halfword +0x18, bit 15) is a 1-bit bit-field, set after the reply.value store
 *    in case TOOL_GET_OLED_ERROR_COUNT; ddc_tool_enter_factory_mode's copy sets the factory mode bit of settings
 *    word +0 through a 1-bit bit-field and tests it through the whole word.
 */

/* The parts of the four records that this file uses through the record (docs/RECORDS.md). */
struct user_settings_record {
    union {
        unsigned int word;
        struct { unsigned int bits_10_31 : 22, bit9 : 1, bits_0_8 : 9; } low;
        struct { unsigned int bits_15_31 : 17, factory_mode : 1, bits_0_13 : 14; } high;
    } word_0x0;                                 /* +0x00: bit 14 = factory mode, bit 9 (sys_user_apply_config_bit31) */
    unsigned char pad004[4];
    unsigned char language, brightness, contrast;       /* +0x08 (1 = English), +0x09, +0x0A */
    unsigned char pad00b[5];
    unsigned char audio_level, color_temperature;       /* +0x10, +0x11 (COLOR_TEMP_*) */
    unsigned char pad012[0xa8 - 0x12];
    unsigned int gaming_flags;                  /* +0xA8: bit 6 = RGB LED */
    unsigned char pad0ac[0x1d5 - 0xac];
    unsigned char burn_in_flag, byte_0x1d6;     /* +0x1D5, +0x1D6 */
    unsigned char pad1d7[0x1ec - 0x1d7];
    union {
        unsigned int word;
        struct { unsigned int bits_8_31 : 24, type_c_pd_charge : 1, bits_0_6 : 7; } bits;
    } boundary_detection;                       /* +0x1EC: read as a word, bit 7 = Type C PD Charge */
    unsigned char pad1f0[6];
    unsigned short factory_marker;              /* +0x1F6: FACTORY_MODE_MARKER while factory mode is on */
    unsigned char pad1f8[4];
};
struct factory_record_layout {
    unsigned char byte_0x0, byte_0x1;
    unsigned char serial_length;                /* +0x02 */
    unsigned char serial[0xd];                  /* +0x03: the 13 serial characters TOOL_ANSWER_SERIAL reads back */
    unsigned char key_test_bits;                /* +0x10: one bit per front key passed in the key test */
    unsigned char pad11[3];
    unsigned char byte_0x14;                    /* +0x14 */
    unsigned char oled_error_count;             /* +0x15: shown after "Panel ERR Count" in the factory menu */
    unsigned short oled_error_reg10;            /* +0x16: the OLED register 0x10 value saved with that count */
    unsigned short check : 1, bits_0_14 : 15;   /* +0x18: bit 15 is shown after "Check" in the factory menu */
    unsigned char pad1a[2];
};
/* Three colour bytes of one colour temperature in the part record. */
struct color_gains { unsigned char red, green, blue; };
struct part_record_layout {
    unsigned char pad00[6];
    struct color_gains warm50;                  /* +0x06 */
    struct color_gains normal65;                /* +0x09 */
    unsigned char pad0c[0x12 - 0xc];
    struct color_gains cool93;                  /* +0x12 */
    unsigned char pad15[0x21 - 0x15];
    struct color_gains row_0x21;                /* +0x21: copied like the three above; what it holds is not shown */
};
struct device_settings_head {
    unsigned int word_0x0, word_0x4;
    unsigned int on_time_minutes : 8,           /* +0x08: on-time, minutes */
                 on_time_hours : 16,            /* +0x09: on-time, hours */
                 brightness_preset : 8;         /* +0x0B: the brightness preset set by the factory tool */
};
extern struct user_settings_record user_settings;
extern struct factory_record_layout factory_record;
extern struct part_record_layout part_record;
extern struct device_settings_head device_settings;
extern unsigned char ddc_tool_inverted_flag, ddc_tool_read_address_high, ddc_tool_read_address_low, osd_request_bits, osd_choice_row;
extern int SYSAPI_WriteEEPROM(unsigned char area, void *record, unsigned short offset, unsigned short size);
extern void power_enter_app_state(unsigned int state);
extern unsigned char sys_get_channel_state(unsigned char channel);
extern unsigned char sys_api_get_channel_state_code(unsigned char channel);
extern void sys_set_factory_mode_flag(void);
extern void sys_clear_factory_mode_flag(void);
extern void nvram_api_store_by_selector(unsigned char what);
extern unsigned char ddc_tool_run_factory_reset(void);
extern int ddc_tool_select_input(unsigned char *request);
extern int ddc_tool_set_color_temp_gain(unsigned char *request);
extern int ddc_tool_set_pip_test_mode(unsigned char *request);
extern int ddc_tool_set_fill_or_inspection(unsigned char *request);
extern int ddc_tool_set_brightness_preset(unsigned char *request);
extern void pq_user_apply_color_settings(void);
extern void ddc_raise_event0(void);
extern void sys_user_apply_brightness(void);
extern void pq_user_apply_color_gain(void);
extern void audio_user_apply_level(void);
extern void gpio_set_port2_bit2_high(void);
extern void gpio_set_port2_bit2_low(void);
extern void sys_user_apply_config_bit31(void);
extern void gpio_user_set_port7_bit1(unsigned char override);
extern void nvram_write_settings_record(void *record, unsigned char mode);
extern void ddc_tool_build_reply(unsigned char *request, unsigned char *reply, unsigned char cmd);
extern void ddc_set_checksum_byte(unsigned char value);
extern void ddc_api_queue_reply(unsigned char port, unsigned short length, unsigned char *reply);

/* Saving: SYSAPI_WriteEEPROM(area, record, offset, size). */
#define EEPROM_AREA_SETTINGS        0x30        /* first argument of SYSAPI_WriteEEPROM: the settings area */
#define USER_SETTINGS_SIZE          0x1fc       /* the user settings record, at offset 0 of that area */
#define FACTORY_RECORD_OFFSET       0x2e0       /* docs/DATA.md: where the factory record is saved */
#define FACTORY_RECORD_SIZE         0x1c
/* nvram_api_store_by_selector: what it saves. */
#define STORE_PART_RECORD           0           /* nvram_write_part_record(part_record) */
#define STORE_DEVICE_SETTINGS       1           /* nvram_write_settings_record(device_settings) */

#define FACTORY_MODE_MARKER         0x55aa      /* user settings +0x1F6 while factory mode is on */
#define FACTORY_MODE_MARKER_CLEARED 0xbb99      /* written there when factory mode ends */
#define SETTINGS_WORD0_FACTORY_MODE 0x4000      /* user settings word +0, bit 14 */
#define FACTORY_MODE_BYTE_0x1D6     0x55        /* stored in settings byte +0x1D6 by ddc_tool_enter_factory_mode */
#define GAMING_FLAG_RGB_LED         0x40        /* user settings word +0xA8, bit 6 */

/* osd_request_bits: requests to the menu code in the main loop. */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02
#define OSD_REQUEST_EVENT_83         0x04       /* event 0x83 */

/* power_enter_app_state */
#define APP_POWER_OFF               1
#define APP_POWER_ON                2
#define APP_POWER_SAVING            3
#define MAIN_CHANNEL                0           /* channel 0: the main picture */
#define CHANNEL_STATE_CODE_OFF      0           /* sys_api_get_channel_state_code: channel off */

/* Colour temperature values (settings +0x11). */
#define COLOR_TEMP_COOL             0
#define COLOR_TEMP_NORMAL           1
#define COLOR_TEMP_WARM             2
#define COLOR_TEMP_CUSTOM           3

#define PERCENT_MAX                 100         /* brightness and contrast are limited to 100 */
#define SERIAL_COMMAND_LENGTH       0xd         /* serial characters a TOOL_CMD_SERIAL request carries */
#define TOOL_SERIAL_FIRST_BYTE      6           /* request byte of the first serial character */

/* Factory tool requests (DDC/CI command DDC_CMD_TOOL_COMMAND):
 *   byte 1, 2  length in bits 0..6, the command 0xC0
 *   byte 3     REQUEST_COMMAND ('c') or REQUEST_QUERY ('s')
 *   byte 5     what to do (enum tool_command) or what to answer (enum tool_query)
 *   byte 6, 7  values; most commands take their value from byte 7
 * The reply starts with the address, DDC_LENGTH_BYTE(6), the command and request bytes 3..6. */
#define REQUEST_COMMAND             'c'
#define REQUEST_QUERY               's'
#define DDC_ADDRESS                 0x6e        /* byte 0 of every reply (docs/MAP.md) */
#define DDC_LENGTH_BYTE(n)          ((n) + 0x80) /* reply byte 1: 0x80 + the number of bytes that follow it */
#define DDC_CMD_TOOL_COMMAND        0xc0        /* request and reply byte 2 */
#define DDC_CHECKSUM_SEED           0x50        /* first value of the reply XOR checksum */
#define REPLY_BUFFER_SIZE           40

/* Result codes in reply byte 7 (ddc_tool_build_reply). */
#define TOOL_RESULT_DONE            0xe0
#define TOOL_RESULT_UNKNOWN         0xe3        /* a value the routine does not know */
#define TOOL_RESULT_BAD_VALUE       0xe4

/* Request byte 5 of a REQUEST_COMMAND request. */
enum tool_command {
    TOOL_CMD_POWER              = 0x01,         /* byte 7: 1 on, 0 off, 2 power saving */
    TOOL_CMD_FACTORY_MODE       = 0x02,         /* byte 7: 1 on, 0 off */
    TOOL_CMD_FACTORY_RESET      = 0x03,
    TOOL_CMD_SAVE_SETTINGS      = 0x04,
    TOOL_CMD_05                 = 0x05,         /* answered TOOL_RESULT_DONE, nothing else */
    TOOL_CMD_BURN_IN            = 0x08,         /* byte 7: 1 on, 0 off */
    TOOL_CMD_SELECT_INPUT       = 0x0a,
    TOOL_CMD_INVERTED_FLAG      = 0x0b,         /* byte 7: 1 clears, 0 sets ddc_tool_inverted_flag */
    TOOL_CMD_COLOR_TEMPERATURE  = 0x0d,
    TOOL_CMD_BRIGHTNESS         = 0x0e,
    TOOL_CMD_CONTRAST           = 0x0f,
    TOOL_CMD_COLOR_GAIN         = 0x11,
    TOOL_CMD_13                 = 0x13,         /* answered with result 0, nothing else */
    TOOL_CMD_SETTINGS_BIT9      = 0x22,
    TOOL_CMD_TYPE_C_PD_CHARGE   = 0x23,
    TOOL_CMD_READ_ADDRESS       = 0x55,         /* address of the next ddc_tool_answer_read_request */
    TOOL_CMD_CLEAR_KEY_TEST     = 0x69,
    TOOL_CMD_LANGUAGE           = 0x6a,
    TOOL_CMD_SERIAL             = 0x6b,
    TOOL_CMD_AUDIO_LEVEL        = 0x6c,
    TOOL_CMD_COPY_GAINS         = 0x6d,
    TOOL_CMD_6E                 = 0x6e,         /* answered with result 0, nothing else */
    TOOL_CMD_PIP_TEST           = 0x6f,
    TOOL_CMD_RGB_LED            = 0x70,
    TOOL_CMD_FILL_OR_INSPECTION = 0x72,
    TOOL_CMD_BRIGHTNESS_PRESET  = 0x73,
    TOOL_CMD_FACTORY_BYTE_14    = 0x74,
    TOOL_CMD_80                 = 0x80,         /* answered TOOL_RESULT_DONE, nothing else */
    TOOL_CMD_ENTER_FACTORY_MODE = 0xaa,
    TOOL_CMD_CLEAR_OLED_ERRORS  = 0xc4,
    TOOL_CMD_CLEAR_ON_TIME      = 0xd0
};

/* Request byte 5 of a REQUEST_QUERY request. Where the answer is not a single byte, the answer kind passed to
   ddc_tool_build_reply (TOOL_ANSWER_* there) is given. */
enum tool_query {
    TOOL_GET_FACTORY_MODE       = 0x02,         /* TOOL_ANSWER_FACTORY_MODE */
    TOOL_GET_BURN_IN            = 0x08,         /* TOOL_ANSWER_BURN_IN */
    TOOL_GET_INPUT              = 0x0a,         /* TOOL_ANSWER_INPUT */
    TOOL_GET_BRIGHTNESS         = 0x0e,
    TOOL_GET_CONTRAST           = 0x0f,
    TOOL_GET_COLOR_GAINS        = 0x11,         /* TOOL_ANSWER_COLOR_GAINS */
    TOOL_GET_1C                 = 0x1c,         /* TOOL_ANSWER_ZERO_BYTES */
    TOOL_GET_1D                 = 0x1d,         /* TOOL_ANSWER_97 */
    TOOL_GET_1E                 = 0x1e,         /* result 0 */
    TOOL_GET_1F                 = 0x1f,         /* TOOL_ANSWER_1F */
    TOOL_GET_KEY_TEST           = 0x69,         /* TOOL_ANSWER_KEY_TEST */
    TOOL_GET_LANGUAGE           = 0x6a,         /* TOOL_ANSWER_LANGUAGE */
    TOOL_GET_SERIAL             = 0x6b,         /* TOOL_ANSWER_SERIAL */
    TOOL_GET_AUDIO_LEVEL        = 0x6c,
    TOOL_GET_KEY_CHECK_1        = 0x6e,         /* TOOL_ANSWER_KEY_CHECK_1 */
    TOOL_GET_KEY_CHECK_2        = 0x6f,         /* TOOL_ANSWER_KEY_CHECK_2 */
    TOOL_GET_BRIGHTNESS_PRESET  = 0x73,
    TOOL_GET_FACTORY_BYTE_14    = 0x74,
    TOOL_GET_FACTORY_STATUS     = 0xaa,         /* TOOL_ANSWER_FACTORY_STATUS */
    TOOL_GET_OLED_ERROR_COUNT   = 0xc1,         /* also sets the check flag */
    TOOL_GET_OLED_ERROR_REG     = 0xc2,         /* TOOL_ANSWER_OLED_ERROR_REG */
    TOOL_GET_CHECK_FLAG         = 0xc3,
    TOOL_GET_ON_TIME            = 0xd0,         /* TOOL_ANSWER_ON_TIME */
    TOOL_GET_FE                 = 0xfe          /* cmd 0xFE: ddc_tool_build_reply answers TOOL_RESULT_E2 */
};

/* Answer kinds of ddc_tool_build_reply (enum tool_answer there). */
#define TOOL_ANSWER_FACTORY_MODE    0x02
#define TOOL_ANSWER_BURN_IN         0x08
#define TOOL_ANSWER_INPUT           0x0a
#define TOOL_ANSWER_1F              0x1f
#define TOOL_ANSWER_KEY_TEST        0x69
#define TOOL_ANSWER_LANGUAGE        0x6a
#define TOOL_ANSWER_SERIAL          0x6b
#define TOOL_ANSWER_KEY_CHECK_1     0x6e
#define TOOL_ANSWER_KEY_CHECK_2     0x6f
#define TOOL_ANSWER_COLOR_GAINS     0x92
#define TOOL_ANSWER_ZERO_BYTES      0x93
#define TOOL_ANSWER_97              0x97
#define TOOL_ANSWER_FACTORY_STATUS  0xaa
#define TOOL_ANSWER_OLED_ERROR_REG  0xc2
#define TOOL_ANSWER_ON_TIME         0xd0

/* Bytes queued for each reply (ddc_api_queue_reply). */
#define REPLY_LENGTH                10
#define REPLY_LENGTH_COLOR_GAINS    0xd
#define REPLY_LENGTH_SERIAL         0x15        /* bytes 0..0x14; ddc_tool_build_reply puts the checksum at 0x15 */

/* ---- Inlined copies of the tool command routines that follow this one's callers in the firmware. ---- */

/* TOOL_CMD_POWER (copy of ddc_tool_set_power): request byte 7 = 1 powers on when the main channel is off, 0 powers
   off when it is not, 2 enters power saving unless the raw state of the main channel is 1. The user settings are
   saved in every case. */
static int ddc_tool_set_power(unsigned char *request)
{
    unsigned char value = request[7];

    if (value == 1) {
        if (sys_api_get_channel_state_code(MAIN_CHANNEL) == CHANNEL_STATE_CODE_OFF)
            power_enter_app_state(APP_POWER_ON);
    } else if (value == 0) {
        if (sys_api_get_channel_state_code(MAIN_CHANNEL) != CHANNEL_STATE_CODE_OFF)
            power_enter_app_state(APP_POWER_OFF);
    } else if (value == 2) {
        if (sys_get_channel_state(MAIN_CHANNEL) != 1)
            power_enter_app_state(APP_POWER_SAVING);
    }
    SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &user_settings, 0, USER_SETTINGS_SIZE);
    return TOOL_RESULT_DONE;
}

/* TOOL_CMD_FACTORY_MODE (copy of ddc_tool_set_factory_mode): 1 sets the factory mode flag and the marker and saves
   the user settings; 0 clears both but does not save the user settings. Both save the device settings. */
static int ddc_tool_set_factory_mode(unsigned char *request)
{
    if (request[7] == 1) {
        sys_set_factory_mode_flag();
        user_settings.factory_marker = FACTORY_MODE_MARKER;
        SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &user_settings, 0, USER_SETTINGS_SIZE);
    } else if (request[7] == 0) {
        sys_clear_factory_mode_flag();
        user_settings.factory_marker = FACTORY_MODE_MARKER_CLEARED;
    }
    nvram_api_store_by_selector(STORE_DEVICE_SETTINGS);
    return TOOL_RESULT_DONE;
}

/* TOOL_CMD_BURN_IN (copy of ddc_tool_set_burn_in). */
static int ddc_tool_set_burn_in(unsigned char *request)
{
    if (request[7] == 1)
        user_settings.burn_in_flag = 1;
    else if (request[7] == 0)
        user_settings.burn_in_flag = 0;
    SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &user_settings, 0, USER_SETTINGS_SIZE);
    return TOOL_RESULT_DONE;
}

/* TOOL_CMD_INVERTED_FLAG (copy of ddc_tool_set_inverted_flag): the flag takes the inverse of the value. */
static unsigned char ddc_tool_set_inverted_flag(unsigned char *request)
{
    if (request[7] == 1)
        ddc_tool_inverted_flag = 0;
    else if (request[7] == 0)
        ddc_tool_inverted_flag = 1;
    return TOOL_RESULT_DONE;
}

/* TOOL_CMD_COLOR_TEMPERATURE (copy of ddc_tool_set_color_temperature): the tool numbers 1..4 are Warm, Cool,
   Normal and Custom. A change is applied, raises DDC/CI event 0 and is saved. */
static int ddc_tool_set_color_temperature(unsigned char *request)
{
    unsigned char color_temperature;

    switch (request[7]) {
    case 1:
        color_temperature = COLOR_TEMP_WARM;
        break;
    case 2:
        color_temperature = COLOR_TEMP_COOL;
        break;
    case 3:
        color_temperature = COLOR_TEMP_NORMAL;
        break;
    case 4:
        color_temperature = COLOR_TEMP_CUSTOM;
        break;
    default:
        return TOOL_RESULT_UNKNOWN;
    }
    if (user_settings.color_temperature != color_temperature) {
        user_settings.color_temperature = color_temperature;
        pq_user_apply_color_settings();
        ddc_raise_event0();
        SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &user_settings, 0, USER_SETTINGS_SIZE);
    }
    return TOOL_RESULT_DONE;
}

/* TOOL_CMD_BRIGHTNESS (copy of ddc_tool_set_brightness): applied, not saved here. */
static int ddc_tool_set_brightness(unsigned char *request)
{
    struct user_settings_record *settings = &user_settings;

    if (request[7] > PERCENT_MAX)
        settings->brightness = PERCENT_MAX;
    else
        settings->brightness = request[7];
    sys_user_apply_brightness();
    osd_request_bits |= OSD_REQUEST_EVENT_83;
    return TOOL_RESULT_DONE;
}

/* TOOL_CMD_CONTRAST (copy of ddc_tool_set_contrast): applied, not saved here. */
static int ddc_tool_set_contrast(unsigned char *request)
{
    struct user_settings_record *settings = &user_settings;

    if (request[7] > PERCENT_MAX)
        settings->contrast = PERCENT_MAX;
    else
        settings->contrast = request[7];
    pq_user_apply_color_gain();
    return TOOL_RESULT_DONE;
}

/* TOOL_CMD_LANGUAGE (copy of ddc_tool_set_language): tool language number -> menu language (settings +8). The
   table is the inverse of the TOOL_ANSWER_LANGUAGE table in ddc_tool_build_reply. Tool numbers not listed keep
   the language; the settings are saved either way. */
static unsigned char ddc_tool_set_language(unsigned char *request)
{
    switch (request[7]) {
    case 0x0:
        user_settings.language = 0x1;
        break;
    case 0x1:
        user_settings.language = 0x3;
        break;
    case 0x2:
        user_settings.language = 0x2;
        break;
    case 0x3:
        user_settings.language = 0x5;
        break;
    case 0x4:
        user_settings.language = 0x4;
        break;
    case 0x5:
        user_settings.language = 0x19;
        break;
    case 0x6:
        user_settings.language = 0x16;
        break;
    case 0x7:
        user_settings.language = 0x9;
        break;
    case 0x8:
        user_settings.language = 0x18;
        break;
    case 0x9:
        user_settings.language = 0x8;
        break;
    case 0xc:
        user_settings.language = 0x0;
        break;
    case 0xd:
        user_settings.language = 0x7;
        break;
    case 0xe:
        user_settings.language = 0x6;
        break;
    case 0x10:
        user_settings.language = 0xd;
        break;
    case 0x11:
        user_settings.language = 0xa;
        break;
    case 0x12:
        user_settings.language = 0xb;
        break;
    case 0x13:
        user_settings.language = 0xc;
        break;
    case 0x14:
        user_settings.language = 0xe;
        break;
    case 0x15:
        user_settings.language = 0xf;
        break;
    case 0x16:
        user_settings.language = 0x10;
        break;
    case 0x17:
        user_settings.language = 0x11;
        break;
    case 0x18:
        user_settings.language = 0x12;
        break;
    case 0x19:
        user_settings.language = 0x13;
        break;
    case 0x1a:
        user_settings.language = 0x14;
        break;
    case 0x1b:
        user_settings.language = 0x15;
        break;
    case 0x1c:
        user_settings.language = 0x17;
        break;
    case 0x1d:
        user_settings.language = 0x1a;
        break;
    case 0x1e:
        user_settings.language = 0x1b;
        break;
    case 0x1f:
        user_settings.language = 0x1c;
        break;
    }
    SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &user_settings, 0, USER_SETTINGS_SIZE);
    nvram_api_store_by_selector(STORE_DEVICE_SETTINGS);
    return TOOL_RESULT_DONE;
}

/* TOOL_CMD_SERIAL (copy of ddc_tool_write_factory_record): request bytes 6..18 -> the 13 serial characters of the
   factory record, then the factory record is saved. */
static int ddc_tool_write_factory_record(unsigned char *request)
{
    unsigned int count = 0;
    unsigned char i = 0;

    do {
        count = count + 1;
        factory_record.serial[i] = request[i + TOOL_SERIAL_FIRST_BYTE];
        i = count & 0xff;
    } while (i < SERIAL_COMMAND_LENGTH);
    SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &factory_record, FACTORY_RECORD_OFFSET, FACTORY_RECORD_SIZE);
    return TOOL_RESULT_DONE;
}

/* TOOL_CMD_AUDIO_LEVEL (copy of ddc_tool_set_level_percent): stored as sent; audio_user_apply_level limits what it
   applies to 100. */
static int ddc_tool_set_level_percent(unsigned char *request)
{
    user_settings.audio_level = request[7];
    audio_user_apply_level();
    SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &user_settings, 0, USER_SETTINGS_SIZE);
    return TOOL_RESULT_DONE;
}

/* TOOL_CMD_COPY_GAINS (copy of ddc_tool_copy_color_temp_gains): copy the colour bytes of the row request byte 6
   names to the row byte 7 names; rows 1 = warm50, 3 = normal65, 2 = cool93, 5 = the row at +0x21. The part
   record is saved. */
static int ddc_tool_copy_color_temp_gains(unsigned char *request)
{
    unsigned char red, green, blue;

    switch (request[6]) {
    case 1:
        red = part_record.warm50.red;
        green = part_record.warm50.green;
        blue = part_record.warm50.blue;
        break;
    case 3:
        red = part_record.normal65.red;
        green = part_record.normal65.green;
        blue = part_record.normal65.blue;
        break;
    case 2:
        red = part_record.cool93.red;
        green = part_record.cool93.green;
        blue = part_record.cool93.blue;
        break;
    case 5:
        red = part_record.row_0x21.red;
        green = part_record.row_0x21.green;
        blue = part_record.row_0x21.blue;
        break;
    default:
        return TOOL_RESULT_UNKNOWN;
    }
    switch (request[7]) {
    case 1:
        part_record.warm50.red = red;
        part_record.warm50.green = green;
        part_record.warm50.blue = blue;
        break;
    case 3:
        part_record.normal65.red = red;
        part_record.normal65.green = green;
        part_record.normal65.blue = blue;
        break;
    case 2:
        part_record.cool93.red = red;
        part_record.cool93.green = green;
        part_record.cool93.blue = blue;
        break;
    case 5:
        part_record.row_0x21.red = red;
        part_record.row_0x21.green = green;
        part_record.row_0x21.blue = blue;
        break;
    default:
        return TOOL_RESULT_UNKNOWN;
    }
    nvram_api_store_by_selector(STORE_PART_RECORD);
    return TOOL_RESULT_DONE;
}

/* TOOL_CMD_6E (copy of uart_cmd_return_zero_copy21). */
static int uart_cmd_return_zero_copy21(void)
{
    return 0;
}

/* TOOL_CMD_RGB_LED (copy of ddc_tool_set_rgb_led): 0 = off, any other value = on; drives pin 2 of GPIO port 2 to
   match and saves the user settings. */
static int ddc_tool_set_rgb_led(unsigned char *request)
{
    if (request[7] == 0) {
        user_settings.gaming_flags &= ~GAMING_FLAG_RGB_LED;
        gpio_set_port2_bit2_low();
    } else {
        user_settings.gaming_flags |= GAMING_FLAG_RGB_LED;
        gpio_set_port2_bit2_high();
    }
    SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &user_settings, 0, USER_SETTINGS_SIZE);
    return TOOL_RESULT_DONE;
}

/* TOOL_CMD_FACTORY_BYTE_14 (copy of ddc_tool_set_factory_flag_14): factory record byte +0x14 = 0 or 1, saved. */
static int ddc_tool_set_factory_flag_14(unsigned char *request)
{
    if (request[7] == 1)
        factory_record.byte_0x14 = 1;
    else if (request[7] == 0)
        factory_record.byte_0x14 = 0;
    SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &factory_record, FACTORY_RECORD_OFFSET, FACTORY_RECORD_SIZE);
    return TOOL_RESULT_DONE;
}

/* TOOL_CMD_ENTER_FACTORY_MODE (copy of ddc_tool_enter_factory_mode): only value 1 does anything. It sets the
   factory mode bit, burn-in, the marker and byte +0x1D6, saves the user settings and answers TOOL_RESULT_DONE
   when the first three read back as set; else, and for any other value, TOOL_RESULT_BAD_VALUE. */
static int ddc_tool_enter_factory_mode(unsigned char *request)
{
    unsigned char value = request[7];
    int result = TOOL_RESULT_BAD_VALUE;

    if (value == 1) {
        user_settings.word_0x0.high.factory_mode = 1;
        user_settings.burn_in_flag = value;
        user_settings.factory_marker = FACTORY_MODE_MARKER;
        user_settings.byte_0x1d6 = FACTORY_MODE_BYTE_0x1D6;
        SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &user_settings, 0, USER_SETTINGS_SIZE);
        if ((user_settings.word_0x0.word & SETTINGS_WORD0_FACTORY_MODE) && user_settings.burn_in_flag == 1 && user_settings.factory_marker == FACTORY_MODE_MARKER)
            result = TOOL_RESULT_DONE;
        else
            result = TOOL_RESULT_BAD_VALUE;
    }
    return result;
}

/* TOOL_CMD_READ_ADDRESS (copy of ddc_tool_set_read_address): request bytes 6 and 7 pick the table of the next
   ddc_tool_answer_read_request. */
static unsigned char ddc_tool_set_read_address(unsigned char *request)
{
    ddc_tool_read_address_low = request[6];
    ddc_tool_read_address_high = request[7];
    return TOOL_RESULT_DONE;
}

/* TOOL_CMD_CLEAR_OLED_ERRORS (copy of ddc_tool_clear_factory_counters): the OLED error count and the register
   value saved with it are cleared, and the factory record is saved. */
static int ddc_tool_clear_factory_counters(void)
{
    factory_record.oled_error_count = 0;
    factory_record.oled_error_reg10 = 0;
    SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &factory_record, FACTORY_RECORD_OFFSET, FACTORY_RECORD_SIZE);
    return TOOL_RESULT_DONE;
}

/* TOOL_CMD_SETTINGS_BIT9 (copy of ddc_tool_set_setting_bit9): settings word +0 bit 9 = (value != 0); a change is
   applied with sys_user_apply_config_bit31 and reported to the menu code. The old bit is kept in osd_choice_row
   for the comparison. Not saved here. */
static int ddc_tool_set_setting_bit9(unsigned char *request)
{
    osd_choice_row = user_settings.word_0x0.low.bit9;
    user_settings.word_0x0.low.bit9 = request[7] != 0;
    if (osd_choice_row != user_settings.word_0x0.low.bit9) {
        sys_user_apply_config_bit31();
        osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
    }
    return TOOL_RESULT_DONE;
}

/* TOOL_CMD_TYPE_C_PD_CHARGE (copy of ddc_tool_set_setting_bit7): Type C PD Charge (settings word +0x1EC bit 7) =
   (value != 0); a change runs gpio_user_set_port7_bit1(0) and is reported to the menu code. The old bit is kept
   in osd_choice_row for the comparison. Not saved here. */
static int ddc_tool_set_setting_bit7(unsigned char *request)
{
    osd_choice_row = user_settings.boundary_detection.bits.type_c_pd_charge;
    user_settings.boundary_detection.bits.type_c_pd_charge = request[7] != 0;
    if (osd_choice_row != user_settings.boundary_detection.bits.type_c_pd_charge) {
        gpio_user_set_port7_bit1(0);
        osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
    }
    return TOOL_RESULT_DONE;
}

/* The 40-byte reply, with byte 6 (the single-byte answer of the 's' requests) as its own field. */
struct tool_reply {
    unsigned char header[6];                    /* bytes 0..5 */
    unsigned int value : 8;                     /* byte 6 */
    unsigned char rest[33];                     /* bytes 7..39 */
};
#define REPLY_BYTES ((unsigned char *)&reply)

/*
 * Carry out one factory tool request and queue the answer.
 *
 *   port     the port ddc_api_take_request gave with the request; passed on to ddc_api_queue_reply
 *   request  the request (layout above the enums); its checksum is already checked
 *
 * Called by ddc_handle_request for DDC/CI command DDC_CMD_TOOL_COMMAND (0xC0); ddc_handle_request leaves the
 * on-screen menu open afterwards.
 *
 * Phases:
 *   1. Clear the 40-byte reply and write its header: address, DDC_LENGTH_BYTE(6), command 0xC0 and request bytes
 *      3..6.
 *   2. A REQUEST_COMMAND request: run the routine of request byte 5 (enum tool_command). Most return
 *      TOOL_RESULT_DONE; a byte 5 that is not listed gives TOOL_RESULT_UNKNOWN. TOOL_CMD_13, TOOL_CMD_6E and
 *      TOOL_CMD_CLEAR_ON_TIME leave the result at 0.
 *   3. A REQUEST_QUERY request: either put a single byte in reply byte 6 with TOOL_RESULT_DONE, or choose the
 *      answer kind that ddc_tool_build_reply fills in (enum tool_query). A byte 5 that is not listed gives
 *      TOOL_RESULT_UNKNOWN. A request byte 3 that is neither 'c' nor 's' leaves the result at 0.
 *   4. ddc_tool_build_reply fills in the result or the answer and the reply checksum; the shared DDC/CI checksum
 *      byte is set back to its seed 0x50 and the reply is queued: REPLY_LENGTH bytes, more for the colour gains
 *      and the serial number.
 */
void ddc_tool_dispatch_command(unsigned char port, unsigned char *request)
{
    struct tool_reply reply;
    unsigned char i;
    char result = 0;
    unsigned short reply_length = REPLY_LENGTH;
    unsigned char *reply_bytes;

    /* Phase 1: the reply header. */
    for (i = 0; i < REPLY_BUFFER_SIZE; i++)
        REPLY_BYTES[i] = 0;
    REPLY_BYTES[0] = DDC_ADDRESS;
    REPLY_BYTES[1] = DDC_LENGTH_BYTE(6);
    REPLY_BYTES[2] = DDC_CMD_TOOL_COMMAND;
    REPLY_BYTES[3] = request[3];
    REPLY_BYTES[4] = request[4];
    REPLY_BYTES[5] = request[5];
    REPLY_BYTES[6] = request[6];
    reply_bytes = REPLY_BYTES;

    /* Phase 2: commands. */
    if (REPLY_BYTES[3] == REQUEST_COMMAND) {
        switch (REPLY_BYTES[5]) {
        case TOOL_CMD_POWER: result = ddc_tool_set_power(request); break;
        case TOOL_CMD_FACTORY_MODE: result = ddc_tool_set_factory_mode(request); break;
        case TOOL_CMD_FACTORY_RESET: result = ddc_tool_run_factory_reset(); break;
        case TOOL_CMD_SAVE_SETTINGS:
            SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &user_settings, 0, USER_SETTINGS_SIZE);
            result = TOOL_RESULT_DONE;
            break;
        case TOOL_CMD_05: result = TOOL_RESULT_DONE; break;
        case TOOL_CMD_BURN_IN: result = ddc_tool_set_burn_in(request); break;
        case TOOL_CMD_SELECT_INPUT: result = ddc_tool_select_input(request); break;
        case TOOL_CMD_INVERTED_FLAG: result = ddc_tool_set_inverted_flag(request); break;
        case TOOL_CMD_COLOR_TEMPERATURE: result = ddc_tool_set_color_temperature(request); break;
        case TOOL_CMD_BRIGHTNESS: result = ddc_tool_set_brightness(request); break;
        case TOOL_CMD_CONTRAST: result = ddc_tool_set_contrast(request); break;
        case TOOL_CMD_CLEAR_KEY_TEST:
            /* Clear the key test bits (TOOL_GET_KEY_TEST reads them) and save the factory record. */
            factory_record.key_test_bits = 0;
            SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &factory_record, FACTORY_RECORD_OFFSET, FACTORY_RECORD_SIZE);
            result = TOOL_RESULT_DONE;
            break;
        case TOOL_CMD_COLOR_GAIN: result = ddc_tool_set_color_temp_gain(request); break;
        case TOOL_CMD_13: break;
        case TOOL_CMD_LANGUAGE: result = ddc_tool_set_language(request); break;
        case TOOL_CMD_SERIAL: result = ddc_tool_write_factory_record(request); break;
        case TOOL_CMD_AUDIO_LEVEL: result = ddc_tool_set_level_percent(request); break;
        case TOOL_CMD_COPY_GAINS: result = ddc_tool_copy_color_temp_gains(request); break;
        case TOOL_CMD_6E: result = uart_cmd_return_zero_copy21(); break;
        case TOOL_CMD_RGB_LED: result = ddc_tool_set_rgb_led(request); break;
        case TOOL_CMD_PIP_TEST: result = ddc_tool_set_pip_test_mode(request); break;
        case TOOL_CMD_FILL_OR_INSPECTION: result = ddc_tool_set_fill_or_inspection(request); break;
        case TOOL_CMD_BRIGHTNESS_PRESET: result = ddc_tool_set_brightness_preset(request); break;
        case TOOL_CMD_FACTORY_BYTE_14: result = ddc_tool_set_factory_flag_14(request); break;
        case TOOL_CMD_ENTER_FACTORY_MODE: result = ddc_tool_enter_factory_mode(request); break;
        case TOOL_CMD_READ_ADDRESS: result = ddc_tool_set_read_address(request); break;
        case TOOL_CMD_CLEAR_OLED_ERRORS: result = ddc_tool_clear_factory_counters(); break;
        case TOOL_CMD_CLEAR_ON_TIME:
            /* Hours and minutes of the on-time to 0 (the brightness preset byte stays); the device settings
               are written, the result stays 0. */
            device_settings.on_time_hours = 0;
            device_settings.on_time_minutes = 0;
            nvram_write_settings_record(&device_settings, 1);
            break;
        case TOOL_CMD_SETTINGS_BIT9: result = ddc_tool_set_setting_bit9(request); break;
        case TOOL_CMD_TYPE_C_PD_CHARGE: result = ddc_tool_set_setting_bit7(request); break;
        case TOOL_CMD_80: result = TOOL_RESULT_DONE; break;
        default: result = TOOL_RESULT_UNKNOWN; break;
        }

    /* Phase 3: queries. */
    } else if (REPLY_BYTES[3] == REQUEST_QUERY) {
        switch (REPLY_BYTES[5]) {
        case TOOL_GET_FE: result = TOOL_GET_FE; break;
        case TOOL_GET_1D: result = TOOL_ANSWER_97; break;
        case TOOL_GET_KEY_CHECK_1: result = TOOL_ANSWER_KEY_CHECK_1; break;
        case TOOL_GET_1E: break;
        case TOOL_GET_BRIGHTNESS: reply.value = user_settings.brightness; result = TOOL_RESULT_DONE; break;
        case TOOL_GET_CONTRAST: reply.value = user_settings.contrast; result = TOOL_RESULT_DONE; break;
        case TOOL_GET_INPUT: result = TOOL_ANSWER_INPUT; break;
        case TOOL_GET_FACTORY_STATUS: result = TOOL_ANSWER_FACTORY_STATUS; break;
        case TOOL_GET_AUDIO_LEVEL: reply.value = user_settings.audio_level; result = TOOL_RESULT_DONE; break;
        case TOOL_GET_1F: result = TOOL_ANSWER_1F; break;
        case TOOL_GET_FACTORY_MODE: result = TOOL_ANSWER_FACTORY_MODE; break;
        case TOOL_GET_BRIGHTNESS_PRESET: reply.value = device_settings.brightness_preset; result = TOOL_RESULT_DONE; break;
        case TOOL_GET_COLOR_GAINS: result = TOOL_ANSWER_COLOR_GAINS; reply_length = REPLY_LENGTH_COLOR_GAINS; break;
        case TOOL_GET_1C: result = TOOL_ANSWER_ZERO_BYTES; break;
        case TOOL_GET_FACTORY_BYTE_14: reply.value = factory_record.byte_0x14; result = TOOL_RESULT_DONE; break;
        case TOOL_GET_ON_TIME: result = TOOL_ANSWER_ON_TIME; break;
        case TOOL_GET_OLED_ERROR_COUNT:
            /* Reading the count sets the check flag, and the factory record is saved. */
            reply.value = factory_record.oled_error_count;
            factory_record.check = 1;
            SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &factory_record, FACTORY_RECORD_OFFSET, FACTORY_RECORD_SIZE);
            result = TOOL_RESULT_DONE;
            break;
        case TOOL_GET_OLED_ERROR_REG: result = TOOL_ANSWER_OLED_ERROR_REG; break;
        case TOOL_GET_LANGUAGE: result = TOOL_ANSWER_LANGUAGE; break;
        case TOOL_GET_CHECK_FLAG: reply.value = factory_record.check; result = TOOL_RESULT_DONE; break;
        case TOOL_GET_SERIAL: result = TOOL_ANSWER_SERIAL; reply_length = REPLY_LENGTH_SERIAL; break;
        case TOOL_GET_KEY_TEST: result = TOOL_ANSWER_KEY_TEST; break;
        case TOOL_GET_KEY_CHECK_2: result = TOOL_ANSWER_KEY_CHECK_2; break;
        case TOOL_GET_BURN_IN: result = TOOL_ANSWER_BURN_IN; break;
        default: result = TOOL_RESULT_UNKNOWN; break;
        }
    }

    /* Phase 4: finish and queue the reply. */
    ddc_tool_build_reply(request, reply_bytes, result);
    ddc_set_checksum_byte(DDC_CHECKSUM_SEED);
    ddc_api_queue_reply(port, reply_length, reply_bytes);
}
