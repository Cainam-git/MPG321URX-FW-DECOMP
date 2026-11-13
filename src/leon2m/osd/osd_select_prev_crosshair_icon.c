/* osd_select_prev_crosshair_icon  (FUN_a009b864)
 *
 * Show the previous crosshair icon (up key)
 * Note: Steps settings byte +0x190 down through 6..0; 0 wraps to 6.
 * Name basis: derived - handler table 0xA802422C: up on state 0x43 (Icon)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009b864 @ 0xa009b864, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the settings record is a byte array; the icon byte (+0x190) is read again for each use;
 *  - osd_choice_row is copied into a block-scope local used for the compare and the mark row.
 */

#define USER_SETTINGS_CROSSHAIR_ICON    0x190   /* the Smart Crosshair icon (user_settings_crosshair_icon) */
#define CROSSHAIR_ICON_LAST             6
#define CHOICE_MARK_ICONS               2       /* list kind of osd_draw_choice_mark used for the icon list */
#define CHOICE_MARK_ON                  1
#define CHOICE_MARK_OFF                 0
#define CROSSHAIR_ICON_SELECTED         1       /* flag of osd_highlight_crosshair_icon */

extern unsigned char user_settings[];
extern unsigned char osd_choice_row;
extern void osd_clear_crosshair_icon_highlight(unsigned char);
extern void osd_highlight_crosshair_icon(unsigned char, int);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_mark_settings_changed(void);

/*
 * Up key in the Smart Crosshair icon list: show the previous icon, wrapping from 0 to 6.
 * The icon is stored in the settings byte at +0x190 at once, and the settings are marked as changed.
 *
 * The mark is drawn at the row of the icon saved on entry (osd_choice_row); it is switched off while the
 * highlight is on that icon and on otherwise.
 */
void osd_select_prev_crosshair_icon(void)
{
    osd_clear_crosshair_icon_highlight(user_settings[USER_SETTINGS_CROSSHAIR_ICON]);
    if (user_settings[USER_SETTINGS_CROSSHAIR_ICON] == 0)
        user_settings[USER_SETTINGS_CROSSHAIR_ICON] = CROSSHAIR_ICON_LAST;
    else
        user_settings[USER_SETTINGS_CROSSHAIR_ICON]--;
    osd_highlight_crosshair_icon(user_settings[USER_SETTINGS_CROSSHAIR_ICON], CROSSHAIR_ICON_SELECTED);
    {
        unsigned char saved = osd_choice_row;
        if (user_settings[USER_SETTINGS_CROSSHAIR_ICON] == saved)
            osd_draw_choice_mark(CHOICE_MARK_ICONS, saved, CHOICE_MARK_OFF);
        else
            osd_draw_choice_mark(CHOICE_MARK_ICONS, saved, CHOICE_MARK_ON);
    }
    osd_mark_settings_changed();
}
