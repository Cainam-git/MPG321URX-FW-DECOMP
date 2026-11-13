/* power_escape_fake_sleep  (FUN_a0080978)
 *
 * Leave the suspend and fake-sleep states and restore the power and LED outputs.
 * Name basis: proven - texts 'reset ucPowerSuspendStatus', 'escape fake sleep'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0080978 @ 0xa0080978, flags -mcpu=v8 -O3 -g.
 * Source form: the 2-bit sleep state is a bit-field (bits 13..14 of the halfword at app_state_record + 4); a mask
 * expression allocates the registers differently.
 */
/* The application state record (see docs/DATA.md); only the fields this routine uses are named. */
struct app_state {
    unsigned short flags_0x0, halfword_0x2;
    unsigned short bit_15 : 1, sleep_state : 2, rest : 13;      /* halfword +4: bits 13..14 = sleep state */
};
extern struct app_state app_state_record;
/* The user settings record; only the fields this routine uses are named. */
struct settings {
    unsigned char bytes_before_0xac[0xac];
    unsigned char rgb_brightness;               /* +0xAC: first byte of the RGB Brightness word */
    unsigned char bytes_before_0x1f4[0x147];
    unsigned int word_0x1f4;
};
extern struct settings user_settings;
extern int dbg_printf();
extern int oled_flag_registers_read(void);
extern void oled_flag_registers_write(unsigned short);
extern unsigned char oled_power_get_state(void), oled_power_get_step(void), oled_power_get_field_11(void);
extern void oled_power_reset_state(void);
extern void sys_set_mode_byte_c9f8(unsigned char);
extern void gpio_set_port4_bit4_low_if_allowed(void), gpio_set_port4_bit7_high_if_allowed(void), gpio_set_port4_bit7_low_if_allowed(void);
extern void gpio_user_set_port2_bit2(void);
extern void UserSetAuroraLEDBarBrightness(unsigned char);
extern void gpio_set_port5_bit7_high(void);
extern void oled_power_set_state(unsigned char), oled_power_set_step(unsigned char), oled_power_set_field_09(unsigned char);
extern void oled_power_set_field_12(unsigned char), oled_power_set_field_0d(unsigned char), oled_power_set_field_0c(unsigned char);
extern void sys_set_key_blocked(int, int);
extern void oled_set_off_sensing(int);
extern void SYSAPI_PanelOnOffControl(int, int);

#define SLEEP_STATE_FAKE_SLEEP  2           /* the firmware's text calls the field ucPowerSuspendStatus */
#define WORD_0X1F4_BIT30        0x40000000  /* user_settings word +0x1F4, bit 30: picks the pin set and the mode byte below */
#define KEY_ALL                 0xff        /* sys_set_key_blocked: every key */

/*
 * Leave the fake sleep: put the pins and the LED light bar back as the settings say and clear the sleep state. No parameters, no return value.
 *
 * It acts only when the sleep state is "fake sleep" (SLEEP_STATE_FAKE_SLEEP) and the OLED power state machine is
 * idle (state 0, step 0); otherwise it does nothing.
 *
 * Then, in order:
 *   1. Reset the OLED power state record, set the sleep state to 0, print "reset ucPowerSuspendStatus".
 *   2. Restore the pins: set the mode byte to 1, drive port 4 pin 4 low and pin 7 high when word +0x1F4 bit 30
 *      is set (pin 7 low when it is clear; each pin routine acts only where the mode byte or the OLED power state
 *      allows it), then set the mode byte to bit 30 of that word; set port 2 pin 2 from the settings, send the
 *      stored RGB brightness to the LED light bar, drive port 5 pin 7 high.
 *   3. Only if field +0x11 of the OLED power record is 1: print "escape fake sleep", clear OLED power fields
 *      (state, step, +9 sensing requested, +0x12 fake sleep, +0xD power-down request, +0xC power-down done),
 *      unblock all keys, write back the retention value read on entry with bits 5 and 8 cleared, stop the off
 *      sensing, and ask for the panel to be switched off and wait until it is (SYSAPI_PanelOnOffControl(0, 1)).
 *
 * Called by sys_app_generate_events when a port state changes during fake sleep, and from the power state 5
 * branch of the power state handler (power_enter_app_state).
 */
void power_escape_fake_sleep(void)
{
    unsigned short retention_value = oled_flag_registers_read();

    if (app_state_record.sleep_state == SLEEP_STATE_FAKE_SLEEP && !oled_power_get_state() && !oled_power_get_step()) {
        oled_power_reset_state();
        app_state_record.sleep_state = 0;
        dbg_printf("reset ucPowerSuspendStatus\r\n");
        sys_set_mode_byte_c9f8(1);
        if (user_settings.word_0x1f4 & WORD_0X1F4_BIT30) {
            gpio_set_port4_bit4_low_if_allowed();
            gpio_set_port4_bit7_high_if_allowed();
        } else {
            gpio_set_port4_bit4_low_if_allowed();
            gpio_set_port4_bit7_low_if_allowed();
        }
        sys_set_mode_byte_c9f8((user_settings.word_0x1f4 >> 30) & 1);
        gpio_user_set_port2_bit2();
        UserSetAuroraLEDBarBrightness(user_settings.rgb_brightness);
        gpio_set_port5_bit7_high();
        if (oled_power_get_field_11() == 1) {
            oled_power_set_state(0);
            oled_power_set_step(0);
            oled_power_set_field_09(0);
            dbg_printf("escape fake sleep\r\n");
            oled_power_set_field_12(0);
            oled_power_set_field_0d(0);
            oled_power_set_field_0c(0);
            sys_set_key_blocked(KEY_ALL, 0);
            oled_flag_registers_write(retention_value & 0xfedf);     /* clears bits 5 and 8 */
            oled_set_off_sensing(0);
            SYSAPI_PanelOnOffControl(0, 1);
        }
    }
}
