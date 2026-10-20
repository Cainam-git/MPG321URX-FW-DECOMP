/* leon2m FUN_a0100434 @ 0xa0100434-0xa0100468 (13 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/13 mismatches.
 * Code facts: v = FUN_a00f1a90(blk, 4) (u8 register read); if (v & 3) == 3 returns (v >> 2) & 3,
 * else 0xff. blk is a u8 param.
 * Fixes vs the autoc draft (54.29): the tests are on the READ value v, not on the param (the draft
 * tested param_1); the == 3 arm comes first in the source (the 'r = ...; if (!=) r = 0xff' form
 * puts the 'and 3' before the srl). int result variable, u8 return type. Aids: none.
 */
extern unsigned char FUN_a00f1a90(unsigned char, unsigned char);

unsigned char FUN_a0100434(unsigned char blk)
{
    unsigned char v;
    int r;

    v = FUN_a00f1a90(blk, 4);
    if ((v & 3) == 3)
        r = (v >> 2) & 3;
    else
        r = 0xff;
    return r;
}
