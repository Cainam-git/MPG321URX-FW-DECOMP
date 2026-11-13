/* osd_run_task_post_redraw_event  (FUN_a00a012c)
 *
 * Run the menu timers, then post the first pending menu redraw request as an event.
 * Note: Posts 0x80..0x83 (0x84 none) from the request bits of byte 0xA802B08E.
 * Name basis: derived - calls osd_run_periodic_task then sys_post_app_event; called by sys_pump_app_events
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a012c, flags -mcpu=v8 -O2 -g.
 * Source form: the event code is one local, set by an if / else chain in this order; the last call posts it.
 */
extern void osd_run_periodic_task(void);
extern unsigned char osd_take_settings_changed(void), osd_take_request_bit0(void), osd_take_request_bit3(void), osd_take_request_bit2(void);
extern void sys_post_app_event(unsigned char code);

/* Menu event codes (type OSD = 0x80). Event 0x84 is the 'none' code that sys_post_app_event drops. */
#define OSD_EVENT_SETTINGS_CHANGED 0x80
#define OSD_EVENT_81               0x81
#define OSD_EVENT_82               0x82
#define OSD_EVENT_83               0x83
#define OSD_EVENT_NONE             0x84

/*
 * Run the menu's periodic task (osd_run_periodic_task), then post one menu event for the first pending request
 * bit of the request byte at 0xA802B08E. The checks run in this order and take (clear) only the bit they find:
 *   bit 1 (settings changed)  event 0x80
 *   bit 0                     event 0x82
 *   bit 3                     event 0x81
 *   bit 2                     event 0x83
 * With no bit set the 'none' event 0x84 is posted, which sys_post_app_event drops.
 * Called from sys_pump_app_events.
 */
void osd_run_task_post_redraw_event(void)
{
    unsigned char event = OSD_EVENT_NONE;

    osd_run_periodic_task();
    if (osd_take_settings_changed())
        event = OSD_EVENT_SETTINGS_CHANGED;
    else if (osd_take_request_bit0())
        event = OSD_EVENT_82;
    else if (osd_take_request_bit3())
        event = OSD_EVENT_81;
    else if (osd_take_request_bit2())
        event = OSD_EVENT_83;
    sys_post_app_event(event);
}
