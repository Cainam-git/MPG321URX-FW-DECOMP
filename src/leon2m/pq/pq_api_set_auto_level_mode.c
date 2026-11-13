/* pq_api_set_auto_level_mode  (FUN_a01492b8)
 *
 * Store the mode byte and start the automatic level stepping when it is 1.
 * Name basis: descriptive - stSysConfig byte +7; mode 1 calls the routine that steps a level from 16 measured
 *   words
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01492b8 @ 0xa01492b8, flags -mcpu=v8 -O2 -g (section default).
 * Source form: the test is 'mode != 1' with the stub call in the first arm; each arm ends in its own return.
 */
extern unsigned char sys_config_auto_level_mode;
extern void pq_auto_level_task(unsigned char start);
extern void sys_poll_events_stub_copy14(void);

#define AUTO_LEVEL_STEPPING 1           /* sys_config_auto_level_mode: stepping on */

/*
 * Store the automatic level mode (sys_config byte +7). Mode 1 runs pq_auto_level_task with start = 1, which
 * sets the ACE block up and makes the stored brightness the applied level; any other mode calls an empty
 * routine, so nothing else happens.
 * Callers, each with a value 0..3: UserSetProMode, UserSetGameMode, sys_user_apply_auto_level and
 * sys_user_factory_reset.
 */
void pq_api_set_auto_level_mode(unsigned char mode)
{
  sys_config_auto_level_mode = mode;
  if (mode != AUTO_LEVEL_STEPPING) {
    sys_poll_events_stub_copy14();
    return;
  }
  pq_auto_level_task(1);
  return;
}
