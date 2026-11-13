/* ddc_post_pending_event  (FUN_a008a09c)
 *
 * Post the first pending DDC/CI event flag as event 0xC0..0xC6.
 * Note: Nothing posted when no flag is set (0xC7).
 * Name basis: proven - posts type 0xC0 = DDCCiEvent through sys_post_app_event
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008a09c, flags -mcpu=v8 -O2 -g.
 * Source forms the exact build depends on:
 *  - the callees are tried in the order bit 0, bit 1, bit 3, bit 2, bit 4, 5, 6 (the order of the if chain);
 *  - the event code is an unsigned char local starting at 0xc7, and the call passes it as unsigned char (the
 *    firmware masks it with 0xc7 because every value 0xc0..0xc7 has bits 3..5 clear).
 */
extern unsigned char ddc_take_event0(void), ddc_take_event1(void), ddc_take_event3(void), ddc_take_event2(void);
extern unsigned char ddc_take_event4(void), ddc_take_event5(void), ddc_take_event6(void);
extern void sys_post_app_event(unsigned char code);

#define APP_EVENT_DDCCI_NONE  0xc7      /* handed on when no flag is set; 0xC0..0xC6 are the DDC/CI events */

/*
 * Take the first set flag of ddc_pending_events and post it as an application event: the flags of bits
 * 0, 1, 3, 2, 4, 5, 6 give the events 0xC0, 0xC2, 0xC1, 0xC3, 0xC4, 0xC5, 0xC6. At most one event per call.
 * When no flag is set, 0xC7 is handed on.
 */
void ddc_post_pending_event(void)
{
    unsigned char event = APP_EVENT_DDCCI_NONE;

    if (ddc_take_event0())
        event = 0xc0;
    else if (ddc_take_event1())
        event = 0xc2;
    else if (ddc_take_event3())
        event = 0xc1;
    else if (ddc_take_event2())
        event = 0xc3;
    else if (ddc_take_event4())
        event = 0xc4;
    else if (ddc_take_event5())
        event = 0xc5;
    else if (ddc_take_event6())
        event = 0xc6;
    sys_post_app_event(event);
}
