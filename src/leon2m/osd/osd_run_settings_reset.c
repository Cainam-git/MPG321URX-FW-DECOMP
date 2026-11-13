/* osd_run_settings_reset  (FUN_a00b8848)
 *
 * Close the menu and reset all user settings to their defaults.
 * Note: Sets request bits 1 (settings changed) and 2 of 0xA802B08E, and bit 0 when channel 0 is not port type
 *   5 and its timing field 0x16 is not 0.
 * Name basis: proven - calls sys_user_factory_reset; only caller osd_confirm_settings_reset
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b8848 @ 0xa00b8848-0xa00b88b8 (28 words), flags -mcpu=v8 -O3 -g.
 * Source form: osd_close_menu takes no argument; input_api_get_timing_field returns unsigned short; both tests
 * are written directly on the call results.
 */
#define OSD_REQUEST_BIT0             0x01       /* bit 0 of osd_request_bits */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02
#define OSD_REQUEST_EVENT_83         0x04
#define PORT_TYPE_5                  5          /* port type for which bit 0 is not requested */
#define TIMING_FIELD_0x16            0x16       /* measured timing field of channel 0, read as non-zero or zero */

extern unsigned char osd_request_bits;

extern void osd_api_set_text_mode(unsigned int, unsigned int);
extern void osd_close_menu(void);
extern void sys_user_factory_reset(void);
extern unsigned char input_get_port_sync_mode(unsigned int);
extern unsigned short input_api_get_timing_field(unsigned int, unsigned int);

/*
 * Reset all user settings to their defaults (the confirmed Reset of the menu).
 * Sets text mode 0, closes the menu, runs sys_user_factory_reset and sets request bits 1 and 2. When channel
 * 0's port type is not 5 and timing field 0x16 of channel 0 is non-zero, request bit 0 is set as well.
 */
void osd_run_settings_reset(void)
{
    osd_api_set_text_mode(0, 0);
    osd_close_menu();
    sys_user_factory_reset();
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED | OSD_REQUEST_EVENT_83;
    if (input_get_port_sync_mode(0) != PORT_TYPE_5) {
        if (input_api_get_timing_field(0, TIMING_FIELD_0x16) != 0)
            osd_request_bits |= OSD_REQUEST_BIT0;
    }
}
