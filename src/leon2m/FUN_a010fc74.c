/* leon2m FUN_a010fc74 @ 0xa010fc74-0xa010fda4 (76 words), flags -mcpu=v8 -O3 -g.
 *
 * void(u8 ch). For ch 0, 1 or 2, sets bit 8 + ch and then clears bit 1 + ch of hardware register 0xD0030004
 * (two read-modify-writes), then does the same on 0xD0038004. Any other ch writes nothing.
 * Source form: one static helper sel(base, ch) with a switch on ch, inlined twice; the base is a const parameter,
 * so every case loads its own register address.
 * Compiler aid: the block '{ struct Aid s = { ch }; }' between the two calls emits no instructions. Its
 * initialisation puts a CLOBBER of the unused structure in front of the second switch's first compare; GCSE jump
 * bypassing only redirects a block holding a single set before its jump, so the second switch's tests are kept
 * after each case of the first switch (the firmware re-tests ch there), and the dead CLOBBER is deleted later.
 */
#define R(b) (*(volatile unsigned int *)((b) | 4))

struct Aid { unsigned int v; };

static void sel(const unsigned int b, unsigned char c)
{
    switch (c) {
    case 0:
        R(b) |= 0x100;
        R(b) &= ~2u;
        break;
    case 1:
        R(b) |= 0x200;
        R(b) &= ~4u;
        break;
    case 2:
        R(b) |= 0x400;
        R(b) &= ~8u;
        break;
    }
}

void FUN_a010fc74(unsigned char ch)
{
    sel(0xd0030000, ch);
    {
        struct Aid s = { ch };
    }
    sel(0xd0038000, ch);
}
