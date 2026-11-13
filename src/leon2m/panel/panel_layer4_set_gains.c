/* panel_layer4_set_gains  (FUN_a010e624)
 *
 * Store three percentages of the fourth layer and write them as 10-bit values (100 gives 1023).
 * Note: A channel above 1 writes both fourth-layer channels. Nothing calls it.
 * Name basis: descriptive - name rests only on the form of the values: three unsigned 10-bit values, (x * 1023
 *   + 50) / 100, in block words 9..11 of the fourth layer; record bytes +0x38..+0x3A
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010e624 @ 0xa010e624-0xa010e8ec (712 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: WRITE_BLOCKS loops on one function-level counter i shared by all six uses; the channel parameter
 * is an unsigned short copied to an unsigned char; each read index is a block-local
 * 'unsigned char block_index = channel > 1 ? 0 : channel;'; the context bytes are stored in ascending order.
 */
/* Stored settings of the fourth layer; the three bytes at +0x38..+0x3A are written here. */
struct layer_context { unsigned char pad[0x38]; unsigned char byte_0x38, byte_0x39, byte_0x3a; };
/* Fourth-layer register blocks: 0xD0032028 / 0xD0032098, second half 0xD003A028 / 0xD003A098. */
struct layer4_block { unsigned int words[0x40]; };
extern struct layer_context panel_layer4_context_ch0, panel_layer4_context_ch1;
extern volatile struct layer4_block *const panel_layer4_blocks_first_half[2];
extern volatile struct layer4_block *const panel_layer4_blocks_second_half[2];

#define LAST_LAYER4_CHANNEL 1           /* channel numbers above this mean "both channels" */
#define BLOCK_WORD_9   9                /* offsets 0x24, 0x28, 0x2C */
#define BLOCK_WORD_10 10
#define BLOCK_WORD_11 11
#define FIELD_BITS_0_9 0x3ff

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
 * The fourth-layer version of panel_channel_layer_set_gains (the name has no "4", but the routine uses only the
 * fourth-layer contexts and blocks).
 *
 *   channel_in             0 or 1, or a number above 1 for both channels
 *   first, second, third   percentages, 0..100
 *
 * Stores the three values in bytes +0x38, +0x39 and +0x3A of the context and writes each, scaled as
 * (value * 1023 + 50) / 100 (100 gives 1023), to bits 0..9 of block words 9, 10 and 11 in both halves. The other
 * bits of each word are kept from the first-half block (channel 0 when the channel is above 1).
 * panel_layer4_set_offsets writes bits 16..23 of the same three words. Nothing in the image calls this routine.
 */
void panel_layer4_set_gains(unsigned short channel_in, unsigned char first, unsigned char second, unsigned char third)
{
    unsigned char channel = channel_in;
    struct layer_context *context;
    unsigned int word;
    unsigned int i;

    context = get_context(channel);
    context->byte_0x38 = first;
    context->byte_0x39 = second;
    context->byte_0x3a = third;
    {
        unsigned char block_index = channel > LAST_LAYER4_CHANNEL ? 0 : channel;
        word = (panel_layer4_blocks_first_half[block_index]->words[BLOCK_WORD_9] & ~FIELD_BITS_0_9) | (first * 1023U + 50) / 100;
    }
    WRITE_BLOCKS(panel_layer4_blocks_first_half, words[BLOCK_WORD_9], word);
    WRITE_BLOCKS(panel_layer4_blocks_second_half, words[BLOCK_WORD_9], word);
    {
        unsigned char block_index = channel > LAST_LAYER4_CHANNEL ? 0 : channel;
        word = (panel_layer4_blocks_first_half[block_index]->words[BLOCK_WORD_10] & ~FIELD_BITS_0_9) | (second * 1023U + 50) / 100;
    }
    WRITE_BLOCKS(panel_layer4_blocks_first_half, words[BLOCK_WORD_10], word);
    WRITE_BLOCKS(panel_layer4_blocks_second_half, words[BLOCK_WORD_10], word);
    {
        unsigned char block_index = channel > LAST_LAYER4_CHANNEL ? 0 : channel;
        word = (panel_layer4_blocks_first_half[block_index]->words[BLOCK_WORD_11] & ~FIELD_BITS_0_9) | (third * 1023U + 50) / 100;
    }
    WRITE_BLOCKS(panel_layer4_blocks_first_half, words[BLOCK_WORD_11], word);
    WRITE_BLOCKS(panel_layer4_blocks_second_half, words[BLOCK_WORD_11], word);
}
