/* leon2s FUN_a0096aa4 @ 0xa0096aa4-0xa0096ad8 (13 words), flags -mcpu=v8 -Os -g.
 * Leaf: r = ARR_a807d7e0 + port * 400; clears the bytes r[0x186], r[0xa1], r[0xe6], r[0x157], r[0x10c],
 * r[0xb8], r[0x181] in this order. void, u8 param.
 * The base is ARR_a807d7e0 (firmware sethi 0xa807d400 | 0x3e0).
 * Source form: the +0x186 clear is last in the source (sched2 hoists the last store of the block to the
 * front; same pattern as FUN_a00a63a8): source order a1, e6, 157, 10c, b8, 181, 186.
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
