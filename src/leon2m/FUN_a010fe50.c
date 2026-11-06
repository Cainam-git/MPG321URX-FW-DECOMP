/* leon2m FUN_a010fe50 @ 0xa010fe50-0xa0110084 (141 words), flags -mcpu=v8 -O3 -g.
 *
 * void(u8 ch). Picks the record p = 0xA802D804 for ch == 1, else 0xA802D704, and w = halfword +0x08 of the row
 * DAT_a802d6a4 points to, shifted right by 1. Two register blocks, 0xD0032000 and 0xD003A000:
 *   off(base): clears bit 2 (ch == 1) or bit 1 (other ch) of base, sets bit 1 or bit 0 of base | 0x270;
 *   on(base):  clears bits 29..31 of base, sets 0x10000004 or 0x10000002 in base, clears bit 1 or bit 0 of
 *              base | 0x270.
 * p->h14 >= w: off(0xD0032000), on(0xD003A000); p->h14 + p->h16 > w: on both; otherwise on(0xD0032000),
 * off(0xD003A000).
 * Source form: off and on are static helpers inlined per call; the side 0 / 1 parameter picks the register block
 * (macro B: 0xD0032000 or 0xD003A000), so every arm builds its own register address and off() after on() tests ch
 * again (as FUN_a010f8fc); the +0x270 register is written as 'base | 0x270'.
 */
#define B(s) ((s) ? 0xd003a000 : 0xd0032000)
#define R(a) (*(volatile unsigned int *)(a))
struct ChBlk { unsigned char pad[0x14]; unsigned short h14, h16; };
struct PanelParam { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short h08; };
extern struct ChBlk DAT_a802d704, DAT_a802d804;
extern struct PanelParam *DAT_a802d6a4;

static void blk_off(int side, unsigned char ch)
{
    if (ch == 1) {
        R(B(side)) &= ~4;
        R(B(side) | 0x270) |= 2;
    } else {
        R(B(side)) &= ~2;
        R(B(side) | 0x270) |= 1;
    }
}

static void blk_on(int side, unsigned char ch)
{
    R(B(side)) &= ~0xe0000000;
    if (ch == 1) {
        R(B(side)) |= 0x10000004;
        R(B(side) | 0x270) &= ~2;
    } else {
        R(B(side)) |= 0x10000002;
        R(B(side) | 0x270) &= ~1;
    }
}

void FUN_a010fe50(unsigned char ch)
{
    struct ChBlk *p;
    unsigned short w;

    p = &DAT_a802d704;
    if (ch == 1) p = &DAT_a802d804;
    w = DAT_a802d6a4->h08 >> 1;
    if (p->h14 >= w) {
        blk_off(0, ch);
        blk_on(1, ch);
    } else if (p->h14 + p->h16 > w) {
        blk_on(0, ch);
        blk_on(1, ch);
    } else {
        blk_on(0, ch);
        blk_off(1, ch);
    }
}
