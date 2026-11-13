/* osd_enter_alarm_clock_choices  (FUN_a0093694)
 *
 * Open the Alarm Clock choices (Location, Off, four timers) on the current setting.
 * Note: States 0x56 Location, 0x57 off, 0x58..0x5B timers; current choice = settings byte +0x1A0.
 * Name basis: derived - OK/right on Gaming item 0x12 = 'Alarm Clock' (texts 0x188DA0)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0093694, flags -mcpu=v8 -O3 -g.
 * Source form: the settings are reached through a volatile byte pointer, so that the timer byte is read from
 * memory three times, as in the firmware; the callees are declared without prototypes and the arguments are
 * masked to a byte.
 */
#define SETTINGS_ADDRESS          0xA802D290    /* the user settings record */
#define SETTINGS_ALARM_CLOCK      0x1a0         /* offset of the Alarm Clock timer choice */
#define MENU_STATE_GAME_ITEMS_BASE 0x0e         /* menu state of the first Gaming item (Game Mode) */
#define MENU_STATE_ALARM_CHOICES  0x56          /* + choice row: row 0 Location, row 1 OFF, rows 2..5 the four timers */

extern unsigned char user_settings_alarm_clock;      /* settings +0x1A0; the code below reaches it through the pointer */
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark();
extern void osd_highlight_item_row();
extern int osd_highlight_choice_row();

/*
 * OK or right key on the Alarm Clock item of the Gaming page: open its choice list on the present choice
 * (settings byte +0x1A0: 0 = OFF, 1..4 = timer). The mark at the row of that choice (choice + 1) is cleared,
 * the choice is saved in osd_choice_row so that the left key can restore it, the item row is highlighted with
 * style 2, and the menu state becomes the state of the choice's row.
 */
void osd_enter_alarm_clock_choices(void)
{
    volatile unsigned char *settings = (volatile unsigned char *)SETTINGS_ADDRESS;
    unsigned char choice;
    unsigned char saved;

    choice = settings[SETTINGS_ALARM_CLOCK];
    osd_draw_choice_mark(1, (choice + 1) & 0xff, 0);
    saved = settings[SETTINGS_ALARM_CLOCK];
    osd_choice_row = saved;
    osd_highlight_item_row((osd_menu_state - MENU_STATE_GAME_ITEMS_BASE) & 0xff, 2);
    saved = settings[SETTINGS_ALARM_CLOCK];
    osd_menu_state = saved + MENU_STATE_ALARM_CHOICES + 1;
    osd_highlight_choice_row((saved + 1) & 0xff, 1);
}
