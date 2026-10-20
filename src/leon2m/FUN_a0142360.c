/* leon2m FUN_a0142360 @ 0xa0142360-0xa0142380 (8 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 8 words.
 * Code facts: leaf: returns 1 if (u8)(v - 2) <= 1 (v == 2 or 3), else 0.
 * Required form: the test is on the u8 of v - 2 (fw 'and %g1, 0xff' after the add). u8 param / u8 return as at
 * its callers (FUN_a0131518 passes a u8). Aids: none.
 */
unsigned char FUN_a0142360(unsigned char v)
{
    if ((unsigned char)(v - 2) <= 1)
        return 1;
    return 0;
}
