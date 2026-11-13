/* panel_layer4_set_buffer  (FUN_a010dc8c)
 *
 * Store the buffer parameters of the fourth layer and program them.
 * Name basis: descriptive - record fields and block words 1, 6 and 8; used by the second-half window set-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010dc8c @ 0xa010dc8c-0xa010de54 (456 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: each block store is its own 'if (half == 0) ... else ...' (as in panel_layer_set_buffer);
 * context->source_width is read where it is used; the round-up test is 'source_width % pixels_per_unit != 0'.
 */
/* Stored settings of the fourth layer; only the fields used here. */
struct layer_context {
    unsigned int base;                  /* +0x00 */
    unsigned int first_half_word;       /* +0x04: buffer address of the first-half part, in 32-byte units */
    unsigned int second_half_word;      /* +0x08: the same for the second-half part */
    unsigned short source_width;        /* +0x0C: pixels per line of the buffer */
    unsigned short source_lines;        /* +0x0E */
    unsigned short first_half_source_width;     /* +0x10: pixels of the buffer line shown in the first half */
    unsigned short second_half_source_width;    /* +0x12 */
    unsigned char pad14[0x10];
    unsigned char bits_per_pixel;       /* +0x24: set by panel_layer4_set_format */
};
extern struct layer_context panel_layer4_context_ch0, panel_layer4_context_ch1;
extern volatile unsigned int *panel_layer4_blocks_first_half[], *panel_layer4_blocks_second_half[];

#define REG(address) (*(volatile unsigned int *)(address))

/* Words of a fourth-layer register block. */
#define BLOCK_WORD_WIDTH        1       /* bits 16..31: source_width */
#define BLOCK_WORD_FIRST_PIXEL  6       /* first pixel inside the first 32-byte unit */
#define BLOCK_WORD_PART_WIDTH   8

/* Buffer address (in 32-byte units) and buffer size (in 16-byte units) of each channel and half. */
#define LAYER4_CH0_ADDR_HALF0 0xd0032280
#define LAYER4_CH0_ADDR_HALF1 0xd003a280
#define LAYER4_CH1_ADDR_HALF0 0xd0032284
#define LAYER4_CH1_ADDR_HALF1 0xd003a284
#define LAYER4_CH0_BUFFER_SIZE_HALF0 0xd00320e8
#define LAYER4_CH0_BUFFER_SIZE_HALF1 0xd003a0e8
#define LAYER4_CH1_BUFFER_SIZE_HALF0 0xd00320ec
#define LAYER4_CH1_BUFFER_SIZE_HALF1 0xd003a0ec

/* Channel 1 has its own context; every other number uses the context of channel 0. */
static struct layer_context *get_context(unsigned char channel)
{
    if (channel != 1) return &panel_layer4_context_ch0;
    return &panel_layer4_context_ch1;
}

/*
 * Program where one half's part of the fourth layer reads its picture from.
 *
 *   channel        0 or 1 (indexes the block tables directly)
 *   half           0: the first half of the output, otherwise the second
 *   part_width     pixels of each buffer line that this half shows
 *   source_lines   lines of the buffer
 *   address        address of the part's first pixel
 *
 * Called twice by panel_layer4_setup_window, once per half. The context must already hold the line
 * width (source_width) and bits_per_pixel. The buffer size written is source_lines times the line length rounded
 * up to whole 32-byte units, counted in 16-byte units; for channel 0 it goes to the channel-0 registers, for any
 * other number to the channel-1 registers.
 */
void panel_layer4_set_buffer(unsigned char channel, unsigned char half, unsigned short part_width, unsigned short source_lines, unsigned int address)
{
    struct layer_context *context;
    unsigned int first_pixel, pixels_per_unit, rounded_width, size, word;

    context = get_context(channel);
    /* The address register counts 32-byte units; the pixels before the address inside its unit go to word 6. */
    first_pixel = (address & 0x1f) / (context->bits_per_pixel >> 3);
    if (half == 0) {
        context->first_half_word = address >> 5;
        context->first_half_source_width = part_width;
    } else {
        context->second_half_word = address >> 5;
        context->second_half_source_width = part_width;
    }
    context->source_lines = source_lines;
    word = context->source_width << 16;
    if (half == 0) panel_layer4_blocks_first_half[channel][BLOCK_WORD_WIDTH] = word; else panel_layer4_blocks_second_half[channel][BLOCK_WORD_WIDTH] = word;
    if (half == 0) panel_layer4_blocks_first_half[channel][BLOCK_WORD_FIRST_PIXEL] = first_pixel; else panel_layer4_blocks_second_half[channel][BLOCK_WORD_FIRST_PIXEL] = first_pixel;
    word = part_width;
    if (half == 0) panel_layer4_blocks_first_half[channel][BLOCK_WORD_PART_WIDTH] = word; else panel_layer4_blocks_second_half[channel][BLOCK_WORD_PART_WIDTH] = word;
    /* Line length rounded up to a whole number of 32-byte units. */
    pixels_per_unit = 32 / (context->bits_per_pixel >> 3);
    rounded_width = context->source_width / pixels_per_unit * pixels_per_unit;
    if (context->source_width % pixels_per_unit != 0)
        rounded_width = (context->source_width / pixels_per_unit + 1) * pixels_per_unit;
    size = source_lines * rounded_width * context->bits_per_pixel >> 7;
    if (channel == 0) {
        if (half == 0) {
            REG(LAYER4_CH0_ADDR_HALF0) = context->first_half_word;
            REG(LAYER4_CH0_BUFFER_SIZE_HALF0) = size;
        } else {
            REG(LAYER4_CH0_ADDR_HALF1) = context->second_half_word;
            REG(LAYER4_CH0_BUFFER_SIZE_HALF1) = size;
        }
    } else {
        if (half == 0) {
            REG(LAYER4_CH1_ADDR_HALF0) = context->first_half_word;
            REG(LAYER4_CH1_BUFFER_SIZE_HALF0) = size;
        } else {
            REG(LAYER4_CH1_ADDR_HALF1) = context->second_half_word;
            REG(LAYER4_CH1_BUFFER_SIZE_HALF1) = size;
        }
    }
}
