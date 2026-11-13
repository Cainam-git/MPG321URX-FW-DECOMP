/* osd_enter_display_hdr_choices  (FUN_a0096c80)
 *
 * Open the DisplayHDR list on the current setting.
 * Note: States 0x77..0x79; current choice = bits 18..19 of settings word +0xAC.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x1D = 'DisplayHDR'; texts 0x190CEC: True
 *   Black 400, Peak 1000 nits, EOTF Boost
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0096c80 @ 0xa0096c80 (-mcpu=v8 -O3 -g)
 * Source form: the DisplayHDR mode is a 2-bit bit-field (bits 18-19 of the word at +0xAC, between a 12-bit and
 * an 18-bit field); the firmware reads it again for every use.
 */
struct user_settings_record {
    unsigned char pad0[0xac];
    unsigned int other_bits_hi : 12, display_hdr_mode : 2, other_bits_lo : 18;    /* +0xAC: bits 18-19 = DisplayHDR mode */
};
extern struct user_settings_record user_settings;
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);

#define PAGE_IMAGE_ITEMS  0x18       /* first item state of the Image page: Brightness (item row = state - 0x18) */
#define MENU_STATE_DISPLAY_HDR_LIST  0x77       /* + mode: the DisplayHDR list (states 0x77..0x79) */
#define CHOICE_MARK_LIST             1          /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_OFF              0
#define HIGHLIGHT_ITEM_LIST_OPEN     2          /* item row highlight while its choice list is open */
#define CHOICE_ROW_EDGED             1          /* highlight style of a choice row in the open list */

/*
 * OK or right on the DisplayHDR item: open its list.
 *
 * The present DisplayHDR mode is saved in osd_choice_row so that the left key can put it back. The item row is
 * highlighted in the "list open" style, the menu state moves to the list state of the mode (0x77 + mode) and that
 * mode's row is highlighted.
 */
void osd_enter_display_hdr_choices(void)
{
    osd_choice_row = user_settings.display_hdr_mode;
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings.display_hdr_mode, CHOICE_MARK_OFF);
    osd_highlight_item_row(osd_menu_state - PAGE_IMAGE_ITEMS, HIGHLIGHT_ITEM_LIST_OPEN);
    osd_menu_state = user_settings.display_hdr_mode + MENU_STATE_DISPLAY_HDR_LIST;
    osd_highlight_choice_row(user_settings.display_hdr_mode, CHOICE_ROW_EDGED);
}
