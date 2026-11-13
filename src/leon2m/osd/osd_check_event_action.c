/* osd_check_event_action  (FUN_a008a034)
 *
 * Flag a menu event whose action number is 3 or lower.
 *   event: event code
 * Note: Only OSD events (type 0x80); tables ROM 0x100068 / 0x100060.
 * Name basis: derived - header: event decode; 0x80 = OSDEvent in APPActionDispatcher
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008a034, flags -mcpu=v8 -O3 -g.
 * Source form: the switch keeps an explicit 'case 0x40: v = 4;' (the firmware tests 0x40 first and branches
 * straight to the v test: that case has its own label in the source; without it gcc drops the 0x40 compare).
 * Its body is the default value, so behaviour is the same as 'if ((p & 0xc0) == 0x80)'.
 */

#define EVENT_TYPE_MASK        0xc0             /* bits 6..7 of an event code: the event type */
#define EVENT_TYPE_KEY         0x40
#define EVENT_TYPE_OSD         0x80
#define EVENT_INDEX_MASK       0x3f             /* bits 0..5: the event's number */
#define OSD_EVENT_ROW_NONE     4                /* osd_event_action_rows entry for an event without an action */
#define OSD_EVENT_ACTION_NONE  4                /* above the flagged range */
#define OSD_EVENT_ACTION_LAST_FLAGGED 3         /* action numbers 0..3 flag the event */

extern const unsigned char osd_event_action_numbers[], osd_event_action_rows[];
extern void osd_set_event_flag(void);

/*
 * Look up the action number of a menu event and call osd_set_event_flag when it is 3 or lower. Only OSD events
 * (type 0x80) have an action number: osd_event_action_rows maps the event's number to a row of
 * osd_event_action_numbers (row 4 = none).
 *   event: event code (type in bits 6..7, number in bits 0..5)
 */
void osd_check_event_action(int event)
{
  unsigned char action = OSD_EVENT_ACTION_NONE;

  switch (event & EVENT_TYPE_MASK) {
  case EVENT_TYPE_KEY:
    action = OSD_EVENT_ACTION_NONE;
    break;
  case EVENT_TYPE_OSD: {
    unsigned char row = osd_event_action_rows[event & EVENT_INDEX_MASK];
    if (row != OSD_EVENT_ROW_NONE)
      action = osd_event_action_numbers[row];
    break;
  }
  }
  if (action <= OSD_EVENT_ACTION_LAST_FLAGGED)
    osd_set_event_flag();
}
