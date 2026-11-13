/* sys_pump_app_events  (FUN_a008a210)
 *
 * Collect events from all producers and dispatch up to 10 of them.
 * Note: Producers: port events, OSD flags, keys, DDC/CI flags; consumer APPActionDispatcher.
 * Name basis: proven - calls the event producers and APPActionDispatcher
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008a210 @ 0xa008a210, flags -mcpu=v8 -O3 -g
 * APP main step: empties the event queue (read index app_event_read_index, count app_event_count), runs the APP event
 * generator sys_app_generate_events and three more producers, then pops each queued event from app_event_queue[]
 * (at most 10) and hands it to the action dispatcher APPActionDispatcher and three more consumers.
 */
extern unsigned char app_event_read_index;
extern unsigned char app_event_count;
extern unsigned char app_event_queue[];
extern void sys_app_generate_events();
extern void osd_run_task_post_redraw_event();
extern void sys_scan_keys_post_event();
extern void ddc_post_pending_event();
extern void APPActionDispatcher(unsigned int ev);
extern void osd_dispatch_key_event();
extern void sys_poll_events_stub();
extern void osd_check_event_action();

#define APP_EVENT_QUEUE_SIZE 10         /* most events the queue holds */

/*
 * Collect the events of all producers and dispatch them.
 *
 * The queue is emptied first. Then four producers post events with sys_post_app_event: sys_app_generate_events,
 * osd_run_task_post_redraw_event, sys_scan_keys_post_event and ddc_post_pending_event. Each queued event
 * (at most 10, in order) is then handed to four consumers: APPActionDispatcher, osd_dispatch_key_event,
 * sys_poll_events_stub (does nothing) and osd_check_event_action.
 * Called by sys_run_app_main_task.
 */
void sys_pump_app_events(void)
{
    unsigned char ev;

    app_event_read_index = 0;
    app_event_count = 0;
    sys_app_generate_events();
    osd_run_task_post_redraw_event();
    sys_scan_keys_post_event();
    ddc_post_pending_event();
    while (app_event_count != 0 && app_event_read_index <= APP_EVENT_QUEUE_SIZE - 1) {
        ev = app_event_queue[app_event_read_index++];
        if (app_event_count != 0)
            app_event_count--;
        APPActionDispatcher(ev);
        osd_dispatch_key_event(ev);
        sys_poll_events_stub(ev);
        osd_check_event_action(ev);
    }
}
