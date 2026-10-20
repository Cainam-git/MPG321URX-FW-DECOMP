/* leon2s FUN_a0091a10 @ 0xa0091a10-0xa0091a4c (15 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp 0/15 mismatches.
 * Code facts: leaf. For ch <= 1 returns (word 0 of the 0x1c-byte record ARR_a807d580[ch] >> 31)
 * != 0 (srl 31; cmp %g0; addx), else 0. u8 result from an int local.
 * Fix vs the autoc draft (80.00): the '!= 0' test of the top bit in an INT local (a u8/_Bool local
 * gives 'and 1' and another schedule: 60.00); 0x1c-byte record struct. Aids: none.
 */
struct Ch1c { unsigned int w0; unsigned int w[6]; };
extern struct Ch1c ARR_a807d580[];

unsigned char FUN_a0091a10(unsigned char ch)
{
    int r = 0;

    if (ch <= 1)
        r = (ARR_a807d580[ch].w0 >> 31) != 0;
    return r;
}
