/* panel_power_sequencer_task  (FUN_a01413d0)
 *
 * Run the panel power sequencer: switch the supplies and signals in timed steps.
 * Name basis: proven - timed steps with pin writes and prints; called from the main-loop task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01413d0, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - panel_request_power (panel_request_power, the routine just before this one) is defined here as a static copy of its
 *    body, so the compiler builds it into the two calls of PANEL_POWER_ON_LAST and PANEL_POWER_OFF_LAST as the
 *    firmware has them;
 *  - the PANEL_POWER_ON_LAST step reaches the record through the local pointer 'sequencer'; the other steps name
 *    panel_power_state directly.
 */

/* Values of panel_power_state.state, as this task steps through them. */
#define PANEL_POWER_OFF       1     /* panel off */
#define PANEL_POWER_ON_FIRST  2     /* first and last of the four steps that switch the panel on */
#define PANEL_POWER_ON_LAST   5
#define PANEL_POWER_ON        6     /* panel on */
#define PANEL_POWER_OFF_FIRST 7     /* first and last of the three steps that switch the panel off */
#define PANEL_POWER_OFF_LAST  9

/* Bits 20..22 of the row's first word: the link type. Type 2 is the one with the "eDP time out!" text and the
   DisplayPort transmitter requests; types 0 and 1 use the V-by-One routines. */
#define ROW_LINK_TYPE_MASK 0x700000
#define ROW_LINK_TYPE_0    0
#define ROW_LINK_TYPE_1    0x100000
#define ROW_LINK_TYPE_2    0x200000

#define EDP_TIMEOUT_TICKS  3000     /* extra wait after which the eDP time-out is printed */
#define ON_DONE_TICKS      100      /* panel_power_on_done_flag is set this long after the panel is on */

/* The sequencer record (panel_power_state). */
struct panel_power_record
{
  unsigned char state;              /* PANEL_POWER_* */
  unsigned short ticks;             /* time stamp of the last step */
  unsigned short req : 1;           /* a switch-on request arrived while the panel was switching off */
  unsigned short rest : 15;
};
extern struct panel_power_record panel_power_state;

/* The waits of the sequence, held in the panel timing row in use; all in timer ticks. */
struct panel_timing_row
{
  unsigned int flags;               /* +0x00 bits 20..22: ROW_LINK_TYPE_* */
  unsigned char pad[0x34];
  unsigned short on_link_wait;      /* +0x38 supply on -> start the link */
  unsigned short on_enable_wait;    /* +0x3A link started -> enable the OLED controller (panel on) */
  unsigned short off_power_wait;    /* +0x3C link stopped -> supply off */
  unsigned short off_link_wait;     /* +0x3E picture blanked -> stop the link */
  unsigned short on_power_wait;     /* +0x40 last step (also the end of a switch-off) -> supply on */
};
extern struct panel_timing_row panel_active_row;
extern unsigned char panel_power_on_done_flag;
extern unsigned char panel_power_reverse_flag;
extern unsigned int *panel_get_active_row(void);
extern unsigned short timer_ticks_since(unsigned short);
extern unsigned short timer_get_ticks16(void);
extern void panel_power_off(void);
extern void PanelPowerOn(void);
extern void oled_controller_enable(void);
extern void gpio_set_port13_bit6_high(void);
extern void gpio_set_port13_bit6_low(void);
extern void gpio_set_aux_bit0_high(void);
extern void gpio_set_aux_bit0_low(void);
extern void oled_controller_disable(void);
extern unsigned char gpio_is_port13_bit5_high(void);
extern unsigned char panel_is_link_ready(void);
extern unsigned char panel_is_vdd_detected(void);
extern void panel_vx1_write_fixed_setup_alt(void);
extern void panel_vx1_start_transmitter(void);
extern void panel_vx1_write_fixed_setup(void);
extern void irq_empty_handler_copy52(void);
extern void panel_vx1_setup_lanes(void);
extern void irq_empty_handler_copy51(void);
extern void ipc_set_edp_hpd_enable(int);
extern void pq_block_blank_with_color(int, int, int, int);
extern int dbg_printf();

/* Copy of panel_request_power (see its own file): start a switch-on (on = 1) or switch-off (on = 0), or, while the
   opposite sequence runs, leave it to the end of that sequence by setting panel_power_reverse_flag. */
static void panel_request_power(unsigned char on)
{
    panel_power_reverse_flag = 0;
    if ((on == 1 && (unsigned char)(panel_power_state.state - PANEL_POWER_ON_FIRST) <= PANEL_POWER_ON_LAST - PANEL_POWER_ON_FIRST) || (on == 0 && (unsigned char)(panel_power_state.state - PANEL_POWER_OFF_FIRST) <= PANEL_POWER_OFF_LAST - PANEL_POWER_OFF_FIRST))
        return;
    if ((on == 1 && panel_power_state.state == PANEL_POWER_ON) || (on == 0 && panel_power_state.state == PANEL_POWER_OFF))
        return;
    if ((on == 0 && (unsigned char)(panel_power_state.state - PANEL_POWER_ON_FIRST) <= PANEL_POWER_ON_LAST - PANEL_POWER_ON_FIRST) || (on == 1 && (unsigned char)(panel_power_state.state - PANEL_POWER_OFF_FIRST) <= PANEL_POWER_OFF_LAST - PANEL_POWER_OFF_FIRST)) {
        panel_power_reverse_flag = 1;
        if (on == 1)
            panel_power_state.req = 1;
    } else {
        if (on == 1)
            panel_power_state.state = PANEL_POWER_ON_FIRST;
        else
            panel_power_state.state = PANEL_POWER_OFF_FIRST;
    }
}

/*
 * One step of the panel power sequencer. panel_request_power sets the first step of a sequence; this task, called
 * over and over from sys_main_loop_periodic_task, and also by SYSAPI_PanelOnOffControl (while it waits) and
 * ShowLogo, carries it out. Each step waits for its time in the active panel timing row, does its work and moves
 * on.
 *
 * Switching on:
 *   PANEL_POWER_OFF   (1)  start the switch-on when the req bit is set (a switch-on request made during a
 *                          switch-off).
 *   step 2                 after on_power_wait: panel supply on (PanelPowerOn).
 *   step 3                 one tick later: for link type 2 ask the input processor for the DisplayPort mode change.
 *   step 4                 after on_link_wait: start the link (V-by-One lanes for type 1, the V-by-One transmitter
 *                          for type 0; type 2 only prints a time-out when the wait was 3000 ticks too long).
 *   step 5                 port 13 pin 6 high once the link is ready; after on_enable_wait: OLED controller on,
 *                          state PANEL_POWER_ON, then run a switch-off request that came in meanwhile, or call
 *                          gpio_set_aux_bit0_high (GPIO port number 0xFF, so no pin changes).
 *   PANEL_POWER_ON    (6)  after 100 more ticks set panel_power_on_done_flag.
 * Switching off:
 *   step 7                 gpio_set_aux_bit0_low (no pin change), OLED controller off. With the panel power pin (port 13 pin 5)
 *                          already low the panel is off at once; otherwise, once the link no longer reports ready,
 *                          port 13 pin 6 low and the picture blanked.
 *   step 8                 after off_link_wait: stop the link (fixed set-up values for types 0 and 1, the
 *                          DisplayPort mode change request for type 2).
 *   step 9                 after off_power_wait: panel supply off, state PANEL_POWER_OFF, then run a switch-on
 *                          request that came in meanwhile.
 *
 * The hooks irq_empty_handler_copy51/52 are empty routines in this firmware.
 */
void panel_power_sequencer_task(void)
{
  unsigned int *row = panel_get_active_row();
  switch (panel_power_state.state)
  {
    case PANEL_POWER_OFF:
      if (panel_power_state.req)
      {
        panel_power_state.state = PANEL_POWER_ON_FIRST;
      }
      break;

    case PANEL_POWER_ON_FIRST:
      /* Switch-on, step 1: the supply. */
      panel_power_on_done_flag = 0;
      if (timer_ticks_since(panel_power_state.ticks) > panel_active_row.on_power_wait)
      {
        PanelPowerOn();
        panel_power_state.req = 0;
        panel_power_state.ticks = timer_get_ticks16();
        panel_power_state.state = 3;
      }
      break;

    case 3:
      /* Switch-on, step 2. */
      if (timer_ticks_since(panel_power_state.ticks) != 0)
      {
        if (((*row) & ROW_LINK_TYPE_MASK) == ROW_LINK_TYPE_2)
        {
          ipc_set_edp_hpd_enable(1);
        }
        panel_power_state.ticks = timer_get_ticks16();
        panel_power_state.state = 4;
      }
      break;

    case 4:
      /* Switch-on, step 3: start the link. */
      if (timer_ticks_since(panel_power_state.ticks) > panel_active_row.on_link_wait)
      {
        if (((*row) & ROW_LINK_TYPE_MASK) == ROW_LINK_TYPE_1)
        {
          panel_vx1_setup_lanes();
          irq_empty_handler_copy51();
        }
        else if (((*row) & ROW_LINK_TYPE_MASK) == ROW_LINK_TYPE_0)
        {
          panel_vx1_start_transmitter();
        }
        else if (((*row) & ROW_LINK_TYPE_MASK) == ROW_LINK_TYPE_2)
        {
          /* Only a print; the step goes on either way. */
          if (timer_ticks_since(panel_power_state.ticks) > (panel_active_row.on_link_wait + EDP_TIMEOUT_TICKS))
          {
            dbg_printf("eDP time out!\r\n");
          }
        }
        panel_power_state.ticks = timer_get_ticks16();
        panel_power_state.state = PANEL_POWER_ON_LAST;
      }
      break;

    case PANEL_POWER_ON_LAST:
    {
      /* Switch-on, step 4: the OLED controller. */
      struct panel_power_record *sequencer;
      if (panel_is_link_ready() == 1)
      {
        gpio_set_port13_bit6_high();
      }
      sequencer = &panel_power_state;
      if (timer_ticks_since(sequencer->ticks) > panel_active_row.on_enable_wait)
      {
        sequencer->state = PANEL_POWER_ON;
        oled_controller_enable();
        sequencer->ticks = timer_get_ticks16();
        if (panel_is_vdd_detected() != 1)
        {
          dbg_printf("\033[1;35mVDD DET not high\r\n\033[m");
        }
        /* A switch-off request came during the switch-on: start it now. */
        if (panel_power_reverse_flag == 1)
        {
          panel_request_power(0);
        }
        else
        {
          gpio_set_aux_bit0_high();
        }
      }
      break;
    }

    case PANEL_POWER_ON:
      if ((panel_power_on_done_flag == 0) && (timer_ticks_since(panel_power_state.ticks) > ON_DONE_TICKS))
      {
        panel_power_on_done_flag = 1;
      }
      break;

    case PANEL_POWER_OFF_FIRST:
      /* Switch-off, step 1: controller off; wait until the link is down, then blank the picture. */
      panel_power_on_done_flag = 0;
      gpio_set_aux_bit0_low();
      oled_controller_disable();
      if (gpio_is_port13_bit5_high() == 1)
      {
        if (panel_is_link_ready() == 0)
        {
          gpio_set_port13_bit6_low();
          pq_block_blank_with_color(0, 0, 0, 0);
          panel_power_state.state = 8;
          panel_power_state.ticks = timer_get_ticks16();
        }
      }
      else
        /* The panel power pin is already low: nothing more to switch off. */
        panel_power_state.state = PANEL_POWER_OFF;
      break;

    case 8:
      /* Switch-off, step 2: stop the link. */
      if (timer_ticks_since(panel_power_state.ticks) > panel_active_row.off_link_wait)
      {
        if (((*row) & ROW_LINK_TYPE_MASK) == ROW_LINK_TYPE_0)
        {
          panel_vx1_write_fixed_setup_alt();
        }
        if (((*row) & ROW_LINK_TYPE_MASK) == ROW_LINK_TYPE_1)
        {
          panel_vx1_write_fixed_setup();
          irq_empty_handler_copy52();
        }
        if (((*row) & ROW_LINK_TYPE_MASK) == ROW_LINK_TYPE_2)
        {
          ipc_set_edp_hpd_enable(0);
        }
        panel_power_state.state = PANEL_POWER_OFF_LAST;
        panel_power_state.ticks = timer_get_ticks16();
      }
      break;

    case PANEL_POWER_OFF_LAST:
      /* Switch-off, step 3: the supply. */
      if (timer_ticks_since(panel_power_state.ticks) > panel_active_row.off_power_wait)
      {
        panel_power_off();
        panel_power_state.state = PANEL_POWER_OFF;
        /* A switch-on request came during the switch-off: start it now. */
        if (panel_power_reverse_flag == 1)
        {
          panel_request_power(1);
        }
        panel_power_state.ticks = timer_get_ticks16();
      }
      break;

  }

}
