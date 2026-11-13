/* panel_cycle_burnin_colour  (FUN_a0082b00)
 *
 * Show the next of nine full-screen test colours of the burn-in cycle.
 * Note: Colour table ROM 0xFECF0. Unless OLED power state field +0x13 is set, each step also swaps which of
 *   pins 4 and 7 of GPIO port 4 is high.
 * Name basis: proven - called by the application timer task while the factory 'Burn In' byte is set
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0082b00 @ 0xa0082b00, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the colour table is copied with memcpy from a string constant (27 bytes, the table in ROM at 0xFECF0);
 *  - the copy of the flag halfword is an unsigned int, and the step to the next colour is unsigned (+ 1u).
 */

#define BURNIN_COLOURS   9
#define PIN_PAIR_TOGGLE  0x100      /* bit 8 of the flag halfword: which pin pair was driven last */

/* The first three halfwords of the application state record. */
struct app_state_record {
    unsigned short word_0x0;
    unsigned short word_0x2;
    unsigned short sleep_word;      /* +4: state flags (the fake-sleep state among them) */
};
extern struct app_state_record app_state_record;
extern unsigned char user_settings_pip_pbp_mode;
extern unsigned char panel_burnin_colour_index;
extern void *memcpy(void *dst, const void *src, int n);
extern void sys_api_set_channel_source_enable(unsigned char channel, unsigned char enable);
extern void reg_set_channel_ctrl_bit(unsigned int bit, unsigned int on);
extern unsigned char oled_power_get_field_13(void);
extern void gpio_set_port4_bit4_high_if_allowed(void);
extern void gpio_set_port4_bit7_low_if_allowed(void);
extern void gpio_set_port4_bit7_high_if_allowed(void);
extern void gpio_set_port4_bit4_low_if_allowed(void);
extern void pq_api_set_fill_color();

/*
 * One step of the factory burn-in test: fill the screen with the next of nine plain colours.
 *
 * The colours in order: white, black, black, red, green, blue, then the half-level mixes red + green,
 * red + blue and green + blue (0x80 each). Called by the application timer task (sys_run_app_timer_task) while
 * the factory menu's "Burn In" setting is on, each time its timer runs out.
 *
 * With PIP or PBP on, the source of the second picture (channel 1) is switched off first, so that the colour
 * fills the whole screen. Unless field +0x13 of the OLED power state is set, each step also swaps which of pins 4
 * and 7 of GPIO port 4 is high, so the two pins alternate with the colours.
 */
void panel_cycle_burnin_colour(void)
{
    unsigned char rgb[BURNIN_COLOURS][3];
    unsigned int flags;

    memcpy(rgb, "\377\377\377", 0x1b);          /* the nine colours from ROM, 3 bytes each */
    if (user_settings_pip_pbp_mode != 0)
        sys_api_set_channel_source_enable(1, 0);
    reg_set_channel_ctrl_bit(0, 0);             /* bit 0 of register 0xCF011FC0 off */
    if (!oled_power_get_field_13()) {
        flags = app_state_record.sleep_word;
        if (!(flags & PIN_PAIR_TOGGLE)) {
            app_state_record.sleep_word = flags | PIN_PAIR_TOGGLE;
            gpio_set_port4_bit4_high_if_allowed();
            gpio_set_port4_bit7_low_if_allowed();
        } else {
            app_state_record.sleep_word = flags & ~PIN_PAIR_TOGGLE;
            gpio_set_port4_bit7_high_if_allowed();
            gpio_set_port4_bit4_low_if_allowed();
        }
    }
    pq_api_set_fill_color(0, rgb[panel_burnin_colour_index][0], rgb[panel_burnin_colour_index][1],
                          rgb[panel_burnin_colour_index][2], 0);
    panel_burnin_colour_index = (panel_burnin_colour_index + 1u) % BURNIN_COLOURS;
}
