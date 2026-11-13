/* osd_switch_change_notice_choice  (FUN_a00b0fc0)
 *
 * Move the highlight between Yes and No in the change notice.
 * Note: Toggles byte 0xA802D43A.
 * Name basis: derived - handler table 0xA802422C: left/right on state 0x116
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b0fc0 @ 0xa00b0fc0, flags -mcpu=v8 -O3 -g. Leaf routine; the call to
 * osd_highlight_dialog_button is a tail call.
 */
extern unsigned char user_settings[];
extern void osd_highlight_dialog_button(int dialog_layout, int selected);

#define SETTING_NOTICE_BUTTON    0x1aa   /* user_settings byte: button highlighted in the change notice */
#define NOTICE_BUTTON_YES        1
#define DIALOG_LAYOUT_NOTICE     0       /* osd_highlight_dialog_button layout 0: two buttons on row 7 */

/* Left or right key in the change notice (key table state 0x116): flip the highlighted button between No (0)
 * and Yes (1) and redraw the two button frames. */
void osd_switch_change_notice_choice(void)
{
    unsigned char button = 1 - user_settings[SETTING_NOTICE_BUTTON];

    user_settings[SETTING_NOTICE_BUTTON] = button;
    if (button == NOTICE_BUTTON_YES)
        osd_highlight_dialog_button(DIALOG_LAYOUT_NOTICE, 1);
    else
        osd_highlight_dialog_button(DIALOG_LAYOUT_NOTICE, 0);
}
