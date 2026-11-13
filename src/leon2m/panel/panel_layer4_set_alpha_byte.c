/* panel_layer4_set_alpha_byte  (FUN_a010c54c)
 *
 * Store a byte of the fourth layer and write it to block word 5.
 * Name basis: descriptive - record byte +0x26; unused
 *
 * Matching notes
 * --------------
 * FUN_a010c54c, flags -mcpu=v8 -O3 -g. Leaf. Nothing in the image calls or points to it.
 * Source form: value is an unsigned int parameter; its masked copy is taken into a local before the byte store.
 */
/* Per-channel stored settings of the fourth layer; only the byte at +0x26 is used here. */
struct layer4_context { unsigned char bytes_0x00_to_0x25[0x26]; unsigned char byte_0x26; };

#define LAST_LAYER4_CHANNEL 1   /* channel numbers above this mean "both channels" */
#define LAYER4_WORD_5 5         /* block word written here */

extern struct layer4_context panel_layer4_context_ch0, panel_layer4_context_ch1;
extern volatile unsigned int *const panel_layer4_blocks_first_half[];
extern volatile unsigned int *const panel_layer4_blocks_second_half[];

/*
 * Store the low byte of value in byte +0x26 of the stored settings of channel 1 (channel 1) or channel 0 (every
 * other channel number), and in word 5 of the fourth-layer register block of the channel in both halves
 * (the whole word becomes that byte). A channel above 1 writes both blocks of both tables.
 */
void panel_layer4_set_alpha_byte(unsigned char channel, unsigned int value)
{
    struct layer4_context *context = &panel_layer4_context_ch0;
    unsigned int i, byte_value;

    if (channel == 1)
        context = &panel_layer4_context_ch1;
    byte_value = (unsigned char)value;
    context->byte_0x26 = value;
    if (channel > LAST_LAYER4_CHANNEL) {
        for (i = 0; i < 2; i++)
            panel_layer4_blocks_first_half[i][LAYER4_WORD_5] = byte_value;
    } else
        panel_layer4_blocks_first_half[channel][LAYER4_WORD_5] = byte_value;
    if (channel > LAST_LAYER4_CHANNEL) {
        for (i = 0; i < 2; i++)
            panel_layer4_blocks_second_half[i][LAYER4_WORD_5] = byte_value;
    } else
        panel_layer4_blocks_second_half[channel][LAYER4_WORD_5] = byte_value;
}
