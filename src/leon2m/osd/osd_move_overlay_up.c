/* osd_move_overlay_up  (FUN_a009478c)
 *
 * Move the edited indicator up in the position editor.
 * Note: Editor target by byte 0xA802D433: 0 refresh rate display, 1 alarm clock, 2 Smart Crosshair.
 * Name basis: derived - handler table 0xA802422C: up on state 0x108
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009478c @ 0xa009478c-0xa0094988 (127 words), flags -mcpu=v8 -O3 -g. No direct callers (reached through
 * a table). Exact form: the byte app_state_record+8 is a plain byte here, the step is read from it into an
 * unsigned char local; the two subtractions of the crosshair y are two separate tests.
 */
struct app_state_record { unsigned char pad[8]; unsigned char move_step; };
struct user_settings_record {
    unsigned char pad[0x1a3];
    unsigned char overlay_target;               /* +0x1A3: what the position editor moves, OVERLAY_* */
    unsigned char byte_0x1a4;
    unsigned char refresh_rate_custom_x;        /* +0x1A5 */
    unsigned char refresh_rate_custom_y;        /* +0x1A6 */
    unsigned char alarm_clock_custom_x;         /* +0x1A7 */
    unsigned char alarm_clock_custom_y;         /* +0x1A8 */
    unsigned char pad1a9[3];
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
#define MOVE_RUN_UP             0               /* high nibble of the move byte during an Up run */

/*
 * Move the overlay being placed one step up (Up key in menu state 0x108, reached through the handler table).
 * user_settings.overlay_target says which overlay it is.
 *
 * Refresh rate display and alarm clock: their y position (a small grid number) goes down by 1 unless it is 0;
 * the preview is erased before and redrawn after the change (osd_draw_overlay_position_preview).
 *
 * Smart Crosshair: crosshair_y goes down by a step kept in the low nibble of app_state_record.move_step. An Up
 * run starts at step 1 (byte 0x01) and uses step 5 and then 10 once the key has been held for more than 2000
 * and 5000 ticks; a pause of more than 100 ticks, or a run begun by another direction (other id in the high
 * nibble), restarts at step 1. The step is taken off when crosshair_y is at least the step; a value that is then
 * below the step is set to 0. The crosshair layer is then moved to the new origin.
 */
void osd_move_overlay_up(void)
{
    unsigned char step;

    if (user_settings.overlay_target == OVERLAY_REFRESH_RATE) {
        if (user_settings.refresh_rate_custom_y != 0) {
            osd_draw_overlay_position_preview(0, 0, 1);
            user_settings.refresh_rate_custom_y--;
            osd_draw_overlay_position_preview(0, 0, 0);
        }
    } else if (user_settings.overlay_target == OVERLAY_ALARM_CLOCK) {
        if (user_settings.alarm_clock_custom_y != 0) {
            osd_draw_overlay_position_preview(1, 0, 1);
            user_settings.alarm_clock_custom_y--;
            osd_draw_overlay_position_preview(1, 0, 0);
        }
    } else if (user_settings.overlay_target == OVERLAY_CROSSHAIR) {
        if (timer_ticks_since(osd_move_key_ticks) > MOVE_GAP_TICKS) {
            app_state_record.move_step = 1;
            osd_move_hold_ticks = timer_api_get_ticks16();
        }
        osd_move_key_ticks = timer_api_get_ticks16();
        if ((app_state_record.move_step >> 4) != MOVE_RUN_UP) {
            app_state_record.move_step = 1;
            osd_move_hold_ticks = timer_api_get_ticks16();
        }
        if (timer_ticks_since(osd_move_hold_ticks) > MOVE_HOLD_FAST_TICKS)
            if (timer_ticks_since(osd_move_key_ticks) <= MOVE_GAP_TICKS - 1)
                app_state_record.move_step = 5;
        if (timer_ticks_since(osd_move_hold_ticks) > MOVE_HOLD_FASTEST_TICKS)
            if (timer_ticks_since(osd_move_key_ticks) <= MOVE_GAP_TICKS - 1)
                app_state_record.move_step = 0xa;
        step = app_state_record.move_step & 0xf;
        if (user_settings.crosshair_y >= step)
            user_settings.crosshair_y -= step;
        if (user_settings.crosshair_y < step)
            user_settings.crosshair_y = 0;
        osd_api_set_origin_and_size(user_settings.crosshair_x, user_settings.crosshair_y, 1);
    }
}
