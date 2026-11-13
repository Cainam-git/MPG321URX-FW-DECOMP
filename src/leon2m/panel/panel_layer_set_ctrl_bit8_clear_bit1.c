/* panel_layer_set_ctrl_bit8_clear_bit1  (FUN_a010fc74)
 *
 * For channel 0..2: set bit 8 + channel, clear bit 1 + channel of layer control word 1, both halves.
 * Note: Any other channel writes nothing. Nothing calls it.
 * Name basis: descriptive - 0xD0030004, then 0xD0038004
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010fc74 @ 0xa010fc74-0xa010fda4 (76 words), flags -mcpu=v8 -O3 -g.
 * Source form: one static helper update_set(set, channel) with a switch on the channel, inlined twice; set 0 / 1
 * picks the register (macro REG: 0xD0030004 or 0xD0038004), so every case loads its own register address and the
 * second switch tests the channel again.
 */
/* Word 1 of the first (set 0) or second (set 1) register set; the second sits 0x8000 higher. */
#define REG(set) (*(volatile unsigned int *)((set) ? 0xd0038004 : 0xd0030004))

static void update_set(int set, unsigned char channel)
{
    switch (channel) {
    case 0:
        REG(set) |= 0x100;
        REG(set) &= ~2u;
        break;
    case 1:
        REG(set) |= 0x200;
        REG(set) &= ~4u;
        break;
    case 2:
        REG(set) |= 0x400;
        REG(set) &= ~8u;
        break;
    }
}

/*
 * For channel 0, 1 or 2: in register 0xD0030004 set bit 8 + channel, then clear bit 1 + channel (two separate
 * read-modify-write steps), and do the same in 0xD0038004. Any other channel writes nothing.
 * No routine in the image calls it.
 */
void panel_layer_set_ctrl_bit8_clear_bit1(unsigned char channel)
{
    update_set(0, channel);
    update_set(1, channel);
}
