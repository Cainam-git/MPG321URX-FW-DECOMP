/* panel_layer4_set_format  (FUN_a010d914)
 *
 * Set the pixel format of the fourth layer.
 * Name basis: derived - the format step of the second-half window set-up, as a routine of its own; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010d914 @ 0xa010d914-0xa010daf8 (121 words), flags -mcpu=v8 -O3 -g.
 * Source form: WRITE_BLOCKS loops on the function's counter i (as panel_layer4_set_gains); the control word is
 * built as 'shifted = code << 16; word = code | shifted | 1' (the firmware's operand order 'or code, shifted').
 * panel_layer4_setup_window holds the same body inline; it is written there as a static helper.
 */
/* Stored settings of the fourth layer; the fields of panel_layer4_setup_window. */
struct layer_context {
    unsigned int base;                  /* +0x00: buffer address */
    unsigned char pad04[8];
    unsigned short source_width, source_lines;              /* +0x0C, +0x0E */
    unsigned char pad10[4];
    unsigned short window_x, window_width;                  /* +0x14, +0x16 */
    unsigned short first_half_position, second_half_position;   /* +0x18, +0x1A */
    unsigned char pad1c[4];
    unsigned short low_word, high_word;                     /* +0x20, +0x22 */
    unsigned char bits_per_pixel;       /* +0x24: 16 or 32 */
    unsigned char format;               /* +0x25: format number as passed in */
    unsigned char byte_0x26;            /* +0x26: also block word 5 */
    unsigned char pad27[0x17];
    unsigned char flags;                /* +0x3E */
};
/* The first six words of a fourth-layer register block (0xD0032028 / 0xD0032098, second half +0x8000). */
struct layer4_block { unsigned int position, word_1, word_2, word_3, word_4, word_5; };
struct panel_timing_row { unsigned char pad00[8]; unsigned short active_size0; };   /* +8: panel width */
extern struct layer_context panel_layer4_context_ch0, panel_layer4_context_ch1;
extern volatile struct layer4_block *const panel_layer4_blocks_first_half[2];
extern volatile struct layer4_block *const panel_layer4_blocks_second_half[2];

/* Declarations of panel_layer4_setup_window, which carries these steps inline; not used here. */
extern unsigned char panel_layer_position_offset, panel_layer_update_strobe_enabled;
extern struct panel_timing_row *panel_working_row_ptr;
extern void panel_layer4_set_buffer(unsigned char, unsigned char, unsigned short, unsigned short, unsigned int);
extern void panel_layer4_set_output_size(unsigned char, unsigned char, unsigned short, unsigned short);
extern unsigned short timer_get_ticks16(void);

#define REG(address) (*(volatile unsigned int *)(address))
#define LAST_LAYER4_CHANNEL 1           /* channel numbers above this mean "both channels" */

/* Control word of each channel of the fourth layer, in the first and the second half. */
#define LAYER4_CH0_CTRL_HALF0 0xd0032004
#define LAYER4_CH0_CTRL_HALF1 0xd003a004
#define LAYER4_CH1_CTRL_HALF0 0xd0032008
#define LAYER4_CH1_CTRL_HALF1 0xd003a008
#define LAYER4_CTRL_BIT0      1         /* set on every format write */

/* Format codes, the same bits as in block word 4 of the channel layers (panel_layer_set_format). */
#define FORMAT_16BPP     0x100          /* bit 8: a 16-bit format; bits 13..15 tell which one */
#define FORMAT_32BPP     0x200          /* bit 9: a 32-bit format */
#define FORMAT_BIT12     0x1000         /* together with bit 9 for format 8 */
#define FORMAT_16BPP_SUBTYPE(n) ((n) << 13)

/* Write val to field f of the channel's block in table, or of both blocks when the channel is above 1 (uses
   channel and i of the caller). */
#define WRITE_BLOCKS(table, f, val) if (channel > LAST_LAYER4_CHANNEL) { for (i = 0; i <= LAST_LAYER4_CHANNEL; i++) table[i]->f = val; } else table[channel]->f = val

/* Channel 1 has its own context; every other number uses the context of channel 0. */
static struct layer_context *get_context(unsigned char channel)
{
    if (channel != 1) return &panel_layer4_context_ch0;
    return &panel_layer4_context_ch1;
}

/*
 * Set the pixel format of the fourth layer.
 *
 *   channel  0 or 1, or a number above 1 for both (the block word); the control word goes to channel 0 for 0
 *            and to channel 1 for every other number
 *   format   1..6: 16-bit formats; 8 and every other number: 32-bit formats
 *   value    goes to byte +0x26 of the context and to block word 5 in both halves
 *
 * Unlike panel_layer_set_format there is no 8-bit format here: format 0 and 9 are taken as the plain 32-bit
 * format. The format code goes to bits 0..15 and again to bits 16..31 of the channel's control word, with bit 0
 * set, in both halves. Other bits of the control word are not kept.
 *
 * No routine calls it directly; panel_layer4_setup_window carries the same steps in its own body and
 * uses them with format 7 and value 0xFF.
 */
void panel_layer4_set_format(unsigned char channel, unsigned char format, unsigned char value)
{
    unsigned int i;
    struct layer_context *context;
    unsigned int code, word, shifted;

    context = get_context(channel);
    context->byte_0x26 = value;
    context->format = format;
    word = value;
    WRITE_BLOCKS(panel_layer4_blocks_first_half, word_5, word);
    WRITE_BLOCKS(panel_layer4_blocks_second_half, word_5, word);
    switch (format)
    {
    case 1: context->bits_per_pixel = 16; code = FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(0); break;
    case 2: context->bits_per_pixel = 16; code = FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(1); break;
    case 3: context->bits_per_pixel = 16; code = FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(2); break;
    case 4: context->bits_per_pixel = 16; code = FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(3); break;
    case 5: context->bits_per_pixel = 16; code = FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(4); break;
    case 6: context->bits_per_pixel = 16; code = FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(5); break;
    case 8: context->bits_per_pixel = 32; code = FORMAT_32BPP | FORMAT_BIT12; break;
    default: context->bits_per_pixel = 32; code = FORMAT_32BPP; break;
    }
    if (channel == 0) { shifted = code << 16; word = code | shifted | LAYER4_CTRL_BIT0; REG(LAYER4_CH0_CTRL_HALF0) = word; REG(LAYER4_CH0_CTRL_HALF1) = word; }
    else { shifted = code << 16; word = code | shifted | LAYER4_CTRL_BIT0; REG(LAYER4_CH1_CTRL_HALF0) = word; REG(LAYER4_CH1_CTRL_HALF1) = word; }
}
