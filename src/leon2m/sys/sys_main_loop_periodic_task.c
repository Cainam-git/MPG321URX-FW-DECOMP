/* sys_main_loop_periodic_task  (FUN_a0153018)
 *
 * Run one pass of the main program's periodic work: input and picture tasks, counters, alive signal.
 * Note: Runs on every main-loop pass; the menu-layer report waits for over 200 ticks, the usage counters for
 *   port timer 0, the level step for a waiting channel.
 * Name basis: proven - prints 'ELS Timer H = %d' and 'OFFS H = %d'; called from main; ends in the alive signal
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0153018 @ 0xa0153018..0xa015373c (457 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on (they change register names only, in the last 88 words):
 *  - sys_refresh_status_and_signal_alive is declared int-returning (its real type: it returns 0). The
 *    value-returning tail call makes the compiler hand the first call-saved register to the first loop's i and
 *    the next one to any_waiting, as in the firmware. Declared void, the registers differ. Writing this routine
 *    as 'int ... { ... return sys_refresh_status_and_signal_alive(); }' gives the same code; void is kept because
 *    the main loop ignores the result.
 *  - The control-pin test is written '!input_is_port_control_pin_active (bus_id)' with the port-timer arm first,
 *    so the register renaming pass meets that arm first and the input_power_on_ports_by_mask arm then gets the
 *    register the firmware uses for i * 2.
 *  - In case PORT_MASK_ENTRY0 the bus_id load comes before the state_bit line (the firmware takes the bus_id
 *    load in the annulled delay slot of the branch).
 *  - bus_id is set to PORT_NONE once, before the cpu_state read (the firmware does it in the delay slot of that
 *    call), not per table entry.
 */

/* The device settings record (0x50 bytes; nvram_write_settings_record writes it back to the EEPROM). Only the
 * usage counters this routine steps are named, after the device settings that return them
 * (nvram_get_device_setting): on-time minutes and hours 6 / 7, EL count 10, OFFS count 11, EL hours 12,
 * OFFS hours 13. The firmware prints el_hours as 'ELS Timer H' and offs_hours as 'OFFS H'. */
struct device_settings_record
{
  unsigned char bytes_0x00[8];
  unsigned char on_time_minutes;                /* +0x08 */
  unsigned short on_time_hours;                 /* +0x09 */
  unsigned char bytes_0x0b[4];
  unsigned char el_count;                       /* +0x0F */
  unsigned char offs_count;                     /* +0x10 */
  unsigned short el_hours;                      /* +0x11 */
  unsigned short offs_hours;                    /* +0x13 */
  unsigned char bytes_0x15[0x3b];
} __attribute__ ((packed, aligned (4)));

/* A port entry (0x12 bytes, four of them used here); +0x10 is the bus id, the index into the port table. */
struct port_entry
{
  unsigned char bytes_0x00[0x10];
  unsigned char bus_id;                         /* +0x10 */
  unsigned char byte_0x11;
};

/* A port record (0x2A bytes, one per input port); +0x20 is the refresh rate in tenths of a hertz. */
struct port_record
{
  unsigned char bytes_0x00[0x20];
  unsigned short refresh_rate;                  /* +0x20 */
  unsigned char bytes_0x22[8];
};

/* One entry of sys_port_service_table in ROM. The four entries are {0x04, 4}, {0x08, 5}, {0x10, 6}, {0x20, 7}:
 * the mask bit and the port timer of port entries 0..3, the same pairs input_power_on_ports_by_mask uses. */
struct port_service_entry
{
  unsigned char mask;
  unsigned char timer;
};

#define HOUSEKEEPING_TICKS      200     /* the menu-layer report runs when more ticks than this have passed */
#define LAYER_STATUS_OFF        0       /* value sent when neither menu layer 0 nor 1 is switched on */
#define LAYER_STATUS_ON         (-1)    /* value sent when menu layer 0 or 1 is switched on */

#define CHANNEL_COUNT           4
#define MODE_WAITMODECHANGE     0xc     /* channel state 12 (enum channel_state) */

#define USAGE_TIMER             0       /* port timer that paces the usage counters */
#define USAGE_TIMER_TICKS       20000   /* re-armed with this many ticks on every pass */
#define USAGE_PASSES            3       /* a counter steps on every 3rd pass */
#define COUNT_LAST              59      /* the counts run 0..59; the next step carries into the hours */
#define HOURS_MAX               0xffff  /* the hour counters stop here */

#define DEVICE_SETTING_SENSING_TEST 0x10        /* device setting 16 */
/* With how many counts between saves of the record, by case (see phase 4). */
#define SAVE_EVERY_USAGE_RECORD 3
#define SAVE_EVERY_SENSING_TEST 10
#define SAVE_EVERY_DEFAULT      30

#define PORT_SERVICE_ENTRIES    4
#define PORT_NONE               0xff
/* Mask bits of the port entries: mask bit n + 2 belongs to port entry n. */
#define PORT_MASK_ENTRY0        0x04
#define PORT_MASK_ENTRY1        0x08
#define PORT_MASK_ENTRY2        0x10
#define PORT_MASK_ENTRY3        0x20
#define POWER_ON_ALWAYS         1       /* input_power_on_ports_by_mask: switch on without the cable test */

/* Port number of a channel: bits 12..15 of the channel's status word (word 0 of its channel record). */
#define CHANNEL_STATUS_PORT(status_word) (((status_word) >> 12) & 0xf)

#define SHARED_BYTE_1           1       /* shared byte the 8051 handshake is requested in */
#define HANDSHAKE_REQUEST       0x55
#define SYS_CONFIG_BIT21        0x200000        /* sys_config word 0, bit 21 */
#define LUT_UPLOAD_PASSES       20      /* look-up tables uploaded on every 20th pass */

extern struct device_settings_record device_settings;
extern struct port_entry port_entries[4];
extern struct port_record port_records[16];
extern const struct port_service_entry sys_port_service_table[4];
extern unsigned short sys_housekeeping_ticks;
extern unsigned char sys_oled_time_pass_count, sys_on_time_pass_count, sys_input_cpu_state_last, sys_lut_upload_pass_count;
extern int ldc_menu_layer_status_last;
extern unsigned int channel_records, sys_config;        /* channel_records: status word of channel 0 */
extern void input_refresh_port_entries (void);
extern void input_port_sync_task (void);
extern void input_report_present_ports (void);
extern void input_channel_bring_up_task (void);
extern void GlobalModeHandler (void);
extern void panel_power_sequencer_task (void);
extern unsigned short timer_ticks_since (unsigned short);
extern unsigned short timer_get_ticks16 (void);
extern unsigned char osd_is_enabled (int);
extern void ldc_write_status_word (int);
extern unsigned char sys_get_channel_state (unsigned char);
extern void pq_auto_level_task (int);
extern void nvram_flush_pending_task (void);
extern unsigned short input_port_timers_update (unsigned char);
extern unsigned char gpio_is_port13_bit5_high (void);
extern void input_port_timer_start (int, int);
extern unsigned char oled_power_get_state (void);
extern unsigned char oled_power_get_step (void);
extern void nvram_write_settings_record (struct device_settings_record *, int);
extern int dbg_printf (const char *, ...);
extern unsigned char oled_request_sensing_in_factory_burn_in (void);
extern unsigned short nvram_get_device_setting (int);
extern unsigned char ipc_input_cpu_get_state_low_byte (void);
extern void ipc_set_status_byte_88dd (unsigned char);
extern unsigned char input_is_port_control_pin_active (unsigned char);
extern void input_power_on_ports_by_mask (unsigned char, int);
extern void sys_service_ports_by_mask (unsigned char);
extern void panel_blurfree_periodic_task (unsigned short);
extern unsigned char ipc_read_8051_byte (int);
extern void ipc_handshake_8051_bytes (void);
extern void dbg_ddr_stress_task (void);
extern void pq_read_zone_color_averages (void);
extern int sys_refresh_status_and_signal_alive (void);

/*
 * One pass of the main program's periodic work. The main loop (startup_main) calls it on every pass, after
 * ipc_ack_port_change_bits and before sys_run_app_main_task. No argument, no result. It has no loop of its own
 * that can wait (two loops of four steps); any waiting happens inside the routines it calls.
 *
 * The phases, in order:
 *  1. Run the input and picture tasks: port entries, port sync, present-port report, channel bring-up,
 *     GlobalModeHandler, panel power sequencer.
 *  2. When more than 200 ticks have passed since the last time: send LAYER_STATUS_ON to the dimming processor's
 *     mailbox (ldc_write_status_word) when menu layer 0 or 1 is switched on, else LAYER_STATUS_OFF, but only when
 *     the value differs from the one sent last. This is the same code as ldc_report_menu_layer_change.
 *  3. When any of the four channels is in state MODE_WAITMODECHANGE, run one step of pq_auto_level_task. Then
 *     nvram_flush_pending_task.
 *  4. Usage counters of the device settings record. They run when port timer 0 has run out and GPIO port 13
 *     pin 5 reads high; the timer is then started again with 20000 ticks. Both counters below step only while
 *     the OLED power state machine is in state 0, step 0.
 *     - On-time: on every 3rd pass on_time_minutes steps; at 60 it goes back to 0 and on_time_hours steps
 *       (up to 0xFFFF), and the record is saved.
 *     - EL / OFFS: on every 3rd pass el_count and offs_count step; each one at 60 goes back to 0 and steps its
 *       hours (el_hours, offs_hours, up to 0xFFFF; each step is printed). The record is saved when either count
 *       is a multiple of 3 (stored panel usage record valid), else of 10 (device setting 16 is 1), else of 30.
 *  5. Read the input processor's state byte and pass it on (ipc_set_status_byte_88dd) when it changed. Then,
 *     for port entries 0..3 (sys_port_service_table), state bit n + 2 of that byte against the entry's
 *     control pin:
 *     - pin not at its active level, the entry's port timer has run out and the state bit is clear:
 *       sys_service_ports_by_mask (it drives the pin to its active level);
 *     - pin at its active level and the state bit set: input_power_on_ports_by_mask (it releases the pin and
 *       starts the entry's port timer).
 *     Entries whose bus id is 0xFF are skipped.
 *  6. panel_blurfree_periodic_task with the refresh rate, in whole hertz, of the port of channel 0.
 *  7. When the 8051 has put HANDSHAKE_REQUEST in shared byte 1, answer it (ipc_handshake_8051_bytes). Then one
 *     step of the memory stress test (dbg_ddr_stress_task).
 *  8. With sys_config bit 21 set and channels 0 and 3 both in state MODE_WAITMODECHANGE: upload the colour
 *     look-up tables on every 20th such pass.
 *  9. Last: sys_refresh_status_and_signal_alive, which ends in the alive signal to the 8051.
 *
 * Ticks are those of timer_get_ticks16.
 */
void sys_main_loop_periodic_task (void)
{
  unsigned char i, any_waiting, cpu_state, state_bit, bus_id;
  int layer_status;

  /* 1. Input and picture tasks. */
  input_refresh_port_entries ();
  input_port_sync_task ();
  input_report_present_ports ();
  input_channel_bring_up_task ();
  GlobalModeHandler ();
  panel_power_sequencer_task ();

  /* 2. Menu-layer status to the dimming processor, at most once per 200 ticks and only on a change. */
  if (timer_ticks_since (sys_housekeeping_ticks) > HOUSEKEEPING_TICKS)
    {
      sys_housekeeping_ticks = timer_get_ticks16 ();
      layer_status = LAYER_STATUS_OFF;
      if (osd_is_enabled (0))
        layer_status = LAYER_STATUS_ON;
      else if (osd_is_enabled (1))
        layer_status = LAYER_STATUS_ON;
      if (layer_status != ldc_menu_layer_status_last)
        ldc_write_status_word (layer_status);
      ldc_menu_layer_status_last = layer_status;
    }

  /* 3. Automatic level step while a channel waits in MODE_WAITMODECHANGE. */
  any_waiting = 0;
  for (i = 0; i < CHANNEL_COUNT; i++)
    if (sys_get_channel_state (i) == MODE_WAITMODECHANGE)
      {
        any_waiting = 1;
        break;
      }
  if (any_waiting)
    pq_auto_level_task (0);
  nvram_flush_pending_task ();

  /* 4. Usage counters, paced by port timer 0. */
  if (input_port_timers_update (USAGE_TIMER) == 0 && gpio_is_port13_bit5_high ())
    {
      input_port_timer_start (USAGE_TIMER, USAGE_TIMER_TICKS);

      /* On-time: minutes, carried into hours; the record is saved when the hours step. */
      if (!oled_power_get_state () && !oled_power_get_step ())
        {
          if (++sys_on_time_pass_count > USAGE_PASSES)
            {
              sys_on_time_pass_count = 1;
              if (++device_settings.on_time_minutes > COUNT_LAST)
                {
                  device_settings.on_time_minutes = 0;
                  if (device_settings.on_time_hours != HOURS_MAX)
                    {
                      device_settings.on_time_hours++;
                      nvram_write_settings_record (&device_settings, 0);
                    }
                }
            }
        }

      /* EL and OFFS counts, each carried into its hours. */
      if (!oled_power_get_state () && !oled_power_get_step ())
        {
          if (++sys_oled_time_pass_count > USAGE_PASSES)
            {
              sys_oled_time_pass_count = 1;
              device_settings.offs_count++;
              if (++device_settings.el_count > COUNT_LAST)
                {
                  device_settings.el_count = 0;
                  if (device_settings.el_hours != HOURS_MAX)
                    {
                      device_settings.el_hours++;
                      dbg_printf ("ELS Timer H = %d\r\n", device_settings.el_hours);
                    }
                }
              if (device_settings.offs_count > COUNT_LAST)
                {
                  device_settings.offs_count = 0;
                  if (device_settings.offs_hours != HOURS_MAX)
                    {
                      device_settings.offs_hours++;
                      dbg_printf ("OFFS H = %d\r\n", device_settings.offs_hours);
                    }
                }
              /* How often the record is saved depends on the stored panel usage record and on device
                 setting 16; a count of 0 always saves. */
              if (oled_request_sensing_in_factory_burn_in ())
                {
                  if (device_settings.el_count % SAVE_EVERY_USAGE_RECORD == 0 || device_settings.offs_count % SAVE_EVERY_USAGE_RECORD == 0)
                    nvram_write_settings_record (&device_settings, 0);
                }
              else if (nvram_get_device_setting (DEVICE_SETTING_SENSING_TEST) == 1)
                {
                  if (device_settings.el_count % SAVE_EVERY_SENSING_TEST == 0 || device_settings.offs_count % SAVE_EVERY_SENSING_TEST == 0)
                    nvram_write_settings_record (&device_settings, 0);
                }
              else if (device_settings.el_count % SAVE_EVERY_DEFAULT == 0 || device_settings.offs_count % SAVE_EVERY_DEFAULT == 0)
                nvram_write_settings_record (&device_settings, 0);
            }
        }
    }

  /* 5. The input processor's state byte: pass it on when it changed, then serve port entries 0..3. */
  bus_id = PORT_NONE;
  cpu_state = ipc_input_cpu_get_state_low_byte ();
  if (sys_input_cpu_state_last != cpu_state)
    {
      sys_input_cpu_state_last = cpu_state;
      ipc_set_status_byte_88dd (cpu_state);
    }
  for (i = 0; i < PORT_SERVICE_ENTRIES; i++)
    {
      /* bus_id is not reset per entry: a mask other than the four below would reuse the previous one. All four
         table entries carry one of these masks. */
      state_bit = 0;
      switch (sys_port_service_table[i].mask)
        {
        case PORT_MASK_ENTRY0:
          bus_id = port_entries[0].bus_id;
          state_bit = (cpu_state >> 2) & 1;
          break;
        case PORT_MASK_ENTRY1:
          state_bit = (cpu_state >> 3) & 1;
          bus_id = port_entries[1].bus_id;
          break;
        case PORT_MASK_ENTRY2:
          state_bit = (cpu_state >> 4) & 1;
          bus_id = port_entries[2].bus_id;
          break;
        case PORT_MASK_ENTRY3:
          state_bit = (cpu_state >> 5) & 1;
          bus_id = port_entries[3].bus_id;
          break;
        }
      if (bus_id != PORT_NONE)
        {
          if (!input_is_port_control_pin_active (bus_id))
            {
              /* Pin not at its active level: drive it once the entry's port timer has run out, unless the state bit
                 is set. */
              if (input_port_timers_update (sys_port_service_table[i].timer) == 0 && !state_bit)
                sys_service_ports_by_mask (sys_port_service_table[i].mask);
            }
          else if (state_bit)
            /* Pin driven and the state bit set: switch the port on (releases the pin, starts its timer). */
            input_power_on_ports_by_mask (sys_port_service_table[i].mask, POWER_ON_ALWAYS);
        }
    }

  /* 6. Blur reduction, with the refresh rate of channel 0's port in whole hertz. */
  panel_blurfree_periodic_task (port_records[CHANNEL_STATUS_PORT (channel_records)].refresh_rate / 10);

  /* 7. Handshake asked for by the 8051, then the memory stress test step. */
  if (ipc_read_8051_byte (SHARED_BYTE_1) == HANDSHAKE_REQUEST)
    ipc_handshake_8051_bytes ();
  dbg_ddr_stress_task ();

  /* 8. Look-up table upload while channels 0 and 3 both wait in MODE_WAITMODECHANGE. */
  if (sys_config & SYS_CONFIG_BIT21)
    if (sys_get_channel_state (0) == MODE_WAITMODECHANGE && sys_get_channel_state (3) == MODE_WAITMODECHANGE)
      {
        if (sys_lut_upload_pass_count % LUT_UPLOAD_PASSES == 0)
          pq_read_zone_color_averages ();
        sys_lut_upload_pass_count++;
      }

  /* 9. Status refresh and the alive signal to the 8051. */
  sys_refresh_status_and_signal_alive ();
}
