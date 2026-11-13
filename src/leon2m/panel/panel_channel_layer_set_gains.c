/* panel_channel_layer_set_gains  (FUN_a010d244)
 *
 * Store three percentages of a channel layer and write them as 10-bit values (100 gives 1023).
 * Note: A channel above 2 writes all three channel layers. Nothing calls it.
 * Name basis: descriptive - name rests only on the form of the values: three unsigned 10-bit values, (x * 1023
 *   + 50) / 100, in bits 0..9 of block words 0x3D..0x3F; record bytes +0x38..+0x3A
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010d244, flags -mcpu=v8 -O3 -g. No direct callers. Same SET form as panel_layer_set_half_width.
 * Source form: the channel parameter is an unsigned short and each read index is
 * 'unsigned short idx = ch > 2 ? 0 : c;' (with unsigned int types the incoming c is moved out of %i0); the record
 * bytes are stored in ascending order.
 */
/* Per-channel stored settings: the three bytes at +0x38..+0x3A are written here. */
struct layer_context { unsigned char bytes_0x00_to_0x37[0x38]; unsigned char byte_0x38, byte_0x39, byte_0x3a; };
/* Channel layer register blocks: first half 0xD0030100..0xD0030300, second half 0xD0038100..0xD0038300. */
struct channel_block { unsigned int words[0x40]; };
extern struct layer_context panel_layer_context_ch0, panel_layer_context_ch2, panel_layer_context_ch1;
extern volatile struct channel_block *const panel_channel_blocks_first_half[3];
extern volatile struct channel_block *const panel_channel_blocks_second_half[3];

#define LAST_CHANNEL 2          /* channel numbers above this mean "all three channels" */
#define BLOCK_WORD_3D 0x3d      /* offsets 0xF4, 0xF8, 0xFC */
#define BLOCK_WORD_3E 0x3e
#define BLOCK_WORD_3F 0x3f
#define FIELD_BITS_0_9 0x3ff

/* Store val in field f of the block of channel 'channel'; a channel above 2 stores it in all three blocks of table tab. */
#define SET(tab, f, val) do { if (channel > LAST_CHANNEL) { unsigned int i; for (i = 0; i <= LAST_CHANNEL; i++) tab[i]->f = val; } else tab[channel]->f = val; } while (0)

/*
 * Store first, second and third in bytes +0x38, +0x39 and +0x3A of the channel's stored settings (channel 1 and
 * 2 have their own record, every other number uses channel 0's), and in bits 0..9 of block words 0x3D, 0x3E
 * and 0x3F of its register blocks in both halves, each scaled as (value * 1023 + 50) / 100 (100 gives 1023).
 * The other bits of each word are kept from the first-half block (channel 0 when the channel is above 2).
 * A channel above 2 writes all three blocks. Nothing calls this routine; panel_channel_layer_set_offsets
 * writes bits 16..23 of the same three words.
 */
void panel_channel_layer_set_gains(unsigned short channel_in, unsigned char first, unsigned char second, unsigned char third)
{
    unsigned char channel = channel_in;
    struct layer_context *context;
    unsigned int word;

    context = &panel_layer_context_ch1;
    if (channel != 1) {
        context = &panel_layer_context_ch0;
        if (channel == 2) context = &panel_layer_context_ch2;
    }
    context->byte_0x38 = first;
    context->byte_0x39 = second;
    context->byte_0x3a = third;
    {
        unsigned short block_index = channel > LAST_CHANNEL ? 0 : channel_in;
        word = (panel_channel_blocks_first_half[(unsigned char)block_index]->words[BLOCK_WORD_3D] & ~FIELD_BITS_0_9) | (first * 1023U + 50) / 100;
    }
    SET(panel_channel_blocks_first_half, words[BLOCK_WORD_3D], word);
    SET(panel_channel_blocks_second_half, words[BLOCK_WORD_3D], word);
    {
        unsigned short block_index = channel > LAST_CHANNEL ? 0 : channel_in;
        word = (panel_channel_blocks_first_half[(unsigned char)block_index]->words[BLOCK_WORD_3E] & ~FIELD_BITS_0_9) | (second * 1023U + 50) / 100;
    }
    SET(panel_channel_blocks_first_half, words[BLOCK_WORD_3E], word);
    SET(panel_channel_blocks_second_half, words[BLOCK_WORD_3E], word);
    {
        unsigned short block_index = channel > LAST_CHANNEL ? 0 : channel_in;
        word = (panel_channel_blocks_first_half[(unsigned char)block_index]->words[BLOCK_WORD_3F] & ~FIELD_BITS_0_9) | (third * 1023U + 50) / 100;
    }
    SET(panel_channel_blocks_first_half, words[BLOCK_WORD_3F], word);
    SET(panel_channel_blocks_second_half, words[BLOCK_WORD_3F], word);
}
