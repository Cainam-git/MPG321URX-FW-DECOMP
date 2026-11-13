/* sys_frc_setup_lock  (FUN_a0109bbc)
 *
 * Set the frame-rate converter up for locked or free-running output.
 * Name basis: proven - FRC lock / free-run set-up from the working panel timing row; prints
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0109bbc @ 0xa0109bbc, flags -mcpu=v8 -O3 -g -msoft-float (see CONSTANTS below). __gtsf2 =
 * __gtsf2.
 * Source forms the exact build depends on:
 *  - the free-run chain has a separate reg_write16_bytes(FRC_V_PART1, ...) call in every branch (the compiler
 *    merges them and puts the three bodies out of line);
 *  - the four part reads go into unsigned short locals;
 *  - explicit (float) casts on unsigned short values (panel_get_pll_frequency_mhz(), block_offsets, output_lines) give the
 *    signed convert + 65536.0 fix-up, while the divisors are promoted to int (zero-extend, no fix-up);
 *  - 'block_offsets < active_lines' (not 'active_lines > block_offsets') gives the bgu;
 *  - active_lines is read from the row at entry on every path.
 * CONSTANTS: 1e6, 0.0, 5.0, 16.0 (0x19ACCC..ACD8, in this order) and 10.0 (0x198760) / 65536.0 (0x19A2D0) are the
 * literal-pool entries of this file after the linker merged .rodata.cst4 across the program (10.0 and 65536.0
 * already existed). The build places .rodata.cst4 as one block, so this file's own pool is not placed at those
 * addresses; the same code with the five constants named by their firmware addresses links with only 65536.0 left in
 * .rodata.cst4 at 0x19A2D0, and its .text and relocations equal this file's entry for entry.
 */

/* The working copy of the active panel timing row (fields as in panel_output_apply_timing). */
struct panel_timing_row
{
  unsigned int flags;                   /* +0: bits 20..22 link type */
  unsigned short half_0x04;
  unsigned char display_mode;           /* +6 */
  unsigned char bpc;                    /* +7 */
  unsigned short active_size0;          /* +8: active width */
  unsigned short active_size1;          /* +0xA: active lines */
  unsigned char byte_0x0c[4];
  unsigned long long clk_min;           /* +0x10 */
  unsigned long long clk_max;           /* +0x18 */
  unsigned short htotal_min;            /* +0x20 */
  unsigned short half_0x22;
  unsigned short htotal_max;            /* +0x24 */
  unsigned short hblank_part;           /* +0x26 */
  unsigned short hblank_part2;          /* +0x28 */
  unsigned short vtotal_min;            /* +0x2A */
  unsigned short vtotal;                /* +0x2C */
};

/* Frame-rate converter registers (names as in FRCConfigPostFRC). */
#define FRC_REG_1A80        (*(volatile unsigned int *)0xcf011a80)
#define FRC_1A80_PARTS      0x80        /* bit 7: the output line is given in four parts (FRC_H_PART0..3) */
#define FRC_MODE_REG        (*(volatile unsigned int *)0xcf011c04)
#define FRC_MODE_FREE_RUN   0x60
#define FRC_MODE_LOCK       0xa0
#define FRC_V_SCALE_REG     (*(volatile unsigned int *)0xcf011e40)
#define FRC_V_SCALE_8       0x2         /* bit 1: the frame parts are stored divided by 8 */
#define FRC_V_SCALE_4       0x4         /* bit 2: divided by 4 */
#define FRC_V_SCALE_2       0x8         /* bit 3: divided by 2 */
#define FRC_REG_1EC0        (*(volatile unsigned int *)0xcf011ec0)
#define FRC_1EC0_LOCK       0x40        /* bit 6: set in lock mode, cleared for free run; bits 0..5 = lock
                                           offset bits 8..13 */
#define FRC_REG_1EC4        (*(volatile unsigned int *)0xcf011ec4)     /* lock offset bits 0..7 */

/* 16-bit register pairs (reg_write16_bytes / reg_read16_bytes). */
#define FRC_H_PART0         0xcf011ac0
#define FRC_H_PART1         0xcf011ac8
#define FRC_H_PART2         0xcf011ad0
#define FRC_H_PART3         0xcf011ad8
#define FRC_V_PART1         0xcf011ae8
#define FRC_LINE_LENGTH     0xcf011c20
#define FRC_FRAME_LENGTH    0xcf011c38
#define FRC_REG_1C48        0xcf011c48  /* the lock offset in lock mode */

/* Registers of picture block 0, the main picture. */
#define MAIN_CHANNEL        0
#define BLK_REG_62          0x62
#define BLK_LINES           0x64
#define BLK_HTOTAL_READBACK 0x82

#define GPLL_DISPM          0           /* clock generators (panel_get_pll_frequency_mhz) */
#define GPLL_FRC            4

#define LOCK_FRAME_LENGTH   0x3fff      /* frame length written in lock mode */

extern struct panel_timing_row *panel_working_row_ptr;
extern unsigned short sys_frc_post_frame_remainder;
extern int dbg_printf();
extern void panel_wait_sync_pulse(void);
extern void reg_write16_bytes(unsigned int, unsigned int);
extern int reg_read16_bytes(int);
extern unsigned short pq_block_read16(unsigned char, unsigned char);
extern unsigned short panel_get_pll_frequency_mhz(unsigned char);
extern unsigned char sys_get_chip_revision(void);

/*
 * Put the frame-rate converter output into lock mode or into free run (the firmware's prints 'lock mode' and
 * 'FRC freerun mode').
 *
 *   lock          1: lock mode; 0: free run
 *   unused        not read
 *   output_lines  lock mode only: the lines_part of the channel's output timing
 *   refresh_rate  in tenths of a hertz
 *
 * Called with lock = 1 by input_channel_bring_up_task ('FRC Lock'), and with lock = 0 by the same task
 * ('FRC Free Run'), panel_api_reapply_nominal_rate, sys_mode_restart_channel (channel 0) and System_Initialize.
 *
 * Phases, lock mode:
 *  1. Wait for a sync pulse; frame length = 0x3FFF.
 *  2. Lines per frame on both sides: main side = DISPM clock / line length read back from block 0 /
 *     refresh rate; converter side = FRC clock / converter line length / refresh rate.
 *  3. The lock offset: the difference of the two frame fractions (block 0 lines over main frame, output_lines over
 *     converter frame), in main-side lines, plus a margin of 5 (single line length) or 16 (four-part line);
 *     the margin alone when the difference is not positive, and at most the main frame less the margin. With
 *     the four-part line, when block 0 has fewer lines than the row's active lines, the lock offset is half of
 *     block 0's lines.
 *  4. Print 'lock mode', write the lock offset and the lock-mode values.
 * Free run: free-run mode value; frame length and FRC_REG_1C48 = the row's vtotal; FRC_V_PART1 = the frame
 * remainder FRCConfigPostFRC kept (sys_frc_post_frame_remainder), divided by the scale that is set, which also
 * clears the other two scale bits; lock bit off.
 */
void sys_frc_setup_lock(unsigned char lock, unsigned char unused, unsigned short output_lines, unsigned short refresh_rate)
{
  unsigned short active_lines = panel_working_row_ptr->active_size1;
  unsigned short main_frame_lines, frc_frame_lines, block_offsets_62, block_offsets, line_length, lock_offset;
  float difference;
  unsigned short part0, part1, part2, part3;

  if (lock != 0) {
    /* 1. */
    panel_wait_sync_pulse();
    reg_write16_bytes(FRC_FRAME_LENGTH, LOCK_FRAME_LENGTH);
    if ((FRC_REG_1A80 & FRC_1A80_PARTS) == 0) {
      /* 2. and 3. with the single line length. */
      main_frame_lines = (float)panel_get_pll_frequency_mhz(GPLL_DISPM) * 1000000.0f / pq_block_read16(MAIN_CHANNEL, BLK_HTOTAL_READBACK) * 10.0f / refresh_rate;
      block_offsets = pq_block_read16(MAIN_CHANNEL, BLK_LINES);
      line_length = reg_read16_bytes(FRC_LINE_LENGTH);
      frc_frame_lines = (float)panel_get_pll_frequency_mhz(GPLL_FRC) * 1000000.0f / line_length * 10.0f / refresh_rate;
      difference = (float)block_offsets / main_frame_lines - (float)output_lines / frc_frame_lines;
      if (difference > 0.0f) {
        lock_offset = main_frame_lines * difference + 5.0f;
        if (lock_offset > main_frame_lines - 5) lock_offset = main_frame_lines - 5;
      } else {
        lock_offset = 5;
      }
    } else {
      /* 2. and 3. with the line in four parts. */
      main_frame_lines = (float)panel_get_pll_frequency_mhz(GPLL_DISPM) * 1000000.0f / pq_block_read16(MAIN_CHANNEL, BLK_HTOTAL_READBACK) * 10.0f / refresh_rate;
      block_offsets_62 = pq_block_read16(MAIN_CHANNEL, BLK_REG_62);
      block_offsets = pq_block_read16(MAIN_CHANNEL, BLK_LINES);
      part0 = reg_read16_bytes(FRC_H_PART0);
      part1 = reg_read16_bytes(FRC_H_PART1);
      part2 = reg_read16_bytes(FRC_H_PART2);
      part3 = reg_read16_bytes(FRC_H_PART3);
      line_length = part0 + part1 + part2 + part3;
      frc_frame_lines = (float)panel_get_pll_frequency_mhz(GPLL_FRC) * 1000000.0f / line_length * 10.0f / refresh_rate;
      difference = (float)(block_offsets_62 + block_offsets) / main_frame_lines - (float)output_lines / frc_frame_lines;
      if (difference > 0.0f) {
        lock_offset = main_frame_lines * difference + 16.0f;
        if (lock_offset > main_frame_lines - 16) lock_offset = main_frame_lines - 16;
      } else {
        lock_offset = 16;
      }
      if (block_offsets < active_lines) {
        lock_offset = block_offsets >> 1;
        dbg_printf("%x,%x\r\n", block_offsets, lock_offset);
      }
    }
    /* 4. */
    dbg_printf("lock mode %x,%x,%x,%x\r\n", block_offsets, main_frame_lines, frc_frame_lines, lock_offset);
    reg_write16_bytes(FRC_REG_1C48, lock_offset);
    FRC_MODE_REG = FRC_MODE_LOCK;
    reg_write16_bytes(FRC_V_PART1, 0xffff);
    FRC_REG_1EC4 = lock_offset & 0xff;
    FRC_REG_1EC0 = (lock_offset >> 8) & 0x3f | FRC_1EC0_LOCK;
  } else {
    dbg_printf("FRC freerun mode\r\n");
    FRC_MODE_REG = FRC_MODE_FREE_RUN;
    reg_write16_bytes(FRC_FRAME_LENGTH, panel_working_row_ptr->vtotal);
    reg_write16_bytes(FRC_REG_1C48, panel_working_row_ptr->vtotal);
    /* The remainder part in the scale FRCConfigPostFRC chose (same revision tests as
       sys_frc_get_output_frame_length). */
    if (sys_get_chip_revision() > 0x82 && (FRC_V_SCALE_REG & FRC_V_SCALE_2)) {
      FRC_V_SCALE_REG &= ~(FRC_V_SCALE_8 | FRC_V_SCALE_4);
      reg_write16_bytes(FRC_V_PART1, sys_frc_post_frame_remainder >> 1);
    } else if (sys_get_chip_revision() > 0x83 && (FRC_V_SCALE_REG & FRC_V_SCALE_4)) {
      FRC_V_SCALE_REG &= ~(FRC_V_SCALE_8 | FRC_V_SCALE_2);
      reg_write16_bytes(FRC_V_PART1, sys_frc_post_frame_remainder >> 2);
    } else if (sys_get_chip_revision() > 0x83 && (FRC_V_SCALE_REG & FRC_V_SCALE_8)) {
      FRC_V_SCALE_REG &= ~(FRC_V_SCALE_4 | FRC_V_SCALE_2);
      reg_write16_bytes(FRC_V_PART1, sys_frc_post_frame_remainder >> 3);
    } else {
      reg_write16_bytes(FRC_V_PART1, sys_frc_post_frame_remainder);
    }
    FRC_REG_1EC0 &= ~FRC_1EC0_LOCK;
  }
}
