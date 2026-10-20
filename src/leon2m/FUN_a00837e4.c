/* leon2m FUN_a00837e4 @ 0xa00837e4-0xa008380c (10 words), flags -mcpu=v8 -O3 -g.
 * Code facts: leaf; returns 1 when (u8)(byte DAT_a802d434 - 4) <= 2 (mode 4..6), else 0, as a u8
 * flag set per path and masked with 'and 1' at the join ('return r & 1'). Fixes vs the autoc draft
 * (50.00): the range test is on the u8 difference (fw 'and 0xff; cmp 2; bgu'), not a signed int
 * compare; _Bool gives other code. Aids: none.
 */
extern unsigned char DAT_a802d434;

unsigned char FUN_a00837e4(void)
{
    unsigned char r = 0;

    if ((unsigned char)(DAT_a802d434 - 4) < 3)
        r = 1;
    return r & 1;
}
