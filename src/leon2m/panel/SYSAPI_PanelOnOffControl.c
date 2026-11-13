/* SYSAPI_PanelOnOffControl  (FUN_a014512c)
 *
 * Switch the panel on or off through the power sequencer, optionally waiting until it is done.
 * Name basis: proven - prints 'SYSAPI_PanelOnOffControl = %02x' (original name)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014512c @ 0xa014512c (-mcpu=v8 -O3 -g).
 * Source form: the on arm and the off arm each have their own wait loop (a do / while (1) with a break on the
 * done test); the two arms are not merged. The parameters are tested through "& 0xff" and the done tests keep
 * the unsigned int result with "& 0xff", as the firmware extends the results at the test.
 */
extern int dbg_printf();
extern int panel_request_power();
extern int panel_power_sequencer_task();
extern int oled_frc_task();
extern int ipc_signal_alive();
extern int panel_is_power_on_done();
extern int panel_is_power_off();

#define PANEL_ON  1     /* on: switch the panel on; any other value switches it off */
#define PANEL_OFF 0
#define WAIT_DONE 1     /* wait: wait until the switching is finished; any other value returns at once */

/*
 * Ask the panel power sequencer to switch the panel on or off, and optionally wait until that is done.
 *
 *   on    1: switch the panel on; any other value (callers pass 0): switch it off
 *   wait  1: do not return before the switching is finished; any other value: return after the first
 *         sequencer step
 *
 * Prints "SYSAPI_PanelOnOffControl = <on>", passes the request to the sequencer (panel_request_power) and runs
 * the sequencer once (panel_power_sequencer_task). When waiting, it repeats the sequencer step, the OLED
 * refresh-rate task (oled_frc_task) and ipc_signal_alive until panel_is_power_on_done (when switching on) or
 * panel_is_power_off (when switching off) reports 1.
 *
 * Callers include the application layer's power-on and power-off paths and the main loop task.
 */
void SYSAPI_PanelOnOffControl(unsigned int on, unsigned int wait)

{
  unsigned int done;

  dbg_printf("SYSAPI_PanelOnOffControl = %02x\r\n", on & 0xff);
  if ((on & 0xff) == PANEL_ON) {
    panel_request_power(1);
    panel_power_sequencer_task();
    if ((wait & 0xff) == WAIT_DONE) {
      do {
        done = panel_is_power_on_done();
        if ((done & 0xff) != 0) {
          break;
        }
        panel_power_sequencer_task();
        oled_frc_task();
        ipc_signal_alive();
      } while( 1 );
    }
  }
  else {
    panel_request_power(0);
    panel_power_sequencer_task();
    if ((wait & 0xff) == WAIT_DONE) {
      do {
        done = panel_is_power_off();
        if ((done & 0xff) != 0) {
          break;
        }
        panel_power_sequencer_task();
        oled_frc_task();
        ipc_signal_alive();
      } while( 1 );
    }
  }
  return;
}
