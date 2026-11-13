/* panel_layer_set_color_key  (FUN_a010c61c)
 *
 * Store a selector and two values of a channel layer and write its control words.
 * Name basis: descriptive - control word and value pairs in the layer's register blocks; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010c61c @ 0xa010c61c-0xa010d068 (659 words), flags -mcpu=v8 -O3 -g.
 * Source form: the write to one block word is the macro WRITE_BLOCKS with the loop counter i declared once at
 * function level (a static helper or a block-local counter gives other registers). Same form as
 * panel_layer4_set_color_key.
 */
/* Per-channel stored settings; only the bytes at +0x27..+0x37 are used here. */
struct layer_context {
    unsigned char bytes_0x00_to_0x26[0x27];
    unsigned char key_select;           /* +0x27: last selector passed in */
    unsigned int pair1_first;           /* +0x28 */
    unsigned int pair1_second;          /* +0x2C */
    unsigned int pair2_first;           /* +0x30 */
    unsigned int pair2_second;          /* +0x34 */
};
extern struct layer_context panel_layer_context_ch0, panel_layer_context_ch2, panel_layer_context_ch1;
extern volatile unsigned int *panel_channel_blocks_first_half[], *panel_channel_blocks_second_half[];

#define LAST_CHANNEL 2                  /* channel numbers above this mean "all three channels" */

/* Words of a channel layer register block. */
#define LAYER_WORD_4        4           /* control word; bits 5 and 6 switch the two pairs on */
#define LAYER_WORD_PAIR1_A  12          /* +0x30 */
#define LAYER_WORD_PAIR1_B  13          /* +0x34 */
#define LAYER_WORD_PAIR2_A  14          /* +0x38 */
#define LAYER_WORD_PAIR2_B  15          /* +0x3C */
#define WORD4_PAIR1_ON      0x20
#define WORD4_PAIR2_ON      0x40

/* Selector values. */
enum {
    KEY_SELECT_ALL_OFF  = 0,            /* both pairs off and cleared */
    KEY_SELECT_PAIR1_ON = 1,
    KEY_SELECT_PAIR1_OFF = 2,
    KEY_SELECT_PAIR2_ON = 3,
    KEY_SELECT_PAIR2_OFF = 4
};

/* Channel 1 and 2 have their own context; every other number uses the context of channel 0. */
static struct layer_context *get_context(unsigned char channel)
{
    struct layer_context *context;
    switch (channel) {
    case 1: context = &panel_layer_context_ch1; break;
    case 2: context = &panel_layer_context_ch2; break;
    default: context = &panel_layer_context_ch0; break;
    }
    return context;
}

/* Write val to word n of the channel's block in table, or of all three blocks when the channel is above 2
   (uses channel and i of the caller). */
#define WRITE_BLOCKS(table, n, val) if (channel > LAST_CHANNEL) { for (i = 0; i <= LAST_CHANNEL; i++) table[i][n] = val; } else table[channel][n] = val

/*
 * Switch one of the two value pairs of a channel layer on or off.
 *
 *   channel     0..2, or a number above 2 for all three channels
 *   select      KEY_SELECT_*: which pair, on or off
 *   first       first value of the pair, used when a pair is switched on
 *   second      second value of the pair
 *
 * The selector and the pair are kept in the channel's context. Block word 4 is read from the first-half block of
 * the channel (channel 0 when the channel is above 2); bit 5 (pair 1) or bit 6 (pair 2) is set or cleared in it
 * and it is written back with the pair's two block words (the values, or 0 when switched off) to both halves.
 * A selector above 4 is only stored. Nothing in the image calls this routine.
 */
void panel_layer_set_color_key(unsigned char channel, unsigned int select, unsigned int first, unsigned int second)
{
    struct layer_context *context;
    unsigned int word;
    unsigned char source_channel;
    unsigned int i;

    context = get_context(channel);
    context->key_select = select;
    source_channel = channel;
    if (channel > LAST_CHANNEL)
        source_channel = 0;
    word = panel_channel_blocks_first_half[source_channel][LAYER_WORD_4];
    switch ((unsigned char)select) {
    case KEY_SELECT_ALL_OFF:
        context->pair1_first = 0;
        context->pair1_second = 0;
        context->pair2_first = 0;
        context->pair2_second = 0;
        word &= ~(WORD4_PAIR1_ON | WORD4_PAIR2_ON);
        WRITE_BLOCKS(panel_channel_blocks_first_half, LAYER_WORD_4, word);
        WRITE_BLOCKS(panel_channel_blocks_second_half, LAYER_WORD_4, word);
        WRITE_BLOCKS(panel_channel_blocks_first_half, LAYER_WORD_PAIR1_A, 0);
        WRITE_BLOCKS(panel_channel_blocks_second_half, LAYER_WORD_PAIR1_A, 0);
        WRITE_BLOCKS(panel_channel_blocks_first_half, LAYER_WORD_PAIR1_B, 0);
        WRITE_BLOCKS(panel_channel_blocks_second_half, LAYER_WORD_PAIR1_B, 0);
        WRITE_BLOCKS(panel_channel_blocks_first_half, LAYER_WORD_PAIR2_A, 0);
        WRITE_BLOCKS(panel_channel_blocks_second_half, LAYER_WORD_PAIR2_A, 0);
        WRITE_BLOCKS(panel_channel_blocks_first_half, LAYER_WORD_PAIR2_B, 0);
        WRITE_BLOCKS(panel_channel_blocks_second_half, LAYER_WORD_PAIR2_B, 0);
        break;
    case KEY_SELECT_PAIR1_ON:
        context->pair1_first = first;
        context->pair1_second = second;
        word |= WORD4_PAIR1_ON;
        WRITE_BLOCKS(panel_channel_blocks_first_half, LAYER_WORD_4, word);
        WRITE_BLOCKS(panel_channel_blocks_second_half, LAYER_WORD_4, word);
        WRITE_BLOCKS(panel_channel_blocks_first_half, LAYER_WORD_PAIR1_A, first);
        WRITE_BLOCKS(panel_channel_blocks_second_half, LAYER_WORD_PAIR1_A, first);
        WRITE_BLOCKS(panel_channel_blocks_first_half, LAYER_WORD_PAIR1_B, second);
        WRITE_BLOCKS(panel_channel_blocks_second_half, LAYER_WORD_PAIR1_B, second);
        break;
    case KEY_SELECT_PAIR1_OFF:
        context->pair1_first = 0;
        context->pair1_second = 0;
        word &= ~WORD4_PAIR1_ON;
        WRITE_BLOCKS(panel_channel_blocks_first_half, LAYER_WORD_4, word);
        WRITE_BLOCKS(panel_channel_blocks_second_half, LAYER_WORD_4, word);
        WRITE_BLOCKS(panel_channel_blocks_first_half, LAYER_WORD_PAIR1_A, 0);
        WRITE_BLOCKS(panel_channel_blocks_second_half, LAYER_WORD_PAIR1_A, 0);
        WRITE_BLOCKS(panel_channel_blocks_first_half, LAYER_WORD_PAIR1_B, 0);
        WRITE_BLOCKS(panel_channel_blocks_second_half, LAYER_WORD_PAIR1_B, 0);
        break;
    case KEY_SELECT_PAIR2_ON:
        context->pair2_first = first;
        context->pair2_second = second;
        word |= WORD4_PAIR2_ON;
        WRITE_BLOCKS(panel_channel_blocks_first_half, LAYER_WORD_4, word);
        WRITE_BLOCKS(panel_channel_blocks_second_half, LAYER_WORD_4, word);
        WRITE_BLOCKS(panel_channel_blocks_first_half, LAYER_WORD_PAIR2_A, first);
        WRITE_BLOCKS(panel_channel_blocks_second_half, LAYER_WORD_PAIR2_A, first);
        WRITE_BLOCKS(panel_channel_blocks_first_half, LAYER_WORD_PAIR2_B, second);
        WRITE_BLOCKS(panel_channel_blocks_second_half, LAYER_WORD_PAIR2_B, second);
        break;
    case KEY_SELECT_PAIR2_OFF:
        context->pair2_first = 0;
        context->pair2_second = 0;
        word &= ~WORD4_PAIR2_ON;
        WRITE_BLOCKS(panel_channel_blocks_first_half, LAYER_WORD_4, word);
        WRITE_BLOCKS(panel_channel_blocks_second_half, LAYER_WORD_4, word);
        WRITE_BLOCKS(panel_channel_blocks_first_half, LAYER_WORD_PAIR2_A, 0);
        WRITE_BLOCKS(panel_channel_blocks_second_half, LAYER_WORD_PAIR2_A, 0);
        WRITE_BLOCKS(panel_channel_blocks_first_half, LAYER_WORD_PAIR2_B, 0);
        WRITE_BLOCKS(panel_channel_blocks_second_half, LAYER_WORD_PAIR2_B, 0);
        break;
    }
}
