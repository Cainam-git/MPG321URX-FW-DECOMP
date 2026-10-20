/* leon2m FUN_a0123c4c @ 0xa0123c4c-0xa0123c80 (13 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/13 mismatches.
 * Code facts: leaf hex-digit decoder, ch is a full int (no entry mask): (u8)(ch - '0') <= 9 returns
 * ch - '0'; else (u8)(ch - 'A') <= 5 returns ch - 0x37 (masked to u8); else returns 0xaa.
 * Returns u8. Fixes vs the autoc draft (53.85): the range tests are on the u8 differences (the fw
 * masks both with 'and 0xff' before cmp 9 / cmp 5) and the function is written with early returns
 * (a single result variable gives the inverted inner branch). Aids: none.
 */
unsigned char FUN_a0123c4c(int ch)
{
    if ((unsigned char)(ch - '0') <= 9)
        return ch - '0';
    if ((unsigned char)(ch - 'A') <= 5)
        return ch - 0x37;
    return 0xaa;
}
