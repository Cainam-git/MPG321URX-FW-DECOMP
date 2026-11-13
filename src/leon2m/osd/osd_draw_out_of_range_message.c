/* osd_draw_out_of_range_message  (FUN_a00b87d4)
 *
 * Show the 'Out Of Range!' message on a black screen.
 * Name basis: proven - page 0x18 ('Out Of Range!' text 0x192d8c); callers osd_show_out_of_range,
 *   osd_run_periodic_task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b87d4 @ 0xa00b87d4 (-mcpu=v8 -O2 -g)
 * Source form: the callees have no prototype and the six parameters (all 32-bit) are declared; the last five
 * are passed on to osd_draw_signal_message.
 */
#define SIGNAL_MESSAGE_OUT_OF_RANGE 0x18        /* osd_draw_signal_message page: 'Out Of Range!' */

extern unsigned short _DAT_a802b092;
extern unsigned short _DAT_a802b094;
extern int osd_draw_signal_message();
extern int SYSAPI_PanelOnOffControl();

/*
 * Show the 'Out Of Range!' message. Calls SYSAPI_PanelOnOffControl(1, 0), sets the halfwords at 0xA802B092 /
 * 0xA802B094 to 0x72C and 0, and draws the page. The first parameter is not used; parameters 2 to 6 are
 * handed to osd_draw_signal_message unchanged.
 */
void osd_draw_out_of_range_message(unsigned int unused,unsigned int arg2,unsigned int arg3,unsigned int arg4,
                 unsigned int arg5,unsigned int arg6)

{
  SYSAPI_PanelOnOffControl(1,0);
  _DAT_a802b092 = 0x72c;
  _DAT_a802b094 = 0;
  osd_draw_signal_message(SIGNAL_MESSAGE_OUT_OF_RANGE,arg2,arg3,arg4,arg5,arg6);
  return;
}
