/* panel_layer_set_half_width  (FUN_a010edbc)
 *
 * Program half of the panel width into the channel register blocks of both halves.
 * Name basis: descriptive - from the working panel timing row; twin of panel_layer4_set_half_width (the
 *   fourth-layer version); unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010edbc @ 0xa010edbc-0xa010ef64 (424 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: the form of panel_layer_clear_word1_bit14: a switch selecting the context pointer;
 * 'source_channel = channel; if (channel > 2) source_channel = 0;' for the read index; separate
 * 'if (channel > 2) loop / else' statements per table and word.
 */
struct layer_context { unsigned char pad0[0x3e]; unsigned char flags; };
/* The working copy of the active panel timing row; only its width is read. */
struct panel_timing_row { unsigned int flags; unsigned short half_0x04; unsigned char display_mode, bpc; unsigned short active_size0; };
extern struct layer_context panel_layer_context_ch0, panel_layer_context_ch2, panel_layer_context_ch1;
extern struct panel_timing_row *panel_working_row_ptr;
extern volatile unsigned int *const panel_channel_blocks_first_half[];
extern volatile unsigned int *const panel_channel_blocks_second_half[];

#define LAST_CHANNEL 2                  /* channel numbers above this mean "all three channels" */
#define LAYER_WORD_1 1
#define LAYER_WORD_3 3                  /* bits 16..31: half the panel width */
#define WORD1_BIT14  0x4000
#define LAYER_FLAG_BIT0 1               /* set here; panel_layer_clear_word1_bit14 clears it */

/*
 * Set bit 0 of the channel's context flags, write half the panel width (active_size0 of the working timing
 * row) to bits 16..31 of block word 3 and set bit 14 of block word 1, in the channel's register blocks of both
 * halves. With flag bit 0 set, panel_channel_layer_setup_window reflects the window's positions inside each
 * half. panel_layer_clear_word1_bit14 undoes the flag and bit 14.
 *
 *   channel  0..2 (1 and 2 have their own context, every other number uses channel 0's), or a number above
 *            2 for the blocks of all three channels
 *
 * Bit 14 is ORed into word 1 as read from the channel's first-half block (channel 0 when the channel is above 2).
 * The fourth layer has its own version, panel_layer4_set_half_width. Nothing in the image calls this routine.
 */
void panel_layer_set_half_width(unsigned char channel)
{
    struct layer_context *context;
    unsigned int half_width_word, word1, i;
    unsigned char source_channel;

    switch (channel) {
    case 1:
        context = &panel_layer_context_ch1;
        break;
    case 2:
        context = &panel_layer_context_ch2;
        break;
    default:
        context = &panel_layer_context_ch0;
        break;
    }
    context->flags |= LAYER_FLAG_BIT0;
    half_width_word = (panel_working_row_ptr->active_size0 >> 1) << 16;
    if (channel > LAST_CHANNEL) {
        for (i = 0; i <= LAST_CHANNEL; i++)
            panel_channel_blocks_first_half[i][LAYER_WORD_3] = half_width_word;
    } else
        panel_channel_blocks_first_half[channel][LAYER_WORD_3] = half_width_word;
    if (channel > LAST_CHANNEL) {
        for (i = 0; i <= LAST_CHANNEL; i++)
            panel_channel_blocks_second_half[i][LAYER_WORD_3] = half_width_word;
    } else
        panel_channel_blocks_second_half[channel][LAYER_WORD_3] = half_width_word;
    source_channel = channel;
    if (channel > LAST_CHANNEL)
        source_channel = 0;
    word1 = panel_channel_blocks_first_half[source_channel][LAYER_WORD_1] | WORD1_BIT14;
    if (channel > LAST_CHANNEL) {
        for (i = 0; i <= LAST_CHANNEL; i++)
            panel_channel_blocks_first_half[i][LAYER_WORD_1] = word1;
    } else
        panel_channel_blocks_first_half[channel][LAYER_WORD_1] = word1;
    if (channel > LAST_CHANNEL) {
        for (i = 0; i <= LAST_CHANNEL; i++)
            panel_channel_blocks_second_half[i][LAYER_WORD_1] = word1;
    } else
        panel_channel_blocks_second_half[channel][LAYER_WORD_1] = word1;
}
