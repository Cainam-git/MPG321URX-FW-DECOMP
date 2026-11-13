/* osd_show_out_of_range  (FUN_a009ea08)
 *
 * Show the 'Out Of Range!' message for an unsupported input timing.
 * Note: Menu state 0x10C; osd_draw_out_of_range_message switches the panel on and draws page 0x18.
 * Name basis: proven - application event table 0xA80241B0 entries 0x16/0x1B; osd_draw_signal_message page 0x18
 *   text 0x192D8C 'Out Of Range!'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009ea08, flags -mcpu=v8 -O2 -g. No direct callers (reached through the application event table).
 * Source form: a void wrapper with a constant store before a tail call; the nop after the call is the one the
 * compiler places behind such a call sequence.
 */
extern unsigned int osd_menu_state;
extern void osd_draw_out_of_range_message(void);

#define MENU_STATE_OUT_OF_RANGE 0x10c           /* 'Out Of Range!' */

/*
 * Application events 0x16 and 0x1B (event table at 0xA80241B0): show the 'Out Of Range!' message for an
 * input timing the monitor cannot display. The menu state becomes 0x10C; osd_draw_out_of_range_message draws
 * the message.
 */
void osd_show_out_of_range(void)
{
    osd_menu_state = MENU_STATE_OUT_OF_RANGE;
    osd_draw_out_of_range_message();
}
