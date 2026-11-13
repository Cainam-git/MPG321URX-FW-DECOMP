/* App_CoolInitialize  (FUN_a0087020)
 *
 * Initialise the application state, show the logo and prepare the main loop (start-up step 3)
 * Note: Called once by startup_main.
 * Name basis: proven - prints 'App_CoolInitialize type = %d' (original name from the text)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0087020 @ 0xa0087020..0xa0087430 (1,040 bytes) "App_CoolInitialize", flags -mcpu=v8 -O3 -g
 * (-msoft-float gives the same code).
 * Source forms the exact build depends on:
 *  - the order of the stores to app_state_record. The 34th memory access (the store to the halfword +0x2A)
 *    is where the scheduler's pending list is cut, so the sleep_word bits 11 and 6, the +0x3E bits and byte
 *    +0x3F, the +0x18 bit and the halfwords +0x2C..+0x32 are written after it. The order is one of many that
 *    compile to the same code; the stores, their values and their final order are the firmware's;
 *  - one logo call after the type-1 block (block reordering duplicates it);
 *  - SYSAPI_WriteEEPROM declared int-returning (delay-slot filling).
 */

/* Power-on types returned by SYSAPI_GetPowerOnType (it maps a status byte onto them). */
#define POWER_ON_TYPE_DEFAULT       0       /* status byte not in the list, stored power status 1 */
#define POWER_ON_TYPE_1             1       /* status byte 2 */
#define POWER_ON_TYPE_2             2       /* status byte 3 */
#define POWER_ON_TYPE_3             3       /* status byte 4 */
#define POWER_ON_TYPE_POWER_OFF     4       /* status byte not in the list, stored power status 0 */
#define POWER_ON_TYPE_5             5       /* status byte 19 */
#define POWER_ON_TYPE_GROUP_MASK    0xf0
#define POWER_ON_TYPE_GROUP_20      0x20    /* 0x21..0x26: status bytes 13..18 */
#define POWER_ON_TYPE_GROUP_30      0x30    /* 0x30..0x37: status bytes 12 and 5..11 */

/* Types for App_Initialize (its START_* values). */
#define START_NORMAL                0
#define START_POWER_ON              1
#define START_WAKE_UP               2
#define START_TYPE_3                3
#define START_POWER_OFF             4

#define FACTORY_MODE_MARKER         0x55aa  /* user settings +0x1F6 while factory mode is on */
#define FACTORY_MODE_MARKER_CLEARED 0xbb99  /* written there when factory mode ends */
#define SOURCE_MENU_INDEX_5         5       /* Input Source stored for POWER_ON_TYPE_2 */
#define EEPROM_AREA_SETTINGS        0x30    /* first argument of SYSAPI_WriteEEPROM: the settings area */

/* Device settings cleared when factory or burn-in mode ends (ids of nvram_set_device_setting). */
#define DEVICE_SETTING_ON_TIME_MINUTES  6   /* device settings byte +8 */
#define DEVICE_SETTING_ON_TIME_HOURS    7   /* device settings +9..+0xA */
#define DEVICE_SETTING_8                8   /* device settings byte +0xC */
#define DEVICE_SETTING_9                9   /* device settings +0xD */
#define DEVICE_SETTING_EL_COUNT         0xa
#define DEVICE_SETTING_OFFS_COUNT       0xb
#define DEVICE_SETTING_EL_HOURS         0xc
#define DEVICE_SETTING_OFFS_HOURS       0xd
#define DEVICE_SETTING_EL_RUNS          0xe
#define DEVICE_SETTING_OFFS_RUNS        0xf
#define DEVICE_SETTING_SENSING_TEST     0x10

/* The application state record (app_state_record). Fields without a known use are named by offset and bit. */
struct app_state_record {
    unsigned short half0_bit15:1, half0_bit14:1, half0_bit13:1, half0_bit12:1,
                   half0_bit11:1, half0_bit10:1, half0_bits9_8:2, half0_low:8;          /* +0x00 */
    unsigned short half_0x2;                                                            /* +0x02 */
    unsigned short sleep_bit15:1, sleep_state:2, sleep_bit12:1,
                   usb_hub_power_on:1,      /* bit 11 = SLEEP_WORD_USB_HUB_POWER_ON */
                   sleep_bits10_9:2, sleep_bits8_7:2, sleep_bit6:1, sleep_low:6;        /* +0x04 sleep_word */
    unsigned short pressed_key_bit:8, half6_bits7_4:4, half6_bits3_0:4;                 /* +0x06 */
    unsigned char byte_0x8, alarm_clock;    /* +0x09: copy of the Alarm Clock setting */  /* +0x08 */
    unsigned short halfa_bits15_7:9,        /* +0x0A high byte = notice_origin, then bit 7 */
                   cec_source_hold:1,       /* bit 6 = APP_STATE_CEC_SOURCE_HOLD */
                   halfa_low:6;                                                         /* +0x0A */
    unsigned short half_0xc;                                                            /* +0x0C */
    unsigned short halfe_bit15:1, halfe_low:15;                                         /* +0x0E */
    unsigned short half_0x10, half_0x12;                                                /* +0x10 */
    unsigned short half14_bit15:1, half14_bit14:1, half14_low:14;                       /* +0x14 */
    unsigned short half_0x16;                                                           /* +0x16 */
    unsigned short half18_bit15:1, half18_low:15;                                       /* +0x18 */
    unsigned short power_on_ticks;                                                      /* +0x1A */
    unsigned char byte_0x1c, byte_0x1d;                                                 /* +0x1C */
    unsigned short half_0x1e, half_0x20, half_0x22, half_0x24, half_0x26, half_0x28,
                   half_0x2a, half_0x2c, half_0x2e, half_0x30, half_0x32;               /* +0x1E */
    unsigned short half_0x34, half_0x36, half_0x38, half_0x3a, half_0x3c;               /* +0x34 */
    unsigned short half3e_bit15:1, half3e_bit14:1, half3e_bit13:1, half3e_bits12_8:5,
                   dialog_button_index:8;                                               /* +0x3E */
};
struct user_settings_record {
    unsigned int word0_high:17, word0_bit14:1, word0_low:14;                            /* +0x000 */
    unsigned char p004[0x1a];
    unsigned char input_source;                                                         /* +0x01E */
    unsigned char p01f[0x178];
    unsigned char alarm_table_0x197[4];     /* indexed by alarm_clock */                /* +0x197 */
    unsigned char alarm_table_0x19b[5];     /* indexed by alarm_clock */                /* +0x19B */
    unsigned char alarm_clock, alarm_byte_0x1a1, alarm_byte_0x1a2;                      /* +0x1A0 */
    unsigned char p1a3[0x32];
    unsigned char burn_in_flag;             /* burn-in mode on (1) or off (0) */        /* +0x1D5 */
    unsigned char p1d6[0xc];
    unsigned char byte_0x1e2, byte_0x1e3, byte_0x1e4, byte_0x1e5, byte_0x1e6, byte_0x1e7; /* +0x1E2 */
    unsigned char p1e8[0xe];
    unsigned short factory_marker;          /* FACTORY_MODE_MARKER while factory mode is on */ /* +0x1F6 */
    unsigned char p1f8[4];
};
extern struct app_state_record app_state_record;
extern struct user_settings_record user_settings;
struct device_settings_record {
    unsigned int power_status:1,            /* bit 31: stored by SYSAPI_SetPowerStatus */
                 f0:1, f1:1, b28:1, f2:1, f3:1, b25:2, rest0:24;
};
extern struct device_settings_record device_settings;
extern int dbg_printf();
extern int SYSAPI_GetPowerOnType(void);
extern void nvram_load_user_settings(void);
extern void sys_read_startup_key(void);
extern void uart_cmd_init_ports(void);
extern void oled_power_set_field_0f(int);
extern void oled_power_reset_state(void);
extern void oled_frc_reset(void);
extern void sys_user_apply_startup_settings(void);
extern void panel_blurfree_apply_user_mode(int);
extern void panel_api_set_blurfree_mode(int);
extern void osd_show_logo_on_power_on(void);
extern void sys_user_apply_mode_byte(void);
extern void sys_user_factory_reset(void);
extern void nvram_set_device_setting(int, int);
extern void nvram_api_store_by_selector(unsigned char);
extern int SYSAPI_WriteEEPROM(int, void *, int, int);
extern int power_api_is_woken_by_power_key(void);
extern void App_Initialize(int);
extern void sys_set_mode_byte_c9f9(unsigned char);

/*
 * Start-up step 3 of the main program: set up the application state, show the logo and start the
 * application by the power-on type. Called once by startup_main before its endless main loop.
 *
 * Phases:
 *   1. Read the power-on type and load the user settings and the factory record from the EEPROM.
 *   2. Set every field of app_state_record to its start value; copy the alarm values of the chosen Alarm Clock
 *      entry.
 *   3. Read the front keys (default type only), print the type, open the 8051 serial channels, reset the OLED
 *      power and refresh-rate state, apply the start-up settings; except for POWER_ON_TYPE_POWER_OFF also the
 *      rate mode and blur reduction off.
 *   4. Logo: for types 0 and 1, and for type 2 when the stored power status is 0. Type 1 first clears
 *      settings word 0 bit 14, ends factory or burn-in mode when one of them is on (defaults back, use and
 *      sensing counters cleared) and writes the settings to the EEPROM.
 *      osd_show_logo_on_power_on itself shows the logo only when its settings bits allow it.
 *   5. Store the mode byte from the settings and call App_Initialize with the START_* value for the type:
 *        1 -> START_POWER_ON;  2 -> Input Source 5, settings saved, START_POWER_ON when the stored power status
 *        is 0, else START_WAKE_UP;  0x30..0x3F and 5 -> START_WAKE_UP;  3 -> START_POWER_OFF when the power key
 *        woke the monitor, else START_TYPE_3 and half0_bit15 set;  0x20..0x2F -> START_TYPE_3;
 *        4 -> START_POWER_OFF;  any other -> START_NORMAL.
 *   6. Store whether factory mode is on (sys_set_mode_byte_c9f9).
 *
 * No loop and no wait in its own code.
 */
void App_CoolInitialize(void)
{
    unsigned char type, alarm;

    /* 1. */
    type = SYSAPI_GetPowerOnType();
    nvram_load_user_settings();
    /* 2. Start values of the application state. */
    app_state_record.half0_bit12 = 0;
    app_state_record.half0_low = 0;
    app_state_record.pressed_key_bit = 0;
    alarm = user_settings.alarm_clock;
    user_settings.alarm_byte_0x1a1 = user_settings.alarm_table_0x197[alarm];
    user_settings.alarm_byte_0x1a2 = user_settings.alarm_table_0x19b[alarm];
    app_state_record.alarm_clock = alarm;
    app_state_record.half0_bit13 = 1;
    app_state_record.half0_bit11 = 1;
    app_state_record.half0_bit10 = 1;
    app_state_record.half0_bits9_8 = 0;
    app_state_record.half0_bit14 = 0;
    app_state_record.half0_bit11 = 1;
    app_state_record.half0_bit15 = 0;
    app_state_record.half_0x24 = 0x2dd;
    app_state_record.half6_bits7_4 = 0;
    app_state_record.cec_source_hold = 0;
    app_state_record.halfe_bit15 = 0;
    app_state_record.half14_bit15 = 0;
    app_state_record.half14_bit14 = 0;
    app_state_record.sleep_state = 0;
    app_state_record.sleep_bit12 = 0;
    app_state_record.sleep_bits10_9 = 0;
    app_state_record.sleep_bit15 = 0;
    app_state_record.half_0x20 = 0x36f;
    app_state_record.half_0x22 = 0x7e;
    app_state_record.half_0x26 = 0x2dd;
    app_state_record.half_0x28 = 0x2dd;
    app_state_record.byte_0x8 = 0;
    app_state_record.byte_0x1c = 0;
    app_state_record.half_0xc = 0;
    app_state_record.half_0x10 = 0;
    app_state_record.half_0x12 = 0;
    app_state_record.power_on_ticks = 0;
    app_state_record.half_0x1e = 0x3ff;
    app_state_record.half_0x2a = 0x2dd;
    /* (stores after the scheduler cut, see the matching notes) */
    app_state_record.usb_hub_power_on = 0;
    app_state_record.sleep_bit6 = 0;
    app_state_record.half3e_bit14 = 0;
    app_state_record.half3e_bit15 = 0;
    app_state_record.half18_bit15 = 0;
    app_state_record.half3e_bit13 = 0;
    app_state_record.dialog_button_index = 0;
    app_state_record.half_0x2c = 0x3ff;
    app_state_record.half_0x2e = 0x3ff;
    app_state_record.half_0x30 = 0x3ff;
    app_state_record.half_0x32 = 0x3ff;
    /* 3. */
    if (type == POWER_ON_TYPE_DEFAULT)
        sys_read_startup_key();
    dbg_printf("\nApp_CoolInitialize type = %d \r\n", type);
    uart_cmd_init_ports();
    oled_power_set_field_0f(0);
    oled_power_reset_state();
    oled_frc_reset();
    sys_user_apply_startup_settings();
    if (type != POWER_ON_TYPE_POWER_OFF) {
        panel_blurfree_apply_user_mode(0);
        panel_api_set_blurfree_mode(0);
    }
    /* 4. Logo. */
    if (type <= POWER_ON_TYPE_1) {
        if (type == POWER_ON_TYPE_1) {
            user_settings.word0_bit14 = 0;
            if (user_settings.factory_marker == FACTORY_MODE_MARKER || user_settings.burn_in_flag != 0) {
                /* Leave factory and burn-in mode: defaults back, use and sensing counters cleared. */
                user_settings.factory_marker = FACTORY_MODE_MARKER_CLEARED;
                user_settings.burn_in_flag = 0;
                sys_user_factory_reset();
                nvram_set_device_setting(DEVICE_SETTING_8, 0);
                nvram_set_device_setting(DEVICE_SETTING_9, 0);
                nvram_set_device_setting(DEVICE_SETTING_ON_TIME_MINUTES, 0);
                nvram_set_device_setting(DEVICE_SETTING_ON_TIME_HOURS, 0);
                user_settings.byte_0x1e2 = 0;
                user_settings.byte_0x1e6 = 0;
                user_settings.byte_0x1e3 = 0;
                user_settings.byte_0x1e7 = 0;
                nvram_set_device_setting(DEVICE_SETTING_OFFS_COUNT, 0);
                nvram_set_device_setting(DEVICE_SETTING_EL_COUNT, 0);
                nvram_set_device_setting(DEVICE_SETTING_OFFS_HOURS, 0);
                nvram_set_device_setting(DEVICE_SETTING_EL_HOURS, 0);
                nvram_set_device_setting(DEVICE_SETTING_SENSING_TEST, 0);
                nvram_set_device_setting(DEVICE_SETTING_EL_RUNS, 0);
                nvram_set_device_setting(DEVICE_SETTING_OFFS_RUNS, 0);
                nvram_api_store_by_selector(1);
            }
            SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &user_settings, 0, sizeof user_settings);
        }
        osd_show_logo_on_power_on();
    } else if (type == POWER_ON_TYPE_2 && device_settings.power_status == 0)
            osd_show_logo_on_power_on();
    /* 5. Start the application. */
    sys_user_apply_mode_byte();
    if (type == POWER_ON_TYPE_1)
        App_Initialize(START_POWER_ON);
    else if (type == POWER_ON_TYPE_2) {
        user_settings.input_source = SOURCE_MENU_INDEX_5;
        SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &user_settings, 0, sizeof user_settings);
        if (device_settings.power_status == 0)
            App_Initialize(START_POWER_ON);
        else
            App_Initialize(START_WAKE_UP);
    } else if ((type & POWER_ON_TYPE_GROUP_MASK) == POWER_ON_TYPE_GROUP_30)
        App_Initialize(START_WAKE_UP);
    else if (type == POWER_ON_TYPE_5)
        App_Initialize(START_WAKE_UP);
    else if (type == POWER_ON_TYPE_3) {
        if ((unsigned char)power_api_is_woken_by_power_key() == 1)
            App_Initialize(START_POWER_OFF);
        else {
            App_Initialize(START_TYPE_3);
            app_state_record.half0_bit15 = 1;
        }
    } else if ((type & POWER_ON_TYPE_GROUP_MASK) == POWER_ON_TYPE_GROUP_20)
        App_Initialize(START_TYPE_3);
    else if (type == POWER_ON_TYPE_POWER_OFF)
        App_Initialize(START_POWER_OFF);
    else
        App_Initialize(START_NORMAL);
    /* 6. */
    if (user_settings.factory_marker == FACTORY_MODE_MARKER)
        sys_set_mode_byte_c9f9(1);
    else
        sys_set_mode_byte_c9f9(0);
}
