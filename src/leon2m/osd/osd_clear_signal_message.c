/* osd_clear_signal_message  (FUN_a00b83e4)
 *
 * Blank and switch off the signal message window.
 * Note: Skipped for input type 5; may set bit 0 of 0xA802B08E.
 * Name basis: derived - only caller osd_dismiss_signal_message; draws page 0x15 (empty) then disables the
 *   layer
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b83e4 @ 0xa00b83e4-0xa00b848c (42 words), flags -mcpu=v8 -O3 -g.
 * Source forms: the store to osd_list_id comes before the second osd_api_enable call; the event hook takes one
 * argument (0); the halfword is field +0x3e of the record app_state_record (the firmware builds the base
 * address with sethi/or).
 */
#define SIGNAL_MESSAGE_EMPTY 0x15               /* osd_draw_signal_message page: frame only */
#define PORT_TYPE_5          5                  /* port type for which the steps below are skipped */
#define TIMING_FIELD_0x16    0x16               /* measured timing field of channel 0, read as non-zero or zero */
#define OSD_REQUEST_BIT0     1                  /* bit 0 of osd_request_bits */
#define MENU_LAYER_MAIN      0
#define ALL_WINDOWS          8                  /* window number that means all eight windows */
#define LIST_ID_AFTER_CLEAR  0x24               /* value stored in osd_list_id */
#define FLAGS_0X3E_KEEP     0x7fff             /* mask that clears bit 15 */

struct app_state_record_fields {
    unsigned char pad[0x3e];
    unsigned short flags_0x3e;                  /* +0x3E: bit 15 is cleared here */
};
extern struct app_state_record_fields app_state_record;
extern unsigned char osd_request_bits;
extern unsigned char osd_list_id;
extern void osd_draw_signal_message(int);
extern unsigned char input_get_port_sync_mode(unsigned int);
extern unsigned short input_api_get_timing_field(unsigned char, unsigned int);
extern void osd_api_set_window_enable(int, int, int);
extern void osd_api_enable(int, int);
extern void sys_poll_events_stub_copy20(int);

/*
 * Draw the empty signal message page and switch the menu layer's windows off.
 *
 * Unless channel 0's port type is 5: the empty page (frame only) is drawn, the empty event hook is called, and
 * when timing field 0x16 of channel 0 is non-zero bit 0 of osd_request_bits is set.
 * In every case after that: layer 0 is switched off, all eight windows are switched off, osd_list_id is set to
 * 0x24, layer 0 is switched on again, and bit 15 of app_state_record halfword +0x3E is cleared.
 */
void osd_clear_signal_message(void)
{
  if (input_get_port_sync_mode(0) != PORT_TYPE_5) {
    osd_draw_signal_message(SIGNAL_MESSAGE_EMPTY);
    sys_poll_events_stub_copy20(0);
    if (input_api_get_timing_field(0, TIMING_FIELD_0x16) != 0)
      osd_request_bits |= OSD_REQUEST_BIT0;
  }
  osd_api_enable(MENU_LAYER_MAIN, 0);
  osd_api_set_window_enable(ALL_WINDOWS, 0, 0);
  osd_list_id = LIST_ID_AFTER_CLEAR;
  osd_api_enable(MENU_LAYER_MAIN, 1);
  app_state_record.flags_0x3e &= FLAGS_0X3E_KEEP;
}
