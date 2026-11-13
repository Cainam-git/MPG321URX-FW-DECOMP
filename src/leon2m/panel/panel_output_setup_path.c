/* panel_output_setup_path  (FUN_a0105150)
 *
 * Set up the output path's configuration record and clock modulation.
 * Name basis: derived - output path set-up A; called from Disp_Init and System_Initialize
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0105150 @ 0xa0105150, flags -mcpu=v8 -O3 -g.
 * Register addresses: the firmware loads %hi(0xCF00EC00) in the delay slots of 'bleu,a' / 'b' at a01055a8 /
 * a01055c0, so the registers are 0xCF00EC04..EC24 and 0xCF00EFC0 (a disassembler comment there that reads
 * 0xcf00e804 is stale).
 * Source forms the exact build depends on:
 *  - the modulation rate/depth clamp as in panel_output_setup_clock: rate_check (unsigned int) and depth_raw are
 *    read before 'if (rate_check != 0)', rate_value is read from the record again, 'depth_value = depth_raw'
 *    comes before the range check of rate_value;
 *  - the modulation tests are nested 'if (x != 0) { set-up } else { off }' (spread_on, spread_mode, rate_check,
 *    spread_ctrl_byte); the compiler joins three of the 'off' arms into one block;
 *  - ctrl_byte is the low byte of +0x0E held in an unsigned int, the test is on the 16-bit field; the first merge
 *    goes to an unsigned char, the second to the unsigned int 'value' with 'ctrl_byte & ~0x1f';
 *  - 'if (sys_get_chip_revision() <= 0x81) ... = 0; else ... = 0x10;' (the ?: form gives subx);
 *    panel_layer_position_offset is read again for CLOCK_REG_B814, and 'value' is reused for CLOCK_REG_B854.
 */
#define R(a) (*(volatile unsigned int *)(a))

/* The output configuration record (0xA802D680, 36 bytes); field names as in panel_output_apply_timing. */
struct panel_output_config {
    unsigned char spread_on;            /* +0: 0 = clock modulation off */
    unsigned char spread_mode;          /* +1: not 0 = rate and depth values, 0 = control byte */
    unsigned char row_bit25;            /* +2 */
    unsigned char byte_0x03;
    unsigned int colour_depth_code;     /* +4 */
    unsigned int display_mode;          /* +8 */
    unsigned char ed58_value;           /* +0xC: written to OUTPUT_SYNC_POLARITY */
    unsigned char ede4_value;           /* +0xD */
    unsigned short spread_ctrl_byte;    /* +0xE: control byte of the modulation (low byte used) */
    unsigned short spread_rate_value;   /* +0x10: 25..500; the rate register gets 1500 / value */
    unsigned short spread_depth_value;  /* +0x12: 5..5000 */
    unsigned char byte_0x14, byte_0x15, byte_0x16, byte_0x17;
    unsigned int word_0x18, word_0x1c, word_0x20;
};

/* The working copy of the active panel timing row (fields as in panel_output_apply_timing). */
struct panel_timing_row {
    unsigned int flags;                 /* +0: bits 20..22 link type, bit 26 clock modulation */
    unsigned short half_0x04;
    unsigned char display_mode;         /* +6 */
    unsigned char bpc;                  /* +7 */
    unsigned short active_size0, active_size1;  /* +8 / +0xA: active width and lines */
    unsigned char pad0c[0x16];
    unsigned short half_0x22;           /* +0x22: the middle horizontal total of the row */
    unsigned char pad24[2];
    unsigned short hblank_part, hblank_part2;   /* +0x26 / +0x28 */
    unsigned char pad2a[6];
    unsigned short half_0x30, half_0x32;
    unsigned int line_rate_x10;         /* +0x34: line rate in tenths of a hertz (564480.0 Hz in the 240 Hz row) */
};
extern struct panel_output_config panel_output_config_record;
extern struct panel_timing_row *panel_working_row_ptr;
extern void pq_block_write8(int, int, int);
extern void panel_output_apply_timing(int);
extern void panel_set_pll_frequency(int, unsigned int);
extern void reg_write16_bytes(unsigned int, unsigned int);
extern void pq_block_update_bits(int, int, int, int);
extern unsigned char sys_get_chip_revision(void);
extern unsigned char panel_layer_position_offset;

#define ALL_BLOCKS 8                    /* block number that writes all eight picture blocks */

/* Clock generators (the firmware's print names). */
enum { GPLL_DISPM = 0, GPLL_DISP1 = 1, GPLL_DISP2 = 2, GPLL_DISP3 = 3 };

/* Bits 20..22 of the row's first word: link type. */
#define ROW_LINK_TYPE_MASK   0x700000
#define ROW_LINK_TYPE_2      0x200000
#define PANEL_ROW_SPREAD_BIT 0x4000000  /* bit 26: clock modulation on for this row */

#define OUTPUT_SYNC_POLARITY R(0xcf00ed58)
#define OUTPUT_REG_ED5C      R(0xcf00ed5c)  /* 0x20 for link type 2 with display modes 8..10, else 0x40 */

/* Clock modulation, two blocks (see panel_spread_configure). */
#define SPREAD_CTRL_BLOCK0   R(0xcf012890)
#define SPREAD_RATE_BLOCK0   R(0xcf012898)
#define SPREAD_DEPTH_BLOCK0  R(0xcf01289c)
#define SPREAD_CTRL_BLOCK1   R(0xcf012990)
#define SPREAD_RATE_BLOCK1   R(0xcf012998)
#define SPREAD_DEPTH_BLOCK1  R(0xcf01299c)

#define CLOCK_REG_B814       R(0xcf00b814)
#define CLOCK_REG_B818       R(0xcf00b818)
#define CLOCK_REG_B844       R(0xcf00b844)
#define CLOCK_REG_B848       R(0xcf00b848)
#define CLOCK_REG_B854       R(0xcf00b854)

/* Output size registers: width and lines of the panel row, each as a low byte and bits 8..12. */
#define OUT_SIZE_REG_EC04    R(0xcf00ec04)
#define OUT_SIZE_REG_EC08    R(0xcf00ec08)
#define OUT_SIZE_REG_EC0C    R(0xcf00ec0c)
#define OUT_WIDTH_LOW        R(0xcf00ec10)
#define OUT_WIDTH_HIGH       R(0xcf00ec14)
#define OUT_SIZE_REG_EC18    R(0xcf00ec18)
#define OUT_SIZE_REG_EC1C    R(0xcf00ec1c)
#define OUT_LINES_LOW        R(0xcf00ec20)
#define OUT_LINES_HIGH       R(0xcf00ec24)

/* Registers of a picture block. */
#define BLK_REG_20           0x20
#define BLK_REG_24           0x24
#define BLK_BLANK_MODE       0x54
#define BLK_REG_6E           0x6e
#define BLK_REG_86           0x86
#define BLK_COUNT_SELECT     0x88
#define BLK_REG_8D           0x8d
#define BLK_REG_8E           0x8e
#define BLK_REG_8F           0x8f
#define BLK_REG_90           0x90

/*
 * Store the output configuration and set up the output path: all eight picture blocks, the output timing, the
 * four display clock generators, the clock modulation and the output size registers.
 *
 *   cfg   the 36-byte output configuration; it is copied to panel_output_config_record first
 *
 * Called from Disp_Init and System_Initialize. panel_output_setup_clock does the same clock and modulation
 * set-up.
 *
 * The main display clock is the row's line rate times its middle horizontal total; the second and third
 * generators get half of it and the fourth a quarter. Clock modulation: off when spread_on is 0; with spread_mode
 * set, from the rate and depth values (out-of-range values become 100 and 150); else from the control byte; in
 * the two set-up cases bit 0 (on) then follows bit 26 of the row. Chip revisions above 0x81 get a position
 * offset of 0x10 (panel_layer_position_offset), revisions above 0x83 also bit 5 of CLOCK_REG_B844.
 */
void panel_output_setup_path(struct panel_output_config *cfg)
{
    unsigned int value;
    unsigned int pixel_clock;
    unsigned short rate_value, depth_value;
    unsigned char merged;
    unsigned int ctrl_byte;
    unsigned int rate_check;
    unsigned short depth_raw;
    panel_output_config_record = *cfg;
    pq_block_write8(ALL_BLOCKS, BLK_REG_8E, 3);
    pq_block_write8(ALL_BLOCKS, BLK_REG_8F, 0);
    pq_block_write8(ALL_BLOCKS, BLK_REG_24, 0);
    pq_block_update_bits(ALL_BLOCKS, BLK_REG_20, 0x80, 1);
    OUTPUT_SYNC_POLARITY = panel_output_config_record.ed58_value;
    if ((panel_working_row_ptr->flags & ROW_LINK_TYPE_MASK) == ROW_LINK_TYPE_2 && (unsigned char)(panel_working_row_ptr->display_mode - 8) <= 2) OUTPUT_REG_ED5C = 0x20;
    else OUTPUT_REG_ED5C = 0x40;
    R(0xcf011658) = 0x40;
    R(0xcf00eda8) = 0;
    pq_block_write8(ALL_BLOCKS, BLK_REG_6E, 7);
    pq_block_write8(ALL_BLOCKS, BLK_REG_86, 0);
    pq_block_write8(ALL_BLOCKS, BLK_COUNT_SELECT, 0x10);
    pq_block_write8(ALL_BLOCKS, BLK_REG_8D, 0);
    /* Link type 2 with display modes 8..10: block 0 gets 8 in register 0x8D. */
    if ((panel_working_row_ptr->flags & ROW_LINK_TYPE_MASK) == ROW_LINK_TYPE_2 && (unsigned char)(panel_working_row_ptr->display_mode - 8) <= 2) pq_block_write8(0, BLK_REG_8D, 8);
    pq_block_update_bits(ALL_BLOCKS, BLK_REG_90, 0x40, 0);
    pq_block_update_bits(ALL_BLOCKS, BLK_REG_90, 0x20, 1);
    pq_block_write8(ALL_BLOCKS, BLK_BLANK_MODE, 2);
    panel_output_apply_timing(ALL_BLOCKS);

    pixel_clock = panel_working_row_ptr->line_rate_x10 / 10 * panel_working_row_ptr->half_0x22;
    panel_set_pll_frequency(GPLL_DISPM, pixel_clock);
    panel_set_pll_frequency(GPLL_DISP1, pixel_clock >> 1);
    panel_set_pll_frequency(GPLL_DISP2, pixel_clock >> 1);
    panel_set_pll_frequency(GPLL_DISP3, pixel_clock >> 2);

    if (panel_output_config_record.spread_on != 0) {
        if (panel_output_config_record.spread_mode != 0) {
            /* Rate and depth (the steps of panel_spread_set_rate_and_depth). */
            rate_check = panel_output_config_record.spread_rate_value;
            depth_raw = panel_output_config_record.spread_depth_value;
            if (rate_check != 0) {
                rate_value = panel_output_config_record.spread_rate_value;
                depth_value = depth_raw;
                if ((rate_value < 25) || (rate_value > 500)) rate_value = 100;
                if ((depth_value < 5) || (depth_value > 5000)) depth_value = 150;
                SPREAD_RATE_BLOCK0 = (unsigned char)(1500 / rate_value);
                SPREAD_DEPTH_BLOCK0 = (unsigned char)((((unsigned int)depth_value * rate_value) << 15) / 15000000);
                SPREAD_RATE_BLOCK0 = SPREAD_RATE_BLOCK0 | 0x80;
                SPREAD_RATE_BLOCK1 = (unsigned char)(1500 / rate_value);
                SPREAD_DEPTH_BLOCK1 = (unsigned char)((((unsigned int)depth_value * rate_value) << 15) / 15000000);
                SPREAD_RATE_BLOCK1 = SPREAD_RATE_BLOCK1 | 0x80;
                if (panel_working_row_ptr->flags & PANEL_ROW_SPREAD_BIT) { SPREAD_CTRL_BLOCK0 = SPREAD_CTRL_BLOCK0 | 1; SPREAD_CTRL_BLOCK1 = SPREAD_CTRL_BLOCK1 | 1; }
                else { SPREAD_CTRL_BLOCK0 = SPREAD_CTRL_BLOCK0 & ~1; SPREAD_CTRL_BLOCK1 = SPREAD_CTRL_BLOCK1 & ~1; }
            } else {
                SPREAD_CTRL_BLOCK0 = SPREAD_CTRL_BLOCK0 & ~1;
                SPREAD_CTRL_BLOCK1 = SPREAD_CTRL_BLOCK1 & ~1;
            }
        } else {
            if (panel_output_config_record.spread_ctrl_byte != 0) {
                /* Control byte: bits 1..4, then bits 5..7, each merged into block 0's value and written to both. */
                ctrl_byte = (unsigned char)panel_output_config_record.spread_ctrl_byte;
                merged = (SPREAD_CTRL_BLOCK0 & ~0x1e) | (ctrl_byte & 0x1e);
                SPREAD_CTRL_BLOCK0 = merged;
                SPREAD_CTRL_BLOCK1 = merged;
                value = (SPREAD_CTRL_BLOCK0 & 0x1f) | (ctrl_byte & ~0x1f);
                SPREAD_CTRL_BLOCK0 = value;
                SPREAD_CTRL_BLOCK1 = value;
                if (panel_working_row_ptr->flags & PANEL_ROW_SPREAD_BIT) { SPREAD_CTRL_BLOCK0 = SPREAD_CTRL_BLOCK0 | 1; SPREAD_CTRL_BLOCK1 = SPREAD_CTRL_BLOCK1 | 1; }
                else { SPREAD_CTRL_BLOCK0 = SPREAD_CTRL_BLOCK0 & ~1; SPREAD_CTRL_BLOCK1 = SPREAD_CTRL_BLOCK1 & ~1; }
            } else {
                SPREAD_CTRL_BLOCK0 = SPREAD_CTRL_BLOCK0 & ~1;
                SPREAD_CTRL_BLOCK1 = SPREAD_CTRL_BLOCK1 & ~1;
            }
        }
    } else {
        SPREAD_CTRL_BLOCK0 = SPREAD_CTRL_BLOCK0 & ~1;
        SPREAD_CTRL_BLOCK1 = SPREAD_CTRL_BLOCK1 & ~1;
    }
    R(0xcf00e9e0) = 0;
    R(0xcf00e9e4) = 0;
    if (sys_get_chip_revision() <= 0x81) panel_layer_position_offset = 0;
    else panel_layer_position_offset = 0x10;
    value = panel_layer_position_offset << 2 | 3;
    CLOCK_REG_B814 = value;
    CLOCK_REG_B818 = 3;
    CLOCK_REG_B848 = 3;
    CLOCK_REG_B854 = value;
    /* Row values as 16-bit pairs. */
    reg_write16_bytes(0xcf00b81c, panel_working_row_ptr->half_0x30);
    reg_write16_bytes(0xcf00b824, panel_working_row_ptr->hblank_part);
    reg_write16_bytes(0xcf00b82c, panel_working_row_ptr->hblank_part + panel_working_row_ptr->hblank_part2);
    reg_write16_bytes(0xcf00b834, panel_working_row_ptr->half_0x30 + panel_working_row_ptr->half_0x32);
    if (sys_get_chip_revision() > 0x83) CLOCK_REG_B844 = CLOCK_REG_B844 | 0x20;
    OUT_SIZE_REG_EC04 = 0;
    OUT_SIZE_REG_EC08 = 0;
    OUT_SIZE_REG_EC0C = 0;
    OUT_WIDTH_LOW = panel_working_row_ptr->active_size0 & 0xff;
    OUT_WIDTH_HIGH = (panel_working_row_ptr->active_size0 >> 8) & 0x1f;
    OUT_SIZE_REG_EC18 = 0;
    OUT_SIZE_REG_EC1C = 0;
    OUT_LINES_LOW = panel_working_row_ptr->active_size1 & 0xff;
    OUT_LINES_HIGH = (panel_working_row_ptr->active_size1 >> 8) & 0x1f;
    R(0xcf00efc0) = 0xc0;
    R(0xcf00f1c0) = R(0xcf00f1c0) | 0x40;
    R(0xcf00f1c0) = R(0xcf00f1c0) | 1;
    R(0xcf011360) = R(0xcf011360) | 1;
}
