/* leon2m FUN_a0114420 @ 0xa0114420-0xa0114498 (30 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/30 mismatches.
 * Code facts: two u16 params w, h. b = h >> 1; if w > 0x780 then w >>= 1; a = (u16)(((w + 7)
 * >> 3) << 3) (round up to a multiple of 8). FUN_a00f308c(addr, val) writes val & 0xff to [addr]
 * and val >> 8 to [addr + 4]; it is called for the hw register pairs 0xcf015b50 = a,
 * 0xcf015b58 = b, 0xcf015b6c = a, 0xcf015b74 = b (the last as a tail call). void.
 * Fixes vs the autoc draft (83.33): 2 params only (the draft passed 4 extra args to the last
 * call), both u16; FUN_a00f308c(unsigned int, unsigned int) void prototype. Aids: none.
 */
extern void FUN_a00f308c(unsigned int, unsigned int);

void FUN_a0114420(unsigned short w, unsigned short h)
{
    unsigned short a;
    unsigned short b;

    b = h >> 1;
    if (w > 0x780)
        w = w >> 1;
    a = ((w + 7) >> 3) << 3;
    FUN_a00f308c(0xcf015b50, a);
    FUN_a00f308c(0xcf015b58, b);
    FUN_a00f308c(0xcf015b6c, a);
    FUN_a00f308c(0xcf015b74, b);
}
