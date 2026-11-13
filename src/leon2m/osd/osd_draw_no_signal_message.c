/* osd_draw_no_signal_message  (FUN_a00b8774)
 *
 * Show the 'No Signal' message on a black screen.
 * Note: Sets bit 12 of halfword 0xA802CFF4 + 0x18.
 * Name basis: proven - page 0x1b ('No Signal' text 0x193008); caller osd_show_no_signal_message
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b8774 @ 0xa00b8774-0xa00b87d4 (24 words), flags -mcpu=v8 -O3 -g.
 * Source form: the halfword at +0x18 is a field of the record app_state_record (the firmware builds the base
 * address once); the return value of pq_block_set_blank_color is unused.
 */
#define SIGNAL_MESSAGE_NO_SIGNAL_ONLY 0x1b      /* osd_draw_signal_message page: 'No Signal' */
#define APP_STATE_BIT12               0x1000    /* bit 12 of the halfword at +0x18 */

struct app_state_record_fields {
    unsigned char pad[0x18];
    unsigned short flags_0x18;                  /* +0x18: bit 12 is set here */
};
extern struct app_state_record_fields app_state_record;
extern unsigned short _DAT_a802b092;
extern unsigned short _DAT_a802b094;
extern void pq_block_set_blank_color(int, int, int, int);
extern void osd_draw_signal_message(int);
extern void SYSAPI_PanelOnOffControl(unsigned int, unsigned int);

/*
 * Show the 'No Signal' message alone. Sets the halfwords at 0xA802B092 / 0xA802B094 to 0x72C and 0, sets the
 * blanking colour values of picture block 0 to 0, draws the page, calls SYSAPI_PanelOnOffControl(1, 0) and
 * sets bit 12 of app_state_record halfword +0x18.
 */
void osd_draw_no_signal_message(void)
{
  _DAT_a802b092 = 0x72c;
  _DAT_a802b094 = 0;
  pq_block_set_blank_color(0, 0, 0, 0);
  osd_draw_signal_message(SIGNAL_MESSAGE_NO_SIGNAL_ONLY);
  SYSAPI_PanelOnOffControl(1, 0);
  app_state_record.flags_0x18 |= APP_STATE_BIT12;
}
