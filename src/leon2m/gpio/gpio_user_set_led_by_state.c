/* gpio_user_set_led_by_state  (FUN_a00d99a8)
 *
 * Call one of two empty routines, chosen by the OLED power state, its step and settings bit 5.
 * Note: Both callees (sys_poll_events_stub_copy9 and _copy10) are empty, so no pin changes.
 * Name basis: descriptive - sys_poll_events_stub_copy9 when the OLED power state or step is not 0 or bit 5 of
 *   settings word +0xA8 is set, else sys_poll_events_stub_copy10
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d99a8 @ 0xa00d99a8, flags -mcpu=v8 -O2 -g.
 * Source form: three separate if blocks, each with its own call and return, tested in this order; the last call
 * is a tail call.
 */

#define GAMING_FLAG_LED_STATE  0x20     /* bit 5 of settings word +0xA8: the RGB brightness item of the Settings page */

extern unsigned int user_settings_gaming_flags;     /* user settings word +0xA8 */
extern void sys_poll_events_stub_copy9(void);
extern void sys_poll_events_stub_copy10(void);
extern unsigned char oled_power_get_state(void);
extern unsigned char oled_power_get_step(void);

/*
 * Call sys_poll_events_stub_copy9 when the OLED power state is not 0, when its step is not 0 or when bit 5 of
 * settings word +0xA8 is set; call sys_poll_events_stub_copy10 otherwise. Both callees are empty routines, so
 * the routine changes nothing.
 * Called from APPActionDispatcher and oled_power_task, mostly right after gpio_user_set_port2_bit2.
 */
void gpio_user_set_led_by_state(void)
{
    if (oled_power_get_state() != 0) {
        sys_poll_events_stub_copy9();
        return;
    }
    if (oled_power_get_step() != 0) {
        sys_poll_events_stub_copy9();
        return;
    }
    if ((user_settings_gaming_flags & GAMING_FLAG_LED_STATE) != 0) {
        sys_poll_events_stub_copy9();
        return;
    }
    sys_poll_events_stub_copy10();
}
