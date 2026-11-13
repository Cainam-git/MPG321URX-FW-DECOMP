/* startup_return_one  (FUN_a01423a0)
 *
 * Return 1.
 * Returns: 1
 * Name basis: descriptive - constant; called from start-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01423a0 @ 0xa01423a0, flags -mcpu=v8 -O2 -g.
 * Source form: a function returning the constant 1.
 */

/*
 * Return the constant 1. The system start-up (startup_bring_up_system) passes the result to sys_frc_set_config_index,
 * which stores it as the first index that selects the frame-rate converter's ROM settings.
 */
unsigned int startup_return_one(void)

{
  return 1;
}
