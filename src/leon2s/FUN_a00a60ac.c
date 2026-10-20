/* leon2s FUN_a00a60ac @ 0xa00a60ac-0xa00a60d8 (11 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0/11 mismatches.
 * Code facts: leaf; returns 2 unless port (u8) == 0, then bit 0 of word +0xb0 of the config record
 * that the pointer table DAT_a807dc04[port] points to (ld [base + port], ld [+0xb0], and 1).
 * Fixes vs the autoc draft (54.55): the pointer is indexed by port (fw keeps the [base + %o0] form;
 * port is 0 there), and the result/return type is a full unsigned int (a u8 result adds the 'and 3'
 * nonzero-bits extension the fw does not have). Aids: none.
 */
struct Cfg { unsigned char pad[0xb0]; unsigned int wb0; };
extern struct Cfg *DAT_a807dc04[];

unsigned int FUN_a00a60ac(unsigned char port)
{
    unsigned int r = 2;

    if (port == 0)
        r = DAT_a807dc04[port]->wb0 & 1;
    return r;
}
