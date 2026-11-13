/* sys_run_app_main_task  (FUN_a0087430)
 *
 * Run one application step: event pump, periodic OSD task, timer task and DDC/CI request task.
 * Note: One of the main-loop tasks called by startup_main.
 * Name basis: proven - calls the event pump, APP timer task and DDC/CI task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0087430 @ 0xa0087430, flags -mcpu=v8 -O2 -g (section default).
 * Calls sys_pump_app_events(), osd_run_periodic_task(), sys_run_app_timer_task() and passes its six arguments to
 * ddc_run_request_task. The four callees are declared with empty parameter lists.
 */
extern int sys_run_app_timer_task();
extern int ddc_run_request_task();
extern int sys_pump_app_events();
extern int osd_run_periodic_task();

/*
 * One step of the application, run from the main loop (startup_main): dispatch the pending events, run the
 * periodic OSD task, run the timer task, then the DDC/CI request task.
 *
 * The six arguments are handed to ddc_run_request_task unchanged; the other three tasks take none.
 */
void sys_run_app_main_task(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3,
                 unsigned int arg4, unsigned int arg5)
{
  sys_pump_app_events();
  osd_run_periodic_task();
  sys_run_app_timer_task();
  ddc_run_request_task(arg0, arg1, arg2, arg3, arg4, arg5);
}
