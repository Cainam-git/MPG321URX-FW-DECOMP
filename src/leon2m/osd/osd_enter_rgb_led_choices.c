/* osd_enter_rgb_led_choices  (FUN_a0098e6c)
 *
 * Open the RGB LED list (OFF, ON, RGB Brightness) on the current setting.
 * Note: States 0xB1..0xB3; setting = bits 5 and 6 of settings word +0xA8.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x2D = 'RGB LED'; texts 0x193248: OFF, ON,
 *   RGB Brightness
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0098e6c @ 0xa0098e6c-0xa0098f28 (47 words), flags -mcpu=v8 -O3 -g.
 * Source form: bit 6 is tested through the word view of the union ('w & 0x40', clear case first) and read through
 * the bit-field view, so the stored bit is computed (shift and mask) rather than known as 0.
 */
/* Settings word +0xA8 as the RGB LED code sees it: bit 6 = LED on, bit 5 = RGB Brightness chosen. */
struct user_settings_record {
    unsigned char pad0[0xa8];
    union {
        struct {
            unsigned int hi25 : 25;
            unsigned int led_on : 1;            /* bit 6: the RGB LED is on */
            unsigned int led_rgb : 1;           /* bit 5: RGB Brightness is the chosen ON mode */
            unsigned int lo5 : 5;
        } f;
        unsigned int w;
    } u;                                        /* +0xA8 */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_choice_row;
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_choice_mark(int, unsigned char, int);

#define PAGE_SETTINGS_ITEMS      0x2a   /* first item state of the Settings page; item row = state - 0x2a */
#define MENU_STATE_RGB_LED_LIST  0xb1   /* + row: OFF 0xB1, ON 0xB2, RGB Brightness 0xB3 */
#define SETTINGS_RGB_LED_ON      0x40   /* bit 6 of settings word +0xA8 */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_CLEAR               0
#define ITEM_ROW_LIST_OPEN       2      /* osd_highlight_item_row mode: parent of an open choice list */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */

/*
 * OK or right on the RGB LED item: open its list (OFF, ON, RGB Brightness) on the setting now stored.
 *
 * LED off (bit 6 clear) gives row 0, state 0xB1. LED on gives row 1 (state 0xB2) or, with bit 5 set, row 2
 * (state 0xB3). The row is saved in osd_choice_row, the item row is highlighted in the "list open" style, the
 * row is highlighted and its mark cleared.
 */
void osd_enter_rgb_led_choices(void)
{
    osd_highlight_item_row(osd_menu_state - PAGE_SETTINGS_ITEMS, ITEM_ROW_LIST_OPEN);
    if (!(user_settings.u.w & SETTINGS_RGB_LED_ON)) {
        osd_menu_state = MENU_STATE_RGB_LED_LIST;
        osd_choice_row = user_settings.u.f.led_on;
    } else {
        osd_menu_state = user_settings.u.f.led_rgb + (MENU_STATE_RGB_LED_LIST + 1);
        osd_choice_row = user_settings.u.f.led_rgb + 1;
    }
    osd_highlight_choice_row(osd_menu_state - MENU_STATE_RGB_LED_LIST, CHOICE_ROW_EDGED);
    osd_draw_choice_mark(CHOICE_MARK_LIST, osd_menu_state - MENU_STATE_RGB_LED_LIST, MARK_CLEAR);
}
