/* panel_layer4_switch_bits  (FUN_a010fda4)
 *
 * Clear one control bit of the fourth layer and set its counterpart.
 * Name basis: descriptive - 0xD0032000 / 0xD003A000 and their +0x270 registers; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010fda4 @ 0xa010fda4-0xa010fe50 (43 words), flags -mcpu=v8 -O3 -g.
 * Source form: one static helper update_set(set, channel) on the block chosen by a set index (BLOCK(set) =
 * 0xD003A000 for set 1, else 0xD0032000), inlined for set 0 and set 1; panel_layer4_update_enable_bits makes the same writes.
 */
/* Base of the first (set 0) or second (set 1) register set of the layer. */
#define BLOCK(set) ((set) ? 0xd003a000 : 0xd0032000)
#define REG(address) (*(volatile unsigned int *)(address))
#define SECOND_WORD_OFFSET 0x270        /* the register at base | 0x270 */

static void update_set(int set, unsigned char channel)
{
    if (channel == 1) {
        REG(BLOCK(set)) &= ~4;
        REG(BLOCK(set) | SECOND_WORD_OFFSET) |= 2;
    } else {
        REG(BLOCK(set)) &= ~2;
        REG(BLOCK(set) | SECOND_WORD_OFFSET) |= 1;
    }
}

/*
 * In the first set (base 0xD0032000) and then the second set (0xD003A000): for channel 1 clear bit 2 of the
 * base register and set bit 1 of the register at base | 0x270; for any other channel clear bit 1 of the base
 * register and set bit 0 of the register at base | 0x270. No routine in the image calls it.
 */
void panel_layer4_switch_bits(unsigned char channel)
{
    update_set(0, channel);
    update_set(1, channel);
}
