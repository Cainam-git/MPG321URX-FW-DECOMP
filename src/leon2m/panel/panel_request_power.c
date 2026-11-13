/* panel_request_power  (FUN_a01412b8)
 *
 * Ask the panel power sequencer to switch the panel on or off.
 * Name basis: proven - request to the sequencer; used by SYSAPI_PanelOnOffControl
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01412b8 @ 0xa01412b8, flags -mcpu=v8 -O3 -g.
 * Source form: the compiler moves the first store of panel_power_reverse_flag = 0 into each path, so the
 * firmware has no store at entry. panel_power_sequencer_task (panel_power_sequencer_task) is built with a static inline copy of
 * this routine, for its two calls.
 */
struct PwrSeq
{
  unsigned char state;
  unsigned short t;
  unsigned short req : 1;
  unsigned short rest : 15;
};
extern struct PwrSeq panel_power_state;
extern unsigned char panel_power_reverse_flag;

/* Values of panel_power_state.state, as panel_power_sequencer_task steps through them. */
#define PANEL_POWER_OFF       1     /* panel off */
#define PANEL_POWER_ON_FIRST  2     /* first and last of the four steps that switch the panel on */
#define PANEL_POWER_ON_LAST   5
#define PANEL_POWER_ON        6     /* panel on */
#define PANEL_POWER_OFF_FIRST 7     /* first and last of the three steps that switch the panel off */
#define PANEL_POWER_OFF_LAST  9

/*
 * Ask the panel power sequencer to switch the panel on or off. It only sets the state; panel_power_sequencer_task
 * carries it out step by step.
 *
 *   on  1: switch on, 0: switch off (any other value is treated like 0 when a sequence has to be started)
 *
 * - The panel is already moving that way or already there: nothing more.
 * - The panel is moving the other way (a switch-on request during the off steps, or the reverse): the request is
 *   not started now. panel_power_reverse_flag is set, and the sequencer runs the opposite request itself when
 *   its steps are finished. A switch-on request also sets the "req" bit of the sequencer record.
 * - Otherwise the sequence starts: state 2 (on) or 7 (off).
 *
 * Callers: SYSAPI_PanelOnOffControl, sys_run_app_timer_task and GlobalModeHandler.
 */
void panel_request_power(unsigned char on)
{
    panel_power_reverse_flag = 0;
    if ((on == 1 && (unsigned char)(panel_power_state.state - PANEL_POWER_ON_FIRST) <= PANEL_POWER_ON_LAST - PANEL_POWER_ON_FIRST) || (on == 0 && (unsigned char)(panel_power_state.state - PANEL_POWER_OFF_FIRST) <= PANEL_POWER_OFF_LAST - PANEL_POWER_OFF_FIRST))
        return;
    if ((on == 1 && panel_power_state.state == PANEL_POWER_ON) || (on == 0 && panel_power_state.state == PANEL_POWER_OFF))
        return;
    if ((on == 0 && (unsigned char)(panel_power_state.state - PANEL_POWER_ON_FIRST) <= PANEL_POWER_ON_LAST - PANEL_POWER_ON_FIRST) || (on == 1 && (unsigned char)(panel_power_state.state - PANEL_POWER_OFF_FIRST) <= PANEL_POWER_OFF_LAST - PANEL_POWER_OFF_FIRST)) {
        panel_power_reverse_flag = 1;
        if (on == 1)
            panel_power_state.req = 1;
    } else {
        if (on == 1)
            panel_power_state.state = PANEL_POWER_ON_FIRST;
        else
            panel_power_state.state = PANEL_POWER_OFF_FIRST;
    }
}
