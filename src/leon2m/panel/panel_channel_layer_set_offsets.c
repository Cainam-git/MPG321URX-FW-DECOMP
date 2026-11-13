/* panel_channel_layer_set_offsets  (FUN_a010d530)
 *
 * Store three percentages of a channel layer and write them as signed 8-bit values (50 gives 0).
 * Note: A channel above 2 writes all three channel layers. Nothing calls it.
 * Name basis: descriptive - name rests only on the form of the values: three signed 8-bit values, (x * 255 +
 *   50) / 100 - 0x80, in bits 16..23 of block words 0x3D..0x3F; record bytes +0x3B..+0x3D
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010d530, flags -mcpu=v8 -O3 -g. No direct callers. Same SET form as panel_layer_set_half_width.
 * Source form: 'unsigned int idx = ch > 2 ? 0 : c;' then '(unsigned char)idx' for each read (the choice is made on
 * the wide parameter); the record bytes are stored in ascending order; SET is a plain if/else statement macro.
 */
/* Per-channel stored settings: the three bytes at +0x3B..+0x3D are written here. */
struct layer_context { unsigned char bytes_0x00_to_0x3a[0x3b]; unsigned char byte_0x3b, byte_0x3c, byte_0x3d; };
/* Channel layer register blocks: first half 0xD0030100..0xD0030300, second half 0xD0038100..0xD0038300. */
struct channel_block { unsigned int words[0x40]; };
extern struct layer_context panel_layer_context_ch0, panel_layer_context_ch2, panel_layer_context_ch1;
extern volatile struct channel_block *const panel_channel_blocks_first_half[3];
extern volatile struct channel_block *const panel_channel_blocks_second_half[3];

#define LAST_CHANNEL 2          /* channel numbers above this mean "all three channels" */
#define BLOCK_WORD_3D 0x3d      /* offsets 0xF4, 0xF8, 0xFC */
#define BLOCK_WORD_3E 0x3e
#define BLOCK_WORD_3F 0x3f
#define FIELD_BITS_16_23 0xff0000

/* Store val in field f of the block of channel 'channel'; a channel above 2 stores it in all three blocks of table tab. */
#define SET(tab, f, val) if (channel > LAST_CHANNEL) { unsigned int i; for (i = 0; i <= LAST_CHANNEL; i++) tab[i]->f = val; } else tab[channel]->f = val

/*
 * Store first, second and third in bytes +0x3B, +0x3C and +0x3D of the channel's stored settings (channel 1 and
 * 2 have their own record, every other number uses channel 0's), and in bits 16..23 of block words 0x3D, 0x3E
 * and 0x3F of its register blocks in both halves, each as (value * 255 + 50) / 100 - 0x80.
 * The other bits of each word are kept from the first-half block (channel 0 when the channel is above 2).
 * A channel above 2 writes all three blocks. Nothing calls this routine; panel_channel_layer_set_gains writes
 * bits 0..9 of the same three words.
 */
void panel_channel_layer_set_offsets(unsigned int channel_in, unsigned char first, unsigned char second, unsigned char third)
{
    unsigned char channel = channel_in;
    struct layer_context *context;
    unsigned int word;

    context = &panel_layer_context_ch1;
    if (channel != 1) {
        context = &panel_layer_context_ch0;
        if (channel == 2) context = &panel_layer_context_ch2;
    }
    context->byte_0x3b = first;
    context->byte_0x3c = second;
    context->byte_0x3d = third;
    {
        unsigned int block_index = channel > LAST_CHANNEL ? 0 : channel_in;
        word = (panel_channel_blocks_first_half[(unsigned char)block_index]->words[BLOCK_WORD_3D] & ~FIELD_BITS_16_23) | (((first * 255U + 50) / 100 - 0x80) << 16);
    }
    SET(panel_channel_blocks_first_half, words[BLOCK_WORD_3D], word);
    SET(panel_channel_blocks_second_half, words[BLOCK_WORD_3D], word);
    {
        unsigned int block_index = channel > LAST_CHANNEL ? 0 : channel_in;
        word = (panel_channel_blocks_first_half[(unsigned char)block_index]->words[BLOCK_WORD_3E] & ~FIELD_BITS_16_23) | (((second * 255U + 50) / 100 - 0x80) << 16);
    }
    SET(panel_channel_blocks_first_half, words[BLOCK_WORD_3E], word);
    SET(panel_channel_blocks_second_half, words[BLOCK_WORD_3E], word);
    {
        unsigned int block_index = channel > LAST_CHANNEL ? 0 : channel_in;
        word = (panel_channel_blocks_first_half[(unsigned char)block_index]->words[BLOCK_WORD_3F] & ~FIELD_BITS_16_23) | (((third * 255U + 50) / 100 - 0x80) << 16);
    }
    SET(panel_channel_blocks_first_half, words[BLOCK_WORD_3F], word);
    SET(panel_channel_blocks_second_half, words[BLOCK_WORD_3F], word);
}
