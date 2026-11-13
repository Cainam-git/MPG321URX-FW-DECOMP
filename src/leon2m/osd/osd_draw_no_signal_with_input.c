/* osd_draw_no_signal_with_input  (FUN_a00b867c)
 *
 * Show the input name with 'No Signal' and keep the panel on.
 * Note: Closes an open menu first; blanks the picture to black.
 * Name basis: proven - page 0x19 of osd_draw_signal_message; caller osd_show_no_signal_with_input
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b867c @ 0xa00b867c (-mcpu=v8 -O3 -g)
 * Source form: the message and the final panel call both test bit 10 of the application state halfword, as in
 * the firmware (the first test sits inside the message condition); app_state_record is read as three halfwords
 * (+4 is the status halfword 0xA802CFF8).
 */
#define SIGNAL_MESSAGE_NO_SIGNAL 0x19           /* osd_draw_signal_message page: input name and 'No Signal' */
#define CHANNEL_STATE_CODE_10    10             /* sys_api_get_channel_state_code value that keeps the menu open */
#define SETTINGS_WORD0_FACTORY_MODE 0x4000      /* bit 14 of settings word +0 */
#define SETTINGS_SIGNATURE_55AA 0x55aa          /* value of settings halfword +0x1F6 that suppresses the message */
#define APP_STATE_BIT10         0x400           /* bit 10 of the status halfword (+4) */

struct user_settings_record {
    unsigned int  word_0x0;                     /* +0x0: flag word (bit 14 = factory mode) */
    unsigned char pad[0x1d5 - 4];
    unsigned char burn_in_flag;                 /* +0x1D5: burn-in mode on (1) or off (0) */
    unsigned char pad2[0x1f6 - 0x1d6];
    unsigned short half_0x1f6;                  /* +0x1F6 */
};
struct app_state_halves { unsigned short half_0x0; unsigned short half_0x2; unsigned short status; };
extern struct user_settings_record user_settings;
extern struct app_state_halves app_state_record;
extern unsigned short _DAT_a802b092;
extern unsigned short _DAT_a802b094;
extern unsigned char osd_api_is_enabled(int);
extern unsigned char sys_api_get_channel_state_code(int);
extern void osd_close_menu(void);
extern void pq_block_set_blank_color(int, int, int, int);
extern void osd_draw_signal_message(int);
extern void SYSAPI_PanelOnOffControl(unsigned int, unsigned int);

/*
 * Show the input name with 'No Signal'.
 *
 * 1. If menu layer 0 or 1 is switched on and channel 0's state code is not 10, the menu is closed.
 * 2. Two halfwords at 0xA802B092 / 0xA802B094 are set to 0x72C and 0 and the blanking colour values of picture
 *    block 0 are set to 0 (pq_block_set_blank_color(0, 0, 0, 0)).
 * 3. The 'No Signal' page is drawn unless burn-in mode is on, settings halfword +0x1F6 is 0x55AA or settings
 *    word +0 has bit 14 (factory mode) set; it is also not drawn while bit 10 of the application status
 *    halfword is set.
 * 4. Unless bit 10 of the application status halfword is set, the panel is switched with
 *    SYSAPI_PanelOnOffControl(1, 0).
 */
void osd_draw_no_signal_with_input(void)
{
    if ((osd_api_is_enabled(0) || osd_api_is_enabled(1)) && sys_api_get_channel_state_code(0) != CHANNEL_STATE_CODE_10)
        osd_close_menu();
    _DAT_a802b092 = 0x72c;
    _DAT_a802b094 = 0;
    pq_block_set_blank_color(0, 0, 0, 0);
    if (user_settings.burn_in_flag == 0 && user_settings.half_0x1f6 != SETTINGS_SIGNATURE_55AA && !(user_settings.word_0x0 & SETTINGS_WORD0_FACTORY_MODE)) {
        if (app_state_record.status & APP_STATE_BIT10)
            return;
        osd_draw_signal_message(SIGNAL_MESSAGE_NO_SIGNAL);
    }
    if (app_state_record.status & APP_STATE_BIT10)
        return;
    SYSAPI_PanelOnOffControl(1, 0);
}
