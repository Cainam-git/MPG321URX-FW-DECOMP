/* leon2s FUN_a0086bd8 @ 0xa0086bd8-0xa0086c48 (28 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0/28 mismatches.
 * Code facts: leaf, returns a u8 status: 0 when bit 0 of hw word 0xcf0189e0 is clear; otherwise 1 / 2 / 3
 * for bit 7 / bit 1 / bit 4 of hw word 0xcf013000 (re-read for each test), else 4. The fw 'and 7' in the
 * retl slot is the u8 return extension narrowed by combine (all values fit in 3 bits).
 * Fixes vs the autoc draft (78.57): u8 return type (int gave no extension) and 0xcf013000 as a constant
 * hardware address (low 10 bits 0: ld [%o5]; the extern symbol gave the simm13 form). volatile only on the
 * two hardware registers. Aids: none.
 */
#define REG_CF0189E0 (*(volatile unsigned int *)0xcf0189e0)
#define REG_CF013000 (*(volatile unsigned int *)0xcf013000)

unsigned char FUN_a0086bd8(void)
{
    unsigned char r = 4;

    if ((REG_CF0189E0 & 1) == 0)
        r = 0;
    else if (REG_CF013000 & 0x80)
        r = 1;
    else if (REG_CF013000 & 0x02)
        r = 2;
    else if (REG_CF013000 & 0x10)
        r = 3;
    return r;
}
