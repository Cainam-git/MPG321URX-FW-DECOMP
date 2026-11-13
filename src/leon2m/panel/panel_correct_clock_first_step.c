/* panel_correct_clock_first_step  (FUN_a0104380)
 *
 * Correct the output clock from measured counts (first step).
 * Name basis: derived - reads two fields of the working panel timing row; used by the bring-up state machine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0104380 @ 0xa0104380-0xa01045a0 (544 bytes), flags -mcpu=v8 -O3 -g (the build also matches with
 * -msoft-float added, and with -O3 alone).
 * Source forms the exact build depends on:
 *  - block_lines and reg84 are int: the callee returns an unsigned short that is zero-extended right after the
 *    call; an unsigned short variable gives other registers;
 *  - correction is a short (gives the shift in the second division).
 */
#define R(a) (*(volatile unsigned int *)(a))

#define COLOR_FILL_CTRL    R(0xcf00e9c4)   /* bit 7: the colour-fill path (see pq_set_color_fill_enable) */
#define PQ_GAMMA_REG_EAC8  R(0xcf00eac8)   /* bit 4 is cleared while the colour-fill bit changes */

#define GPLL_DISPM         0               /* clock generator of the main display output */

/* Registers of a picture block. */
#define BLK_REG_50         0x50
#define BLK_BLANK_MODE     0x54         /* blanking mode (see pq_block_blank) */
#define BLK_LINES          0x64
#define BLK_LINES_2        0x71
#define BLK_HTOTAL_READBACK 0x82        /* a horizontal total read back from the block */
#define BLK_REG_84         0x84
#define BLK_REG_86         0x86
#define BLK_COUNT_SELECT   0x88         /* selects what register 0x89 reads (see the second step) */

/* The working copy of the active panel timing row (fields as in panel_output_apply_timing). */
struct panel_timing_row {
  unsigned int flags;
  unsigned short half_0x04;
  unsigned char display_mode;
  unsigned char bpc;
  unsigned short active_size0;          /* +8: active width in pixels */
  unsigned short active_size1;          /* +0xA: active lines */
  unsigned char byte_0x0c[4];
  unsigned long long clk_min;           /* +0x10: the two clock values printed as 'clk' */
  unsigned long long clk_max;           /* +0x18 */
  unsigned short htotal_min;            /* +0x20: the three horizontal totals printed as 'Htoal' */
  unsigned short half_0x22;
  unsigned short htotal_max;            /* +0x24 */
};
extern struct panel_timing_row *panel_working_row_ptr;
extern unsigned char panel_clock_saved_reg50, panel_clock_saved_reg88, panel_clock_saved_reg86;
extern unsigned char pq_block_read8(unsigned char blk, unsigned char reg);
extern void pq_block_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern unsigned short pq_block_read16(unsigned char blk, unsigned char reg);
extern void pq_block_write16(unsigned char blk, unsigned char reg, unsigned short val);
extern unsigned short pq_block_read16_stable(unsigned char blk, unsigned char reg);
extern void pq_port_set_reg10_bit0();
extern void panel_set_pll_frequency(unsigned char ch, unsigned int freq);

/*
 * First of the two clock corrections after a channel's output is set up: prepare the picture block for the
 * measurement and correct the pixel clock once from the block's read-back values.
 *
 *   port         the channel's port: the picture block
 *   pixel_clock  the channel's output pixel clock in Hz (output timing +0x18); corrected in place
 *
 * Called from input_channel_bring_up_task (state 8, step 3); panel_correct_clock_second_step follows in the next
 * step and puts back the three registers saved here (0x50 into panel_clock_saved_reg50, 0x86 into panel_clock_saved_reg86,
 * 0x88 into panel_clock_saved_reg88).
 *
 * The correction is applied only when the horizontal total read back lies within the panel row's htotal_min ..
 * htotal_max; the corrected clock always goes to the main display clock generator (GPLL_DISPM), whatever the port.
 */
void panel_correct_clock_first_step(unsigned char port, unsigned long long *pixel_clock)
{
    unsigned int saved_gamma;
    int block_lines, reg84;
    unsigned short htotal_readback;
    int reg84_x10, lines_x9;
    short correction;

    panel_clock_saved_reg50 = pq_block_read8(port, BLK_REG_50);
    panel_clock_saved_reg86 = pq_block_read8(port, BLK_REG_86);
    panel_clock_saved_reg88 = pq_block_read8(port, BLK_COUNT_SELECT);
    /* Colour fill on (the same steps as pq_set_color_fill_enable). */
    saved_gamma = PQ_GAMMA_REG_EAC8;
    PQ_GAMMA_REG_EAC8 &= ~0x10;
    COLOR_FILL_CTRL |= 0x80;
    PQ_GAMMA_REG_EAC8 = saved_gamma & 0xff;
    pq_port_set_reg10_bit0(port, 0);
    pq_block_write8(port, BLK_BLANK_MODE, 0);
    /* The second line register's value goes into the first. */
    block_lines = pq_block_read16(port, BLK_LINES_2);
    pq_block_write16(port, BLK_LINES, block_lines);
    pq_block_write8(port, BLK_REG_50, panel_clock_saved_reg50 | 0x20);

    /* correction = reg84 - 0.9 * lines when that is positive, else reg84 + 0.1 * lines. */
    reg84 = pq_block_read16_stable(port, BLK_REG_84);
    reg84_x10 = reg84 * 10;
    lines_x9 = block_lines * 9;
    if (reg84_x10 > lines_x9) correction = (reg84_x10 - lines_x9) / 10;
    else correction = (reg84_x10 + block_lines) / 10;
    htotal_readback = pq_block_read16_stable(port, BLK_HTOTAL_READBACK);
    if (panel_working_row_ptr->htotal_min <= htotal_readback && htotal_readback <= panel_working_row_ptr->htotal_max) {
        *pixel_clock -= (int)(*pixel_clock * correction * 100 / block_lines / htotal_readback / 100);
        panel_set_pll_frequency(GPLL_DISPM, *pixel_clock);
    }
    pq_block_write8(port, BLK_REG_86, 1);
    pq_block_write8(port, BLK_COUNT_SELECT, 6);
}
