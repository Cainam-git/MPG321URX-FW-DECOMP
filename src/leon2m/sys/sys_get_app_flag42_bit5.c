/* sys_get_app_flag42_bit5  (FUN_a0083c20)
 *
 * Return bit 5 of the application flag halfword 0xA802AF42.
 * Returns: 0 or 1
 * Name basis: descriptive - code only; caller osd_run_periodic_task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0083c20 @ 0xa0083c20, flags -mcpu=v8 -O2 -g (section default).
 * Returns (app_port_flags >> 5) & 1 as an unsigned short.
 */
extern unsigned short app_port_flags;

/*
 * Return bit 5 of app_port_flags (1 or 0): the second-group bit (5 + port) of port 0.
 * Called by osd_run_periodic_task.
 */
unsigned short sys_get_app_flag42_bit5(void)
{
  return app_port_flags >> 5 & 1;
}
