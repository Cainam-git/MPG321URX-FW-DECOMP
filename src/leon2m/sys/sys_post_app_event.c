/* sys_post_app_event  (FUN_a008a184)
 *
 * Append an event to the application event queue (at most 10)
 *   ev: event code
 * Note: Queue 0xA802AFA8; the 'none' codes 0x3F, 0x4F, 0x84 and 0xC7 are dropped.
 * Name basis: proven - record: APP event post
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008a184 @ 0xa008a184, flags -mcpu=v8 -O3 -g
 * APP event post: appends event 'ev' to the 10-entry event queue app_event_queue[] (count app_event_count),
 * except events 0x3F, 0x4F, 0x84, 0xC7, which are dropped; a full queue (count 10) drops the event.
 */
extern unsigned char app_event_count;
extern unsigned char app_event_queue[];

#define APP_EVENT_QUEUE_SIZE 10         /* most events the queue holds */

/*
 * Append event ev to the application event queue.
 *
 *   ev   event code (type in bits 6..7: 0 application, 0x40 key, 0x80 OSD, 0xC0 DDC/CI; index in bits 0..5)
 *
 * The events 0x3F, 0x4F, 0x84 and 0xC7 (the 'none' code of each type) are not queued, and nothing is queued
 * when the queue already holds 10 events. The queue is emptied by sys_pump_app_events.
 */
void sys_post_app_event(unsigned char ev)
{
    unsigned char n;

    if (ev == 0x3f || ev == 0x4f || ev == 0x84 || ev == 0xc7)
        return;
    n = app_event_count;
    if (n == APP_EVENT_QUEUE_SIZE)
        return;
    app_event_queue[n] = ev;
    n++;
    if (n > APP_EVENT_QUEUE_SIZE)
        app_event_count = APP_EVENT_QUEUE_SIZE;
    else
        app_event_count = n;
}
