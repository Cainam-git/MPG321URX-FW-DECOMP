/* panel_output_apply_timing  (FUN_a01023f4)
 *
 * Program the output timing block from the active panel timing row.
 * Name basis: proven - output timing apply; many callers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01023f4 @ 0xa01023f4, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the register macro is written "volatile unsigned long" instead of "unsigned int" (same 32-bit width on
 *    SPARC v8, different alias type, so gcc places the reload of display_mode later);
 *  - control is an unsigned char that starts at 0x61 and is overwritten with 0xE1;
 *  - the display-mode test is written "!= 0" first, which gives the firmware's branches;
 *  - the low byte of row +0x30 is read as byte +0x31 through an unsigned char pointer.
 */
#define R(a) (*(volatile unsigned long *)(a))

#define OUTPUT_TIMING_CTRL R(0xcf00ed40)      /* output control byte, built below */
#define OUT_REG_EDE4 R(0xcf00ede4)

/* Bits of the output control byte 0xCF00ED40 (bit 0: the output timing runs). */
#define CTRL_BASE        0x61           /* bits 0, 5 and 6 are always set */
#define CTRL_BASE_BIT23  0xe1           /* the same with bit 7, when the row's first word has bit 23 set */
#define CTRL_DEPTH_SHIFT 3              /* colour_depth_code goes to bit 3 up; its value 2 gives bit 4 */
#define CTRL_LINK_TYPE_1 0x10           /* set when the working row's link type is 1 */
#define CTRL_MODE_0      0x04           /* set only for display mode 0 */
#define CTRL_BIT25       0x02           /* set when the row and the record both have bit 25 */

/* Bits of the row's first word. Bits 20..22 hold the link type; in the working copy panel_transform_row has
   swapped the values 1 and 2 of the active row. */
#define ROW_BIT23          0x800000
#define ROW_LINK_TYPE_MASK 0x700000
#define ROW_LINK_TYPE_1    0x100000
#define ROW_BIT25          0x2000000

/* Registers of a picture block (pq_block_write16 writes each as a 16-bit pair), named after the row value
   written to them. */
#define BLK_VTOTAL       0x5b
#define BLK_HTOTAL       0x5e
#define BLK_HTOTAL_2     0x79
#define BLK_ROW_0X30_SUM 0x62           /* row +0x30 plus row +0x32 */
#define BLK_ROW_0X30_SUM_2 0x6f
#define BLK_LINES        0x64
#define BLK_LINES_2      0x71
#define BLK_HBLANK_PART  0xa0           /* row +0x26 */
#define BLK_HBLANK_SUM   0x66           /* row +0x26 plus row +0x28 */
#define BLK_HBLANK_SUM_2 0x73
#define BLK_WIDTH        0x68
#define BLK_WIDTH_2      0x75
#define BLK_ROW_0X31     0xbe           /* the low byte of row +0x30 */

/* Registers of each of the two menu layers. */
#define LAYER_ROW_0X31     0x5d         /* the low byte of row +0x30 */
#define LAYER_ROW_0X30_SUM 0x62         /* row +0x30 plus row +0x32, a 16-bit pair */

/* The output configuration record (0xA802D680, 36 bytes). panel_output_setup_clock and
   panel_output_setup_path copy it in; the fields named here are the ones read below. */
struct panel_output_config {
    unsigned char byte_0x00, byte_0x01;
    unsigned char row_bit25;            /* +2: bit 25 of the row's first word (panel_setup_output_after_row_change) */
    unsigned char byte_0x03;
    unsigned int colour_depth_code;     /* +4: 2 when the row has 10 bits per colour, else 0 (same routine) */
    unsigned int display_mode;          /* +8: from DispModeTransform, 0..17 */
    unsigned char ed58_value;           /* +0xC: written to 0xCF00ED58 by panel_output_setup_clock */
    unsigned char ede4_value;           /* +0xD: written to 0xCF00EDE4 here */
    unsigned char byte_0x0e, byte_0x0f;
    unsigned int rest[5];
};

/* The working copy of the active panel timing row (0x58 bytes; only the first 0x34 bytes are declared). */
struct panel_timing_row {
    unsigned int flags;                 /* +0: bits 20..22 link type, 23, 25, 26 */
    unsigned short half_0x04;
    unsigned char display_mode;         /* +6: filled in by panel_transform_row */
    unsigned char bpc;                  /* +7: bits per colour */
    unsigned short active_size0;        /* +8: active width in pixels */
    unsigned short active_size1;        /* +0xA: active lines */
    unsigned char clocks[0x14];         /* +0xC..+0x1F; the two clock values printed as 'clk' are at +0x10, +0x18 */
    unsigned short htotal_min;          /* +0x20: the three horizontal totals the firmware prints as 'Htoal' */
    unsigned short half_0x22;           /* +0x22: the middle one of them */
    unsigned short htotal_max;          /* +0x24 */
    unsigned short hblank_part;         /* +0x26: (htotal_min - active width) / 48 * 16, set by panel_api_set_active_row */
    unsigned short hblank_part2;        /* +0x28: the same value */
    unsigned short vtotal_min;          /* +0x2A: the three vertical totals printed as 'Vtoal' */
    unsigned short vtotal;              /* +0x2C */
    unsigned short vtotal_max;          /* +0x2E */
    unsigned short half_0x30, half_0x32;
};

extern struct panel_output_config panel_output_config_record;
extern struct panel_timing_row *panel_working_row_ptr;
extern void panel_output_setup_for_display_mode(unsigned char);
extern void pq_block_write16(unsigned char, unsigned char, unsigned short);
extern void reg_write_block_byte(int, int, int);
extern void osd_write_reg16(int, int, unsigned short);

/*
 * Program the output timing from the working copy of the active panel timing row.
 *
 *   block  the picture block whose timing registers are written: 0, or 8 for all eight blocks
 *
 * Callers: panel_api_set_active_row (when the new row is to be applied), panel_output_setup_clock,
 * pq_block_blank_with_color and oled_frc_task with block 0; panel_output_setup_path with block 8.
 *
 * Steps: the output control byte 0xCF00ED40 from the row flags and the configuration record; for display modes
 * above 2 the byte 0xCF00EDE4; the format fields of the display mode (panel_output_setup_for_display_mode); the
 * totals and sizes of the row into the picture block (most of them into two registers); and the row's +0x30 /
 * +0x32 values into both menu layers.
 */
void panel_output_apply_timing(unsigned char block)
{
    unsigned char control;
    control = CTRL_BASE;
    if (panel_working_row_ptr->flags & ROW_BIT23) control = CTRL_BASE_BIT23;
    control = panel_output_config_record.colour_depth_code << CTRL_DEPTH_SHIFT | control;
    if ((panel_working_row_ptr->flags & ROW_LINK_TYPE_MASK) == ROW_LINK_TYPE_1) control |= CTRL_LINK_TYPE_1;
    if (panel_output_config_record.display_mode != 0) control &= 0xfb; else control |= CTRL_MODE_0;
    if ((panel_working_row_ptr->flags & ROW_BIT25) && panel_output_config_record.row_bit25 != 0) control |= CTRL_BIT25; else control &= 0xfd;
    OUTPUT_TIMING_CTRL = control & 0xff;
    if (panel_output_config_record.display_mode > 2) OUT_REG_EDE4 = panel_output_config_record.ede4_value;
    panel_output_setup_for_display_mode(panel_output_config_record.display_mode);

    pq_block_write16(block, BLK_VTOTAL, panel_working_row_ptr->vtotal);
    pq_block_write16(block, BLK_ROW_0X31, ((unsigned char *)&panel_working_row_ptr->half_0x30)[1]);
    pq_block_write16(block, BLK_ROW_0X30_SUM, panel_working_row_ptr->half_0x30 + panel_working_row_ptr->half_0x32);
    pq_block_write16(block, BLK_LINES, panel_working_row_ptr->active_size1);
    pq_block_write16(block, BLK_ROW_0X30_SUM_2, panel_working_row_ptr->half_0x30 + panel_working_row_ptr->half_0x32);
    pq_block_write16(block, BLK_LINES_2, panel_working_row_ptr->active_size1);
    pq_block_write16(block, BLK_HTOTAL, panel_working_row_ptr->half_0x22);
    pq_block_write16(block, BLK_HBLANK_PART, panel_working_row_ptr->hblank_part);
    pq_block_write16(block, BLK_HBLANK_SUM, panel_working_row_ptr->hblank_part + panel_working_row_ptr->hblank_part2);
    pq_block_write16(block, BLK_WIDTH, panel_working_row_ptr->active_size0);
    pq_block_write16(block, BLK_HBLANK_SUM_2, panel_working_row_ptr->hblank_part + panel_working_row_ptr->hblank_part2);
    pq_block_write16(block, BLK_WIDTH_2, panel_working_row_ptr->active_size0);
    pq_block_write16(block, BLK_HTOTAL_2, panel_working_row_ptr->half_0x22);

    /* The same +0x30 values for menu layer 0 and menu layer 1. */
    reg_write_block_byte(0, LAYER_ROW_0X31, ((unsigned char *)&panel_working_row_ptr->half_0x30)[1]);
    osd_write_reg16(0, LAYER_ROW_0X30_SUM, panel_working_row_ptr->half_0x30 + panel_working_row_ptr->half_0x32);
    reg_write_block_byte(1, LAYER_ROW_0X31, ((unsigned char *)&panel_working_row_ptr->half_0x30)[1]);
    osd_write_reg16(1, LAYER_ROW_0X30_SUM, panel_working_row_ptr->half_0x30 + panel_working_row_ptr->half_0x32);
}
