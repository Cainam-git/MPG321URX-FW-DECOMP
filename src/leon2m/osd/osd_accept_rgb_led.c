/* osd_accept_rgb_led  (FUN_a0098f28)
 *
 * Switch the RGB LED off or on as highlighted and go back (OK)
 * Note: OFF (state 0xB1) clears bit 6 of settings word +0xA8; the other rows set it and store bit 0 of the
 *   state in bit 5 (1 = RGB Brightness, state 0xB3).
 * Name basis: derived - handler table 0xA802422C: OK on states 0xB1/0xB2; texts 0x193248: OFF, ON, RGB
 *   Brightness
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0098f28 @ 0xa0098f28-0xa009901c (61 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table). Source form: bits 5 and 6 of word +0xA8 are 1-bit bit-fields.
 */
/* Settings word +0xA8 as the RGB LED code sees it: bit 6 = LED on, bit 5 = RGB Brightness chosen. */
struct user_settings_record {
    unsigned char pad[0xa8];
    unsigned int hi : 25, led_on : 1, led_rgb : 1, lo : 5; /* +0xA8: bit 6 = LED on, bit 5 = RGB Brightness */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_choice_row;
extern unsigned char osd_request_bits;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void gpio_user_set_port2_bit2(void);
extern void gpio_user_set_led_by_state(void);
extern void osd_highlight_item_row(unsigned char, int);

#define MENU_STATE_RGB_LED_ITEM  0x2d   /* RGB LED item of the Settings page (item row 3) */
#define MENU_STATE_RGB_LED_OFF   0xb1   /* the OFF row of the list; ON is 0xB2, RGB Brightness 0xB3 */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_CLEAR               0
#define MARK_DRAW                1
#define ITEM_ROW_ACTIVE          1      /* osd_highlight_item_row mode: cursor is in the item list */
#define CHOICE_ROW_PLAIN         0      /* osd_highlight_choice_row style: plain */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02 /* osd_request_bits bit 1: a setting was changed */

/*
 * OK on OFF or ON in the RGB LED list (states 0xB1, 0xB2): store the choice and go back to the RGB LED item.
 * No table entry for OK on state 0xB3 points here (that state opens the RGB Brightness slider).
 *
 * The cursor row (state - 0xB1, written as state + 0x4F in the byte argument) loses its highlight and the row
 * saved on entry (osd_choice_row) loses its mark. OFF clears bit 6 of settings word +0xA8. Otherwise bit 6 is
 * set and bit 5 gets the low bit of the state. The row of the stored setting is highlighted and marked, the two
 * LED pin routines apply the new setting, the menu state returns to the RGB LED item and the item row is
 * highlighted as active.
 */
void osd_accept_rgb_led(void)
{
    osd_clear_choice_highlight(osd_menu_state + 0x4f);
    osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row, MARK_CLEAR);
    if (osd_menu_state == MENU_STATE_RGB_LED_OFF) {
        user_settings.led_on = 0;
        osd_highlight_choice_row(0, CHOICE_ROW_PLAIN);
        osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings.led_on, MARK_DRAW);
    } else {
        user_settings.led_on = 1;
        user_settings.led_rgb = osd_menu_state;
        osd_highlight_choice_row(user_settings.led_rgb + 1, CHOICE_ROW_PLAIN);
        osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings.led_rgb + 1, MARK_DRAW);
    }
    gpio_user_set_port2_bit2();
    gpio_user_set_led_by_state();
    osd_menu_state = MENU_STATE_RGB_LED_ITEM;
    osd_highlight_item_row(3, ITEM_ROW_ACTIVE);
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
