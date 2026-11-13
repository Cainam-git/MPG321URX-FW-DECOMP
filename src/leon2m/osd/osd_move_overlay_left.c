/* osd_move_overlay_left  (FUN_a00945a8)
 *
 * Move the edited indicator left in the position editor.
 * Note: Editor target by byte 0xA802D433: 0 refresh rate display, 1 alarm clock, 2 Smart Crosshair.
 * Name basis: derived - handler table 0xA802422C: left on state 0x108
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00945a8 @ 0xa00945a8-0xa009478c (121 words), flags -mcpu=v8 -O3 -g. No direct callers (reached through
 * a table). Exact form: the byte app_state_record+8 is a union of a plain byte and two 4-bit bit-fields; the step
 * is the low bit-field read into an unsigned short local. The three target values are an if / else chain.
 */
union move_step_byte { unsigned char byte; struct { unsigned char run_id : 4, step : 4; } f; };
struct app_state_record { unsigned char pad[8]; union move_step_byte move_step; };
struct user_settings_record {
    unsigned char pad[0x1a3];
    unsigned char overlay_target;               /* +0x1A3: what the position editor moves, OVERLAY_* */
    unsigned char byte_0x1a4;
    unsigned char refresh_rate_custom_x;        /* +0x1A5 */
    unsigned char refresh_rate_custom_y;        /* +0x1A6 */
    unsigned char alarm_clock_custom_x;         /* +0x1A7 */
    unsigned char pad1a8[4];
    unsigned short crosshair_x;                 /* +0x1AC */
    unsigned short crosshair_y;                 /* +0x1AE */
};
extern struct app_state_record app_state_record;
extern struct user_settings_record user_settings;
extern unsigned short osd_move_key_ticks, osd_move_hold_ticks;
extern unsigned short timer_api_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short start);
extern void osd_draw_overlay_position_preview(int, int, int);
extern void osd_api_set_origin_and_size(int, int, int);

#define OVERLAY_REFRESH_RATE    0               /* position editor target: the refresh rate display */
#define OVERLAY_ALARM_CLOCK     1               /* the alarm clock */
#define OVERLAY_CROSSHAIR       2               /* the Smart Crosshair */
#define MOVE_GAP_TICKS          100             /* more ticks than this since the last move: a new run starts */
#define MOVE_HOLD_FAST_TICKS    2000            /* run held longer than this: the next step size */
#define MOVE_HOLD_FASTEST_TICKS 5000            /* run held longer than this: the largest step size */
#define MOVE_RUN_LEFT           2               /* high nibble of the move byte during a Left run */

/*
 * Move the overlay being placed one step to the left (Left key in menu state 0x108, reached through the handler
 * table). user_settings.overlay_target says which overlay it is.
 *
 * Refresh rate display and alarm clock: their x position (a small grid number) goes down by 1 unless it is 0;
 * the preview is erased before and redrawn after the change (osd_draw_overlay_position_preview).
 *
 * Smart Crosshair: the x position in crosshair_x moves by a step kept in the low nibble of
 * app_state_record.move_step. A Left run starts at step 2 and uses step 6 and then 10 once the key has been
 * held for more than 2000 and 5000 ticks; a pause of more than 100 ticks, or a run begun by another
 * direction (other id in the high nibble), restarts at step 2. The step is taken off crosshair_x when it
 * fits; otherwise crosshair_x goes down by 2 while it is above 1. The crosshair layer is then moved to the
 * new origin.
 */
void osd_move_overlay_left(void)
{
    unsigned short step;

    if (user_settings.overlay_target == OVERLAY_REFRESH_RATE) {
        if (user_settings.refresh_rate_custom_x != 0) {
            osd_draw_overlay_position_preview(0, 0, 1);
            user_settings.refresh_rate_custom_x--;
            osd_draw_overlay_position_preview(0, 0, 0);
        }
    } else if (user_settings.overlay_target == OVERLAY_ALARM_CLOCK) {
        if (user_settings.alarm_clock_custom_x != 0) {
            osd_draw_overlay_position_preview(1, 0, 1);
            user_settings.alarm_clock_custom_x--;
            osd_draw_overlay_position_preview(1, 0, 0);
        }
    } else if (user_settings.overlay_target == OVERLAY_CROSSHAIR) {
        if (timer_ticks_since(osd_move_key_ticks) > MOVE_GAP_TICKS) {
            app_state_record.move_step.byte = 0x22;
            osd_move_hold_ticks = timer_api_get_ticks16();
        }
        osd_move_key_ticks = timer_api_get_ticks16();
        if ((app_state_record.move_step.byte >> 4) != MOVE_RUN_LEFT) {
            app_state_record.move_step.byte = 0x22;
            osd_move_hold_ticks = timer_api_get_ticks16();
        }
        if (timer_ticks_since(osd_move_hold_ticks) > MOVE_HOLD_FAST_TICKS)
            if (timer_ticks_since(osd_move_key_ticks) <= MOVE_GAP_TICKS - 1)
                app_state_record.move_step.byte = 0x26;
        if (timer_ticks_since(osd_move_hold_ticks) > MOVE_HOLD_FASTEST_TICKS)
            if (timer_ticks_since(osd_move_key_ticks) <= MOVE_GAP_TICKS - 1)
                app_state_record.move_step.byte = 0x2a;
        step = app_state_record.move_step.f.step;
        if (step <= user_settings.crosshair_x)
            user_settings.crosshair_x -= step;
        else if (user_settings.crosshair_x > 1)
            user_settings.crosshair_x -= 2;
        osd_api_set_origin_and_size(user_settings.crosshair_x, user_settings.crosshair_y, 1);
    }
}
