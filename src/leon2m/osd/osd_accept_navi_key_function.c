/* osd_accept_navi_key_function  (FUN_a00984f0)
 *
 * Keep the highlighted function for the edited Navi Key direction and go back (OK)
 * Note: States 0x86..0x91 = OFF .. KVM; returns to the direction's item (0x26 + row).
 * Name basis: derived - handler table 0xA802422C: OK on states 0x86..0x91; texts 0x1935BC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00984f0 @ 0xa00984f0-0xa0098618 (74 words), flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is a struct whose array navi_key_function (+0x18A) is followed by the byte at
 * +0x1A3; both are indexed as below. Same record as osd_cancel_navi_key_function.
 */
/* The fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x18a];
    unsigned char navi_key_function[0x1a3 - 0x18a];     /* +0x18A: up, down, left, right, ... */
    unsigned char edited_key;                           /* +0x1A3: the Navi key direction being edited */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_request_bits;
extern unsigned char osd_choice_row;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);

#define PAGE_NAVI_KEY_ITEMS          0x26       /* first item state of the Navi Key page; item row = state - 0x26 */
#define MENU_STATE_NAVI_FUNCTION_LIST 0x86      /* + function: the function list of a Navi key (states 0x86..0x91) */
#define CHOICES_PER_PAGE             7          /* rows of one page of the function list */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* bit of osd_request_bits: event 0x80 */
#define CHOICE_MARK_LIST             1          /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON               1
#define CHOICE_MARK_OFF              0
#define CHOICE_ROW_PLAIN             0          /* highlight style of a choice row while the list is left */
#define HIGHLIGHT_ITEM_ACTIVE        1          /* highlight style of an item row with the cursor in the item list */

/*
 * OK in the function list of a Navi key (menu states 0x86..0x91): keep the highlighted function and return to
 * the item of that direction.
 *
 * The routine does not write the function itself. The highlight and mark of the row saved on entry
 * (osd_choice_row modulo 7) are removed, the row of the present state (state minus 0x86, modulo 7) is
 * highlighted, and the row of the function stored for the direction in byte +0x1A3 is marked. The menu state
 * returns to the item of the direction (0x26 plus the direction) with its item row highlighted, and the
 * settings-changed request bit is set.
 */
void osd_accept_navi_key_function(void)
{
    osd_clear_choice_highlight(osd_choice_row % CHOICES_PER_PAGE);
    osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row % CHOICES_PER_PAGE, CHOICE_MARK_OFF);
    osd_highlight_choice_row((osd_menu_state - MENU_STATE_NAVI_FUNCTION_LIST) % CHOICES_PER_PAGE, CHOICE_ROW_PLAIN);
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings.navi_key_function[user_settings.edited_key] % CHOICES_PER_PAGE, CHOICE_MARK_ON);
    osd_menu_state = user_settings.edited_key + PAGE_NAVI_KEY_ITEMS;
    osd_highlight_item_row(user_settings.edited_key, HIGHLIGHT_ITEM_ACTIVE);
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
