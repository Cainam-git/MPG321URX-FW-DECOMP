/* osd_reset_crosshair_position  (FUN_a009584c)
 *
 * Store the reset position of the crosshair (0x750, 0x402) and return to the G.I. list.
 * Note: The two values are stored only in state 0x42 ('Reset'), in position halfwords +0x1AC / +0x1AE.
 * Name basis: proven - handler table 0xA802422C: OK on state 0x42 = 'Reset' (texts 0x18F984)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009584c, flags -mcpu=v8 -O3 -g.
 */
#define MENU_STATE_CROSSHAIR_RESET_ITEM 0x42    /* Smart Crosshair items, Reset row (item row 3) */
#define MENU_STATE_GI_CROSSHAIR_ITEM    0x0c    /* G.I. page, item Smart Crosshair (item row 1) */
#define OSD_REQUEST_SETTINGS_CHANGED    0x02    /* bit of osd_request_bits */
#define CROSSHAIR_RESET_X               0x750   /* value stored in crosshair_x */
#define CROSSHAIR_RESET_Y               0x402   /* value stored in crosshair_y */
#define KEY_TEXT_MOVE                   0       /* key guide texts: Move, Enter */
#define KEY_TEXT_ENTER                  1

/* The Smart Crosshair position in the user settings record. */
struct user_settings_record {
    unsigned char pad[0x1ac];
    unsigned short crosshair_x;                 /* +0x1AC */
    unsigned short crosshair_y;                 /* +0x1AE */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern unsigned char osd_request_bits;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_key_guide(unsigned char sel, unsigned char mode);
extern void osd_update_key_guide(unsigned char hi, unsigned char lo);
extern void osd_highlight_item_row(unsigned char, int);

/*
 * OK key on the Reset item of the Smart Crosshair items. When the menu state is the Reset item, the crosshair
 * position is set to the fixed values 0x750 and 0x402 and the highlight of choice row 3 is cleared. In every
 * case the key guide is drawn with Move and Enter, the menu state goes back to the Smart Crosshair item of the
 * G.I. page with its row highlighted, and the settings-changed request is made.
 */
void osd_reset_crosshair_position(void)
{
    if (osd_menu_state == MENU_STATE_CROSSHAIR_RESET_ITEM) {
        user_settings.crosshair_x = CROSSHAIR_RESET_X;
        user_settings.crosshair_y = CROSSHAIR_RESET_Y;
        osd_clear_choice_highlight(3);
    }
    osd_draw_key_guide(1, 2);
    osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_ENTER);
    osd_menu_state = MENU_STATE_GI_CROSSHAIR_ITEM;
    osd_highlight_item_row(1, 1);
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
