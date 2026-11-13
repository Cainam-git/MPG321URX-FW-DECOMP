/* startup_reset_channel_records  (FUN_a013c944)
 *
 * Reset the four channel records.
 * Name basis: proven - memory writes to the four channel records, then channel 3 switched on by
 *   sys_set_channel_enable when bit 21 of sys_config is set; called from start-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013c944 @ 0xa013c944, flags -mcpu=v8 -O3 -g -msoft-float (without -msoft-float the loop pass hoists
 * other mask constants).
 * Source form (no aids, the firmware's order of stores):
 *  - one bit-field store per field (word 0, word +0x70, word +0x68 as bit-field structs): the firmware's chains of
 *    and/or masks are exactly gcc's bit-field stores. The combine pass merges the small masks and widens the
 *    clear of bits 12..13 with the known-zero bits;
 *  - the switch arms stand in the order default (window 1), case 2, case 3; other orders give other code;
 *  - channel 0 starts with the store to display_delay, before the flag word; chained 'a = b = x' stores b first, so
 *    the pairs are written in the firmware's store order;
 *  - in the third loop the +0x68 stores come after the halfwords and 'run_again = 0' is last.
 */
/* Word 0 of a channel record (same layout as the head of input_channel_bring_up_task's channel_record). */
struct channel_word0 {
    unsigned int state:4,           /* bits 28..31 */
                 bits_24_27:4,
                 step:4,            /* bits 20..23 */
                 bits_16_19:4,      /* set to the channel number here */
                 port:4,            /* bits 12..15 */
                 receiver:4,        /* bits 8..11 */
                 window:4,          /* bits 4..7: picture window, 4 = none */
                 bits_1_3:3,
                 bit0:1;
};
/* Flag word +0x70; bit numbers and names as in input_channel_bring_up_task. */
struct channel_flags {
    unsigned int path_owner:1,          /* bit 31 */
                 bit_30:1,
                 timing_flagged:1,      /* bit 29 */
                 rate_high:1,           /* bit 28 */
                 show_timer_done:1,     /* bit 27 */
                 panel_ready:1,         /* bit 26 */
                 hold:1,                /* bit 25 */
                 enabled:1,             /* bit 24 */
                 bit_23:1,
                 run_again:1,           /* bit 22: run the state machine again in the same call */
                 wait_stable_port:1,    /* bit 21 */
                 frc_flag:1,            /* bit 20 */
                 bit_19:1,
                 bit_18:1,
                 port_bring_up:1,       /* bit 17 */
                 display_delay:1,       /* bit 16 */
                 restart_field:2,       /* bits 14..15 */
                 selector:2,            /* bits 12..13 */
                 rest:12;
};
struct channel_word_0x68 { unsigned int bits_24_31:8, bit_23:1, bit_22:1, bit_21:1, bit_20:1, rest:20; };
struct channel_record {
    struct channel_word0 word0;                 /* +0x00 */
    unsigned char pad04[0x4a - 0x04];
    /* +0x4a..+0x5c: the output timing part of the record, filled from the active panel row */
    unsigned short half_0x4a, half_0x4c, half_0x4e, half_0x50, half_0x52, half_0x54, half_0x56, half_0x58, half_0x5a, half_0x5c;
    unsigned char pad5e[0x68 - 0x5e];
    struct channel_word_0x68 word_0x68;         /* +0x68 */
    unsigned char pad6c[4];
    struct channel_flags flags;                 /* +0x70 */
    unsigned short display_delay;               /* +0x74 */
    unsigned char pad76[2];
};
/* The active panel row (0x58 bytes); only the fields used here. */
struct panel_row_fields { unsigned char pad00[8]; unsigned short half_0x08, half_0x0a; unsigned char pad0c[0x26 - 0x0c];
                unsigned short half_0x26, half_0x28; unsigned char pad2a[0x30 - 0x2a]; unsigned short half_0x30, half_0x32; };
extern struct channel_record channel_records[4];
extern struct panel_row_fields panel_active_row;
extern unsigned int sys_config;
extern const unsigned char startup_channel_ports[];
extern void sys_set_channel_enable(unsigned char, unsigned char);

#define CH_STATE_WAIT_SYNC   5      /* channel state 5: wait for the port's sync to be stable */
#define CH_STATE_OFF         0
#define WINDOW_NONE          4      /* no picture window */
#define CH_DISPLAY_DELAY_TICKS 500  /* start value of the channel's display_delay */
#define SYS_CONFIG_CHANNEL3_BIT 0x200000    /* bit 21 of sys_config word 0 */

/*
 * Put the four channel records (channel_records) into their start state. Pure RAM writes, no waits.
 * Called once from the start-up routine, after the display output has been set up (startup_init_display_output
 * has returned) and System_Initialize has run.
 *
 * Channel 0 starts in state 5 (wait for sync) with the enabled and frc flags set, bit 30 set, and window 0 and
 * port 0. Channels 1..3 start in state 0 (off) with the enabled flag cleared; channel 1 gets path 1 and bit 30 set,
 * channels 2 and 3 get path 2 and bit 30 cleared. Their ports come from startup_channel_ports (FW.021: 0, 2, 1, 3,
 * so channels 1..3 get ports 2, 1, 3); their window is 1 for channel 1 and 4 (none) for channels 2 and 3.
 * All four get display_delay 500.
 *
 * Then, for every channel: bit 0 of word 0 is set for channel 0 only; the flag bits 25..29 and 31 and the
 * restart field are cleared, bit 18 is set and run_again is cleared; and the output timing halfwords +0x4A..+0x5C are
 * filled from the active panel row (each value is stored twice: +0x4A and +0x4C, +0x52 and +0x54, +0x4E and
 * +0x50, +0x58 and +0x56; +0x5A and +0x5C are zero). Finally, if bit 21 of the system configuration word is
 * set, channel 3 is switched on (sys_set_channel_enable(3, 1)).
 */
void startup_reset_channel_records(void)
{
    unsigned char i;

    channel_records[0].display_delay = CH_DISPLAY_DELAY_TICKS;
    channel_records[0].word0.state = CH_STATE_WAIT_SYNC;
    channel_records[0].word0.bits_24_27 = 5;
    channel_records[0].word0.step = 0;
    channel_records[0].word0.window = 0;
    channel_records[0].word0.bits_1_3 = 0;
    channel_records[0].word0.port = 0;
    channel_records[0].word0.bits_16_19 = 0;
    channel_records[0].flags.enabled = 1;
    channel_records[0].flags.bit_30 = 1;
    channel_records[0].flags.frc_flag = 1;
    channel_records[0].flags.port_bring_up = 0;
    channel_records[0].flags.display_delay = 0;
    channel_records[0].flags.selector = 1;
    for (i = 1; i < 4; i++) {
        channel_records[i].word0.state = CH_STATE_OFF;
        channel_records[i].word0.bits_24_27 = 0;
        channel_records[i].flags.enabled = 0;
        channel_records[i].word0.step = 0;
        channel_records[i].flags.bit_23 = 1;
        channel_records[i].flags.frc_flag = 0;
        channel_records[i].flags.port_bring_up = 0;
        channel_records[i].flags.display_delay = 0;
        channel_records[i].flags.selector = 1;
        channel_records[i].display_delay = CH_DISPLAY_DELAY_TICKS;
        if (i == 1) {
            channel_records[i].word0.bits_1_3 = 1;
            channel_records[i].flags.bit_30 = 1;
        } else {
            channel_records[i].flags.bit_30 = 0;
            channel_records[i].word0.bits_1_3 = 2;
        }
        switch (i) {
        default:
            channel_records[i].word0.port = startup_channel_ports[i];
            channel_records[i].word0.window = 1;
            break;
        case 2:
            channel_records[i].word0.port = startup_channel_ports[i];
            channel_records[i].word0.window = WINDOW_NONE;
            break;
        case 3:
            channel_records[i].word0.port = startup_channel_ports[i];
            channel_records[i].word0.window = WINDOW_NONE;
            break;
        }
        channel_records[i].word0.bits_16_19 = i;
    }

    for (i = 0; i < 4; i++) {
        if (i == 0)
            channel_records[i].word0.bit0 = 1;
        else
            channel_records[i].word0.bit0 = 0;
        channel_records[i].flags.path_owner = 0;
        channel_records[i].flags.timing_flagged = 0;
        channel_records[i].flags.rate_high = 0;
        channel_records[i].flags.show_timer_done = 0;
        channel_records[i].flags.panel_ready = 0;
        channel_records[i].flags.hold = 0;
        channel_records[i].flags.restart_field = 0;
        channel_records[i].flags.bit_18 = 1;
        channel_records[i].half_0x4a = channel_records[i].half_0x4c = panel_active_row.half_0x08;
        channel_records[i].half_0x52 = channel_records[i].half_0x54 = panel_active_row.half_0x0a;
        channel_records[i].half_0x4e = channel_records[i].half_0x50 = panel_active_row.half_0x28 + panel_active_row.half_0x26;
        channel_records[i].half_0x58 = channel_records[i].half_0x56 = panel_active_row.half_0x32 + panel_active_row.half_0x30;
        channel_records[i].word_0x68.bit_23 = 1;
        channel_records[i].word_0x68.bit_20 = 0;
        channel_records[i].half_0x5c = channel_records[i].half_0x5a = 0;
        channel_records[i].flags.run_again = 0;
    }
    if (sys_config & SYS_CONFIG_CHANNEL3_BIT)
        sys_set_channel_enable(3, 1);
}
