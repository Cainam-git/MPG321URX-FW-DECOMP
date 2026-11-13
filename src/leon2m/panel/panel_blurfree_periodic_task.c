/* panel_blurfree_periodic_task  (FUN_a0150248)
 *
 * Run the blur-reduction countdown while PWM channels are active.
 * Name basis: derived - counts halfword 0xA802CC88 down or reloads 1000 around PWM calls; called from the
 *   main-loop task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0150248, flags -mcpu=v8 -O3 -g.
 */

extern unsigned char panel_blurfree_channel_mask;
extern unsigned short panel_blurfree_timer;
extern unsigned short panel_blurfree_task_threshold;
extern unsigned short panel_blurfree_cycle_length;
extern void panel_pwm_set_duty(unsigned char channel, unsigned short duty);

/*
 * Periodic task of blur reduction; does nothing while no PWM channel is selected in the channel mask.
 *
 * value above the threshold: count the timer down one step per call; once it is 0, set the duty of channel
 * 0x18 to the cycle length on every call.
 * value at or below the threshold: set the duty of channel 0x18 to 0 and reload the timer with 1000.
 *
 * Called by sys_main_loop_periodic_task (main-loop task).
 */
void panel_blurfree_periodic_task(unsigned short value)
{
    if (panel_blurfree_channel_mask != 0) {
        if (value > panel_blurfree_task_threshold) {
            if (panel_blurfree_timer != 0)
                panel_blurfree_timer--;
            else
                panel_pwm_set_duty(0x18, panel_blurfree_cycle_length);
        } else {
            panel_pwm_set_duty(0x18, 0);
            panel_blurfree_timer = 1000;
        }
    }
}
