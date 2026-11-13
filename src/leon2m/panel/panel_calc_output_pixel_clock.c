/* panel_calc_output_pixel_clock  (FUN_a010325c)
 *
 * Compute the output pixel clock for a channel and program it.
 * Name basis: proven - output pixel clock calculation with prints; used by the bring-up state machine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010325c @ 0xa010325c-0xa0103808, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - -msoft-float (the firmware has no floating-point instructions at all): it fixes the 32 FP registers, which
 *    keeps the loads of disp.lines, disp.input_lines and FRC_CTRL inside the htotal loop, as in the firmware;
 *  - struct disp_timing starts with a 32-bit field, so its fields land at the firmware's frame offsets
 *    (fp-36 / -30 / -18 / -14 with a 136-byte frame);
 *  - panel_working_row_ptr is read through the pointer every time (no cached row local); link_type is a signed
 *    3-bit bitfield at bits 22..20, which gives the 'and 0x700000 / cmp 0x200000' form and makes the row's first
 *    word reload in every pass (the store to out->pixel_clock may alias it);
 *  - bit 14 of input +0x3A is a 1-bit unsigned short bitfield (gives the firmware's operand order of the test);
 *  - dbg_printf is declared 'int (const char *, ...)'; 'void' changes the argument set-up around both calls;
 *  - the three texts are the data labels DAT_0019a7d8 / DAT_0019a7f0 / DAT_0019a828.
 */

/* The input timing of a channel: the copy at +6 of the channel record (see input_api_get_timing_field). */
struct input_timing {
    unsigned short line_rate;           /* +0x00: in units of 100 Hz (timing field 0) */
    unsigned short refresh_rate;        /* +0x02: in tenths of a hertz (timing field 1) */
    unsigned short half_0x04, half_0x06;
    unsigned short half_0x08;           /* +0x08: timing field 4 */
    unsigned short half_0x0a;
    unsigned short half_0x0c, half_0x0e, half_0x10;
    unsigned short active_lines;        /* +0x12: picture lines of the input (timing field 10) */
    unsigned char pad14[0x26];
    unsigned short bit15 : 1, bit14 : 1, low_bits : 14;   /* +0x3A */
};

/* The output timing of a channel (channel record +0x48), filled in by the bring-up steps. */
struct output_timing {
    unsigned short htotal;              /* +0x00: horizontal total of the output, in pixels */
    unsigned short width;               /* +0x02: compared with the panel row's active width */
    unsigned short half_0x04, half_0x06, half_0x08;
    unsigned short lines;               /* +0x0A: written to the picture block's line register */
    unsigned short lines_part;          /* +0x0C: added to byte +0x20 for the second line register */
    unsigned short half_0x0e;
    unsigned char pad10[8];
    unsigned long long pixel_clock;     /* +0x18: in Hz; the firmware calls it poutputtiming->ulDisplayClk */
    unsigned char lines_extra;          /* +0x20 */
};

/* The values worked with here (the firmware prints the horizontal total as 'disp.htotal'). */
struct disp_timing {
    unsigned int word_0x00;
    unsigned short htotal, half_0x06, half_0x08;
    unsigned short lines;               /* output lines: out->lines_part + out->lines_extra */
    unsigned int word_0x0c;
    unsigned short half_0x10, half_0x12, half_0x14;
    unsigned short measured;            /* the value input_block_measure_pixel_clock returns; not used further */
    unsigned short half_0x18;
    unsigned short input_lines;         /* in->active_lines */
};

/* The working copy of the active panel timing row (fields as in panel_output_apply_timing). */
struct panel_timing_row {
    int flags_hi : 9, link_type : 3, flags_lo : 20;     /* +0: bits 20..22 = link type */
    unsigned short half_0x04;
    unsigned char display_mode;         /* +6 */
    unsigned char bpc;                  /* +7: bits per colour */
    unsigned short active_size0;        /* +8: active width in pixels */
    unsigned char pada[6];
    unsigned long long clk_min;         /* +0x10: the smaller of the two clock values printed as 'clk', in Hz */
    unsigned char pad18[8];
    unsigned short htotal_min;          /* +0x20: the three horizontal totals printed as 'Htoal' */
    unsigned short half_0x22;
    unsigned short htotal_max;          /* +0x24 */
};

extern struct panel_timing_row *panel_working_row_ptr;
extern unsigned char pq_block_read8(unsigned char port, unsigned char reg);
extern void pq_block_write8(unsigned char port, unsigned char reg, unsigned char val);
extern void pq_block_update_bits(unsigned char port, unsigned char reg, unsigned char mask, unsigned char set);
extern unsigned char input_block_get_status_bit2(unsigned char port);
extern unsigned short input_block_measure_pixel_clock(unsigned char port);
extern int dbg_printf(const char *fmt, ...);
extern const char DAT_0019a7d8[], DAT_0019a7f0[], DAT_0019a828[];
extern void pq_block_write16(unsigned char port, unsigned char reg, unsigned short val);
extern void panel_set_pll_frequency(unsigned char ch, unsigned int hz);
#define R(a) (*(volatile unsigned int *)(a))

/* Frame-rate converter registers. */
#define FRC_CTRL           R(0xcf011a00)
#define FRC_CHANNEL4_ON    0x10         /* bit 4: set by SetFRCCHRW when it turns converter channel 4 on */
#define FRC_REG_1CE0       R(0xcf011ce0)    /* low byte of a 16-bit value SetFRCCHRW writes */
#define FRC_REG_1CE4       R(0xcf011ce4)    /* its high byte */

/* Registers of a picture block. */
#define BLK_REG_50         0x50
#define BLK_REG_55         0x55
#define BLK_REG_6E         0x6e
#define BLK_LINES          0x64
#define BLK_LINES_2        0x71

#define HTOTAL_STEP        8            /* the horizontal total is searched in steps of 8 pixels */
#define MIN_HBLANK         0xe0         /* the search starts at least 224 pixels above the active width */
#define MIN_PIXEL_CLOCK    50000000     /* 50 MHz: the clock is never set lower */

/*
 * Work out the horizontal total and the pixel clock of a channel's output and program the clock generator.
 *
 *   port          the channel's port: the picture block and the clock generator to program
 *   unused        not used (the caller passes bit 0 of the channel record)
 *   frc_flag      bit 20 of the channel's flag word
 *   in            the channel's input timing
 *   out           the channel's output timing; htotal and pixel_clock are written back
 *
 * Called from input_channel_bring_up_task (state 8, step 1). Always returns 1.
 *
 * The pixel clock is the input line rate scaled to the output lines, times the horizontal total less a tenth of a
 * pixel. It is doubled when status bit 2 of the input block is set (unless frc_flag is set and bit 14 of
 * in +0x3A is set). For port 0 with the converter's channel 4 on and frc_flag set, it is scaled by
 * in +0x08 / (FRC_REG_1CE4:FRC_REG_1CE0). In every other case it is raised to a floor of
 * in +0x08 * in +0x0A * refresh_rate / 100, and at least 50 MHz; the horizontal total grows with it.
 */
unsigned int panel_calc_output_pixel_clock(unsigned char port, int unused, unsigned char frc_flag, struct input_timing *in, struct output_timing *out)
{
    struct disp_timing disp;
    unsigned short htotal_start, active_width;
    unsigned char double_clock;
    unsigned int line_pixels, floor_clock;

    pq_block_write8(port, BLK_REG_55, pq_block_read8(port, BLK_REG_55) & 0xf0);
    pq_block_update_bits(port, BLK_REG_50, 4, 1);
    pq_block_update_bits(port, BLK_REG_50, 0x20, 1);
    pq_block_write8(port, BLK_REG_6E, 7);
    disp.input_lines = in->active_lines;
    if (input_block_get_status_bit2(port) && (!frc_flag || !in->bit14))
        double_clock = 1;
    else
        double_clock = 0;
    disp.lines = out->lines_part + out->lines_extra;
    disp.htotal = out->htotal;
    disp.measured = input_block_measure_pixel_clock(port);
    active_width = panel_working_row_ptr->active_size0;
    htotal_start = panel_working_row_ptr->htotal_min;
    /* Keep at least 224 pixels of blanking; the start is a multiple of 8. */
    if (htotal_start < active_width + MIN_HBLANK)
        htotal_start = ((active_width + 0xe4) >> 3) << 3;     /* 224 + 4, rounded down to 8 */
    /* Port 0 at the panel row's active width: search the smallest horizontal total, from htotal_start towards
       htotal_max, whose pixel clock is above the row's clk_min. */
    if (port == 0 && out->width == active_width) {
        for (disp.htotal = htotal_start; disp.htotal < panel_working_row_ptr->htotal_max; disp.htotal += HTOTAL_STEP) {
            /* Link type 2 with display modes 8..10 takes only multiples of 16. */
            if (panel_working_row_ptr->link_type == 2 && (unsigned char)(panel_working_row_ptr->display_mode - 8) <= 2 && (disp.htotal & 0xf) != 0)
                continue;
            line_pixels = ((unsigned long long)disp.htotal * 100 - 10) * disp.lines / disp.input_lines / 100;
            out->pixel_clock = (unsigned int)(in->line_rate * line_pixels * 100);
            if (double_clock == 1)
                out->pixel_clock <<= 1;
            if ((FRC_CTRL & FRC_CHANNEL4_ON) && frc_flag)
                out->pixel_clock = out->pixel_clock * in->half_0x08 / (FRC_REG_1CE0 | FRC_REG_1CE4 << 8);
            if (out->pixel_clock > panel_working_row_ptr->clk_min)
                break;
        }
        if (disp.htotal > panel_working_row_ptr->htotal_max && disp.htotal > htotal_start)
            disp.htotal -= HTOTAL_STEP;
    }
    dbg_printf(DAT_0019a7d8, disp.htotal);     /* "disp.htotal  %ld" */
    out->htotal = disp.htotal;
    pq_block_write16(port, BLK_LINES, out->lines);
    pq_block_write16(port, BLK_LINES_2, disp.lines);

    /* The clock for the chosen horizontal total. */
    line_pixels = ((unsigned long long)disp.htotal * 100 - 10) * disp.lines / disp.input_lines / 100;
    if (line_pixels == 0)
        line_pixels = 1;
    out->pixel_clock = (unsigned int)(in->line_rate * line_pixels * 100);
    dbg_printf(DAT_0019a7f0, port, (unsigned int)out->pixel_clock);    /* "(%d)poutputtiming->ulDisplayClk Re calculate %ld" */
    if (double_clock == 1)
        out->pixel_clock <<= 1;
    if (port == 0 && (FRC_CTRL & FRC_CHANNEL4_ON) && frc_flag) {
        out->pixel_clock = out->pixel_clock * in->half_0x08 / (FRC_REG_1CE0 | FRC_REG_1CE4 << 8);
    } else {
        floor_clock = (unsigned int)in->half_0x08 * in->half_0x0a / 10 * in->refresh_rate / 10;
        if (floor_clock < MIN_PIXEL_CLOCK)
            floor_clock = MIN_PIXEL_CLOCK;
        /* Below the floor: raise the clock to it and the horizontal total in the same ratio. */
        if (out->pixel_clock < floor_clock) {
            out->htotal = (unsigned long long)out->htotal * floor_clock / out->pixel_clock;
            out->pixel_clock = floor_clock;
        }
    }
    dbg_printf(DAT_0019a828, port, (unsigned int)out->pixel_clock);    /* "(%d)poutputtiming->ulDisplayClk final %ld" */
    panel_set_pll_frequency(port, (unsigned int)out->pixel_clock);
    return 1;
}
