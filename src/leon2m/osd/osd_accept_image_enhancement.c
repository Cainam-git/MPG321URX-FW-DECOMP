/* osd_accept_image_enhancement  (FUN_a0096230)
 *
 * Leave the Image Enhancement list on OK: move highlight and mark and go back.
 * Note: Does not write the level; returns to state 0x17 and raises the settings-changed request.
 * Name basis: derived - handler table 0xA802422C: OK on states 0x64..0x68
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0096230 @ 0xa0096230 (-mcpu=v8 -O3 -g)
 * Source form: the Image Enhancement halfword (settings +0x34) is a volatile 16-bit variable of its own, masked
 * with 0xF at the use; osd_menu_state - 100 is unsigned and masked with 0xFF.
 */
extern unsigned char osd_choice_row;
extern unsigned char osd_request_bits;
extern unsigned int osd_menu_state;
extern volatile unsigned short user_settings_image_enhancement;

extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_highlight_item_row(int, int);

#define MENU_STATE_IMAGE_ENHANCEMENT_ITEM 0x17  /* Professional page, item Image Enhancement (item row 2) */
#define MENU_STATE_IMAGE_ENHANCEMENT_LIST 100   /* + level: the Image Enhancement list (states 0x64..0x68) */
#define IMAGE_ENHANCEMENT_LEVEL_MASK      0xf   /* bits 0-3 of the halfword at settings +0x34 */
#define IMAGE_ENHANCEMENT_ITEM_ROW        2     /* item row of the Image Enhancement item */
#define OSD_REQUEST_SETTINGS_CHANGED      0x02  /* bit of osd_request_bits: event 0x80 */
#define CHOICE_MARK_LIST                  1     /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON                    1
#define CHOICE_MARK_OFF                   0
#define CHOICE_ROW_PLAIN                  0     /* highlight style of a choice row while the list is left */
#define HIGHLIGHT_ITEM_ACTIVE             1     /* highlight style of an item row with the cursor in the item list */

/*
 * OK in the Image Enhancement list (menu states 100..104): accept the highlighted level and return to the item.
 *
 * The routine does not write the level itself. It takes the highlight off the row saved on entry
 * (osd_choice_row) and clears its mark, highlights the row of the present state, marks the stored level,
 * returns to the Image Enhancement item with its row highlighted, and sets the settings-changed request bit.
 */
void osd_accept_image_enhancement(void)
{
    osd_clear_choice_highlight(osd_choice_row);
    osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row, CHOICE_MARK_OFF);
    osd_highlight_choice_row((osd_menu_state - MENU_STATE_IMAGE_ENHANCEMENT_LIST) & 0xff, CHOICE_ROW_PLAIN);
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings_image_enhancement & IMAGE_ENHANCEMENT_LEVEL_MASK,
                         CHOICE_MARK_ON);
    osd_menu_state = MENU_STATE_IMAGE_ENHANCEMENT_ITEM;
    osd_highlight_item_row(IMAGE_ENHANCEMENT_ITEM_ROW, HIGHLIGHT_ITEM_ACTIVE);
    osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
}
