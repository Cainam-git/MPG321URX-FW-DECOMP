/* panel_is_power_on_done  (FUN_a0141a98)
 *
 * Return whether the panel power sequencer has finished switching on.
 * Returns: 0 or 1
 * Name basis: derived - sequencer state 6 with its done flag
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0141a98 @ 0xa0141a98 (-mcpu=v8 -O2 -g).
 * Source form: the result is a local preset to 1 and cleared in two places (the else arm of the state test and
 * the failed flag test); the Ghidra layout of the nested if / else is kept.
 */
#define PANEL_POWER_ON 6    /* panel_power_state value: panel on (the state the sequencer reaches after the switch-on steps) */

extern unsigned char panel_power_on_done_flag;
extern unsigned char panel_power_state;

/*
 * Tell whether the switch-on of the panel is complete: the sequencer is in its "panel on" state AND its done
 * flag is set. The done flag is set by panel_power_sequencer_task 100 ticks after it entered the "panel on"
 * state, and cleared when a switch-on or switch-off starts, so the answer is 0 during the switching and during
 * those first 100 ticks. Returns 1 or 0.
 */
unsigned int panel_is_power_on_done(void)
{
  unsigned int result;

  result = 1;
  if (panel_power_state == PANEL_POWER_ON) {
    if (panel_power_on_done_flag != 1) {
      result = 0;
    }
  }
  else {
    result = 0;
  }
  return result;
}
