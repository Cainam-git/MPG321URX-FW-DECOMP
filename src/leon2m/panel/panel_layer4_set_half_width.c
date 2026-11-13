/* panel_layer4_set_half_width  (FUN_a010f7a4)
 *
 * Write half the row width to word 6 or 7 of both fourth-layer register sets and set bit 20 or 21.
 * Note: Also sets bit 0 of the layer context's flags. Nothing calls it.
 * Name basis: descriptive - half of row halfword +8 to 0xD0032018 / 0xD003201C and their +0x8000 twins; bit 20
 *   or 21 of word 0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010f7a4 @ 0xa010f7a4, flags -mcpu=v8 -O3 -g -msoft-float. Reads the panel row through
 * panel_working_row_ptr; the row's halfword at +0x08 is shifted right by one into an unsigned int.
 */
#define REG(address) (*(volatile unsigned int *)(address))
struct layer_context { unsigned char pad[0x3e]; unsigned char flags; };
/* Only the halfword at +0x08 is used here. */
struct panel_row_head { unsigned int word_0x00; unsigned short half_0x04; unsigned char byte_0x06, byte_0x07; unsigned short half_0x08; };
extern struct layer_context panel_layer4_context_ch0, panel_layer4_context_ch1;
extern struct panel_row_head *panel_working_row_ptr;

#define LAYER_FLAG_BIT0 1               /* cleared again by panel_layer4_clear_half_width_bit */
#define WORD0_BIT20     0x100000        /* channel 0 */
#define WORD0_BIT21     0x200000        /* any other channel */

/*
 * Set bit 0 of the layer context's flags, then write half of the working row's halfword at +0x08 to word 6
 * (channel 0, 0x...018) or word 7 (any other channel, 0x...01C) of the layer's register set, in the first set
 * (0xD0032000) and in the second set (0xD003A000), and set bit 20 (channel 0) or bit 21 (any other channel) in
 * word 0 of both sets. panel_layer4_clear_half_width_bit undoes the flag and the bit. Channel 1 uses the second context,
 * every other value the first. No routine in the image calls it.
 */
void panel_layer4_set_half_width(unsigned char channel)
{
    struct layer_context *context;
    unsigned int half_value;

    context = &panel_layer4_context_ch0;
    if (channel == 1) context = &panel_layer4_context_ch1;
    context->flags |= LAYER_FLAG_BIT0;
    half_value = panel_working_row_ptr->half_0x08 >> 1;
    if (channel == 0) {
        REG(0xd0032018) = half_value;
        REG(0xd003a018) = half_value;
        REG(0xd0032000) |= WORD0_BIT20;
        REG(0xd003a000) |= WORD0_BIT20;
    } else {
        REG(0xd003201c) = half_value;
        REG(0xd003a01c) = half_value;
        REG(0xd0032000) |= WORD0_BIT21;
        REG(0xd003a000) |= WORD0_BIT21;
    }
}
