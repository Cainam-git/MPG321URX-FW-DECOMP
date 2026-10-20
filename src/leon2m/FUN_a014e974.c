/* BYTE-EXACT: leon2m FUN_a014e974 @ 0xa014e974-0xa014e9d8 (25 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/25 (autoc draft 92.00).
 * Code facts: (u8 p) -> u16. For i = 0..8 (u8 counter, gcc keeps it as inc + and 0xff), bit i of the result is set
 * when the byte table DAT_a802a480[i] (sethi a802a400 + or 0x80) equals p; returns the 9-bit mask as u16
 * (sll/srl 16 at the exit). The cmp operand order (cmp %i0,%g1) comes from a separate u8 local for the table
 * byte compared as 'p == v'; the direct 'DAT_a802a480[i] == p' / 'p == DAT_a802a480[i]' forms give cmp %g1,%i0.
 * No aids.
 */
extern unsigned char DAT_a802a480[];
unsigned short FUN_a014e974(unsigned char p)
{
    unsigned short r = 0;
    unsigned char i;
    for (i = 0; i <= 8; i++) {
        unsigned char v = DAT_a802a480[i];
        if (p == v)
            r |= 1 << i;
    }
    return r;
}
