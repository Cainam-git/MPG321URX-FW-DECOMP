/* osd_accept_pro_mode  (FUN_a0095e54)
 *
 * Leave the Pro Mode list on OK: move the marks, set the Pro (not Game) flag and go back.
 * Note: States 0x5C..0x63 = Eco .. Display P3; sets bit 11 of settings word +0xA8; the Pro mode byte +0x181 is
 *   only read; returns to 0x15.
 * Name basis: derived - handler table 0xA802422C: OK on states 0x5C..0x63; texts 0x1951DC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0095e54 @ 0xa0095e54-0xa0095fb0 (87 words), flags -mcpu=v8 -O3 -g.
 * Source form: the row of the earlier choice is kept in an unsigned char; the condition is written as the Pro
 * mode range test, then the Low Blue Light test, then the byte +0x178 test.
 */

/* The fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0xa8];
    unsigned int gaming_flags;                  /* +0xA8: bit 11 = Pro (1) or Game (0) mode */
    unsigned char pada_c[0x11c - 0xac];
    unsigned int professional_flags;            /* +0x11C: bit 4 = Low Blue Light */
    unsigned char pad120[0x178 - 0x120];
    unsigned char byte_0x178;                   /* +0x178 */
    unsigned char pad179[0x181 - 0x179];
    unsigned char pro_mode;                     /* +0x181: the Professional mode */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_choice_row;
extern unsigned char osd_request_bits;
extern unsigned char osd_step_pro_mode_index(unsigned char, unsigned char);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_low_blue_light_switch(void);
extern void osd_draw_mode_status_header(void);

#define MENU_STATE_PRO_MODE_ITEM     0x15       /* Professional page, item Pro Mode */
#define MENU_STATE_PRO_MODE_LIST     0x5c       /* + list index: the Pro Mode list */
#define PRO_MODE_LIST_ROWS           7          /* rows of the Pro Mode list */
#define PRO_MODE_RANGE_FIRST         4          /* pro_mode 4..6 is the range tested before byte +0x178 is cleared */
#define LOW_BLUE_LIGHT_FLAG          0x10       /* bit 4 of professional_flags */
#define GAMING_FLAG_PRO_MODE         0x800      /* bit 11 of gaming_flags: Pro mode instead of Game mode */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* bit of osd_request_bits: event 0x80 */
#define CHOICE_MARK_LIST             1          /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON               1
#define CHOICE_MARK_OFF              0
#define CHOICE_ROW_PLAIN             0          /* highlight style of a choice row while the list is left */
#define STEP_UP                      0          /* direction argument of osd_step_pro_mode_index (1 = down) */
#define PRO_MODE_ITEM_ROW            0          /* item row of the Pro Mode item */
#define HIGHLIGHT_ITEM_ACTIVE        1          /* highlight style of an item row with the cursor in the item list */

/*
 * OK in the Pro Mode list (menu states 0x5C..0x63): accept the highlighted Pro mode and return to the Pro Mode
 * item (menu state 0x15).
 *
 * Byte +0x178 of the settings is cleared when it is 1 and either the Pro mode is 4..6 or Low Blue Light is on.
 * The highlight and mark of the earlier choice row (derived from osd_choice_row through osd_step_pro_mode_index)
 * are removed, the row of the present state (menu state minus 0x5C, modulo 7) is highlighted and marked, and the
 * Pro Mode item is highlighted again. The routine sets the Pro flag in gaming_flags, redraws the Low Blue Light switch and the
 * mode status header, and sets the settings-changed request bit.
 */
void osd_accept_pro_mode(void)
{
    unsigned char old_row;

    if (((unsigned char)(user_settings.pro_mode - PRO_MODE_RANGE_FIRST) <= 2
         || (user_settings.professional_flags & LOW_BLUE_LIGHT_FLAG))
        && user_settings.byte_0x178 == 1)
        user_settings.byte_0x178 = 0;
    old_row = osd_step_pro_mode_index(osd_choice_row, STEP_UP) % PRO_MODE_LIST_ROWS;
    osd_clear_choice_highlight(old_row);
    osd_draw_choice_mark(CHOICE_MARK_LIST, old_row, CHOICE_MARK_OFF);
    osd_highlight_choice_row((osd_menu_state - MENU_STATE_PRO_MODE_LIST) % PRO_MODE_LIST_ROWS, CHOICE_ROW_PLAIN);
    osd_draw_choice_mark(CHOICE_MARK_LIST, (osd_menu_state - MENU_STATE_PRO_MODE_LIST) % PRO_MODE_LIST_ROWS,
                         CHOICE_MARK_ON);
    osd_menu_state = MENU_STATE_PRO_MODE_ITEM;
    osd_highlight_item_row(PRO_MODE_ITEM_ROW, HIGHLIGHT_ITEM_ACTIVE);
    user_settings.gaming_flags |= GAMING_FLAG_PRO_MODE;
    osd_draw_low_blue_light_switch();
    osd_draw_mode_status_header();
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
