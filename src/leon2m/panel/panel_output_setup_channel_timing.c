/* panel_output_setup_channel_timing  (FUN_a01038c0)
 *
 * Set up the display output timing for one channel.
 * Name basis: proven - vertical total from pixel clock, horizontal total and input refresh rate; prints
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01038c0 @ 0xa01038c0..0xa01042c8, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the first test keeps 'status_bit2 = input_block_get_status_bit2(port) ? 1 : 0; if (status_bit2 == 1)': the
 *    same test instruction as 'if (status_bit2)', but the '== 1' form lowers the block's estimated frequency and
 *    places it behind the re-check block, as in the firmware;
 *  - htotal_readback is an unsigned short; reg7c (the false arm) is an unsigned int, and in the true arm
 *    reg55_low is computed before register 0x55 is read;
 *  - saved_gamma and saved_spread are unsigned char (the write-back stores the low byte, the firmware's 'and 0xff');
 *  - input_block_set_capture_reg0e is declared void here; abs() is the builtin;
 *  - saved_start_y is read before input_block_set_offset(port, 0); the port test is written
 *    'port != (REG_CF01166C & 3)';
 *  - htotal, vtotal and out_lines live in one 16-byte local struct (frame slots fp-20 / -18 / -14), the timing
 *    copy at fp-88.
 */
#define R(a) (*(volatile unsigned int *)(a))

/* The input timing of a channel: the copy at +6 of the channel record (see input_api_get_timing_field). */
struct input_timing {
    unsigned short line_rate;           /* +0x00: in units of 100 Hz (timing field 0) */
    unsigned short refresh_rate;        /* +0x02: in tenths of a hertz (timing field 1) */
    unsigned char pad04[8];
    unsigned short half_0x0c;           /* +0x0C: timing field 7 */
    unsigned short half_0x0e;           /* +0x0E: timing field 8 */
    unsigned short half_0x10;           /* +0x10: timing field 9 */
    unsigned short active_lines;        /* +0x12: timing field 10 */
    unsigned short half_0x14;
    unsigned short capture_start_y;     /* +0x16: vertical start (channel record +0x1C), restored below */
    unsigned char rest[0x24];
};

/* The output timing of a channel (channel record +0x48). */
struct output_timing {
    unsigned short htotal;              /* +0x00: horizontal total, from panel_calc_output_pixel_clock */
    unsigned short width;               /* +0x02 */
    unsigned short half_0x04;
    unsigned short half_0x06, half_0x08;
    unsigned short lines;               /* +0x0A */
    unsigned short lines_part;          /* +0x0C */
    unsigned short half_0x0e;
    unsigned char pad10[8];
    unsigned long long pixel_clock;     /* +0x18: in Hz */
    unsigned int word_0x20;
};

/* The working copy of the active panel timing row (fields as in panel_output_apply_timing). */
struct panel_timing_row {
    unsigned char pad00[0xa];
    unsigned short active_size1;        /* +0xA: active lines */
    unsigned char pad0c[0x1e];
    unsigned short vtotal_min;          /* +0x2A: the smallest of the three vertical totals printed as 'Vtoal' */
    unsigned char pad2c[4];
    unsigned short half_0x30, half_0x32;
};
extern struct panel_timing_row *panel_working_row_ptr;

/* The output configuration record (0xA802D680); only the two arrays written here are declared. */
struct panel_output_config {
    unsigned char pad00[0x15];
    unsigned char block_reg7c_high[4];  /* +0x15: bits 4..7 of register 0x7C of picture blocks 0..3 */
    unsigned char byte_0x19;
    unsigned short block_reg77[4];      /* +0x1A: register 0x77 (bits 0..14) of picture blocks 0..3 */
};
extern struct panel_output_config panel_output_config_record;
extern unsigned char input_block_get_status_bit2(unsigned char);
extern unsigned char pq_block_read8(unsigned char blk, unsigned char reg);
extern void pq_block_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern void pq_block_write16(unsigned char blk, unsigned char reg, unsigned short val);
extern unsigned short pq_block_read16_stable(unsigned char blk, unsigned char reg);
extern unsigned short pq_block_read16(unsigned char blk, unsigned char reg);
extern void pq_block_update_bits(unsigned char blk, unsigned char reg, unsigned int mask, unsigned char set);
extern void input_capture_update_bits(unsigned char blk, unsigned char reg, unsigned int mask, unsigned char set);
extern unsigned char input_capture_read8(unsigned char blk, unsigned char reg);
extern unsigned short input_capture_read16(unsigned char blk, unsigned char reg);
extern void input_capture_write16(unsigned char blk, unsigned char reg, unsigned short val);
extern void input_block_set_offset(unsigned char blk, unsigned short v);
extern void input_block_set_capture_reg0e(unsigned char blk, unsigned short v);
extern void timer_wait_frames(unsigned char frames, unsigned short rate);
extern void *memcpy(void *dst, const void *src, int n);
extern int dbg_printf();

extern int abs(int);

#define REG_CF01166C       R(0xcf01166c)   /* bits 0..1 compared with the channel's port */
#define COLOR_FILL_CTRL    R(0xcf00e9c4)   /* bit 7: the colour-fill path (see pq_set_color_fill_enable) */
#define PQ_GAMMA_REG_EAC8  R(0xcf00eac8)   /* bit 4 is cleared while the colour-fill bit changes */
#define SPREAD_CTRL_BLOCK0 R(0xcf012890)   /* clock modulation, bit 0 = on */
#define SPREAD_CTRL_BLOCK1 R(0xcf012990)

/* Registers of a picture block. */
#define BLK_REG_50         0x50
#define BLK_REG_53         0x53
#define BLK_BLANK_MODE     0x54         /* blanking mode (see pq_block_blank) */
#define BLK_REG_55         0x55         /* bits 0..3: register 0x7C bits 4..7 plus 3; bit 7 with status bit 2 */
#define BLK_VTOTAL         0x5b
#define BLK_HTOTAL         0x5e
#define BLK_ROW_0X30_SUM   0x62         /* row +0x30 plus row +0x32 */
#define BLK_LINES          0x64
#define BLK_REG_6E         0x6e         /* 7; 0x47 when 0xDC and 0xDE still differ */
#define BLK_ROW_0X30_SUM_2 0x6f
#define BLK_REG_77         0x77
#define BLK_REG_7C         0x7c
#define BLK_HTOTAL_READBACK 0x82        /* a horizontal total read back from the block */
#define BLK_REG_88         0x88
#define BLK_REG_90         0x90         /* bit 5: set when the output window differs from the input's */
#define BLK_REG_DC         0xdc         /* the two values compared in the re-check */
#define BLK_REG_DE         0xde

/* Registers of an input capture block. */
#define CAP_REG_04         4            /* bits 0..3 choose the kind of re-check */
#define CAP_REG_0C         0xc          /* the two 16-bit values swapped by the second kind */
#define CAP_REG_0E         0xe
#define CAP_REG_56         0x56         /* bit 0: the two values are swapped */

#define CAPTURE_START_Y_PROBE 5         /* vertical start set while a capture offset is tried */
#define LOCK_WAIT_FRAMES    10

/*
 * Program the vertical and horizontal total of a channel's output into its picture block and, for an input
 * with status bit 2, re-check the block until its registers 0xDC and 0xDE agree.
 *
 *   port               the channel's port: the picture block (and input capture block) to program
 *   unused1            not used (the caller passes bits 8..11 of the channel word)
 *   channel_bit0       bit 0 of the channel word: the vertical total follows the panel row, and the colour-fill
 *                      bit is set around the re-check
 *   in                 the channel's input timing (a copy)
 *   out                the channel's output timing (a copy)
 *   unused5            not used (the caller passes bit 20 of the channel's flag word)
 *   skip_recheck_flag  bit 25 of the system configuration word AND bit 31 of the channel's flag word; with it
 *                      set the re-check is skipped for the port named in REG_CF01166C
 *
 * Called from input_channel_bring_up_task (state 8, step 2).
 *
 * The vertical total is pixel_clock / htotal / refresh rate, rounded. It is raised to more than the panel row's
 * +0x30 + +0x32 + active lines (channel_bit0) or to 16 above the block's own registers 0x62 + 0x64, and never
 * below the row's vtotal_min when register 0x64 equals the row's active lines.
 *
 * Re-check, kind 1 (capture register 4 bits 0..3 at most 1): with capture offsets 0, -1 and 1 in turn, wait ten
 * frames and stop at the first offset where registers 0xDC and 0xDE differ by at most 1; then the vertical start
 * is restored. Kind 2: the capture registers 0x0C / 0x0E are swapped when their order is wrong, and swapped
 * back when the two values move by more than 5 after bit 6 of register 0x6E is set. Clock modulation and the
 * block registers 0x50, 0x54, 0x88 are held off during the check and restored after it (the modulation of the
 * second block is switched off and not restored).
 */
void panel_output_setup_channel_timing(unsigned char port, int unused1, unsigned char channel_bit0, struct input_timing *in, struct output_timing *out, int unused5,
                  unsigned char skip_recheck_flag)
{
    struct { unsigned short pad0[2]; unsigned short htotal, vtotal, pad, out_lines; unsigned short pad1[2]; } disp;
    struct input_timing timing;
    unsigned short row_sum, block_lines, saved_start_y;
    unsigned char saved_gamma;
    unsigned char saved_spread;
    unsigned char status_bit2;
    unsigned char reg55_low, reg55;
    unsigned int reg7c;
    unsigned short htotal_readback;
    unsigned char saved_reg50, saved_blank_mode, saved_reg88;

    status_bit2 = input_block_get_status_bit2(port) ? 1 : 0;
    disp.htotal = out->htotal;
    disp.out_lines = out->lines;
    if (status_bit2 == 1) {
        pq_block_write8(port, BLK_REG_50, pq_block_read8(port, BLK_REG_50) & 0xdf);
    } else if (port == 1 && in->half_0x0c == 0xf00 && in->half_0x0e == 0x870 && in->half_0x10 == 0x108 && in->active_lines == 0x10e
               && in->refresh_rate > 0x640) {
        /* Port 1 with 3840 x 2160 at +0x0C/+0x0E, 0x108 / 0x10E at +0x10/+0x12 and above 160.0 Hz: as above. */
        pq_block_write8(port, BLK_REG_50, pq_block_read8(port, BLK_REG_50) & 0xdf);
    } else {
        /* Take the block's own horizontal total when it is within 4 of the computed one. */
        htotal_readback = pq_block_read16_stable(port, BLK_HTOTAL_READBACK);
        if ((unsigned int)(htotal_readback - disp.htotal + 4) <= 8) disp.htotal = htotal_readback;
    }
    disp.vtotal = ((out->pixel_clock * 100 / disp.htotal) / in->refresh_rate + 5) / 10;
    row_sum = pq_block_read16(port, BLK_ROW_0X30_SUM);
    block_lines = pq_block_read16(port, BLK_LINES);
    if (channel_bit0 && disp.vtotal <= panel_working_row_ptr->half_0x30 + panel_working_row_ptr->half_0x32 + panel_working_row_ptr->active_size1)
        disp.vtotal = panel_working_row_ptr->half_0x30 + panel_working_row_ptr->half_0x32 + panel_working_row_ptr->active_size1 + 1;
    else if (disp.vtotal <= row_sum + block_lines)
        disp.vtotal = row_sum + block_lines + 0x10;
    if (panel_working_row_ptr->active_size1 == block_lines && disp.vtotal < panel_working_row_ptr->vtotal_min) {
        dbg_printf("\033[1;33mwarning: (%d)display vtotal (%d) < (%d)\r\n", port, disp.vtotal, panel_working_row_ptr->vtotal_min);
        disp.vtotal = panel_working_row_ptr->vtotal_min;
    }
    pq_block_write16(port, BLK_VTOTAL, disp.vtotal);
    if (out->word_0x20 & 0x100000) {
        pq_block_write16(port, BLK_ROW_0X30_SUM, panel_working_row_ptr->half_0x30 + panel_working_row_ptr->half_0x32);
        pq_block_write16(port, BLK_ROW_0X30_SUM_2, panel_working_row_ptr->half_0x30 + panel_working_row_ptr->half_0x32 + (panel_working_row_ptr->active_size1 - disp.out_lines) / 2);
    }
    pq_block_write16(port, BLK_HTOTAL, disp.htotal);
    memcpy(&timing, in, 0x3c);
    pq_block_update_bits(port, BLK_REG_53, 0xf0, 0);
    if (port <= 3) {
        panel_output_config_record.block_reg7c_high[port] = pq_block_read8(port, BLK_REG_7C) >> 4;
        panel_output_config_record.block_reg77[port] = pq_block_read16_stable(port, BLK_REG_77) & 0x7fff;
    }
    if (input_block_get_status_bit2(port)) {
        pq_block_update_bits(port, BLK_REG_50, 0x40, 1);
        reg55_low = (pq_block_read8(port, BLK_REG_7C) >> 4) + 3;
        reg55 = pq_block_read8(port, BLK_REG_55);
        pq_block_write8(port, BLK_REG_55, reg55_low | (reg55 & 0xf0) | 0x80);
    } else {
        pq_block_update_bits(port, BLK_REG_50, 0x40, 1);
        reg7c = pq_block_read8(port, BLK_REG_7C);
        reg55 = pq_block_read8(port, BLK_REG_55);
        pq_block_write8(port, BLK_REG_55, (reg55 & 0xf0) | ((reg7c >> 4) + 3));
        pq_block_update_bits(port, BLK_REG_55, 0x80, 0);
    }
    if (port != (REG_CF01166C & 3) || skip_recheck_flag == 0) {
        memcpy(&timing, in, 0x3c);
        if (input_block_get_status_bit2(port)) {
            saved_blank_mode = pq_block_read8(port, BLK_BLANK_MODE);
            saved_reg50 = pq_block_read8(port, BLK_REG_50);
            saved_reg88 = pq_block_read8(port, BLK_REG_88);
            if (channel_bit0) {
                /* Colour fill on (the same steps as pq_set_color_fill_enable). */
                saved_gamma = PQ_GAMMA_REG_EAC8; PQ_GAMMA_REG_EAC8 = PQ_GAMMA_REG_EAC8 & ~0x10;
                COLOR_FILL_CTRL = COLOR_FILL_CTRL | 0x80;
                PQ_GAMMA_REG_EAC8 = saved_gamma;
            }
            pq_block_write8(port, BLK_BLANK_MODE, 0);
            saved_spread = SPREAD_CTRL_BLOCK0;
            SPREAD_CTRL_BLOCK0 = SPREAD_CTRL_BLOCK0 & ~1;
            SPREAD_CTRL_BLOCK1 = SPREAD_CTRL_BLOCK1 & ~1;
            if ((input_capture_read8(port, CAP_REG_04) & 0xf) <= 1) {
                /* Kind 1: try capture offsets 0, -1 and 1. */
                pq_block_write8(port, BLK_REG_6E, 7);
                saved_start_y = timing.capture_start_y;
                input_block_set_offset(port, 0);
                input_block_set_capture_reg0e(port, CAPTURE_START_Y_PROBE);
                timer_wait_frames(LOCK_WAIT_FRAMES, timing.refresh_rate);
                if (abs(pq_block_read16_stable(port, BLK_REG_DC) - pq_block_read16_stable(port, BLK_REG_DE)) > 1) {
                    input_block_set_offset(port, 0xffff);
                    input_block_set_capture_reg0e(port, CAPTURE_START_Y_PROBE);
                    timer_wait_frames(LOCK_WAIT_FRAMES, timing.refresh_rate);
                    if (abs(pq_block_read16_stable(port, BLK_REG_DC) - pq_block_read16_stable(port, BLK_REG_DE)) > 1) {
                        input_block_set_offset(port, 1);
                        input_block_set_capture_reg0e(port, CAPTURE_START_Y_PROBE);
                        timer_wait_frames(LOCK_WAIT_FRAMES, timing.refresh_rate);
                    }
                }
                input_block_set_capture_reg0e(port, saved_start_y);
                timer_wait_frames(LOCK_WAIT_FRAMES, timing.refresh_rate);
                if (abs(pq_block_read16_stable(port, BLK_REG_DC) - pq_block_read16_stable(port, BLK_REG_DE)) > 1)
                    pq_block_write8(port, BLK_REG_6E, 0x47);
            } else {
                /* Kind 2: put the capture values 0x0C / 0x0E in order and check again. */
                unsigned short lock_a, lock_b;
                if ((input_capture_read8(port, CAP_REG_04) & 3) == 3) {
                    pq_block_write8(port, BLK_REG_6E, 7);
                } else {
                    pq_block_write8(port, BLK_REG_6E, 7);
                    if (abs(input_capture_read16(port, CAP_REG_0C) - input_capture_read16(port, CAP_REG_0E)) <= 0) {
                        input_capture_update_bits(port, CAP_REG_56, 1, 0);
                    } else if ((input_capture_read8(port, CAP_REG_56) & 1) == 0) {
                        unsigned short value_0e, value_0c;
                        input_capture_update_bits(port, CAP_REG_56, 1, 1);
                        value_0e = input_capture_read16(port, CAP_REG_0E); value_0c = input_capture_read16(port, CAP_REG_0C);
                        input_capture_write16(port, CAP_REG_0E, value_0c); input_capture_write16(port, CAP_REG_0C, value_0e);
                    }
                    timer_wait_frames(LOCK_WAIT_FRAMES, timing.refresh_rate);
                    lock_a = pq_block_read16_stable(port, BLK_REG_DC);
                    lock_b = pq_block_read16_stable(port, BLK_REG_DE);
                    if (abs(pq_block_read16_stable(port, BLK_REG_DC) - pq_block_read16_stable(port, BLK_REG_DE)) > 1) {
                        pq_block_update_bits(port, BLK_REG_6E, 0x40, 1);
                        timer_wait_frames(LOCK_WAIT_FRAMES, timing.refresh_rate);
                        /* The readings moved by more than 5: swap the two values back. */
                        if (abs(lock_a - pq_block_read16_stable(port, BLK_REG_DC)) > 5 || abs(lock_b - pq_block_read16_stable(port, BLK_REG_DE)) > 5) {
                            unsigned short value_0e, value_0c;
                            value_0e = input_capture_read16(port, CAP_REG_0E); value_0c = input_capture_read16(port, CAP_REG_0C);
                            input_capture_write16(port, CAP_REG_0E, value_0c); input_capture_write16(port, CAP_REG_0C, value_0e);
                        }
                    }
                }
            }
            SPREAD_CTRL_BLOCK0 = saved_spread;
            pq_block_write8(port, BLK_BLANK_MODE, saved_blank_mode);
            pq_block_write8(port, BLK_REG_50, saved_reg50);
            pq_block_write8(port, BLK_REG_88, saved_reg88);
            if (channel_bit0) {
                /* Colour fill off again. */
                saved_gamma = PQ_GAMMA_REG_EAC8; PQ_GAMMA_REG_EAC8 = PQ_GAMMA_REG_EAC8 & ~0x10;
                COLOR_FILL_CTRL = COLOR_FILL_CTRL & ~0x80;
                PQ_GAMMA_REG_EAC8 = saved_gamma;
            }
        }
    }
    /* Bit 5 of register 0x90 is cleared only when the input's +0x10 / +0x12 equal the output's +0x04 / +0x0C. */
    if (in->half_0x10 == out->half_0x04 && in->active_lines == out->lines_part)
        pq_block_update_bits(port, BLK_REG_90, 0x20, 0);
    else
        pq_block_update_bits(port, BLK_REG_90, 0x20, 1);
}
