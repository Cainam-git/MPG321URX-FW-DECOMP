/* sys_scan_keys_post_event  (FUN_a008e7b0)
 *
 * Read the front keys, apply repeat, long-press and block rules, and post the key event.
 * Note: Key codes 0x40..0x4E from ROM table 0x10051F; 0x4F = none; key 0x40 is dropped within 1 s of the time
 *   stamp 0xA802D00E.
 * Name basis: proven - posts 0x40-type key events via sys_post_app_event; timing from the key timing setters
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008e7b0 @ 0xa008e7b0-0xa008ec48 (294 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three table searches are unsigned char for loops (as in sys_read_startup_key), the two code-table
 *    searches with 'entry = j & 0xf' into the unsigned int entry;
 *  - key_entry and saved_entry are unsigned char locals assigned from entry ('key_entry = entry;
 *    saved_entry = entry;'): their zero extensions stay 'and 0xff' (0xa008e8ac, 0xa008e9f8, 0xa008eb58,
 *    0xa008eb7c); the same-key tests are 'key_entry != 0';
 *  - the KEY_MODE_BLOCKED arm clears sys_key_last_entry and key_entry and jumps past 'key_entry = saved_entry;'
 *    (goto);
 *  - one local, event, holds first the key bit and later the key event.
 */

/* sys_key_code_table (ROM 0x10051F): 16 entries {scan code, key event}. Entry 0 is {0, KEY_EVENT_NONE}; a scan
   code that is in no entry also gives entry 0, and entries with scan code 0 are never found. Entries 1..14 hold
   events from 0x40 to 0x4E; entry 15 is {0, 0}. */
#define KEY_ENTRIES             16
#define KEY_ENTRY_NONE          0
#define KEY_ENTRY_SCAN_CODE     0       /* byte 0 of an entry */
#define KEY_ENTRY_EVENT         1       /* byte 1 of an entry */
#define KEY_EVENT_NONE          0x4f    /* "no key": sys_post_app_event drops it */
#define KEY_EVENT_40            0x40    /* event of entry 1 (scan code 1) */
#define KEY_EVENT_41            0x41    /* event of entry 2 (scan code 2) */

/* sys_key_bit_table (ROM 0x10053F): 6 pairs {key input bit, key bit} for the factory key test. */
#define KEY_BIT_ENTRIES         6
#define FACTORY_KEY_TEST_BITS   0x10    /* factory_record +0x10: one bit per front key passed in the key test */
#define FACTORY_MODE_MARKER     0x55aa  /* user_settings +0x1F6 while the factory tool's factory mode is on */
#define EEPROM_AREA             0x30    /* SYSAPI_WriteEEPROM: the one area code it knows */
#define FACTORY_RECORD_OFFSET   0x2e0
#define FACTORY_RECORD_SIZE     0x1c

#define APP_STATE_STARTUP_KEY   0x0800  /* app_state_record halfword +0: bit 11, cleared on every scan */
#define SETTINGS_WORD0_BIT14    0x4000  /* user settings word +0, bit 14 */
#define STARTUP_KEY_SCAN_CODE   2       /* the key scan value that sets SETTINGS_WORD0_BIT14 */

/* Key modes (sys_key_mode), chosen from the four per-key bit masks when a key is pressed. A later
   mask wins: blocked over long/short over long-only over repeat. */
#define KEY_MODE_NONE           0       /* the event is posted once, at the press */
#define KEY_MODE_REPEAT         1       /* sys_key_repeat_mask: at the press, after the repeat delay, then at each
                                           repeat interval */
#define KEY_MODE_LONG_ONLY      2       /* sys_key_long_only_mask: once, when held past the long-press time */
#define KEY_MODE_LONG_ALT       3       /* sys_key_long_alt_mask: held past the long-press time, the event of
                                           sys_key_long_codes[entry]; let go earlier, its own event */
#define KEY_MODE_BLOCKED        4       /* sys_key_blocked_mask: no event */

#define POWER_ON_KEY_HOLD_OFF   1000    /* ticks after app_state_record.power_on_ticks in which KEY_EVENT_40 is
                                           dropped */

/* An entry of sys_key_bit_table. */
struct key_bit_entry
{
  unsigned char input_bit;
  unsigned char key_bit;
};
/* The fields of the user settings record used here. */
struct user_settings_record
{
  unsigned int word_0x0;                /* +0x000 */
  unsigned char p004[0x1d1];
  unsigned char burn_in_flag;           /* +0x1D5 */
  unsigned char p1d6[0x20];
  unsigned short factory_mode_marker;   /* +0x1F6 */
};
/* The fields of the application state record (0xA802CFF4) used here. */
struct app_state_record
{
  union
  {
    unsigned short half_0x0;            /* +0x00: bit 11 = APP_STATE_STARTUP_KEY */
    struct
    {
      unsigned short bit15 : 1;         /* when set, KEY_EVENT_41 is posted once and the bit cleared */
      unsigned short : 15;
    } bits;
  } u0;
  unsigned char p2[4];
  unsigned char pressed_key_bit;        /* +0x06: key bit of the last key read, for the factory key test */
  unsigned char p7[0x13];
  unsigned short power_on_ticks;        /* +0x1A: tick count stored by App_Initialize at power-on type 1 */
};
extern const struct key_bit_entry sys_key_bit_table[6];
extern unsigned char sys_key_code_table[];
extern struct user_settings_record user_settings;
extern struct app_state_record app_state_record;
extern unsigned char factory_record[];
extern unsigned char sys_key_last_entry;
extern unsigned int sys_key_mode;
extern unsigned short sys_key_hold_ticks;
extern unsigned short sys_key_wait_time;
extern unsigned short sys_key_blocked_mask;
extern unsigned short sys_key_long_alt_mask;
extern unsigned short sys_key_long_only_mask;
extern unsigned short sys_key_repeat_mask;
extern unsigned char sys_key_long_codes[];
extern unsigned short sys_key_long_press_time;
extern unsigned short sys_key_repeat_interval;
extern unsigned short sys_key_repeat_delay;
extern unsigned char input_read_keys_debounced(void);
extern int SYSAPI_WriteEEPROM(unsigned char, void *, unsigned short, unsigned short);
extern unsigned short timer_api_get_ticks16(void);
extern unsigned short timer_api_ticks_since(unsigned short);
extern void sys_post_app_event(unsigned char);

/*
 * The front-key producer of the application event queue: read the keys, apply the key's mode (repeat,
 * long-press, blocked) and post at most one key event, plus KEY_EVENT_41 when the state record asks for it.
 * Called on every pass by sys_pump_app_events, after sys_app_generate_events and
 * osd_run_task_post_redraw_event.
 * Takes no arguments and returns nothing; all its state is in the sys_key_* variables.
 *
 * The phases, in order:
 *   1. Two debounced key reads (input_read_keys_debounced): the first gives the scan code for the key events,
 *      the second the keys for the factory key test and the start-up key option.
 *   2. Factory key test: the key bit of the first pressed key (sys_key_bit_table) is kept in the state record;
 *      in factory mode, with burn-in off, a key bit not yet in the factory record's test bits is added and
 *      the factory record is saved.
 *   3. Start-up key: while APP_STATE_STARTUP_KEY is set, key value 2 sets SETTINGS_WORD0_BIT14 and any other
 *      value clears it; APP_STATE_STARTUP_KEY is then cleared (on every scan).
 *   4. The scan code is looked up in sys_key_code_table; the entry number (0 = no key) is the key from here on.
 *   5. Key change or key held, by the key's mode (KEY_MODE_*). Times are counted from sys_key_hold_ticks in
 *      timer ticks: sys_key_repeat_delay, sys_key_repeat_interval and sys_key_long_press_time.
 *   6. The event of the resulting entry is posted. KEY_EVENT_40 within 1000 ticks of the power-on time stamp
 *      becomes KEY_EVENT_NONE, and KEY_EVENT_NONE is dropped by sys_post_app_event.
 *   7. KEY_EVENT_41 is posted once more when bit 15 of the state record's first halfword is set.
 *
 * sys_key_last_entry holds the entry number (not the scan code) seen at the last scan.
 */
void sys_scan_keys_post_event(void)
{
  unsigned char scan_code;
  unsigned char keys;
  unsigned char event = 0;      /* first the key bit for the key test, then the key event */
  unsigned char saved_entry;
  unsigned char j;
  unsigned int entry;
  unsigned char key_entry;

  /* 1. Read the keys twice. */
  scan_code = input_read_keys_debounced();
  keys = input_read_keys_debounced();
  /* 2. Factory key test. */
  if (keys != 0)
  {
    for (j = 0; j < KEY_BIT_ENTRIES; j++)
    {
      if (sys_key_bit_table[j].input_bit & keys)
      {
        event = sys_key_bit_table[j].key_bit;
        break;
      }
    }
    app_state_record.pressed_key_bit = event;
    if (((user_settings.factory_mode_marker == FACTORY_MODE_MARKER) && (!(factory_record[FACTORY_KEY_TEST_BITS] & app_state_record.pressed_key_bit))) && (user_settings.burn_in_flag == 0))
    {
      factory_record[FACTORY_KEY_TEST_BITS] |= app_state_record.pressed_key_bit;
      SYSAPI_WriteEEPROM(EEPROM_AREA, factory_record, FACTORY_RECORD_OFFSET, FACTORY_RECORD_SIZE);
    }
  }
  /* 3. Start-up key option (the same step as in sys_read_startup_key). */
  if (app_state_record.u0.half_0x0 & APP_STATE_STARTUP_KEY)
  {
    if (keys == STARTUP_KEY_SCAN_CODE)
    {
      user_settings.word_0x0 |= SETTINGS_WORD0_BIT14;
    }
    else
    {
      user_settings.word_0x0 &= ~SETTINGS_WORD0_BIT14;
    }
  }
  app_state_record.u0.half_0x0 &= ~APP_STATE_STARTUP_KEY;
  /* 4. Entry of the scan code; not found (j = 16) wraps to entry 0. */
  for (j = 0; j < KEY_ENTRIES; j++)
    if (sys_key_code_table[j * 2 + KEY_ENTRY_SCAN_CODE] == scan_code)
      break;
  entry = j & 0xf;
  key_entry = entry;
  saved_entry = entry;
  /* 5. Key change or key held. */
  if (sys_key_last_entry != key_entry)
  {
    if (key_entry == KEY_ENTRY_NONE)
    {
      /* Let go. A long/short key let go before the long-press time sends its own event now. */
      if (sys_key_mode == KEY_MODE_LONG_ALT)
      {
        key_entry = sys_key_last_entry;
        sys_key_last_entry = 0;
        sys_key_mode = KEY_MODE_NONE;
      }
      else
      {
        sys_key_last_entry = entry;
      }
    }
    else
    {
      /* A new key: take its mode from the masks (bit n = entry n) and start timing. */
      sys_key_last_entry = entry;
      sys_key_mode = (sys_key_repeat_mask >> key_entry) & 1;
      sys_key_mode = ((sys_key_long_only_mask >> key_entry) & 1) ? (KEY_MODE_LONG_ONLY) : (sys_key_mode);
      sys_key_mode = ((sys_key_long_alt_mask >> key_entry) & 1) ? (KEY_MODE_LONG_ALT) : (sys_key_mode);
      sys_key_mode = ((sys_key_blocked_mask >> key_entry) & 1) ? (KEY_MODE_BLOCKED) : (sys_key_mode);
      sys_key_hold_ticks = timer_api_get_ticks16();
      if (sys_key_mode == KEY_MODE_REPEAT)
      {
        sys_key_wait_time = sys_key_repeat_delay;
      }
      else
        if (sys_key_mode == KEY_MODE_LONG_ONLY)
      {
        /* Nothing is sent at the press. */
        sys_key_wait_time = sys_key_long_press_time;
        saved_entry = 0;
      }
      else
        if (sys_key_mode == KEY_MODE_LONG_ALT)
      {
        sys_key_wait_time = sys_key_long_press_time;
        saved_entry = 0;
      }
      else
        if (sys_key_mode == KEY_MODE_BLOCKED)
      {
        /* Forgetting the key makes the next scan see it as new again, so it stays without events. */
        sys_key_last_entry = 0;
        key_entry = 0;
        goto done;
      }
      key_entry = saved_entry;
      done:;
    }
  }
  else
    if ((key_entry != 0) && (sys_key_mode == KEY_MODE_LONG_ONLY))
  {
    /* Held past the long-press time: the event goes out once (mode NONE from now on). */
    if (timer_api_ticks_since(sys_key_hold_ticks) > sys_key_wait_time)
    {
      sys_key_mode = KEY_MODE_NONE;
    }
    else
    {
      key_entry = 0;
    }
  }
  else
    if ((key_entry != 0) && (sys_key_mode == KEY_MODE_LONG_ALT))
  {
    /* Held past the long-press time: send the entry whose event is the key's long code, once. */
    if (timer_api_ticks_since(sys_key_hold_ticks) > sys_key_wait_time)
    {
      sys_key_mode = KEY_MODE_NONE;
      for (j = 0; j < KEY_ENTRIES; j++)
        if (sys_key_code_table[j * 2 + KEY_ENTRY_EVENT] == sys_key_long_codes[key_entry])
          break;
      entry = j & 0xf;
      key_entry = entry;
    }
    else
    {
      key_entry = 0;
    }
  }
  else
    if ((key_entry != 0) && (sys_key_mode == KEY_MODE_REPEAT))
  {
    /* Repeat: after the first delay, every repeat interval. */
    if (timer_api_ticks_since(sys_key_hold_ticks) > sys_key_wait_time)
    {
      sys_key_hold_ticks = timer_api_get_ticks16();
      sys_key_wait_time = sys_key_repeat_interval;
    }
    else
    {
      key_entry = 0;
    }
  }
  else
  {
    /* No key, or a key held in mode NONE: nothing to send. */
    sys_key_hold_ticks = timer_api_get_ticks16();
    sys_key_mode = KEY_MODE_NONE;
    key_entry = 0;
  }
  /* 6. Post the event of the entry. */
  event = sys_key_code_table[(key_entry * 2) + KEY_ENTRY_EVENT];
  if ((timer_api_ticks_since(app_state_record.power_on_ticks) < POWER_ON_KEY_HOLD_OFF) && (event == KEY_EVENT_40))
  {
    event = KEY_EVENT_NONE;
  }
  sys_post_app_event(event);
  /* 7. A KEY_EVENT_41 asked for by the state record. */
  if (app_state_record.u0.bits.bit15)
  {
    sys_post_app_event(KEY_EVENT_41);
    app_state_record.u0.bits.bit15 = 0;
  }
}
