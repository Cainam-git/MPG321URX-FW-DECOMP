/* leon2m FUN_a010f8fc @ 0xa010f8fc-0xa010fc74 (222 words), flags -mcpu=v8 -O3 -g.
 *
 * void(u8 ch). Picks the record p (ch 1: 0xA802D7C4, ch 2: 0xA802D784, else 0xA802D744) and w = halfword +0x08
 * of the row DAT_a802d6a4 points to, shifted right by 1. For ch 0, 1 or 2 (any other ch writes nothing):
 *   on(base):  sets bit 8 + ch, then clears bit 1 + ch of register base + 4;
 *   off(base): sets bit 1 + ch, then clears bit 8 + ch of register base + 4.
 * p->h14 >= w: on(0xD0030000), off(0xD0038000); p->h14 + p->h16 > w (signed): off on both; otherwise
 * off(0xD0030000), on(0xD0038000).
 * Source form: on and off are static helpers with a switch on ch, inlined per call, with the base as a const
 * parameter (every case builds its own address).
 * Compiler aid: the block '{ struct Aid s = { ch }; }' between the two helper calls of each arm emits no
 * instructions. Its initialisation puts a CLOBBER of the unused structure in front of the second switch's first
 * compare; GCSE jump bypassing only redirects a block holding a single set before its jump, so the second switch's
 * tests are kept after each case of the first (the firmware re-tests ch there), and the dead CLOBBER is deleted
 * later.
 */
struct Aid { unsigned int v; };
#define R(b) (*(volatile unsigned int *)((b) | 4))
struct ChBlk { unsigned char pad[0x14]; unsigned short h14, h16; };
struct PanelParam { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short h08; };
extern struct ChBlk DAT_a802d744, DAT_a802d784, DAT_a802d7c4;
extern struct PanelParam *DAT_a802d6a4;

static void blk_on(const unsigned int b, unsigned char c)
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

static void blk_off(const unsigned int b, unsigned char c)
{
    switch (c) {
    case 0:
        R(b) |= 2;
        R(b) &= ~0x100u;
        break;
    case 1:
        R(b) |= 4;
        R(b) &= ~0x200u;
        break;
    case 2:
        R(b) |= 8;
        R(b) &= ~0x400u;
        break;
    }
}

void FUN_a010f8fc(unsigned char ch)
{
    struct ChBlk *p;
    unsigned short w;

    switch (ch) {
    case 1: p = &DAT_a802d7c4; break;
    case 2: p = &DAT_a802d784; break;
    default: p = &DAT_a802d744; break;
    }
    w = DAT_a802d6a4->h08 >> 1;
    if (p->h14 >= w) {
        blk_on(0xd0030000, ch);
        {
            struct Aid s = { ch };
        }
        blk_off(0xd0038000, ch);
    } else if (p->h14 + p->h16 > w) {
        blk_off(0xd0030000, ch);
        {
            struct Aid s = { ch };
        }
        blk_off(0xd0038000, ch);
    } else {
        blk_off(0xd0030000, ch);
        {
            struct Aid s = { ch };
        }
        blk_on(0xd0038000, ch);
    }
}
