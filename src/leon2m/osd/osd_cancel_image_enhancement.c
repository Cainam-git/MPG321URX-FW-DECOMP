/* osd_cancel_image_enhancement  (FUN_a00962ac)
 *
 * Restore the Image Enhancement level saved on entry, re-apply it and go back.
 * Note: Re-applies both channels (sys_user_apply_channel0_scaling_mode /
 *   sys_user_apply_channel1_scaling_mode).
 * Name basis: derived - handler table 0xA802422C: left on states 0x64..0x68
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00962ac @ 0xa00962ac-0xa0096338 (35 words), flags -mcpu=v8 -O3 -g.
 * Source form: the level is a 4-bit bit-field between a 12-bit and a 16-bit field of the word at +0x34
 * (big-endian, first field = top bits); the firmware reads it again for every use. The callees are declared with
 * byte or unsigned parameters as below, and the last call is a tail call.
 */
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;

/* The field of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x34];
    unsigned int other_bits_hi : 12;
    unsigned int image_enhancement : 4;         /* +0x34: bits 0-3 of the halfword = Image Enhancement level */
    unsigned int other_bits_lo : 16;
};
extern struct user_settings_record user_settings;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned int, unsigned int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern void sys_user_save_mode_slot(void);
extern void sys_user_apply_channel1_scaling_mode(void);
extern void sys_user_apply_channel0_scaling_mode(void);

#define MENU_STATE_IMAGE_ENHANCEMENT_ITEM 0x17  /* Professional page, item Image Enhancement (item row 2) */
#define MENU_STATE_IMAGE_ENHANCEMENT_LIST 100   /* + level: the Image Enhancement list (states 0x64..0x68) */
#define IMAGE_ENHANCEMENT_ITEM_ROW        2     /* item row of the Image Enhancement item */
#define CHOICE_MARK_LIST                  1     /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON                    1
#define CHOICE_ROW_PLAIN                  0     /* highlight style of a choice row while the list is left */
#define HIGHLIGHT_ITEM_ACTIVE             1     /* highlight style of an item row with the cursor in the item list */

/*
 * Left key in the Image Enhancement list: put back the level that was saved when the list was opened
 * (osd_choice_row), apply the scaling mode for channel 0 and channel 1, and save the mode slot. Then the highlight
 * leaves the list, the level's mark is drawn, the menu state returns to the Image Enhancement item and its row is
 * highlighted.
 */
void osd_cancel_image_enhancement(void)
{
    user_settings.image_enhancement = osd_choice_row;
    sys_user_apply_channel0_scaling_mode();
    sys_user_apply_channel1_scaling_mode();
    sys_user_save_mode_slot();
    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_IMAGE_ENHANCEMENT_LIST);
    osd_highlight_choice_row(user_settings.image_enhancement, CHOICE_ROW_PLAIN);
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings.image_enhancement, CHOICE_MARK_ON);
    osd_menu_state = MENU_STATE_IMAGE_ENHANCEMENT_ITEM;
    osd_highlight_item_row(IMAGE_ENHANCEMENT_ITEM_ROW, HIGHLIGHT_ITEM_ACTIVE);
}
