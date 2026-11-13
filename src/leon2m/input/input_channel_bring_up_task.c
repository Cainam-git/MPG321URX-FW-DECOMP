/* input_channel_bring_up_task  (FUN_a013dc6c)
 *
 * Run the state machine that brings a channel up when its input gets a signal.
 * Name basis: proven - large state machine with prints; called from the main-loop task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013dc6c @ 0xa013dc6c-0xa013f1e4 (1374 words), flags -mcpu=v8 -O3 -g.
 * Source form (each item checked against the firmware's instructions):
 *  - the case blocks of the state switch are in the firmware's block order 0/3, 1, 4, 5, 6, 7, 8, 9, 10, 11, 12, 2
 *    (each ends in 'break'); the step switches of states 8, 10 and 11 are in natural order 0, 1, 2, ...
 *  - case 1 is written without a fall-through into case 2 (same code; gcc shares the copy of the state-6 test).
 *  - the port-lost exit of state 6 is 'SET_STATE_WORD(c, 5); CLR(c, CH_RUN_AGAIN);', that of states 7..11 the other
 *    order 'CLR(...); SET_STATE_WORD(...);'. With the same order in all six gcc merges the state-6 copy (-9 insns).
 *  - state 5 ready arm: the flag-word stores first (0xc000, 31, 27), then state, step and the port's sync-lost bit.
 *  - state 6 step 0: the timing copy is the static copy_port_timing(); clearing the two word_0x40 bits and
 *    INC_STEP stay in the caller (the firmware reads word 0 again after the inlined copy). word_0x40 bits 31 and 30
 *    are 1-bit bit-fields: 'bit31 = 0; bit30 = 0;' and 'if (c->word_0x40.bit31)' give the firmware's ld / cmp / bge.
 *  - state 6 step 1 and state 10: 'if (x) SET(...); else CLR(...);' (the firmware falls into the SET arm).
 *  - state 8 step 5: the window test is on the whole word, '(head.word & 0xf0) != 0x40' (a bit-field test gives
 *    srl + and + cmp 4); the exit is 'SET_STEP(c, 0); SET_STATE(c, MODE_WAIT2SHOW);' in this order.
 *  - state 10 step 0: the usVSyncFreq print takes the channel's refresh rate as its third argument (the firmware
 *    keeps it in %o2 from the 'refresh_rate > rate + 20' test up to the call).
 *  - state 10 step 0: 'if (!(flags & 0x30000000)) { whole step } INC_STEP(c); break;' (one shared INC_STEP).
 *    Channel 0: 'if (lock bit) {lock arm} else {free-run arm}' (the firmware falls into the lock arm; the free-run
 *    arm is out of line). Lock arm: 'if (refresh > rate_limit) FRCConfigPostFRC(byte 3 != 0, rate, 1); else
 *    FRCConfigPostFRC(byte 3 != 0, rate_limit, 1);' (gcc cross-jumps the call). sys_frc_setup_lock's 4th argument is
 *    read fresh from channel_records[0] each time (no local). 'block_lines < panel_lines / 2' with the (1, ok) arm
 *    first; 'channel' declared before 'rate_ok'.
 *  - sys_config is its own object (struct sys_config_record), not part of the panel row before it: the firmware
 *    reaches word 0, word 4, word 0x38 and byte 3 from one base address.
 *  - channel_port() is the inlined form of sys_get_channel_source_class (sys_get_channel_source_class): it takes the CHANNEL and
 *    switches on its port field; its local is 'unsigned char' (the firmware keeps 'and 3' after the join).
 *  - state 12 is written exit-first: 'if (state != 4) {exit} else if (sync lost) {exit} else {...}'.
 *  - prototypes: panel_correct_clock_second_step(uchar, unsigned long long *, ushort) (a K&R declaration changes
 *    the argument set-up order); input_bring_up_set_pixel_clock(int, int, struct record16 *);
 *    input_csc_setup_with_selector with five arguments and a void return; sys_frc_set_lock_mode(int, uchar, uchar);
 *    input_setup_converter_port(uchar, int, ushort, int); panel_wait_sync_pulse returns void (with an int return
 *    the scheduler moves the argument set-up of pq_port_set_reg10_bit0).
 */

/* The input timing of a channel (channel record +6, 0x3C bytes), as copied for panel_output_setup_channel_timing. */
struct input_timing {
    unsigned short line_rate, refresh_rate;     /* +0x00: 100 Hz units; +0x02: tenths of a hertz */
    unsigned char pad04[8];
    unsigned short half_0x0c, half_0x0e, half_0x10;
    unsigned short active_lines;                /* +0x12: timing field 10 */
    unsigned short half_0x14;
    unsigned short capture_width;               /* +0x16 */
    unsigned char rest[0x24];
};

/* The output timing of a channel (channel record +0x48). */
struct output_timing {
    unsigned short htotal, width;               /* +0x00, +0x02 */
    unsigned short half_0x04, half_0x06, half_0x08;
    unsigned short lines, lines_part;           /* +0x0A, +0x0C */
    unsigned short half_0x0e;
    unsigned char pad10[8];
    unsigned long long pixel_clock;             /* +0x18: in Hz (the firmware's ulDisplayClk) */
    unsigned int word_0x20;
};

/* 16 bytes handed to a callee: a capture window (callback slot 3) or a timing report (input_query_port_timing). */
struct record16 { unsigned int w[4]; };

/* One channel record (0x78 bytes; the firmware's texts call the array MDHDLRs). */
struct channel_record {
    union {
        unsigned int word;
        struct {
            unsigned int state:4;               /* bits 28..31: enum channel_state */
            unsigned int bits_24_27:4;
            unsigned int step:4;                /* bits 20..23: step inside the state */
            unsigned int bits_16_19:4;
            unsigned int port:4;                /* bits 12..15: the port shown */
            unsigned int receiver:4;            /* bits 8..11: receiver index */
            unsigned int window:4;              /* bits 4..7: picture window, 4 = none */
            unsigned int bits_1_3:3;
            unsigned int bit0:1;                /* bit 0: passed to the output set-up */
        } f;
    } head;                                     /* +0x00 */
    unsigned short step_ticks;                  /* +0x04: timer_get_ticks16 stamp of the step that waits */
    unsigned short line_rate, refresh_rate;     /* +0x06: input timing starts here (100 Hz units); +0x08: tenths of Hz */
    unsigned char pixel_repeat;                 /* +0x0A: copy of port record +0x24 */
    unsigned char register_0x22, register_0x23; /* +0x0B, +0x0C: copies of port record +0x22, +0x23 */
    unsigned char byte_0x0d;
    unsigned short half_0x0e, half_0x10;        /* +0x0E, +0x10 */
    unsigned char pad12[0x3e - 0x12];
    unsigned char csc_format_group_3;           /* +0x3E: input_csc_is_format_group_3 of the port's format code */
    unsigned char sync_mode;                    /* +0x3F: copy of the port's sync mode */
    struct { unsigned int bit31:1, bit30:1, rest:30; } word_0x40;  /* +0x40 */
    unsigned char pad44[4];
    struct output_timing out;                   /* +0x48 */
    unsigned int flags;                         /* +0x70: the CH_* bits below */
    unsigned short display_delay;               /* +0x74: ticks waited in state 11 when CH_DISPLAY_DELAY is set */
};

/* One port record (0x2A bytes), kept by input_port_sync_task. */
struct port_record {
    unsigned short status;                      /* +0x00: bit 12 = PORT_STATUS_SYNC_LOST */
    unsigned char state;                        /* +0x02: sync state of the port */
    unsigned char pad03[6];
    unsigned char sync_mode;                    /* +0x09: read by input_get_port_sync_mode */
    unsigned char port_code;                    /* +0x0A */
    unsigned char pad0b[0x1a - 0x0b];
    unsigned short half_0x1a, half_0x1c;        /* +0x1A, +0x1C */
    unsigned short line_rate, refresh_rate;     /* +0x1E: 100 Hz units; +0x20: tenths of a hertz */
    unsigned char register_0x22, register_0x23; /* +0x22, +0x23: copies of input block registers */
    unsigned char pixel_repeat, pad25;          /* +0x24 */
    unsigned short pixel_clock_value;           /* +0x26 */
    unsigned char format_code, pad29;           /* +0x28: colour format code */
};

/* The panel timing row in use (panel_active_row, 0x58 bytes), the fields read here. */
struct panel_timing_row {
    unsigned char pad00[0x48];
    unsigned short vfreq_at_min_clock;          /* +0x48: tenths of a hertz */
    unsigned char pad4a[0x52 - 0x4a];
    unsigned short refresh_rate;                /* +0x52: tenths of a hertz */
    unsigned char pad54[0x58 - 0x54];
};

/* The system configuration record (stSysConfig), the fields read here. */
struct sys_config_record {
    union { unsigned int w; unsigned char b[4]; } word0;   /* +0x00: bit 27 = SYSCFG_FRC_LOCK; b[3] = sys_config_byte_3 */
    unsigned int word_0x04;                     /* +0x04: bits 28..31 tested in state 10 */
    unsigned char pad08[0x38 - 0x08];
    unsigned int blurfree_mode;                 /* +0x38 */
};

/* The callback table (fifteen slots), the two slots called here. */
struct callback_table {
    unsigned char pad00[0xc];
    void (*capture_window_hook)(unsigned char, struct record16 *);  /* slot 3: fills a capture window for a channel */
    unsigned char pad10[0x38 - 0x10];
    void (*slot14_hook)(unsigned char);         /* slot 14: called with the channel's slot before it is shown */
};

/* The working copy of the active panel timing row, the fields read here. */
struct panel_working_row {
    unsigned char pad00[0xa];
    unsigned short active_size1;                /* +0x0A: active lines */
    unsigned char pad0c[0x50 - 0x0c];
    unsigned short vfreq_max;                   /* +0x50: tenths of a hertz */
};

extern unsigned char input_bring_up_channel;
extern struct channel_record channel_records[4];
extern struct port_record port_records[];
extern struct panel_timing_row panel_active_row;
extern struct sys_config_record sys_config;
extern unsigned char sys_config_byte_3, sys_config_byte_0x22, sys_config_byte_0x23;
extern struct callback_table sys_callback_table;
extern struct panel_working_row *panel_working_row_ptr;


extern unsigned char dbg_is_print_enabled(unsigned char);
extern int dbg_printf(const char *fmt, ...);
extern unsigned short timer_ticks_since(unsigned short);
extern unsigned short timer_get_ticks16(void);
extern void panel_wait_sync_pulse(void);
extern int reg_set_channel_ctrl_bit();
extern int input_port_code_to_receiver_index();
extern unsigned char input_port_is_av_muted();
extern int input_bring_up_lock_port();
extern unsigned char input_get_port_sync_mode(unsigned int);
extern unsigned char panel_is_power_on_done(void);
extern int sys_find_channel_of_port();
extern void pq_port_set_reg10_bit0(unsigned char, unsigned char);
extern int input_csc_is_format_group_3();
extern int sys_channel_apply_output_timing();
extern void input_csc_setup_with_selector(unsigned char, unsigned char, unsigned int, unsigned char, unsigned char);
extern unsigned char input_block_is_interlaced();
extern void input_match_port_mode(unsigned char);
extern unsigned char input_is_timing_out_of_range();
extern unsigned char input_is_refresh_rate_high();
extern unsigned char panel_get_power_state(void);
extern unsigned short pq_block_read_reg64_word();
extern unsigned char sys_get_chip_revision(void);
extern void sys_frc_set_lock_mode(int ch, unsigned char mode, unsigned char ok);
extern void panel_output_setup_block4(int, unsigned char);
extern void pq_block_show(unsigned char);
extern void FRCConfigPostFRC(unsigned char, unsigned short, unsigned char);
extern void sys_frc_setup_lock(unsigned char, unsigned char, unsigned short, unsigned short);
extern int input_bring_up_select_port();
extern int input_bring_up_clear_counters();
extern unsigned char input_bring_up_check_free_run(unsigned char, unsigned char);
extern void input_setup_converter_port(unsigned char port, int f8, unsigned short h, int f4);
extern unsigned char input_port_id_to_entry_index(unsigned char);
extern int ipc_set_hdmi21_port_mask();
extern unsigned char input_block_get_signal_code(unsigned char);
extern int ipc_api_set_dp_rx_reg40_bits();
extern int pq_window_enable();
extern int pq_select_window(int);
extern int pq_window_enable_stages();
extern void input_set_bring_up_port(unsigned char p);
extern void *memcpy(void *dst, const void *src, int n);
extern void input_query_port_timing(unsigned char, void *, struct record16 *);
extern void input_bring_up_set_pixel_clock(int, int, struct record16 *);
extern void panel_correct_clock_second_step(unsigned char, unsigned long long *, unsigned short);
extern void panel_correct_clock_first_step(unsigned char, unsigned long long *);
extern void panel_output_setup_channel_timing(unsigned char, int, unsigned char, struct input_timing *, struct output_timing *, int, unsigned char);
extern int sys_set_channel_window_size(int);
extern int sys_setup_channel_window(int);
extern int panel_calc_output_pixel_clock();
extern int input_store_capture_window(unsigned char, struct record16 *);

/* Channel states (bits 28..31 of the channel word). The MODE_ names are the firmware's own debug texts. */
enum channel_state {
    CH_STATE_OFF = 0,                   /* set by sys_set_channel_enable when a channel is switched off */
    CH_STATE_1 = 1,
    CH_STATE_2 = 2,
    CH_STATE_3 = 3,                     /* nothing is done in this state */
    CH_STATE_4 = 4,
    CH_STATE_WAIT_SYNC = 5,             /* wait for the port's sync to be stable */
    MODE_MODESEARCH = 6,
    MODE_CAPTURE = 7,
    MODE_DISPLAY = 8,
    MODE_WAIT2SHOW = 9,
    MODE_WAITPANELREADY = 10,
    MODE_WAITPANELREADY_2ND = 11,
    MODE_WAITMODECHANGE = 12
};

/* Bits of the channel flag word (+0x70), by bit number. Where only the use is known, the name says what this
   routine does with the bit. */
#define CH_AV_MUTED          11         /* set in MODE_WAITMODECHANGE when "AV MUTE" is printed */
#define CH_DISPLAY_DELAY     16         /* the firmware's bDisplayDelay (sys_api_set_channel_timeout) */
#define CH_PORT_BRING_UP     17         /* the port goes through the input_bring_up_* clock routines */
#define CH_FRC_FLAG          20         /* passed on to the output clock and timing set-up */
#define CH_WAIT_STABLE_PORT  21         /* state 1 waits for port state 4 */
#define CH_RUN_AGAIN         22         /* run the next state in the same call */
#define CH_ENABLED           24         /* written by sys_set_channel_enable */
#define CH_HOLD              25         /* set and cleared for all four channels at once; states 6 and 8 wait */
#define CH_PANEL_READY       26         /* GlobalModeHandler: panel_is_power_on_done, or always 1 for a channel
                                           whose panel it does not follow */
#define CH_SHOW_TIMER_DONE   27         /* GlobalModeHandler, state 9: its timer has run out, or none is set */
#define CH_RATE_HIGH         28         /* input_is_refresh_rate_high returned 1 */
#define CH_TIMING_FLAGGED    29         /* input_is_timing_out_of_range returned 1 */
#define CH_PATH_OWNER        31         /* this channel holds the path selector (GlobalModeHandler) */
#define CH_RESTART_FIELD     0xc000     /* bits 14..15; sys_restart_channel sets 2 when it restarts from state 12 */
#define CH_SELECTOR_SHIFT    12         /* bits 12..13: the selector passed to input_csc_setup_with_selector */
#define CH_NOT_SHOWN         ((1u << CH_RATE_HIGH) | (1u << CH_TIMING_FLAGGED))
#define CH_READY_TO_SHOW     ((1u << CH_ENABLED) | (1u << CH_SHOW_TIMER_DONE))

#define CH_PORT_FIELD        0xf000     /* port bits of the channel word */
#define CH_WINDOW_FIELD      0xf0       /* picture window bits of the channel word */
#define WINDOW_NONE          4          /* no picture window (pq_window_enable takes 0..3) */

#define PORT_STATUS_SYNC_LOST 0x1000    /* set by input_port_sync_task when the port leaves its stable state */
#define PORT_SYNC_STABLE     4          /* port state: sync stable (the firmware's SYNC_IS_STABLE) */
#define PORT_STATE_6         6
#define SYNC_MODE_5          5          /* sync mode 5 (input_block_detect_sync_mode) */

#define SYSCFG_FRC_LOCK      0x8000000  /* bit 27 of sys_config word 0: lock the frame-rate converter */
#define SYSCFG_BIT21         0x200000   /* bit 21 of sys_config word 0: channel 3 gets lock mode 0 */
#define DBG_BRING_UP         4          /* debug class of the bring-up messages */
#define CHIP_REV_82          0x82       /* sys_get_chip_revision: the HDMI 2.1 port mask is sent above this */
#define SIGNAL_CODE_DP_71    0x71       /* the two DisplayPort signal codes */
#define SIGNAL_CODE_DP_81    0x81
#define RATE_MARGIN          20         /* 2.0 Hz in tenths of a hertz */
#define RATE_LIMIT_FLOOR     650        /* 65.0 Hz in tenths of a hertz */

#define STATE(c)       ((c)->head.f.state)
#define STEP(c)        ((c)->head.f.step)
#define PORT(c)        ((c)->head.f.port)
#define SET_STATE(c, v)      ((c)->head.f.state = (v))
#define SET_STATE_WORD(c, v) ((c)->head.word = ((c)->head.word & ~0xf0000000) | ((unsigned int)(v) << 28))
#define SET_STEP(c, v) ((c)->head.f.step = (v))
#define INC_STEP(c)    ((c)->head.f.step++)
#define FLAG(c, b)     (((c)->flags >> (b)) & 1)
#define SET(c, b)      ((c)->flags |= 1u << (b))
#define CLR(c, b)      ((c)->flags &= ~(1u << (b)))
#define SYNC_LOST(p)   ((port_records[p].status >> 12) & 1)
#define DBG(s) do { if (dbg_is_print_enabled(DBG_BRING_UP)) dbg_printf(s, input_bring_up_channel); } while (0)
/* The port of the channel is usable: sync stable and not lost since the channel took it. */
#define PORT_OK(c)     (port_records[PORT(c)].state == PORT_SYNC_STABLE && !SYNC_LOST(PORT(c)))

/*
 * Copy the measured timing of the channel's port into the channel's input timing (MODE_MODESEARCH step 0).
 * For sync mode 5 the refresh rate is worked out again as line_rate * 1000 / port +0x1C (rounded) and +0x0E /
 * +0x10 come from port +0x1A / +0x1C; otherwise +0x10 is the port's pixel_clock_value.
 */
static void copy_port_timing(struct channel_record *c)
{
    struct port_record *p;

    p = &port_records[PORT(c)];
    c->line_rate = p->line_rate;
    c->refresh_rate = p->refresh_rate;
    c->register_0x22 = p->register_0x22;
    c->register_0x23 = p->register_0x23;
    c->pixel_repeat = p->pixel_repeat;
    if (input_get_port_sync_mode(PORT(c)) == SYNC_MODE_5) {
        p = &port_records[PORT(c)];
        c->half_0x0e = p->half_0x1a;
        c->refresh_rate = (c->line_rate * 1000u + p->half_0x1c / 2) / p->half_0x1c;
        c->half_0x10 = p->half_0x1c;
    } else
        c->half_0x10 = port_records[PORT(c)].pixel_clock_value;
    c->sync_mode = port_records[PORT(c)].sync_mode;
}

/* The port field of a channel when it is 0..3, else 0 (sys_get_channel_source_class, inlined). */
static unsigned int channel_port(unsigned char ch)
{
    unsigned char port = 0;
    switch (PORT(&channel_records[ch])) {
    case 0: port = 0; break;
    case 1: port = 1; break;
    case 2: port = 2; break;
    case 3: port = 3; break;
    }
    return port;
}

/* A channel on port 2 is left alone while sys_config_byte_0x22 is 1, one on port 3 while sys_config_byte_0x23 is 1. */
static int channel_is_held(struct channel_record *c)
{
    if ((c->head.word & CH_PORT_FIELD) == (2 << 12) && sys_config_byte_0x22 == 1) return 1;
    if ((c->head.word & CH_PORT_FIELD) == (3 << 12) && sys_config_byte_0x23 == 1) return 1;
    return 0;
}

/*
 * One pass of the bring-up state machine for one channel. Each call works on input_bring_up_channel and then
 * moves it on to the next channel (0, 1, 2, 3, 0, ...); 0xFF means none, and then nothing is done at all.
 * Called on every pass of sys_main_loop_periodic_task, after input_port_sync_task and before GlobalModeHandler.
 *
 * The channel's record (channel_records) holds the state and step in its first word and flag bits in +0x70
 * (CH_* above). The port in the first word selects the port record that input_port_sync_task keeps; port state
 * 4 means the port's sync is stable. While CH_RUN_AGAIN is set after a state, the next state runs in the same
 * call; the states that must wait clear it. A channel held by channel_is_held is skipped.
 *
 * The states, in order of a bring-up:
 *   1, 2         go to 3 when the port state is 4 (state 1 with CH_WAIT_STABLE_PORT) or when the channel is
 *                enabled and the port state is 6. 0 and 3 do nothing; 4 goes to 5.
 *   5            wait until the port state is 4, then MODE_MODESEARCH. With CH_PORT_BRING_UP the port is
 *                selected for bring-up and its counters cleared on every pass.
 *   6  MODE_MODESEARCH   copy the port timing (step 0); match it against the mode table and set
 *                CH_TIMING_FLAGGED / CH_RATE_HIGH (step 1).
 *   7  MODE_CAPTURE      colour format group, output timing and colour set-up of the receiver.
 *   8  MODE_DISPLAY      step 0 capture window (callback slot 3), step 1 window size and output pixel clock,
 *                step 2 output timing (after 80 ticks), step 5 (after 40 more ticks) the converter port, the HDMI
 *                2.1 port mask, the DisplayPort receiver and the picture window, then MODE_WAIT2SHOW. Steps 3 and
 *                4 (the two clock corrections) follow nothing here: step 2 goes on to step 5. With
 *                CH_PORT_BRING_UP, step 0 goes straight to step 5, which programs the pixel clock from the
 *                receiver's timing report; steps 6 and 7 run the free-run check, then MODE_WAITMODECHANGE.
 *   9  MODE_WAIT2SHOW    wait while input_port_is_av_muted returns 1, and until CH_ENABLED and
 *                CH_SHOW_TIMER_DONE are both set.
 *   10 MODE_WAITPANELREADY   step 0: frame-rate converter set-up (channel 0: lock or free run) and show the
 *                picture block; step 1: wait for CH_PANEL_READY and panel power state 5 or 6.
 *   11 MODE_WAITPANELREADY_2nd   step 0: after the display delay and once the panel has powered on, call
 *                slot 14, clear bit 0 of register 0x10 of the block, wait three sync pulses and clear the
 *                channel control bit; step 1: wait for CH_PANEL_READY, then MODE_WAITMODECHANGE.
 *   12 MODE_WAITMODECHANGE   watch the port: back to 5 when its sync is no longer stable, or when
 *                input_port_is_av_muted returns 1 ("AV MUTE", CH_AV_MUTED set); else with
 *                CH_PORT_BRING_UP run input_bring_up_lock_port.
 * In states 6 to 11 a port that is not stable sends the channel back to state 5 and ends the pass.
 * States 10 and 11 skip their set-up (but not their step counting) when CH_TIMING_FLAGGED or CH_RATE_HIGH is set.
 */
void input_channel_bring_up_task(void)
{
    struct channel_record *c;
    unsigned char receiver;
    struct record16 window, report, window_copy;
    struct input_timing input_copy;
    struct output_timing output_copy;
    unsigned char port_info_input[0x3c];
    struct record16 report_copy;

    if (input_bring_up_channel == 0xff) return;
    c = &channel_records[input_bring_up_channel];
    receiver = input_port_code_to_receiver_index(port_records[PORT(c)].port_code);
    if (!channel_is_held(c) && input_bring_up_channel != 0xff) {
        do {
            switch (STATE(c)) {
            case CH_STATE_OFF:
            case CH_STATE_3:
                break;
            case CH_STATE_1:
                if (FLAG(c, CH_WAIT_STABLE_PORT)) {
                    if (port_records[PORT(c)].state == PORT_SYNC_STABLE) SET_STATE(c, CH_STATE_3);
                } else if (FLAG(c, CH_ENABLED) && port_records[PORT(c)].state == PORT_STATE_6) SET_STATE(c, CH_STATE_3);
                break;
            case CH_STATE_4:
                SET_STATE_WORD(c, CH_STATE_WAIT_SYNC);
                break;
            case CH_STATE_WAIT_SYNC:
                if (FLAG(c, CH_PORT_BRING_UP)) {
                    input_bring_up_select_port(PORT(c));
                    input_bring_up_clear_counters(PORT(c));
                }
                if (port_records[PORT(c)].state == PORT_SYNC_STABLE) {
                    /* Port stable: clear bits 14..15, CH_PATH_OWNER, CH_SHOW_TIMER_DONE and the port's sync-lost
                       bit, then search the mode. */
                    c->flags &= ~CH_RESTART_FIELD;
                    CLR(c, CH_PATH_OWNER);
                    CLR(c, CH_SHOW_TIMER_DONE);
                    SET_STATE(c, MODE_MODESEARCH);
                    SET_STEP(c, 0);
                    port_records[PORT(c)].status &= ~PORT_STATUS_SYNC_LOST;
                }
                break;
            case MODE_MODESEARCH:
                if (PORT_OK(c)) {
                if (FLAG(c, CH_HOLD)) break;
                if (FLAG(c, CH_PORT_BRING_UP)) {
                    if (input_block_is_interlaced(PORT(c))) break;
                    CLR(c, CH_RUN_AGAIN);
                }
                if (STEP(c) == 0) {
                    DBG("MODE_MODESEARCH(%d) : 0\r\n");
                    copy_port_timing(c);
                    c->word_0x40.bit31 = 0;
                    c->word_0x40.bit30 = 0;
                    INC_STEP(c);
                } else if (STEP(c) == 1) {
                    DBG("MODE_MODESEARCH(%d) : 1\r\n");
                    input_match_port_mode(PORT(c));
                    SET_STEP(c, 0);
                    SET_STATE(c, MODE_CAPTURE);
                    if (input_is_timing_out_of_range(PORT(c))) SET(c, CH_TIMING_FLAGGED); else CLR(c, CH_TIMING_FLAGGED);
                    if (input_is_refresh_rate_high(PORT(c))) SET(c, CH_RATE_HIGH); else CLR(c, CH_RATE_HIGH);
                }
                } else {
                    SET_STATE_WORD(c, CH_STATE_WAIT_SYNC);
                    CLR(c, CH_RUN_AGAIN);
                }
                break;
            case MODE_CAPTURE:
                if (PORT_OK(c)) {
                DBG("MODE_CAPTURE(%d) : 0\r\n");
                c->csc_format_group_3 = input_csc_is_format_group_3(port_records[PORT(c)].format_code);
                sys_channel_apply_output_timing(receiver, PORT(c), (c->flags & CH_RESTART_FIELD) == 0);
                input_csc_setup_with_selector(receiver, PORT(c), ((c->flags >> CH_SELECTOR_SHIFT) & 3), 1, port_records[PORT(c)].format_code);
                SET_STATE(c, MODE_DISPLAY);
                SET_STEP(c, 0);
                } else {
                    CLR(c, CH_RUN_AGAIN);
                    SET_STATE_WORD(c, CH_STATE_WAIT_SYNC);
                }
                break;
            case MODE_DISPLAY:
                if (PORT_OK(c)) {
                if (FLAG(c, CH_HOLD)) break;
                switch (STEP(c)) {
                case 0:
                    /* Bring-up ports skip the capture window and the output set-up: straight to step 5. */
                    DBG("MODE_DISPLAY(%d) : 0\r\n");
                    if (FLAG(c, CH_PORT_BRING_UP)) {
                        input_bring_up_select_port(PORT(c));
                        input_bring_up_clear_counters(PORT(c));
                        SET_STEP(c, 5);
                        c->step_ticks = timer_get_ticks16();
                    } else {
                        if (sys_callback_table.capture_window_hook) {
                            sys_callback_table.capture_window_hook(input_bring_up_channel, &window);
                            window_copy = window;
                            input_store_capture_window(input_bring_up_channel, &window_copy);
                        }
                        INC_STEP(c);
                    }
                    break;
                case 1:
                    DBG("MODE_DISPLAY(%d) : 1\r\n");
                    sys_set_channel_window_size(input_bring_up_channel);
                    sys_setup_channel_window(input_bring_up_channel);
                    panel_calc_output_pixel_clock(PORT(c), c->head.f.bit0, FLAG(c, CH_FRC_FLAG), (struct input_timing *)&c->line_rate, &c->out);
                    INC_STEP(c);
                    c->step_ticks = timer_get_ticks16();
                    if (c->word_0x40.bit31) CLR(c, CH_RUN_AGAIN);
                    break;
                case 2:
                    /* After 80 ticks: the output timing, from copies of the input and output timing. Then step 5
                       (steps 3 and 4 are not reached from here). */
                    if (timer_ticks_since(c->step_ticks) > 80) {
                        DBG("MODE_DISPLAY(%d) : 2\r\n");
                        memcpy(&input_copy, &c->line_rate, 0x3c);
                        output_copy = c->out;
                        panel_output_setup_channel_timing(PORT(c), c->head.f.receiver, c->head.f.bit0, &input_copy, &output_copy, FLAG(c, CH_FRC_FLAG), (sys_config.word0.w >> 25) & (c->flags >> CH_PATH_OWNER));
                        SET_STEP(c, 5);
                        c->step_ticks = timer_get_ticks16();
                    }
                    break;
                case 3:
                    DBG("MODE_DISPLAY(%d) : 3\r\n");
                    panel_correct_clock_first_step(PORT(c), &c->out.pixel_clock);
                    INC_STEP(c);
                    break;
                case 4:
                    DBG("MODE_DISPLAY(%d) : 4\r\n");
                    panel_correct_clock_second_step(PORT(c), &c->out.pixel_clock, c->refresh_rate);
                    INC_STEP(c);
                    c->step_ticks = timer_get_ticks16();
                    break;
                case 5:
                    DBG("MODE_DISPLAY(%d) : 5\r\n");
                    if (timer_ticks_since(c->step_ticks) > 40) {
                        if (FLAG(c, CH_PORT_BRING_UP)) {
                            /* Bring-up port: program the pixel clock from the receiver's timing report. */
                            input_set_bring_up_port(PORT(c));
                            memcpy(port_info_input, &c->line_rate, 0x3c);
                            input_query_port_timing(PORT(c), port_info_input, &report);
                            report_copy = report;
                            input_bring_up_set_pixel_clock(1, 1, &report_copy);
                            SET_STEP(c, 6);
                            c->step_ticks = timer_get_ticks16();
                        } else {
                            input_setup_converter_port(PORT(c), c->head.f.receiver, c->line_rate, c->head.f.window);
                            if (sys_get_chip_revision() > CHIP_REV_82)
                                ipc_set_hdmi21_port_mask(input_port_id_to_entry_index(port_records[PORT(c)].port_code), 1, (unsigned char)(1 << input_bring_up_channel));
                            if (input_block_get_signal_code(PORT(c)) == SIGNAL_CODE_DP_71 || input_block_get_signal_code(PORT(c)) == SIGNAL_CODE_DP_81)
                                ipc_api_set_dp_rx_reg40_bits(receiver);
                            /* Switch the channel's picture window and all picture stages on. */
                            if ((c->head.word & CH_WINDOW_FIELD) != (WINDOW_NONE << 4)) {
                                pq_window_enable(c->head.f.window);
                                pq_select_window(c->head.f.window);
                                pq_window_enable_stages(0xff);
                            }
                            SET_STEP(c, 0);
                            SET_STATE(c, MODE_WAIT2SHOW);
                            c->step_ticks = timer_get_ticks16();
                            CLR(c, CH_RUN_AGAIN);
                        }
                        CLR(c, CH_AV_MUTED);
                    }
                    break;
                case 6:
                    /* Bring-up port: after 50 ticks start the free-run check, then wait for it. */
                    if (timer_ticks_since(c->step_ticks) > 50) {
                        input_bring_up_check_free_run(PORT(c), 1);
                        SET_STEP(c, 7);
                    }
                    break;
                case 7:
                    if (input_bring_up_check_free_run(PORT(c), 0)) {
                        SET_STEP(c, 0);
                        SET_STATE(c, MODE_WAITMODECHANGE);
                        CLR(c, CH_RUN_AGAIN);
                    }
                    break;
                }
                } else {
                    CLR(c, CH_RUN_AGAIN);
                    SET_STATE_WORD(c, CH_STATE_WAIT_SYNC);
                }
                break;
            case MODE_WAIT2SHOW:
                if (PORT_OK(c)) {
                if (dbg_is_print_enabled(DBG_BRING_UP)) dbg_printf("MODE_WAIT2SHOW >>> (%d, %d, %d)\r\n", input_bring_up_channel, FLAG(c, CH_SHOW_TIMER_DONE), FLAG(c, CH_ENABLED));
                if (input_port_is_av_muted(PORT(c), receiver) == 1) break;
                if ((c->flags & CH_READY_TO_SHOW) == CH_READY_TO_SHOW) {
                    SET_STEP(c, 0);
                    SET_STATE(c, MODE_WAITPANELREADY);
                }
                } else {
                    CLR(c, CH_RUN_AGAIN);
                    SET_STATE_WORD(c, CH_STATE_WAIT_SYNC);
                }
                break;
            case MODE_WAITPANELREADY:
                if (PORT_OK(c)) {
                DBG("MODE_WAITPANELREADY(%d)\r\n");
                switch ((int)STEP(c)) {
                case 0:
                    if (!(c->flags & CH_NOT_SHOWN)) {
                    /* The frame-rate converter set-up is skipped while CH_AV_MUTED is set. */
                    if (!FLAG(c, CH_AV_MUTED)) {
                        unsigned short rate_limit, block_lines, panel_lines;
                        unsigned char channel = input_bring_up_channel;
                        unsigned char rate_ok = 1;
                        rate_limit = panel_active_row.vfreq_at_min_clock > RATE_LIMIT_FLOOR ? panel_active_row.vfreq_at_min_clock : RATE_LIMIT_FLOOR;
                        output_copy = channel_records[0].out;
                        block_lines = pq_block_read_reg64_word(channel);
                        panel_lines = panel_working_row_ptr->active_size1;
                        /* Up to revision 0x82 the limit is also capped by the row's vfreq_max; above it, it is 0. */
                        if (sys_get_chip_revision() <= CHIP_REV_82) rate_limit = rate_limit > panel_working_row_ptr->vfreq_max ? panel_working_row_ptr->vfreq_max : rate_limit;
                        else rate_limit = 0;
                        /* An input more than 2.0 Hz above the panel row's rate clears the 'ok' passed to the lock mode. */
                        if (channel_records[channel].refresh_rate > panel_active_row.refresh_rate + RATE_MARGIN) rate_ok = 0;
                        dbg_printf("\033[1;33mMDHDLRs[%d].InputTiming.usVSyncFreq = %d \r\n\033[m", channel, channel_records[channel].refresh_rate);
                        if (channel == 0) {
                            if (!(channel_records[0].head.f.bit0)) {
                                if (sys_config.word0.w & SYSCFG_FRC_LOCK) {
                                    dbg_printf("FRC Lock--------------------\r\n");
                                    if (channel_records[0].refresh_rate > rate_limit) {
                                        FRCConfigPostFRC(sys_config.word0.b[3] != 0, panel_active_row.refresh_rate, 1);
                                    } else {
                                        FRCConfigPostFRC(sys_config.word0.b[3] != 0, rate_limit, 1);
                                    }
                                    /* The second argument (blurfree_mode == 3) is not read by sys_frc_setup_lock. */
                                    sys_frc_setup_lock(1, sys_config.blurfree_mode == 3, output_copy.lines_part, channel_records[0].refresh_rate);
                                    if ((sys_config.word_0x04 & 0xf0000000) == 0x30000000 || (sys_config.word_0x04 & 0xf0000000) == 0x20000000)
                                        sys_frc_set_lock_mode(channel_port(0), 2, rate_ok & 1);
                                    else {
                                        dbg_printf("\033[1;33m%x,%x\r\n\033[m", block_lines, panel_lines);
                                        /* Lock mode 1 when register 0x64 of block 0 holds less than half the panel's active lines. */
                                        if (block_lines < panel_lines / 2)
                                            sys_frc_set_lock_mode(channel_port(0), 1, rate_ok & 1);
                                        else
                                            sys_frc_set_lock_mode(channel_port(0), 0, 0);
                                    }
                                } else {
                                    dbg_printf("FRC Free Run--------------------\r\n");
                                    FRCConfigPostFRC(sys_config.word0.b[3] != 0, panel_active_row.refresh_rate, 1);
                                    sys_frc_setup_lock(0, 0, 0, channel_records[0].refresh_rate);
                                    sys_frc_set_lock_mode(channel_port(0), 2, rate_ok & 1);
                                }
                            }
                        } else if (channel == 3 && (sys_config.word0.w & SYSCFG_BIT21))
                            sys_frc_set_lock_mode(channel_port(3), 0, 0);
                        else
                            sys_frc_set_lock_mode(channel_port(channel), 2, rate_ok & 1);
                    }
                    CLR(c, CH_AV_MUTED);
                    if (input_bring_up_channel == 0 && sys_config_byte_3 == 0) panel_output_setup_block4(panel_active_row.refresh_rate, 0);
                    pq_block_show(PORT(c));
                    c->step_ticks = timer_get_ticks16();
                    }
                    INC_STEP(c);
                    break;
                case 1:
                    if (FLAG(c, CH_PANEL_READY) && panel_get_power_state() > 4 && panel_get_power_state() <= 6) INC_STEP(c);
                    break;
                case 2:
                    SET_STEP(c, 0);
                    SET_STATE(c, MODE_WAITPANELREADY_2ND);
                    break;
                }
                } else {
                    CLR(c, CH_RUN_AGAIN);
                    SET_STATE_WORD(c, CH_STATE_WAIT_SYNC);
                }
                break;
            case MODE_WAITPANELREADY_2ND:
                if (PORT_OK(c)) {
                DBG("MODE_WAITPANELREADY_2nd(%d)\r\n");
                switch ((int)STEP(c)) {
                case 0:
                    /* With CH_DISPLAY_DELAY, wait display_delay ticks from the stamp taken in state 10. */
                    if (!FLAG(c, CH_DISPLAY_DELAY) || timer_ticks_since(c->step_ticks) >= c->display_delay) {
                        if (panel_is_power_on_done()) {
                            if (!(c->flags & CH_NOT_SHOWN)) {
                                if (sys_callback_table.slot14_hook) sys_callback_table.slot14_hook(sys_find_channel_of_port(PORT(c)));
                                pq_port_set_reg10_bit0(PORT(c), 0);
                                panel_wait_sync_pulse();
                                panel_wait_sync_pulse();
                                panel_wait_sync_pulse();
                                reg_set_channel_ctrl_bit(PORT(c), 0);
                            }
                            INC_STEP(c);
                        }
                    }
                    break;
                case 1:
                    if (FLAG(c, CH_PANEL_READY)) {
                        SET_STEP(c, 0);
                        SET_STATE(c, MODE_WAITMODECHANGE);
                    }
                    break;
                }
                } else {
                    CLR(c, CH_RUN_AGAIN);
                    SET_STATE_WORD(c, CH_STATE_WAIT_SYNC);
                }
                break;
            case MODE_WAITMODECHANGE:
                if (port_records[PORT(c)].state != PORT_SYNC_STABLE) {
                    CLR(c, CH_RUN_AGAIN);
                    SET_STATE(c, CH_STATE_WAIT_SYNC);
                    DBG("Exit MODE_WAITMODECHANGE(%d)\r\n");
                } else if (SYNC_LOST(PORT(c))) {
                    CLR(c, CH_RUN_AGAIN);
                    SET_STATE(c, CH_STATE_WAIT_SYNC);
                    DBG("Exit MODE_WAITMODECHANGE(%d)\r\n");
                } else {
                    if (input_port_is_av_muted(PORT(c), receiver) == 1) {
                        SET(c, CH_AV_MUTED);
                        CLR(c, CH_RUN_AGAIN);
                        SET_STATE(c, CH_STATE_WAIT_SYNC);
                        dbg_printf("\033[0;35mAV MUTE(%d)\r\n\033[m", input_bring_up_channel);
                    } else if (FLAG(c, CH_PORT_BRING_UP))
                        input_bring_up_lock_port(PORT(c));
                }
                break;
            case CH_STATE_2:
                if (FLAG(c, CH_ENABLED) && port_records[PORT(c)].state == PORT_STATE_6) SET_STATE(c, CH_STATE_3);
                break;
            }
        } while (c->flags & (1u << CH_RUN_AGAIN));
    }
    input_bring_up_channel = (input_bring_up_channel + 1) & 3;
}
