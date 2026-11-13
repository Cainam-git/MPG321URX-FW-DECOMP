/* panel_layer4_set_word9_bit24  (FUN_a010e448)
 *
 * Set or clear bit 24 of word 9 of the fourth layer's register blocks.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010e448 @ 0xa010e448-0xa010e624 (476 bytes). Flags -mcpu=v8 -O3 -g.
 * Source form: channel is an unsigned int holding (unsigned char)channel_arg, computed once before the 'on' test;
 * the first-half channel parameter of set_word9 is unsigned int (second_half_channel stays unsigned char and is
 * masked again from the argument); the SET macro is the panel_layer4_set_format form: one 'unsigned int i' serves the loop
 * and the single-entry arm ('i = n; tab[i]'); with a loop-local counter the end of the second loop is laid out
 * differently.
 */
/* Word 9 (offset 0x24) of a layer register block; the other words are not used here. */
struct layer_block { unsigned int w[10]; };
extern volatile struct layer_block *const panel_layer4_blocks_first_half[2];
extern volatile struct layer_block *const panel_layer4_blocks_second_half[2];

#define LAYER_WORD9_BIT24 0x1000000     /* the bit this routine sets or clears */

/* Write field f of table entry n; a value of n above 1 writes both entries (0 and 1). */
#define SET(tab, n, f, val) do { unsigned int i; if ((n) > 1) { for (i = 0; i <= 1; i++) tab[i]->f = val; } else { i = (n); tab[i]->f = val; } } while (0)

/* Write value to word 9 of the blocks of the channel in both tables. */
static void set_word9(unsigned int first_half_channel, unsigned char second_half_channel, unsigned int value)
{
    SET(panel_layer4_blocks_first_half, first_half_channel, w[9], value);
    SET(panel_layer4_blocks_second_half, second_half_channel, w[9], value);
}

/*
 * Set (on != 0) or clear (on == 0) bit 24 of word 9 in the register blocks of the channel, in the first half's
 * and the second half's table. The new value is built from word 9 of the first half's block (channel above 1
 * reads block 0) and written to both tables; a channel above 1 writes blocks 0 and 1 of each table.
 */
void panel_layer4_set_word9_bit24(unsigned short channel_arg, unsigned char on)
{
    unsigned int channel = (unsigned char)channel_arg;
    unsigned int word9;

    if (on == 0) {
        {
            unsigned char index = channel > 1 ? 0 : channel_arg;
            word9 = panel_layer4_blocks_first_half[index]->w[9];
        }
        set_word9(channel, channel_arg, word9 & ~LAYER_WORD9_BIT24);
    } else {
        {
            unsigned char index = channel > 1 ? 0 : channel_arg;
            word9 = panel_layer4_blocks_first_half[index]->w[9];
        }
        set_word9(channel, channel_arg, word9 | LAYER_WORD9_BIT24);
    }
}
