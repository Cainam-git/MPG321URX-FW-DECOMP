/* leon2m FUN_a010f8fc @ 0xa010f8fc-0xa010fc74 (222 words), flags -mcpu=v8 -O3 -g.
 *
 * void(u8 ch). Picks the record p (ch 1: 0xA802D7C4, ch 2: 0xA802D784, else 0xA802D744) and w = halfword +0x08
 * of the row DAT_a802d6a4 points to, shifted right by 1. For ch 0, 1 or 2 (any other ch writes nothing):
 *   on(base):  sets bit 8 + ch, then clears bit 1 + ch of register base + 4;
 *   off(base): sets bit 1 + ch, then clears bit 8 + ch of register base + 4.
 * p->h14 >= w: on(0xD0030000), off(0xD0038000); p->h14 + p->h16 > w (signed): off on both; otherwise
 * off(0xD0030000), on(0xD0038000).
 * Source form: on and off are static helpers with a switch on ch, inlined per call; the side 0 / 1 parameter picks
 * the register block (macro R: 0xD0030004 or 0xD0038004), so every case builds its own register address and the
 * second switch tests ch again (as FUN_a010fc74).
 */
#define R(s) (*(volatile unsigned int *)((s) ? 0xd0038004 : 0xd0030004))
struct ChBlk { unsigned char pad[0x14]; unsigned short h14, h16; };
struct PanelParam { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short h08; };
extern struct ChBlk DAT_a802d744, DAT_a802d784, DAT_a802d7c4;
extern struct PanelParam *DAT_a802d6a4;

static void blk_on(int side, unsigned char c)
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

static void blk_off(int side, unsigned char c)
{
    switch (c) {
    case 0:
        R(side) |= 2;
        R(side) &= ~0x100u;
        break;
    case 1:
        R(side) |= 4;
        R(side) &= ~0x200u;
        break;
    case 2:
        R(side) |= 8;
        R(side) &= ~0x400u;
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
        blk_on(0, ch);
        blk_off(1, ch);
    } else if (p->h14 + p->h16 > w) {
        blk_off(0, ch);
        blk_off(1, ch);
    } else {
        blk_off(0, ch);
        blk_on(1, ch);
    }
}
