/* leon2s FUN_a0096aa4 @ 0xa0096aa4-0xa0096ad8 (13 words), flags -mcpu=v8 -Os -g.
 * Code facts: leaf: r = ARR_a807d7e0 + port * 400; clears the bytes r[0x186], r[0xa1], r[0xe6], r[0x157], r[0x10c],
 * r[0xb8], r[0x181] in this order. void.
 * Fix vs the autoc draft (76.92): real base ARR_a807d7e0 (fw sethi 0xa807d400 | 0x3e0; the draft added 0xa807d400
 * as a constant and named mid-record arrays), void, u8 param. Store order: the +0x186 clear is LAST in the source
 * (sched2 hoists the last store of the block to the front; same pattern as FUN_a00a63a8); the fw order
 * is reached with a1, e6, 157, 10c, b8, 181, 186. Aids: none.
 */
extern unsigned char ARR_a807d7e0[];

void FUN_a0096aa4(unsigned char port)
{
    unsigned char *r = &ARR_a807d7e0[port * 400];

    r[0xa1] = 0;
    r[0xe6] = 0;
    r[0x157] = 0;
    r[0x10c] = 0;
    r[0xb8] = 0;
    r[0x181] = 0;
    r[0x186] = 0;
}
