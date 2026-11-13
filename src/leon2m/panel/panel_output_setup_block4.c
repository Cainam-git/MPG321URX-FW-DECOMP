/* panel_output_setup_block4  (FUN_a01062e0)
 *
 * Set up output block 4 from the working panel timing row.
 * Name basis: derived - FRC output timing: full or reduced register set; used by the bring-up state machine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01062e0 @ 0xa01062e0, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - in the full recipe the row fields are loaded into locals in the order shown, the width into a temporary
 *    early (width_early) and hblank_part last;
 *  - pq_block_read16 returns unsigned short, the two sys_frc_get_output_active_* routines return int, and
 *    source_width / source_lines are int;
 *  - the converter test is written with the 'running' arm first.
 */
#define R(a) (*(volatile unsigned int *)(a))

/* The working copy of the active panel timing row (fields as in panel_output_apply_timing). */
struct panel_timing_row {
    unsigned int flags;                 /* +0: bits 20..22 link type */
    unsigned short half_0x04;
    unsigned char display_mode, bpc;    /* +6 / +7 */
    unsigned short active_size0, active_size1;  /* +8 / +0xA: active width and lines */
    unsigned char pad0c[0x14];
    unsigned short htotal_min, half_0x22;       /* +0x20 / +0x22: smallest and middle horizontal total */
    unsigned char pad24[2];
    unsigned short hblank_part, hblank_part2;   /* +0x26 / +0x28 */
    unsigned short vtotal_min, vtotal, vtotal_max;  /* +0x2A..+0x2E */
    unsigned short half_0x30, half_0x32;
};
extern struct panel_timing_row *panel_working_row_ptr;
extern unsigned char sys_frc_is_running(void);
extern unsigned short pq_block_read16(int, int);
extern int sys_frc_get_output_active_height(void);
extern int sys_frc_get_output_active_width(void);
extern void pq_block_write16(unsigned char, unsigned char, unsigned short);
extern void pq_block_write8(unsigned char, unsigned char, unsigned char);
extern void pq_block_update_bits(unsigned char, unsigned char, unsigned int, unsigned char);

#define BLOCK4             4            /* the picture block programmed here */
#define MAIN_CHANNEL       0            /* block 0: the main picture */

/* Bits 20..22 of the row's first word: link type. */
#define ROW_LINK_TYPE_MASK 0x700000
#define ROW_LINK_TYPE_2    0x200000

/* Registers of a picture block (names as in panel_output_apply_timing). */
#define BLK_SOURCE_LINES   0x18
#define BLK_SOURCE_WIDTH   0x1a
#define BLK_REG_50         0x50
#define BLK_BLANK_MODE     0x54
#define BLK_VTOTAL         0x5b
#define BLK_HTOTAL         0x5e
#define BLK_REG_61         0x61
#define BLK_ROW_0X30_SUM   0x62
#define BLK_LINES          0x64
#define BLK_HBLANK_SUM     0x66
#define BLK_WIDTH          0x68
#define BLK_REG_6E         0x6e
#define BLK_ROW_0X30_SUM_2 0x6f
#define BLK_LINES_2        0x71
#define BLK_HBLANK_SUM_2   0x73
#define BLK_WIDTH_2        0x75
#define BLK_HTOTAL_2       0x79
#define BLK_REG_86         0x86
#define BLK_COUNT_SELECT   0x88
#define BLK_REG_8D         0x8d
#define BLK_HBLANK_PART    0xa0
#define BLK_ROW_0X31       0xbe

/* Output registers. */
#define OUT_SIZE_REG_EC00  R(0xcf00ec00)
#define OUT_SIZE_REG_EC04  R(0xcf00ec04)
#define OUT_SIZE_REG_EC08  R(0xcf00ec08)
#define OUT_SIZE_REG_EC0C  R(0xcf00ec0c)
#define OUT_WIDTH_LOW      R(0xcf00ec10)
#define OUT_WIDTH_HIGH     R(0xcf00ec14)
#define OUT_SIZE_REG_EC18  R(0xcf00ec18)
#define OUT_SIZE_REG_EC1C  R(0xcf00ec1c)
#define OUT_LINES_LOW      R(0xcf00ec20)
#define OUT_LINES_HIGH     R(0xcf00ec24)
#define OUT_REG_ED80       R(0xcf00ed80)

/*
 * Program picture block 4 with the timing of the active panel row.
 *
 *   unused       not used (the caller passes the active row's rate field)
 *   full_timing  not 0: the row's vertical total, its middle horizontal total and its +0x30 values;
 *                0: the row's smallest totals, with 1 and 2 in place of the +0x30 values
 *
 * The source size comes from the frame-rate converter's output when the converter runs, else from block 0's
 * registers. In the full recipe both source registers get the line count (the converter's active height, or
 * block 0's line register, read twice). input_channel_bring_up_task calls it with full_timing 0 for channel 0.
 *
 * Both recipes end with the output size registers (row width and lines, low byte and bits 8..12) and 0xCF00ED80;
 * the reduced recipe sets 0xCF00ED80 (and block 4's register 0x8D) only for link type 2 with display modes 8..10.
 */
void panel_output_setup_block4(int unused, unsigned char full_timing)
{
    int source_width, source_lines;
    unsigned short hblank_part, row_0x30, row_0x32, htotal, width_early, vtotal, hblank_part2, lines, width, htotal_min, vtotal_min;
    if (full_timing) {
        if (sys_frc_is_running()) { source_width = sys_frc_get_output_active_height(); source_lines = sys_frc_get_output_active_height(); }
        else { source_width = pq_block_read16(MAIN_CHANNEL, BLK_LINES); source_lines = pq_block_read16(MAIN_CHANNEL, BLK_LINES); }
        /* Row fields in the order the firmware loads them. */
        row_0x30 = panel_working_row_ptr->half_0x30; row_0x32 = panel_working_row_ptr->half_0x32; width_early = panel_working_row_ptr->active_size0; htotal = panel_working_row_ptr->half_0x22;
        vtotal = panel_working_row_ptr->vtotal; hblank_part2 = panel_working_row_ptr->hblank_part2; lines = panel_working_row_ptr->active_size1; hblank_part = panel_working_row_ptr->hblank_part;
        width = width_early;
        pq_block_write16(BLOCK4, BLK_SOURCE_LINES, source_lines);
        pq_block_write16(BLOCK4, BLK_SOURCE_WIDTH, source_width);
        pq_block_write8(BLOCK4, BLK_REG_61, 0x12);
        pq_block_write8(BLOCK4, BLK_BLANK_MODE, 0);
        pq_block_write16(BLOCK4, BLK_VTOTAL, vtotal);
        pq_block_write16(BLOCK4, BLK_ROW_0X31, row_0x30);
        pq_block_write16(BLOCK4, BLK_HTOTAL, htotal);
        pq_block_write16(BLOCK4, BLK_HBLANK_PART, hblank_part);
        pq_block_write16(BLOCK4, BLK_ROW_0X30_SUM, (unsigned short)(row_0x30 + row_0x32));
        pq_block_write16(BLOCK4, BLK_LINES, lines);
        pq_block_write16(BLOCK4, BLK_HBLANK_SUM, (unsigned short)(hblank_part + hblank_part2));
        pq_block_write16(BLOCK4, BLK_WIDTH, width);
        pq_block_write16(BLOCK4, BLK_ROW_0X30_SUM_2, (unsigned short)(row_0x30 + row_0x32));
        pq_block_write16(BLOCK4, BLK_LINES_2, lines);
        pq_block_write16(BLOCK4, BLK_HBLANK_SUM_2, (unsigned short)(hblank_part + hblank_part2));
        pq_block_write16(BLOCK4, BLK_WIDTH_2, width);
        pq_block_write16(BLOCK4, BLK_HTOTAL_2, htotal);
        pq_block_write16(BLOCK4, BLK_ROW_0X31, row_0x30);
        pq_block_write8(BLOCK4, BLK_REG_6E, 1);
        pq_block_write8(BLOCK4, BLK_COUNT_SELECT, 0x11);
        pq_block_write8(BLOCK4, BLK_REG_86, 0x18);
        OUT_SIZE_REG_EC04 = 0; OUT_SIZE_REG_EC08 = 0; OUT_SIZE_REG_EC0C = 0;
        OUT_WIDTH_LOW = width & 0xff; OUT_WIDTH_HIGH = (width >> 8) & 0x1f;
        OUT_SIZE_REG_EC18 = 0; OUT_SIZE_REG_EC1C = 0;
        OUT_LINES_LOW = lines & 0xff; OUT_LINES_HIGH = (lines >> 8) & 0x1f;
        OUT_SIZE_REG_EC00 = 9;
        OUT_REG_ED80 = 0x10;
    } else {
        if (sys_frc_is_running()) { source_width = sys_frc_get_output_active_width(); source_lines = sys_frc_get_output_active_height(); }
        else { source_width = pq_block_read16(MAIN_CHANNEL, BLK_WIDTH); source_lines = pq_block_read16(MAIN_CHANNEL, BLK_LINES); }
        hblank_part = panel_working_row_ptr->hblank_part; htotal_min = panel_working_row_ptr->htotal_min; vtotal_min = panel_working_row_ptr->vtotal_min; width = panel_working_row_ptr->active_size0;
        hblank_part2 = panel_working_row_ptr->hblank_part2; lines = panel_working_row_ptr->active_size1;
        pq_block_write16(BLOCK4, BLK_SOURCE_LINES, source_lines);
        pq_block_write16(BLOCK4, BLK_SOURCE_WIDTH, source_width);
        pq_block_write8(BLOCK4, BLK_REG_61, 0x12);
        pq_block_write8(BLOCK4, BLK_BLANK_MODE, 0);
        pq_block_write16(BLOCK4, BLK_VTOTAL, vtotal_min);
        pq_block_write16(BLOCK4, BLK_ROW_0X31, 1);
        pq_block_write16(BLOCK4, BLK_HTOTAL, htotal_min);
        pq_block_write16(BLOCK4, BLK_HBLANK_PART, hblank_part);
        pq_block_write16(BLOCK4, BLK_ROW_0X30_SUM, 2);
        pq_block_write16(BLOCK4, BLK_LINES, lines);
        pq_block_write16(BLOCK4, BLK_HBLANK_SUM, (unsigned short)(hblank_part + hblank_part2));
        pq_block_write16(BLOCK4, BLK_WIDTH, width);
        pq_block_write16(BLOCK4, BLK_ROW_0X30_SUM_2, 2);
        pq_block_write16(BLOCK4, BLK_LINES_2, lines);
        pq_block_write16(BLOCK4, BLK_HBLANK_SUM_2, (unsigned short)(hblank_part + hblank_part2));
        pq_block_write16(BLOCK4, BLK_WIDTH_2, width);
        pq_block_write16(BLOCK4, BLK_HTOTAL_2, htotal_min);
        pq_block_write16(BLOCK4, BLK_ROW_0X31, 1);
        pq_block_update_bits(BLOCK4, BLK_REG_50, 0x20, 0);
        pq_block_write8(BLOCK4, BLK_REG_6E, 1);
        pq_block_write8(BLOCK4, BLK_COUNT_SELECT, 0x11);
        pq_block_write8(BLOCK4, BLK_REG_86, 0x18);
        OUT_SIZE_REG_EC04 = 0; OUT_SIZE_REG_EC08 = 0; OUT_SIZE_REG_EC0C = 0;
        OUT_WIDTH_LOW = width & 0xff; OUT_WIDTH_HIGH = (width >> 8) & 0x1f;
        OUT_SIZE_REG_EC18 = 0; OUT_SIZE_REG_EC1C = 0;
        OUT_LINES_LOW = lines & 0xff; OUT_LINES_HIGH = (lines >> 8) & 0x1f;
        OUT_SIZE_REG_EC00 = 9;
        if ((panel_working_row_ptr->flags & ROW_LINK_TYPE_MASK) == ROW_LINK_TYPE_2 && (unsigned char)(panel_working_row_ptr->display_mode - 8) <= 2) {
            pq_block_write8(BLOCK4, BLK_REG_8D, 8);
            OUT_REG_ED80 = 0x10;
        } else OUT_REG_ED80 = 0;
    }
}
