/* leon2m FUN_a0101a70 @ 0xa0101a70-0xa0101aa0 (12 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/12 mismatches.
 * Code facts: leaf. hw reg 0xcf0160f4 &= 0xf1 (clears bits 1..3 and 8..31); then
 * 0xcf0160f4 |= (p & 0xff) << 1 (fw: and 0xff, add x,x). Two read-modify-write cycles on the same
 * hw register, so volatile (real 0xcf... register). u8 param, void.
 * Fix vs the autoc draft (83.33): BEHAVIOUR: the mask is 0xf1 (draft 0x9f) and the shift is 1
 * (draft 5). Aids: none.
 */
#define REG_cf0160f4 (*(volatile unsigned int *)0xcf0160f4)

void FUN_a0101a70(unsigned char p)
{
    REG_cf0160f4 &= 0xf1;
    REG_cf0160f4 |= p << 1;
}
