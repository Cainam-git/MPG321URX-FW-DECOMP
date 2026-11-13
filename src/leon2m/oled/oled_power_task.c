/* oled_power_task  (FUN_a0127c78)
 *
 * Run the OLED power and care state machine.
 * Name basis: proven - prints 'Go to OFFSENSING' and other state texts; called from the application layer
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0127c78 @ 0xa0127c78-0xa0129598, flags -mcpu=v8 -O3 -g -msoft-float.
 * The six small routines above it are copies of routines that also have their own files; they are defined here
 * so that the compiler builds them into oled_power_task as the firmware has them (the firmware routine writes the
 * I2C buffers itself). Their own flags: -mcpu=v8 -O3 -g, except OLEDIIC_getTempSensing (-mcpu=v8 -O3
 * -msoft-float, no -g). oled_wait_500_ticks is a static helper with no firmware routine of its own.
 * Source forms the exact build depends on:
 *  - the two blink parity tests are written 'blink_step % 2 == 1', not 'blink_step & 1' (EL sensing step 6,
 *    off sensing step 3). Same meaning for an unsigned char; with '& 1' gcc 3.4's branch prediction rates the two
 *    arms 50/50 and the block order changes. '% 2 == 1' reaches the predictor as a compare with a non-zero
 *    constant, which favours the colour arm, so the shared zero-colour block lands where the firmware has it;
 *  - power_down is a union: state 0 reads bytes +0xC and +0xD as one halfword.
 */

/* States of the machine (oled_power_state.state), named after the firmware's own texts. */
enum {
    OLED_POWER_RECOVER_OFF = 0,     /* "RecoverOFF": idle; decides whether a run must start */
    OLED_POWER_EL_SENSING  = 1,     /* "ELSENSING": the long panel care run */
    OLED_POWER_OFF_SENSING = 2,     /* "OFFSENSING": the short panel care run */
    OLED_POWER_QSM         = 3,     /* "QSM": stop a sensing run at once (set by APPActionDispatcher) */
    OLED_POWER_POWER_OFF   = 4      /* "start panel power off sequence" */
};

/* What follows a sensing run (oled_power_state.after_sensing). */
enum {
    AFTER_SENSING_DISPLAY      = 0, /* "Goto Display" */
    AFTER_SENSING_POWER_SAVING = 1, /* "Goto PowerSaving" */
    AFTER_SENSING_POWER_OFF    = 2  /* "Goto PowerOff"; also chosen when the panel is too warm */
};

/* Device settings (nvram_get_device_setting) of the two runs; the factory menu prints them as "n %d, %dh %dm". */
#define DEVICE_SETTING_EL_COUNT     0xa     /* use time since the last EL sensing run: count below an hour */
#define DEVICE_SETTING_OFFS_COUNT   0xb     /* use time since the last off sensing run: count 0..59 below an hour */
#define DEVICE_SETTING_EL_HOURS     0xc     /* hours since the last EL sensing run */
#define DEVICE_SETTING_OFFS_HOURS   0xd     /* hours since the last off sensing run, printed as "OFFS H" */
#define DEVICE_SETTING_EL_RUNS      0xe     /* finished EL sensing runs */
#define DEVICE_SETTING_OFFS_RUNS    0xf     /* finished off sensing runs */
#define DEVICE_SETTING_SENSING_TEST 0x10    /* factory menu switch "Sensing Test" */
#define DEVICE_SETTING_USAGE_RECORD 0x11    /* device setting 17 */

#define OFFS_HOURS_DUE          4           /* off sensing is due after this many hours of use */
#define OFFS_TEST_MINUTES_DUE   19          /* with "Sensing Test": due above hours * 60 + count = 19 */

#define FACTORY_MODE_MARKER     0x55aa      /* settings halfword +0x1F6 while the factory tool's factory mode is on */
#define SETTINGS_WORD_1F4_BIT30 0x40000000  /* chooses the level of port 4 pin 7 when the picture comes back */
#define SETTINGS_EEPROM_OFFSET  0x30        /* where SYSAPI_WriteEEPROM stores the settings record */
#define SETTINGS_SIZE           0x1fc

#define SLEEP_STATE_FAKE_SLEEP  2           /* app_state_record.sleep_state: "DPMS standby" / fake sleep */
#define APP_POWER_OFF           1           /* power_enter_app_state: power off */
#define APP_POWER_SAVING        3           /* power_enter_app_state: power saving ("APPSetPowersaving") */

#define PANEL_OFF               0           /* SYSAPI_PanelOnOffControl: first argument */
#define PANEL_ON                1
#define NO_WAIT                 0           /* SYSAPI_PanelOnOffControl: second argument */
#define WAIT_DONE               1

#define KEY_ALL                 0xff        /* sys_set_key_blocked: every key */
#define PANEL_TEMPERATURE_LIMIT 45          /* above this OLEDIIC_getTempSensing value the run is cut short */
#define SECOND_TICKS            1000
#define BLINK_TICKS             500
#define BLINK_STEPS             8           /* steps 1..7 blink; step 8 ends the blinking */
#define RETAINED_RUN_BITS       0x120       /* bits of the retention registers set while off sensing runs */
#define RETAINED_RUN_BITS_CLEAR 0xfedf      /* the same bits cleared (16-bit complement of 0x120) */

/* The OLED panel controller on software I2C bus 0 (address 0x60, two register address bytes). */
#define OLED_I2C_ADDRESS        0x60
#define OLED_REG_ADDRESS_BYTES  2
#define I2C_BIT_DELAY           5
#define I2C_BUS_0               0
#define OLED_REG_TEMPERATURE    8
#define OLED_REG_OFF_SENSING    0xc0
#define OLED_REG_EL_SENSING     0xc2
#define TEMPERATURE_STEP        0.0625      /* the temperature register value is multiplied by this */

/* The state record of this machine (oled_power_state, 0xA802D896). Other code sets several of these fields
   through the oled_power_set_field_<offset> routines before it calls oled_power_task. */
struct oled_power_record {
    unsigned char state;                /* +0x00 OLED_POWER_* */
    unsigned char step;                 /* +0x01 step inside the state */
    unsigned short second_ticks;        /* +0x02 time stamp of the one-second tick (states 1, 2), also of 500-tick waits */
    unsigned short ticks;               /* +0x04 time stamp of the step waits */
    unsigned short seconds;             /* +0x06 seconds counted in the current step */
    unsigned char blink_phase;          /* +0x08 level last given to the pin toggled every second */
    unsigned char sensing_requested;    /* +0x09 a run is wanted: needed before state 0 starts off sensing */
    unsigned char forced_sensing;       /* +0x0A start off sensing without checking the use time */
    unsigned char byte_0xb;             /* +0x0B */
    union {
        unsigned char done;             /* +0x0C 1: the power-down after a run has been done */
        unsigned short done_and_request;  /* +0x0C/+0x0D as one halfword: == 1 means request set, done clear */
    } power_down;                       /*       +0x0D is the power-down request, set by the power-saving and
                                                 power-off code together with after_sensing */
    unsigned char byte_0xe;             /* +0x0E */
    unsigned char after_sensing;        /* +0x0F AFTER_SENSING_* */
    unsigned char qsm_done;             /* +0x10 1 after the QSM steps; state 0 then starts no off sensing */
    unsigned char byte_0x11;            /* +0x11 set to 2 here when a run ends towards power saving or power off */
    unsigned char fake_sleep;           /* +0x12 1: the fake sleep minute counter runs */
    unsigned char sensing_active;       /* +0x13 1 during an off sensing run; the pin toggles each second */
    unsigned short run_seconds;         /* +0x14 seconds since the run started */
    unsigned char blink_count;          /* +0x16 blink step 0..7 */
};
/* The fields of the user settings record (user_settings, docs/RECORDS.md) that the runs use. The settings are saved
   at the start and at the end of each run, so the bytes below survive a power loss in the middle of a run. */
struct user_settings_record {
    unsigned char p000[0x1d5];
    unsigned char burn_in_flag;         /* +0x1D5 */
    unsigned char p1d6[0x1e2 - 0x1d6];
    unsigned char byte_0x1e2;           /* +0x1E2 cleared at the end of an off sensing run */
    unsigned char byte_0x1e3;           /* +0x1E3 cleared at the end of an EL sensing run */
    unsigned char byte_0x1e4;           /* +0x1E4 0: byte_0x1e6 is set at the start of off sensing; 1 is cleared at its end */
    unsigned char byte_0x1e5;           /* +0x1E5 the same for EL sensing and byte_0x1e7 */
    unsigned char byte_0x1e6;           /* +0x1E6 1 from the start to the end of an off sensing run */
    unsigned char byte_0x1e7;           /* +0x1E7 1 from the start to the end of an EL sensing run */
    unsigned char p1e8[0x1f4 - 0x1e8];
    union { unsigned int word; struct { unsigned short high, factory_mode_marker; } half; } word_0x1f4;  /* +0x1F4 */
};
/* Halfword +4 of the application state record: bits 13..14 hold the sleep state. */
struct app_state_record { unsigned short half_0x0, half_0x2; unsigned short bit15:1, sleep_state:2, low_bits:13; };

extern struct oled_power_record oled_power_state;
extern struct user_settings_record user_settings;
extern struct app_state_record app_state_record;
extern unsigned char oled_read_buffer[2], oled_write_buffer[2];
#define power    oled_power_state
#define settings user_settings


extern int dbg_printf();
extern unsigned short timer_ticks_since(unsigned short);
extern unsigned short timer_get_ticks16(void);
extern void timer_sleep_ticks(int ticks);
extern unsigned short nvram_get_device_setting(unsigned int);
extern void nvram_set_device_setting(unsigned int, unsigned short);
extern void nvram_api_store_by_selector(unsigned char);
extern int SYSAPI_WriteEEPROM();
extern void SYSAPI_PanelOnOffControl(unsigned int, unsigned int);
extern unsigned char sys_api_get_channel_state_code(unsigned char);
extern unsigned char sys_api_is_channel_port_state4(unsigned char);
extern void sys_api_clear_all_channels_flag25(void);
extern void sys_api_restart_channel_at_level(int, int);
extern void panel_api_reapply_nominal_rate(void);
extern void PanelPowerOn(void), panel_power_off(void), oled_controller_enable(void);
extern void gpio_set_port4_bit7_high_if_allowed(void), gpio_set_port4_bit7_low_if_allowed(void), gpio_set_port4_bit4_high_if_allowed(void), gpio_set_port4_bit4_low_if_allowed(void);
extern unsigned char oled_is_controller_enabled(void);
extern unsigned char gpio_is_port9_bit4_high(void);
extern void gpio_set_port5_bit7_high(void), sys_poll_events_stub_copy9(void), irq_empty_handler_copy53(void), irq_empty_handler_copy54(void);
extern void gpio_set_port2_bit2_high(void), gpio_set_port2_bit2_low(void);
extern void oled_set_frame_rate_control(unsigned char);
extern void irq_empty_handler_copy18(int, int, int);
extern void irq_empty_handler_copy20(int, int, int);
extern void irq_empty_handler_copy21(int, int, int);
extern void gpio_user_set_port2_bit2(void), gpio_user_set_led_by_state(void);
extern void power_enter_app_state(unsigned int);
extern void sys_set_key_blocked(int, int);
extern int oled_flag_registers_read(void);
extern void oled_flag_registers_write(unsigned short);
extern int pq_block_blank();
extern void osd_close_menu(void);
extern unsigned short timer_api_get_ticks16(void);
extern unsigned short timer_api_ticks_since(unsigned short);
extern void ipc_api_signal_alive(void);
extern unsigned short i2c_api_write_block();
extern unsigned short i2c_api_read_block();
extern void SYSAPI_GetPanelParamStruct(unsigned int, int, unsigned char);

/* Start (1) or stop (0) the off-state sensing of the panel (register 0xC0). Does nothing while the controller is
   off. */
void oled_set_off_sensing(unsigned char on)
{
    oled_write_buffer[0] = 0;
    oled_write_buffer[1] = on;
    if (!oled_is_controller_enabled()) return;
    dbg_printf("\033[1;32mOLED set OFF Sensing %d\r\n\033[m", on);
    i2c_api_write_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_OFF_SENSING, I2C_BIT_DELAY, I2C_BUS_0, oled_write_buffer, 2, 1);
}

/* Start (1) or stop (0) the EL sensing of the panel (register 0xC2). Does nothing while the controller is off. */
void oled_set_el_sensing(unsigned char on)
{
    oled_write_buffer[0] = 0;
    oled_write_buffer[1] = on;
    if (!oled_is_controller_enabled()) return;
    dbg_printf("\033[1;32mOLED set EL sensing %d\r\n\033[m", on);
    i2c_api_write_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_EL_SENSING, I2C_BIT_DELAY, I2C_BUS_0, oled_write_buffer, 2, 1);
}

/* Read the temperature register and return it times 0.0625, cut to a whole number. While the controller is off
   the value of the previous read is used. */
unsigned short OLEDIIC_getTempSensing(void)
{
    unsigned short raw, temperature;
    if (oled_is_controller_enabled())
        i2c_api_read_block(OLED_I2C_ADDRESS, OLED_REG_ADDRESS_BYTES, OLED_REG_TEMPERATURE, I2C_BIT_DELAY, I2C_BUS_0, oled_read_buffer, 2);
    raw = (oled_read_buffer[0] << 8) | oled_read_buffer[1];
    dbg_printf("1.OLEDIIC_getTempSensing %d\r\n", raw);
    temperature = raw * TEMPERATURE_STEP;
    dbg_printf("2.OLEDIIC_getTempSensing %d\r\n", temperature);
    return temperature;
}

/* Wait 500 ticks, sending the alive signal all the time. */
static void oled_wait_500_ticks(void)
{
    unsigned short start = timer_api_get_ticks16();
    while (timer_api_ticks_since(start) < 500)
        ipc_api_signal_alive();
}

/* 1 when the use time since the last off sensing run has reached the point where the next run is due. */
unsigned char oled_is_off_sensing_due(void)
{
    unsigned char due;
    if (nvram_get_device_setting(DEVICE_SETTING_SENSING_TEST) == 0) {
        if (nvram_get_device_setting(DEVICE_SETTING_OFFS_HOURS) >= OFFS_HOURS_DUE) due = 1; else due = 0;
    } else {
        if (nvram_get_device_setting(DEVICE_SETTING_OFFS_HOURS) * 60 + nvram_get_device_setting(DEVICE_SETTING_OFFS_COUNT) > OFFS_TEST_MINUTES_DUE) due = 1; else due = 0;
    }
    return due;
}

/* 1 when the factory mode marker, the burn-in flag and device setting 17 are all set; then a run is requested
   and goes back to the picture afterwards. */
unsigned char oled_request_sensing_in_factory_burn_in(void)
{
    unsigned char valid;
    if (settings.word_0x1f4.half.factory_mode_marker == FACTORY_MODE_MARKER && settings.burn_in_flag != 0 && nvram_get_device_setting(DEVICE_SETTING_USAGE_RECORD) == 1) {
        power.sensing_requested = 1;
        power.after_sensing = AFTER_SENSING_DISPLAY;
        valid = 1;
    } else
        valid = 0;
    return valid;
}

/* 2 (= OLED_POWER_OFF_SENSING) when an off sensing run should start, else 0. */
unsigned char oled_choose_recover_mode(void)
{
    unsigned char mode;
    if (power.forced_sensing == 1) mode = 2;
    else if (oled_is_off_sensing_due() == 1) mode = 2;
    else if (oled_request_sensing_in_factory_burn_in() == 1 && nvram_get_device_setting(DEVICE_SETTING_OFFS_HOURS) * 60 + nvram_get_device_setting(DEVICE_SETTING_OFFS_COUNT) >= 0) mode = 2;
    else mode = 0;
    return mode;
}

/*
 * One step of the OLED power and care state machine. Called again and again from the application layer
 * (APPSetPowerOff, power_enter_app_state and the main loop task sys_run_app_timer_task); each call does at most one step and
 * returns. No arguments, no return value.
 *
 * The panel has two care runs, both named in the firmware's texts:
 *  - off sensing ("OFFSENSING", state 2): 180 s with the panel off, then the sensing itself (at most 370 s). It
 *    is due after 4 hours of use (after 20 minutes with the factory switch "Sensing Test"), or forced by the
 *    panel refresh request. State 0 starts it.
 *  - EL sensing ("ELSENSING", state 1): 900 s and 2100 s with the panel off, the off sensing register between
 *    them, the EL sensing register at the end. No code of this program enters state 1: oled_power_set_state is
 *    called with 0 and 3 only, and no other routine writes the state byte.
 * Each run ends in one of three ways, chosen by after_sensing: back to the picture, power saving or power off.
 *
 * Phases by state:
 *  state 0 RecoverOFF   decide: start off sensing (step 0 saves the settings, blanks the four picture blocks;
 *                       step 1 switches the panel off, blocks the keys and enters state 2), or, when only a
 *                       power-down is requested, go to state 4.
 *  state 1 ELSENSING    every second: count, toggle port 4 pin 7. Steps: 0 wait 900 s, panel on; 1 check the
 *                       temperature, start off sensing; 2 wait for port 9 pin 4 or 370 s, panel off; 3 wait 2100 s,
 *                       panel on; 4 check the temperature, start EL sensing; 5 wait for port 9 pin 4 or 95 s;
 *                       6 blink seven times; 7 reset the counters and go back to the picture, power saving or
 *                       power off.
 *  state 2 OFFSENSING   every second: count, toggle port 4 pin 4. Steps: 0 wait 180 s (5 s in factory burn-in),
 *                       panel on, check the temperature, start off sensing; 1 wait for port 9 pin 4 or 370 s;
 *                       2 wait for the pin to drop or 1000 ticks, panel off; 3 blink seven times; 4 reset the
 *                       counters and go back to the picture, power saving or power off.
 *  state 3 QSM          panel on, after 1000 ticks stop off sensing, panel off, then back to state 0.
 *  state 4 power off    three steps with prints, then power saving (fake sleep when off sensing is due) or power
 *                       off.
 *
 * When the panel reads above 45 the run is cut short and ends in power off ("temp %d over 45, go to DC off").
 * The hooks irq_empty_handler_copy18/20/21/53/54 and sys_poll_events_stub_copy9 are empty routines in this
 * firmware; the arguments passed to them are kept as they are. The firmware never checks the input signal here.
 */
void oled_power_task(void)
{
    unsigned char blink_step; int result;

    switch (power.state) {
    case OLED_POWER_RECOVER_OFF:
        result = oled_choose_recover_mode();
        if (result == 2 && power.sensing_requested == 1 && power.qsm_done == 0) {
            /* An off sensing run is due and wanted. */
            if (power.step == 0) {
                dbg_printf("RecoverOFF -> OFFSENSING 00\r\n");
                dbg_printf("---->OFFSENSING  %d %d %d %d\r\n", oled_is_off_sensing_due(), power.sensing_requested, power.forced_sensing, power.qsm_done);
                /* Mark the run in the saved settings. */
                if (settings.byte_0x1e4 == 0) settings.byte_0x1e6 = 1;
                SYSAPI_WriteEEPROM(SETTINGS_EEPROM_OFFSET, &settings, 0, SETTINGS_SIZE);
                oled_flag_registers_write(oled_flag_registers_read() | RETAINED_RUN_BITS);
                pq_block_blank(0);
                pq_block_blank(1);
                pq_block_blank(2);
                pq_block_blank(3);
                power.ticks = timer_get_ticks16();
                power.step = 1;
            } else if (power.step == 1) {
                dbg_printf("RecoverOFF -> OFFSENSING 01\r\n");
                if (timer_ticks_since(power.ticks) > 10) {
                    gpio_set_port4_bit7_low_if_allowed();
                    gpio_set_port4_bit4_low_if_allowed();
                    dbg_printf("Go to OFFSENSING\r\n");
                    SYSAPI_PanelOnOffControl(PANEL_OFF, NO_WAIT);
                    /* Enter state 2 with all counters at zero. */
                    power.blink_phase = 1;
                    power.forced_sensing = 0;
                    power.step = 0;
                    power.state = result;
                    power.second_ticks = timer_get_ticks16();
                    power.ticks = timer_get_ticks16();
                    power.sensing_active = 1;
                    power.run_seconds = 0;
                    power.blink_count = 0;
                    power.seconds = 0;
                    gpio_set_port5_bit7_high();
                    gpio_user_set_port2_bit2();
                    irq_empty_handler_copy18(0, 0, 0);
                    timer_sleep_ticks(5);
                    sys_poll_events_stub_copy9();
                    /* Keys stay blocked during the run, except key 0x40. */
                    sys_set_key_blocked(KEY_ALL, 1);
                    sys_set_key_blocked(0x40, 0);
                }
            }
        } else if (power.power_down.done_and_request == 1) {
            /* No run: a power-down is requested and not done yet. */
            dbg_printf("RecoverOFF -> POWEROFF\r\n");
            power.state = OLED_POWER_POWER_OFF;
            power.step = 0;
        }
        break;

    case OLED_POWER_EL_SENSING:
        /* The one-second tick: count the seconds and toggle port 4 pin 7. */
        if (timer_ticks_since(power.second_ticks) > SECOND_TICKS) {
            power.second_ticks = timer_get_ticks16();
            power.seconds++;
            power.run_seconds++;
            if (power.sensing_active == 1) {
                if (power.blink_phase == 1) {
                    gpio_set_port4_bit7_low_if_allowed();
                    power.blink_phase = 0;
                } else {
                    gpio_set_port4_bit7_high_if_allowed();
                    power.blink_phase = 1;
                }
            }
            /* 3465 is close to the sum of the step limits of this state, in seconds. */
            irq_empty_handler_copy21(0xd89, power.run_seconds, power.state);
        }
        switch (power.step) {
        case 0:
            /* First half: 900 s with the panel off. */
            if (settings.byte_0x1e5 == 0) settings.byte_0x1e7 = 1;
            SYSAPI_WriteEEPROM(SETTINGS_EEPROM_OFFSET, &settings, 0, SETTINGS_SIZE);
            if (power.seconds > 900) {
                PanelPowerOn();
                power.step = 1;
                power.seconds = 0;
                dbg_printf("go substate 1\r\n");
            }
            break;
        case 1:
            if (power.seconds > 1) {
                power.seconds = 0;
                oled_controller_enable();
                if (OLEDIIC_getTempSensing() > PANEL_TEMPERATURE_LIMIT) {
                    /* Too warm: skip to the blinking and end in power off. */
                    power.step = 6;
                    power.after_sensing = AFTER_SENSING_POWER_OFF;
                    gpio_set_port4_bit7_low_if_allowed();
                    gpio_set_port4_bit4_low_if_allowed();
                    dbg_printf("temp %d over 45, go to DC off\r\n", OLEDIIC_getTempSensing());
                } else {
                    oled_set_frame_rate_control(0);
                    panel_api_reapply_nominal_rate();
                    oled_wait_500_ticks();
                    oled_set_off_sensing(1);
                    power.step = 2;
                    dbg_printf("go substate 2\r\n");
                }
            }
            break;
        case 2:
            /* Off sensing until port 9 pin 4 goes high, at most 370 s; then the panel goes off for the second half. */
            if (gpio_is_port9_bit4_high() || power.seconds > 370) {
                power.step = 3;
                oled_wait_500_ticks();
                panel_power_off();
                power.seconds = 0;
                gpio_set_port4_bit7_high_if_allowed();
                gpio_set_port4_bit4_low_if_allowed();
                dbg_printf("go substate 3\r\n");
            }
            break;
        case 3:
            /* Second half: 2100 s with the panel off. */
            if (power.seconds > 2100) {
                PanelPowerOn();
                power.step = 4;
                power.seconds = 0;
                dbg_printf("go substate 4\r\n");
            }
            break;
        case 4:
            if (power.seconds > 1) {
                power.seconds = 0;
                oled_controller_enable();
                if (OLEDIIC_getTempSensing() > PANEL_TEMPERATURE_LIMIT) {
                    power.step = 6;
                    gpio_set_port4_bit7_low_if_allowed();
                    gpio_set_port4_bit4_low_if_allowed();
                } else {
                    power.step = 5;
                    oled_set_el_sensing(1);
                    dbg_printf("go substate 5\r\n");
                }
            }
            break;
        case 5:
            /* EL sensing until port 9 pin 4 goes high, at most 95 s. */
            if (gpio_is_port9_bit4_high() || power.seconds > 95) {
                power.second_ticks = timer_get_ticks16();
                power.step = 6;
                power.seconds = 0;
                dbg_printf("go substate 6\r\n");
            }
            break;
        case 6:
            /* Every 500 ticks: panel off and one blink step, black on odd steps, white on even ones. */
            if (timer_ticks_since(power.second_ticks) > BLINK_TICKS) {
                panel_power_off();
                power.second_ticks = timer_get_ticks16();
                blink_step = power.blink_count + 1;
                if (blink_step < BLINK_STEPS) {
                    power.blink_count = blink_step;
                    if (blink_step % 2 == 1) irq_empty_handler_copy20(0, 0, 0);
                    else irq_empty_handler_copy20(0xff, 0xff, 0xff);
                } else {
                    power.step = 7;
                    power.run_seconds = 0;
                    power.blink_count = 0;
                    if (power.after_sensing == AFTER_SENSING_DISPLAY) gpio_user_set_led_by_state();
                    dbg_printf("go substate 7\r\n");
                }
            }
            break;
        case 7:
            if (power.after_sensing == AFTER_SENSING_DISPLAY) {
                dbg_printf("ELSENING DONE !Goto Display \r\n");
                /* Restart both use-time counts and count the finished run. */
                nvram_set_device_setting(DEVICE_SETTING_EL_HOURS, 0);
                nvram_set_device_setting(DEVICE_SETTING_EL_COUNT, 0);
                nvram_set_device_setting(DEVICE_SETTING_OFFS_HOURS, 0);
                nvram_set_device_setting(DEVICE_SETTING_OFFS_COUNT, 0);
                nvram_set_device_setting(DEVICE_SETTING_EL_RUNS, nvram_get_device_setting(DEVICE_SETTING_EL_RUNS) + 1);
                nvram_api_store_by_selector(1);
                gpio_set_port4_bit4_low_if_allowed();
                gpio_set_port4_bit7_high_if_allowed();
                SYSAPI_PanelOnOffControl(PANEL_OFF, WAIT_DONE);
                settings.byte_0x1e7 = 0;
                settings.byte_0x1e3 = 0;
                if (settings.byte_0x1e5 == 1) settings.byte_0x1e5 = 0;
                SYSAPI_WriteEEPROM(SETTINGS_EEPROM_OFFSET, &settings, 0, SETTINGS_SIZE);
                if (sys_api_get_channel_state_code(0) == 10) {
                    /* Channel 0 is at state code 10 (raw channel state 12): set up the panel mode again
                       and restart channels 0 and 1. */
                    SYSAPI_GetPanelParamStruct(0, 1, 0);
                    sys_api_restart_channel_at_level(0, 3);
                    sys_api_restart_channel_at_level(1, 3);
                } else {
                    SYSAPI_PanelOnOffControl(PANEL_ON, WAIT_DONE);
                }
                power.step = 0;
                power.state = OLED_POWER_RECOVER_OFF;
            } else if (power.after_sensing == AFTER_SENSING_POWER_SAVING || power.after_sensing == AFTER_SENSING_POWER_OFF) {
                dbg_printf("ELSENSING DONE !Goto PowerSaving or PowerOff\r\n");
                nvram_set_device_setting(DEVICE_SETTING_EL_HOURS, 0);
                nvram_set_device_setting(DEVICE_SETTING_EL_COUNT, 0);
                nvram_set_device_setting(DEVICE_SETTING_OFFS_HOURS, 0);
                nvram_set_device_setting(DEVICE_SETTING_OFFS_COUNT, 0);
                nvram_set_device_setting(DEVICE_SETTING_EL_RUNS, nvram_get_device_setting(DEVICE_SETTING_EL_RUNS) + 1);
                nvram_api_store_by_selector(1);
                power.power_down.done = 1;
                power.state = OLED_POWER_RECOVER_OFF;
                power.step = 0;
                power.ticks = timer_get_ticks16();
                power.byte_0x11 = 2;
                settings.byte_0x1e7 = 0;
                settings.byte_0x1e3 = 0;
                if (settings.byte_0x1e5 == 1) settings.byte_0x1e5 = 0;
                SYSAPI_WriteEEPROM(SETTINGS_EEPROM_OFFSET, &settings, 0, SETTINGS_SIZE);
                if (power.after_sensing == AFTER_SENSING_POWER_SAVING) {
                    if (app_state_record.sleep_state == SLEEP_STATE_FAKE_SLEEP) {
                        /* Fake sleep: the same pins as power saving, panel off, keys free again. */
                        dbg_printf("DPMS standby\r\n");
                        gpio_set_port4_bit7_low_if_allowed();
                        gpio_set_port4_bit4_high_if_allowed();
                        gpio_set_port2_bit2_low();
                        osd_close_menu();
                        SYSAPI_PanelOnOffControl(PANEL_OFF, WAIT_DONE);
                        sys_set_key_blocked(KEY_ALL, 0);
                        oled_flag_registers_write(oled_flag_registers_read() & RETAINED_RUN_BITS_CLEAR);
                    } else {
                        power_enter_app_state(APP_POWER_SAVING);
                        SYSAPI_PanelOnOffControl(PANEL_OFF, WAIT_DONE);
                    }
                }
                if (power.after_sensing == AFTER_SENSING_POWER_OFF) power_enter_app_state(APP_POWER_OFF);
            }
            break;
        }
        break;

    case OLED_POWER_OFF_SENSING:
        /* The one-second tick: count the seconds and toggle port 4 pin 4. */
        if (timer_ticks_since(power.second_ticks) > SECOND_TICKS) {
            power.second_ticks = timer_get_ticks16();
            power.seconds++;
            power.run_seconds++;
            if (power.sensing_active == 1) {
                if (power.blink_phase == 1) {
                    gpio_set_port4_bit4_low_if_allowed();
                    power.blink_phase = 0;
                } else {
                    gpio_set_port4_bit4_high_if_allowed();
                    power.blink_phase = 1;
                }
            }
            /* 550 is close to the sum of the step limits of this state, in seconds. */
            irq_empty_handler_copy21(0x226, power.run_seconds, power.state);
        }
        switch (power.step) {
        case 0: {
            /* Wait with the panel off: 180 s, or 5 s in the factory burn-in. */
            unsigned short wait_seconds;
            if (settings.word_0x1f4.half.factory_mode_marker == FACTORY_MODE_MARKER && settings.burn_in_flag != 0 && nvram_get_device_setting(DEVICE_SETTING_USAGE_RECORD) == 1) wait_seconds = 5;
            else wait_seconds = 180;
            if (power.seconds > wait_seconds) {
                SYSAPI_PanelOnOffControl(PANEL_ON, WAIT_DONE);
                if (OLEDIIC_getTempSensing() > PANEL_TEMPERATURE_LIMIT) {
                    /* Too warm: no sensing, end in power off. */
                    power.after_sensing = AFTER_SENSING_POWER_OFF;
                    power.step = 4;
                    dbg_printf("temp %d over 45, go to DC off\r\n", OLEDIIC_getTempSensing());
                } else {
                    oled_set_frame_rate_control(0);
                    panel_api_reapply_nominal_rate();
                    timer_sleep_ticks(500);
                    irq_empty_handler_copy53();
                    oled_set_off_sensing(1);
                    power.step = 1;
                    power.seconds = 0;
                }
            }
            break;
        }
        case 1:
            /* Off sensing until port 9 pin 4 goes high, at most 370 s. */
            if (gpio_is_port9_bit4_high() == 1 || power.seconds > 370) {
                power.step = 2;
                power.second_ticks = timer_get_ticks16();
            }
            break;
        case 2:
            /* Then until the pin drops again, at most 1000 ticks; then the panel goes off. */
            if (!gpio_is_port9_bit4_high() || timer_ticks_since(power.second_ticks) > SECOND_TICKS) {
                SYSAPI_PanelOnOffControl(PANEL_OFF, WAIT_DONE);
                irq_empty_handler_copy54();
                power.second_ticks = timer_get_ticks16();
                power.step = 3;
            }
            break;
        case 3:
            /* Every 500 ticks one blink step, black on odd steps, 0xff/0x10/0 on even ones. */
            if (timer_ticks_since(power.second_ticks) > BLINK_TICKS) {
                power.second_ticks = timer_get_ticks16();
                blink_step = power.blink_count + 1;
                if (blink_step < BLINK_STEPS) {
                    power.blink_count = blink_step;
                    if (blink_step % 2 == 1) irq_empty_handler_copy20(0, 0, 0);
                    else irq_empty_handler_copy20(0xff, 0x10, 0);
                } else {
                    power.step = 4;
                    power.run_seconds = 0;
                    power.blink_count = 0;
                    if (power.after_sensing == AFTER_SENSING_DISPLAY) gpio_user_set_led_by_state();
                }
            }
            break;
        case 4:
            if (timer_ticks_since(power.second_ticks) > BLINK_TICKS) {
                power.sensing_active = 0;
                if (power.after_sensing == AFTER_SENSING_DISPLAY) {
                    dbg_printf("OFFSENSING DONE !Goto Display\r\n");
                    if (!sys_api_is_channel_port_state4(0) && settings.burn_in_flag == 0) {
                        /* The port of channel 0 is not in state 4: fall into fake sleep instead; the next call
                           ends the run towards power saving. */
                        app_state_record.sleep_state = SLEEP_STATE_FAKE_SLEEP;
                        power.after_sensing = AFTER_SENSING_POWER_SAVING;
                    } else {
                        sys_api_restart_channel_at_level(0, 0);
                        sys_api_restart_channel_at_level(1, 0);
                        sys_api_clear_all_channels_flag25();
                        /* Restart the off sensing use time; count the run unless device setting 17 was set. */
                        nvram_set_device_setting(DEVICE_SETTING_OFFS_HOURS, 0);
                        nvram_set_device_setting(DEVICE_SETTING_OFFS_COUNT, 0);
                        if (nvram_get_device_setting(DEVICE_SETTING_USAGE_RECORD) == 0) nvram_set_device_setting(DEVICE_SETTING_OFFS_RUNS, nvram_get_device_setting(DEVICE_SETTING_OFFS_RUNS) + 1);
                        nvram_set_device_setting(DEVICE_SETTING_USAGE_RECORD, 0);
                        nvram_api_store_by_selector(1);
                        settings.byte_0x1e6 = 0;
                        settings.byte_0x1e2 = 0;
                        if (settings.byte_0x1e4 == 1) settings.byte_0x1e4 = 0;
                        SYSAPI_WriteEEPROM(SETTINGS_EEPROM_OFFSET, &settings, 0, SETTINGS_SIZE);
                        if (settings.word_0x1f4.word & SETTINGS_WORD_1F4_BIT30) gpio_set_port4_bit7_high_if_allowed();
                        else gpio_set_port4_bit7_low_if_allowed();
                        gpio_set_port4_bit4_low_if_allowed();
                        SYSAPI_PanelOnOffControl(PANEL_OFF, WAIT_DONE);
                        SYSAPI_GetPanelParamStruct(0, 1, 0);
                        /* In the factory burn-in the panel is switched on again without waiting. */
                        if (settings.word_0x1f4.half.factory_mode_marker == FACTORY_MODE_MARKER && settings.burn_in_flag != 0) SYSAPI_PanelOnOffControl(PANEL_ON, NO_WAIT);
                        power.step = 0;
                        power.sensing_requested = 0;
                        power.state = OLED_POWER_RECOVER_OFF;
                        sys_set_key_blocked(KEY_ALL, 0);
                        oled_flag_registers_write(oled_flag_registers_read() & RETAINED_RUN_BITS_CLEAR);
                    }
                } else if (power.after_sensing == AFTER_SENSING_POWER_SAVING) {
                    dbg_printf("OFFSENSING DONE !Goto powersaving \r\n");
                    nvram_set_device_setting(DEVICE_SETTING_OFFS_HOURS, 0);
                    nvram_set_device_setting(DEVICE_SETTING_OFFS_COUNT, 0);
                    if (nvram_get_device_setting(DEVICE_SETTING_USAGE_RECORD) == 0) nvram_set_device_setting(DEVICE_SETTING_OFFS_RUNS, nvram_get_device_setting(DEVICE_SETTING_OFFS_RUNS) + 1);
                    nvram_set_device_setting(DEVICE_SETTING_USAGE_RECORD, 0);
                    nvram_api_store_by_selector(1);
                    settings.byte_0x1e6 = 0;
                    settings.byte_0x1e2 = 0;
                    if (settings.byte_0x1e4 == 1) settings.byte_0x1e4 = 0;
                    SYSAPI_WriteEEPROM(SETTINGS_EEPROM_OFFSET, &settings, 0, SETTINGS_SIZE);
                    power.sensing_requested = 0;
                    power.ticks = timer_get_ticks16();
                    power.byte_0x11 = 2;
                    sys_api_clear_all_channels_flag25();
                    if (app_state_record.sleep_state == SLEEP_STATE_FAKE_SLEEP) {
                        dbg_printf("DPMS standby\r\n");
                        if (sys_api_get_channel_state_code(0) > 4) {
                            /* Channel 0 is past state code 4: leave fake sleep. */
                            if (settings.word_0x1f4.word & SETTINGS_WORD_1F4_BIT30) gpio_set_port4_bit7_high_if_allowed();
                            else gpio_set_port4_bit7_low_if_allowed();
                            gpio_set_port4_bit4_low_if_allowed();
                            gpio_set_port2_bit2_high();
                            app_state_record.sleep_state = 0;
                        } else {
                            if (settings.word_0x1f4.word & SETTINGS_WORD_1F4_BIT30) {
                                gpio_set_port4_bit7_low_if_allowed();
                                gpio_set_port4_bit4_high_if_allowed();
                            } else {
                                gpio_set_port4_bit7_low_if_allowed();
                                gpio_set_port4_bit4_low_if_allowed();
                            }
                            gpio_set_port2_bit2_low();
                        }
                        osd_close_menu();
                        SYSAPI_PanelOnOffControl(PANEL_OFF, WAIT_DONE);
                        power.step = 0;
                        power.state = OLED_POWER_RECOVER_OFF;
                        sys_set_key_blocked(KEY_ALL, 0);
                        oled_flag_registers_write(oled_flag_registers_read() & RETAINED_RUN_BITS_CLEAR);
                    } else {
                        power.step = 0;
                        power.state = OLED_POWER_RECOVER_OFF;
                    }
                    power_enter_app_state(APP_POWER_SAVING);
                } else if (power.after_sensing == AFTER_SENSING_POWER_OFF) {
                    dbg_printf("OFFSENSING DONE !Goto poweroff \r\n");
                    nvram_set_device_setting(DEVICE_SETTING_OFFS_HOURS, 0);
                    nvram_set_device_setting(DEVICE_SETTING_OFFS_COUNT, 0);
                    if (nvram_get_device_setting(DEVICE_SETTING_USAGE_RECORD) != 1 || settings.word_0x1f4.half.factory_mode_marker != FACTORY_MODE_MARKER)
                        nvram_set_device_setting(DEVICE_SETTING_OFFS_RUNS, nvram_get_device_setting(DEVICE_SETTING_OFFS_RUNS) + 1);
                    nvram_set_device_setting(DEVICE_SETTING_USAGE_RECORD, 0);
                    nvram_api_store_by_selector(1);
                    settings.byte_0x1e6 = 0;
                    settings.byte_0x1e2 = 0;
                    if (settings.byte_0x1e4 == 1) settings.byte_0x1e4 = 0;
                    SYSAPI_WriteEEPROM(SETTINGS_EEPROM_OFFSET, &settings, 0, SETTINGS_SIZE);
                    power.power_down.done = 1;
                    power.step = 0;
                    power.state = OLED_POWER_RECOVER_OFF;
                    power.ticks = timer_get_ticks16();
                    power_enter_app_state(APP_POWER_OFF);
                }
            }
            break;
        }
        break;

    case OLED_POWER_QSM:
        /* Panel on, stop off sensing, panel off, back to state 0. */
        switch (power.step) {
        case 0:
            if (timer_ticks_since(power.ticks) > 10) {
                dbg_printf("QSM:AC det ON\r\n");
                SYSAPI_PanelOnOffControl(PANEL_ON, WAIT_DONE);
                power.ticks = timer_get_ticks16();
                power.step = 1;
            }
            break;
        case 1:
            if (timer_ticks_since(power.ticks) > 1000) {
                dbg_printf("QSM:Force to stop sensing\r\n");
                oled_set_off_sensing(0);
                power.ticks = timer_get_ticks16();
                power.step = 2;
            }
            break;
        case 2:
            if (timer_ticks_since(power.ticks) > 10) {
                dbg_printf("QSM:Panel power off\r\n");
                SYSAPI_PanelOnOffControl(PANEL_OFF, WAIT_DONE);
                power.ticks = timer_get_ticks16();
                power.step = 3;
            }
            break;
        case 3:
            if (timer_ticks_since(power.ticks) > 15) {
                power.state = OLED_POWER_RECOVER_OFF;
                power.qsm_done = 1;
                power.step = 0;
                if (power.after_sensing == AFTER_SENSING_POWER_SAVING || power.after_sensing == AFTER_SENSING_POWER_OFF) {
                    dbg_printf("QSM power off \r\n");
                    power_enter_app_state(APP_POWER_OFF);
                }
            }
            break;
        }
        break;

    case OLED_POWER_POWER_OFF:
        /* A power-down without a run. */
        switch (power.step) {
        case 0:
            dbg_printf("start panel power off sequence (OFFSENSING data Update)\r\n");
            power.step = 1;
            break;
        case 1:
            dbg_printf("detect power off done pin, goto power saving or power off\r\n");
            power.step = 2;
            power.ticks = timer_get_ticks16();
            break;
        case 2:
            if (timer_ticks_since(power.ticks) > 10) {
                power.step = 0;
                power.ticks = timer_get_ticks16();
                power.state = OLED_POWER_RECOVER_OFF;
                power.power_down.done = 1;
                if (power.after_sensing == AFTER_SENSING_POWER_SAVING) {
                    dbg_printf("check OFFSensing time %d\r\n", nvram_get_device_setting(DEVICE_SETTING_OFFS_HOURS));
                    result = oled_is_off_sensing_due();
                    if (result == 1) {
                        /* Off sensing is due: power saving as fake sleep, so that the run can follow. */
                        power.fake_sleep = result;
                        app_state_record.sleep_state = SLEEP_STATE_FAKE_SLEEP;
                        dbg_printf("SYSAPI_SetFakeSleep\r\n");
                        power_enter_app_state(APP_POWER_SAVING);
                    } else if (app_state_record.sleep_state == SLEEP_STATE_FAKE_SLEEP) {
                        dbg_printf("_PowerSuspendStatus_DPMS\r\n");
                    } else {
                        power_enter_app_state(APP_POWER_SAVING);
                    }
                    dbg_printf("goto power saving\r\n");
                }
                if (power.after_sensing == AFTER_SENSING_POWER_OFF) {
                    dbg_printf("goto power off\r\n");
                    power_enter_app_state(APP_POWER_OFF);
                }
            }
            break;
        }
        break;
    }
}
