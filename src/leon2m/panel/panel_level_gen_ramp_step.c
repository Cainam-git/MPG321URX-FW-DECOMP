/* panel_level_gen_ramp_step  (FUN_a0129c10)
 *
 * Advance the level generator's ramp by one step and switch the generator on when it ends.
 * Name basis: descriptive - ramp flag at 0xA802CA04; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0129c10 @ 0xa0129c10-0xa0129c64 (21 words), flags -mcpu=v8 -O3 -g.
 * Source form: the byte is stored back from the return value of panel_level_gen_ramp_next before it is tested.
 */
extern unsigned char panel_level_gen_ramp_running;
extern int panel_level_gen_ramp_next(unsigned char restart);
extern void panel_level_gen_set_enable(unsigned char);

/*
 * Take one step of the level generator's ramp and switch the generator on when the ramp has ended.
 *
 *   restart  nonzero: start a new ramp (the ramp byte is set to 1 and panel_level_gen_ramp_next resets the
 *            block first); zero: continue the ramp that is running
 *
 * The byte panel_level_gen_ramp_running (panel_level_gen_ramp_running) is 1 while a ramp is running; it takes the value
 * panel_level_gen_ramp_next returns, which is 0 when the ramp has reached its end. Nothing happens while it is 0.
 * No routine calls this one.
 */
void panel_level_gen_ramp_step(unsigned char restart)
{
    if (restart)
        panel_level_gen_ramp_running = 1;
    if (panel_level_gen_ramp_running) {
        panel_level_gen_ramp_running = panel_level_gen_ramp_next(restart);
        if (panel_level_gen_ramp_running == 0)
            panel_level_gen_set_enable(1);
    }
}
