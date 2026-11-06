/* leon2m FUN_a010fc74 @ 0xa010fc74-0xa010fda4 (76 words), flags -mcpu=v8 -O3 -g.
 *
 * void(u8 ch). For ch 0, 1 or 2, sets bit 8 + ch and then clears bit 1 + ch of hardware register 0xD0030004
 * (two read-modify-writes), then does the same on 0xD0038004. Any other ch writes nothing.
 * Source form: one static helper sel(side, ch) with a switch on ch, inlined twice; side 0 / 1 picks the register
 * block (macro R: 0xD0030004 or 0xD0038004), so every case loads its own register address and the second switch
 * tests ch again.
 */
#define R(s) (*(volatile unsigned int *)((s) ? 0xd0038004 : 0xd0030004))

static void sel(int side, unsigned char c)
{
    switch (c) {
    case 0:
        R(side) |= 0x100;
        R(side) &= ~2u;
        break;
    case 1:
        R(side) |= 0x200;
        R(side) &= ~4u;
        break;
    case 2:
        R(side) |= 0x400;
        R(side) &= ~8u;
        break;
    }
}

void FUN_a010fc74(unsigned char ch)
{
    sel(0, ch);
    sel(1, ch);
}
