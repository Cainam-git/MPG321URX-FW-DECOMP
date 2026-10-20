/* leon2s FUN_a0073520 @ 0xa0073520-0xa0073540 (8 words), flags -mcpu=v8 -Os -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp_l2s 0 mismatches / 8 words.
 * Code facts: leaf: returns 1 if (u8)(v - 2) <= 1 (v == 2 or 3), else 0. Same body as leon2m FUN_a0142360.
 * Fix vs the autoc draft (75.00): the test is on the u8 of v - 2 (fw 'and 0xff' after the add; the draft compared
 * a signed int < 2). u8 param / u8 return. Aids: none.
 */
unsigned char FUN_a0073520(unsigned char v)
{
    if ((unsigned char)(v - 2) <= 1)
        return 1;
    return 0;
}
