/* sys_channel_apply_output_timing  (FUN_a013c144)
 *
 * Apply the output timing of a channel, including the low-resolution path.
 * Name basis: derived - 480p chain; used by the bring-up state machine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013c144 @ 0xa013c144-0xa013c894 (468 instructions). Flags -mcpu=v8 -O3 -g (-msoft-float gives the
 * same bytes).
 * Source forms the exact build depends on:
 *  - sys_channel0_apply_timing_block is compiled in this file and declared 'inline' (gcc 3.4 -O3 inlines it;
 *    without 'inline' it stays a call). Its code here gives its own firmware code too.
 *  - width and lines are addressable locals, reloaded after every call: they are passed by address to the
 *    static adjust_channel0_size, which is inlined. Declaration order lines, width.
 *  - flag word +0x70 bit 31 is a 1-bit bitfield (path_owner, in a union with the word; bit 30 is tested as a word
 *    mask). With 'flags < 0' the picture block 5 block and the interlaced arm are laid out in other places.
 *  - bits 16..19 of word 0 are read as a 4-bit bitfield of the top halfword (lduh; a plain '& 0xf' becomes
 *    ldub +1).
 *  - 'term_large = 0; if (term > 0x1fff) term_large = 1;' with term an unsigned int local that is reused for the
 *    width argument of input_block_set_size_pair.
 *  - 'pad = 0x10 - width % 16; pad %= 16;' as two statements (one expression folds 16 - y to a negation);
 *    'odd = height % 2'.
 *  - input_block_enable_scaler_ratio and input_block_set_capture_reg12 are written as two calls in if/else (the
 *    compiler merges them).
 *  - phase 3 tests 'timing_width != width || timing_height != height' with the term_large arm first (the
 *    opposite arm order gives two register differences).
 */
/* The input timing of a channel: the 0x3C bytes at channel record +6. */
struct timing_block { unsigned char d[0x3c]; };

/* One channel record (0x78 bytes), the fields used here. sys_channel_fill_size_fields fills +0x12..+0x20:
   the timing_* values from the port record and the input block's registers, and copies of them as the position
   values width / height / start_x / start_y (which the position handlers can change). */
struct channel_record {
    union {
        struct { unsigned char pad0[6]; struct timing_block timing; } a;
        struct {
            unsigned short bits_20_31 : 12, bits_16_19 : 4;                /* top half of word 0 */
            unsigned short half_0x02, step_ticks, line_rate;
            unsigned short refresh_rate;                                    /* +0x08: tenths of a hertz */
            unsigned short half_0x0a, half_0x0c;
            unsigned short half_0x0e;           /* +0x0E: bound of start_x + width (channel 0) */
            unsigned short half_0x10;           /* +0x10: bound of start_y + height (channel 0) */
            unsigned short timing_width, timing_height;                     /* +0x12, +0x14 */
            unsigned short width, height;                                   /* +0x16, +0x18 */
            unsigned short timing_start_x, timing_start_y;                  /* +0x1A, +0x1C */
            unsigned short start_x, start_y;                                /* +0x1E, +0x20 */
            unsigned char p22[0x1c];
            unsigned char csc_format_group_3;   /* +0x3E: the port's format code is in colour format group 3 */
        } b;
    } u;
    unsigned char pad42[0x26];
    union { unsigned int w; unsigned char b[4]; } word_0x68;
    unsigned int word_0x6c;
    union { unsigned int w; struct { unsigned int path_owner : 1, rest : 31; } f; } flags;   /* +0x70 */
};

/* The active panel timing row, its first fields. */
struct panel_timing_row { unsigned int flags; unsigned short half_0x04; unsigned char display_mode, bpc; unsigned short active_size0, active_size1; };

/* channel_records seen as words: only word 0 (port in bits 12..15) is read through this type. */
struct channel_record_word0 { unsigned int word0; unsigned char p04[0x74]; };

#define SYS_CONFIG_BIT25    0x2000000       /* bit 25 of sys_config word 0 */
#define CH_FLAG_BIT30       0x40000000      /* channel flag word bit 30: set up the low-resolution path */
#define WORD_0X68_BIT22     0x400000
#define WORD_0X68_BIT21     0x200000

#define RECEIVER_NONE       0xff            /* no receiver index */
#define PORT_CODE_ROUTED    0xb1            /* signal code of a block that takes another channel's source */
#define PORT_TYPE_5         5               /* input_get_port_sync_mode value that gets a new measurement */
#define CALLBACK_SLOT_6     6               /* sys_callback_table slot called with the channel number */
#define CHANNEL_NONE        0xff
#define TERM_LIMIT          0x1fff
#define PATH_ON_WAIT_TICKS  0x32            /* wait between switching the path on and reading block 5 back */

extern struct panel_timing_row panel_active_row;
extern unsigned int sys_config;
extern void (*sys_callback_table[15])(unsigned char);
extern struct channel_record_word0 channel_records[];
extern struct channel_record *sys_find_channel_by_port(unsigned char port);
extern void *memcpy(void *dst, const void *src, int n);
extern unsigned char input_block_get_status_bit2(unsigned char port);
extern void SetFRCCHRW(unsigned char channel, struct timing_block *timing, unsigned short width, unsigned short lines, unsigned char double_lines, unsigned char on_request, unsigned char mode);
extern void input_block0_toggle_pre_frc(void);
extern unsigned char input_block_get_signal_code(unsigned char);
extern unsigned char sys_get_active_port_code(void);
extern void input_block_set_offset(unsigned char, unsigned short);
extern unsigned char input_get_port_sync_mode(unsigned int);
extern void sys_poll_events_stub_copy6(unsigned char, unsigned char);
extern void input_block_measure_active_area(unsigned char);
extern void sys_channel_fill_size_fields(unsigned char, unsigned char);
extern void sys_call_empty_hook(unsigned char);
extern unsigned char sys_check_channel_index(unsigned char);
extern void input_block_disable_scaler(unsigned char);
extern unsigned char input_is_port_code_scalable(unsigned char);
extern void input_block_enable_scaler_ratio(unsigned char, unsigned short);
extern void input_block_set_reg6_bit6(unsigned char);
extern unsigned char input_block_get_reg6_bit6(unsigned char);
extern unsigned char sys_frc_get_enable_bit4(void);
extern void input_block_set_capture_start(unsigned char, unsigned short, unsigned short);
extern unsigned char sys_is_value_in_pip_limit(unsigned char);
extern void input_block_setup_capture(unsigned char, unsigned short, unsigned short, unsigned short);
extern void input_block_setup_capture_quarter(unsigned char, unsigned short, unsigned short, unsigned short);
extern void input_block_set_reg41_quarter(unsigned char, unsigned short);
extern void sys_set_block_5b50_size(unsigned short, unsigned short);
extern void drv_Set3DDEISC(unsigned short, unsigned short, unsigned short);
extern void sys_api_enable_selected_path(unsigned char);
extern void timer_sleep_ticks(int ms);
extern void pq_block5_copy_htotal_readback(void);
extern void sys_api_disable_selected_path(unsigned char);
extern void input_block_set_capture_reg12(unsigned char, unsigned short);
extern void input_block_set_capture_reg0e(unsigned char, unsigned short);
extern void sys_setup_low_resolution_path(unsigned char, unsigned short, unsigned short);
extern void input_block_set_size_pair(unsigned char, unsigned short, unsigned short, unsigned char);
extern void input_block_reset_window_regs(unsigned char);

/*
 * The code of sys_channel0_apply_timing_block (which has its own file), compiled again here so that it is
 * inlined below: for port 0, hand a copy of the channel's input timing to SetFRCCHRW, then clear bits 21 and 22
 * of word +0x68 and toggle the pre-converter bit of input block 0. Other ports do nothing.
 */
inline void sys_channel0_apply_timing_block(unsigned char port, unsigned short width, unsigned short lines)
{
    struct channel_record *record;
    struct timing_block timing_copy_interlaced;
    struct timing_block timing_copy;

    record = sys_find_channel_by_port(port);
    if (port != 0)
        return;
    if ((sys_config & SYS_CONFIG_BIT25) && record->flags.f.path_owner && input_block_get_status_bit2(0) == 1) {
        /* The record's height instead of `lines`, with double_lines set; byte +0x68 is cleared. */
        memcpy(&timing_copy_interlaced, &record->u.a.timing, 0x3c);
        SetFRCCHRW(0, &timing_copy_interlaced, width, record->u.b.height, 1, 0, 0);
        record->word_0x68.b[0] = 0;
    } else {
        memcpy(&timing_copy, &record->u.a.timing, 0x3c);
        SetFRCCHRW(0, &timing_copy, width, lines, 0, 0, 0);
    }
    record->word_0x68.w &= ~WORD_0X68_BIT22;
    record->word_0x68.w &= ~WORD_0X68_BIT21;
    input_block0_toggle_pre_frc();
}

/*
 * Channel 0 only, when its input block's state flag is set: adjust the size handed on in *width / *lines.
 * When bit 4 of the converter register 0xCF011800 is set, the width is padded up to a multiple of 16 and the
 * height up to an even number, and start_x / start_y are pulled back so that start + size + padding stays within
 * half_0x0e / half_0x10 (half_0x10 counts twice when input block 0 reports status bit 2). Byte +0x68 of the
 * record always gets active_size1 of the active panel row * (lines added) * 110 / 100 / height, which is 0
 * when no line was added.
 */
static void adjust_channel0_size(unsigned short *width, unsigned short *lines)
{
    struct channel_record *record;
    unsigned char pad, odd;

    record = sys_find_channel_by_port(0);
    pad = 0;
    odd = 0;
    if (sys_frc_get_enable_bit4()) {
        pad = 0x10 - record->u.b.width % 16;
        pad %= 16;
        if (record->u.b.start_x + record->u.b.width + pad > record->u.b.half_0x0e)
            record->u.b.start_x = record->u.b.half_0x0e - record->u.b.width - pad;
        odd = record->u.b.height % 2;
        if (input_block_get_status_bit2(0)) {
            if (record->u.b.start_y + record->u.b.height + odd > record->u.b.half_0x10 * 2)
                record->u.b.start_y = record->u.b.half_0x10 * 2 - record->u.b.height - odd;
        } else {
            if (record->u.b.start_y + record->u.b.height + odd > record->u.b.half_0x10)
                record->u.b.start_y = record->u.b.half_0x10 - record->u.b.height - odd;
        }
    }
    *width = record->u.b.width + pad;
    *lines = record->u.b.height + odd;
    record->word_0x68.b[0] = panel_active_row.active_size1 * odd * 110u / 100 / record->u.b.height;
}

/*
 * Program the input block of `port` for the channel that shows that port: measurement, scaler, capture window,
 * the picture block 5 path, the converter window (channel 0) and the output size. Returns 1.
 *
 *   receiver     receiver index of the port's code (0xFF: none); only decides whether the two empty routines
 *                are called
 *   port         port number; the same number selects the input block, and the channel record is the one
 *                whose port field equals it (sys_find_channel_by_port)
 *   build_flag   passed on to sys_channel_fill_size_fields, which takes only the port
 *
 * Called by input_channel_bring_up_task in MODE_CAPTURE, with build_flag = 1 when the channel's restart field
 * is 0.
 *
 * Phases, in order:
 *   1. Signal code of the block (0xB1 stands for the port code behind sys_source_b1_block); the block's stored
 *      offset is set to 0. For a port of type 5: measure the active area and rebuild the channel's timing values (+0x12..+0x20).
 *   2. Callback slot 6, when one is registered: called with the number of the channel that shows the port, or
 *      0xFF when the port is above 3 or no channel shows it.
 *   3. Scaler: term = (half_0x10 - timing_height) * half_0x0e / 2. The scaling bit is switched off. When the
 *      position size differs from the timing size, the scaler ratio is written when term is above 0x1FFF
 *      (start_y - timing_start_y, or start_y when that would be negative) and bit 6 of register 6 is set.
 *      Otherwise a port whose code input_is_port_code_scalable accepts gets the scaling bit off again, and any
 *      other port the ratio 0 when term is above 0x1FFF.
 *   4. Size handed on: width x height, adjusted for channel 0 (adjust_channel0_size).
 *   5. Capture: input_block_set_capture_start gets that size; the capture set-up with half_0x0e and the timing size, in full units
 *      when csc_format_group_3 is 1 and bits 16..19 of the record pass sys_is_value_in_pip_limit, else in
 *      units of 4; a quarter of half_0x0e to register 0x41.
 *   6. Picture block 5 path: with sys_config bit 25, the channel holding the path selector and status bit 2 of
 *      the block, block 0xCF015B50 and picture block 5 are set up for the size and refresh rate, the path is
 *      switched on, and after 0x32 ticks the measured width is copied. Otherwise the path is switched off.
 *   7. start_x (less timing_start_x when the block's state flag is set) to input_block_set_capture_reg12,
 *      start_y to input_block_set_capture_reg0e; with flag bit 30 the low-resolution path.
 *   8. Converter window of channel 0 (sys_channel0_apply_timing_block, inlined).
 *   9. Output size: width (halved for a port above 3 when csc_format_group_3 is not 0) and the lines; then the
 *      block's window registers are reset.
 */
int sys_channel_apply_output_timing(unsigned char receiver, unsigned char port, unsigned char build_flag)
{
    struct channel_record *rec;
    struct channel_record *rec_again;
    unsigned char signal_code, call_empty_hooks, i, channel, found, term_large;
    unsigned int term;
    unsigned short lines;
    unsigned short width;

    /* Phase 1: signal code, measurement and timing values. */
    rec = sys_find_channel_by_port(port);
    signal_code = input_block_get_signal_code(port);
    call_empty_hooks = 0;
    if (signal_code == PORT_CODE_ROUTED)
        signal_code = sys_get_active_port_code();
    if (receiver != RECEIVER_NONE && (signal_code == 0x31 || signal_code == 0x41 || signal_code == 0x51 || signal_code == 0x61))
        call_empty_hooks = 1;
    input_block_set_offset(port, 0);
    if (input_get_port_sync_mode(port) == PORT_TYPE_5) {
        if (call_empty_hooks)
            sys_poll_events_stub_copy6(receiver, port);
        input_block_measure_active_area(port);
        sys_channel_fill_size_fields(port, build_flag);
        if (call_empty_hooks)
            sys_call_empty_hook(receiver);
    }

    /* Phase 2: callback slot 6 with the channel number. */
    if (sys_callback_table[CALLBACK_SLOT_6] != 0) {
        i = 0;
        found = 0;
        if (port < 4) {
            for (i = 0; i < 4; i++)
                if (port == ((channel_records[i].word0 >> 12) & 0xf))
                    break;
            if (i < 4) {
                channel = i;
                for (i = 0; i < 4; i++)
                    if (sys_check_channel_index(i) == channel) {
                        found = 1;
                        break;
                    }
            }
        }
        if (!found)
            i = CHANNEL_NONE;
        sys_callback_table[CALLBACK_SLOT_6](i);
    }

    /* Phase 3: scaler. */
    rec_again = sys_find_channel_by_port(port);
    term = (unsigned int)((rec_again->u.b.half_0x10 - rec_again->u.b.timing_height) * rec_again->u.b.half_0x0e) >> 1;
    term_large = 0;
    if (term > TERM_LIMIT)
        term_large = 1;
    input_block_disable_scaler(port);
    rec_again = sys_find_channel_by_port(port);
    if (rec_again->u.b.timing_width != rec_again->u.b.width || rec_again->u.b.timing_height != rec_again->u.b.height) {
        if (term_large) {
            if (rec_again->u.b.timing_start_y <= rec_again->u.b.start_y)
                input_block_enable_scaler_ratio(port, rec_again->u.b.start_y - rec_again->u.b.timing_start_y);
            else
                input_block_enable_scaler_ratio(port, rec_again->u.b.start_y);
        }
        input_block_set_reg6_bit6(port);
    } else {
        if (input_is_port_code_scalable(port) == 1)
            input_block_disable_scaler(port);
        else if (term_large)
            input_block_enable_scaler_ratio(port, 0);
    }

    /* Phase 4: the size handed on. */
    width = rec->u.b.width;
    lines = rec->u.b.height;
    if (port == 0 && input_block_get_reg6_bit6(0) == 1)
        adjust_channel0_size(&width, &lines);

    /* Phase 5: capture. */
    input_block_set_capture_start(port, width, lines);
    if (rec->u.b.csc_format_group_3 == 1 && sys_is_value_in_pip_limit(rec->u.b.bits_16_19))
        input_block_setup_capture(port, rec->u.b.half_0x0e, rec->u.b.timing_width, rec->u.b.timing_height);
    else
        input_block_setup_capture_quarter(port, rec->u.b.half_0x0e, rec->u.b.timing_width, rec->u.b.timing_height);
    input_block_set_reg41_quarter(port, rec->u.b.half_0x0e);

    /* Phase 6: picture block 5 path. */
    if ((sys_config & SYS_CONFIG_BIT25) && rec->flags.f.path_owner && input_block_get_status_bit2(port) == 1) {
        sys_set_block_5b50_size(width, lines);
        drv_Set3DDEISC(width, lines, rec->u.b.refresh_rate);
        sys_api_enable_selected_path(port);
        timer_sleep_ticks(PATH_ON_WAIT_TICKS);
        pq_block5_copy_htotal_readback();
    } else {
        sys_api_disable_selected_path(port);
    }

    /* Phase 7: start position and the low-resolution path. */
    if (input_block_get_reg6_bit6(port))
        input_block_set_capture_reg12(port, rec->u.b.start_x - rec->u.b.timing_start_x);
    else
        input_block_set_capture_reg12(port, rec->u.b.start_x);
    input_block_set_capture_reg0e(port, rec->u.b.start_y);
    if (rec->flags.w & CH_FLAG_BIT30)
        sys_setup_low_resolution_path(port, width, lines);

    /* Phase 8: converter window of channel 0. */
    sys_channel0_apply_timing_block(port, width, lines);

    /* Phase 9: output size (term is reused for the width). */
    if (rec->u.b.csc_format_group_3 != 0 && port > 3)
        term = rec->u.b.width >> 1;
    else
        term = rec->u.b.width;
    input_block_set_size_pair(port, term, lines, 0);
    input_block_reset_window_regs(port);
    return 1;
}
