/* GlobalModeHandler  (FUN_a0131518)
 *
 * Run the main state machine that decides what each channel shows and when.
 * Name basis: proven - prints GlobalModeHandler state texts (original name); called from the main-loop task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0131518 @ 0xa0131518..0xa0132768 (1172 words). Flags -mcpu=v8 -O3 -g -msoft-float (only
 * -msoft-float gives the firmware's single .LLC constant 0x0fffffff). The static helpers are all inlined.
 * Source forms the exact build depends on:
 *  - every per-channel phase takes its own fresh pointer '= &channel_records[channel]' (rec_timer, rec_wait,
 *    rec_capture, rec_frc, rec in run_state_entry_actions, other in the two scans) besides the loop pointer rec.
 *    The firmware's address operands are '[off + base]' throughout, which is what an access through such a
 *    pointer gives; channel_records[x].field gives base-first. rec_capture is taken before receiver_2_or_3.
 *  - other_channel_above / no_other_channel_above test 'channel == q', claim_path_selector 'q == channel'; the
 *    state test in claim_path_selector is unsigned ('> 5U').
 *  - phase 4 is 'if (a != b || c != d) { state; step } else {...}' (one read-modify-write of the word), and
 *    sys_enable_channel_port is called as 'if (c) f(channel, 1); else f(channel, 0);'.
 *  - identical-arm diamonds 'if (frc_off) { step = 0; frc_off = 0; } else frc_off = 0;' (and the frc_off = 1
 *    twin): the firmware has one read-modify-write store with the and/or in the annulled slot.
 *  - 'unsigned short default_row_lines = panel_default_row_active_lines;' is read once for the print and the compare
 *    (the ROM value stays in a register across the print).
 *  - choose_source_action writes b1_channel through an 'unsigned char *' (b1_channel lives in a stack slot);
 *    'if (entry == 0xff) return 0;' sits inside it; the port class test comes first, with the '?:' form;
 *    '*b1_channel = 0;' comes after 'action = sys_source_b1_block != 0;'.
 *  - in phase 6 the clock_out_of_range block stores the flag word first; 'clock_out_of_range = 0;' comes before
 *    'rec_frc = ...'.
 * Further source forms (no behaviour change):
 *  - phase 1 tests 'link type != 2' first, so the print arm comes first in the source.
 *  - run_state_entry_actions re-tests the state in separate ifs ('if (st == A) f(); if (st == A && ...) g();'),
 *    not nested.
 *  - input_port_get_status_bit10 / _bit7 are declared returning unsigned char here.
 *  - phase 8: 'int k = i;', and input_get_port_status_bit's result cast to unsigned char at the test; the test call
 *    and input_is_receiver_index_2_or_3 take k, the other calls take i.
 *  - claim_path_selector's 'if (q < channel) return;' stands for a jump out of the loop (a goto is predicted
 *    differently).
 *  - SOURCE_KEEP block: 'if (block != 0xff) if (signal code != 0xb1) {...}'.
 */
/* Channel states (bits 28..31 of a channel record's first word). The MODE_ names are the firmware's own texts. */
enum channel_state {
    CH_STATE_WAIT_SYNC = 5,             /* wait for the port's sync to be stable */
    MODE_MODESEARCH = 6,
    MODE_CAPTURE = 7,
    MODE_DISPLAY = 8,
    MODE_WAIT2SHOW = 9,
    MODE_WAITPANELREADY = 10,
    MODE_WAITPANELREADY_2ND = 11,
    MODE_WAITMODECHANGE = 12
};

/* Fields of a channel record's first word, as masks of the whole word. */
#define CH_STATE_FIELD      0xf0000000
#define CH_STEP_FIELD       0x00f00000
#define STATE_WORD(st)      ((unsigned int)(st) << 28)
#define STEP_WORD(n)        ((unsigned int)(n) << 20)
#define IN_STATE(word, st)  (((word) & CH_STATE_FIELD) == STATE_WORD(st))
#define IN_STEP(word, n)    (((word) & CH_STEP_FIELD) == STEP_WORD(n))

/* Bits of a channel record's flag word (+0x70). */
#define CH_FLAG_FRC_BACK_CHECK 0x80000      /* bit 19: set when the FRC Back Check finds the pixel clock outside
                                               the panel row's range; cleared when the channel enters MODE_DISPLAY */
#define CH_FLAG_PANEL_READY    0x4000000    /* bit 26 */
#define CH_FLAG_SHOW_TIMER_DONE 0x8000000   /* bit 27 */
#define CH_FLAG_PATH_OWNER     0x80000000   /* bit 31: this channel holds the path selector */

/* Bits of word 0 of the system configuration record. */
#define SYS_CONFIG_CHANNEL3_BIT   0x200000  /* bit 21: channel 3 is left out of other_channel_above */
#define SYS_CONFIG_FRC_LOCK_MODE  0x8000000 /* bit 27 */
#define SYS_CONFIG_BYTE_3         0xff      /* byte +3 (sys_config_byte_3) = bits 0..7 of word 0 */
#define SYS_CONFIG_CONVERTER_MODE 0xf0000000 /* bits 28..31 of word +4 */

/* Link type of the active panel timing row (bits 20..22 of its first word). */
#define ROW_LINK_TYPE_MASK  0x700000
#define ROW_LINK_TYPE_2     0x200000

#define DEVICE_SETTINGS_PIP_MODE 7          /* byte +7 of the device settings: picture-in-picture mode (0 = one picture) */
#define PIP_MODE_2               2

/* Port record status bits. */
#define PORT_STATUS_BIT4    0x10
#define PORT_STATUS_BIT7    0x80

#define PORT_CLASS_5        5               /* port class (bits 12..15 of the port entry) given special handling */
#define PORT_CODE_ROUTED    0xb1            /* source code given to an input block that takes channel 0's source */
#define ENTRY_NONE          0xff            /* no port entry */
#define BLOCK_NONE          0xff            /* sys_source_b1_block: no block has the 0xB1 source */
#define PORT_ENTRY_COUNT    7
#define LAST_CHANNEL_WITH_PATH 1            /* channels 2 and 3 never take the path selector */

#define PANEL_POWER_REQUEST_ON  1
#define CHANNEL_PORT_ON     1
#define CHANNEL_PORT_OFF    0

/* What choose_source_action asks for. */
#define SOURCE_KEEP         0               /* nothing to change */
#define SOURCE_TAKE         1               /* give block 0 the 0xB1 source */
#define SOURCE_RELEASE_TAKE 2               /* both (handled, but choose_source_action never returns it) */
#define SOURCE_RELEASE      3               /* give the 0xB1 block its own source back */

/* First word of a channel record. */
struct channel_word_bits {
    unsigned int state:4;               /* bits 28..31: enum channel_state */
    unsigned int prev_state:4;          /* bits 24..27: the state at the end of the last pass of this routine */
    unsigned int step:4;                /* bits 20..23: step inside the state */
    unsigned int bits_16_19:4;
    unsigned int port:4;                /* bits 12..15: the port shown */
    unsigned int bits_1_11:11;
    unsigned int frc_off:1;             /* bit 0: set where "FRC OFF" is printed, cleared where "FRC ON" is */
};

/* One channel record (0x78 bytes), the fields used here. */
struct channel_record {
    union { unsigned int word; struct channel_word_bits f; } head;       /* +0x00 */
    unsigned int step_ticks;
    unsigned short refresh_rate;                                          /* +0x08: tenths of a hertz */
    unsigned char p0a[0x12 - 0x0a];
    unsigned short timing_width, timing_height;                           /* +0x12, +0x14 */
    unsigned char p16[0x54 - 0x16];
    unsigned short lines_part;                                            /* +0x54: output timing +0xC */
    unsigned char p56[0x60 - 0x56];
    unsigned long long pixel_clock;                                       /* +0x60: output timing +0x18 */
    unsigned char p68[0x70 - 0x68];
    unsigned int flags;                                                   /* +0x70: CH_FLAG_* */
    unsigned int display_delay;
};

/* The system configuration record (stSysConfig), the fields used here. */
struct sys_config_record {
    union { unsigned int w; unsigned char b[4]; } word0;
    unsigned int word_0x04;
    unsigned char p08[0x2e - 0x08];
    unsigned char byte_0x2e;            /* 0: follow the panel power for channel 0 only; 1: for every channel */
    unsigned char byte_0x2f;            /* 0: state entry actions for channel 0 only; 1: for every channel */
    unsigned char p30[0x34 - 0x30];
    unsigned char delay_to_show;        /* bits 4..7: one bit per channel; bits 0..3: 0 = no wait, 1 = the
                                           channel's bit is cleared after one wait */
    unsigned char p35;
    unsigned short delay_to_show_ticks; /* +0x36: how long MODE_WAIT2SHOW waits */
};

/* The active panel timing row: its two clock values (printed as 'clk' when the row is set). */
struct panel_timing_row { unsigned char p00[0x10]; unsigned long long clk_min, clk_max; };

/* One port record (0x2A bytes), the fields used here. */
struct port_record { unsigned short status; unsigned char p02[0x0a - 0x02]; unsigned char port_code; unsigned char p0b[0x2a - 0x0b]; };

/* First halfword of a port entry. */
struct port_entry_bits {
    unsigned short port_class:4;        /* bits 12..15 */
    unsigned short bit11:1;             /* the port's bit of port_present_mask at the last pass */
    unsigned short bits_6_10:5;
    unsigned short bit5:1;
    unsigned short bit4:1;
    unsigned short bits_0_3:4;
};
struct port_entry { union { unsigned short class_and_flags; struct port_entry_bits f; } head; unsigned char p02[0x12 - 0x02]; };

extern struct channel_record channel_records[4];
extern struct sys_config_record sys_config;
extern struct panel_timing_row panel_active_row;
extern struct port_record port_records[];
extern struct port_entry port_entries[];
extern unsigned short sys_wait2show_start_ticks[];
extern unsigned char sys_source_b1_block, sys_mode_handler_port;
extern unsigned char device_settings[];
extern unsigned short panel_default_row_active_lines;

extern int dbg_printf(const char *fmt, ...);
extern unsigned int *panel_get_active_row(void);
extern unsigned char panel_is_power_on_done(void);
extern unsigned char panel_is_power_off(void);
extern void panel_request_power(int);
extern unsigned char gpio_is_aux_bit0_high(void);
extern void gpio_set_aux_bit0_high(void);
extern void sys_poll_events_stub_copy22(unsigned char);
extern void SysTasksBeforeDisplay_byChannel(unsigned char);
extern void sys_mode_apply_converter_setup(void);
extern void sys_mode_reset_vx1_if_link_type_1(void);
extern void sys_mode_enter_state_c(unsigned char);
extern void sys_mode_notify_channel0_port(void);
extern void sys_mode_restart_channel(unsigned char);
extern void sys_mode_set_pwm7_and_continue(void);
extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short);
extern unsigned char input_port_get_status_bit10(unsigned int);
extern unsigned char input_port_get_status_bit7(unsigned int);
extern unsigned char input_get_port_mask_bit(unsigned char);
extern unsigned char input_get_port_mask_bit_alt(unsigned char);
extern void sys_enable_channel_port(unsigned char, unsigned char);
extern unsigned char input_port_id_to_entry_index(unsigned char);
extern unsigned char input_is_receiver_index_2_or_3(unsigned char);
extern unsigned char input_block_get_status_bit2(unsigned char);
extern unsigned char input_is_timing_supported(unsigned short, unsigned short, unsigned short);
extern void pq_block_blank(unsigned char);
extern void sys_set_path_selector(unsigned char);
extern int input_get_port_status_bit(unsigned char);
extern int input_is_receiver_index_0_or_1(unsigned int);
extern void ipc_restart_hdmi_port(unsigned char);
extern void ipc_load_dp_rx_clock_registers(unsigned char);
extern void sys_channels_idle_task(void);
extern void input_select_block_source(unsigned char, unsigned char);
extern void input_load_block_source_registers(unsigned char, unsigned char);
extern unsigned char input_block_get_signal_code(unsigned char);
extern unsigned char pq_block_is_blanked(unsigned char);
extern void input_setup_route_for_source(unsigned char, unsigned char);
extern void ipc_send_dsc_dec_command(unsigned char);

/* Return 1 when a channel other than `channel` is in a state above `state`. Channels 1..3 count only when
   byte_0x2f of the system configuration is not 0, and channel 3 not when SYS_CONFIG_CHANNEL3_BIT is set. */
static unsigned char other_channel_above(unsigned char channel, unsigned int state)
{
    unsigned char q;
    struct channel_record *other;
    for (q = 0; q < 4; q++) {
        if (channel == q) continue;
        if (q != 0 && sys_config.byte_0x2f == 0) continue;
        if (q == 3 && (sys_config.word0.w & SYS_CONFIG_CHANNEL3_BIT)) continue;
        other = &channel_records[q];
        if ((other->head.word >> 28) > state) return 1;
    }
    return 0;
}

/* Return 1 when no channel other than `channel` is in a state above `state`. */
static unsigned char no_other_channel_above(unsigned char channel, unsigned int state)
{
    unsigned char q;
    struct channel_record *other;
    for (q = 0; q < 4; q++) {
        if (channel == q) continue;
        other = &channel_records[q];
        if ((other->head.word >> 28) > state) return 0;
    }
    return 1;
}

/* Run the entry actions of the state `channel` has just entered (nothing when it is still in `prev_state`). */
static void run_state_entry_actions(unsigned char channel, unsigned char prev_state)
{
    struct channel_record *rec = &channel_records[channel];

    if (channel == 0xff) return;
    if (prev_state == rec->head.f.state) return;
    if (prev_state == CH_STATE_WAIT_SYNC && IN_STATE(channel_records[channel].head.word, MODE_MODESEARCH)) sys_poll_events_stub_copy22(channel);
    if (IN_STATE(rec->head.word, MODE_WAITPANELREADY)) SysTasksBeforeDisplay_byChannel(channel);
    /* The converter set-up and the format step run only when no other channel is already past MODE_WAIT2SHOW. */
    if (IN_STATE(rec->head.word, MODE_WAITPANELREADY) && !other_channel_above(channel, MODE_WAIT2SHOW)) sys_mode_apply_converter_setup();
    if (IN_STATE(rec->head.word, MODE_WAITPANELREADY_2ND) && !other_channel_above(channel, MODE_WAIT2SHOW)) sys_mode_reset_vx1_if_link_type_1();
    if (IN_STATE(rec->head.word, MODE_WAITMODECHANGE)) sys_mode_enter_state_c(channel);
    if (IN_STATE(rec->head.word, MODE_WAITMODECHANGE) && !other_channel_above(channel, MODE_WAITPANELREADY_2ND)) sys_mode_notify_channel0_port();
    if (IN_STATE(rec->head.word, CH_STATE_WAIT_SYNC)) sys_mode_restart_channel(channel);
    if (IN_STATE(rec->head.word, CH_STATE_WAIT_SYNC) && no_other_channel_above(channel, CH_STATE_WAIT_SYNC)) sys_mode_set_pwm7_and_continue();
}

/*
 * Decide what to do with the 0xB1 source, from channel 0's port entry `entry`. When block 0 is to take it,
 * *b1_channel is set to 0.
 *   - no port entry: SOURCE_KEEP;
 *   - a port of another class than 5: SOURCE_RELEASE when a block has the 0xB1 source, else SOURCE_KEEP;
 *   - a class 5 port: SOURCE_RELEASE when a block has the 0xB1 source and the entry is not the one taken last;
 *     otherwise, when bit 5 of the entry is set, the entry is taken (sys_mode_handler_port) and the answer is
 *     SOURCE_TAKE unless block 0 already has the source.
 */
static unsigned int choose_source_action(unsigned char entry, unsigned char *b1_channel)
{
    unsigned int action = SOURCE_KEEP;
    if (entry == ENTRY_NONE) return 0;
    if (port_entries[entry].head.f.port_class != PORT_CLASS_5) {
        action = (sys_source_b1_block != BLOCK_NONE) ? SOURCE_RELEASE : SOURCE_KEEP;
    } else {
        if (sys_mode_handler_port != entry && sys_source_b1_block != BLOCK_NONE) {
            action = SOURCE_RELEASE;
        } else {
            if (port_entries[entry].head.f.bit5) {
                sys_mode_handler_port = entry;
                action = sys_source_b1_block != 0;
                *b1_channel = 0;
            }
        }
    }
    return action;
}

/*
 * Give the path selector to `channel` (rec = its record). When another channel holds it: a lower channel keeps
 * it and nothing changes; a higher channel loses it, and if it is past CH_STATE_WAIT_SYNC it is sent back to
 * MODE_MODESEARCH with its picture block blanked.
 */
static void claim_path_selector(unsigned char channel, struct channel_record *rec)
{
    unsigned char q;
    for (q = 0; q < 4; q++) {
        if (q == channel) continue;
        if (channel_records[q].flags & CH_FLAG_PATH_OWNER) {
            if (q < channel) return;
            channel_records[q].flags &= ~CH_FLAG_PATH_OWNER;
            if (channel_records[q].head.f.state > (unsigned int)CH_STATE_WAIT_SYNC) {
                channel_records[q].head.f.state = MODE_MODESEARCH;
                channel_records[q].head.f.step = 0;
                pq_block_blank(channel_records[q].head.f.port);
            }
            break;
        }
    }
    rec->flags |= CH_FLAG_PATH_OWNER;
    sys_set_path_selector(channel_records[channel].head.f.port);
}

/*
 * One pass of the mode handler over the four channels, then over the seven port entries, then the choice of the
 * 0xB1 source. No arguments; it works on channel_records, port_records, port_entries and sys_config.
 * Called from the main-loop task.
 *
 * Each channel record keeps its state from the last pass in prev_state; "entering" a state below means the state
 * differs from prev_state. The states themselves are stepped by input_channel_bring_up_task.
 *
 * Phases, in order:
 *   0. A scan of the channels for one above MODE_DISPLAY; its result is not used.
 *   For each channel 0..3:
 *   1. Panel power (channel 0 only, or every channel when sys_config byte_0x2e is 1; other channels get
 *      CH_FLAG_PANEL_READY set):
 *        - entering MODE_WAITPANELREADY: ask for the panel to be switched on. With a row of link type 2 only
 *          while the power-on has not finished; otherwise always, with the print "Tigger to display";
 *        - in MODE_WAITPANELREADY_2ND with the panel off: back to MODE_WAIT2SHOW;
 *        - CH_FLAG_PANEL_READY follows panel_is_power_on_done;
 *        - entering MODE_WAITMODECHANGE with the panel on: gpio_set_aux_bit0_high (GPIO port number 0xFF, which
 *          gpio_write_pin does not serve, so no pin changes).
 *   2. State entry actions (channel 0 only, or every channel when byte_0x2f is 1): run_state_entry_actions.
 *   3. MODE_WAIT2SHOW timer: on entry, when the channel's bit (4 + channel) of delay_to_show is set and its
 *      low nibble is not 0, take a time stamp and clear CH_FLAG_SHOW_TIMER_DONE; otherwise set it at once.
 *      While the channel stays there, CH_FLAG_SHOW_TIMER_DONE is set once delay_to_show_ticks have passed; a low
 *      nibble of 1 clears the channel's bit, so the wait happens once.
 *   4. MODE_WAIT2SHOW port check: when status bits 10 and 7 of the port record differ from the port's bits in
 *      the two port masks, back to MODE_MODESEARCH step 0. Otherwise the channel's port is switched on when
 *      either mask bit or status bit 4 is set, else off.
 *   5. Path selector: on entering MODE_CAPTURE at step 0, channel 0 or 1 claims the path selector when its input
 *      block reports status bit 2, its port entry is not receiver 2 or 3, and its timing is in the table of
 *      supported timings.
 *   6. FRC decision, channel 0 only (the others get frc_off cleared):
 *        - entering MODE_DISPLAY clears CH_FLAG_FRC_BACK_CHECK;
 *        - status bit 7 of the port record: frc_off cleared;
 *        - MODE_DISPLAY step 1: "FRC OFF" (frc_off set) in picture-in-picture modes 0 and 2 when lines_part is
 *          at least the default panel row's halfword +0xA, the converter mode (sys_config word +4 bits 28..31)
 *          is 0, FRC lock mode is off and sys_config byte 3 is 0; otherwise "FRC ON" (frc_off cleared). When
 *          frc_off changes, the channel goes back to step 0 of its state;
 *        - MODE_DISPLAY step 5 with frc_off set: "FRC Back Check" when the channel's pixel clock lies outside
 *          clk_min..clk_max of the active panel row: CH_FLAG_FRC_BACK_CHECK set, frc_off cleared, step 0.
 *   7. prev_state = state.
 *   After the channels:
 *   8. Port presence: for each port entry whose bit 11 (its port_present_mask bit at the last pass) is set while
 *      the port is not present now, restart the port on the input processor (entries 0 and 1: HDMI port restart;
 *      entries 2 and 3: DisplayPort receiver clock registers). Then bit 11 takes the present bit.
 *   9. sys_channels_idle_task.
 *  10. The 0xB1 source (choose_source_action on channel 0's port entry):
 *        - SOURCE_RELEASE: the block that had it gets the source of its own channel's port back, and so does
 *          the block of each of channels 1..3 (numbered by the channel's port) that has signal code 0xB1 (blanked
 *          first when it is not blanked);
 *        - SOURCE_TAKE: block 0 gets the routing of channel 0's port, the 0xB1 source, and the input processor
 *          gets channel 0's port code (ipc_send_dsc_dec_command);
 *        - SOURCE_KEEP: the block that has it gets the 0xB1 source again when its signal code is not 0xB1;
 *        - then, while a block has it and channel 0's block has signal code 0xB1: the block of each of channels
 *          1..3 whose signal code is not 0xB1 but equals the port code of the 0xB1 block's channel also gets
 *          the 0xB1 source.
 */
void GlobalModeHandler(void)
{
    struct channel_record *rec, *rec_frc, *rec_timer, *rec_capture, *rec_wait;
    unsigned char channel, i, receiver_2_or_3, entry, port_code, prev_state, clock_out_of_range;
    unsigned char b1_channel;
    unsigned int source_action;

    /* Phase 0. */
    for (i = 0; i < 4; i++) {
        rec = &channel_records[i];
        if ((rec->head.word >> 28) > MODE_DISPLAY) break;
    }

    for (channel = 0; channel < 4; channel++) {
        rec = &channel_records[channel];

        /* Phase 1: panel power. */
        if ((sys_config.byte_0x2e == 0 && channel == 0) || sys_config.byte_0x2e == 1) {
            prev_state = rec->head.f.prev_state;
            if ((*panel_get_active_row() & ROW_LINK_TYPE_MASK) != ROW_LINK_TYPE_2) {
                if (prev_state != rec->head.f.state && IN_STATE(channel_records[channel].head.word, MODE_WAITPANELREADY)) {
                    panel_request_power(PANEL_POWER_REQUEST_ON);
                    dbg_printf(">>>>>>GlobalModeHandler : Tigger to display\r\n");
                }
            } else if (prev_state != rec->head.f.state && IN_STATE(channel_records[channel].head.word, MODE_WAITPANELREADY) && !panel_is_power_on_done()) panel_request_power(PANEL_POWER_REQUEST_ON);
            if (IN_STATE(rec->head.word, MODE_WAITPANELREADY_2ND) && panel_is_power_off()) rec->head.f.state = MODE_WAIT2SHOW;
            if (panel_is_power_on_done() == 1) rec->flags |= CH_FLAG_PANEL_READY; else rec->flags &= ~CH_FLAG_PANEL_READY;
            if (prev_state != rec->head.f.state && IN_STATE(rec->head.word, MODE_WAITMODECHANGE) && panel_is_power_on_done() == 1 && !gpio_is_aux_bit0_high()) gpio_set_aux_bit0_high();
        } else {
            rec->flags |= CH_FLAG_PANEL_READY;
        }

        /* Phase 2: state entry actions. */
        if ((sys_config.byte_0x2f == 0 && channel == 0) || sys_config.byte_0x2f == 1)
            run_state_entry_actions(channel, rec->head.f.prev_state);

        /* Phase 3: MODE_WAIT2SHOW timer. */
        rec_timer = &channel_records[channel];
        if (rec->head.f.prev_state != rec_timer->head.f.state) {
            if (IN_STATE(rec_timer->head.word, MODE_WAIT2SHOW)) {
                if (((sys_config.delay_to_show >> (channel + 4)) & 1) && (sys_config.delay_to_show & 0xf)) {
                    sys_wait2show_start_ticks[channel] = timer_get_ticks16();
                    rec_timer->flags &= ~CH_FLAG_SHOW_TIMER_DONE;
                    dbg_printf("timer...\r\n");
                } else {
                    rec_timer->flags |= CH_FLAG_SHOW_TIMER_DONE;
                }
            }
        } else if (IN_STATE(rec_timer->head.word, MODE_WAIT2SHOW) && sys_config.delay_to_show != 0 && timer_ticks_since(sys_wait2show_start_ticks[channel]) > sys_config.delay_to_show_ticks) {
            if ((sys_config.delay_to_show & 0xf) == 1) sys_config.delay_to_show &= ~(1 << (channel + 4));
            rec_timer->flags |= CH_FLAG_SHOW_TIMER_DONE;
        }

        /* Phase 4: MODE_WAIT2SHOW port check. */
        rec_wait = &channel_records[channel];
        if (IN_STATE(rec_wait->head.word, MODE_WAIT2SHOW)) {
            if (input_port_get_status_bit10(rec_wait->head.f.port) != input_get_port_mask_bit(rec_wait->head.f.port)
                || input_port_get_status_bit7(rec_wait->head.f.port) != input_get_port_mask_bit_alt(rec_wait->head.f.port)) {
                rec_wait->head.f.state = MODE_MODESEARCH;
                rec_wait->head.f.step = 0;
            } else {
                if (input_get_port_mask_bit(rec_wait->head.f.port) || input_get_port_mask_bit_alt(rec_wait->head.f.port) || (port_records[rec_wait->head.f.port].status & PORT_STATUS_BIT4)) sys_enable_channel_port(channel, CHANNEL_PORT_ON); else sys_enable_channel_port(channel, CHANNEL_PORT_OFF);
            }
        }

        /* Phase 5: path selector, on entering MODE_CAPTURE. */
        prev_state = rec->head.f.prev_state;
        rec_capture = &channel_records[channel];
        receiver_2_or_3 = input_is_receiver_index_2_or_3(input_port_id_to_entry_index(port_records[rec_capture->head.f.port].port_code));
        if (prev_state != rec_capture->head.f.state && IN_STATE(rec_capture->head.word, MODE_CAPTURE) && IN_STEP(rec_capture->head.word, 0) && input_block_get_status_bit2(rec_capture->head.f.port) == 1 && receiver_2_or_3 == 0
            && input_is_timing_supported(rec_capture->timing_width, rec_capture->timing_height, rec_capture->refresh_rate) == 1 && channel != 2) if (channel != 3) claim_path_selector(channel, rec_capture);

        /* Phase 6: FRC decision. */
        prev_state = rec->head.f.prev_state;
        clock_out_of_range = 0;
        rec_frc = &channel_records[channel];
        if (channel != 0) {
            rec_frc->head.f.frc_off = 0;
        } else {
            if (prev_state != rec_frc->head.f.state && IN_STATE(rec_frc->head.word, MODE_DISPLAY)) rec_frc->flags &= ~CH_FLAG_FRC_BACK_CHECK;
            if (port_records[rec_frc->head.f.port].status & PORT_STATUS_BIT7) {
                rec_frc->head.f.frc_off = 0;
            } else if (IN_STATE(rec_frc->head.word, MODE_DISPLAY) && !(rec_frc->flags & CH_FLAG_FRC_BACK_CHECK)) {
                if (IN_STEP(rec_frc->head.word, 1)) {
                    unsigned short default_row_lines = panel_default_row_active_lines;
                    dbg_printf("%d->%d(%d,%d),%x %x %x \r\n", 0, device_settings[DEVICE_SETTINGS_PIP_MODE], rec_frc->lines_part, default_row_lines, sys_config.word_0x04 >> 28,
                                 sys_config.word0.b[3], (sys_config.word0.w >> 27) & 1);
                    if ((device_settings[DEVICE_SETTINGS_PIP_MODE] == 0 || device_settings[DEVICE_SETTINGS_PIP_MODE] == PIP_MODE_2) && rec_frc->lines_part >= default_row_lines
                        && !(sys_config.word_0x04 & SYS_CONFIG_CONVERTER_MODE) && !(sys_config.word0.w & (SYS_CONFIG_FRC_LOCK_MODE | SYS_CONFIG_BYTE_3))) {
                        dbg_printf("\033[1;35mFRC OFF\r\n\033[m");
                        if (!rec_frc->head.f.frc_off) { rec_frc->head.f.step = 0; rec_frc->head.f.frc_off = 1; } else rec_frc->head.f.frc_off = 1;
                    } else {
                        dbg_printf("\033[1;35mFRC ON\r\n\033[m");
                        if (rec_frc->head.f.frc_off) { rec_frc->head.f.step = 0; rec_frc->head.f.frc_off = 0; } else rec_frc->head.f.frc_off = 0;
                    }
                } else if (IN_STEP(rec_frc->head.word, 5) && rec_frc->head.f.frc_off) {
                    if (rec_frc->pixel_clock < panel_active_row.clk_min || rec_frc->pixel_clock > panel_active_row.clk_max) {
                        dbg_printf("\033[1;35mFRC Back Check %ld  (%ld,%ld)\r\n\033[m", rec_frc->pixel_clock, panel_active_row.clk_min, panel_active_row.clk_max);
                        clock_out_of_range = 1;
                    }
                    if (clock_out_of_range) {
                        rec_frc->flags |= CH_FLAG_FRC_BACK_CHECK;
                        rec_frc->head.f.frc_off = 0;
                        rec_frc->head.f.step = 0;
                    }
                }
            }
        }

        /* Phase 7. */
        rec->head.f.prev_state = rec->head.f.state;
    }

    /* Phase 8: port presence. */
    for (i = 0; i < PORT_ENTRY_COUNT; i++) {
        struct port_entry *pe = &port_entries[i];
        int k = i;
        if (pe->head.f.bit11 && !(unsigned char)input_get_port_status_bit(k)) {
            if ((unsigned char)input_is_receiver_index_0_or_1(i) == 1) ipc_restart_hdmi_port(i);
            if (input_is_receiver_index_2_or_3(k)) ipc_load_dp_rx_clock_registers(i);
        }
        pe->head.f.bit11 = input_get_port_status_bit(i);
    }

    /* Phase 9. */
    sys_channels_idle_task();

    /* Phase 10: the 0xB1 source. */
    b1_channel = 0xff;
    source_action = SOURCE_KEEP;
    entry = input_port_id_to_entry_index(port_records[channel_records[0].head.f.port].port_code);
    source_action = choose_source_action(entry, &b1_channel);
    if (source_action == SOURCE_RELEASE_TAKE || source_action == SOURCE_RELEASE) {
        input_select_block_source(sys_source_b1_block, port_records[channel_records[sys_source_b1_block].head.f.port].port_code);
        input_load_block_source_registers(sys_source_b1_block, port_records[channel_records[sys_source_b1_block].head.f.port].port_code);
        sys_source_b1_block = BLOCK_NONE;
        for (i = 1; i < 4; i++) {
            if (input_block_get_signal_code(channel_records[i].head.f.port) == PORT_CODE_ROUTED) {
                if (!pq_block_is_blanked(channel_records[i].head.f.port)) pq_block_blank(channel_records[i].head.f.port);
                input_select_block_source(channel_records[i].head.f.port, port_records[channel_records[i].head.f.port].port_code);
                input_load_block_source_registers(channel_records[i].head.f.port, port_records[channel_records[i].head.f.port].port_code);
            }
        }
    }
    if (source_action == SOURCE_TAKE || source_action == SOURCE_RELEASE_TAKE) {
        port_code = port_records[channel_records[b1_channel].head.f.port].port_code;
        input_setup_route_for_source(b1_channel, port_code);
        input_select_block_source(b1_channel, PORT_CODE_ROUTED);
        input_load_block_source_registers(b1_channel, PORT_CODE_ROUTED);
        ipc_send_dsc_dec_command(port_code);
        sys_source_b1_block = b1_channel;
    }
    if (source_action == SOURCE_KEEP) {
        if (sys_source_b1_block != BLOCK_NONE) if (input_block_get_signal_code(sys_source_b1_block) != PORT_CODE_ROUTED) {
            input_select_block_source(sys_source_b1_block, PORT_CODE_ROUTED);
            input_load_block_source_registers(sys_source_b1_block, PORT_CODE_ROUTED);
        }
    }
    if (sys_source_b1_block != BLOCK_NONE) {
        for (i = 1; i < 4; i++) {
            if (input_block_get_signal_code(channel_records[i].head.f.port) != PORT_CODE_ROUTED && input_block_get_signal_code(channel_records[0].head.f.port) == PORT_CODE_ROUTED
                && input_block_get_signal_code(channel_records[i].head.f.port) == port_records[channel_records[sys_source_b1_block].head.f.port].port_code) {
                input_select_block_source(channel_records[i].head.f.port, PORT_CODE_ROUTED);
                input_load_block_source_registers(channel_records[i].head.f.port, PORT_CODE_ROUTED);
            }
        }
    }
}
