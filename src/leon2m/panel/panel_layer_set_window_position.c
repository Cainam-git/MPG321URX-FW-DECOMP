/* panel_layer_set_window_position  (FUN_a010bdcc)
 *
 * Set the window position of a channel layer.
 * Name basis: derived - position words with the half offset; word 5 of the layer table; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010bdcc, flags -mcpu=v8 -O3 -g. The compiler also inlines this routine into
 * panel_channel_layer_setup_window.
 * Source form: struct layer_context is declared as in panel_channel_layer_setup_window: the two positions at
 * +0x18 as 16-bit bitfields of one word, and +0x20 as a union with a bitfield view of the same word.
 */
/* Stored settings of a channel layer (field names shared with the other panel_layer_* files). */
struct layer_context {
    unsigned int base;                          /* +0x00 */
    unsigned char pad4[8];
    unsigned short source_width, source_lines;  /* +0x0C, +0x0E */
    unsigned char pad10[4];
    unsigned short window_x, window_width;      /* +0x14, +0x16 */
    unsigned int first_half_position:16, second_half_position:16;  /* +0x18, +0x1A */
    unsigned char pad1c[4];
    union { struct { unsigned short low_word, high_word; } h; struct { unsigned int low_word:16, high_word:16; } b; } words20; /* +0x20, +0x22 */
    unsigned char bits_per_pixel, format, byte_0x26; /* +0x24.. */
    unsigned char pad27[0x17];
    unsigned char flags, pad3f;                 /* +0x3E */
};
struct PanelParam { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short h08; };
extern struct PanelParam *panel_working_row_ptr;
extern struct layer_context panel_layer_context_ch0, panel_layer_context_ch2, panel_layer_context_ch1;
extern volatile unsigned int *panel_channel_blocks_first_half[], *panel_channel_blocks_second_half[];
extern unsigned char panel_layer_position_offset, panel_layer_update_strobe_enabled;
extern void panel_layer_set_buffer(unsigned char, unsigned char, unsigned short, unsigned short, unsigned int);
extern void panel_layer_set_output_size(unsigned char, unsigned char, unsigned short, unsigned short);
extern unsigned short timer_get_ticks16(void);
#define R(a) (*(volatile unsigned int *)(a))

#define LAYER_WORD_POSITION 5           /* word of the register block: position << 16 | low word */
#define LAYER_FLAG_BIT0     1           /* flags bit 0: the second half subtracts the position offset */

/* The stored settings of a channel: channels 1 and 2 have their own record, every other number uses
   channel 0's. */
static struct layer_context *ctx(unsigned char ch)
{
    struct layer_context *p;
    switch (ch) {
    case 1: p = &panel_layer_context_ch1; break;
    case 2: p = &panel_layer_context_ch2; break;
    default: p = &panel_layer_context_ch0; break;
    }
    return p;
}

/*
 * Store a channel layer's position for one half of the output and program it.
 *
 *   ch        channel layer 0..2
 *   half      0: first half (stored at +0x18), otherwise the second half (+0x1A)
 *   position  goes to bits 16..31 of word 5 of the half's register block
 *   low_word  stored at +0x20 and written to bits 0..15 of the same word
 *
 * In the second half the written position is shifted by panel_layer_position_offset (0x10 on chip revisions
 * above 0x81, see panel_output_setup_path): subtracted when flags bit 0 is set, added otherwise. The stored
 * position is the one passed in.
 */
void panel_layer_set_window_position(unsigned char ch, unsigned char half, unsigned short position, unsigned short low_word)
{
    struct layer_context *layer;
    unsigned int value;

    layer = ctx(ch);
    if (half == 0) { layer->first_half_position = position; value = position; }
    else {
        layer->second_half_position = position;
        if (layer->flags & LAYER_FLAG_BIT0) value = position - panel_layer_position_offset; else value = position + panel_layer_position_offset;
    }
    layer->words20.h.low_word = low_word;
    value = value << 16 | low_word;
    if (half == 0) panel_channel_blocks_first_half[ch][LAYER_WORD_POSITION] = value; else panel_channel_blocks_second_half[ch][LAYER_WORD_POSITION] = value;
}
