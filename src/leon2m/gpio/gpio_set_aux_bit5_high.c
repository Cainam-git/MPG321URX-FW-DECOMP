/* gpio_set_aux_bit5_high  (FUN_a0125bc4)
 *
 * Ask for pin 5 of GPIO port number 0xFF to go high; no pin changes (gpio_write_pin: ports 1..17).
 * Note: gpio_write_pin has no arm for port 0xFF, so the call writes nothing; called by sys_run_app_timer_task,
 *   App_Initialize.
 * Name basis: descriptive - gpio_write_pin(0xFF, 0x20, 0x1); port number 0xFF is not among the ports 1..17 the
 *   pin routines serve
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125bc4 @ 0xa0125bc4, flags -mcpu=v8 -O2 -g.
 */
extern int gpio_write_pin();

/*
 * Write level 1 (high) to mask 0x20 (pin 5) of port 0xff.
 * Port 0xff is not one of the ports 1..17 that gpio_write_pin handles, so the call changes nothing.
 * Called by App_Initialize and sys_run_app_timer_task.
 */
void gpio_set_aux_bit5_high(void)
{
    gpio_write_pin(0xff, 0x20, 1);
}
