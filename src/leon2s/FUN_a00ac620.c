/* leon2s FUN_a00ac620 @ 0xa00ac620-0xa00ac66c (19 words), flags -mcpu=v8 -Os -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp_l2s 0 mismatches / 19 words.
 * Code facts: returns the 24-bit value (r(0x3d2) << 16) + (r(0x3d1) << 8) + r(0x3d0) with r(x) = FUN_a00a6bb8(ch, x)
 * & 0xff (three byte registers, high byte first).
 * Fix vs the autoc draft (75.00): BEHAVIOUR - the first read (0x3d2) is the HIGH byte (<< 16) and 0x3d1 is << 8
 * (the draft had them swapped); the bytes are joined with + (fw add), as in FUN_a00af320. Aids: none.
 */
extern unsigned int FUN_a00a6bb8(unsigned char, unsigned short);

unsigned int FUN_a00ac620(unsigned char ch)
{
    unsigned int r;

    r = (FUN_a00a6bb8(ch, 0x3d2) & 0xff) << 16;
    r += (FUN_a00a6bb8(ch, 0x3d1) & 0xff) << 8;
    return r + (FUN_a00a6bb8(ch, 0x3d0) & 0xff);
}
