/* panel_layer4_clear_half_width_bit  (FUN_a010f864)
 *
 * Clear bit 0 of a fourth-layer context's flags and bit 20 or 21 of word 0 of both register sets.
 * Note: Undoes the flag and the bit that panel_layer4_set_half_width sets. Nothing calls it.
 * Name basis: descriptive - flags byte +0x3E bit 0; bit 20 (channel 0) or 21 (any other) of 0xD0032000 /
 *   0xD003A000
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010f864 @ 0xa010f864-0xa010f8fc (38 words), flags -mcpu=v8 -O3 -g.
 */
#define REG(address) (*(volatile unsigned int *)(address))
struct layer_context { unsigned char pad[0x3e]; unsigned char flags; };
extern struct layer_context panel_layer4_context_ch0, panel_layer4_context_ch1;

#define LAYER_FLAG_BIT0 1               /* set by panel_layer4_set_half_width */
#define WORD0_BIT20     0x100000        /* channel 0 */
#define WORD0_BIT21     0x200000        /* any other channel */

/*
 * Counterpart of panel_layer4_set_half_width: clear bit 0 of the layer context's flags and bit 20 (channel 0)
 * or bit 21 (any other channel) in word 0 of the first set (0xD0032000) and of the second set (0xD003A000).
 * Channel 1 uses the second context, every other value the first. No routine in the image calls it.
 */
void panel_layer4_clear_half_width_bit(unsigned char channel)
{
    struct layer_context *context;

    context = &panel_layer4_context_ch0;
    if (channel == 1) context = &panel_layer4_context_ch1;
    context->flags &= ~LAYER_FLAG_BIT0;
    if (channel == 0) {
        REG(0xd0032000) &= ~WORD0_BIT20;
        REG(0xd003a000) &= ~WORD0_BIT20;
    } else {
        REG(0xd0032000) &= ~WORD0_BIT21;
        REG(0xd003a000) &= ~WORD0_BIT21;
    }
}
