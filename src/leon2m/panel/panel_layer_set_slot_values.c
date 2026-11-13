/* panel_layer_set_slot_values  (FUN_a010f064)
 *
 * Write two packed values into one of two slots of a channel's second-set blocks in both halves.
 * Note: Slot 0 = words 2 and 3 with control bit 0, any other = words 4 and 5 with bit 4; word 6 always gets
 *   0x50005. Nothing calls it.
 * Name basis: descriptive - two values packed as (upper / 2) << 16 | lower, a control bit ORed into word 0,
 *   0x50005 into word 6
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010f064 @ 0xa010f064-0xa010f50c (1192 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: the first packed value of each arm is written by a static helper (write_word2 / write_word4, as in
 *   panel_layer_clear_word0_bit0_or_bit4) called with channel and the raw parameter channel_in as its two channel numbers;
 *   the firmware masks the parameter again ('and %i0, 0xff') for the second-half write of that value while every
 *   other write uses channel.
 */
/* The first seven words of a second-set layer register block (0xD0030030..0xD0030070, second half +0x8000). */
struct alt_block { unsigned int control, word_1, word_2, word_3, word_4, word_5, word_6; };
extern volatile struct alt_block *const panel_layer_alt_blocks_first_half[3];
extern volatile struct alt_block *const panel_layer_alt_blocks_second_half[3];

#define LAST_CHANNEL 2                  /* channel numbers above this mean "all three channels" */
#define CONTROL_SLOT0_BIT 0x01          /* set when slot 0 (words 2 and 3) is written */
#define CONTROL_SLOT1_BIT 0x10          /* set when slot 1 (words 4 and 5) is written */
#define WORD6_VALUE       0x50005       /* written on every call; meaning not shown */

/* Field f of block n of table, or of blocks 0..2 when n is above 2. */
#define WRITE_BLOCKS(table, n, f, val) { if ((n) > LAST_CHANNEL) { unsigned int i; for (i = 0; i <= LAST_CHANNEL; i++) table[i]->f = val; } \
                              else table[n]->f = val; }

static void write_word2(unsigned char channel, unsigned char channel_again, unsigned int value)
{
    WRITE_BLOCKS(panel_layer_alt_blocks_first_half, channel, word_2, value);
    WRITE_BLOCKS(panel_layer_alt_blocks_second_half, channel_again, word_2, value);
}

static void write_word4(unsigned char channel, unsigned char channel_again, unsigned int value)
{
    WRITE_BLOCKS(panel_layer_alt_blocks_first_half, channel, word_4, value);
    WRITE_BLOCKS(panel_layer_alt_blocks_second_half, channel_again, word_4, value);
}

/*
 * Write two packed values into one of the two slots of a channel's second-set register blocks, in both halves.
 *
 *   channel_in    0..2, or a number above 2 for all three channels
 *   slot          0: words 2 and 3, control bit 0; any other value: words 4 and 5, control bit 4
 *   first_upper   halved and put in bits 16..31 of the first value
 *   first_lower   bits 0..15 of the first value
 *   second_upper  halved and put in bits 16..31 of the second value
 *   second_lower  bits 0..15 of the second value
 *
 * The slot's control bit is ORed into word 0 as read from the channel's first-half block (channel 0 when the
 * channel is above 2); bits already set stay set. Word 6 gets 0x50005 every time. Nothing in the image calls this
 * routine.
 */
void panel_layer_set_slot_values(unsigned short channel_in, unsigned char slot, unsigned short first_upper, unsigned short first_lower, unsigned short second_upper,
                  unsigned short second_lower)
{
    unsigned char channel = channel_in;
    unsigned int first_value, second_value, word;

    first_value = ((first_upper >> 1) << 16) | first_lower;
    second_value = ((second_upper >> 1) << 16) | second_lower;
    {
        unsigned char source_channel = channel > LAST_CHANNEL ? 0 : channel_in;
        word = panel_layer_alt_blocks_first_half[source_channel]->control;
    }
    if (slot == 0) {
        write_word2(channel, channel_in, first_value);
        WRITE_BLOCKS(panel_layer_alt_blocks_first_half, channel, word_3, second_value);
        WRITE_BLOCKS(panel_layer_alt_blocks_second_half, channel, word_3, second_value);
        word |= CONTROL_SLOT0_BIT;
        WRITE_BLOCKS(panel_layer_alt_blocks_first_half, channel, control, word);
        WRITE_BLOCKS(panel_layer_alt_blocks_second_half, channel, control, word);
    } else {
        write_word4(channel, channel_in, first_value);
        WRITE_BLOCKS(panel_layer_alt_blocks_first_half, channel, word_5, second_value);
        WRITE_BLOCKS(panel_layer_alt_blocks_second_half, channel, word_5, second_value);
        word |= CONTROL_SLOT1_BIT;
        WRITE_BLOCKS(panel_layer_alt_blocks_first_half, channel, control, word);
        WRITE_BLOCKS(panel_layer_alt_blocks_second_half, channel, control, word);
    }
    word = WORD6_VALUE;
    WRITE_BLOCKS(panel_layer_alt_blocks_first_half, channel, word_6, word);
    WRITE_BLOCKS(panel_layer_alt_blocks_second_half, channel, word_6, word);
}
